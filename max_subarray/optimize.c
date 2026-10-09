#include<stdio.h>
#include<stdlib.h>
#include"../Sorting/basic.h"

/**
 * Stores the maximum subarray found by max_subarray().
 *
 * The returned array contains a copy of the selected values and must be
 * released by the caller with free().
 */
struct format{
    int total_elements;  // Number of values in the maximum subarray.
    int* array;          // Dynamically allocated copy of those values.
    int sum;              // Sum of all values in the maximum subarray.
};

/**
 * Returns the larger of two integer values.
 */
int max(int a, int b){
    return a>b?a:b;
}

/**
 * Finds the contiguous subarray with the greatest possible sum.
 *
 * This is Kadane's algorithm. curr_sum represents the best subarray ending
 * at the current position. When extending that subarray would be worse than
 * starting at the current value, the running subarray is restarted. The index
 * variables preserve the boundaries needed to copy the winning values into
 * the result.
 *
 * Time complexity: O(n)
 * Space complexity: O(n) for the returned copy of the subarray
 *
 * @param array Input array of integers.
 * @param n Number of elements in array. The caller must provide n >= 1.
 * @return A format containing the maximum subarray, its length, and its sum.
 *         If memory allocation fails, array is NULL, total_elements is 0,
 *         and sum is 0.
 */
struct format max_subarray(int array[],int n){
    int i,l_o_index,l_n_index,u_index;

    // l_o_index and u_index bound the best subarray found so far.
    // l_n_index marks where the current candidate subarray begins.
    i=0;
    l_o_index=0;
    l_n_index=0;
    u_index=0;
    struct format temp;

    // Allocate enough space for the largest possible result: the full input.
    temp.array = malloc(n * sizeof(int));
    if(temp.array == NULL){
        temp.total_elements=0;
        temp.sum=0;
        return temp;
    }
    if(n==1){
        temp.total_elements=1;
        temp.array[0]=array[0];
        temp.sum=array[0];
        return temp;

    }
    int max_sum,curr_sum;
    max_sum=array[0];
    curr_sum=array[0];
    for(i=1;i<n;i++){
        // Extend the current subarray with array[i].
        curr_sum+=array[i];

        // Starting at array[i] is better than keeping the previous values.
        if(curr_sum<array[i]){
            curr_sum=array[i];
            l_n_index=i;
        }

        // Record the current candidate whenever it improves the best sum.
        if(curr_sum>max_sum){
            max_sum=curr_sum;
            l_o_index=l_n_index;
            u_index=i;

        }
        

    }
    // Copy the chosen contiguous range into the result-owned buffer.
    temp.total_elements=u_index-l_o_index+1;
    for(int i=0;i<temp.total_elements;i++){
        temp.array[i]=array[l_o_index+i];
    }
    temp.sum=max_sum;

    return temp;

}

int main(){
    int n,flag;

    // Keep asking until the number of elements is read as an integer.
    do{
        flag=1;
        printf("Enter the no of Elements in array: ");
        int t=scanf("%d",&n);
        printf("\n");
        if(t != 1){
            printf("!Invalid input\nEnter valid input\n");
            printf("\n");
            flag=0;

            // Clear the input buffer to prevent infinite loop.
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
    }
    while(!flag);

    // Read and display the input array before solving it.
    int array[n];
    array_input(array,n);
    printf("Array is \n\n");
    print_array(array,n);

    // Compute, display, and finally release the dynamically allocated result.
    struct format temp=max_subarray(array,n);
    printf("Maximum subarray is ");
    print_array(temp.array,temp.total_elements);
    printf("\n");
    printf("Sum is %d\n\n",temp.sum);
    free(temp.array);
    return 0;
}