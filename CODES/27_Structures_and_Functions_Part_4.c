// Returning a structure variable from the function.
#include<stdio.h>
#include<stdlib.h>
struct point {
    int x, y;
};
void print(struct point p){
    printf("%d %d\n",p.x,p.y);
}
struct point edit(struct point p){
    (p.x)++;
    p.y+=5;
    // Returning a structure variable from the function
    return p;
}
int main(){
    struct point p1={66,77};
    struct point p2={88,99};
    print(p1);
    print(p2);
    p1=edit(p1);
    p2=edit(p2);
    print(p1);
    print(p2);
    return 0;
}