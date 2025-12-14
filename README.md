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
