// Inserting an element at beg
#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

void print(struct node*);
struct node* adAtBeg(struct node*,int);

int main(){
    struct node *tail=NULL;
    tail=adAtBeg(tail,45);
    tail=adAtBeg(tail,47);
    tail=adAtBeg(tail,48);
    tail=adAtBeg(tail,49);
    tail=adAtBeg(tail,50);
    print(tail);
    return 0;
}

void print(struct node *tail){
    if(!tail)
        printf("list is empty\n");
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

struct node* adAtBeg(struct node *tail, int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    if(!tail){
        newNode->next=newNode;
        newNode->prev=newNode;
        return newNode;
    }
    else{
        newNode->next=tail->next;
        newNode->next->prev=newNode;
        newNode->prev=tail;
        tail->next=newNode;
        return tail;
    }
}