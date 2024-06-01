// creating Plynomials
#include<stdio.h>
#include<stdlib.h>

struct node {
    float coeff;
    int expo;
    struct node *next;
};

void print(struct node*);
struct node* insert(struct node*,float,int);
struct node* createPoly(struct node*);

int main(){
    struct node *poly=NULL;
    printf("Enter the Polynomial:- \n");
    poly=createPoly(poly);
    print(poly);
    return 0;
}

struct node* createPoly(struct node *poly){
    int expo,size;
    float coeff;
    printf("Enter the total terms: ");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        printf("Enter the coeffitient of term %d: ",i+1);
        scanf("%f",&coeff);
        printf("Enter the exponent of term %d: ",i+1);
        scanf("%d",&expo);
        poly=insert(poly,coeff,expo);
    }
    return poly;
}

struct node* insert(struct node *head, float coeff, int expo){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->coeff=coeff;
    newNode->expo=expo;
    int key=expo;
    if(!head || key > head->expo){
        newNode->next=head;
        head=newNode;
    }
    else{
        struct node *temp=head;
        while(temp->next && temp->next->expo > key)
            temp=temp->next;
        newNode->next=temp->next;
        temp->next=newNode;
    }
    return head;
}

void print(struct node *poly){
    if(!poly)
        printf("No Polynomial!\n");
    else{
        struct node *temp=poly;
        while(temp){
            printf("%.1fx^%d ",temp->coeff,temp->expo);
            temp=temp->next;
            if(!temp)
                printf("\n");
            else
                printf("+");
        }
    }
}