# Divide and Conquer Method

This folder contains C programs that implement classic **divide and conquer** sorting algorithms:

- **Merge Sort**
- **Quick Sort**

Both programs are **menu-driven**, read input data from files, and produce sorted output files along with performance statistics such as **execution time** and **number of comparisons**.

---

## Programs

| S. No. | Topic | Solution | Description |
|---|---|---|---|
| 1. | Merge Sort | [merge_sort.c](https://github.com/PrateekRaj8125/Basic-Data-Algorithms/blob/main/code/4.%20Divide%20and%20Conquer%20Method/merge_sort.c) | Sorts a list of integers using **Merge Sort**. Input can be ascending, descending, or random data read from files. Outputs sorted results to corresponding files while reporting number of comparisons and execution time. |
| 2. | Quick Sort | [quick_sort.c](https://github.com/PrateekRaj8125/Basic-Data-Algorithms/blob/main/code/4.%20Divide%20and%20Conquer%20Method/quick_sort.c) | Sorts a list of integers using **Quick Sort**. Detects whether partitioning corresponds to best-case or worst-case scenarios. Reads input data from files and writes sorted results to output files along with the number of comparisons. |

---

## Input and Output Files

Each program works with three types of data files:

- **Ascending Data**  
      - Input: `inAsce.dat` (e.g., `10 20 30 40 ...`)  
      - Output: `outMergeAsce.dat` / `outQuickAsce.dat`

- **Descending Data**  
      - Input: `inDesc.dat` (e.g., `90 80 70 60 ...`)  
      - Output: `outMergeDesc.dat` / `outQuickDesc.dat`

- **Random Data**  
      - Input: `inRand.dat` (e.g., `55 66 33 11 44 ...`)  
      - Output: `outMergeRand.dat` / `outQuickRand.dat`

---

## Sample Run (Merge Sort)

MAIN MENU (MERGE SORT)

1. Ascending Data
2. Descending Data
3. Random Data
4. EXIT
Enter option: 1

Before Sorting:
10 20 30 40 ...

After Sorting:
10 20 30 40 ...

Number of Comparisons: 1225
Execution Time: 184562 nanoseconds

---

## Sample Run (Quick Sort)

MAIN MENU (QUICK SORT)

1. Ascending Data
2. Descending Data
3. Random Data
4. EXIT
Enter option: 2

Before Sorting:
90 80 70 60 ...

After Sorting:
60 70 80 90 ...

Number of Comparisons: 1350
Scenario: Worst-case partitioning

---

## How to Compile and Run

1. Compile with `gcc`:

    ```bash
    gcc merge_sort.c -o merge_sort
    gcc quick_sort.c -o quick_sort
    ```

2. Run the executables:

    ```bash
    ./merge_sort
    ./quick_sort
    ```

3. Follow the menu prompts to choose the input type.

## Learning Outcomes

- Understand the divide and conquer paradigm with practical examples.
- Implement Merge Sort and measure execution time with high-resolution clocks.
- Implement Quick Sort and analyze best-case vs worst-case partitioning.
- Practice working with file I/O in C for handling large datasets (300–500 entries).
- Gain insights into algorithmic complexity through actual comparison counts.
