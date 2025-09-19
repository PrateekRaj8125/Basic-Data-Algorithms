// Write a C program to find the GCD (Greatest Common Divisor) of two numbers using iteration (Euclidean algorithm).
#include<stdio.h>
int gcd(int a, int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
void main(){
    int a,b;
    printf("Enter two nos.:");
    scanf("%d %d",&a,&b);
    printf("GCD(%d,%d)=%d",a,b,gcd(a,b));
}