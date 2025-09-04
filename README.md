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

This implementation sorts 100 integers under **900** operations, and 500 integers under **8500** operations.

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
- **Small datasets** (2 - 3 numbers)
- **Large datasets** (100 - 500 numbers)

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
   ├─ error.c
   ├─ init.c
   ├─ instruct-push.c
   ├─ instruct-revrotate.c
   ├─ instruct-rotate.c
   ├─ instruct-swap.c
   ├─ log.c
   ├─ main.c
   ├─ sort-big-utils.c
   ├─ sort-big.c
   ├─ sort-small.c
   ├─ stack-read.c
   ├─ stack-write.c
   └─ validate-input.c
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
- `Error` - Input error (e.g. `push_swap` is printing something other than the instructions)


