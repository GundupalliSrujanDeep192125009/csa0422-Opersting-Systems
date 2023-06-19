#include <stdio.h>
#include <stdlib.h>

int isPagePresent(int pages[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (pages[i] == page) {
            return 1; 
        }
    }
    return 0; 
}

int getOptimalPageIndex(int pages[], int n, int reference[], int refSize, int currentIndex) {
    int index = -1;
    int farthest = currentIndex;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = currentIndex + 1; j < refSize; j++) {
            if (pages[i] == reference[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == refSize) {
            return i; 
        }
    }
    return (index == -1) ? 0 : index;
}

int countPageFaults(int frames, int reference[], int refSize) {
    int pageFaults = 0;
    int* pages = (int*)malloc(frames * sizeof(int));

    for (int i = 0; i < frames; i++) {
        pages[i] = -1; 
    }

    for (int i = 0; i < refSize; i++) {
        if (!isPagePresent(pages, frames, reference[i])) {
            int optimalIndex = getOptimalPageIndex(pages, frames, reference, refSize, i);
            pages[optimalIndex] = reference[i];
            pageFaults++;
        }
    }

    free(pages);
    return pageFaults;
}

int main() {
    int frames = 3;
    int reference[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int refSize = sizeof(reference) / sizeof(reference[0]);

    int pageFaults = countPageFaults(frames, reference, refSize);
    printf("Number of page faults: %d\n", pageFaults);

    return 0;
}
 
