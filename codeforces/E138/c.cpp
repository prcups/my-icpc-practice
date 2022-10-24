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
        int l = 1, r = n, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int t = 0;
            for (int i = 1; i <= n; ++i) {
                if (a[i] <= i && a[i] <= mid) ++t;
            }
            if (t / 2 + (t % 2) >= mid) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
}
