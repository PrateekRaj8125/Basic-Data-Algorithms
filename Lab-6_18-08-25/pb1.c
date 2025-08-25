#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight; // in pounds
};

// Global variables
struct person *arr = NULL;
int n = 0;   // current size
int capacity = 0;

// ---------- Heapify functions ----------
void swap(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heapify based on age
void minHeapify(int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if (l < n && arr[l].age < arr[smallest].age) smallest = l;
    if (r < n && arr[r].age < arr[smallest].age) smallest = r;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(smallest);
    }
}

// Max-heapify based on weight
void maxHeapify(int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if (l < n && arr[l].weight > arr[largest].weight) largest = l;
    if (r < n && arr[r].weight > arr[largest].weight) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(largest);
    }
}

// Build Min-heap
void buildMinHeap() {
    for (int i = n/2 - 1; i >= 0; i--) minHeapify(i);
}

// Build Max-heap
void buildMaxHeap() {
    for (int i = n/2 - 1; i >= 0; i--) maxHeapify(i);
}

// Insert into Min-heap (age)
void insertMinHeap(struct person p) {
    n++;
    arr = realloc(arr, n * sizeof(struct person));
    int i = n - 1;
    arr[i] = p;

    // Fix heap property
    while (i != 0 && arr[(i-1)/2].age > arr[i].age) {
        swap(&arr[i], &arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Delete oldest person (max age)
void deleteOldest() {
    if (n == 0) {
        printf("Heap is empty!\n");
        return;
    }
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].age > arr[maxIndex].age) maxIndex = i;
    }
    printf("Deleting oldest person: %s (Age %d)\n", arr[maxIndex].name, arr[maxIndex].age);
    arr[maxIndex] = arr[n-1];
    n--;
    arr = realloc(arr, n * sizeof(struct person));
    buildMinHeap(); // rebuild to maintain heap
}

// ---------- Menu ----------
int main() {
    int choice;
    char filename[50];

    do {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter filename: ");
            scanf("%s", filename);
            FILE *fp = fopen(filename, "r");
            if (!fp) {
                printf("Error opening file!\n");
                continue;
            }
            fscanf(fp, "%d", &n); // first line contains count
            arr = malloc(n * sizeof(struct person));
            for (int i = 0; i < n; i++) {
                char temp[100];
                fscanf(fp, "%d %s %d %d %d", &arr[i].id, temp, &arr[i].age, &arr[i].height, &arr[i].weight);
                arr[i].name = malloc(strlen(temp) + 1);
                strcpy(arr[i].name, temp);
            }
            fclose(fp);
            printf("Data read successfully.\n");

        } else if (choice == 2) {
            buildMinHeap();
            printf("Min-heap created (age).\n");

        } else if (choice == 3) {
            buildMaxHeap();
            printf("Max-heap created (weight).\n");

        } else if (choice == 4) {
            if (n == 0) printf("Heap empty.\n");
            else {
                printf("Weight of youngest student: %.2f kg\n", arr[0].weight * 0.453592);
            }

        } else if (choice == 5) {
            struct person p;
            printf("Enter new person details (id name age height weight): ");
            scanf("%d %s %d %d %d", &p.id, p.name, &p.age, &p.height, &p.weight);
            insertMinHeap(p);
            printf("Inserted successfully into Min-heap.\n");

        } else if (choice == 6) {
            deleteOldest();

        } else if (choice == 7) {
            printf("Exiting...\n");

        } else {
            printf("Invalid choice.\n");
        }

    } while (choice != 7);

    free(arr);
    return 0;
}
