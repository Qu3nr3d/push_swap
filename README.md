*This project has been created as part of the 42 curriculum by kgirczyc, akacpere.*

# Push Swap

## Description

Push Swap is a sorting algorithm challenge designed to teach algorithmic optimization and stack-based problem solving. The project requires sorting a stack of integers in ascending order using a limited set of operations, with the primary goal of minimizing the number of moves required.

The solver works with two stacks (`a` and `b`) and implements multiple sorting strategies, each optimized for different input characteristics:
- **Simple Sort**: Quadratic approach for small or nearly sorted inputs
- **Medium Sort**: Block-based partitioning for medium-sized inputs
- **Complex Sort**: Radix-based algorithm for large or highly disordered inputs
- **Adaptive Mode**: Automatically selects the best strategy based on input disorder

### Project Components

- **push_swap**: The main program that generates an optimal sequence of operations to sort the input stack
- **checker**: A validation program that verifies whether a sequence of operations successfully sorts a given input

### Supported Operations

The following stack operations are available:
- `sa`, `sb`, `ss`: Swap the first two elements of stack a, stack b, or both
- `pa`, `pb`: Push the top element from stack b to stack a (or vice versa)
- `ra`, `rb`, `rr`: Rotate stack a, b, or both upward (move first element to end)
- `rra`, `rrb`, `rrr`: Reverse rotate stack a, b, or both downward (move last element to front)

---

## Instructions

### Compilation

Build the main push_swap program:

```bash
make
```

Build the checker program:

```bash
make bonus
```

### Execution

**Basic usage:**

```bash
./push_swap 3 2 1 4 5
```

This outputs a sequence of operations that sorts the stack.

**Validate a solution:**

```bash
./push_swap 3 2 1 4 5 | ./checker_linux 3 2 1 4 5
```

If the operations successfully sort the input, the checker prints `OK`; otherwise, it prints `KO`.

### Strategy Selection Flags

The program supports the following flags for strategy selection:

- `--simple`: Use simple quadratic sorting (best for small/nearly sorted inputs)
- `--medium`: Use block-based sorting (balanced performance for medium inputs)
- `--complex`: Use radix-based sorting (optimal for large or disordered inputs)
- `--adaptive`: Automatically choose strategy based on disorder metric
- `--bench`: Benchmark mode for performance analysis and comparison

**Examples:**

```bash
./push_swap --simple 4 3 2 1
./push_swap --medium 9 8 7 6 5 4 3 2 1
./push_swap --complex 50 40 30 20 10
./push_swap --adaptive 12 7 5 9 8 1 3
./push_swap --bench --adaptive 100 42 7 89 3 12
```

---

## Algorithm Design and Justification

### 1. Simple Sort Strategy

**When to use:** Small inputs (typically < 10 elements) or nearly sorted stacks

**Algorithm:**
1. Find the minimum value in stack `a`
2. Rotate stack `a` so the minimum reaches the top (using `ra` or `rra`)
3. Push the minimum to stack `b` (using `pb`)
4. Repeat until all elements are moved to `b`
5. Push elements back to stack `a` in correct order (using `pa`)

**Time Complexity:** O(n²)  
**Why this approach:** Simplicity and reliability are prioritized over optimization for small inputs. Quadratic complexity is acceptable when the input size is small or close to sorted.

### 2. Medium Sort Strategy

**When to use:** Medium-sized inputs (typically 10-500 elements) with moderate disorder

**Algorithm:**
1. Determine a block size based on the total number of elements (e.g., √n)
2. Partition elements into ranges and sort each range using directional logic
3. Use a two-pass approach with "level" and "orientation" mechanisms
4. Push elements from appropriate ranges to stack `b` in the first pass
5. Merge sorted sections progressively using `pa` and rotations

**Time Complexity:** O(n log n) in practice  
**Why this approach:** Balances performance and implementation complexity. Better than naive quadratic sorting while remaining practical to code and debug.

### 3. Complex Sort Strategy (Radix-Based)

**When to use:** Large inputs or highly disordered stacks (typically > 500 elements)

**Algorithm:**
1. Assign each value an index based on its sorted position
2. Process indices bit by bit, from least significant to most significant
3. For each bit position:
   - Elements with bit = 0 are pushed from stack `a` to stack `b`
   - Elements with bit = 1 remain in stack `a`
4. Rotate stack `a` to maintain relative order of elements with bit = 1
5. After processing all bits, push everything from `b` back to `a` in correct order

**Time Complexity:** O(n log max_value) - efficient for large datasets  
**Why this approach:** Radix sorting is highly efficient because it avoids comparison-based sorting. Each pass processes a single bit, exploiting the structure of integer keys. Natural fit for stack-based operations.

### 4. Adaptive Strategy Selection

**Algorithm:**
- Calculate a "disorder metric" that measures how far the input is from sorted order
- The metric counts inversions (pairs where a larger element appears before a smaller one)
- Based on disorder percentage:
  - Low disorder (< 25%) → Simple sort
  - Medium disorder (25-75%) → Medium sort
  - High disorder (> 75%) → Complex sort

**Why this matters:** The same algorithm doesn't work optimally for all inputs. Adaptive selection ensures consistent performance by matching the algorithm to the input characteristics, avoiding worst-case scenarios while maintaining code simplicity.

---

## Technical Notes

- **Input Validation:** All input is validated for duplicates, integer overflow, and invalid format. Duplicate values result in program termination.
- **Memory Management:** The program uses dynamic memory allocation with proper cleanup. No memory leaks.
- **Operation Tracking:** Each operation is counted to measure sorting efficiency and allow benchmarking.
- **Checker Compatibility:** Output format strictly follows 42 specifications for compatibility with the official checker.

---

## Resources

### Relevant References

- **42 Project Subject:** Push Swap official specifications
- **Radix Sort:**
  - Wikipedia: Radix Sort
  - "Radix Sorting" in Introduction to Algorithms
  - youtube: https://www.youtube.com/watch?v=ujb2CIWE8zY
- **Stack-Based Algorithms:**
  - Classic stack operation problems and solutions
  - Wikipedia: chunking
- **Algorithm Analysis:**
  - Time and space complexity analysis techniques
  - Inversion counting and disorder metrics
  - geek4geeks: c structures

### AI Usage

AI was used for README documentation creation