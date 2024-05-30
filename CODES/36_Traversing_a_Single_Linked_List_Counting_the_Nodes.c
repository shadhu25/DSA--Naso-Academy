// traversal and counting nodes of a single linklist
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void countNodes(struct node*);
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
    printf("%d ",head->data);
    printf("%d ",head->next->data);
    printf("%d \n",head->next->next->data);
    countNodes(head);
    return 0;
}
void countNodes(struct node *head){
    int count=0;
    if(head==NULL)
        printf("Linkedlist is empty!\n");
    else{
        struct node *temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        printf("total nodes: %d\n",count);
    }
}