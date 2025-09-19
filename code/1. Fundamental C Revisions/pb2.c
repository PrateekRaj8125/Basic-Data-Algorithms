// Write a C program to perform basic arithmetic operations (add, subtract, multiply, divide, remainder) on two numbers using a switch statement.
#include<stdio.h>
void main(){
    int a,b,ch;
    printf("Enter two nos.:");
    scanf("%d %d",&a,&b);
    printf("1-Add, 2-Subtract, 3-Multiply, 4-Divide, 5-Remainder\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch (ch){
        case 1:
        printf("Sum:%d",(a+b));
        break;
        case 2:
        printf("Subtract:%d",(a-b));
        break;
        case 3:
        printf("Multiply:%d",(a*b));
        break;
        case 4:
        printf("Divide:%d",(a/b));
        break;
        case 5:
        printf("Remainder:%d",(a%b));
        break;
        default:
        printf("Wrong choice entered");
    }
}