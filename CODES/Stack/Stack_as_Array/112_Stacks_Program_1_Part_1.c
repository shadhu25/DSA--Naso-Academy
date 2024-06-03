// Stack program 1
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stackArr[MAX];
int first=-1;

void push(int);
void print();
int isFull();
int isEmpty();

int main(){
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    print();
    return 0;
}

void push(int data){
    if(isFull()){
        printf("Stack overflow!\n");
        return;
    }
    for(int i=++first; i>0;i--)
        stackArr[i]=stackArr[i-1];
    stackArr[0]=data;
}

int isFull(){
    return first==MAX-1;
}

int isEmpty(){
    return first==-1;
}

void print(){
    if(isEmpty()){
        printf("Stack underflow!\n");
        return;
    }
    printf("[ ");
    for(int i=0; i<=first;i++)
        printf("%d ",stackArr[i]);
    printf("]\n");
}