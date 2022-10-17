#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int T, n, k, fk;
int a[100005];

int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') w = -w, ch = getchar();
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

int main() {
	T = read();
	while (T--) {
		n = read();
		k = read();
		if (n == 4 && k == 3) {
			printf("-1\n");
			continue;
		}
		if (k == n - 1) {
			memset(a, 0, sizeof(a));
			printf("%d %d\n", 1, n - 1);
			a[1] = a[n - 1] = 1;
			for (int pt = 0; (1 << pt) < n; ++pt) {
				printf("%d %d\n", n - 1 - (1 << pt), (1 << (pt + 1)) % n);
				a[n - 1 - (1 << pt)] = a[(1 << (pt + 1)) % n] = 1;
			}
			for (int i = 0; i < n; ++i) {
				if (a[i] == 0) {
					printf("%d %d\n", i, n - i - 1);
					a[i] = a[n - i - 1] = 1;
				}
			}
			continue;
		}
		fk = n - k - 1;
		printf("%d %d\n", k, n - 1);
		if (k != 0) printf("%d %d\n", fk, 0);
		for (int i = 1; i < n / 2; ++i) {
			 if (i != k && i != fk) printf("%d %d\n", i, n - i - 1);
		}
	}
}
