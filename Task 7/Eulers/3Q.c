#include <stdio.h>

int is_palindrome(int num) {
    int original = num;
    int reversed = 0;

    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }

    return original == reversed;
}

int largest_palindrome(int limit) {
    int max = -1;
    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int product = i * j;
            if (product < limit && is_palindrome(product)) {
                if (product > max) {
                    max = product;
                }
            }
        }
    }
    return max;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int result = largest_palindrome(n);
        printf("%d\n", result);
    }

    return 0;
}
