/*
Write a program in C to find GCD of two numbers using recursion.
Read all pair of numbers from a file and store the result in a separate file.

# Note:
Source file name and destination file name taken from command line arguments.
The source file must contain at least 20 pairs of numbers.

Give the contents of the input disc file “inGcd.dat” as 8 12 20 45 30 80
Contents of the output disc file “outGcd.dat” as
The GCD of 8 and 12 is 4
The GCD of 20 and 45 is 5
The GCD of 30 and 80 is 10

Terminal Input:
$gcc lab2q2.c -o lab2q2
$./lab2q2 inGcd.dat outGcd.dat

Output: Display the gcd stored in the output file outGcd.dat
*/

#include <stdio.h>
#include <stdlib.h>

// Recursive GCD function
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *inputFile = argv[1];
    char *outputFile = argv[2];

    FILE *in = fopen(inputFile, "r");
    if (!in) {
        perror("Error opening input file");
        return 1;
    }

    FILE *out = fopen(outputFile, "w");
    if (!out) {
        perror("Error opening output file");
        fclose(in);
        return 1;
    }

    int a, b, count = 0;
    while (fscanf(in, "%d %d", &a, &b) == 2) {
        int result = gcd(a, b);
        fprintf(out, "The GCD of %d and %d is %d\n", a, b, result);
        count++;
    }

    fclose(in);
    fclose(out);

    // Display output file content
    out = fopen(outputFile, "r");
    if (!out) {
        perror("Error reading output file");
        return 1;
    }

    char line[100];
    printf("Output:\n");
    while (fgets(line, sizeof(line), out)) {
        printf("%s", line);
    }

    fclose(out);
    return 0;
}
