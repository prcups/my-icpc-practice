#include <iostream>
#include <cstring>

using namespace std;

int n;
int a[1000005], b[1000005], t[1000005];

int main() {
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; ++i) {
        a[i] = getchar() - '0';
    }

    int s;
    for (s = 1; s <= n; ++s) {
        if (a[s] == 1) break;
    }
    if (s > n) {
        putchar('0');
        return 0;
    }

    int l;
    for (l = s; l <= n; ++l) {
        if (a[l] == 0) break;
    }

    if (l > n) {
        for (int i = s; i <= n; ++i) {
            putchar('1');
        }
        return 0;
    }

    for (int i = s; i <= l; ++i) {
        for (int j = l; j <= n; ++j) {
            t[j] = (a[i + j - l] | a[j]);
        }
        bool f = 0;
        for (int j = l; j <= n; ++j) {
            if (b[j] > t[j]) break;
            if (b[j] < t[j]) {
                f = 1;
                break;
            }
        }
        if (f) {
            for (int j = l; j <= n; ++j) {
                b[j] = t[j];
            }
        }
    }

    for (int i = s; i < l; ++i) {
        printf("%d", a[i]);
    }
    for (int i = l; i <= n; ++i) {
        printf("%d", b[i]);
    }
}
