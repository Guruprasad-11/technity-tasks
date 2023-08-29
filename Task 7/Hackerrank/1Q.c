#include <stdio.h>

void compareTriplets(int* a, int* b, int* result) {
    int alice_score = 0;
    int bob_score = 0;

    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) {
            alice_score++;
        } else if (a[i] < b[i]) {
            bob_score++;
        }
    }

    result[0] = alice_score;
    result[1] = bob_score;
}

int main() {
    int a[3];
    int b[3];
    int result[2];

    for (int i = 0; i < 3; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 3; i++) {
        scanf("%d", &b[i]);
    }

    compareTriplets(a, b, result);

    printf("%d %d\n", result[0], result[1]);

    return 0;
}
