
// Inserting before a given position
#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

void print(struct node*);
struct node* addAtBeg(struct node*, int);
struct node* addAtEnd(struct node*, int);
struct node* addBeforePos(struct node*, int, int);

int main(){
    struct node *head=NULL;
    head=addAtEnd(head,45);
    head=addAtEnd(head,46);
    head=addAtEnd(head,47);
    head=addAtEnd(head,48);
    head=addAtEnd(head,49);
    print(head);
    head=addBeforePos(head,4,50);
    print(head);
    return 0;
}

struct node* addBeforePos(struct node *head, int position, int data){
    struct node *temp, *temp2, *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->prev=NULL;
    newNode->data=data;
    newNode->next=NULL;
    if(!head || !head->next){
        head=addAtBeg(head,data);
    }
    else{
        temp=head;
        while(position>2){
            temp=temp->next;
            position--;
        }
        temp2=temp->next;
        temp->next=newNode;
        temp2->prev=newNode;
        newNode->prev=temp;
        newNode->next=temp2;
    }
    return head;
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