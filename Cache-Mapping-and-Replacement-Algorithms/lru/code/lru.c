#include <stdio.h>

int main() {
    int pages[30], frames[10], time[10];
    int no_of_pages, no_of_frames;
    int i, j, pos;
    int counter = 0;
    int hits = 0, misses = 0;
    int found, empty;

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter the page sequence:\n");
    for (i = 0; i < no_of_pages; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    // Initialize frames
    for (i = 0; i < no_of_frames; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    // Table header
    printf("\nLRU PAGE REPLACEMENT (WORKING)\n");
    printf("-----------------------------------------------------------------\n");
    printf("| Page | Hit/Miss | Action              | Frames                  |\n");
    printf("-----------------------------------------------------------------\n");

    for (i = 0; i < no_of_pages; i++) {
        found = 0;
        empty = 0;

        // Check HIT
        for (j = 0; j < no_of_frames; j++) {
            if (frames[j] == pages[i]) {
                hits++;
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        // MISS
        if (!found) {
            misses++;

            // Check for empty frame
            for (j = 0; j < no_of_frames; j++) {
                if (frames[j] == -1) {
                    frames[j] = pages[i];
                    counter++;
                    time[j] = counter;
                    empty = 1;
                    break;
                }
            }

            // Replace using LRU
            if (!empty) {
                int min = time[0];
                pos = 0;

                for (j = 1; j < no_of_frames; j++) {
                    if (time[j] < min) {
                        min = time[j];
                        pos = j;
                    }
                }

                frames[pos] = pages[i];
                counter++;
                time[pos] = counter;
            }
        }

        // Print table row
        printf("| %4d | %-8s | %-19s | ",
               pages[i],
               found ? "HIT" : "MISS",
               found ? "No change" : (empty ? "Inserted" : "Replaced (LRU)"));

        for (j = 0; j < no_of_frames; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("|\n");
    }

    printf("-----------------------------------------------------------------\n");

    printf("\nTotal Hits   = %d", hits);
    printf("\nTotal Misses = %d", misses);
    printf("\nHit Ratio    = %.2f\n", (float)hits / (hits + misses));

    return 0;
}
