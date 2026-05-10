/*
 * File: selection_sort.c
 * Description: Implementation of Selection Sort algorithm
 * Author: Vansh Saharawat
 * Date: May 10, 2026
 * Purpose: Sorts an array of integers in ascending order using selection sort
 */

#include<stdio.h>
#include<stdlib.h>

/*
 * Function: swap
 * Description: Swaps two elements in an array
 * Parameters:
 *   arr[] - The array containing elements
 *   a     - Index of first element
 *   b     - Index of second element
 * Return: void
 */
void swap(int arr[],int a, int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

/*
 * Function: selection_sort
 * Description: Sorts array using selection sort algorithm
 *              Finds minimum element in unsorted portion and places it at correct position
 * Parameters:
 *   arr[] - The array to be sorted
 *   n     - Number of elements in the array
 * Return: void
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */
void selection_sort(int arr[],int n){
    // Traverse through each position in the array
    for(int i=0;i<n;i++){
        int ind=i;  // Assume current position has minimum element
        
        // Find the minimum element in remaining unsorted array
        for(int j=i+1;j<n;j++){
            if(arr[ind]>arr[j]){
                ind=j;  // Update index if smaller element found
            }
        }
        
        // Swap minimum element with current position
        swap(arr,ind,i);
    }
}

/*
 * Function: printarray
 * Description: Displays array elements in formatted output
 * Parameters:
 *   arr[] - The array to be printed
 *   n     - Number of elements in the array
 * Return: 0 on success, -1 if array is empty
 */
int printarray(int arr[],int n){
    // Check if array is empty
    if(n == 0){
        printf("This is empty array\n");
        return -1;
    }
    else{
        printf("[");
        // Print all elements except the last one with comma separator
        for(int i=0;i<n-1;i++){
            printf("%d, ",arr[i]);
        }
        // Print the last element without comma
        printf("%d]\n\n",arr[n-1]);
    }
    return 0;
}

/*
 * Function: main
 * Description: Entry point of the program. Handles user input and controls program flow
 * Return: 0 on successful execution, 1 on error
 */
int main(){
    int n;
    
    // Get array size from user
    printf("Enter the no of elements in array: ");
    if(scanf("%d", &n) != 1){
        printf("Invalid input! Please enter a number.\n");
        return 1;
    }
    
    int *arr = (int*)malloc(n * sizeof(int));  //Dynamically allocate memory for array
    
    // Input array elements from user
    for(int i = 0; i < n; i++){
        printf("Enter the arr[%d]: ", i);
        if(scanf("%d", &arr[i]) != 1){
            printf("Invalid input! Please enter a number.\n");
            return 1;
        }
    }
    
    // Display original array
    printf("\nOriginal array: ");
    printarray(arr, n);
    
    // Perform selection sort
    selection_sort(arr, n);
    
    // Display sorted array
    printf("Sorted array: ");
    printarray(arr, n);
    free(arr);  //Free dynamically allocated memory
    return 0;
}