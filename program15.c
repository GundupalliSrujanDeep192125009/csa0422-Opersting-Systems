#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 100

int tracks[MAX_TRACKS];
int num_tracks;

void read_input() {
    printf("Enter the number of tracks: ");
    scanf("%d", &num_tracks);
    printf("Enter the track positions: ");
    for (int i = 0; i < num_tracks; i++) {
        scanf("%d", &tracks[i]);
    }
}

void fcfs(int head_pos) {
    int curr_pos = head_pos;
    int total_head_movement = 0;
    for (int i = 0; i < num_tracks; i++) {
        total_head_movement += abs(tracks[i] - curr_pos);
        curr_pos = tracks[i];
    }
    printf("Average head movement for FCFS: %.2f\n", (float)total_head_movement / num_tracks);
}

int main() {
    int head_pos = 50; // starting head position
    read_input();
    fcfs(head_pos);
    return 0;
}
