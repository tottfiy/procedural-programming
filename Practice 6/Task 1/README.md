

### 1. Compile the Source Files

You need to compile `main.c` and `c_list.c` into object files (`.o` files). Run the following commands:

```bash
gcc -c main.c -o main.o
gcc -c c_list.c -o c_list.o
```

### 2. Link the Object Files

After creating the object files, link them together to create the final executable:

```bash
gcc -o list main.o c_list.o
```


### 3. Run the Program

- On **Linux/macOS**:
  ```bash
  ./my_program
  ```


## Single-Step Compilation

You can also compile and link in a single step using:

```bash
gcc -o my_program main.c c_list.c
```

This will directly create the executable `my_program` without creating intermediate object files.


