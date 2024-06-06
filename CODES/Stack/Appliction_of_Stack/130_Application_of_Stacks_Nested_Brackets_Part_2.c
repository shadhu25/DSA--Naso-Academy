// Array implementation of stack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top=-1;

void push(char);
char pop();
int isEmpty();
int isFull();
int checkBalanced(char*);
int matchChar(char,char);
void print();

int main(){
    char expr[MAX];
    int balabced;
    printf("Enter the algebraic expression: ");
    scanf("%s",expr);
    printf("%s\n",expr);
    balabced=checkBalanced(expr);

    if(balabced){
        printf("The expression is valid\n");
    }
    else{
        printf("The expression is not valid\n");
    }
    return 0;
}

int matchChar(char a, char b){
    if(a == '{' && b == '}')
        return 1;
    if(a == '(' && b == ')')
        return 1;
    if(a == '[' && b == ']')
        return 1;
    return 0;
}

int checkBalanced(char *s){
    char temp;
    for(int i=0;i<strlen(s);i++){
        // if the symbol is a left bracket, then push that symbol onto stack
        if(s[i]=='[' || s[i]=='{' || s[i]=='(')
            push(s[i]);
        // if the symbol is a bracket
        if(s[i]==']' || s[i]=='}' || s[i]==')'){
            if(isEmpty()){
                printf("Right brackets are more than the left.\n");
                return 0;
            }
            else{
                temp=pop();
                if(!matchChar(temp,s[i])){
                    printf("Miscmatched brackets.\n");
                    return 0;
                }
            }
        }
    }
    if(isEmpty()){
        printf("Brackets are well balanced.\n");
        return 1;
    }
    else{
        printf("Left btackets are more than the right.\n");
        return 0;
    }
}

int isEmpty(){
    return top==-1;
}

char pop(){
    if(isEmpty()){
        printf("stack underflow");
        exit(1);
    }
    char value;
    value=stack[top--];
    return value;
}

void push(char data){
    if(isFull()){
        printf("Stack overflow!\n");
        exit(1);
    }
    stack[++top]=data;
}

int isFull(){
    return top==MAX-1;
}

void print(){
    if(isEmpty()){
        printf("Stack underflow!\n");
        return;
    }
    int i=top;
    printf("[ ");
    while(i>=0)
        printf("%c ",stack[i--]);
    printf("]\n");
}