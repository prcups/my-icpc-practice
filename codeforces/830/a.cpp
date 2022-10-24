#include <iostream>

using namespace std;

int T, n, a[25];

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int ans;

void calc(int x, int c, int t) {
    if (t == 1) {
        ans = min(ans, c);
        return;
    }
    int tmp = gcd(gcd(x, a[x]), t);
    calc(x - 1, c + n - x + 1, tmp);
    if (tmp != 1) calc(x - 1, c, t);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int t;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            if (i == 1) t = a[i];
            else t = gcd(t, a[i]);
        }
        ans = 0x7fffffff;
        calc(n, 0, t);
        printf("%d\n", ans);
    }
}
