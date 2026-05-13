/**
 * File: insertion_sort.c
 * Description: Implementation of Insertion Sort algorithm (both iterative and recursive)
 * Author: Vansh Saharawat
 * Date: May 10, 2026
 * Purpose: Demonstrates insertion sort with two approaches:
 *          - insertion_sort_iterative: Classical iterative approach
 *          - insertion_sort_recursive: Divide-and-conquer recursive approach
 *
 * Both implementations sort integers in ascending order with O(n²) time complexity
 */

#include<stdio.h>
#include<stdlib.h>

/**
 * insertion_sort_iterative - Sorts array using iterative insertion sort
 * @array: Pointer to the integer array to be sorted
 * @size: Number of elements in the array
 *
 * Description: Builds a sorted array one element at a time by comparing each
 * element with previously sorted elements and inserting it at the correct position.
 * Similar to sorting playing cards in your hand.
 *
 * Algorithm: 
 * - Starts from the second element (index 1)
 * - For each element, compares it with sorted portion and shifts larger elements right
 * - Inserts current element at the correct position
 * - Continues until entire array is sorted
 *
 * Time Complexity: O(n²) worst/average case, O(n) best case (already sorted)
 * Space Complexity: O(1) - sorts in-place with no extra space
 *
 * Return: void
 */
void insertion_sort_iterative(int array[], int size) {
    // Start from second element as first element is already considered sorted
    for(int i = 1; i < size; i++) {
        int current_element = array[i];  // Element to be inserted into sorted portion
        int compare_index = i - 1;        // Index for comparing with sorted portion
        
        // Shift all elements greater than current_element one position to the right
        while(compare_index >= 0 && array[compare_index] > current_element) {
            array[compare_index + 1] = array[compare_index];  // Shift element right
            compare_index--;                                   // Move to previous element
        }
        
        // Insert current_element at its correct position in sorted portion
        array[compare_index + 1] = current_element;
    }
}

/**
 * insertion_sort_recursive - Sorts array using recursive insertion sort
 * @array: Pointer to the integer array to be sorted
 * @size: Current index being sorted (should be called with size-1 from main)
 *
 * Description: Implements insertion sort using recursion with divide-and-conquer.
 * First recursively sorts array[0...size-1], then inserts array[size] into
 * its correct position in the sorted portion.
 *
 * Algorithm:
 * - Base case: if size is 0, array is sorted (return)
 * - Recursive case:
 *   1. Recursively sort array[0...size-1]
 *   2. Insert array[size] at correct position in sorted portion
 *
 * Time Complexity: O(n²) worst/average case, O(n) best case
 * Space Complexity: O(n) - due to recursion call stack depth
 *
 * Return: void
 */
void insertion_sort_recursive(int array[], int size) {
    // Base case: array with single element is already sorted
    if(size == 0) {
        return;
    }
    
    // Recursively sort array[0...size-1]
    insertion_sort_recursive(array, size - 1);
    
    // Insert array[size] into its correct position in sorted portion
    int current_element = array[size];
    int compare_index = size - 1;
    
    // Shift elements greater than current_element one position to the right
    while(compare_index >= 0 && array[compare_index] > current_element) {
        array[compare_index + 1] = array[compare_index];
        compare_index--;
    }
    
    // Insert current_element at its correct position
    array[compare_index + 1] = current_element;
}

/**
 * print_array - Displays array elements in formatted bracket notation
 * @array: Pointer to the integer array
 * @size: Number of elements in the array
 *
 * Description: Prints array in format [elem1, elem2, ...] with proper formatting.
 * Includes error handling for empty arrays.
 *
 * Return: 0 on success, -1 if array is empty
 */
int print_array(int array[], int size) {
    if(size == 0) {
        printf("Array is empty\n");
        return -1;
    }
    
    printf("[");
    
    // Print all elements except last with comma separator
    for(int i = 0; i < size - 1; i++) {
        printf("%d, ", array[i]);
    }
    
    // Print last element without trailing comma
    printf("%d]\n\n", array[size - 1]);
    
    return 0;
}

/**
 * main - Entry point and driver function for insertion sort demonstrations
 *
 * Description: Interactive program that:
 * - Prompts user for array size and elements with input validation
 * - Sorts array using recursive insertion sort
 * - Displays original and sorted arrays
 * - Properly manages dynamically allocated memory
 *
 * Return: 0 on successful execution, 1 on input error
 */
int main() {
    int size;
    
    // Get array size from user with input validation
    printf("\n========== Insertion Sort Demonstration ==========\n");
    printf("Enter the number of elements in array: ");
    if(scanf("%d", &size) != 1 || size <= 0) {
        printf("Error: Please enter a valid positive number.\n");
        return 1;
    }
    
    // Dynamically allocate memory for original array
    int *original_array = (int*)malloc(size * sizeof(int));
    if(original_array == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Read array elements from user with validation
    printf("\nEnter %d array elements:\n", size);
    for(int i = 0; i < size; i++) {
        printf("  array[%d]: ", i);
        if(scanf("%d", &original_array[i]) != 1) {
            printf("Error: Invalid input! Please enter a number.\n");
            free(original_array);
            return 1;
        }
    }
    
    // Display original array
    printf("\nOriginal array: ");
    print_array(original_array, size);
    
    // ========== ITERATIVE INSERTION SORT ==========
    printf("\n--- Method 1: Iterative Insertion Sort ---\n");
    
    // Create a copy of the array for iterative sort
    int *iterative_array = (int*)malloc(size * sizeof(int));
    if(iterative_array == NULL) {
        printf("Error: Memory allocation failed.\n");
        free(original_array);
        return 1;
    }
    for(int i = 0; i < size; i++) {
        iterative_array[i] = original_array[i];
    }
    
    // Sort using iterative method
    insertion_sort_iterative(iterative_array, size);
    printf("Sorted array (Iterative): ");
    print_array(iterative_array, size);
    
    // ========== RECURSIVE INSERTION SORT ==========
    printf("\n--- Method 2: Recursive Insertion Sort ---\n");
    
    // Create a copy of the array for recursive sort
    int *recursive_array = (int*)malloc(size * sizeof(int));
    if(recursive_array == NULL) {
        printf("Error: Memory allocation failed.\n");
        free(original_array);
        free(iterative_array);
        return 1;
    }
    for(int i = 0; i < size; i++) {
        recursive_array[i] = original_array[i];
    }
    
    // Sort using recursive method
    insertion_sort_recursive(recursive_array, size - 1);
    printf("Sorted array (Recursive): ");
    print_array(recursive_array, size);
    
    // ========== COMPARISON ==========
    printf("\n--- Comparison ---\n");
    printf("Time Complexity:  Both O(n²) worst/average, O(n) best case\n");
    printf("Space Complexity: Iterative O(1), Recursive O(n) due to call stack\n\n");
    
    // Free all dynamically allocated memory
    free(original_array);
    free(iterative_array);
    free(recursive_array);
    
    return 0;
}