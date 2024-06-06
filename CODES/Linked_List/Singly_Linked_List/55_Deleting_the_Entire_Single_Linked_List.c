// deleting the entire linklist
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* addAtEnd(struct node*, int);
struct node* delList(struct node*);
void print(struct node*);
int main(){
    struct node *head=NULL;
    head=addAtEnd(head,45);
    head=addAtEnd(head,46);
    head=addAtEnd(head,47);
    print(head);
    head=delList(head);
    print(head);
    return 0;
}
struct node* delList(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        temp=temp->next;
        free(head);
        head=temp;
    }
    return head;
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