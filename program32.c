#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void sortTracks(int tracks[], int numTracks) {
    int i, j, temp;
    for (i = 0; i < numTracks - 1; i++) {
        for (j = i + 1; j < numTracks; j++) {
            if (tracks[i] > tracks[j]) {
                temp = tracks[i];
                tracks[i] = tracks[j];
                tracks[j] = temp;
            }
        }
    }
}
float calculateAverageHeadMovement(int tracks[], int numTracks, int headPosition, bool direction) {
    int totalHeadMovement = 0;
    int currentIndex;
    int i;
    for (i = 0; i < numTracks; i++) {
        if (tracks[i] == headPosition) {
            currentIndex = i;
            break;
        }
    }

     
    if (direction) {
        
        for (i = currentIndex; i < numTracks; i++) {
            totalHeadMovement += abs(tracks[i] - headPosition);
            headPosition = tracks[i];
        }

        
        totalHeadMovement += abs(tracks[numTracks - 1] - tracks[0]);
        headPosition = tracks[0];

        for (i = 0; i < currentIndex; i++) {
            totalHeadMovement += abs(tracks[i] - headPosition);
            headPosition = tracks[i];
        }
    } else {
        
        for (i = currentIndex; i >= 0; i--) {
            totalHeadMovement += abs(tracks[i] - headPosition);
            headPosition = tracks[i];
        }

        
        totalHeadMovement += abs(tracks[0] - tracks[numTracks - 1]);
        headPosition = tracks[numTracks - 1];

        for (i = numTracks - 1; i > currentIndex; i--) {
            totalHeadMovement += abs(tracks[i] - headPosition);
            headPosition = tracks[i];
        }
    }

    
    float averageHeadMovement = (float)totalHeadMovement / numTracks;

    return averageHeadMovement;
}

int main() {
    int numTracks = 9;
    int tracks[] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int headPosition = 50;
    bool direction = true;  

    
    sortTracks(tracks, numTracks);

    
    float averageHeadMovement = calculateAverageHeadMovement(tracks, numTracks, headPosition, direction);
    printf("Average Head Movement: %.2f\n", averageHeadMovement);

    return 0;
}
