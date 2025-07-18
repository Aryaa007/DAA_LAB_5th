#include <stdio.h>
#include <string.h>

typedef struct {
    int value;
    char name[10];
    int number;
} Element;

void BubbleSort(Element s[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(s[j].value > s[j + 1].value) {
                Element temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Element s[n];

    for(int i = 0; i < n; i++) {
        scanf("%d %s %d", &s[i].value, s[i].name, &s[i].number);
    }

    BubbleSort(s, n);

    for(int i = 0; i < n; i++) {
        printf("%d %s %d\n", s[i].value, s[i].name, s[i].number);
    }

    return 0;
}
