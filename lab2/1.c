#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

void copyArray(int *source, int *dest, int n) {
    for (int i = 0; i < n; i++)
        dest[i] = source[i];
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        swap(&arr[i], &arr[min]);
    }
}

int main() {
    int unsorted[MAX], temp[MAX], n;
    FILE *fp;

    printf("Enter number of elements to generate in file: ");
    scanf("%d", &n);

    fp = fopen("numbers.txt", "w");

    srand(time(0));
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", rand() % 100000);
    }
    fclose(fp);

    fp = fopen("numbers.txt", "r");

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &unsorted[i]);
    }
    fclose(fp);

    copyArray(unsorted, temp, n);
    clock_t start = clock();
    bubbleSort(temp, n);
    clock_t end = clock();
    printf("Bubble Sort Time: %.6f sec\n", (double)(end - start) / CLOCKS_PER_SEC);

    copyArray(unsorted, temp, n);
    start = clock();
    selectionSort(temp, n);
    end = clock();
    printf("Selection Sort Time: %.6f sec\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
