/**
 * @file inversion_calculation.c
 * @brief Counts the number of inversion pairs in an array using merge sort
 * 
 * An inversion pair (i, j) exists when i < j but arr[i] > arr[j].
 * Uses a modified merge sort algorithm to count inversions in O(n log n) time.
 */

#include<stdio.h>
#include<stdlib.h>

/**
 * Merges two sorted subarrays and counts inversions
 * 
 * @param arr     Pointer to the array
 * @param s       Start index of the first subarray
 * @param m       Middle index (end of first subarray)
 * @param l       End index of the second subarray
 * @return        Number of inversion pairs found during merge
 * 
 * Time Complexity: O(n) where n = l - s + 1
 * Space Complexity: O(n) for temporary arrays
 */
int merge(int arr[], int s, int m, int l) {
    int c = 0;  // Inversion counter
    int l1 = m - s + 1;  // Length of first subarray
    int l2 = l - m;      // Length of second subarray
    int t1 = s;
    int t2 = m + 1;

    // Create temporary arrays for left and right subarrays
    int arr1[l1], arr2[l2];

    // Copy left subarray to temporary array
    for(int i = 0; i < l1; i++, t1++) {
        arr1[i] = arr[t1];
    }

    // Copy right subarray to temporary array
    for(int j = 0; j < l2; j++, t2++) {
        arr2[j] = arr[t2];
    }

    int i = 0, j = 0;
    
    // Merge subarrays while both have elements
    while(i < l1 && j < l2) {
        if(arr1[i] < arr2[j]) {
            // Element from left is smaller, no inversions
            arr[s] = arr1[i];
            s++;
            i++;
        }
        else {
            // Element from right is smaller, forms inversion with all remaining left elements
            arr[s] = arr2[j];
            s++;
            j++;
            c += l1 - i;  // Count inversions: all remaining elements in arr1 are greater than arr2[j]
        }
    }

    // Copy remaining elements from left subarray (no inversions here)
    if(i == l1) {
        for(; j < l2; j++, s++) {
            arr[s] = arr2[j];
        }
    }
    else {
        // Copy remaining elements from right subarray
        for(; i < l1; i++, s++) {
            arr[s] = arr1[i];
        }
    }

    return c;
}

/**
 * Recursively sorts array using merge sort and counts inversions
 * 
 * @param arr   Pointer to the array
 * @param t     Start index
 * @param n     End index
 * @return      Total number of inversion pairs in arr[t...n]
 * 
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
int merge_sort(int arr[], int t, int n) {
    int m = (t + n) / 2;
    
    // Base case: single element has no inversions
    if(t == n) {
        return 0;
    }

    // Count inversions in left half
    int a = merge_sort(arr, t, m);
    
    // Count inversions in right half
    int b = merge_sort(arr, m + 1, n);
    
    // Count inversions during merge of two halves
    int c = merge(arr, t, m, n);
    
    // Return total inversions
    return a + b + c;
}

/**
 * Prints array elements in a formatted manner
 * 
 * @param arr   Pointer to the array
 * @param n     Number of elements
 * @return      0 on success, -1 if array is empty
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
 * Wrapper function to count inversions without modifying original array
 * 
 * @param arr1  Original array
 * @param n     Size of array
 * @return      Total count of inversion pairs in the array
 */
int inversion_pair_count(int arr1[], int n) {
    // Create a copy to avoid modifying the original array
    int arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = arr1[i];
    }
    
    return merge_sort(arr, 0, n - 1);
}

/**
 * Main function - Entry point
 * Reads array from user input and displays the total inversion pair count
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
    
    /* Count and display inversion pairs */
    int i = inversion_pair_count(arr, n);
    printf("Total inversion pair in this array is %d\n\n", i);
    
    /* Free dynamically allocated memory */
    free(arr);
    
    return 0;
}

