// inserting at beg
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* addToEmpty(int);
void addAtBeg(struct node*,int);

int main(){
    struct node *tail=addToEmpty(45);
    addAtBeg(tail,44);
    printf("%d ",tail->next->data);
    printf("%d \n",tail->next->next->data);
    return 0;
}

struct node* addToEmpty(int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=newNode;
    return newNode;
}

void addAtBeg(struct node *tail,int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=tail->next;
    tail->next=newNode;
}