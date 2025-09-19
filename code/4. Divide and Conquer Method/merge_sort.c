/*
Write a menu driven program to sort list of array elements using MergeSort technique and calculate the execution time only to sort the elements.
Count the number of comparisons.
# Note:
● To calculate execution time, assume that single program is under execution in the CPU.
● Number of elements in each input file should vary from 300 to 500 entries.
● For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40.....,
Store the result in “outMergeAsce.dat”.
● For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60....,
Store the result in “outMergeDesc.dat”.
● For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 ...,
Store the result in “outMergeRand.dat”

Sample Input from file:
MAIN MENU (MERGE SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. ERROR (EXIT)

Output:
Enter option: 1
Before Sorting: Content of the input file
After Sorting: Content of the output file
Number of Comparisons: Actual
Execution Time: lapse time in nanosecond
*/

#define _POSIX_C_SOURCE 199309L
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/time.h>
#endif

long long comparisonCount = 0;

// Merge function
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisonCount++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

// Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Read array from file
int readFromFile(const char *filename, int arr[]) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Could not open %s\n", filename);
        return 0;
    }
    int count = 0;
    while (fscanf(fp, "%d", &arr[count]) != EOF) {
        count++;
    }
    fclose(fp);
    return count;
}

// Write array to file
void writeToFile(const char *filename, int arr[], int n) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: Could not open %s\n", filename);
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
}

int main() {
    int choice;
    int arr[1000];
    int n;
    char inFile[50], outFile[50];

    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. EXIT\n");
    printf("Enter option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcpy(inFile, "inAsce.dat");
            strcpy(outFile, "outMergeAsce.dat");
            break;
        case 2:
            strcpy(inFile, "inDesc.dat");
            strcpy(outFile, "outMergeDesc.dat");
            break;
        case 3:
            strcpy(inFile, "inRand.dat");
            strcpy(outFile, "outMergeRand.dat");
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    n = readFromFile(inFile, arr);
    if (n == 0) return 0;
        // Measure execution time
    #ifdef _WIN32
        LARGE_INTEGER freq, start, end;
        QueryPerformanceFrequency(&freq);
        QueryPerformanceCounter(&start);
        mergeSort(arr, 0, n - 1);
        QueryPerformanceCounter(&end);
        long long elapsed_ns = (end.QuadPart - start.QuadPart) * 1000000000LL / freq.QuadPart;
    #else
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);
        mergeSort(arr, 0, n - 1);
        clock_gettime(CLOCK_MONOTONIC, &end);
        long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
    #endif

    printf("After Sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    writeToFile(outFile, arr, n);

    printf("Number of Comparisons: %lld\n", comparisonCount);
    printf("Execution Time: %lld nanoseconds\n", elapsed_ns);

    return 0;
}
