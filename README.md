*This project has been created as part of the 42 curriculum by smolines.*

# push_swap

## Description

`push_swap` is an algorithmic project that consists of sorting a stack of integers using a second stack and a limited set of operations, while trying to achieve the sort in as few operations as possible.

You are given a list of unique, random integers as program arguments, stored in stack `a`, with stack `b` initially empty. Using only `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`, the program computes and prints the shortest possible sequence of instructions to sort stack `a` in ascending order (smallest value on top).

This implementation represents each stack as a **doubly-linked list** (`t_list`), where every node stores its own index, target position in the other stack, and push cost. Sorting relies on a **cost-based approach** (similar to Turk's algorithm): at each step, the algorithm identifies the cheapest node to move back to `a` — the one requiring the fewest combined rotations across both stacks — rather than processing elements in a fixed order.

### Sorting strategy by stack size

- **1 element:** already sorted, no action needed.
- **2 elements:** a single `sa` if out of order.
- **3 elements:** sorted directly with a dedicated function (`sort_three_stacka`) using the minimal combination of swaps/rotations.
- **More than 3 elements:**
  1. All elements except the last 3 are pushed to stack `b`.
  2. The remaining 3 elements in `a` are sorted.
  3. While `b` is not empty, the cheapest node is repeatedly identified, rotated into position, and pushed back to `a`.
  4. Once `b` is empty, `a` is rotated in the shortest direction until the minimum value reaches the top.

## Instructions

### Compilation

```bash
make
```

This compiles the project according to the Norm and produces the `push_swap` executable. The Makefile includes the required `$(NAME)`, `all`, `clean`, `fclean`, and `re` rules, and does not perform unnecessary relinking.

### Execution

```bash
./push_swap "2 1 3 6 5 8"
```

The program prints the sequence of operations needed to sort the stack, one instruction per line, separated by `\n`.

### Behavior

- **No arguments:** the program prints nothing and returns to the prompt.
- **Invalid arguments** (non-integers, duplicates, or values outside `INT_MIN`/`INT_MAX`): the program prints `"Error"` followed by `\n` on the standard error.
- **Already sorted stack:** no output.

### Example

```bash
$> ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$> ./push_swap 0 one 2 3
Error
```

### Checking correctness and operation count

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

This counts the number of operations generated. The result can be validated against a `checker` program that replays the instructions on the original stack and confirms whether the result is properly sorted.

### Benchmark targets

| Numbers | Operations (max, full validation) |
|---------|-----------------------------------|
| 100     | < 700                             |
| 500     | ≤ 5500                            |

## Project Structure

```
.
├── Makefile
├── include/
│   └── pushswap.h
└── src/
    ├── cost.c              # node cost calculation, cheapest node selection, 3-element sort
    ├── create_lst.c        # linked list node creation and helpers
    ├── error_free.c        # error handling and memory cleanup
    ├── ft_split.c          # string splitting for argument parsing
    ├── index_position.c    # index assignment, target/min/max lookup
    ├── move_stack.c        # rotation logic to move nodes between stacks
    ├── parsing.c           # argument parsing and stack initialization
    ├── parsing_util.c      # character/number validation helpers
    ├── parsing_util2.c     # additional parsing validation
    ├── push.c              # pa / pb operations
    ├── push_swap.c         # main entry point and sorting orchestration
    ├── reverse_rotate.c    # rra / rrb / rrr operations
    ├── rotate.c            # ra / rb / rr operations
    ├── swap.c              # sa / sb / ss operations
    └── util.c              # general utility functions
```
