// deleting at certain position
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct myNode {
    int size;
    struct node *tail;
}mynode;

struct node* addToEmpty(int);
struct node* addAtEnd(struct node*,int);
void print(struct node*);
void createCircularSingly(struct node*);
struct node* delAtPos(struct node*,int);

int main(){
    struct node *tail=NULL;
    createCircularSingly(tail);
    tail=mynode.tail;
    print(tail);
    tail=delAtPos(tail,3);
    print(tail);
    return 0;
}

struct node* delAtPos(struct node *tail,int position){
    if(position<1){
        printf("Try again, You entered a invalid position number(%d)\n",position);
    }
    else{
        if(position<=mynode.size){
            if(!tail)
                return tail;
            if(tail->next==tail){
                free(tail);
                tail=NULL;
                return tail;
            }
            else{
                struct node *temp2, *temp=tail;
                while(position>1){
                    temp=temp->next;
                    position--;
                }
                temp2=temp->next;
                temp->next=temp2->next;
                //handling the case of deleting the last node.
                if(temp2==tail)
                    tail=temp;
                free(temp2);
                temp2=NULL;
                return tail;
            }
        }
        else{
            printf("Try again, List has only %d element, so we can't delete the %dth positon element.\n",mynode.size,position);
        }
    }
    return tail;
}
void createCircularSingly(struct node *tail){
    int size,data;
    printf("Please enter the number of nodes: ");
    scanf("%d",&size);
    if(size<1)
        printf("Try again, you entered invalid size(%d)\n",size);
    else{
        printf("Enter node1: ");
        scanf("%d",&data);
        tail=addToEmpty(data);
        mynode.size=size;
        for(int i=1;i<size;i++){
            printf("Enter node%d: ",i+1);
            scanf("%d",&data);
            tail=addAtEnd(tail,data);
        }
    }
    mynode.tail=tail;
}

void print(struct node *tail){
    if(!tail)
        printf("list is empty\n");
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