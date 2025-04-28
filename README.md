# Push_swap

Push_swap is a project from 42 School that consists in sorting a stack of integers using a limited set of operations.  
The goal is to sort the stack with the least number of moves possible.

## Rules

- You must use two stacks: `a` and `b`.
- The program must sort stack `a` in ascending order using only the following operations:
  - `sa` (swap a)
  - `sb` (swap b)
  - `ss` (swap a and b)
  - `pa` (push to a)
  - `pb` (push to b)
  - `ra` (rotate a)
  - `rb` (rotate b)
  - `rr` (rotate both)
  - `rra` (reverse rotate a)
  - `rrb` (reverse rotate b)
  - `rrr` (reverse rotate both)

---

## How It Works

1. Parse input arguments (supporting single and multiple arguments).
2. Validate the input:
   - Check for non-numeric characters.
   - Check for integer overflow.
   - Check for duplicates.
3. Initialize the stacks.
4. Apply a sorting algorithm optimized for small or large sets:
   - For small sets (3-5 numbers): use minimal hardcoded moves.

Use the provided `Makefile`:

```
make
```

## Usage
./push_swap [numbers to sort]
