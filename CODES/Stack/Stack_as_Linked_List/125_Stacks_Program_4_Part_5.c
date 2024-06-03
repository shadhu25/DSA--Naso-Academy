// stack program 4
#include<stdio.h>

void changeVal(int **ptr){
    int val2=46;
    *ptr=&val2;
}

int main(){
    int val=35;
    int *ptr;
    ptr=&val;
    printf("%d \n",*ptr);
    changeVal(&ptr);
    printf("%d \n",*ptr);
    return 0;
}