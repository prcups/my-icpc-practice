#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, a[500005];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int t = 0, c = 0;
    for (int i = 1; i <= n && t < m; ++i) {
        for (; t != a[i]; ++t) {
            if (c % (t + 1)) {
                printf("No");
                return 0;
            }
            c = c / (t + 1);
        }
        ++c;
    }
    for (; t < m; ++t) {
        if (c % (t + 1)) {
            printf("No");
            return 0;
        }
        c = c / (t + 1);
    }
    printf("Yes");
}
