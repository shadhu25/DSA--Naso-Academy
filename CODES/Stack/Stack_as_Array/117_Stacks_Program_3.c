// Stack program 3
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stackArr[MAX];
int top=-1;

void push(int);
int pop();
int isFull();
int isEmpty();
void decimal2binary(int);
void printBinary();

int main(){
    int number;
    printf("Please enter the number: ");
    scanf("%d",&number);
    decimal2binary(number);
    return 0;
}

void decimal2binary(int num){
    while(num!=0){
        push(num%2);
        num=num/2;
    }
    printBinary();
}

void printBinary(){
        while(!isEmpty())
            printf("%d ",pop());
        printf("\n");
}

int isEmpty(){
    return top==-1;
}

int isFull(){
    return top==MAX-1;
}

int pop(){
    int value;
    if(isEmpty()){
        printf("Stack underflow!\n");
        return;
    }
    value=stackArr[top--];
    return value;
}

void push(int data){
    if(isFull()){
        printf("Stack overflow!\n");
        return;
    }
    stackArr[++top]=data;
}