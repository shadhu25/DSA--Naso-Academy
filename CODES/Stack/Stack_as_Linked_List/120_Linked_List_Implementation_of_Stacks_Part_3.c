// implementing stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *top=NULL;

void print();
void push(int);
int peek();
int isEmpty();
int pop();

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
                if(!isEmpty()){
                    printf("The topmost element of the stack is %d\n",peek());
                }
                else{
                    printf("Stack underflow!\n");
                }
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

int pop(){
    struct node *temp;
    int value;
    temp=top;
    value=temp->data;
    top=top->next;
    free(temp);
    temp=NULL;
    return value;
}

int peek(){
    return top->data;
}

int isEmpty(){
    return top==NULL;
}

void push(int data){
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Stack overflow!\n");
    }
    else{
        newNode->data=data;
        newNode->next=NULL;
        newNode->next=top;
        top=newNode;
    }
}

void print(){
        struct node *temp=top;
        if(isEmpty()){
            printf("Stack underflow!\n");
        }
        else{
            printf("Stack element are:- \n");
            printf("[ ");
            while(temp){
                printf("%d ",temp->data);
                temp=temp->next;
            }
            printf("]\n");
        }
}