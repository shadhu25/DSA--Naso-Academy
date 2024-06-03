// implementing stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *top=NULL;

void print();
void push(int);

int main(){
    push(55);
    push(56);
    push(57);
    print();
    return 0;
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
        printf("Stack element are:- \n");
        printf("[ ");
        while(temp){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("]\n");
}