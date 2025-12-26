# Gold Rabbits (C++)

This project implements the GoldRabbits function, a Fibonacci-style sequence that models rapid rabbit population growth. The program is written in C++ and focuses on performance optimization, integer overflow detection, and command-line argument handling.

## Description
The GoldRabbits sequence follows this rule:

GoldRabbits(n) = GoldRabbits(n-1) + GoldRabbits(n-2)

with base cases:
GoldRabbits(0) = 1  
GoldRabbits(1) = 1  

The program improves efficiency by using a static map to store previously computed values (memoization). It also detects integer overflow and reports the value of n that caused the overflow.

## Files Included
goldRabbits.cpp  
goldRabbits.log  

## How to Compile
```text
g++ goldRabbits.cpp -o goldRabbits
```
## How to Run
```text
./goldRabbits 4 -1 6 -1 45
```

- Positive integers compute the GoldRabbits value
- -1 prints the contents of the stored map
- Non-integer inputs display an error message
- Overflow conditions are reported with an error message

## Features
- Fast Fibonacci-style computation using memoization
- Integer overflow detection with exceptions
- Command-line argument processing
- Efficient execution for large inputs
