#include <stdio.h>

int sum(int limit) {
    int a = 1, b = 2;
    int even_sum = 0;

    while (b <= limit) {
        if (b % 2 == 0) {
            even_sum += b;
        }
        int temp = a;
        a = b;
        b += temp;
    }

    return even_sum;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int result = sum(n);
        printf("%d\n", result);
    }

    return 0;
}
