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
    int data;
    struct node *stack, *temp, *temp1, *temp2;
    stack=temp1=temp2=NULL;
    push(&stack,1);
    push(&stack,2);
    push(&stack,3);
    print(&stack);
    // from original stack to temporary stack 1
    data=pop(&stack);
    push(&temp1,data);
    data=pop(&stack);
    push(&temp1,data);
    data=pop(&stack);
    push(&temp1,data);
    print(&stack);
    print(&temp1);
    // from temporaray stack 1 to temporary stack 2
    data=pop(&temp1);
    push(&temp2,data);
    data=pop(&temp1);
    push(&temp2,data);
    data=pop(&temp1);
    push(&temp2,data);
    print(&temp1);
    print(&temp2);
    // from temporary stack 2 to original stack
    data=pop(&temp2);
    push(&stack,data);
    data=pop(&temp2);
    push(&stack,data);
    data=pop(&temp2);
    push(&stack,data);
    print(&temp2);
    print(&stack);
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