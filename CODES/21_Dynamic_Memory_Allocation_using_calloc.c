// calloc() function
#include<stdio.h>
#include<stdlib.h>
void input(int*, int);
void print(int*,int);
int main(){
    int size, i, *ptr;
    printf("Enter how many integers you want to input: ");
    scanf("%d",&size);
    ptr=(int*)calloc(size,sizeof(int));
    if(ptr==NULL){
        printf("we could not allocate memory! sorry...\n");
        exit(0);
    }
    // in calloc all memory blocks are automatcally initialised with 0.
    print(ptr,size);
    input(ptr,size);
    print(ptr,size);
    return 0;
}
void input(int *ptr, int size){
    int i;
    for(i=0;i<size;i++){
        printf("Enter number->%d: ",i+1);
        scanf("%d",(ptr+i));
    }
}
void print(int *ptr,int size){
    int i;
    printf("[ ");
    for(i=0;i<size;i++){
        printf("%d ",*(ptr+i));
    }
    printf("]");
    printf("\n");
}