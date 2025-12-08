# Direct-Mapped Cache Simulation

A C program demonstrating the fundamentals of direct-mapped cache memory in computer architecture.

## Overview

This project implements a simplified direct-mapped cache system that simulates how CPU caches work. It shows the concepts of cache hits, cache misses, and memory access patterns in a direct-mapped cache architecture.

## Project Structure

- `directmapping.c` - Main implementation of the direct-mapped cache simulator

## How It Works

### Cache Configuration
- **Cache Size**: 8 lines
- **Memory Size**: 32 blocks
- **Cache Type**: Direct-mapped (1 block can only map to 1 cache line)

### Cache Structure
Each cache line contains:
- **Valid bit**: Indicates if the cache line contains valid data
- **Tag**: Used to identify which memory block is stored in the cache line
- **Data**: The actual data from the memory block

### Direct Mapping Formula
For a given memory address:
- **Cache Index** = `address % CACHE_SIZE`
- **Tag** = `address / CACHE_SIZE`

## Usage

1. **Compile the program**:
   ```bash
   gcc -o directmapping directmapping.c
   ```

2. **Run the program**:
   ```bash
   ./directmapping
   ```

3. **Enter a memory block number** (0 to 31) when prompted

4. The program will:
   - Calculate the cache line index and tag
   - Check if the data is already in the cache (cache hit)
   - Load the data from memory if not in cache (cache miss)
   - Display the results

## Example Output

```
Enter memory block number (0 to 31): 5

Memory Block: 5
Cache Line Index (address % cache_size): 5
Tag (address / cache_size): 0

CACHE MISS!
Loading block 5 into cache line 5...
New data in cache: 50
```

## Learning Objectives

This project demonstrates:
- Cache organization and addressing
- Direct-mapped cache behavior
- Cache hit vs. cache miss scenarios
- Tag and index calculation
- Basic memory hierarchy concepts

## Requirements

- GCC compiler (or any standard C compiler)
- C standard library (stdio.h)

## Author

Digital Fundamentals Assignment