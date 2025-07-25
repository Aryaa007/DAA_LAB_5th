#include <stdio.h>
#include <limits.h>

int main() {
    FILE *file = fopen("numbers.txt", "r");

    int n;
    fscanf(file, "%d", &n);

    if (n < 2) {
        printf("Need at least two numbers.\n");
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    int min = INT_MAX, second_min = INT_MAX;
    int max = INT_MIN, second_max = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            second_min = min;
            min = arr[i];
        } else if (arr[i] < second_min && arr[i] != min) {
            second_min = arr[i];
        }

        if (arr[i] > max) {
            second_max = max;
            max = arr[i];
        } else if (arr[i] > second_max && arr[i] != max) {
            second_max = arr[i];
        }
    }

    if (second_min == INT_MAX) {
        printf("Not Found.\n");
    } else {
        printf("Second Smallest: %d\n", second_min);
    }

    if (second_max == INT_MIN) {
        printf("Not Found\n");
    } else {
        printf("Second Largest: %d\n", second_max);
    }

    return 0;
}
