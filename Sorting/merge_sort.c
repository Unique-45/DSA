/**
 * @file merge_sort.c
 * @brief Implementation of the Merge Sort algorithm
 * 
 * Merge Sort is a divide-and-conquer sorting algorithm that divides the array
 * into halves, recursively sorts them, and merges the sorted halves.
 * This implementation provides stable sorting with O(n log n) time complexity.
 */

#include<stdio.h>
#include<stdlib.h>

/**
 * Merges two sorted subarrays into a single sorted subarray
 * 
 * @param arr   Pointer to the array
 * @param s     Start index of the first subarray
 * @param m     Middle index (end of first subarray)
 * @param l     End index of the second subarray
 * 
 * Time Complexity: O(n) where n = l - s + 1
 * Space Complexity: O(n) for temporary arrays arr1 and arr2
 * 
 * The function assumes both arr[s...m] and arr[m+1...l] are already sorted.
 * It merges them in-place back into arr[s...l] in sorted order.
 */
void merge(int arr[], int s, int m, int l) {
    int l1 = m - s + 1;  // Length of first subarray
    int l2 = l - m;      // Length of second subarray
    int t1 = s;
    int t2 = m + 1;

    // Create temporary arrays to hold copies of the subarrays
    int arr1[l1], arr2[l2];

    // Copy first subarray to temporary array arr1
    for(int i = 0; i < l1; i++, t1++) {
        arr1[i] = arr[t1];
    }

    // Copy second subarray to temporary array arr2
    for(int j = 0; j < l2; j++, t2++) {
        arr2[j] = arr[t2];
    }

    int i = 0, j = 0;
    
    // Merge the two temporary arrays back into the original array
    // Pick the smaller element from both arrays and place it in order
    while(i < l1 && j < l2) {
        if(arr1[i] < arr2[j]) {
            // Element from first subarray is smaller
            arr[s] = arr1[i];
            s++;
            i++;
        }
        else {
            // Element from second subarray is smaller or equal
            arr[s] = arr2[j];
            s++;
            j++;
        }
    }

    // Copy any remaining elements from first subarray
    if(i == l1) {
        for(; j < l2; j++, s++) {
            arr[s] = arr2[j];
        }
    }
    else {
        // Copy any remaining elements from second subarray
        for(; i < l1; i++, s++) {
            arr[s] = arr1[i];
        }
    }
}

/**
 * Recursively sorts an array using the Merge Sort algorithm
 * 
 * @param arr   Pointer to the array
 * @param t     Start index of the segment to sort
 * @param n     End index of the segment to sort
 * 
 * Time Complexity: O(n log n) for all cases (best, average, worst)
 * Space Complexity: O(n) for temporary arrays during merging
 * 
 * This function uses divide-and-conquer approach:
 * 1. Divide the array into two halves
 * 2. Recursively sort each half
 * 3. Merge the sorted halves
 */
void merge_sort(int arr[], int t, int n) {
    int m = (t + n) / 2;  // Calculate middle index
    
    // Base case: single element is already sorted
    if(t == n) {
        return;
    }

    // Sort left half: arr[t...m]
    merge_sort(arr, t, m);
    
    // Sort right half: arr[m+1...n]
    merge_sort(arr, m + 1, n);
    
    // Merge the two sorted halves
    merge(arr, t, m, n);
}

/**
 * Prints array elements in a formatted manner
 * 
 * @param arr   Pointer to the array
 * @param n     Number of elements in the array
 * @return      0 on success, -1 if array is empty
 * 
 * Outputs array in the format: [element1, element2, ..., elementN]
 */
int printarray(int arr[], int n) {
    if(n == 0) {
        printf("This is empty array\n");
        return -1;
    }
    
    printf("[");
    
    // Print all elements except the last with comma separator
    for(int i = 0; i < n - 1; i++) {
        printf("%d, ", arr[i]);
    }
    
    // Print last element without trailing comma
    printf("%d]\n\n", arr[n - 1]);
    
    return 0;
}

/**
 * Main function - Entry point of the program
 * 
 * Handles user input/output and performs merge sort on user-provided array.
 * Includes input validation and proper memory management.
 * 
 * @return 0 on successful execution, 1 on error
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
    
    /* Input array elements from user with validation */
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
    
    /* Sort the array using merge sort */
    merge_sort(arr, 0, n - 1);
    
    /* Display sorted array */
    printf("Sorted array: ");
    printarray(arr, n);
    
    /* Free dynamically allocated memory */
    free(arr);
    
    return 0;
}

