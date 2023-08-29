#include <stdio.h>

int sum_of_multiples(int a, int b, int n) {
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % a == 0 || i % b == 0) {
            total_sum += i;
        }
    }
    return total_sum;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        int a = 3, b = 5;
        int result = sum_of_multiples(a, b, n);
        printf("%d\n", result);
    }
    
    return 0;
}
    