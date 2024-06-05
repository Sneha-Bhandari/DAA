// sequential sort

#include<stdio.h>

int main() {
    int arr[] = {1, 3, 4, 5, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5; // Define the key to be searched
    int index = -1; // Initialize the index variable to -1

    // Perform sequential search
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            index = i; // Set the index if key is found
            break; // Exit the loop since the key is found
        }
    }

    // Check if key is found or not and print the result
    if (index != -1) {
        printf("Number found at index %d \n", index);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}