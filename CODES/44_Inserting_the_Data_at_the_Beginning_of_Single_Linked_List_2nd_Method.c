// adding a new node at begining of the linklist(2nd method)
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* addAtEnd(struct node*, int);
void addAtBeg(struct node**, int);
void print(struct node*);
int main(){
    struct node *head=NULL;
    head=addAtEnd(head,45);
    head=addAtEnd(head,46);
    head=addAtEnd(head,47);
    print(head);
    addAtBeg(&head,48);
    print(head);
    return 0;
}
struct node* addAtEnd(struct node *head, int data){
    struct node *temp, *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
        newNode->data=data;
        newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    return head;
}
void addAtBeg(struct node **head, int data){
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
        newNode->data=data;
        newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
    }
    else{
        newNode->next=*head;
        *head=newNode;
    }
}
void print(struct node *head){
    if(head==NULL)
        printf("Linkedlist is empty!\n");
    else{
        struct node *temp=head;
        printf("[ ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("]\n");
    }
}