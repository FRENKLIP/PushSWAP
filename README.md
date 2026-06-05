*This activity has been created as part of the 42 curriculum by fpaluku and kvarfi.*

# Push_swap

## Description

Push_swap is a sorting project written in C. The goal is to sort a stack of
integers in ascending order using only a restricted set of stack operations and
to print those operations to standard output.

The program starts with all integers in stack `a` and an empty stack `b`. The
smallest value must finish at the top of stack `a`.

Allowed operations:

- `sa`, `sb`, `ss`: swap the first two elements of one or both stacks.
- `pa`, `pb`: push the top element from one stack to the other.
- `ra`, `rb`, `rr`: rotate one or both stacks upward.
- `rra`, `rrb`, `rrr`: reverse rotate one or both stacks downward.

## Instructions

Compile the project with:

```sh
make
```

Clean object files:

```sh
make clean
```

Remove object files and the executable:

```sh
make fclean
```

Rebuild from scratch:

```sh
make re
```

Run the program:

```sh
./push_swap 2 1 3 6 5 8
```

The program also accepts the numbers as one quoted argument:

```sh
./push_swap "2 1 3 6 5 8"
```

Check the result with the provided checker:

```sh
ARG="2 1 3 6 5 8"
./push_swap $ARG | ./checker/ubuntu_checker $ARG
```

Expected checker result:

```txt
OK
```

## Strategy Selectors

The subject requires four strategies to be available from the `push_swap`
binary:

- `--simple`: force the simple `O(n^2)` strategy.
- `--medium`: force the medium chunk-based strategy.
- `--complex`: force the radix-style `O(n log n)` strategy.
- `--adaptive`: choose a strategy from the measured disorder. This is the
  default behavior when no selector is given.

Examples:

```sh
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

## Algorithms

### Simple Strategy

The simple strategy is a selection-sort adaptation using two stacks.

It repeatedly finds the smallest value in stack `a`, rotates stack `a` until
that value reaches the top, pushes it to stack `b`, then pushes everything back
to stack `a`.

Complexity in Push_swap operations: `O(n^2)`.

### Medium Strategy

The medium strategy uses indexed values and chunk-based sorting.

The input values are first assigned indexes according to their sorted order.
The algorithm then pushes values from stack `a` to stack `b` by index ranges.
After all chunks are pushed, it repeatedly brings the largest indexed value in
stack `b` to the top and pushes it back to stack `a`.

Complexity target in Push_swap operations: approximately `O(n sqrt(n))`,
depending on chunk size and input distribution.

### Complex Strategy

The complex strategy is a binary radix-sort adaptation.

Each value is represented by its sorted index. For each bit of the index, the
algorithm rotates values whose current bit is `1` and pushes values whose
current bit is `0` to stack `b`. After each pass, all values are pushed back to
stack `a`.

Complexity in Push_swap operations: `O(n log n)`.

### Adaptive Strategy

The adaptive strategy computes a disorder score before performing any move.
The disorder score is the ratio of inverted pairs to total pairs:

```txt
disorder = number_of_inverted_pairs / number_of_pairs
```

Current thresholds:

- `disorder < 0.2`: use the simple strategy.
- `0.2 <= disorder < 0.5`: use the medium strategy.
- `disorder >= 0.5`: use the complex strategy.

The idea is to use simpler logic for mostly ordered inputs and stronger
strategies for more disordered inputs.

## Error Handling

The program writes `Error` followed by a newline to standard error when input
is invalid.

Invalid input includes:

- Non-integer arguments.
- Integers outside the `int` range.
- Duplicate values.

If no arguments are given, the program prints nothing and exits.

## Benchmark Mode

The subject specifies an optional `--bench` mode that should print benchmark
information to standard error while keeping the operation stream on standard
output.

Required benchmark information:

- Computed disorder percentage.
- Selected strategy and theoretical complexity.
- Total number of operations.
- Count for each operation type.

Example expected usage:

```sh
ARG="4 67 3 87 23"
./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker/ubuntu_checker $ARG
cat bench.txt
```

## Resources

- 42 Push_swap subject.
- `man write`
- `man malloc`
- Big-O notation and algorithmic complexity references.
- Stack-based sorting examples and radix sort explanations.

## AI Usage

AI was used as a support tool to review the subject requirements, compare them
with the current implementation, and help draft this README structure. The code
and final project behavior must still be understood, tested, and defended by
the learners.

## Contributors

- `fpaluku`: parsing, validation, stack operations, sorting strategies, testing,
  and documentation.
