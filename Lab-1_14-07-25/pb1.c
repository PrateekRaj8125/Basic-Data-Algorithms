#include<stdio.h>
#include<string.h>
void main(){
    char name[100];
    printf("Enter Name:");
    scanf("%[^\n]s",&name);
    printf("Name: %s\n",name);
}