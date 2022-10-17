#include <iostream>

using namespace std;

int T, n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1, j = 1, k = n; i <= n; ++i) {
            if (i % 2) {
                printf("%d ", j);
                ++j;
            }
            else {
                printf("%d ", k);
                --k;
            }
        }
        printf("\n");
    }
}
