// Stack program 2
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stackArr[MAX];
int top=-1;

void push(int);
int pop();
int isFull();
int isEmpty();
void findPrimeFact(int);
void printPrimes();

int main(){
    int number;
    printf("Please enter the number: ");
    scanf("%d",&number);
    findPrimeFact(number);
    return 0;
}

void findPrimeFact(int num){
    int i=2;
    while(num!=1){
        while(num%i==0){
            push(i);
            num=num/i;
        }
        i++;
    }
    printPrimes();
}

void printPrimes(){
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