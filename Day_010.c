#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--;
    }

    int left = 0;
    int right = len - 1;
    int isPalindrome = 1;

    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        printf("%s is a palindrome", s);
    else
        printf("%s is not a palindrome", s);

    return 0;
}