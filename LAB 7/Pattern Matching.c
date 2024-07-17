#include <stdio.h>
#include <string.h>

// Function to find the index of the first occurrence of the pattern in the text
int substringMatch(char text[], char pattern[]) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patternLength) {
            return i; // Pattern found at index i
        }
    }
    return -1; // Pattern not found
}

int main() {
    char text[100], pattern[100];

    printf("Enter the main text: ");
    scanf("%s", text);

    printf("Enter the pattern to search: ");
    scanf("%s", pattern);

    int index = substringMatch(text, pattern);
    if (index != -1) {
        printf("Substring found at index: %d\n", index);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
