#include<stdio.h>
#include"basic.h"

int max_subarray(int array[],int temp[],int size){
    if(size==1){
        temp[0]=temp[1]=0;
        temp[2]=array[0];
        return 1;
    }
    int sum=array[0];
    temp[0]=temp[1]=0;
    temp[2]=array[0];
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            int new_sum=0;
            for(int k=i;k<j+1;k++){
                new_sum+=array[k];
            }
            if(sum<new_sum){
                temp[0]=i;
                temp[1]=j;
                sum=new_sum;
            }
        }
    }
    temp[2]=sum;
    return 1;
}

int main(){
    int n,flag;
    int temp[3];
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
    array_input(array,n);
    printf("Array is \n\n");
    print_array(array,n);
    max_subarray(array,temp,n);
    int size=temp[1]-temp[0]+1;
    printf("Maximum subarray is ");
    print_array(&array[temp[0]],size);
    printf("\n");
    printf("Sum is %d\n\n",temp[2]);
    return 0;

    
}