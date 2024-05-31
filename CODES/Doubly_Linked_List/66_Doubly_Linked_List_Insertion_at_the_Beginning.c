// inserting at begining
#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node* addToEmpty(int);
struct node* addAtBeg(struct node*, int);

int main(){
    struct node *head=addToEmpty(45);
    printf("%d\n",head->data);
    head=addAtBeg(head,44);
    printf("%d ",head->data);
    printf("%d\n",head->next->data);
    return 0;
}

struct node* addAtBeg(struct node *head, int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->prev=NULL;
    newNode->data=data;
    newNode->next=NULL;
    if(!head){}
    else{
        newNode->next=head;
        head->prev=newNode;
    }
    return newNode;
}

struct node* addToEmpty(int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    return temp;
}