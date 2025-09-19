// Write a C program to input two arrays, then compute the sum of selected elements based on user choice using a switch statement.
#include<stdlib.h>
#include<stdio.h>
void main(){
    int arr1[5],arr2[4],i;
    int m=sizeof(arr1)/sizeof(int),n=sizeof(arr2)/sizeof(int);
    printf("Enter values in Array 1 (size-5):");
    for(i=0;i<m;i++)
        scanf("%d",&arr1[i]);
    printf("Enter values in Array 2 (size-4):");
    for(i=0;i<n;i++)
        scanf("%d",&arr2[i]);
    int ch,a,b;
    printf("Choice Output:\n");
    printf("1.Sum of any two elements of array 1\n");
    printf("2.Sum of any two elements of array 2\n");
    printf("3.Sum of two elements each from both arrays\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("Enter both indices of array 1:");
            scanf("%d %d",&a,&b);
            if(a>m||b>m||a<0||b<0){
                printf("Indices out of bound");
                exit(0);
            }
            printf("Sum of element %d and element %d from array 1:%d",a,b,(arr1[a-1]+arr1[b-1]));
        break;
        case 2:
            printf("Enter both indices of array 2:");
            scanf("%d %d",&a,&b);
            if(a>n||b>n||a<0||b<0){
                printf("Indices out of bound");
                exit(0);
            }
            printf("Sum of element %d and element %d from array 2:%d",a,b,(arr2[a-1]+arr2[b-1]));
        break;
        case 3:
            printf("Enter index for array 1:");
            scanf("%d",&a);
            printf("Enter index for array 2:");
            scanf("%d",&b);
            if(a>m||b>n||a<0||b<0){
                printf("Indices out of bound");
                exit(0);
            }
            printf("Sum of element %d of array 1 and element %d of array 2:%d",a,b,(arr1[a-1]+arr2[b-1]));
        break;
        default:
        printf("Wrong choice entered");
        exit(0);
    }
}