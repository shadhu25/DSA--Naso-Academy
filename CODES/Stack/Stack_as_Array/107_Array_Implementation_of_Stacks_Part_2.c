// Array implementation of stack 
#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stackArr[MAX];
int top=-1;

void push(int);

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    return 0;
}

void push(int data){
    if(top==MAX-1){
        printf("Stack overflow!\n");
        return;
    }
    stackArr[++top]=data;
}