// adding a new node at end of the linklist
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* addAtEnd(struct node*, int);
void print(struct node*);
int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->next=NULL;
    struct node *current=malloc(sizeof(struct node));
    current->data=46;
    current->next=NULL;
    head->next=current;
    current=malloc(sizeof(struct node));
    current->data=47;
    current->next=NULL;
    head->next->next=current;
    print(head);
    head=addAtEnd(head,48);
    print(head);
    return 0;
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