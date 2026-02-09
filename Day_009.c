#include <stdio.h>
#include <string.h>

void rev(char str[100]) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    char temp;
    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }

    printf("Reversed string: %s\n", str);
}

int main() {
    char arr[100];
    printf("Enter a string: ");
    fgets(arr, sizeof(arr), stdin);

    printf("You entered: %s", arr);
    rev(arr);

    return 0;
}
