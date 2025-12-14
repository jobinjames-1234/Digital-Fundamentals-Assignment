# LRU (Least Recently Used) Page Replacement Algorithm

## Overview
This project implements the **Least Recently Used (LRU) page replacement algorithm** in C.  
The program simulates memory management in an operating system by tracking page references and replacing the page that has not been used for the longest period of time when a page fault occurs.

The working of the algorithm is displayed **step-by-step in tabular format**, making it suitable for **academic assignments and lab records**.

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

---

## Input
- Number of pages  
- Page reference string  
- Number of frames  

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


---

## Technologies Used
- Programming Language: **C**
- Compiler: GCC / Turbo C
- Platform: Windows / Linux

---

## Learning Outcomes
- Understanding of **page replacement techniques**
- Practical knowledge of **LRU algorithm**
- Ability to analyze **hit and miss behavior**
- Visualization of memory frames using tabular output

---

## Conclusion
The LRU page replacement algorithm efficiently manages memory by removing the page that has not been accessed for the longest time. This implementation clearly demonstrates the working of the algorithm and is suitable for laboratory and academic use.

---