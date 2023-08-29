#include <stdio.h>
#include <math.h>

int main() {
    int n, m, a;
    scanf("%d %d %d", &n, &m, &a);
    
    int stones = ceil((double)n / a) * ceil((double)m / a);
    printf("%d\n", stones);
    
    return 0;
}
