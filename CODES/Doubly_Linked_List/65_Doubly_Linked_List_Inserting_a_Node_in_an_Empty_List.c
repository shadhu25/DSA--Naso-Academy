// Inserting an element to an empty Doubly linkedlist
#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node* addToEmpty(int);

int main(){
    struct node *head=addToEmpty(45);
    printf("%d\n",head->data);
    return 0;
}

struct node* addToEmpty(int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    return temp;
}