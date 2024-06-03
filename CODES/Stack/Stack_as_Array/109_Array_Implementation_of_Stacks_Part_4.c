// Array implementation of stack
#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stackArr[MAX];
int top=-1;

void print();
void push(int);
int pop();
int peek();
int isFull();
int isEmpty();

int main(){
    int data,choice;
    while(1){
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Print the top element\n");
        printf("4.Print all elements of the stack\n");
        printf("5.Quit\n");
        printf("Please enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                 if(!isEmpty()){
                    data=pop();
                    printf("Deleted element is %d\n",data);
                }
                else{
                    printf("Stack underflow!\n");
                }
                break;
            case 3:
                printf("The topmost element of the stack is %d\n",peek());
                break;
            case 4:
                print();
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

int isEmpty(){
    return top==-1;
}

int isFull(){
    return top==MAX-1;
}

int peek(){
    if(isEmpty()){
        printf("Stack underflow!\n");
        return;
    }
    return stackArr[top];
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

void print(){
    if(isEmpty()){
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
    if(isFull()){
        printf("Stack overflow!\n");
        return;
    }
    stackArr[++top]=data;
}