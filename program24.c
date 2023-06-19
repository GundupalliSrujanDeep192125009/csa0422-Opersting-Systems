#include <stdio.h>
#include <math.h>

#define BLOCK_SIZE 8192     
#define POINTER_SIZE 4      
#define NUM_DIRECT_BLOCKS 12
#define INDIRECT_BLOCK_SIZE (BLOCK_SIZE / POINTER_SIZE)
#define DOUBLE_INDIRECT_BLOCK_SIZE (INDIRECT_BLOCK_SIZE * INDIRECT_BLOCK_SIZE)
#define TRIPLE_INDIRECT_BLOCK_SIZE (DOUBLE_INDIRECT_BLOCK_SIZE * INDIRECT_BLOCK_SIZE)

unsigned long long calculateMaxFileSize() {
    unsigned long long maxFileSize = 0;
    unsigned long long totalBlocks = 0;
    totalBlocks = NUM_DIRECT_BLOCKS + INDIRECT_BLOCK_SIZE + DOUBLE_INDIRECT_BLOCK_SIZE + TRIPLE_INDIRECT_BLOCK_SIZE;
    maxFileSize = (unsigned long long)totalBlocks * BLOCK_SIZE;

    return maxFileSize;
}

int main() {
    unsigned long long maxFileSize = calculateMaxFileSize();
    printf("Maximum file size in bytes: %llu\n", maxFileSize);
    
    return 0;
}
