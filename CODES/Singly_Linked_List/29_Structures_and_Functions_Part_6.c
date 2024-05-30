// Passing array of structures as argumemt.
#include<stdio.h>
#include<stdlib.h>
struct point {
    int x,y;
};
void print(struct point arr[]){
    int i;
    for(i=0;i<2;i++)
        printf("%d %d\n",arr[i].x,arr[i].y);
}
int main(){
    struct point arr[2]={{1,2},{3,4}};
    // Passing array of structures as argumemt
    print(arr);
    return 0;
}