# Direct Mapping Cache Simulation

## Overview
This project implements **Direct Mapping Cache Memory** in C.  
Each memory block is mapped to exactly one cache line using a fixed mapping function.

The program displays the cache working **step-by-step in tabular format**, including
block number, index calculation, tag comparison, hit/miss status, and cache contents.

---

## Objectives
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


---

## Input
- Cache size
- Number of memory blocks
- Memory block reference string

---

## Output
- Block number
- Cache line index
- Tag
- Hit or Miss
- Action performed
- Cache contents after each access
- Total hits, misses, and hit ratio

---

## Sample Input
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


---

## Learning Outcomes
- Understanding of **fixed mapping**
- Knowledge of **cache conflicts**
- Ability to analyze cache efficiency

---

## Conclusion
Direct mapping is simple and fast but suffers from conflict misses.
This program clearly demonstrates its working using tabular representation.

---