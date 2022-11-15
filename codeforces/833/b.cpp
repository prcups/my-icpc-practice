#include <iostream>

using namespace std;

int read() {
    int s = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s;
}

int T, n, a[100005];

int main() {
    T = read();
    while (T--) {
        n = read();
        for (int i = 1; i <= n; ++i) {
            a[i] = getchar() - '0';
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int c = 0, t[10] = {0}, mt = 0, l = min(n, i + 105);
            for (int j = i; j <= l; ++j) {
                if (t[a[j]] == 0) ++c;
                ++t[a[j]];
                if (t[a[j]] > mt) mt = t[a[j]];
                if (mt <= c) ++ans;
            }
        }
        printf("%d\n", ans);
    }

}
