// stack program 4 -> reversing a stack
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *stack=NULL;

void print(struct node**);
void push(struct node**, int);
int peek(struct node**);
int isEmpty(struct node**);
int pop(struct node**);
void reverse(struct node**);

int main(){
    int data,choice;
    while(1){
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Print the top element\n");
        printf("4.Print all elements of the stack\n");
        printf("5.Rverse the stack\n");
        printf("6.Quit\n");
        printf("Please enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d",&data);
                push(&stack,data);
                break;
            case 2:
                if(!isEmpty(&stack)){
                    data=pop(&stack);
                    printf("Deleted element is %d\n",data);
                }
                else{
                    printf("Stack underflow!\n");
                }
                break;
            case 3:
                if(!isEmpty(&stack)){
                    printf("The topmost element of the stack is %d\n",peek(&stack));
                }
                else{
                    printf("Stack underflow!\n");
                }
                break;
            case 4:
                print(&stack);
                break;
            case 5:
                reverse(&stack);
                printf("Stack is reversed\n");
                break;
            case 6:
                exit(1);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void reverse(struct node **stack){
    struct node *temp1, *temp2;
    temp1=temp2=NULL;
    while(*stack){
        push(&temp1,pop(stack));
    }
    while(temp1){
        push(&temp2,pop(&temp1));
    }
    while(temp2){
        push(stack,pop(&temp2));
    }
}

int pop(struct node **top){
    struct node *temp;
    int value;
    temp=*top;
    value=temp->data;
    *top=(*top)->next;
    free(temp);
    temp=NULL;
    return value;
}

int peek(struct node **top){
    return (*top)->data;
}

int isEmpty(struct node **top){
    return *top==NULL;
}

void push(struct node **top, int data){
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Stack overflow!\n");
    }
    else{
        newNode->data=data;
        newNode->next=NULL;
        newNode->next=*top;
        *top=newNode;
    }
}

void print(struct node **top){
        struct node *temp=*top;
        if(isEmpty(top)){
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