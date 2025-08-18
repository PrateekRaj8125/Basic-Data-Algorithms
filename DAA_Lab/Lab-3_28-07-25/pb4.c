/*Aim of the program: Write a function to ROTATE_RIGHT (p1, p2) right an array for first p2
elements by 1 position using EXCHANGE (p, q) function that swaps/exchanges the numbers p
& q. Parameter p1 be the starting address of the array and p2 be the number of elements to be
rotated.
Input:
Enter an array A of size N (9): 11 22 33 44 55 66 77 88 99
Call the function ROTATE_RIGHT (A, 5)
Output:
Before ROTATE: 11 22 33 44 55 66 77 88 99
After ROTATE: 55 11 22 33 44 66 77 88 99*/

#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

// Function to rotate first p2 elements right by 1
void ROTATE_RIGHT(int *p1, int p2) {
    for (int i = p2 - 1; i > 0; i--) {
        EXCHANGE(&p1[i], &p1[i - 1]);
    }
}

int main() {
    int n;
    
    // Take array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate array
    int *A = (int *)malloc(n * sizeof(int));
    if (A == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Take array input
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int k;
    // Take how many elements to rotate
    printf("Enter how many elements to rotate from the beginning: ");
    scanf("%d", &k);

    // Show before rotation
    printf("Before ROTATE: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Call rotation function
    if (k <= n && k > 0)
        ROTATE_RIGHT(A, k);
    else
        printf("Invalid number of elements to rotate!\n");

    // Show after rotation
    printf("After ROTATE: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    free(A);
    return 0;
}
