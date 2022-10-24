#include <iostream>

using namespace std;

int T, n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n == 2) {
            printf("1 2\n");
        } else if (n == 3) {
            printf("1 2 3\n");
        } else if (n % 2) {
            int t = n / 2;
            for (int i = t + 1; i >= 2; --i) {
                printf("%d %d ", i, i + t);
            }
            printf("1\n");
        } else {
            int t = n / 2;
            for (int i = t; i >= 1; --i) {
                printf("%d %d ", i, i + t);
            }
            printf("\n");
        }
    }
}
