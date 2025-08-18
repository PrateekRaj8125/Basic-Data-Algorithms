/*Aim of the program: Given an array arr[] of size N, find the prefix sum of the array. A prefix
sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is
arr[0] + arr[1] + arr[2] . . . arr[i].
Input Array:    3   4   5   1   2
Output Array:   3   7   12  13  15*/
#include<stdio.h>
void main(){
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter values:");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Input Array:\t");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    for(int i=1;i<n;i++)
        arr[i]+=arr[i-1];
    printf("\nOutput Array:\t");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}