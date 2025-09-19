# Basic Data Algorithms

This repository contains a collection of **C programming exercises and algorithm implementations** organized into five modules.  
The goal of this repository is to help learners **revise fundamental C concepts**, **practice data structures**, and **understand core algorithmic techniques** such as Divide and Conquer and Heap operations.

---

## Repository Structure

├── [code/](https://github.com/PrateekRaj8125/Basic-Data-Algorithms/tree/main/code)  
│
│ ├── [1. Fundamental C Revisions](https://github.com/PrateekRaj8125/Basic-Data-Algorithms/tree/main/code/1.%20Fundamental%20C%20Revisions)  
│ ├── [2. Revision of Data Structures](https://github.com/PrateekRaj8125/Basic-Data-Algorithms/tree/main/code/2.%20Revision%20of%20Data%20Structures)  
│ ├── [3. Fundamentals of Algorithmic Problem Solving](https://github.com/PrateekRaj8125/Basic-Data-Algorithms/tree/main/code/3.%20Fundamentals%20of%20Algorithmic%20Problem%20Solving)  
│ ├── [4. Divide and Conquer Method](https://github.com/PrateekRaj8125/Basic-Data-Algorithms/tree/main/code/4.%20Divide%20and%20Conquer%20Method)  
│ └── [5. Heap](https://github.com/PrateekRaj8125/Basic-Data-Algorithms/tree/main/code/5.%20Heap)  
│
├── [docs/]()  
│ ├── [CONTRIBUTING]()  
│ ├── [Security Policy]()  
│ └── [CODE OF CONDUCT]()  
│
├── [LICENSE]()  
└── [README]()  
---

## Folder Overview

### 1. Fundamental C Revisions

Basic revision programs in C focusing on:

- Input/Output operations
- Loops and conditionals
- Arrays and strings
- Functions and pointer basics

This section ensures that the groundwork of C programming is strong before moving to advanced concepts.

---

### 2. Revision of Data Structures

Exercises revising fundamental **array operations** and **file I/O**:

- Find second smallest and second largest elements
- Compute prefix sums of an array
- Detect duplicate values and most repeating elements from a file
- Rotate first *k* elements of an array using pointer-based functions

---

### 3. Fundamentals of Algorithmic Problem Solving

Programs that apply algorithmic thinking to solve basic problems, introducing:

- Iterative vs recursive solutions
- Searching and traversal
- Problem decomposition into functions
- Small coding challenges to practice logical reasoning

---

### 4. Divide and Conquer Method

Implementation of **sorting algorithms** using the Divide and Conquer paradigm:

- **Merge Sort**
  - Counts comparisons
  - Measures execution time in nanoseconds
  - Reads/writes data from files (`inAsce.dat`, `inDesc.dat`, `inRand.dat`)
- **Quick Sort**
  - Detects best-case vs worst-case partitioning scenarios
  - Works with ascending, descending, and random datasets
  - Outputs results to separate files

---

### 5. Heap

Menu-driven program implementing **Min-Heap** and **Max-Heap** operations on student records:

- Read student details from a file into dynamically allocated structures
- Build Min-Heap (by age) and Max-Heap (by weight)
- Insert a new student
- Delete the oldest student
- Query the weight of the youngest student

---

## How to Use

1. Clone the repository:

   ```bash
   git clone https://github.com/PrateekRaj8125/Basic-Data-Algorithms.git
   cd Basic-Data-Algorithms
    ```

2. Compile any program using `gcc`:

    ```bash
    gcc program_name.c -o program_name
    ```

3. Run the executable:

    ```bash
    ./program_name
    ```

4. Follow the menu prompts or input requirements (some programs read from `.dat` or `.txt` files).

## Learning Outcomes

By working through this repository, you will:

- ✅ Strengthen your fundamentals of C programming.
- ✅ Revise and practice core data structure operations.
- ✅ Learn algorithmic problem solving by breaking down problems into smaller components.
- ✅ Understand the Divide and Conquer paradigm through Merge Sort and Quick Sort.
- ✅ Apply Heap data structures in managing records with real-world relevance.
- ✅ Gain hands-on experience with file handling, dynamic memory allocation, and performance measurement.

## License

This project is licensed under the MIT License. See the [LICENSE] file for details.
