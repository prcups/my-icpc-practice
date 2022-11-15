#include <iostream>
#include <algorithm>

using namespace std;

int T, n;
int a[200005];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        int mx = 0;
        for (int i = 1; i <= n; ++i) {
            if (i >= 3 && mx < a[i] - a[i - 1] + a[i] - a[1]) mx = a[i] - a[i - 1] + a[i] - a[1];
            if (i <= n - 2 && mx < a[i + 1] - a[i] + a[n] - a[i]) mx = a[i + 1] - a[i] + a[n] - a[i];
        }
        printf("%d\n", mx);
    }
}
