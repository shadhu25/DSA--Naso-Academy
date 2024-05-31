// inserting at end
#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node* addAtEnd(struct node*, int);

int main(){
    struct node *head=NULL;
    head=addAtEnd(head,45);
    head=addAtEnd(head,46);
    printf("%d ",head->data);
    printf("%d\n",head->next->data);
    return 0;
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
