#include <iostream>
#include <cstring>
using namespace std;

long long T, n, m, k;
long long t, a[100005], c[100005], cc, ccl, f;

int main() {
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld %lld %lld", &n, &m, &k);
        for (long long i = 1; i <= k; ++i) {
            scanf("%lld", &a[i]);
        }
        memset(c, 0, sizeof(c));
        t = k;
        cc = 0;
        ccl = n * m - 4;
        f = 0;
        for (long long i = 1; i <= k; ++i) {
            if (a[i] == t) {
                --t;
                while (c[t]) {
                    c[t] = 0;
                    --t;
                    --cc;
                }
            } else {
                c[a[i]] = 1;
                ++cc;
                if (cc > ccl) {
                    f = 1;
                    break;
                }
            }
        }
        if (f == 1) {
            printf("TIDAK\n");
        } else {
            printf("YA\n");
        }
    }
}
