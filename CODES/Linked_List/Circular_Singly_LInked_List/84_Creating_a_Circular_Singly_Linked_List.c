// creating an entire circular singly linked list
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* addToEmpty(int);
struct node* addAtEnd(struct node*,int);
void print(struct node*);
struct node* createCircularSingly(struct node*);

int main(){
    struct node *tail=NULL;
    tail=createCircularSingly(tail);
    print(tail);
    return 0;
}

struct node* createCircularSingly(struct node *tail){
    int size,data;
    printf("Please enter the number of nodes: ");
    scanf("%d",&size);
    if(size<1)
        printf("Try again, you entered invalid size(%d)\n",size);
    else{
        printf("Enter node1: ");
        scanf("%d",&data);
        tail=addToEmpty(data);
        for(int i=1;i<size;i++){
            printf("Enter node%d: ",i+1);
            scanf("%d",&data);
            tail=addAtEnd(tail,data);
        }
    }
    return tail;
}

void print(struct node *tail){
    if(!tail)
        printf("list is empty!\n");
    else{
        struct node *temp=tail->next;
        printf("[ ");
        do{
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=tail->next);
        printf("]\n");
    }
}

struct node* addToEmpty(int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=newNode;
    return newNode;
}

struct node* addAtEnd(struct node *tail,int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=tail->next;
    tail->next=newNode;
    return newNode;
}