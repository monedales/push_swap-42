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
- **3 elements**: Maximum 2 operations using conditional logic
- **4-5 elements**: Use of stack B as auxiliary storage

### Large Numbers (100+ elements) - *In Development*
- **Turk Algorithm**: Efficient sorting for larger datasets
- **Chunk-based approach**: Divide and conquer strategy
- **Cost analysis**: Calculate optimal moves for each element
- **Performance targets**: Meet strict operation count requirements


## Source Code Structure 📂

### Core Implementation
• **`src/push_swap.c`** - Main program entry point and algorithm coordination

• **`src/ft_parsing.c`** - Command-line argument parsing and stack initialization 

• **`src/ft_args_validation.c`** - Input validation (duplicates, integer overflow, format checking)

• **`src/ft_sorting.c`** - Sorting algorithms for different input sizes (2-5 elements optimized)

### Stack Operations
• **`src/operations-swap.c`** - Swap operations (sa, sb, ss)

• **`src/operations-push.c`** - Push operations (pa, pb)

• **`src/operations-rotate.c`** - Rotate operations (ra, rb, rr)

• **`src/operations-reverse.c`** - Reverse rotate operations (rra, rrb, rrr)

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

### Development Commands
• **Clean object files**: `make clean`

• **Remove all generated files**: `make fclean`

• **Rebuild from scratch**: `make re`

• **Check code style**: `make normi`

## Used Tests 🧪

• [Push Swap Tester](https://github.com/laisarena/push_swap_tester)

• [Push Swap Visualizer](https://push-swap42-visualizer.vercel.app/)

## Current Status 🚧

**Completed:**
- Small number sorting algorithms (2-5 elements)
- All stack operations implemented and tested
- Input parsing and validation
- Memory management and error handling
- Project structure organization

**🔄 In Progress:**
- Turk Algorithm implementation for large numbers (100-500 elements)
- Performance optimization and testing
- Final project validation

## Useful Links 🔗

• [Artigo do divo que inventou o algoritmo](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

• [Doubly Linked List in C – GeeksforGeeks](https://www.geeksforgeeks.org/c/doubly-linked-list-in-c/)

• [Sorting Algorithms – GeeksforGeeks](https://www.geeksforgeeks.org/sorting-algorithms/) 

• [Stack Data Structure – GeeksforGeeks](https://www.geeksforgeeks.org/c/stack-data-structure-in-c/)

• [Algorithm Complexity Analysis – Khan Academy](https://www.khanacademy.org/computing/computer-science/algorithms/asymptotic-notation/a/asymptotic-notation)

• [Memory Management in C – Tutorialspoint](https://www.tutorialspoint.com/cprogramming/c_memory_management.htm)

## License 📜

This project was developed for academic purposes at 42 School, but feel free to use it as reference or inspiration for your own learning journey.
