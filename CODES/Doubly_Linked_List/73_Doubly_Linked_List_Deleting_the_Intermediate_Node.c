// deleting at certain position
#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct myNode {
    int size;
    struct node *head;
}mynode;

void print(struct node*);
struct node* addAtEnd(struct node*, int);
struct myNode createDlist(struct node*);
struct node* delAtBeg(struct node*);
struct node* delAtEnd(struct node*);
struct node* delAtPos(struct node*, int);

int main(){
    struct node *head=NULL; 
    mynode=createDlist(head);
    head=mynode.head;
    print(head);
    head=delAtPos(head,100);
    print(head);
    return 0;
}

struct node* delAtPos(struct node *head, int position){
    struct node *temp=head;
    if(position<1){
        printf("Try again, You entered a invalid position number(%d)\n",position);
    }
    else{
        if(position<=mynode.size){
            if(!head || !head->next){
                head=delAtBeg(head);
            }
            else{
                while(position>1){
                    temp=temp->next;
                    position--;
                }
                if(!temp->next){
                    temp->prev->next=NULL;
                    temp=delAtEnd(temp);
                }
                else{
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                    free(temp);
                    temp=NULL;
                }
            }
        }
        else{
            printf("Try again, List has only %d element, so we can't delete the %dth positon element.\n",mynode.size,position);
        }
    }
    return head;
}

struct node* delAtEnd(struct   node *head){
    struct node *temp=head;
    if(!head || !head->next)
        head=delAtBeg(head);
    else{
        while(temp->next->next){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
    return head;
}   

struct node* delAtBeg(struct node *head){
    if(!head)
        printf("list is empty!");
    else if(!head->next){
        free(head);
        head=NULL;
    }
    else{
        head=head->next;
        free(head->prev);
    }
    return head;
}

struct myNode createDlist(struct node *head){
    int size,data;
    struct myNode mynode;
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
    mynode.head=head;
    mynode.size=size;
    return mynode;
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