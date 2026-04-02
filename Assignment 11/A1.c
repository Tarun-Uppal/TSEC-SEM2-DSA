#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

void printFactorials(int current, int n) {
    if (current > n)
        return;
    printf("%d! = %d\n", current, factorial(current));

    printFactorials(current + 1, n);
}

void main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printFactorials(1, n);
}
