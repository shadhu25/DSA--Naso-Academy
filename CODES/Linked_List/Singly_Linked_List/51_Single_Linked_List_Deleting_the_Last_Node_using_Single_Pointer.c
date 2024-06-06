// deleting a node at end of the linklist(using single pointer)
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* addAtEnd(struct node*, int);
struct node* delAtEnd(struct node*);
void print(struct node*);
int main(){
    struct node *head=NULL;
    head=addAtEnd(head,45);
    head=addAtEnd(head,46);
    head=addAtEnd(head,47);
    print(head);
    head=delAtEnd(head);
    print(head);
    return 0;
}
struct node* delAtEnd(struct node *head){
    if(head==NULL)
    printf("Linked list is already empty!\n");
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node *temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
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