*This project has been created as part of the 42 curriculum by kgirczyc, akacpere.*

# Push Swap

## Description

Push Swap is a sorting challenge in which a stack of integers must be ordered in ascending order using a very limited set of operations. The goal is not just to sort the numbers, but to do it with the lowest number of moves possible and with a clear understanding of algorithmic trade-offs.

The project consists of two main components:

- `push_swap`: the sorting program that generates the sequence of operations.
- `checker`: a validation tool that checks whether a generated operation list successfully sorts the input stack.

The solver works with two stacks, `a` and `b`, and supports operations such as `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`. The input is parsed, validated, and then processed by one of several strategies depending on how disordered the stack is.

The project also includes benchmarking and strategy flags such as `--simple`, `--medium`, `--complex`, `--adaptive`, and `--bench`, which allow comparing different sorting approaches and measuring behavior on varied inputs.

### Work split

This project was developed as a collaborative effort:

- `kgirczyc`: simple sort, medium sort, and part of parsing/flag handling.
- `akacpere`: complex sort, checker, and part of parsing/flag handling.

---

## Instructions

### Compilation

From the project root, build the main solver:

```bash
make
```

The repository also contains a checker implementation. To build it:

```bash
make -C checker
```

You can also use the provided binary in the repository root if present:

```bash
./checker_linux
```

### Execution

Run the sorter with a list of integers:

```bash
./push_swap 3 2 1 4 5
```

This prints a sequence of operations that sorts the stack. The output can then be validated with the checker:

```bash
./push_swap 3 2 1 4 5 | ./checker_linux 3 2 1 4 5
```

or using the compiled checker from the `checker` directory:

```bash
./push_swap 3 2 1 4 5 | ./checker 3 2 1 4 5
```

### Strategy flags

The project supports strategy selection:

```bash
./push_swap --simple 4 3 2 1
./push_swap --medium 9 8 7 6 5 4 3 2 1
./push_swap --complex 50 40 30 20 10
./push_swap --adaptive 12 7 5 9 8 1 3
```

Benchmark mode:

```bash
./push_swap --bench --adaptive 100 42 7 89 3 12
```

The adaptive mode automatically chooses the strategy based on the computed disorder of the input stack.

---

## Algorithm design and justification

### 1. Simple sort

The simple strategy is designed for small or nearly sorted stacks. It is intentionally straightforward and uses a repeated “find the minimum, rotate it to the top, push it to stack b, then rebuild stack a” pattern.

How it works:

- Find the minimum value in stack `a`.
- Rotate `a` or reverse-rotate `a` so that the minimum reaches the top.
- Push that value to stack `b`.
- Repeat until `a` is empty.
- Pop elements back from `b` to `a` in correct order.

Why this algorithm:

- Simplicity and reliability are more important than optimization for very small inputs.
- Its complexity is quadratic, which is acceptable when the input is already close to sorted or small in size.
- This makes it predictable and easy to debug.

### 2. Medium sort

The medium strategy is a block-based sorting approach inspired by merge-like partitioning. It is used for inputs that are larger than trivial cases but still not large enough to justify the fully optimized complex strategy.

How it works:

- Determine a block size based on the number of elements.
- Split the stack into blocks and sort each block using directional logic.
- Merge the sorted blocks progressively using additional passes.
- The logic uses a “level” and “orientation” mechanism to decide whether operations should be done in increasing or decreasing order.

Why this algorithm:

- It reduces the number of operations compared with naive quadratic sorting.
- It balances performance and implementation complexity.
- It is a good middle point between the very simple and the more advanced radix-based strategy.

This approach is especially useful when the stack is not completely sorted but still manageable without the highest-performance solution.

### 3. Complex sort

The complex strategy is the most advanced part of the project and is based on radix sort, adapted to the constraints of two stacks.

How it works:

- Each value is assigned an index based on its position in the ordering.
- The algorithm processes the indices bit by bit.
- Values whose current bit is `0` are pushed from `a` to `b`.
- Values whose current bit is `1` stay in `a` or are rotated to the top in order to preserve order.
- The process is repeated for each bit, gradually building a sorted arrangement.

Why this algorithm:

- Radix sorting is highly efficient for integer keys because each pass works on bits instead of comparisons.
- It avoids the cost of full comparison-based sorting in large datasets.
- It is a natural fit for constrained stack operations, where the algorithm can reorganize values using push and rotate operations.

This is the preferred strategy for larger or highly disordered inputs, where a quadratic method would be too expensive.

### 4. Adaptive strategy selection

The project includes an adaptive mode driven by a disorder metric. The function `compute_disorder` measures how far the input is from sorted order by counting inversions relative to the total number of possible pairs.

The logic is:

- low disorder -> simple sort
- medium disorder -> medium sort
- high disorder -> complex sort

Why this matters:

- The same input set can behave very differently depending on its structure.
- Not all random or partially ordered stacks need the same algorithm.
- Adaptive selection gives more consistent performance while keeping the code easier to reason about and benchmark.

---

## Project structure

The source tree is organized around the different sorting strategies and support modules:

- `main.c`: entry point and execution flow.
- `flags.c`: parsing of global options and strategy selection.
- `disorder.c`: disorder metric and adaptive sorting choice.
- `simple_sort.c`: simple stack sorting method.
- `medium_sort.c` and `medium_sort_2.c`: medium block-based strategy.
- `complex_sort.c`: radix-like sorting algorithm.
- `parse.c`: input validation and number parsing.
- `checker/`: the checker program and its helpers.
- `metrics.c`: benchmarking and operation counting.

---

## Resources

### Relevant references

- 42 Project subject: Push Swap
- Introduction to Algorithms, by Cormen, Leiserson, Rivest, Stein
- Radix sort and bitwise sorting references
- Sorting theory and stack-based algorithm design notes
- Articles and tutorials on inversion counting and adaptive algorithm selection

### AI usage

AI was used only to help prepare this README file, mainly for:

- writing a clear and readable project description,
- structuring the instructions and usage examples,
- summarizing the algorithm choices in an understandable way,
- improving the overall presentation of the documentation.

No AI-generated solution was used as a substitute for the actual project implementation or algorithm design; the code and logic were developed directly by the project authors.

---

## Final note

This project is a strong example of how algorithm choice matters in real-world optimization problems: a better sorting strategy can drastically reduce the number of operations, especially when combined with adaptive selection based on measured disorder. It also demonstrates the importance of clean input validation, benchmarking, and modular project design in a competitive programming context.
