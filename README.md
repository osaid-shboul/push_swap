Push_swap

------------------------------------
Description

Push_swap is a 42 school project that requires sorting a stack of integers using a limited set of operations and two stacks (A and B). The goal is to sort the numbers in stack A in ascending order with the minimum number of operations.
------------------------------------
Sorting Algorithm

This implementation uses a Chunk Sorting algorithm (K-Sort) for large sets of numbers (100 and 500).

1. Indexing: Each number is assigned an index based on its relative value to simplify range management.

2. Pushing to B: Numbers are pushed from stack A to stack B in chunks based on their index and a dynamic range.

3. Pushing to A: Once stack A is empty, the program finds the largest element in stack B and pushes it back to stack A, ensuring a sorted order.
------------------------------------
Performance

The efficiency of this algorithm meets the project requirements:

* 100 numbers: Less than 700 operations.

* 500 numbers: Less than 5500 operations.
------------------------------------
Operations

The program utilizes the following instructions:

* Push: pa, pb.

* Swap: sa, sb.

* Rotate: ra, rb.

* Reverse Rotate: rra, rrb.
------------------------------------
Installation and Usage

Compile the project using the Makefile:

 make
------------------------------------
To run the program with a set of numbers:

 ./push_swap 3 2 1 0
------------------------------------
To test the number of operations:

 ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
------------------------------------
Error Handling

The program displays "Error" on the standard error output for:

* Non-numeric parameters.

* Parameters larger than an integer.

* Duplicate parameters.