#include<stdio.h>
#include<stdlib.h>

/**
 * swap - Exchanges two elements in an array
 * @arr: Pointer to the integer array
 * @a: Index of first element to swap
 * @b: Index of second element to swap
 *
 * Description: Swaps the values at indices a and b using a temporary variable.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

/**
 * bubble_sort - Sorts an array using bubble sort algorithm
 * @arr: Pointer to the integer array to be sorted
 * @n: Number of elements in the array
 *
 * Description: Implements bubble sort with early termination optimization.
 * Compares adjacent elements and swaps them if they're in wrong order.
 * Includes loop counters for performance analysis.
 *
 * Time Complexity: O(n²) worst/average case, O(n) best case (already sorted)
 * Space Complexity: O(1)
 *
 * Return: void
 */
void bubble_sort(int arr[], int n) {
    int ol = 0;  /* Outer loop iteration counter */
    int il = 0;  /* Inner loop iteration counter */
    
    /* Iterate n times, reducing range each pass */
    for(int i = 0; i < n; i++) {
        ol++;
        int s = 0;  /* Swap counter for early termination check */
        
        /* Compare adjacent elements; range decreases as largest elements settle */
        for(int j = 0; j < n - i - 1; j++) {
            il++;
            if(arr[j] > arr[j+1]) {
                swap(arr, j, j+1);
                s++;
            }
        }
        
        /* Optimization: If no swaps occurred, array is already sorted */
        if(s == 0) {
            break;
        }
    }
    
    /* Display performance metrics */
    printf("Outer loop runs %d time\n\n", ol);
    printf("Inner loop runs %d times\n\n", il);
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
    printf("%d]\n\n", arr[n-1]);
    
    return 0;
}

/**
 * main - Entry point; driver function for bubble sort
 *
 * Description: Prompts user for array size and elements, performs bubble sort,
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
    bubble_sort(arr, n);
    
    /* Display sorted array */
    printf("Sorted array: ");
    printarray(arr, n);
    
    /* Free dynamically allocated memory */
    free(arr);
    
    return 0;
}