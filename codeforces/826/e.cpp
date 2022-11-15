#include <iostream>
#include <cstring>

using namespace std;

int T, n, a[200005];
bool dp[200005];

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        if (n < 2) {
            printf("NO\n");
            continue;
        }

        dp[0] = 1;
        if (a[1] + 1 <= n) dp[a[1] + 1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (dp[i] == 0 && i - a[i] - 1 >= 0) dp[i] = dp[i - a[i] - 1];
            if (dp[i] == 1 && i != n && i + a[i + 1] + 1 <= n) dp[i + a[i + 1] + 1] = 1;
        }
        if (dp[n] == 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
