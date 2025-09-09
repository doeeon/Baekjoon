#include <stdio.h>

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int ans = 1;
    while (n1 != n2) {
        if (n2 <= 0) {
            printf("-1");
            return 0;
        }
        if (n2 % 10 == 1) {
            n2 /= 10;
        }
        else if (n2 % 2 == 0) {
            n2 /= 2;
        }
        else {
            printf("-1");
            return 0;
        }
        ans++;
    }
    printf("%d", ans);
    return 0;
}