#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_REFERENCES 20

int frames[MAX_FRAMES];
int num_frames = 0;
int num_references = 0;
int references[MAX_REFERENCES];
int faults = 0;

void print_frames() {
    printf("Frames: ");
    for (int i = 0; i < num_frames; i++) {
        printf("%d ", frames[i]);
    }
    printf("\n");
}

int find_next_use(int page, int start_index) {
    for (int i = start_index; i < num_references; i++) {
        if (references[i] == page) {
            return i;
        }
    }
    return num_references;
}

int replace_page(int page, int current_index) {
    int max_future_use = -1;
    int replace_index = -1;
    for (int i = 0; i < num_frames; i++) {
        int next_use = find_next_use(frames[i], current_index);
        if (next_use > max_future_use) {
            max_future_use = next_use;
            replace_index = i;
        }
    }
    frames[replace_index] = page;
    faults++;
    return replace_index;
}

int main() {
    int num_frames = 3;
    int num_references = 19;
    int reference_sequence[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};

    for (int i = 0; i < num_references; i++) {
        int page = reference_sequence[i];
        int page_index = -1;
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == page) {
                page_index = j;
                break;
            }
        }
        if (page_index == -1) {
            if (num_frames < MAX_FRAMES) {
                frames[num_frames] = page;
                num_frames++;
                faults++;
            } else {
                page_index = replace_page(page, i);
            }
        }
        print_frames();
    }

    printf("Number of page faults: %d\n", faults);

    return 0;
}
