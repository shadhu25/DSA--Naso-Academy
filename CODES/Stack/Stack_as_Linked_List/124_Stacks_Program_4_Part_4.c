// stack program 4 -> reversing a stack
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int isEmpty(struct node*);
struct node* push(struct node*, int);
void print(struct node*);
struct node* pop(struct node*);

int main(){
    struct node *stack, *temp, *temp1, *temp2;
    stack=temp1=temp2=NULL;
    stack=push(stack,1);
    stack=push(stack,2);
    stack=push(stack,3);
    temp=pop(stack);
    stack=temp->next;
    temp1=push(temp1,temp->data);
    temp=pop(stack);
    stack=temp->next;
    temp1=push(temp1,temp->data);
    print(stack);
    print(temp1);
    return 0;
}

struct node* pop(struct node *top){
    struct node *temp;
    if(isEmpty(top)){
        printf("Stack underflow!\n");
        exit(1);
    }
    temp=top;
    top=top->next;
    return temp;
}

struct node* push(struct node *top, int data){
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
    return top;
}

int isEmpty(struct node *top){
    return top==NULL;
}

void print(struct node *top){
        struct node *temp=top;
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