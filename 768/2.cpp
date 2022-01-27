#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int T, n, c;
int a[200005];

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
		for (int i = 1; i <= n; ++i) {
			a[i] = read();
		}
		c = 0;
		for (int i = n - 1; i >= 1; --i) {
			if (a[i] != a[i + 1]) {
				++c;
				i -= (n - i - 1);
				if (i >= 1) a[i] = a[n];
			}
		}
		printf("%d\n", c);
	}
}
