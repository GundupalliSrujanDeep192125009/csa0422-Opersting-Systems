#include <stdio.h>
#include <stdlib.h>

int abs_diff(int a, int b) {
    return abs(a - b);
}

void sort_tracks(int tracks[], int num_tracks) {
    // Sort the tracks in ascending order
    for (int i = 0; i < num_tracks - 1; i++) {
        for (int j = 0; j < num_tracks - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                // Swap tracks[j] and tracks[j+1]
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int num_tracks = sizeof(tracks) / sizeof(tracks[0]);
    int head_position, direction, total_head_movement = 0;

    printf("Enter the initial head position: ");
    scanf("%d", &head_position);

    // Sort the tracks in ascending order
    sort_tracks(tracks, num_tracks);

    printf("Head Movement: ");

    // Find the index of the first track greater than the head position
    int i = 0;
    while (i < num_tracks && tracks[i] < head_position) {
        i++;
    }

    // Set the direction based on the head position and track order
    if (i == 0 || i == num_tracks) {
        // If the head position is at the beginning or end, move in the same direction
        direction = (i == 0) ? 1 : -1;
    } else {
        // Choose the direction based on the nearest track
        int prev_diff = abs_diff(tracks[i - 1], head_position);
        int next_diff = abs_diff(tracks[i], head_position);
        direction = (prev_diff <= next_diff) ? -1 : 1;
    }

    // Perform C-LOOK disk scheduling
    while (i >= 0 && i < num_tracks) {
        printf("%d ", tracks[i]);
        total_head_movement += abs_diff(head_position, tracks[i]);
        head_position = tracks[i];
        i += direction;
    }

    printf("\n");
    printf("Average Head Movement: %.2f\n", (float)total_head_movement / num_tracks);

    return 0;
}
