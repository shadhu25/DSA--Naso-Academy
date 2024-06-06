// infix to postfix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX], infix[MAX], postfix[MAX];
int top=-1;

void push(char);
char pop();
int isEmpty();
int isFull();
int checkBalanced(char*);
int matchChar(char,char);
void print();
char peek();
void inToPost();
int isSpace(char);
int precedence(char);
void print1();

int main(){
    int balabced;
    printf("Enter the algebraic expression: ");
    gets(infix);
    printf("%s\n",infix);
    balabced=checkBalanced(infix);

    if(balabced){
        inToPost();
        print1();
    }
    else{
        printf("The expression is not valid\n");
    }
    return 0;
}

void inToPost(){
    int i, j=0;
    char symbol, next;
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        // if symbol is not whitespace or tab
        if(!isSpace(symbol)){
            switch(symbol){
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while((next=pop())!='(')
                        postfix[j++]=next;
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while(!isEmpty() && precedence(peek()) >= precedence(symbol))
                        postfix[j++]=pop();
                    push(symbol);
                    break;
                default:
                    // if the symbol is an operand
                    postfix[j++]=symbol;
            }
        }
    }
    while(!isEmpty())
        postfix[j++]=pop();
    postfix[j]='\0';
}

void print1(){
    int i=0;
    printf("the equivalent postfix expression is: ");
    while(postfix[i])
        printf("%c",postfix[i++]);
    printf("\n");
}

int precedence(char symbol){
    switch(symbol){
        // higher value means greater precedence
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int isSpace(char c){
    // if the symbol is a space or a tab
    if(c==' ' || c=='\t')
        return 1;
    else
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

char peek(){
    if(isEmpty()){
        printf("stack underflow");
        exit(1);
    }
    return stack[top];
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