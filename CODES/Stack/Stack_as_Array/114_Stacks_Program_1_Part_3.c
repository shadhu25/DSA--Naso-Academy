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
int pop();
int peek();

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

int peek(){
    if(isEmpty()){
        printf("Stack underflow!\n");
        return;
    }
    return stackArr[0];
}

int pop(){
    if(isEmpty()){
        printf("Stack underflow!\n");
        return;
    }
    int value;
    value=stackArr[0];
    for(int i=0;i<first;i++)
        stackArr[i]=stackArr[i+1];
    first--;
    printf("the poped element is: ");
    return value;
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