// adding a new node at begining of the linklist
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* addAtEnd(struct node*, int);
struct node* addAtBeg(struct node*, int);
void print(struct node*);
int main(){
    struct node *head=NULL;
    head=addAtEnd(head,45);
    head=addAtEnd(head,46);
    head=addAtEnd(head,47);
    print(head);
    head=addAtBeg(head,48);
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
struct node* addAtBeg(struct node *head, int data){
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
        newNode->data=data;
        newNode->next=NULL;
        newNode->next=head;
        head=newNode;
        return head;
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