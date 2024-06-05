#include <stdio.h>

int main(void) {
    int numbers[] = {2,3,4,5,6,7};
    int length = sizeof(numbers)/sizeof(numbers[0]);


    int key = 3;
    int left = 0;
    int right = length - 1;

    while(left<=right) {
        int mid =  (left + right)/2;

        if(numbers[mid] == key) {
            printf("%d is found at index %d" , key, mid);
            return 0;
        }
        if(numbers[mid]<key) {
            left = mid +1;
        }else {
            right = mid - 1;
        }
    }
    printf("Not found3");
    return 0;


}