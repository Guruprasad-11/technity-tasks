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
