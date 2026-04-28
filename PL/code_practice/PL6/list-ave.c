#include <stdio.h>

double list_ave(int *list, int size) {
    if (size == 0) {
        return 0.0;
    }
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += list[i];
    }
    return (double)sum / size;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    double average = list_ave(arr, size);
    printf("리스트의 평균: %.2f\n", average);
    return 0;
}