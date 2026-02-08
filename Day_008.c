#include <stdio.h>

long long power(int a, int b) {
    if (b == 0) return 1;
    return (long long)a * power(a, b - 1);
}

int main() {
    int a, b;
    printf("Enter base and exponent: ");
    scanf("%d %d", &a, &b);
    printf("%lld", power(a, b));
    return 0;
}
