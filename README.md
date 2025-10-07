# push_swap 🔄

A sophisticated sorting algorithm implementation using two stacks and a limited set of operations, developed as part of the 42 School curriculum to explore algorithmic efficiency and data structure manipulation.

## Description 📜

The push_swap project challenges you to sort a stack of integers using the minimum number of operations. You have two stacks (A and B) and a set of specific operations to manipulate them. The goal is to sort all numbers in stack A in ascending order using the fewest possible moves.

**Key Challenge:** Different input sizes have strict operation limits:

- **3 numbers**: Maximum 3 operations

- **5 numbers**: Maximum 12 operations  

- **100 numbers**: Less than 700 operations for full points

- **500 numbers**: Less than 5500 operations for full points

## Stack Operations Reference 🔧

| Operation | Description | Effect |
|-----------|-------------|--------|
| **sa** | swap a | Swap first 2 elements of stack A |
| **sb** | swap b | Swap first 2 elements of stack B |  
| **ss** | swap both | Execute sa and sb simultaneously |
| **pa** | push a | Push top element from B to A |
| **pb** | push b | Push top element from A to B |
| **ra** | rotate a | Rotate up (first becomes last) in A |
| **rb** | rotate b | Rotate up (first becomes last) in B |
| **rr** | rotate both | Execute ra and rb simultaneously |
| **rra** | reverse rotate a | Rotate down (last becomes first) in A |
| **rrb** | reverse rotate b | Rotate down (last becomes first) in B |
| **rrr** | reverse rotate both | Execute rra and rrb simultaneously |

## Technologies & Concepts 🛠️

• **Data Structures**: Doubly linked lists for stack implementation

• **Algorithm Design**: Sorting algorithms optimized for specific constraints

• **Stack Operations**: Push, pop, swap, rotate operations

• **Memory Management**: Dynamic allocation and proper cleanup

• **Performance Optimization**: Minimizing operation count for different input sizes

• **Parsing & Validation**: Robust input handling and error management

• **Modular Programming**: Clean separation of concerns and reusable functions

## Algorithm Strategy 📊

### Small Numbers (2-5 elements)
- **2 elements**: Maximum 1 operation (sa if needed)
- **3 elements**: Maximum 2 operations using optimized decision tree
- **4-5 elements**: Reduction strategy using stack B as auxiliary storage

### Large Numbers (100-500 elements) - **Turk Algorithm**
- **Chunk-based approach**: Optimized chunk sizes for different dataset sizes
  - 50 elements: chunks of 10
  - 100 elements: chunks of 25
  - 500 elements: chunks of 70
- **Two-phase sorting**:
  - Phase 1 (A→B): Push elements to stack B in chunks using cost analysis
  - Phase 2 (B→A): Push back to A in optimal order with combined rotations
- **Cost optimization**: Calculate cheapest moves considering both rotation directions
- **Combined operations**: Use rr/rrr when both stacks rotate in same direction


## Source Code Structure 📂

### Core Implementation
• **`src/push_swap.c`** - Main program entry point and algorithm coordination

• **`src/ft_parsing.c`** - Command-line argument parsing and stack initialization 

• **`src/ft_args_validation.c`** - Input validation (duplicates, integer overflow, format checking)

• **`src/ft_sorting.c`** - Sorting dispatcher and algorithms for 2-5 elements

• **`src/ft_algorithm.c`** - Turk algorithm implementation for large datasets (100-500 elements)

### Stack Operations
• **`src/operations-swap.c`** - Swap operations (sa, sb, ss)

• **`src/operations-push.c`** - Push operations (pa, pb)

• **`src/operations-rotate.c`** - Rotate operations (ra, rb, rr)

• **`src/operations-reverse.c`** - Reverse rotate operations (rra, rrb, rrr)

### Turk Algorithm Components
• **`src/ft_chunks.c`** - Chunk size calculation and element selection

• **`src/ft_costs.c`** - Cost calculation for A→B phase

• **`src/ft_costs2.c`** - Additional cost utilities

• **`src/ft_costs_b_to_a.c`** - Cost calculation for B→A phase with target finding

• **`src/ft_movements.c`** - Movement execution and optimization logic

• **`src/ft_rotation_helpers.c`** - Combined rotation optimization (rr/rrr)

### Utilities & Data Management  
• **`src/ft_utils_doubly_list.c`** - Doubly linked list creation and manipulation

• **`src/ft_utils_doubly_list2.c`** - Additional list utilities and helper functions

• **`src/ft_free.c`** - Memory cleanup and error handling

### Headers & Libraries
• **`includes/push_swap.h`** - Main header with type definitions and function declarations

• **`libft/`** - Extended custom library with printf, string manipulation, and memory functions

## Instructions ⚙️

### Building the Project
• Run `make` to compile the main push_swap executable
```bash
make
```

### Running the Program
• **Basic usage**: Pass integers as arguments
```bash
./push_swap 4 67 3 87 23
```

• **Alternative format**: Use quoted string
```bash  
./push_swap "4 67 3 87 23"
```

### Testing 
• **Use the included test script**: Test with different dataset sizes
```bash
bash test.sh 100 200    # Test with 100 numbers, range from 1-200(default it's 100)
bash test.sh 500 1000     # Test with 500 numbers, range from 1-1000
```

### Development Commands
• **Clean object files**: `make clean`

• **Remove all generated files**: `make fclean`

• **Rebuild from scratch**: `make re`

• **Check norminette**: `make normi`

## Used Tests 🧪

• [Push Swap Tester](https://github.com/gemartin99/Push-Swap-Tester)

• [Push Swap Visualizer](https://push-swap42-visualizer.vercel.app/)

## Current Status ✅

**Project Complete!**

📊 **Performance Results:**
- **100 numbers**: ~606-695 operations
- **500 numbers**: ~4873-5073 operations 


## Useful Links 🔗

• [Artigo do divo que inventou o algoritmo](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

• [Doubly Linked List in C – GeeksforGeeks](https://www.geeksforgeeks.org/c/doubly-linked-list-in-c/)

• [Sorting Algorithms – GeeksforGeeks](https://www.geeksforgeeks.org/sorting-algorithms/) 

• [Stack Data Structure – GeeksforGeeks](https://www.geeksforgeeks.org/c/stack-data-structure-in-c/)

• [Algorithm Complexity Analysis – Khan Academy](https://www.khanacademy.org/computing/computer-science/algorithms/asymptotic-notation/a/asymptotic-notation)

• [Memory Management in C – Tutorialspoint](https://www.tutorialspoint.com/cprogramming/c_memory_management.htm)

## License 📜

This project was developed for academic purposes at 42 School, but feel free to use it as reference or inspiration for your own learning journey.
