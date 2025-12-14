# Digital-Fundamentals-Assignment (Group Project)

---

## 📘 Overview

This repository contains **multiple Digital Fundamentals and Computer Organization laboratory implementations** written in **C**, designed strictly according to **college assignment and lab-record criteria**.

Each module:

* Explains the **theory**, **algorithm**, and **working** clearly
* Displays execution in **step-by-step tabular format**
* Calculates **hits, misses, and hit ratio** wherever applicable

---

# LFU PAGE REPLACEMENT ALGORITHM

**Author:** Jobin James

### Author Role

Responsible for algorithm design, frequency tracking logic, LRU tie-breaking mechanism, and structured output formatting.

## 🔍 What is LFU?

The **Least Frequently Used (LFU)** page replacement algorithm replaces the page with the **lowest usage frequency**.

If two or more pages have the same frequency, the tie is resolved using **LRU (Least Recently Used)** by checking the **oldest timestamp**.

## ✅ Features

* Tracks page hits and misses
* Maintains frequency count for each page
* Uses timestamp for LRU tie-breaking
* Displays frame status after every reference
* Clean and simple C implementation

## 🧠 Algorithm

            1. Initialize frames as empty
            2. Initialize frequency[] and timestamp[]
            3. For each page reference:

            * If page found → **HIT**

                * Increase frequency
                * Update timestamp
            * Else → **MISS**

                * If empty frame exists, insert page
                * Else replace page with:

                * Minimum frequency
                * Oldest timestamp (LRU tie-break)
            4. Display frames after each reference

## 📊 Sample Output

```
            Ref | Frames
            ----+---------------------
            7 |  7  -  -   (M)
            0 |  7  0  -   (M)
            1 |  7  0  1   (M)
            2 |  2  0  1   (M)
            0 |  2  0  1   (H)
            ...
            Hits: 3
            Misses: 9
            Hit Ratio: 25.00%
```

---

# LRU PAGE REPLACEMENT ALGORITHM

**Author:** Jidhin Mathew

### Author Role

Implemented timestamp-based tracking, frame replacement logic, and tabular output formatting.

## 🧠 Overview

The **Least Recently Used (LRU)** algorithm replaces the page that has **not been used for the longest time**.

## 🧮 Algorithm Steps

            1. Initialize frames as empty
            2. For each page reference:

            * If present → HIT
            * Else → MISS
            * If frames full, replace least recently used page
            3. Display working in table format
            4. Calculate hit ratio

## 📊 Sample Output (Tabular)

            ```
            | Page | Hit/Miss | Action         | Frames       |
            |------|----------|----------------|--------------|
            |  55  | MISS     | Inserted       | 1 55 - -     |
            |  55  | HIT      | No Change      | 1 55 - -     |
            |   3  | MISS     | Replaced (LRU) | 3 55 7 9     |
            ```

---

# DIRECT MAPPING CACHE SIMULATION

**Author:** ___________________________

### Author Role

Designed cache mapping logic, index/tag calculation, and conflict-miss visualization.

## 🧠 Overview

Direct mapping maps each memory block to **exactly one cache line** using a fixed function.

## 🔢 Address Format

| TAG | INDEX |

**Formulas:**

            * Index = BlockNumber % CacheSize
            * Tag   = BlockNumber / CacheSize

## 📊 Sample Output

            ```
            | Block | Index | Tag | Hit/Miss | Cache |
            |-------|-------|-----|----------|-------|
            |   1   |   1   |  0  | MISS     | - 0 - - |
            ```

---

# ASSOCIATIVE CACHE MAPPING WITH FIFO

**Author:** ___________________________

### Author Role

Implemented associative search, FIFO replacement logic, and full tabular cache visualization.

## 🧠 Overview

Associative mapping allows a block to be placed in **any cache line**. FIFO decides replacement order.

## 🔢 Address Format

| TAG | WORD |

**Formulas:**

* TAG  = Address / BlockSize
* WORD = Address % BlockSize

## 📊 Sample Output

            ```
            | Address | TAG | WORD | Hit/Miss | Cache |
            |---------|-----|------|----------|-------|
            |   999   | 249 |  3   | MISS     | 249 13 19 5 |
            ```

---

# QUEUE IMPLEMENTATION IN C

**Author:** Josekutty Shoby

### Author Role

Implemented FIFO logic, overflow/underflow handling, and menu-driven operations.

## 🧠 Overview

A basic **array-based queue** implementation demonstrating FIFO behavior.

## 🔁 Operations

* Enqueue
* Dequeue
* Peek
* Display

Handles:

* Queue Overflow
* Queue Underflow

---

## 🛠 Algorithm


            Step 1: Start the program.
            Step 2: Declare the queue array with fixed size and initialize front = -1, rear = -1, hits = 0, and misses = 0.
            Step 3: For each enqueue request, check whether the element is already present in the queue by scanning from front to rear.
            Step 4: If the element is found, increment the hit count, display the current queue content, and mark the result as Hit.
            Step 5: If the element is not found, increment the miss count and check whether the queue is full.
            Step 6: If the queue is full, remove the front element using FIFO replacement by shifting all elements one position to the left.
            Step 7: Insert the new element at the rear of the queue and display the updated queue content, marking the result as Miss.
            Step 8: For a dequeue request, check whether the queue is empty.
            Step 9: If the queue is empty, display Underflow.
            Step 10: If the queue is not empty, delete the element at the front by incrementing front and display the updated queue content with status Deleted.
            Step 11: Repeat enqueue and dequeue operations until all requests are completed.
            Step 12: Calculate the hit ratio using the formula Hit Ratio = Hits / (Hits + Misses).
            Step 13: Display the total number of hits, misses, and the hit ratio.
            Step 14: Stop the program.


---

## 🎯 Learning Outcomes

* Understanding of page replacement algorithms
* Cache mapping techniques
* Hit and miss analysis
* FIFO and LRU concepts
* Structured tabular output interpretation

---

## ✅ Conclusion

This project provides a **clear, structured, and professional demonstration** of key concepts in **Operating Systems, Cache Memory, and Data Structures**, making it ideal for **college lab records, viva preparation, and group evaluation**.
