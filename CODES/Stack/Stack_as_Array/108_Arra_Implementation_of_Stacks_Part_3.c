// Array implementation of stack
#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stackArr[MAX];
int top=-1;

void print();
void push(int);
int pop();

int main(){
    int data;
    push(1);
    push(2);
    push(3);
    push(4);
    data=pop();
    data=pop();
    print();
    return 0;
}

int pop(){
    int value;
    if(top==-1){
        printf("Stack underflow!");
        exit(1);
    }
    value=stackArr[top--];
    return value;
}

void print(){
    if(top==-1){
        printf("Stack underflow!\n");
        return;
    }
    int i=top;
    printf("[ ");
    while(i>=0)
        printf("%d ",stackArr[i--]);
    printf("]\n");
}

void push(int data){
    if(top==MAX-1){
        printf("Stack overflow!\n");
        return;
    }
    stackArr[++top]=data;
}