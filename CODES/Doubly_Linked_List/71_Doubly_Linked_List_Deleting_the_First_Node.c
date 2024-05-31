// Deleting the first node
#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

void print(struct node*);
struct node* addAtEnd(struct node*, int);
struct node* createDlist(struct node*);
struct node* delAtBeg(struct node*);

int main(){
    struct node *head=NULL;
    head=createDlist(head);
    print(head);
    head=delAtBeg(head);
    print(head);
    return 0;
}

struct node* delAtBeg(struct node *head){
    if(!head)
        printf("list is empty!");
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        head=head->next;
        free(head->prev);
    }
    return head;
}

struct node* createDlist(struct node *head){
    int size,data;
    printf("Please Enter number of nodes: ");
    scanf("%d",&size);
    if(size<1){
        printf("Try again, You entered envalid size(%d)\n",size);
    }
    else{
        for(int i=0;i<size;i++){
            printf("enter node %d: ",i+1);
            scanf("%d",&data);
            head=addAtEnd(head,data);
        }
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