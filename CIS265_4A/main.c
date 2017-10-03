/*************************************************************************
* Title: (CIS265_4A) Largest Non-negative Number Entered.
* File: main.c
* Author: James Eli
* Date: 8/25/2017
*
* Write a program that finds the largest in a series of numbers entered by 
* the user. The program must prompt the user to enter numbers one by one. 
* When the user enters 0 or a negative number, the program must display the 
* largest nonnegative number entered:
*   Enter a number: 60
*   Enter a number: 38.3
*   Enter a number: 4.89
*   Enter a number: 100.62
*   Enter a number: 75.2295
*   Enter a number: 0
*   The largest number entered was 100.62
* Notice the numbers aren’t necessarily integers.
*
* The basic functionality of the program is contained in the following:
*   if (value <= 0.0f)
*     break;
*   if (value <= FLT_MAX && value > maxValue) {
*     maxValue = value;
*
* The remainder of the code deals with input and validation.
*
* Notes:
*  (1) Compiled with MS Visual Studio 2017 Community (v141), using C
*      language options.
*  (2) The preogram keeps a copy of the maximum float value input and
*      a string copy to preclude displaying a conversion difference.
*  (3) (Arbitrary) choice of maximum of 32 for input string size.
*  (4) Uses secure scanf_s and strcpy_s.
*
* Submitted in partial fulfillment of the requirements of PCC CIS-265.
*************************************************************************
* Change Log:
*   08/25/2017: Initial release. JME
*************************************************************************/
#include <assert.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define MAX_STRING_LEN 32 // Maximum input string size.

// Program starts here.
int main(void) {
	char input[MAX_STRING_LEN];     // Temporary holds user input as string.
	float value = 0.f;              // Converted value of user input string.
	float maxValue = 0.0f;          // Maximum (non-negative) value entered in float format.
	char maxString[MAX_STRING_LEN] = { 0 }; // Maximum value entered in string format,
	                                        // Initialize to null in order to catch no entry.

	// Post program instructions.
	fputs("Enter a series of numbers.\nEnter '0' or a negative number to end.\n", stdout);
	fputs("The program will determine the largest non-negative number entered.\n\n", stdout);

	// Loop until sentinel entered.
	while (1) {
		// Prompt and grab user input.
		fputs("Enter a number: ", stdout);
		if (!fgets(input, sizeof input, stdin)) {
			fputs("\nFatal program error!\n", stderr);
			exit(EXIT_FAILURE);
		}
		else if (!strchr(input, '\n')) {
			// input too long, eat remainder.
			while (fgets(input, sizeof input, stdin) && !strchr(input, '\n'))
				; // Empty body.
			fputs("Too many characters input. Try a smaller number.\n", stdout);
		}
		else {
			// Catch special case of null input.
			if (strlen(input) <= 1)
				continue;

			// Attempt to convert from string to float, and validate.
			if (sscanf_s(input, "%f", &value)) {
				if (value <= 0.0f)
					break;
				if (value <= FLT_MAX && value > maxValue) {
					maxValue = value;
					strcpy_s(maxString, sizeof input, input);
				}
				else if (value > FLT_MAX)
					fputs("Sorry, value entered is too large.\n", stdout);
			}
			else
				fputs("Invalid input.\n", stdout);
		}
	}

	// Display largest value (using string prevents potential confusion due to inexact float conversions).
	fprintf(stdout, "The largest number entered was %s\n", strlen(maxString) ? maxString : "<No entry found!>");
}

