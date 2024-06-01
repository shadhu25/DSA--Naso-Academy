// traversing and printing
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* addToEmpty(int);
void addAtBeg(struct node*,int);
void print(struct node*);

int main(){
    struct node *tail=NULL;
    tail=addToEmpty(45);
    addAtBeg(tail,44);
    addAtBeg(tail,46);
    addAtBeg(tail,47);
    addAtBeg(tail,48);
    addAtBeg(tail,49);
    print(tail);
    return 0;
}

void print(struct node *tail){
    if(!tail)
        printf("list is empty!\n");
    else{
        struct node *temp=tail->next;
        printf("[ ");
        do{
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=tail->next);
        printf("]\n");
    }
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