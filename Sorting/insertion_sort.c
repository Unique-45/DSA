/**
 * File: insertion_sort.c
 * Description: Implementation of Insertion Sort algorithm
 * Author: Vansh Saharawat
 * Date: May 10, 2026
 * Purpose: Sorts an array of integers in ascending order using insertion sort
 */

#include<stdio.h>
#include<stdlib.h>

/**
 * insertion_sort - Sorts an array using insertion sort algorithm
 * @arr: Pointer to the integer array to be sorted
 * @n: Number of elements in the array
 *
 * Description: Implements insertion sort by building sorted array one element at a time.
 * Compares each element with previous elements and inserts it at the correct position.
 * Works similarly to sorting playing cards in hand.
 *
 * Time Complexity: O(n²) worst/average case, O(n) best case (already sorted)
 * Space Complexity: O(1)
 *
 * Return: void
 */
void insertion_sort(int arr[], int n) {
    /* Start from second element as first element is considered sorted */
    for(int i = 1; i < n; i++) {
        int key = arr[i];  /* Element to be inserted into sorted portion */
        int j = i - 1;     /* Index for comparing with sorted portion */
        
        /* Move elements greater than key one position ahead */
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  /* Shift element to the right */
            j--;                   /* Move to previous element */
        }
        
        /* Insert the key at its correct position */
        arr[j + 1] = key;
    }
}

/**
 * printarray - Displays array elements in bracket notation
 * @arr: Pointer to the integer array
 * @n: Number of elements in the array
 *
 * Description: Prints array in format [elem1, elem2, ...] with proper formatting.
 * Handles empty array edge case.
 *
 * Return: 0 on success, -1 if array is empty
 */
int printarray(int arr[], int n) {
    if(n == 0) {
        printf("This is empty array\n");
        return -1;
    }
    
    printf("[");
    /* Print all elements except last with comma separator */
    for(int i = 0; i < n - 1; i++) {
        printf("%d, ", arr[i]);
    }
    /* Print last element without trailing comma */
    printf("%d]\n\n", arr[n - 1]);
    
    return 0;
}

/**
 * main - Entry point; driver function for insertion sort
 *
 * Description: Prompts user for array size and elements, performs insertion sort,
 * displays original and sorted arrays. Includes input validation and memory
 * management using dynamic allocation.
 *
 * Return: 0 on success, 1 on error
 */
int main() {
    int n;
    
    /* Get array size from user with input validation */
    printf("Enter the no of elements in array: ");
    if(scanf("%d", &n) != 1) {
        printf("Invalid input! Please enter a number.\n");
        return 1;
    }
    
    /* Dynamically allocate memory for array */
    int *arr = (int*)malloc(n * sizeof(int));
    
    /* Input array elements from user */
    for(int i = 0; i < n; i++) {
        printf("Enter the arr[%d]: ", i);
        if(scanf("%d", &arr[i]) != 1) {
            printf("Invalid input! Please enter a number.\n");
            free(arr);  /* Free memory before exit */
            return 1;
        }
    }
    
    /* Display original array before sorting */
    printf("\nOriginal array: ");
    printarray(arr, n);
    
    /* Sort the array */
    insertion_sort(arr, n);
    
    /* Display sorted array */
    printf("Sorted array: ");
    printarray(arr, n);
    
    /* Free dynamically allocated memory */
    free(arr);
    
    return 0;
}