/* lfu.c
   LFU page replacement simulation in C.
   Tie-breaker: when multiple pages share the same minimum frequency,
   the page with the oldest timestamp (least recently used among them) is evicted.
*/

#include <stdio.h>
#include <limits.h>

void print_frames(int frames[], int capacity) {
    for (int i = 0; i < capacity; ++i) {
        if (frames[i] == -1) printf(" - ");
        else printf("%2d ", frames[i]);
    }
}

void lfu_simulate(int pages[], int n, int capacity) {
    if (capacity <= 0) {
        printf("Frame capacity must be > 0\n");
        return;
    }

    int frames[capacity];     // page numbers in frames
    int freq[capacity];       // usage frequency for each frame
    int time_stamp[capacity]; // last used time (incrementing counter)
    for (int i = 0; i < capacity; ++i) {
        frames[i] = -1;
        freq[i] = 0;
        time_stamp[i] = 0;
    }

    int time_counter = 0;
    int hits = 0, misses = 0;

    printf("LFU simulation (capacity=%d)\n", capacity);
    printf("Ref | Frames (left->right)\n");
    printf("----+---------------------\n");

    for (int i = 0; i < n; ++i) {
        int page = pages[i];
        time_counter++;

        // check hit
        int hit_index = -1;
        for (int j = 0; j < capacity; ++j) {
            if (frames[j] == page) { hit_index = j; break; }
        }

        if (hit_index != -1) {
            // Hit: increase frequency and update timestamp
            freq[hit_index]++;
            time_stamp[hit_index] = time_counter;
            hits++;
            printf("%3d | ", page);
            print_frames(frames, capacity);
            printf("  (H)\n");
            continue;
        }

        // Miss
        misses++;

        // find empty slot if any
        int empty_index = -1;
        for (int j = 0; j < capacity; ++j) {
            if (frames[j] == -1) { empty_index = j; break; }
        }

        if (empty_index != -1) {
            // place page in empty slot
            frames[empty_index] = page;
            freq[empty_index] = 1;
            time_stamp[empty_index] = time_counter;
        } else {
            // find victim: smallest freq, tie-break by oldest time_stamp
            int victim = 0;
            for (int j = 1; j < capacity; ++j) {
                if (freq[j] < freq[victim]) victim = j;
                else if (freq[j] == freq[victim] && time_stamp[j] < time_stamp[victim]) victim = j;
            }
            // replace victim
            frames[victim] = page;
            freq[victim] = 1;
            time_stamp[victim] = time_counter;
        }

        printf("%3d | ", page);
        print_frames(frames, capacity);
        printf("  (M)\n");
    }

    printf("----+---------------------\n");
    printf("Total refs: %d, Hits: %d, Misses: %d, Hit ratio: %.2f%%\n",
           n, hits, misses, 100.0 * hits / n);
}

int main() {
    // Example usage:
    // change the array or capacity to test other sequences
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    lfu_simulate(pages, n, capacity);
    return 0;
}
