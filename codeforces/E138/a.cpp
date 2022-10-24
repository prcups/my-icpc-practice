#include <iostream>

int T, n, m, t;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; ++i) {
            scanf("%d %d", &t, &t);
        }
        if (n == m) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
}
