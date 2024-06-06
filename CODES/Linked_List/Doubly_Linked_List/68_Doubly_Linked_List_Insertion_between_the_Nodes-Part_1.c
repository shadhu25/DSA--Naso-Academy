// Inserting after a given position
#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

void print(struct node*);
struct node* addAtEnd(struct node*, int);
void addAfterPos(struct node*, int, int);

int main(){
    struct node *head=NULL;
    head=addAtEnd(head,45);
    head=addAtEnd(head,46);
    head=addAtEnd(head,47);
    head=addAtEnd(head,48);
    head=addAtEnd(head,49);
    print(head);
    addAfterPos(head,4,50);
    print(head);
    return 0;
}

void addAfterPos(struct node *head, int position, int data){
    struct node *temp, *temp2, *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->prev=NULL;
    newNode->data=data;
    newNode->next=NULL;
    
    if(!head || !head->next){
        head=addAtEnd(head,data);
    }
    else{
        temp=head;
        while(position!=1){
            temp=temp->next;
            position--;
        }
        temp2=temp->next;
        temp->next=newNode;
        temp2->prev=newNode;
        newNode->prev=temp;
        newNode->next=temp2;
    }
}

struct node* addAtEnd(struct node *head, int data){
    struct node *temp, *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->prev=NULL;
    newNode->data=data;
    newNode->next=NULL;
    if(!head){ 
        return newNode;
    }
    else{
        temp=head;
        while(temp->next){
            temp=temp->next;
        }
        newNode->prev=temp;
        temp->next=newNode;
        return head;
    }
}

void print(struct node *head){
    if(!head)
        printf("Linkedlist is empty!\n");
    else{
        struct node *temp=head;
        printf("[ ");
        while(temp){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("]\n");
    }
}