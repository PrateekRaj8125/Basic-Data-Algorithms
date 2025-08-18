/*Aim of the program: Write a program to read ‘n’ integers from a disc file that must contain 
some duplicate values and store them into an array. Perform the following operations on the 
array.
a) Find out the total number of duplicate elements.
b) Find out the most repeating element in the array.
Input:
Enter how many numbers you want to read from file: 15
Output:
The content of the array: 10 40 35 47 68 22 40 10 98 10 50 35 68 40 10
Total number of duplicate values = 4
The most repeating element in the array = 10*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    int arr[n];
    int freq[1000] = {0};  // Adjust size for max value range

    // Read from file into array
    for (int i = 0; i < n; i++) {
        if (fscanf(fp, "%d", &arr[i]) != 1) {
            printf("Error reading number %d from file.\n", i+1);
            fclose(fp);
            return 1;
        }
        freq[arr[i]]++;  // Count frequency directly
    }
    fclose(fp);

    // Print array
    printf("The content of the array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Count distinct duplicates
    int duplicateCount = 0;
    for (int i = 0; i < 1000; i++) {
        if (freq[i] > 1)
            duplicateCount++;
    }
    printf("Total number of duplicate values = %d\n", duplicateCount);

    // Find most repeating element
    int maxFreq = 0, mostRepeating = -1;
    for (int i = 0; i < 1000; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mostRepeating = i;
        }
    }
    printf("The most repeating element in the array = %d\n", mostRepeating);

    return 0;
}
