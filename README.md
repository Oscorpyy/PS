This project has been created as part of the 42 curriculum by (!!login1!!)[, (!!login2!!)]]

Push_swap
Description

Push_swap is a sorting project from the 42 curriculum.
Its purpose is to generate the smallest possible list of stack operations required to sort a list of integers using only two stacks (a and b) and a limited instruction set.

This implementation contains four required algorithms:

O(n²) — simple strategy

O(n√n) — medium strategy

O(n log n) — complex strategy

Adaptive strategy — chooses the best method dynamically based on the input disorder

The program takes integers as arguments and prints the sequence of operations sorting stack a.
A benchmark mode is also provided.

A bonus checker program can validate whether a sequence of operations actually sorts the stack.

Instructions
Compilation

make
make bonus
make clean
make fclean
make re

Usage
Default adaptive strategy

./push_swap 3 2 1

Force a strategy

./push_swap --simple 5 4 3 2 1
./push_swap --medium 90 3 12 7 50
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 10 2 8 4 1

Benchmark mode

./push_swap --bench 4 67 3 87 23

Benchmark output (stderr):

Disorder percentage

Strategy used

Complexity class

Total number of operations

Count of each operation (sa, sb, pa, ra, rra, etc.)

Checker (bonus)

echo -e "pb\nsa\npa" | ./checker 3 2 1

Algorithms
Simple Algorithm — O(n²)

Chosen method: (!!describe your simple algorithm!!)
Complexity justification: (!!explain why it is O(n²)!!)

Medium Algorithm — O(n√n)

Chosen method: (!!describe your chunk/block algorithm!!)
Complexity justification: (!!explain why it matches O(n√n)!!)

Complex Algorithm — O(n log n)

Chosen method: (!!describe your radix/merge/quick/heap adaptation!!)
Complexity justification: (!!explain your reasoning!!)

Adaptive Algorithm

Disorder thresholds:

Low disorder (< 0.2): O(n) method (!!describe!!)

Medium disorder (< 0.5): O(n√n) method (!!describe!!)

High disorder (≥ 0.5): O(n log n) method (!!describe!!)

Threshold explanation: (!!justify your numbers!!)
Internal design: (!!explain how disorder is computed and used!!)

Performance

Official requirements:

100 numbers

< 2000 operations to pass

< 1500 good

< 700 excellent

500 numbers

< 12000 operations to pass

< 8000 good

< 5500 excellent

Your results:

100 numbers: (!!your score!!)
500 numbers: (!!your score!!)

Contributors

(!!login1!!) — (!!contribution!!)

(!!login2!!) — (!!contribution!!)

Resources

Sorting algorithms: https://en.wikipedia.org/wiki/Sorting_algorithm

Time complexity: https://en.wikipedia.org/wiki/Time_complexity

Push_swap subject (42)
Other resources used: (!!list your resources!!)

Use of AI

!!Explain how you used AI (doc help, idea organization, etc.), while confirming that all code is understood and validated by you.!!
