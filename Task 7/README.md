# Programming
        Solutions for the prombles are here...

## Hackerrank Project Euler: (First 5 problems)

### Problem 1

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
    
    
### Problem 2

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


### Problem 3

#include <stdio.h>

int largest_prime_factor(int n) {
    int largest_factor = 1;
    while (n % 2 == 0) {
        largest_factor = 2;
        n /= 2;
    }
    for (int i = 3; i <= n; i += 2) {
        while (n % i == 0) {
            largest_factor = i;
            n /= i;
        }
    }
    return largest_factor;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        int result = largest_prime_factor(n);
        printf("%d\n", result);
    }
    
    return 0;
}


### Problem 4

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


### Problem 5

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


---


## Hackerrank

### Problem 1

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


### Problem 2

#include <stdio.h>
#include <stdlib.h>

int diagonalDifference(int arr[][100], int n) {
    int left_diag_sum = 0;
    int right_diag_sum = 0;

    for (int i = 0; i < n; i++) {
        left_diag_sum += arr[i][i];
        right_diag_sum += arr[i][n - i - 1];
    }

    return abs(left_diag_sum - right_diag_sum);
}

int main() {
    int n;
    scanf("%d", &n);

    int matrix[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int result = diagonalDifference(matrix, n);

    printf("%d\n", result);

    return 0;
}


### Problem 3

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


### Problem 4

#include <stdio.h>

int birthdayCakeCandles(int* candles, int n) {
    int max_height = candles[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (candles[i] > max_height) {
            max_height = candles[i];
            count = 1;
        } else if (candles[i] == max_height) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int candles[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &candles[i]);
    }

    int result = birthdayCakeCandles(candles, n);

    printf("%d\n", result);

    return 0;
}


### Problem 5

#include <stdio.h>
#include <string.h>

void timeConversion(char* s, char* military_time) {
    int hh, mm, ss;
    char meridiem[3];

    sscanf(s, "%d:%d:%d%s", &hh, &mm, &ss, meridiem);

    if (strcmp(meridiem, "PM") == 0 && hh != 12) {
        hh += 12;
    } else if (strcmp(meridiem, "AM") == 0 && hh == 12) {
        hh = 0;
    }

    sprintf(military_time, "%02d:%02d:%02d", hh, mm, ss);
}

int main() {
    char time_12_hour[11];
    char military_time[9];

    scanf("%s", time_12_hour);

    timeConversion(time_12_hour, military_time);

    printf("%s\n", military_time);

    return 0;
}


---


## Codeforces

### Problem 1

#include <stdio.h>
#include <math.h>

int main() {
    int n, m, a;
    scanf("%d %d %d", &n, &m, &a);
    
    int stones = ceil((double)n / a) * ceil((double)m / a);
    printf("%d\n", stones);
    
    return 0;
}


### Problem 2

#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        char word[101];
        scanf("%s", word);
        
        int len = strlen(word);
        
        if (len > 10) {
            printf("%c%d%c\n", word[0], len - 2, word[len - 1]);
        } else {
            printf("%s\n", word);
        }
    }
    
    return 0;
}


### Problem 3

#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int scores[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
    }
    
    int thresholdScore = scores[k - 1];
    int participantsAdvanced = 0;
    
    for (int i = 0; i < n; i++) {
        if (scores[i] >= thresholdScore && scores[i] > 0) {
            participantsAdvanced++;
        }
    }
    
    printf("%d\n", participantsAdvanced);
    
    return 0;
}


### Problem 4

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int x = 0;
    
    for (int i = 0; i < n; i++) {
        char statement[4];
        scanf("%s", statement);
        
        if (strstr(statement, "++")) {
            x++;
        } else {
            x--;
        }
    }
    
    printf("%d\n", x);
    
    return 0;
}


### Problem 5

#include <stdio.h>
#include <stdbool.h>

int main() {
    char situ[101];
    scanf("%s", situ);
    
    int adjacentCount = 1;
    char prevPlayer = situ[0];
    bool isDangerous = false;
    
    for (int i = 1; situ[i] != '\0'; i++) {
        if (situ[i] == prevPlayer) {
            adjacentCount++;
            if (adjacentCount >= 7) {
                isDangerous = true;
                break;
            }
        } else {
            adjacentCount = 1;
            prevPlayer = situ[i];
        }
    }
    
    if (isDangerous) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
