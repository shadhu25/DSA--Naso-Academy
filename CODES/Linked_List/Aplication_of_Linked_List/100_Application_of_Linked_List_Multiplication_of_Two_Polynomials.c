// Multiplication of two polynomials
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
struct node*  mulPoly(struct node*, struct node*);

int main(){
    struct node *poly1, *poly2, *poly3;
    poly1=poly2=poly3=NULL;
    printf("\nEnter the Polynomial1:- \n");
    poly1=createPoly(poly1);
    printf("\nEnter the Polynomial2:- \n");
    poly2=createPoly(poly2);
    printf("\n the Polynomial1:- \n");
    print(poly1);
    printf("\nthe Polynomial2:- \n");
    print(poly2);
    poly3=mulPoly(poly1,poly2);
    printf("\nAdded Polynomial:- \n");
    print(poly3);
    return 0;
}

struct node*  mulPoly(struct node *poly1, struct node *poly2){
    struct node *poly3=NULL, *ptr1, *ptr2;
    if(!poly1 || !poly2)
        printf("Zero Polynomial\n");
    else{
        ptr1=poly1;
        while(ptr1){
            ptr2=poly2;
            while(ptr2){
                poly3=insert(poly3, ptr1->coeff * ptr2->coeff, ptr1->expo + ptr2->expo);
                ptr2=ptr2->next;
            }
            ptr1=ptr1->next;
        }
    }
    return poly3;
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
                printf("+ ");
        }
    }
}