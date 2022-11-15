#include <iostream>

using namespace std;

int T, n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n % 2) printf("3\n");
        else printf("2\n");
    }
}
