#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// Function to find the index of the track with the shortest seek time
int findShortestSeekTime(int tracks[], int n, int head) {
    int shortestSeekTime = INT_MAX;
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (abs(tracks[i] - head) < shortestSeekTime) {
            shortestSeekTime = abs(tracks[i] - head);
            index = i;
        }
    }

    return index;
}

// Function to calculate the average head movement
float calculateAverageHeadMovement(int tracks[], int n, int head) {
    int totalHeadMovement = 0;
    int currentTrack = head;

    for (int i = 0; i < n; i++) {
        int shortestSeekIndex = findShortestSeekTime(tracks, n, currentTrack);

        totalHeadMovement += abs(tracks[shortestSeekIndex] - currentTrack);
        currentTrack = tracks[shortestSeekIndex];

        // Mark the visited track as -1 to indicate it has been accessed
        tracks[shortestSeekIndex] = -1;
    }

    return (float)totalHeadMovement / n;
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);

    int head;
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    float avgHeadMovement = calculateAverageHeadMovement(tracks, n, head);
    printf("Average head movement: %.2f\n", avgHeadMovement);

    return 0;
}
