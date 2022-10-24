#include <iostream>

using namespace std;

int T, n, a[100005];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        getchar();
        for (int i = 1; i <= n; ++i) {
            a[i] = getchar() - '0';
        }
        int pt = 1;
        for (; pt <= n && a[pt] == 0; ++pt);
        int c = 0;
        for (++pt; pt <= n; ++pt) {
            if (a[pt] != a[pt - 1]) ++c;
        }
        printf("%d\n", c);
    }
}
