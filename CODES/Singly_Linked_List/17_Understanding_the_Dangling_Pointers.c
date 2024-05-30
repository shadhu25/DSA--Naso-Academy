// dangling pointer
#include<stdio.h>
int* fun();
int main(){
    int *p=NULL;
    p=fun();
    printf("%d\n",*p); // After termination of fun(), it will became a dangling pointer
    return 0;
}

int* fun(){
    int x=100;
    return &x;
}