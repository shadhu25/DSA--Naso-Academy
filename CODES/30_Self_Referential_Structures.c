#include<stdio.h>
#include<stdlib.h>
// self referential structure
struct point {
    int x,y;
    struct point *ptr;
};
int main(){
    struct point p1,p2;
    p1.x=22;
    p1.y=33;
    p1.ptr=NULL;
    p2.x=44;
    p2.y=55;
    p2.ptr=&p1;
    printf("%d %d\n",p2.ptr->x,p2.ptr->y);
    return 0;
}