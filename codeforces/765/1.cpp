#include <iostream>
#include <cstdio>

using namespace std;

int T, n, m, c, t1, t0;
int a[105];

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
		m = read();
		for (int i = 1; i <= n; ++i) {
			a[i] = read();
		}
		c = 0;
		for (int i = 0; i < m; ++i) {
			t1 = t0 = 0;
			for (int j = 1; j <= n; ++j) {
				if ((1 << i) & a[j]) ++t1;
				else ++t0;
			}
			if (t1 > t0) c += (1 << i);
		}
		printf("%d\n", c);
	}
}
