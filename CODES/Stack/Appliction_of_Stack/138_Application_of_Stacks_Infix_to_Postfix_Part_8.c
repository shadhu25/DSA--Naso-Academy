// infix to postfix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int stack[MAX];
char infix[MAX], postfix[MAX];
int top=-1;

void push(int);
int pop();
int peek();
int isEmpty();
int isFull();
void print();
void inToPost();
int isSpace(char);
int precedence(char);
int evaluatePost();
int pow(int a, int b){
    int i, mult=1;
    for(i=0;i<b;i++)
        mult*=a;
    return mult;
}

int main(){
    int balabced;
    printf("Enter the algebraic expression: ");
    gets(infix);
    
    inToPost();
    int result=evaluatePost();
    print();
    printf("the result obtained after postfix evaluation is: ");
    printf("%d\n",result);
    return 0;
}

int evaluatePost(){
    int i;
    int a,b;
    for(i=0;i<strlen(postfix);i++){
        // if the symbol is an operand
        if(postfix[i]>='0' && postfix[i]<='9')
            push(postfix[i]-'0');
        else{
            // pop the topmost symbols
            a=pop();
            b=pop();

            switch(postfix[i]){
                case '+':
                    push(b+a); break;
                case '-':
                    push(b-a); break;
                case '*':
                    push(b*a); break;
                case '/':
                    push(b/a);
                case '^':
                    push(pow(b,a)); break;
            }
        }
    }
    return pop();
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

int isEmpty(){
    return top==-1;
}

int pop(){
    if(isEmpty()){
        printf("stack underflow");
        exit(1);
    }
    int value;
    value=stack[top--];
    return value;
}

void push(int data){
    if(isFull()){
        printf("Stack overflow!\n");
        exit(1);
    }
    stack[++top]=data;
}

int isFull(){
    return top==MAX-1;
}

int peek(){
    if(isEmpty()){
        printf("stack underflow");
        exit(1);
    }
    return stack[top];
}

void print(){
    int i=0;
    printf("the equavalent postfix expression is: ");
    while(postfix[i])
        printf("%c",postfix[i++]);
    printf("\n");
}