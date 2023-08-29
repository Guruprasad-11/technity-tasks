#include <stdio.h>

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result = lcm(result, i);
        }
        
        printf("%d\n", result);
    }
    
    return 0;
}
