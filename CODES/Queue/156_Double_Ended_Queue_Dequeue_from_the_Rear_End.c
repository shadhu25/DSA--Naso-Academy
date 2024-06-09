// implementing Double Ended Queue using array
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int deque[MAX];
int front=-1, rear=-1;

void print();
int peek();
int dequeueFront();
int dequeueRear();
void enqueueRear(int);
void enqueueFront(int);
int isEmpty();
int isFull();

int main(){
    int data,choice;
    while(1){
        printf("\n1.Insert at Front\n");
        printf("2.Insert at rear\n");
        printf("3.Delete at front\n");
        printf("4.Delete at rear\n");
        printf("5.Print the first element\n");
        printf("6.Print all elements of the queue\n");
        printf("7.Quit\n");
        printf("Please enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                if(!isFull()){
                    printf("Enter the element to be inserted: ");
                    scanf("%d",&data);
                    enqueueFront(data);
                }
                else{
                    printf("Queue Overflow!\n");
                }
                break;
            case 2:
                if(!isFull()){
                    printf("Enter the element to be inserted: ");
                    scanf("%d",&data);
                    enqueueRear(data);
                }
                else{
                    printf("Queue Overflow!\n");
                }
                break;
            case 3:
                 if(!isEmpty()){
                    data=dequeueFront();
                    printf("Deleted element is %d\n",data);
                }
                else{
                    printf("Queue underflow!\n");
                }
                break;
            case 4:
                 if(!isEmpty()){
                    data=dequeueRear();
                    printf("Deleted element is %d\n",data);
                }
                else{
                    printf("Queue underflow!\n");
                }
                break;
            case 5:
                if(!isEmpty()){
                    printf("The topmost element of the stack is %d\n",peek());
                }
                else{
                    printf("Queue underflow!\n");
                }
                break;
            case 6:
                if(!isEmpty())
                    print();
                else
                    printf("Queue underflow!\n");
                break;
            case 7:
                exit(1);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

int dequeueRear(){
    int data;
    // optional code for this program
    // if(isEmpty()){
    //     printf("Queue underflow!\n");
    //     exit(1);
    // }
    data=deque[rear];
    if(rear==front)
        rear=front=-1;
    else if(rear==0)
        rear=MAX-1;
    else
        rear--;
    return data;
}

void enqueueFront(int data){
    // optional code for this program
    // if(isFull()){
    //     printf("Queue overflow!\n");
    //     exit(1);
    // }
    if(rear==-1)
        rear=front=0;
    else if(front==0)
        front=MAX-1;
    else
        front--;
    deque[front]=data;
}

void print(){
    // optional code for this program
    // if(isEmpty()){
    //     printf("Queue underflow!\n");
    //     exit(1);
    // }
    printf("[ ");
    int temp=front;
    if(front<=rear){
        while(temp<=rear)
            printf("%d ",deque[temp++]);
    }
    else{
        while(temp<=MAX-1)
            printf("%d ",deque[temp++]);
        temp=0;
        while(temp<=rear)
            printf("%d ",deque[temp++]);
    }
    printf("]\n");
}

int peek(){
    // optional code for this program
    // if(isEmpty()){
    //     printf("Queue underflow!\n");
    //     exit(1);
    // }
    return deque[front];
}

int dequeueFront(){
    int data;
    // optional code for this program
    // if(isEmpty()){
    //     printf("Queue underflow!\n");
    //     exit(1);
    // }
    data=deque[front];
    if(rear==front)
        rear=front=-1;
    else if(front==MAX-1)
        front=0;
    else
        front++;
    return data;
}

int isEmpty(){
    return front==-1;
}

int isFull(){
    return (front==0 && rear==MAX-1) || (front==rear+1);
}

void enqueueRear(int data){
    // optional code for this program
    // if(isFull()){
    //     printf("Queue overflow!\n");
    //     exit(1);
    // }
    if(front==-1)
        front=0;
    if(rear==MAX-1)
        rear=0;
    else
        rear++;
    deque[rear]=data;
}