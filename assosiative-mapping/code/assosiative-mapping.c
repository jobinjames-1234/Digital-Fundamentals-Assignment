#include <stdio.h>

int main() {
    int cacheLines, blockSize, n;
    int cacheTag[20];
    int address[50];
    int hits = 0, misses = 0;
    int filled = 0;
    int fifoIndex = 0;
    int i, j;

    printf("Enter number of cache lines: ");
    scanf("%d", &cacheLines);

    printf("Enter block size (words per block): ");
    scanf("%d", &blockSize);

    printf("Enter number of memory addresses: ");
    scanf("%d", &n);

    printf("Enter memory addresses:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &address[i]);
    }

    /* Initialize cache */
    for (i = 0; i < cacheLines; i++) {
        cacheTag[i] = -1;
    }

    /* Table Header */
    printf("\nASSOCIATIVE MAPPING WITH FIFO (WORKING)\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("| Address | TAG | WORD | Hit/Miss | Action (FIFO)     | Cache Contents               |\n");
    printf("-------------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        int tag = address[i] / blockSize;
        int word = address[i] % blockSize;
        int found = 0;
        char action[25] = "No Change";

        /* Search cache */
        for (j = 0; j < cacheLines; j++) {
            if (cacheTag[j] == tag) {
                hits++;
                found = 1;
                break;
            }
        }

        /* MISS handling with FIFO */
        if (!found) {
            misses++;

            if (filled < cacheLines) {
                cacheTag[filled] = tag;
                filled++;
                sprintf(action, "Inserted");
            } else {
                cacheTag[fifoIndex] = tag;
                sprintf(action, "Replaced line %d", fifoIndex);
                fifoIndex = (fifoIndex + 1) % cacheLines;
            }
        } else {
            sprintf(action, "Hit (No replace)");
        }

        /* Print table row */
        printf("| %7d | %3d | %4d | %-8s | %-18s | ",
               address[i], tag, word,
               found ? "HIT" : "MISS",
               action);

        for (j = 0; j < cacheLines; j++) {
            if (cacheTag[j] != -1)
                printf("%d ", cacheTag[j]);
            else
                printf("- ");
        }
        printf("|\n");
    }

    printf("-------------------------------------------------------------------------------------\n");

    /* Final results */
    printf("\nTotal Hits   = %d\n", hits);
    printf("Total Misses = %d\n", misses);
    printf("Hit Ratio    = %.2f\n",
           (float)hits / (hits + misses));

    return 0;
}
