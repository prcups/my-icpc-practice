#include <iostream>
#include <algorithm>

using namespace std;

int a[200005], b[200005];
int n, c;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        b[a[i]] = i;
    }
    if (a[2] != 2 && a[a[2]] == 2) {
        c += min(a[2], 2);
        a[a[2]] = a[2];
        a[2] = 2;
    }
    cout << c;
   
    while (1) {
        if (b[1] == 1) {
            bool f = 0;
            for (int i = n; i > 1; --i) {
                if (a[i] != i) {
                    a[1] = a[i];
                    b[a[i]] = 1;
                    a[i] = 1;
                    b[1] = i;
                    c += 1;
                    f = 1;
                    break;
                }
            }
            if (f == 0) break;
        } else {
            c += 1;
            int pt = b[1], tgt = b[b[1]];
            a[pt] = pt;
            b[pt] = pt;
            a[tgt] = 1;
            b[1] = tgt;
        }
    }
    printf("%d\n", c);
}
