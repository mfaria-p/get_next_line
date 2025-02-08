# get_next_line

## Description
The `get_next_line` project provides a function to read content line by line from various input sources, such as files, standard input (stdin), or network connections. This function is crucial for handling text data sequentially, making it an essential tool for future projects requiring line-by-line processing.

The project includes both a standard version and a bonus version that supports multiple file descriptors. The function reads a line from a file descriptor until a newline character is encountered or the end of the file is reached.

## Features
- **Read from multiple sources**: Supports reading from files, stdin, or network connections.
- **Line-by-line reading**: Efficiently retrieves content one line at a time.
- **Multiple file descriptors (Bonus version)**: Allows reading from multiple file descriptors simultaneously.
- **Memory management**: Includes utility functions for memory allocation and string manipulation.

## Files
- `get_next_line.c` – Implementation of the `get_next_line` function for reading from a single file descriptor.
- `get_next_line.h` – Header file containing function prototypes and macro definitions for the standard version.
- `get_next_line_bonus.c` – Implementation of the `get_next_line` function for reading from multiple file descriptors.
- `get_next_line_bonus.h` – Header file containing function prototypes and macro definitions for the bonus version.
- `get_next_line_utils.c` – Utility functions used by the standard version of `get_next_line`.
- `get_next_line_utils_bonus.c` – Utility functions used by the bonus version of `get_next_line`.

## Usage
To use the `get_next_line` function in your project, include the appropriate header file and call the function with a file descriptor:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

For the bonus version, include the `get_next_line_bonus.h` header file and use the same approach to read from multiple file descriptors.

## Compilation
Compile the project using a C compiler, such as `gcc`:

```sh
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o get_next_line
gcc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c -o get_next_line_bonus
```

