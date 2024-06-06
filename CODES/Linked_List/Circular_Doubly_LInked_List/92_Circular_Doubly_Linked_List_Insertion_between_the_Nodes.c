// Inserting an element after a position
#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node* addAtEnd(struct node*,int);
void print(struct node*);
struct node* addAfterPos(struct node*,int,int);

int main(){
    struct node *tail=NULL;
    tail=addAtEnd(tail,45);
    tail=addAtEnd(tail,47);
    tail=addAtEnd(tail,48);
    tail=addAtEnd(tail,49);
    tail=addAtEnd(tail,50);
    print(tail);
    tail=addAfterPos(tail,3,44);
    print(tail);
    return 0;
}

struct node* addAfterPos(struct node *tail,int position, int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    if(!tail){
        newNode->next=newNode;
        newNode->prev=newNode;
        return newNode;
    }
    else{
        struct node *temp=tail->next;
        while(position>1){
            temp=temp->next;
            position--;
        }
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next->prev=newNode;
        temp->next=newNode;
        // handling the case of inserting at the end of the list
        if(temp==tail)
            tail=newNode;
        return tail;
    }
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

struct node* addAtEnd(struct node *tail, int data){
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