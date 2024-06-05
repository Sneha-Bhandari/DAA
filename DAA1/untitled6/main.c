#include <stdio.h>

int main(void) {
    int numbers[] = {4, 5, 3, 2, 7, 6};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    // Print unsorted array
    for (int i = 0; i < length; i++) {
        printf(" %d", numbers[i]);
    }
    printf("\n");

    // Insertion Sort
    for (int i = 1; i < length; i++) {
        int key = numbers[i];
        int j = i - 1;

        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = key;
    }

    // Print sorted array
    printf("Sorted array:");
    for (int i = 0; i < length; i++) {
        printf(" %d", numbers[i]);
    }
    printf("\n");

    return 0;
}