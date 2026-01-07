_This project has been created as part of the 42 curriculum by opernod, lgoderne_

# Push_swap
## Description

Push_swap is a sorting project from the 42 curriculum.
Its purpose is to generate the smallest possible list of stack operations required to sort a list of integers using only two stacks (a and b) and a limited instruction set.

This implementation contains four required algorithms:

`O(n²) — simple strategy`

`O(n√n) — medium strategy`

`O(n log n) — complex strategy`

`Adaptive strategy` — chooses the best method dynamically based on the input disorder

The program takes integers as arguments and prints the sequence of operations sorting stack a.
A benchmark mode is also provided.

A bonus checker program can validate whether a sequence of operations actually sorts the stack.

## Instructions

**make**
**make bonus**
**make clean**
**make fclean**
**make re**

Usage
Default `adaptive strategy`

	./push_swap 3 2 1

### Force a strategy :

	./push_swap 5 4 3 2 1 --simple 
	./push_swap 90 3 12 7 50 --medium
	./push_swap 4 67 3 87 23 --complex
	./push_swap 10 2 8 4 1 --adaptive

### Benchmark mode :

	./push_swap 4 67 3 87 23 --bench

- Benchmark output (stderr)
- Disorder percentage
- Strategy used / Complexity class
- Total number of operations
- Count of each operation (sa, sb, pa, ra, rra, etc.)

### Checker (bonus) :

	echo -e "pb\nsa\npa" | ./checker 3 2 1


OR

	./checker 3 2 1
	pb
	sa
	pa
	/eof

## Algorithms

### Simple Algorithm — O(n²)

#### Chosen method:
We use Selection Sort.
This algorithm repeatedly searches for the smallest element in the unsorted part of the array and places it at the correct position. The array is divided into a sorted part (on the left) and an unsorted part (on the right).

#### Complexity justification:
For each element, the algorithm scans the rest of the array to find the minimum value.
This results in two nested loops, leading to O(n²) time complexity, regardless of the initial order of the data.

#### Why we choose it
We choose it because of it's simplicity to implement and to undestand

### Medium Algorithm — O(n√n)

#### Chosen method:
We use Bucket Sort with √n buckets.
The elements are distributed into √n buckets according to their value ranges. Each bucket is then sorted using a simple algorithm (like Selection Sort), and finally all buckets are concatenated.

#### Complexity justification:

Distributing elements into buckets takes O(n) time.

Each bucket contains about √n elements, and sorting one bucket costs O((√n)²) = O(n).

Since there are √n buckets, the total sorting cost is O(n√n).

Thus, the overall complexity is O(n√n).

#### Why we choose it
The first we try to implement and to undestand, because of the performance we have with it and we understand it pretty well

### Complex Algorithm — O(n log n)

#### Chosen method:
We use Quick Sort.
This algorithm selects a pivot element, partitions the array into two sub-arrays (elements smaller and greater than the pivot), and recursively sorts each part.

#### Complexity justification:
On average, Quick Sort divides the array into two balanced sub-arrays.
Each partitioning step takes O(n) time, and the depth of recursion is O(log n), leading to an average time complexity of O(n log n).

#### Why we choose it
it has been choose, because in the first place we try with radix sort, but in search for better performance we go with quick sort

### Adaptive Algorithm

The adaptive algorithm chooses the most appropriate sorting method based on the level of disorder in the array.

#### Disorder thresholds:

##### Low disorder (< 0.2): O(n²) method
-Selection Sort
When the array is almost sorted, the overhead of complex algorithms is unnecessary, and Selection Sort remains simple and efficient to apply.

##### Medium disorder (< 0.5): O(n√n) method
-Bucket Sort
With moderate disorder, Bucket Sort efficiently groups elements and reduces the sorting effort inside each bucket.

##### High disorder (≥ 0.5): O(n log n) method
-Quick Sort
For highly disordered data, Quick Sort provides the best performance thanks to its average O(n log n) complexity.

## Performance

### Official requirements:

#### 100 numbers

< 2000 operations to pass

< 1500 good

< 700 excellent

#### 500 numbers

< 12000 operations to pass

< 8000 good

< 5500 excellent

### Our results:

#### less than 20% of disorder :
- 100 numbers: 470
- 500 numbers: 5900

#### disorder between 20% and 50%:
- 100 numbers: 370/600
- 500 numbers: 2800/5200

#### 50% or more of disorder :
- 100 numbers: 830/873
- 500 numbers: 5900/6043


## Contributors

**Opernod** — Simple, adaptative algorthim + benchmode and repartition of the code + Readme

**Lgoderne** — Meduim and Complex algorthim + checker 

### Resources

- Sorting algorithms: https://en.wikipedia.org/wiki/Sorting_algorithm
- Time complexity: https://en.wikipedia.org/wiki/Time_complexity

Push_swap subject (42)
Other resources used: friend and people next to us

#### Use of AI

We have use AI for :
- Exemple/details the subject (for better understanding of the subject)
- List some algorithm for know some and discide which one to take
- Help for some debuging

<img width="1281" height="1254" alt="Screenshot from 2025-12-17 15-59-49" src="https://github.com/user-attachments/assets/162b8d2b-f4ba-436a-8310-4063a0d75fc3" />

