#include<stdio.h>
#include<stdlib.h>

/**
 * Merges two sorted subarrays of the main array
 * 
 * @param array     Pointer to the main array
 * @param start     Start index of the first subarray
 * @param mid       End index of the first subarray
 * @param end       End index of the second subarray
 * 
 * This function assumes both subarrays are already sorted and merges them
 * in ascending order while maintaining stability.
 */
void merge(int array[], int start, int mid, int end) {
    int left_length = mid - start + 1;   // Length of first subarray
    int right_length = end - mid;        // Length of second subarray
    int left_index = start;
    int right_index = mid + 1;

    // Create temporary arrays to hold copies of the subarrays
    int left_array[left_length];
    int right_array[right_length];

    // Copy first subarray to temporary array
    for(int i = 0; i < left_length; i++, left_index++) {
        left_array[i] = array[left_index];
    }

    // Copy second subarray to temporary array
    for(int j = 0; j < right_length; j++, right_index++) {
        right_array[j] = array[right_index];
    }

    int i = 0, j = 0;
    int merge_index = start;
    
    // Merge the two temporary arrays back into the original array
    // Compare elements from both arrays and place smaller one in order
    while(i < left_length && j < right_length) {
        if(left_array[i] < right_array[j]) {
            // Element from first subarray is smaller
            array[merge_index] = left_array[i];
            i++;
        }
        else {
            // Element from second subarray is smaller or equal
            array[merge_index] = right_array[j];
            j++;
        }
        merge_index++;
    }

    // Copy remaining elements from left array (if any)
    while(i < left_length) {
        array[merge_index++] = left_array[i++];
    }
    
    // Copy remaining elements from right array (if any)
    while(j < right_length) {
        array[merge_index++] = right_array[j++];
    }
}


/**
 * Recursively sorts an array using the Merge Sort algorithm
 * 
 * @param array Start index of the segment to sort
 * @param start Start index of the segment to sort
 * @param end   End index of the segment to sort
 * 
 * Time Complexity: O(n log n) for all cases (best, average, worst)
 * Space Complexity: O(n) for temporary arrays during merging
 * 
 * Uses divide-and-conquer approach:
 * 1. Divide array into two halves
 * 2. Recursively sort each half
 * 3. Merge the sorted halves
 */
void merge_sort(int array[], int start, int end) {
    // Base case: single element is already sorted
    if(start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;  // Calculate middle index (avoid overflow)
    
    // Sort left half: array[start...mid]
    merge_sort(array, start, mid);
    
    // Sort right half: array[mid+1...end]
    merge_sort(array, mid + 1, end);
    
    // Merge the two sorted halves
    merge(array, start, mid, end);
}

/**
 * Checks if two elements in an array sum to a target value
 * 
 * @param array         Pointer to the input array
 * @param target_sum    The target sum to search for
 * @param size          Number of elements in the array
 * 
 * @return 1 if two elements found that sum to target, 0 otherwise
 * 
 * Algorithm: Two-pointer approach with merge sort
 * Time Complexity: O(n log n) - dominated by merge sort
 * Space Complexity: O(n) - for sorted array copy
 */
int find_pair_with_sum(int array[], int target_sum, int size) {
    // Create a copy of the array to avoid modifying the original
    int sorted_array[size];
    for(int i = 0; i < size; i++) {
        sorted_array[i] = array[i];
    }
    
    // Sort the copy array
    merge_sort(sorted_array, 0, size - 1);
    
    // Initialize pointers at both ends
    int left_ptr = 0;
    int right_ptr = size - 1;
    
    // Two-pointer search
    while(left_ptr < right_ptr) {
        int current_sum = sorted_array[left_ptr] + sorted_array[right_ptr];
        
        if(current_sum == target_sum) {
            printf("\n✓ Found! Two elements sum to %d: %d + %d = %d\n\n",
                   target_sum, sorted_array[left_ptr], sorted_array[right_ptr], target_sum);
            return 1;
        }
        else if(current_sum < target_sum) {
            // Sum too small, need larger numbers
            left_ptr++;
        }
        else {
            // Sum too large, need smaller numbers
            right_ptr--;
        }
    }
    
    printf("\n✗ No pair found that sums to %d\n", target_sum);
    return 0;
}

/**
 * Prints array elements in a formatted way
 * 
 * @param array Pointer to the array to print
 * @param size  Number of elements in the array
 * 
 * @return 0 on success, -1 if array is empty
 */
int print_array(int array[], int size) {
    if(size == 0) {
        printf("Array is empty\n");
        return -1;
    }
    
    printf("[");
    
    // Print all elements except the last with comma separator
    for(int i = 0; i < size - 1; i++) {
        printf("%d, ", array[i]);
    }
    
    // Print last element without trailing comma
    printf("%d]\n\n", array[size - 1]);
    
    return 0;
}

/**
 * Main entry point of the Two Sum Problem solver
 * 
 * Prompts user for array input and target sum,
 * then searches for two elements that sum to the target.
 * 
 * @return 0 on successful execution, 1 on error
 */
int main() {
    int size, target_sum;
    
    // Get array size from user
    printf("\n=== Two Sum Problem Solver ===\n");
    printf("Enter the number of elements in array: ");
    if(scanf("%d", &size) != 1 || size <= 0) {
        printf("Error: Please enter a valid positive number.\n");
        return 1;
    }
    
    // Allocate memory for the array
    int *array = (int*)malloc(size * sizeof(int));
    if(array == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Read array elements from user
    printf("\nEnter %d array elements:\n", size);
    for(int i = 0; i < size; i++) {
        printf("  array[%d]: ", i);
        if(scanf("%d", &array[i]) != 1) {
            printf("Error: Invalid input! Please enter a number.\n");
            free(array);
            return 1;
        }
    }

    // Display the original array
    printf("\nOriginal Array: ");
    print_array(array, size);

    // Get target sum from user
    printf("Enter the target sum to search for: ");
    if(scanf("%d", &target_sum) != 1) {
        printf("Error: Invalid input! Please enter a number.\n");
        free(array);
        return 1;
    }

    // Search for pair with target sum
    printf("\nSearching for pair with sum = %d...\n", target_sum);
    find_pair_with_sum(array, target_sum, size);

    // Free allocated memory
    free(array);
    return 0;
}