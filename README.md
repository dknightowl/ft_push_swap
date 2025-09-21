```
                              █████
                             ░░███
 ████████  █████ ████  █████  ░███████              █████  █████ ███ █████  ██████   ████████
░░███░░███░░███ ░███  ███░░   ░███░░███            ███░░  ░░███ ░███░░███  ░░░░░███ ░░███░░███
 ░███ ░███ ░███ ░███ ░░█████  ░███ ░███           ░░█████  ░███ ░███ ░███   ███████  ░███ ░███
 ░███ ░███ ░███ ░███  ░░░░███ ░███ ░███            ░░░░███ ░░███████████   ███░░███  ░███ ░███
 ░███████  ░░████████ ██████  ████ █████ █████████ ██████   ░░████░████   ░░████████ ░███████
 ░███░░░    ░░░░░░░░ ░░░░░░  ░░░░ ░░░░░ ░░░░░░░░░ ░░░░░░     ░░░░ ░░░░     ░░░░░░░░  ░███░░░
 ░███                                                                                ░███
 █████                                                                               █████
░░░░░                                                                               ░░░░░
```

## 🗺️  Overview

`push_swap` is a program that sorts data in stack using a limited set of instructions, aiming to achieve the lowest possible number of actions, and two stacks - `A` and `B`. `A` serves an the input stack and `B` serves as the auxiliary stack that is initially empty to facilitate the sorting process.

This implementation sorts 100 integers under **700** operations, and 500 integers under **5500** operations.

## 🎯 Features

✔️ Sorts within the confines of a limited instruction set:
- `sa`, `sb`,`ss` – swap the first two elements
- `pa`, `pb` – push top element between stacks
- `ra`, `rb`, `rr` – rotate stack upwards
- `rra`, `rrb`, `rrr` – rotate stack downwards

✔️ Validates input:
- Detects **duplicates**
- Checks **integer overflow / underflow**
- Ensures all arguments are **valid integers**

✔️ Optimized for:
- **Small datasets** (2 - 5 numbers)
- **Large datasets** (>5, 100, 500 numbers)

## 📁 Project Structure

```
ft_push_swap
├─ Makefile
├─ README.md
├─ checker_linux
├─ includes
│  └─ push_swap.h
├─ libft
├─ push_swap
└─ srcs
   ├─ CBI.c
   ├─ CBI_helper.c
   ├─ LIS.c
   ├─ LIS_helper.c
   ├─ create.c
   ├─ free.c
   ├─ instruct_comb.c
   ├─ instruct_single.c
   ├─ log.c
   ├─ main.c
   ├─ normalize.c
   ├─ preprocess.c
   ├─ sort_big.c
   ├─ sort_big_helper.c
   ├─ sort_small.c
   ├─ stack_ops_extra.c
   ├─ stack_ops_std.c
   ├─ utils.c
   └─ validate.c
```

## 🚀 Usage

### Compile and execute
1. `make`
2. `./push_swap <list_of_integers>`

Example:
```
./push_swap 9 0 -217 2147483647 -2147483648
```

Testing with randomized inputs (for 500 integers, for example)
```sh
ARG=$(seq -250 249 | shuf | tr '\n' ' '); ./push_swap $ARG
```

### Validation checker program

To run `push_swap` with the checker program:
```sh
ARG="0 6 2 1 4 2"; ./push_swap $ARG | ./checker_linux $ARG
```
- `OK` - Stack is sorted
- `KO` - Stack is not sorted
- `Error` - Input error (e.g. `push_swap` is printing something other than the instructions, non-numerical inputs)




