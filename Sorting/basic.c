#include<stdio.h>
#include"basic.h"

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

void swap(int array[], int a, int b){
    int temp=array[a];
    array[a]=array[b];
    array[b]=temp;
    return;
}

int array_input(int array[],int n){
    for(int i=0;i<n;i++){
        int flag;
        do{
            flag=1;
            printf("Enter the %d element of array: ",i);
            int t=scanf("%d",&array[i]);
            printf("\n");
            if(t != 1){
                printf("!Invalid input\nEnter valid input\n");
                printf("\n");
                flag=0;
                
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {}
            }
        }
        while(!flag);
    }
    return 1;
}