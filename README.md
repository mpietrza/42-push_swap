# 42 push_swap 🚀

> Summary: Implementation of the 42 push_swap project in C. The program outputs a sequence of operations that sorts a stack of distinct integers using a second auxiliary stack and a restricted set of operations. The implementation focuses on correctness, input validation, and producing a reasonably efficient sequence of moves.

---

## 📁 Repository layout (root)
- Makefile
- checker_Mac (provided checker binary for macOS)
- checker_linux (provided checker binary for Linux)
- libft/ (local libft dependency)
- include/ (public headers)
- srcs/ (source files)

---

## 📂 srcs/ (actual files)
The sorting logic and helpers are implemented in srcs/:

- actions_rr_rrr.c
- data_parse_preparation.c
- exit_free.c
- find_cheapest.c
- give_index.c
- give_push_price.c
- oprs_push.c
- oprs_r_rotate.c
- oprs_rotate.c
- oprs_swap.c
- push_swap.c
- range_3.c
- range_s.c
- stack_utils.c
- stack_utils2.c
- stack_utils3.c
- utils.c
- what_rotation.c

Key entrypoint: srcs/push_swap.c

---

## ✅ Features
- Full set of allowed operations implemented:
  - sa, sb, ss
  - pa, pb
  - ra, rb, rr
  - rra, rrb, rrr
- Robust input parsing and validation:
  - Accepts command-line arguments (multiple or quoted)
  - Detects invalid integers and overflow
  - Detects duplicate values and reports errors
- Memory management and controlled exits with cleanup
- Strategy separation for different input sizes (small/large ranges)
- Included checker binaries for local verification:
  - checker_Mac (macOS)
  - checker_linux (Linux)

---

## 🔧 Build
From repository root:
```bash
make         # build push_swap (and any additional targets defined in Makefile)
make clean   # remove object files
make fclean  # remove object files and executables
make re      # rebuild everything
```

Note: The Makefile is at the project root. If you use a custom libft in libft/, ensure the Makefile links against it or build libft first.

---

## 🚀 Usage
Basic usage:
```bash
# Example: sort 5 numbers
./push_swap 2 1 3 6 5
```

You can also pass many numbers quoted:
```bash
./push_swap "3 2 5 1 4"
```

To validate output using the provided checker (choose the correct binary for your OS):
```bash
# On Linux
./push_swap 3 2 1 | ./checker_linux 3 2 1

# On macOS
./push_swap 3 2 1 | ./checker_Mac 3 2 1
```

The program prints one operation per line. On invalid input the program must print "Error" to stderr and exit with a non-zero status.

---

## 🧪 Testing & Debugging Tips
- Start with very small inputs (2–5) to verify correctness and minimal operation counts.
- Use the provided checker binary to verify that a produced sequence sorts the stack.
- Test edge cases: repeated values, non-numeric input, and integer overflow.
- Use tooling (valgrind, sanitizers) to check for memory leaks and undefined behavior.
- Add temporary debug prints of stacks/state while developing (remove for final submission).

---

## 📌 Error handling rules (project requirements)
- Print "Error" and exit non-zero for:
  - Non-integer or out-of-range values
  - Duplicate values
  - Wrong input format
- Do not print extraneous output on success — only the operations sequence.

---

## 🧠 Algorithms & Strategy notes
- Small N (2–3–5): implement optimized minimal-move solutions.
- Larger N: use a chunk-based approach or indexed/radix-like method to reduce total operations.
- The code includes helpers for computing move costs (find_cheapest.c, give_push_price.c) and for choosing rotations (what_rotation.c).

---

## 🛠️ Implementation notes
- Stack utilities live across stack_utils{,2,3}.c.
- Operation implementations are in oprs_*.c.
- push_swap.c contains main orchestration and flow.
- Ensure your Makefile compiles all srcs/ files and links correctly to libft if needed.

---

## 🎯 Learning outcomes
- Algorithm design under restricted operation sets
- Careful input validation and defensive programming in C
- Data structure manipulation (stacks) and move-cost reasoning
- Writing correct, memory-safe C code suitable for testing with an external checker
