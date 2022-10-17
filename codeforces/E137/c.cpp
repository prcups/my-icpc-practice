#include <iostream>

using namespace std;

long long T, n;

long long a[200005], b[200005], c[200005];

int main() {
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &n);
        getchar();
        for (int i = 1; i <= n; ++i) {
            b[i] = getchar() - '0';
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            c[i] = c[i - 1] + a[i];
        }
        long long ans = 0;
        long long l = 0;

        int i;
        for (i = 1; i <= n; ++i) {
            if (b[i] == 0) break;
            ans += a[i];
        }
        if (i > n) {
            printf("%lld\n", ans);
            continue;
        }
        for (; i <= n; ++i) {
            if (!b[i]) {
                l = 0;
                continue;
            }
            if (l == 0) l = i;
            if (c[i] - c[l - 1] <= c[i - 1] - c[l - 2]) {
                b[l - 1] = 1;
                b[i] = 0;
                ans += a[l - 1];
                l = 0;
            } else {
                ans += a[i];
            }
        }
        printf("%lld\n", ans);
    }
}
