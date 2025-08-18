/*
2.1 Aim of the program: Write a program in C to convert the first ‘n’ decimal numbers of a disc
file to binary using recursion. Store the binary value in a separate disc file.
Note# Read the value of ‘n’, source file name and destination file name from command line
arguments. Display the decimal numbers and their equivalent binary numbers from the output
file.
Give the contents of the input disc file “inDec.dat” as
30 75 2564 ...
Contents of the output disc file “outBin.dat” as
The binary equivalent of 30 is 0000000000011110
The binary equivalent of 75 is 0000000001001011
The binary equivalent of 2564 is 0000101000000100
Terminal Input:
$gcc lab2q1.c -o lab2q1
$./lab2q1 150 inDec.dat outBin.dat
Output: Content of the first ‘n’ decimal and their equivalent binary numbers
*/
#include <stdio.h>
#include <stdlib.h>

#define BIT_SIZE 16

// Recursive function to convert decimal to binary
void decToBin(int num, char *binStr, int bitPos) {
    if (bitPos < 0) return;
    binStr[BIT_SIZE - 1 - bitPos] = (num & 1) ? '1' : '0';
    decToBin(num >> 1, binStr, bitPos - 1);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <source_file> <dest_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    char *srcFile = argv[2];
    char *destFile = argv[3];

    FILE *src = fopen(srcFile, "r");
    if (!src) {
        perror("Error opening source file");
        return 1;
    }

    FILE *dest = fopen(destFile, "w");
    if (!dest) {
        perror("Error opening destination file");
        fclose(src);
        return 1;
    }

    int num, count = 0;
    while (fscanf(src, "%d", &num) == 1 && count < n) {
        char binStr[BIT_SIZE + 1] = {0};
        decToBin(num, binStr, BIT_SIZE - 1);
        fprintf(dest, "The binary equivalent of %d is %s\n", num, binStr);
        count++;
    }

    fclose(src);
    fclose(dest);

    // Reopen dest file to display the result
    dest = fopen(destFile, "r");
    if (!dest) {
        perror("Error reopening destination file");
        return 1;
    }

    char line[100];
    printf("Output:\n");
    while (fgets(line, sizeof(line), dest)) {
        printf("%s", line);
    }

    fclose(dest);
    return 0;
}
