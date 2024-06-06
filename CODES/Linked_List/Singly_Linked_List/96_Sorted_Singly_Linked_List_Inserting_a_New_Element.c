// inserting in sorted list
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

void print(struct node*);
struct node* addInSorted(struct node*,int);

int main(){
    struct node *head=NULL;
    head=addInSorted(head,1);
    head=addInSorted(head,3);
    head=addInSorted(head,2);
    head=addInSorted(head,5);
    head=addInSorted(head,1);
    print(head);
    return 0;
}

struct node* addInSorted(struct node *head, int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    int key=data;
    if(!head || key < head->data){
        newNode->next=head;
        head=newNode;
    }
    else{
        struct node *temp=head;
        while(temp->next && temp->next->data < key)
            temp=temp->next;
        newNode->next=temp->next;
        temp->next=newNode;
    }
    return head;
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