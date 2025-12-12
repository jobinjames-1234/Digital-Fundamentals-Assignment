#include <stdio.h>

int main() {
    int pages[30], frames[10], time[10];
    int no_of_pages, no_of_frames;
    int i, j, flag1, flag2, pos, counter = 0, page_faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter the page sequence: ");
    for (i = 0; i < no_of_pages; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    // Initialize frames as empty
    for (i = 0; i < no_of_frames; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nPage\tFrames\n");

    for (i = 0; i < no_of_pages; i++) {
        flag1 = flag2 = 0;

        // Check if page is already in frame
        for (j = 0; j < no_of_frames; j++) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;   // update recent use time
                flag1 = flag2 = 1;
                break;
            }
        }

        // If page not found in frame
        if (flag1 == 0) {
            for (j = 0; j < no_of_frames; j++) {
                if (frames[j] == -1) {  // empty frame
                    counter++;
                    page_faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If no empty frame → replace using LRU
        if (flag2 == 0) {
            int min = time[0];
            pos = 0;

            for (j = 1; j < no_of_frames; j++) {
                if (time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            counter++;
            page_faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

        // Print frames status
        printf("%d\t", pages[i]);
        for (j = 0; j < no_of_frames; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
