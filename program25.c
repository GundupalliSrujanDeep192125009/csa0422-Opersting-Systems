#include <stdio.h>
int calculateContiguousIO(int blockNumber) {
    if (blockNumber == 0) {
        return 0;
    }
    return 1;
}
int calculateLinkedIO(int blockNumber) {
   
    if (blockNumber == 0) {
        return 0;
    }
    return 1;
}
int calculateIndexedIO(int blockNumber) {
    
    if (blockNumber == 0) {
        return 0;
    }
    return 1;
}

int main() {
    int blockNumber;

    blockNumber = 0;
    printf("Contiguous allocation (Case a): %d disk I/O operations\n", calculateContiguousIO(blockNumber));
    printf("Linked allocation (Case a): %d disk I/O operations\n", calculateLinkedIO(blockNumber));
    printf("Indexed allocation (Case a): %d disk I/O operations\n\n", calculateIndexedIO(blockNumber));
    blockNumber = 50;
    printf("Contiguous allocation (Case b): %d disk I/O operations\n", calculateContiguousIO(blockNumber));
    printf("Linked allocation (Case b): %d disk I/O operations\n", calculateLinkedIO(blockNumber));
    printf("Indexed allocation (Case b): %d disk I/O operations\n\n", calculateIndexedIO(blockNumber));
    blockNumber = 99;
    printf("Contiguous allocation (Case c): %d disk I/O operations\n", calculateContiguousIO(blockNumber));
    printf("Linked allocation (Case c): %d disk I/O operations\n", calculateLinkedIO(blockNumber));
    printf("Indexed allocation (Case c): %d disk I/O operations\n\n", calculateIndexedIO(blockNumber));

    return 0;
}
