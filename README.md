# Associative Cache Mapping with FIFO Replacement

## Overview
This project implements **Associative Cache Mapping** using the **FIFO (First-In First-Out) replacement policy** in C.  
The program simulates cache behavior by dividing memory addresses into **TAG** and **WORD** fields, performing associative search, and displaying the complete working in **tabular format**.

This implementation is designed as part of a **Cache Memory / Computer Organization laboratory assignment**.

---

## Objectives
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
- Programming Language: C
- Compiler: GCC / Turbo C
- Platform: Windows / Linux

---

## Learning Outcomes
- Clear understanding of associative cache mapping
- Practical implementation of FIFO replacement
- Insight into cache hit and miss behavior
- Ability to visualize cache working using tables

---

## Conclusion
This program demonstrates how associative cache mapping works with FIFO replacement. By showing the internal working in a tabular format, it provides a clear understanding of cache behavior, making it suitable for academic and lab record submissions.

---