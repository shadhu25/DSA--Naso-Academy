// realloc() function
#include<stdio.h>
#include<stdlib.h>
void input(int*, int);
void print(int*,int);
int reAlloc(int*,int);
int main(){
    int size, i, *ptr;
    printf("Enter how many integers you want to input: ");
    scanf("%d",&size);
    ptr=(int*)malloc(size*sizeof(int));
    if(ptr==NULL){
        printf("we could not allocate memory! sorry...\n");
        exit(0);
    }
    input(ptr,size);
    size=reAlloc(ptr,size);
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
int reAlloc(int *ptr,int oldSize){
    int newSize,i;
    printf("enter new size(newSize > oldSize),oldSize = %d: ",oldSize);
    scanf("%d",&newSize);
    if(newSize<oldSize){
        printf("newSize < oldSize\n");
        exit(0);
    }
    ptr=realloc(ptr,newSize*sizeof(int));
    if(ptr==NULL){
        printf("we could not allocate memory! sorry...\n");
        exit(0);
    }
    for(i=oldSize;i<newSize;i++){
        printf("Enter number->%d: ",i+1);
        scanf("%d",(ptr+i));
    }
    return newSize;
}