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

