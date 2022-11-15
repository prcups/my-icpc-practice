#include <iostream>

using namespace std;

int read() {
    int s = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s;
}

int T, n;

int main() {
    T = read();
    while (T--) {
        n = read();
        if (n % 2) n = n / 2 + 1;
        else n /= 2;
        printf("%d\n", n);
    }
    return 0;
}
