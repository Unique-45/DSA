#include<stdio.h>
#include<math.h>
#include"basic.h"

// Function to maintain the max-heap property from top to bottom
int heapify_down(int array[], int size){
    if(size==1){
        return 1;
    }
    int i=1; // 1-based index for the root node
    while(i*2 <= size){
        // Check if the left child is greater than the current node and also greater than the right child
        if((array[i*2-1]>array[i-1]) && (array[(i*2)-1] > array[i*2])){
            
            swap(array,i*2-1,i-1); // Swap with left child
            i=i*2; // Move down to left child
        }
        // Check if the right child exists and is greater than the current node and the left child
        else if(((i*2+1 < size) && array[(i*2)] > array[i-1]) && (array[i*2] > array[i*2-1])){
            swap(array,i*2,i-1); // Swap with right child
            i=i*2+1; // Move down to right child
        }
        else{
            // The max-heap property is satisfied
            return 1;
        }
    }
    return 1;

}

// Function to maintain the max-heap property from bottom to top
int heapify_up(int array[], int size){
    int i=size; // 1-based index for the newly inserted element
    if(i==1){
        return 1;
    }
    while(i>1){
        // If the parent is smaller than the current node, swap them
        if(array[(i/2)-1]< array[i-1]){
            swap(array,i-1,i/2-1);
            i/=2; // Move up to the parent node
        }
        else {
            // The max-heap property is satisfied
            return 1;
        }
    }
    
    return 1;
}

// Function to insert elements from array 'p' into the heap 'array'
void insertion(int array[],int* size,int* p,int n){
    for(int i=0;i<n;i++){
        
        array[(*size)]=*(p+i); // Insert at the end of the heap
        (*size)++; // Increase the heap size
        heapify_up(array,*size); // Restore the max-heap property
    }
    return;
}

// Function to delete the root (maximum element) from the max-heap
int deletion(int array[],int* size){
    if(!(*size)){
        printf("No element to deleted\n\n");
        return 0;
    }
    int temp=array[0]; // Store the maximum element
    array[0]=array[*size-1]; // Move the last element to the root
    (*size)--; // Decrease the heap size
    heapify_down(array,*size); // Restore the max-heap property
    return temp;
}

// Function to perform heap sort on the given array
int heap_sort(int array[], int size){
    if(!size){
        printf("Array is empty\n\n");
        return 0;
    }
    else if(size==1){
        printf("Array sorted Successfully!\n\n");
        return 1;
    }
    int temp[size]; // Temporary array to build the max-heap
    int t=0; // Current size of the heap
    
    // Insert all elements into the heap
    insertion(temp,&t,array,size);
    print_array(temp,size);
    
    // Extract elements from the heap one by one
    for(int i=0;i<size;i++){
        int a=deletion(temp,&t); // Get the maximum element
        array[size-i-1]=a; // Place it at the correct sorted position (end of array)
    }
    printf("Array sorted Successfully!\n\n");
    return 1;
}

int main(){
    int n,flag,p;
    
    // Input validation loop for the number of elements
    do{
        flag=1;
        printf("Enter the no of Elements in array: ");
        int t=scanf("%d",&n);
        printf("\n");
        if(t != 1){
            printf("!Invalid input\nEnter valid input\n");
            printf("\n");
            flag=0;
            
            // Clear the input buffer to prevent infinite loop
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
    }
    while(!flag);
    
    int array[n];
    array_input(array,n); // Read the elements into the array
    
    printf("Original Array: ");
    print_array(array,n);
    printf("\n\n");
    
    heap_sort(array,n); // Sort the array using heap sort
    print_array(array,n); // Print the sorted array
}