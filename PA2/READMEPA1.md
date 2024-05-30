# PA1

This repository contains a collection of C programs, each serving different purposes. Below are the details for each program along with build and clean instructions.

## first

### Source File: `first.c`

#### Build Instructions:

```bash
gcc -Wall -Werror -fsanitize=address first.c -o first
Clean Instructions:
bash
Copy code
rm -rf first
Description:
The first program reads numbers from a file and determines if each number is a prime or a twin prime.

second
Source File: second.c
Build Instructions:
bash
Copy code
gcc -Wall -Werror -fsanitize=address second.c -o second
Clean Instructions:
bash
Copy code
rm -rf second
Description:
The second program reads input data from a file and performs bitwise operations based on the input commands ("get", "comp", "set").

third
Source File: third.c
Build Instructions:
bash
Copy code
gcc -Wall -Werror -fsanitize=address third.c -o third
Clean Instructions:
bash
Copy code
rm -rf third
Description:
The third program calculates the parity and counts pairs of consecutive 1s in a binary representation of a given number.

fourth
Source File: fourth.c
Build Instructions:
bash
Copy code
gcc -Wall -Werror -fsanitize=address fourth.c -o fourth
Clean Instructions:
bash
Copy code
rm -rf fourth
Description:
The fourth program reads commands and values from a file to manipulate a sorted linked list. It supports insertion and deletion operations.
