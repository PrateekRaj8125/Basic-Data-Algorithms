/*
Write a program to find out the second smallest and second largest element stored in an array of n integers.
Input: Size of the array is ‘n’ and read ‘n’ number of elements from a disc file.
Output: Second smallest, Second largest
*/

#include<stdio.h>
#include<stdlib.h>
int largest(int *, int);
int smallest(int *,int);
void main(){
    int n;
    printf("Enter the range of array:");
    scanf("%d",&n);
    int *p;
    p=(int *)malloc(sizeof(int)*n);
    printf("Enter the values:");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    int j=largest(p,n);
    int k=smallest(p,n);
    p[j]=0;
    printf("Second Largest: %d\n",p[largest(p,n)]);
    p[j]=999999;
    p[k]=999999;
    printf("Second Smallest: %d\n",p[smallest(p,n)]);
}
int largest(int *p, int n){
    int max = p[0], mi = 0;
    for(int i = 1; i < n; i++){
        if(p[i] > max){
            max = p[i];
            mi = i;
        }
    }
    return mi;
}
int smallest(int *p, int n){
    int min = p[0], si = 0;
    for(int i = 1; i < n; i++){
        if(p[i] < min){
            min = p[i];
            si = i;
        }
    }
    return si;
}