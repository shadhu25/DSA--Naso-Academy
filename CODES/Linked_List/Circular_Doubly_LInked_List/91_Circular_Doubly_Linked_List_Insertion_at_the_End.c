// Inserting an element at beg
#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node* adAtEnd(struct node*,int);
void print(struct node*);

int main(){
    struct node *tail=NULL;
    tail=adAtEnd(tail,45);
    tail=adAtEnd(tail,47);
    tail=adAtEnd(tail,48);
    tail=adAtEnd(tail,49);
    tail=adAtEnd(tail,50);
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

struct node* adAtEnd(struct node *tail, int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    if(!tail){
        newNode->next=newNode;
        newNode->prev=newNode;
    }
    else{
        newNode->prev=tail;
        newNode->next=tail->next;
        tail->next=newNode;
    }
    return newNode;
}
