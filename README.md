Sure, here's the README translated into English:

---

# List Running Processes

This C program lists the running processes on a Linux system by displaying their ID, name, and memory usage.

## Prerequisites

This program is designed to work on Linux systems.

## Compilation

To compile the program, you can use any standard C compiler. For example, with gcc, you can run the following command:

```bash
gcc list-processus.c -o list
```

## Usage

Once compiled, execute the program by simply typing:

```bash
./list
```

The program will then display a list of running processes, including their ID, name, and memory usage.

## Operation

The program uses the `/proc` directory in Linux to access information about running processes. It traverses this directory and opens the `status` file of each process to extract relevant information such as ID, name, and memory usage.

## Limitations

This program will only work on Linux systems, as it relies on the specific `/proc` file system structure in Linux.



