# Revision of Data Structures

This folder contains C programming exercises focused on fundamental array manipulations and file handling. Each program illustrates important concepts such as finding min/max elements, prefix sums, handling duplicates, and performing array rotations.

| S. No. | Topic | Solution | Description |
|---|---|---|---|
| 1. | Find Second Smallest and Second Largest | [Solution](https://github.com/PrateekRaj8125/Basic-Data-Algorithms/blob/main/code/2.%20Revision%20of%20Data%20Structures/pb1.c) | Reads an array of integers and determines the second smallest and second largest elements. Demonstrates array traversal and min/max search logic. |
| 2. | Prefix Sum of an Array | [Solution](https://github.com/PrateekRaj8125/Basic-Data-Algorithms/blob/main/code/2.%20Revision%20of%20Data%20Structures/pb2.c) | Computes the prefix sum array from an input array. Reinforces cumulative addition and in-place array updates. |
| 3. | Duplicates and Most Repeating Element | [Solution](https://github.com/PrateekRaj8125/Basic-Data-Algorithms/blob/main/code/2.%20Revision%20of%20Data%20Structures/pb3.c) · [Input File](https://github.com/PrateekRaj8125/Basic-Data-Algorithms/blob/main/code/2.%20Revision%20of%20Data%20Structures/input.txt) | Reads integers from a file into an array, counts distinct duplicate elements, and finds the most frequently occurring element. Illustrates file I/O, frequency counting, and duplicate detection. |
| 4. | Rotate First N Elements Right by 1 Position | [Solution](https://github.com/PrateekRaj8125/Basic-Data-Algorithms/blob/main/code/2.%20Revision%20of%20Data%20Structures/pb4.c) | Rotates the first *k* elements of an array to the right by one position using a helper swap (`EXCHANGE`) function. Demonstrates pointer manipulation and modular function design. |

## How to Use

1. Compile each C program using `gcc`:

    ```bash
    gcc program_name.c -o program_name
    ```

2. Run the executable:

    ```bash
    ./program_name
    ```

3. Follow the prompts for input (some programs also read from `input.txt`).

## Learning Outcomes

- Practice array traversal and searching for extremum values.
- Understand prefix sums and cumulative operations on arrays.
- Work with file input in C to detect duplicates and frequencies.
- Implement pointer-based array manipulations and modular functions.
