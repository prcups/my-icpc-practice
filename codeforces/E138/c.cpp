#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int T, n, a[105];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        int l = 1, r = n / 2 + (n % 2), ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            bool f = 0;
            for (int i = mid * 2 - 1, t = mid; t >= 1; --i, --t) {
                if (a[i] > t) {
                    f = 1;
                    break;
                }
            }
            if (!f) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
}
