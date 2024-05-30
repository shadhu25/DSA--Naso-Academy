// Passing structure member as argument
#include<stdio.h>
struct student {
char name[50];
int age;
int roll_no;
float marks;
};
struct charset {
    char s;
    int i;
};
void print(char name[], int age, int roll,float marks){
    printf("%s %d %d %.2f\n",name, age,roll,marks);
}
void keyValue(char *s, int *i){
    printf("Enter Key Value: ");
    scanf("%c %d",s,i);
}
int main(){
    struct student s1 = {"Nick",16,50, 72.5};
    // passing(call by value)
    print(s1.name,s1.age, s1.roll_no, s1.marks);
    struct charset cs;
    // passing(call by reference)
    keyValue(&cs.s,&cs.i);
    printf("%c %d\n",cs.s,cs.i);
    return 0;
}