/**
 * @file basic.h
 * @brief Provides basic utility
 */

 /**
  * @brief Prints the elements of an integer array.
  * 
  * This function iterates through the given array and prints each
  * element to the standard output.
  * 
  * @param array The integer array to be printed.
  * @param size  The number of elements in the array.
  * @return int  Returns 0 on successful execution, or an appropriate error code.
  */
#ifndef BASIC_H
#define BASIC_H
int print_array(int array[], int size);
void swap(int array[], int a, int b);
int array_input(int array[],int n);
#endif /* BASIC_H */