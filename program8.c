#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n, head, track[MAX], i;
    int total_movement = 0;

    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    printf("Enter the track positions: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &track[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("The sequence of tracks is: ");
    printf("%d", head);

    for (i = 0; i < n; i++) {
        total_movement += abs(track[i] - head);
        head = track[i];
        printf(", %d", head);
    }

    printf("\nTotal head movement: %d\n", total_movement);
    printf("Average head movement: %.2f\n", (float) total_movement / n);

    return 0;
}
