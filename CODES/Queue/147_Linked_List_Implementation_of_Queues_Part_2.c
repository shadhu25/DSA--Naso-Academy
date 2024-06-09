// implementing Queue using linked kist
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*front=NULL, *rear=NULL;

void print();
int peek();
int dequeue();
void enqueue(int);
int isEmpty();

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
                    printf("Enter the element to be inserted: ");
                    scanf("%d",&data);
                    enqueue(data);
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
                    printf("The topmost element of the Queue is %d\n",peek());
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
    struct node *temp=front;
    printf("[ ");
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("]\n");
}

int peek(){
    return front->data;
}

int dequeue(){
    // optional code for this program
    // if(isEmpty()){
    //     printf("Queue underflow!\n");
    //     exit(1);
    // }
    int data;
    struct node *temp=front;
    data=temp->data;
    if(!front->next)
        rear=NULL;
    front=front->next;
    free(temp);
    temp=NULL;
    return data;
}

int isEmpty(){
    return front==NULL;
}

void enqueue(int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    if(!newNode){
        printf("Queue overflow!\n");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    if(!rear){
        front=newNode;
    }
    else{
        struct node *temp=rear;
        temp->next=newNode;
    }
    rear=newNode;
}