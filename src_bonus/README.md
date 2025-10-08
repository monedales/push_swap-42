# Checker - Bonus Program

## 📖 Overview

The **checker** program validates whether a sequence of operations correctly sorts a stack.

**What it does:**
- Reads a list of numbers (like push_swap)
- Reads operations from stdin (sa, pb, rra, etc.)
- Executes operations **silently** (no output)
- Prints `OK` if final stack is sorted, `KO` if not
- Prints `Error` for invalid operations or input

---

## 🚀 Usage

```bash
# Compile the checker
make bonus

# Test with manual operations
echo -e "sa\nrra" | ./checker 3 2 1

# Validate push_swap output
./push_swap 3 2 1 | ./checker 3 2 1

# Test with file input
./checker 3 2 1 < operations.txt
```

---

## 📂 Core File: `read_operations.c`

This file reads operation instructions from stdin and executes them silently.

---

## Function 1: `ft_execute_operation()`

```c
static void ft_execute_operation(t_stack **stack_a, t_stack **stack_b, char *operation)
```

Takes a **string** (like `"sa\n"`) and executes the corresponding stack operation.

**Parameters:**
- `stack_a` - Pointer to stack A
- `stack_b` - Pointer to stack B  
- `operation` - Operation string (e.g., `"sa\n"`, `"pb\n"`, `"rra\n"`)

**How it works:**

```c
if (ft_strncmp(operation, "sa\n", 3) == 0)
    ft_sa_silent(stack_a);
```
If the operation string is `'sa\n'` (comparing first 3 characters), call `ft_sa_silent()` to swap the top 2 elements of stack A **without printing**.

**Why `3`?** Because `"sa\n"` has 3 characters: `'s'`, `'a'`, `'\n'` (newline from `get_next_line`)

```c
else if (ft_strncmp(operation, "pb\n", 3) == 0)
    ft_pb_silent(stack_a, stack_b);
```
If it's `'pb\n'`, push from A to B.

```c
else if (ft_strncmp(operation, "rra\n", 4) == 0)
    ft_rra_silent(stack_a);
```
If it's `'rra\n'`, reverse rotate A (last becomes first).

**Why `4`?** Because `"rra\n"` has 4 characters: `'r'`, `'r'`, `'a'`, `'\n'`

```c
else
    ft_error();
```
If the operation string doesn't match ANY valid operation, print `Error` and exit.

**This catches:**
- Invalid operations like `"xyz\n"`
- Misspelled operations like `"saa\n"`
- Empty lines
- Any garbage input

**Why is it `static`?**
Only visible within this file - it's a helper function for internal use.

**Benefits:**
- Encapsulation (hides implementation details)
- Avoids naming conflicts
- Follows the principle of "expose only what's necessary"

---

## Function 2: `ft_read_and_execute_operations()`

```c
void ft_read_and_execute_operations(t_stack **stack_a, t_stack **stack_b)
```

Continuously reads operations from stdin and executes them until there's no more input.

**Parameters:**
- `stack_a` - Pointer to stack A
- `stack_b` - Pointer to stack B

**How it works:**

**Initialize:**
```c
char *line;
```
Create a variable to hold each line of input.

**Read first line:**
```c
line = get_next_line(0);
```
Read from file descriptor `0` (stdin).

**What is `get_next_line(0)`?**
- Reads one line at a time from a file descriptor
- Returns the line as a string (including the `\n`)
- Returns `NULL` when there's no more input

**Why `0`?**
- File descriptor `0` = stdin (keyboard/pipe input)
- File descriptor `1` = stdout (screen output)
- File descriptor `2` = stderr (error output)

**Loop while there's input:**
```c
while (line)
{
```
Keep looping as long as `line` is not NULL.

**Execute the operation:**
```c
    ft_execute_operation(stack_a, stack_b, line);
```
Parse and execute the operation.

**Free memory:**
```c
    free(line);
```
Free the memory allocated by `get_next_line`.

**Why is this critical?**
- `get_next_line` allocates memory with `malloc` for each line
- Without freeing, you have a **memory leak**
- In a loop, this leak grows with each iteration
- The checker might read hundreds of operations!

**Memory leak example (BAD):**
```c
line = get_next_line(0);  // Allocates 10 bytes
line = get_next_line(0);  // Allocates 10 bytes (lost pointer to first!)
line = get_next_line(0);  // Allocates 10 bytes (lost pointers!)
// After 100 operations: 1000 bytes leaked!
```

**Proper memory management (GOOD):**
```c
line = get_next_line(0);  // Allocates 10 bytes
free(line);               // Frees 10 bytes
line = get_next_line(0);  // Allocates 10 bytes
free(line);               // Frees 10 bytes
// Memory usage stays constant!
```

**Read next line:**
```c
    line = get_next_line(0);
```
Read the next line from stdin and loop back.

**Loop ends:**
When `get_next_line(0)` returns `NULL` (no more input), the loop exits and the function returns.

---

## 🎬 Complete Execution Flow

**Input from stdin:**
```
sa
pb
ra
```

**What happens:**

```c
// First iteration:
line = get_next_line(0);          // line = "sa\n"
while (line) {                     // "sa\n" is not NULL, enter loop
    ft_execute_operation(..., "sa\n");  // Executes ft_sa_silent()
    free(line);                    // Free "sa\n"
    line = get_next_line(0);       // line = "pb\n"
}

// Second iteration:
while (line) {                     // "pb\n" is not NULL, continue loop
    ft_execute_operation(..., "pb\n");  // Executes ft_pb_silent()
    free(line);                    // Free "pb\n"
    line = get_next_line(0);       // line = "ra\n"
}

// Third iteration:
while (line) {                     // "ra\n" is not NULL, continue
    ft_execute_operation(..., "ra\n");  // Executes ft_ra_silent()
    free(line);                    // Free "ra\n"
    line = get_next_line(0);       // line = NULL (end of input)
}

// Exit loop:
while (line) {                     // NULL is false, exit loop
// Function returns to caller (checker.c main)
```

---

## Design Principles

**Separation of Concerns:**
- `ft_read_and_execute_operations()` handles input loop and memory management
- `ft_execute_operation()` handles operation dispatch and validation
- Silent operation functions handle actual stack manipulation

Each function has ONE clear job!

**Error Handling:**
```c
else
    ft_error();  // Catches ALL invalid operations
```
One place to handle all invalid input. No scattered error checks.

**Memory Safety:**
```c
free(line);  // Always free after use
```
No memory leaks, even with hundreds of operations.

**Extensibility:**
Want to add a new operation? Just add one `else if`:
```c
else if (ft_strncmp(operation, "new_op\n", 7) == 0)
    ft_new_op_silent(stack_a);
```

**Maintainability:**
Clear logic flow:
1. Read line
2. Execute operation
3. Free line
4. Repeat

---

## 🧪 Testing Examples

### Valid operations
```bash
$ echo -e "sa\nrra" | ./checker 2 1 3
OK
```
Operations execute successfully and result in a sorted stack.

### Invalid operation
```bash
$ echo -e "sa\nINVALID" | ./checker 3 2 1
Error
```
Program stops immediately when encountering an invalid operation.

### Pipe from push_swap
```bash
$ ./push_swap 3 2 1 | ./checker 3 2 1
OK
```
Checker validates that push_swap's operations correctly sort the stack.

---

## 📊 Push_swap vs Checker

### Push_swap (Main Program):
```c
ft_sa(stack_a);           // Executes swap AND prints "sa\n"
ft_pb(stack_a, stack_b);  // Executes push AND prints "pb\n"
```
**Purpose:** Generate sorting instructions  
**Output:** `sa`, `pb`, `ra`, etc.

### Checker (Bonus):
```c
ft_sa_silent(stack_a);           // Executes swap, NO printing
ft_pb_silent(stack_a, stack_b);  // Executes push, NO printing
```
**Purpose:** Validate sorting instructions  
**Output:** Nothing during operations, only final `OK` or `KO` or `Error`

---

## 🎯 Key Takeaways

1. **`ft_execute_operation()`** = String parser + operation dispatcher
   - Takes operation string, executes corresponding function
   - Validates input, calls `ft_error()` for invalid operations

2. **`ft_read_and_execute_operations()`** = Input loop + memory manager
   - Reads operations one by one from stdin
   - Frees memory properly to prevent leaks

3. **`get_next_line(0)`** = Read from stdin one line at a time
   - `0` = stdin file descriptor
   - Returns line with `\n` included
   - Returns `NULL` when input ends

4. **`free(line)`** = Essential to prevent memory leaks
   - Must free after each `get_next_line` call
   - Critical in loops with many iterations

5. **`\n` in comparisons** = Because `get_next_line` includes newlines
   - `"sa\n"` not `"sa"`
   - Length is 3 not 2

6. **`static`** = Hide helper function from other files
   - Internal implementation detail
   - Not part of public API

7. **`ft_error()`** = Catch ALL invalid operations in one place
   - Centralized error handling
   - Prints "Error\n" to stderr and exits

8. **Silent operations** = Execute without printing
   - `ft_sa_silent()`, `ft_pb_silent()`, etc.
   - Reuse generic functions: `swap_generic()`, `push_generic()`, etc.

---

## 💡 Design Patterns

**Command Pattern:** Operation strings (`"sa"`, `"pb"`, etc.) are commands dispatched to appropriate handlers.

**Strategy Pattern:** Different silent operation functions implement the same interface but different behaviors.

**Single Responsibility Principle (SRP):**
- `ft_read_and_execute_operations()` only handles I/O loop
- `ft_execute_operation()` only handles dispatching
- Silent functions only handle stack operations

**Don't Repeat Yourself (DRY):** Generic functions (`swap_generic`, `push_generic`, etc.) are reused by both main program and checker.
