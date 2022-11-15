#include <iostream>

using namespace std;

long long T, n;

int main() {
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &n);
        long long l, r, tl = 0, tr = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld %lld", &l, &r);
            if (l < r) swap(l, r);
            if (l > tl) tl = l;
            tr += r;
        }
        printf("%lld\n", 2 * (tl + tr));
    }
}
