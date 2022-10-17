#include <iostream>

using namespace std;

int T;
int a[15][15];

int main() {
    for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) a[i][j] = 1;
            else a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }


    scanf("%d", &T);
    int n, t;
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &t);
        printf("%d\n", a[10 - n][2] * 6);
    }
    return 0;
}
