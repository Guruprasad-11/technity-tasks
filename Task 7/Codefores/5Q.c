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
