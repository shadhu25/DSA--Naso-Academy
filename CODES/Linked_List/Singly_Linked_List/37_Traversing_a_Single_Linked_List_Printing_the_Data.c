// traversal and printing nodes of a single linklist
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
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