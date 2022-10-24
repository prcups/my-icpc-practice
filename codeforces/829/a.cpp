#include <iostream>

using namespace std;

int T, n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        getchar();
        int c = 0;
        char t;
        for (int i = 1; i <= n; ++i) {
            t = getchar();
            if (t == 'Q') {
                ++c;
            } else {
                if (c != 0) --c;
            }
        }
        if (c != 0) printf("No\n");
        else printf("Yes\n");
    }
}
