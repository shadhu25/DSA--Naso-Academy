// implementing Circular Queue using array
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front=-1, rear=-1;

void print();
int peek();
int dequeue();
void enqueue(int);
int isEmpty();
int isFull();

int main(){
    int data,choice;
    while(1){
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Print the first element\n");
        printf("4.Print all elements of the queue\n");
        printf("5.Quit\n");
        printf("Please enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                if(!isFull()){
                    printf("Enter the element to be inserted: ");
                    scanf("%d",&data);
                    enqueue(data);
                }
                else{
                    printf("Queue Overflow!\n");
                }
                break;
            case 2:
                 if(!isEmpty()){
                    data=dequeue();
                    printf("Deleted element is %d\n",data);
                }
                else{
                    printf("Queue underflow!\n");
                }
                break;
            case 3:
                if(!isEmpty()){
                    printf("The topmost element of the stack is %d\n",peek());
                }
                else{
                    printf("Queue underflow!\n");
                }
                break;
            case 4:
                if(!isEmpty())
                    print();
                else
                    printf("Queue underflow!\n");
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
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
            printf("%d ",queue[temp++]);
    }
    else{
        while(temp<=MAX-1)
            printf("%d ",queue[temp++]);
        temp=0;
        while(temp<=rear)
            printf("%d ",queue[temp++]);
    }
    printf("]\n");
}

int peek(){
    // optional code for this program
    // if(isEmpty()){
    //     printf("Queue underflow!\n");
    //     exit(1);
    // }
    return queue[front];
}

int dequeue(){
    int data;
    // optional code for this program
    // if(isEmpty()){
    //     printf("Queue underflow!\n");
    //     exit(1);
    // }
    data=queue[front];
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

void enqueue(int data){
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
    queue[rear]=data;
}