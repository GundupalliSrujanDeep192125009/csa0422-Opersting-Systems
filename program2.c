#include <stdio.h>

int main() {
    int pageFrames = 3;
    int pageReference[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int pageFrame[pageFrames];
    int pageFaults = 0;
    int currentPageFrameIndex = 0;
    int pageReferenceIndex = 0;
    int i, j, k;

    
    for (i = 0; i < pageFrames; i++) {
        pageFrame[i] = -1;
    }

    
    for (i = 0; i < sizeof(pageReference) / sizeof(int); i++) {
        int currentPage = pageReference[i];
        int pageFound = 0;

        
        for (j = 0; j < pageFrames; j++) {
            if (pageFrame[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }

        
        if (!pageFound) {
            pageFaults++;

            pageFrame[currentPageFrameIndex] = currentPage;
            currentPageFrameIndex++;

            
            if (currentPageFrameIndex == pageFrames) {
                currentPageFrameIndex = 0;
            }
        }

        
        for (k = 0; k < pageFrames; k++) {
            printf("%d ", pageFrame[k]);
        }

        if (pageFound) {
            printf("No Page Fault\n");
        } else {
            printf("Page Fault\n");
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
 
