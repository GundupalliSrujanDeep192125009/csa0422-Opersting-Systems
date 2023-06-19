#include <stdio.h>
#include <stdbool.h>

#define NUM_BLOCKS 16
#define INODE_BLOCKS 8
#define FILE_BLOCKS (NUM_BLOCKS - INODE_BLOCKS)


bool isBlockFree(bool allocationMap[], int block) {
    return !allocationMap[block];
}


void allocateBlocks(bool allocationMap[], int startBlock, int numBlocks) {
    for (int i = startBlock; i < startBlock + numBlocks; i++) {
        allocationMap[i] = true;
    }
}


int findNextContiguousBlocks(bool allocationMap[], int numBlocks) {
    int count = 0;
    int startBlock = -1;
    
    for (int i = INODE_BLOCKS; i < NUM_BLOCKS; i++) {
        if (isBlockFree(allocationMap, i)) {
            if (startBlock == -1) {
                startBlock = i;
            }
            
            count++;
            
            if (count == numBlocks) {
                return startBlock;
            }
        } else {
            count = 0;
            startBlock = -1;
        }
    }
    
    return -1;
}

int main() {
    bool allocationMap[NUM_BLOCKS] = {false}; 
    int fileSizes[] = {2, 3, 4, 10}; 
    int numFiles = sizeof(fileSizes) / sizeof(fileSizes[0]);
    
    printf("Available Blocks:\n");
    for (int i = INODE_BLOCKS; i < NUM_BLOCKS; i++) {
        printf("Block %d: Free\n", i);
    }
    
    printf("\n");
    
    
    for (int i = 0; i < numFiles; i++) {
        int fileSize = fileSizes[i];
        printf("Allocating Blocks for File of Size %d KB:\n", fileSize);
        
        if (fileSize < 1) {
            printf("File size must be at least 1 KB.\n");
            return 1;
        }
        
        if (fileSize > FILE_BLOCKS) {
            printf("Not enough contiguous blocks available. Exiting program.\n");
            return 1;
        }
        
        int startBlock = findNextContiguousBlocks(allocationMap, fileSize);
        
        if (startBlock != -1) {
            allocateBlocks(allocationMap, startBlock, fileSize);
            printf("Blocks Allocated: %d to %d\n", startBlock, startBlock + fileSize - 1);
            printf("Allocation Successful!\n");
        } else {
            printf("Not enough contiguous blocks available. Exiting program.\n");
            return 1;
        }
        
        printf("\n");
    }
    
    printf("Final Allocation Map:\n");
    for (int i = 0; i < NUM_BLOCKS; i++) {
        printf("Block %d: %s\n", i, allocationMap[i] ? "Allocated" : "Free");
    }
    
    return 0;
}
