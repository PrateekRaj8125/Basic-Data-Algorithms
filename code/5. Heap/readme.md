# Heap

This folder contains a **menu-driven C program** that demonstrates the implementation of **Min-Heap** and **Max-Heap** operations using a custom `struct person`. The program reads data of students from a file, builds heaps based on different attributes, and performs typical heap operations.

---

## Program Details

| Topic | Solution | Description |
|---|---|---|
| Heap Operations on Student Records | [heap.c](https://github.com/PrateekRaj8125/Basic-Data-Algorithms/blob/main/code/5.%20Heap/heap.c) . [data.txt](https://github.com/PrateekRaj8125/Basic-Data-Algorithms/blob/main/code/5.%20Heap/data.txt) | Reads student records (ID, name, age, height, weight) into a dynamically allocated array of structs. Implements Min-Heap (based on **age**) and Max-Heap (based on **weight**). Provides menu options for heap creation, insertion, deletion, and querying. |

---

## Struct Definition

```c
struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight; // in pounds
};
```

## Menu Options

MAIN MENU (HEAP)

1. Read Data
2. Create a Min-heap based on the age
3. Create a Max-heap based on the weight
4. Display weight of the youngest person
5. Insert a new person into the Min-heap
6. Delete the oldest person
7. Exit

## Input File Format

The input file should contain the number of records on the first line, followed by student details:

```txt
7
0 Adarsh 39 77 231
1 Levi 56 77 129
2 Priya 63 78 240
3 Dorothy 47 72 229
4 Florence 24 75 171
5 Erica 38 73 102
6 Norma 23 75 145

```

- **id** → integer
- **name** → string (no spaces)
- **age** → integer (years)
- **height** → integer (inches)
- **weight** → integer (pounds)

## Sample Run

```yaml
Enter option: 1
Data read successfully.

Enter option: 2
Min-heap created (age).

Enter option: 4
Weight of youngest student: 65.77 kg

Enter option: 6
Deleting oldest person: Priya (Age 63)
```

## Features Implemented

- ✅ Read student data from a file into a dynamic array.
- ✅ Build Min-Heap based on `age`.
- ✅ Build Max-Heap based on `weight`.
- ✅ Display weight of the youngest student (converted to kg).
- ✅ Insert a new person into the Min-Heap.
- ✅ Delete the oldest person (max age).

## How to Compile and Run

1. Compile with `gcc`:

    ```bash
    gcc heap.c -o heap
    ```

2. Run the program:

    ```bash
    ./heap
    ```

3. Provide the input file when prompted.

## Learning Outcomes

- Understand heap data structures (min-heap and max-heap).
- Implement heapify operations for different attributes.
- Practice dynamic memory allocation with arrays of structs.
- Apply heaps to solve real-world record management problems.
