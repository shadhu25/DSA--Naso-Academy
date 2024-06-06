#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void print(struct node*);
struct node* addAtBeg(struct node*,int);
struct node* createLL(struct node*,int);
struct node* reverse(struct node*);
void back2Num(struct node*);
struct node* addTwoNum(struct node*,struct node*);

int main(){
    int number1, number2;
    printf("Enter the two numbers: ");
    scanf("%d %d",&number1,&number2);
    printf("\nLinked list representation of first number:- \n");
    struct node *head1=NULL;
    head1=createLL(head1,number1);
    print(head1);
    printf("\nLinked list representation of second number:- \n");
    struct node *head2=NULL;
    head2=createLL(head2,number2);
    print(head2);
    head1=reverse(head1);
    head2=reverse(head2);
    printf("\nRevered Linked Lists:- \n");
    print(head1);
    print(head2);
    struct node *head3=NULL;
    head3=addTwoNum(head1,head2);
    printf("\nResultent Linked List:-\n");
    print(head3);
    back2Num(head3);
    return 0;
}

struct node* addTwoNum(struct node *head1, struct node *head2){
    if(!head1->data)
        return head2;
    if(!head2->data)
        return head1;
    struct node *ptr1=head1;
    struct node *ptr2=head2;
    struct node *head3=NULL;
    int carry=0, sum;
    while(ptr1 || ptr2){
        sum=0;
        if(ptr1)
            sum+=ptr1->data;
        if(ptr2)
            sum+=ptr2->data;
        sum+=carry;

        carry=sum/10;
        sum=sum%10;

        head3=addAtBeg(head3, sum);

        if(ptr1)
            ptr1=ptr1->next;
        if(ptr2)
            ptr2=ptr2->next;
    }
    if(carry)
        head3=addAtBeg(head3,carry);
    return head3;
}

void back2Num(struct node *head){
    struct node *temp=head;
    printf("\nResult = ");
    while(temp){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

struct node* reverse(struct node *head){
    if(!head)
        return head;
    struct node *current=NULL, *next;
    next=head->next;
    head->next=NULL;
    while(next){
        current=next;
        next=next->next;
        current->next=head;
        head=current;
    }
    return head;
}

struct node* addAtBeg(struct node *head, int value){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->next=head;
    head=newNode;
    return head;
}

struct node* createLL(struct node *head, int number){
    while(number){
        head=addAtBeg(head,number%10);
        number=number/10;
    }
    return head;
}

void print(struct node *head){
    struct node *temp=head;
    if(!head)
        printf("No numbers\n");
    else{
        while(temp->next){
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}