/*
Write a menu driven program to sort a list of elements in ascendingorder using Quick Sort technique.
Each choice for the input data has its own disc file.
A separate output file can be used for sorted elements.
After sorting display the content of the output file along with number of comparisons.
Based on the partitioning position for each recursive call, conclude the input scenario is either best-case partitioning or worst-case partitioning.

# Note:
● The worst-case behavior for quicksort occurs when the partitioning routine produces one
subproblem with n-1 elements and one with 0 elements. The best-case behaviour
occurred in most even possible split, PARTITION produces two subproblems, each of
size no more than n/2.
● Number of elements in each input file should vary from 300 to 500 entries.
● For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40.....,
Store the result in “outQuickAsce.dat”.
● For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60....,
Store the result in “outQuickDesc.dat”.
● For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 ...,
Store the result in “outQuickRand.dat”

Sample Input from file:
MAIN MENU (QUICK SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. ERROR (EXIT)

Output:
Enter option: 1
Before Sorting: Content of the input file
After Sorting: Content of the output file
Number of Comparisons: Actual
Scenario: Best or Worst-case
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long comparisonCount = 0;
int worstCaseFlag = 0, bestCaseFlag = 1; // To track partition quality

// Swap helper
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        comparisonCount++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    int leftSize = (i + 1) - low;
    int rightSize = high - (i + 1);

    // Check partitioning quality
    if (leftSize == 0 || rightSize == 0) {
        worstCaseFlag = 1;
    }
    if (leftSize > (high - low + 1) / 2 || rightSize > (high - low + 1) / 2) {
        bestCaseFlag = 0; // not an even split
    }

    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    printf("MAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. EXIT\n");
    printf("Enter option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcpy(inFile, "inAsce.dat");
            strcpy(outFile, "outQuickAsce.dat");
            break;
        case 2:
            strcpy(inFile, "inDesc.dat");
            strcpy(outFile, "outQuickDesc.dat");
            break;
        case 3:
            strcpy(inFile, "inRand.dat");
            strcpy(outFile, "outQuickRand.dat");
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

    printf("Before Sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Perform sorting
    quickSort(arr, 0, n - 1);

    printf("After Sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    writeToFile(outFile, arr, n);

    printf("Number of Comparisons: %lld\n", comparisonCount);
    if (worstCaseFlag)
        printf("Scenario: Worst-case partitioning\n");
    else if (bestCaseFlag)
        printf("Scenario: Best-case partitioning\n");
    else
        printf("Scenario: Neither strict best-case nor worst-case\n");

    return 0;
}

