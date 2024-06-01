// Passing pointers to structures as argument.
#include<stdio.h>
#include<stdlib.h>
struct point {
    int x, y;
};
void print(struct point *p){
    printf("%d %d\n",p->x,p->y);
}
int main(){
    struct point p1={66,77};
    struct point p2={88,99};
    // Passing pointers to structures as argument.
    print(&p1);
    print(&p2);
    return 0;
}