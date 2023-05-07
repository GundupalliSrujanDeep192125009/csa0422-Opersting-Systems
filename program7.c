#include <stdio.h>

#define MAX_FRAMES 3

int main() {
    int reference_string[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int num_pages = sizeof(reference_string) / sizeof(int);

    int frames[MAX_FRAMES];
    int page_faults = 0;

    for (int i = 0; i < num_pages; i++) {
        int page = reference_string[i];

        int found = 0;
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            page_faults++;

            // Find the least recently used page
            int lru_index = 0;
            int lru_page = frames[lru_index];
            for (int j = 1; j < MAX_FRAMES; j++) {
                if (frames[j] == 0) {
                    lru_index = j;
                    break;
                } else if (frames[j] == lru_page) {
                    lru_index = j;
                } else if (frames[j] < lru_page) {
                    lru_index = j;
                    lru_page = frames[lru_index];
                }
            }

            frames[lru_index] = page;
        }

        printf("Page %d -> Frames: ", page);
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == 0) {
                printf("-");
            } else {
                printf("%d", frames[j]);
            }
            if (j < MAX_FRAMES - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}
