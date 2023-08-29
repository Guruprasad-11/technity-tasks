#include <stdio.h>

void staircase(int n) {
    for (int i = 1; i <= n; i++) {
        int spaces = n - i;
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    staircase(n);

    return 0;
}
