// Stack program 5 -> checking palindrome using stack
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *top=NULL;

void push(int);
int isEmpty();
int pop();
void checkPalindrome(char *s){
    int i;
    for(i=0;s[i]!='X';i++)
        push(s[i]);
    i++;
    while(s[i]){
        if(isEmpty() || s[i] != pop()){
            printf("Not a palindrome!\n");
            exit(1);
        }
        i++;
    }
    printf("Palindrome!\n");
}

int main(){
    int data,choice;
    char s[100];
    printf("Please enter the string: ");
    scanf("%s",s);
    checkPalindrome(s);
    return 0;
}

int pop(){
    struct node *temp;
    int value;
    if(isEmpty()){
        printf("Stack underflow!\n");
        exit(1);
    }
    temp=top;
    value=temp->data;
    top=top->next;
    free(temp);
    temp=NULL;
    return value;
}

int isEmpty(){
    return top==NULL;
}

void push(int data){
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Stack overflow!\n");
        exit(1);
    }
    else{
        newNode->data=data;
        newNode->next=NULL;
        newNode->next=top;
        top=newNode;
    }
}