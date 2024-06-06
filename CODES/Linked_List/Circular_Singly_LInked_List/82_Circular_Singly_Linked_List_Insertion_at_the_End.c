// inserting at end
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* addToEmpty(int);
struct node* addAtEnd(struct node*,int);
void print(struct node*);

int main(){
    struct node *tail=addToEmpty(45);
    tail=addAtEnd(tail,44);
    tail=addAtEnd(tail,46);
    tail=addAtEnd(tail,47);
    tail=addAtEnd(tail,48);
    tail=addAtEnd(tail,49);
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

struct node* addAtEnd(struct node *tail,int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=tail->next;
    tail->next=newNode;
    return newNode;
}