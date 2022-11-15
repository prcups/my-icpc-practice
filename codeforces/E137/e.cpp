#include <iostream>

using namespace std;

long long p1, t1, p2, t2, h, s;
long long f[15005];

int main() {
    scanf("%lld %lld %lld %lld %lld %lld", &p1, &t1, &p2, &t2, &h, &s);
    for (long long i = 1; i <= h; ++i) {
        f[i] = 1e18;
    }
    for (long long i = 1; i <= h; ++i) {
        f[i] = min(f[max(0ll, i - (p1 - s))] + t1, f[max(0ll, i - (p2 - s))] + t2);
        for (long long j = 1; j <= i / min(p1 - s, p2 - s); ++j) {
            if (j * t1 >= t2) {
                f[i] = min(f[i], f[max(0ll, i - (j - 1)*(p1 - s) - (t1 * j - t2 ) / t2 * (p2 - s) - (p1 + p2 - s))] + t1 * j);
            }
            if (j * t2 >= t1) {
                f[i] = min(f[i], f[max(0ll, i - (j - 1)*(p2 - s) - (t2 * j - t1 ) / t1 * (p1 - s) - (p1 + p2 - s))] + t2 * j);
            }
        }
    }
    printf("%lld\n", f[h]);
}
