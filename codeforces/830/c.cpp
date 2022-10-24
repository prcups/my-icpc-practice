#include <iostream>

using namespace std;

long long read() {
    long long s = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s;
}

long long T, n, m, a[100005], b[100005], c[100005];

int main() {
    T = read();
    while (T--) {
        n = read();
        m = read();
        for (int i = 1; i <= n; ++i) {
            a[i] = read();
            b[i] = b[i - 1] + a[i];
            c[i] = (c[i - 1] ^ a[i]);
        }
        long long l, r;
        l = read();
        r = read();
        long long ans = -1e12, t, s1 = l, s2 = r;
        for (int i = l; i <= r; ++i) {
            for (int j = i; j <= r; ++j) {
                t = (b[j] - b[i - 1]) - (c[j] ^ c[i - 1]);
                if (t > ans) {
                    ans = t;
                    s1 = i;
                    s2 = j;
                } else if (t == ans && j - i < s2 - s1) {
                    s1 = i;
                    s2 = j;
                }
            }
        }
        printf("%lld %lld\n", s1, s2);
    }
}
