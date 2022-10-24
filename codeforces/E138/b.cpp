#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

long long T, n, a[200005], b[200005];

int main() {
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &n);
        long long mx = 0, pt, ans = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            ans += a[i];
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &b[i]);
            if (b[i] > mx) mx = b[i], pt = i;
        }
        for (int i = 1; i <= n; ++i) {
            if (i != pt) ans += b[i];
        }
        printf("%lld\n", ans);
    }
}
