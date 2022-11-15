#include <iostream>
#include <map>
#include <cstring>

using namespace std;

long long read() {
    long long s = 0, w = 1;
    char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') w = -w, ch = getchar();
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

long long T, n, a[200005], b[200005], mx, ans;
map <long long, int> p;

int main() {
    T = read();
    while (T--) {
        mx = ans = 0;
        n = read();
        bool f = 0;
        for (int i = 1; i <= n; ++i) {
            a[i] = read();
            b[i] = b[i - 1] + a[i];
            if (a[i] == 0) {
                ans += mx;
                mx = 1;
                p.clear();
                p[b[i]] = 1;
                f = 1;
            } else if (f == 1){
                if (!p.count(b[i])) p[b[i]] = 0;
                ++p[b[i]];
                if (p[b[i]] > mx) mx = p[b[i]];
            } else if (b[i] == 0) ++mx;
        }
        ans += mx;
        printf("%lld\n", ans);
    }
}
