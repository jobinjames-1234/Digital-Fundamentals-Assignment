# Digital-Fundamentals-Assignment For Gorup
LFU Page Replacement Algorithm (C Program)

This project implements the LFU (Least Frequently Used) page replacement algorithm using C.
LFU replaces the page with the lowest frequency of use.
If multiple pages have the same frequency, the tie is broken using LRU (Least Recently Used) by checking the oldest timestamp.

🔍 What is LFU?

The Least Frequently Used page replacement algorithm works by:

    . Counting how many times each page is used.

    . Replacing the page with the least usage frequency when a page fault occurs.

    . If two or more pages have the same frequency, the page that was used longest ago is removed.

    . This algorithm helps in cases where frequently used pages should stay in memory longer.

✅ Features

Tracks:

    . Page hits

    . Page misses

    . Frequency count of each page

    . Timestamp for LRU tie-breaking

    . Step-by-step frame display after each page reference

    . Clean and simple C implementation

Suitable for:

    . College lab programs

    . OS assignment projects

File Structure:
    
      lfu:
      algorithm:
         lfu_algorithm.txt
      code:
         lfu.c
      illustration:
         lfu_illustration.png
      output:
         lfu_output.txt


Algorithm:

Initialize frames as empty
Initialize frequency[] and timestamp[]

For each page in reference string:
    If page is found → HIT:
        Increase frequency
        Update timestamp

    Else → MISS:
        If empty frame exists:
            Insert page with freq=1 and timestamp

        Else:
            Select a victim:
                Page with smallest frequency
                Tie → oldest timestamp (LRU)

            Replace victim with new page

Print frames and hit/miss after every reference

Sample Output:

    Ref | Frames
    ----+---------------------
    7 |  7  -  -   (M)
    0 |  7  0  -   (M)
    1 |  7  0  1   (M)
    2 |  2  0  1   (M)
    0 |  2  0  1   (H)
    3 |  2  0  3   (M)
    ...
    Total refs: 12
    Hits: 3
    Misses: 9
    Hit ratio: 25.00%

# LRU (Least Recently Used) Page Replacement Algorithm

## Overview
This project implements the **Least Recently Used (LRU) page replacement algorithm** in C.  
The program simulates memory management in an operating system by tracking page references and replacing the page that has not been used for the longest period of time when a page fault occurs.

The working of the algorithm is displayed **step-by-step in tabular format**, making it suitable for **academic assignments and lab records**.
# Direct Mapping Cache Simulation

## Overview
This project implements **Direct Mapping Cache Memory** in C.  
Each memory block is mapped to exactly one cache line using a fixed mapping function.

The program displays the cache working **step-by-step in tabular format**, including
block number, index calculation, tag comparison, hit/miss status, and cache contents.
# Associative Cache Mapping with FIFO Replacement

## Overview
This project implements **Associative Cache Mapping** using the **FIFO (First-In First-Out) replacement policy** in C.  
The program simulates cache behavior by dividing memory addresses into **TAG** and **WORD** fields, performing associative search, and displaying the complete working in **tabular format**.

This implementation is designed as part of a **Cache Memory / Computer Organization laboratory assignment**.

---

## Objectives
- To simulate the **LRU page replacement algorithm**
- To identify **page hits and page faults**
- To replace the **least recently used page**
- To display the complete working in **tabular form**
- To calculate **total hits, total misses, and hit ratio**

---

## Algorithm Used
**Least Recently Used (LRU)**

When a page fault occurs and no free frame is available, the page that was **used least recently** is replaced.
- To understand **direct mapping cache technique**
- To compute **index and tag values**
- To identify **cache hits and misses**
- To visualize cache behavior using **tabular output**
- To calculate **hit ratio**

---

## Address Mapping
In Direct Mapping, the address is divided as:

| TAG | INDEX |


Formulas:
Index = BlockNumber % CacheSize
Tag = BlockNumber / CacheSize
- To understand **associative cache mapping**
- To implement **TAG and WORD address fields**
- To apply **FIFO replacement policy**
- To display cache working step-by-step in **tabular form**
- To calculate **cache hits, misses, and hit ratio**

---

## Cache Address Format
In associative mapping, a memory address is divided as:

| TAG | WORD |



- **TAG** identifies the memory block
- **WORD** identifies the word inside the block
- There is **no index field** in associative mapping

Formulas used:
TAG = Address / BlockSize
WORD = Address % BlockSize



---

## Input
- Number of pages  
- Page reference string  
- Number of frames  
- Cache size
- Number of memory blocks
- Memory block reference string

---

## Output
- Page number for each reference  
- Hit or Miss indication  
- Action taken (Inserted / Replaced / No change)  
- Frame contents after each reference  
- Total hits  
- Total misses  
- Hit ratio  

---

## Algorithm Steps (Summary)
   1. Initialize all frames as empty.
   2. For each page reference:
      - If the page is already in a frame, it is a **HIT**.
      - If not present, it is a **MISS**.
      - If a free frame exists, insert the page.
      - Otherwise, replace the **least recently used** page.
   3. Display the working after each reference.
   4. Calculate and display hit ratio.
- Block number
- Cache line index
- Tag
- Hit or Miss
- Action performed
- Cache contents after each access
- Total hits, misses, and hit ratio
## Algorithm: Associative Mapping with FIFO Replacement

   1. Start.
   2. Read the number of cache lines.
   3. Read the block size (words per block).
   4. Read the number of memory addresses and the reference string.
   5. Initialize all cache tags to empty (−1).
   6. Initialize:
      - hits = 0
      - misses = 0
      - filled = 0
      - fifoIndex = 0
   7. For each memory address:
      - Compute TAG and WORD.
      - Search TAG in all cache lines.
      - If TAG found → HIT.
      - Else → MISS:
      - If cache not full, insert TAG.
      - Else replace TAG using FIFO policy.
      - Display the working in tabular format.
   8. Calculate hit ratio.
   9. Display total hits, misses, and hit ratio.
   10. Stop.

---

## Program Features
   - Associative cache search
   - FIFO replacement policy
   - Step-by-step **tabular output**
   - Displays:
   - Address
   - TAG
   - WORD
   - Hit/Miss
   - FIFO action
   - Cache contents
   - Calculates hit ratio

---

## Sample Input
   Number of pages: 10
   Page sequence:
   7 0 1 2 0 3 0 4 2 3
   Number of frames: 3


## Sample Output (Tabular)
      LRU PAGE REPLACEMENT (WORKING)
      -----------------------------------------------------------------
      | Page | Hit/Miss | Action              | Frames                  |
      -----------------------------------------------------------------
      |    1 | MISS     | Inserted            | 1 - - - |
      |   55 | MISS     | Inserted            | 1 55 - - |
      |    7 | MISS     | Inserted            | 1 55 7 - |
      |   55 | HIT      | No change           | 1 55 7 - |
      |    9 | MISS     | Inserted            | 1 55 7 9 |
      |    7 | HIT      | No change           | 1 55 7 9 |
      |    3 | MISS     | Replaced (LRU)      | 3 55 7 9 |
      |    2 | MISS     | Replaced (LRU)      | 3 2 7 9 |
      |    7 | HIT      | No change           | 3 2 7 9 |
      |    6 | MISS     | Replaced (LRU)      | 3 2 7 6 |
      -----------------------------------------------------------------

Cache lines: 4
Block size: 4
Addresses:
1 2 3 55 76 23 999 44 23 33


---

## Sample Output (Tabular)
         ASSOCIATIVE MAPPING WITH FIFO (WORKING)
         -------------------------------------------------------------------------------------
         | Address | TAG | WORD | Hit/Miss | Action (FIFO)     | Cache Contents               |
         -------------------------------------------------------------------------------------
         |       1 |   0 |    1 | MISS     | Inserted          | 0 - - -                      |
         |       2 |   0 |    2 | HIT      | No Change         | 0 - - -                      |
         |       3 |   0 |    3 | HIT      | No Change         | 0 - - -                      |
         |      55 |  13 |    3 | MISS     | Inserted          | 0 13 - -                     |
         |      76 |  19 |    0 | MISS     | Inserted          | 0 13 19 -                    |
         |      23 |   5 |    3 | MISS     | Inserted          | 0 13 19 5                    |
         |     999 | 249 |    3 | MISS     | Replaced line 0   | 249 13 19 5                  |
         |      44 |  11 |    0 | MISS     | Replaced line 1   | 249 11 19 5                  |
         |      23 |   5 |    3 | HIT      | No Change         | 249 11 19 5                  |
         |      33 |   8 |    1 | MISS     | Replaced line 2   | 249 11 8 5                   |
         |      44 |  11 |    0 | HIT      | No Change         | 249 11 8 5                   |
         |      55 |  13 |    3 | MISS     | Replaced line 3   | 249 11 8 13                  |
         -------------------------------------------------------------------------------------

         Total Hits   = 4
         Total Misses = 8
         Hit Ratio    = 0.33

...

---

## Technologies Used
- Programming Language: **C**
- Compiler: GCC / Turbo C
- Platform: Windows / Linux
   Cache size: 4
   Blocks: 1 2 3 4 5 1 6 2 7 3

---
## Sample Output
      DIRECT MAPPING CACHE (WORKING)
      ---------------------------------------------------------------------------------
      | Block | Index | Tag | Hit/Miss | Action           | Cache Contents            |
      ---------------------------------------------------------------------------------
      |     1 |     1 |   0 | MISS     | Loaded/Replaced  | - 0 - - |
      |     2 |     2 |   0 | MISS     | Loaded/Replaced  | - 0 0 - |
      |     3 |     3 |   0 | MISS     | Loaded/Replaced  | - 0 0 0 |
      |     4 |     0 |   1 | MISS     | Loaded/Replaced  | 1 0 0 0 |
      |     5 |     1 |   1 | MISS     | Loaded/Replaced  | 1 1 0 0 |
      |     1 |     1 |   0 | MISS     | Loaded/Replaced  | 1 0 0 0 |
      |     6 |     2 |   1 | MISS     | Loaded/Replaced  | 1 0 1 0 |
      |     2 |     2 |   0 | MISS     | Loaded/Replaced  | 1 0 0 0 |
      |     7 |     3 |   1 | MISS     | Loaded/Replaced  | 1 0 0 1 |
      |     3 |     3 |   0 | MISS     | Loaded/Replaced  | 1 0 0 0 |
      ---------------------------------------------------------------------------------

      Total Hits   = 0
      Total Misses = 10
      Hit Ratio    = 0.00

- Programming Language: C
- Compiler: GCC / Turbo C
- Platform: Windows / Linux

---

## Learning Outcomes
- Understanding of **page replacement techniques**
- Practical knowledge of **LRU algorithm**
- Ability to analyze **hit and miss behavior**
- Visualization of memory frames using tabular output
- Understanding of **fixed mapping**
- Knowledge of **cache conflicts**
- Ability to analyze cache efficiency
- Clear understanding of associative cache mapping
- Practical implementation of FIFO replacement
- Insight into cache hit and miss behavior
- Ability to visualize cache working using tables

---

## Conclusion
The LRU page replacement algorithm efficiently manages memory by removing the page that has not been accessed for the longest time. This implementation clearly demonstrates the working of the algorithm and is suitable for laboratory and academic use.

---
Direct mapping is simple and fast but suffers from conflict misses.
This program clearly demonstrates its working using tabular representation.

---
This program demonstrates how associative cache mapping works with FIFO replacement. By showing the internal working in a tabular format, it provides a clear understanding of cache behavior, making it suitable for academic and lab record submissions.

---
# Queue Implementation in C
A simple C program demonstrating the fundamentals of the Queue data structure using the FIFO (First In, First Out) principle.

## Overview
This project implements a basic array-based queue and simulates common queue operations such as insertion, deletion, viewing the front element, and displaying all queue elements.

This program helps beginners understand:
- How queues work  
- How front and rear pointers update  
- Overflow and underflow conditions  
- FIFO behavior in data structures


## Queue Structure
The queue uses an array and maintains two pointers:

- front – Index of the first element  
- rear – Index of the last element  

### Queue Operations
- Enqueue – Insert an element  
- Dequeue – Remove an element  
- Peek – View the first element  
- Display – Show all elements  
- Handles Queue Overflow and Queue Underflow

## How It Works
A queue follows the FIFO principle:


