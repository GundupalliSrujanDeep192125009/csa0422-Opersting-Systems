#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void sortArray(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int findNearestIndex(int arr[], int n, int head) {
    int index = 0;
    int diff = abs(head - arr[index]);
    for (int i = 1; i < n; i++) {
        if (abs(head - arr[i]) < diff) {
            index = i;
            diff = abs(head - arr[i]);
        }
    }
    return index;
}


float calculateAverageHeadMovement(int tracks[], int n, int head, int direction) {
    int i, headIndex, totalMovement = 0;
    int* visited = (int*)calloc(n, sizeof(int));
    
    
    sortArray(tracks, n);

    
    headIndex = findNearestIndex(tracks, n, head);
    
   
    int increment = direction == 1 ? 1 : -1;
    
    
    i = headIndex;
    while (i >= 0 && i < n) {
        totalMovement += abs(head - tracks[i]);
        visited[i] = 1;
        head = tracks[i];
        i += increment;
    }
    
   
    i = headIndex - increment;
    while (i >= 0 && i < n) {
        if (visited[i] == 0) {
            totalMovement += abs(head - tracks[i]);
            head = tracks[i];
            visited[i] = 1;
        }
        i -= increment;
    }
    
    free(visited);
    
    
    return (float)totalMovement / n;
}

int main() {
    int numTracks = 5;
    int tracks[] = {55, 58, 60, 70, 18};
    int headPosition = 50;
    int direction = 1; 
    
    float avgHeadMovement = calculateAverageHeadMovement(tracks, numTracks, headPosition, direction);
    printf("Average head movement: %.2f\n", avgHeadMovement);
    
    return 0;
}
