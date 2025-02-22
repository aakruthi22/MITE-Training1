#include <stdio.h>

#define MAX_AMBULANCES 100

void selectionSort(int distances[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (distances[j] < distances[minIndex]) {
                minIndex = j;
            }
        }
        int temp = distances[i];
        distances[i] = distances[minIndex];
        distances[minIndex] = temp;
    }
}

int main() {
    int distances[MAX_AMBULANCES];
    int n;

    printf("Enter number of ambulances: ");
    scanf("%d", &n);

    printf("Enter distances of ambulances in km:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &distances[i]);
    }

    selectionSort(distances, n);

    printf("Sorted: [");
    for (int i = 0; i < n; i++) {
        printf("%d", distances[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    printf("Nearest Ambulance Assigned: Distance %d km\n", distances[0]);

    return 0;
}
