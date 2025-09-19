// Write a C program to find the GCD (greatest common divisor) of two numbers using recursion.
#include<stdio.h>
#include<stdlib.h>
int gcd(int a,int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
void main(){
    int a,b,gc;
    printf("Enter two nos.:");
    scanf("%d %d",&a,&b);
    if(a==b)
        gc=a;
    if(a>b)
        gc=gcd(a,b);
    if(b>a)
        gc=gcd(b,a);
    printf("GCD(%d,%d)=%d",a,b,gc);
}