#include <stdio.h>
#include <stdlib.h>

int abs(int a) {
    return a < 0 ? -a : a;
}

void cscan(int tracks[], int n, int initialPos) {
    int totalHeadMovement = 0;
    int currentPos = initialPos;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }
    int i;
    for (i = 0; i < n; i++) {
        if (tracks[i] >= initialPos) {
            break;
        }
    }

    printf("Sequence of tracks visited:\n");
    for (int j = i; j < n; j++) {
        printf("%d ", tracks[j]);
        totalHeadMovement += abs(tracks[j] - currentPos);
        currentPos = tracks[j];
    }
    printf("0 ");

    totalHeadMovement += abs(0 - currentPos);
    currentPos = 0;
    for (int j = 0; j < i; j++) {
        printf("%d ", tracks[j]);
        totalHeadMovement += abs(tracks[j] - currentPos);
        currentPos = tracks[j];
    }
    printf("\n\nAverage head movement: %.2f\n", (float)totalHeadMovement / n);
}
int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int initialPos = 5;
    printf("No of tracks: %d\nTrack position: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", tracks[i]);
    }
    printf("\n");
    cscan(tracks, n, initialPos);
    return 0;
}
