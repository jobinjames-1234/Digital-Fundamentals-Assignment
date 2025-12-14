#include <stdio.h>

int main() {
    int cacheSize, n;
    int cacheTag[20], cacheData[20];
    int blocks[50];
    int hits = 0, misses = 0;
    int i, index, tag;

    printf("Enter cache size: ");
    scanf("%d", &cacheSize);

    printf("Enter number of memory blocks: ");
    scanf("%d", &n);

    printf("Enter memory block sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &blocks[i]);
    }

    // Initialize cache
    for (i = 0; i < cacheSize; i++) {
        cacheTag[i] = -1;
        cacheData[i] = -1;
    }

    // Table header
    printf("\nDIRECT MAPPING CACHE (WORKING)\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("| Block | Index | Tag | Hit/Miss | Action           | Cache Contents            |\n");
    printf("---------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        index = blocks[i] % cacheSize;
        tag   = blocks[i] / cacheSize;

        if (cacheTag[index] == tag) {
            hits++;
            printf("| %5d | %5d | %3d | HIT      | No Change        | ",
                   blocks[i], index, tag);
        } else {
            misses++;
            cacheTag[index] = tag;
            cacheData[index] = blocks[i];
            printf("| %5d | %5d | %3d | MISS     | Loaded/Replaced  | ",
                   blocks[i], index, tag);
        }

        for (int j = 0; j < cacheSize; j++) {
            if (cacheTag[j] != -1)
                printf("%d ", cacheTag[j]);
            else
                printf("- ");
        }
        printf("|\n");
    }

    printf("---------------------------------------------------------------------------------\n");
    printf("\nTotal Hits   = %d", hits);
    printf("\nTotal Misses = %d", misses);
    printf("\nHit Ratio    = %.2f\n", (float)hits / (hits + misses));

    return 0;
}
