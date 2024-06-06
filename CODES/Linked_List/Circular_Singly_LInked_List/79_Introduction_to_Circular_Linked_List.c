// creating the first node
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* circleSingly(int);

int main(){
    struct node *tail=circleSingly(45);
    printf("%d\n",tail->data);
    return 0;
}

struct node* circleSingly(int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=newNode;
    return newNode;
}