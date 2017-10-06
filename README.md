# Pima CIS265 Week #5 Project A

Write a program that finds the largest in a series of numbers entered by the user. The program must prompt the user to enter numbers one by one.  When the user enters 0 or a negative number, the program must display the largest nonnegative number entered:
```text
   Enter a number: 60
   Enter a number: 38.3
   Enter a number: 4.89
   Enter a number: 100.62
   Enter a number: 75.2295
   Enter a number: 0
   The largest number entered was 100.62
```
Notice the numbers aren’t necessarily integers.

The basic functionality of the program is contained in the following:
```C
   if (value <= 0.0f)
     break;
   if (value <= FLT_MAX && value > maxValue) {
     maxValue = value;
```
The remainder of the code deals with input and validation.

Notes:
* Compiled with MS Visual Studio 2017 Community (v141), using C language options.
* The preogram keeps a copy of the maximum float value input and a string copy to preclude displaying a conversion difference.
* (Arbitrary) choice of maximum of 32 for input string size.
* Uses secure scanf_s and strcpy_s.
