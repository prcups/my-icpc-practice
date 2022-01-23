#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int T, n, l, len, maxn;
int a[200005], b[200005], c[200005], d[200005], m[200005];

inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') w = -w, ch = getchar();
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

inline void getMEX(int pt) {
	l = 0;
	memset(c, 0, sizeof(c));
	for (; pt <= n; ++pt) {
		if (l != a[pt]) {
			b[pt] = l;
			c[a[pt]] = 1;
		} else {
			c[a[pt]] = 1;
			++l;
			for (;c[l] != 0; ++l);
			b[pt] = l;
		}
		if (b[pt] > m[pt]) break;
	}
}

int main() {
	T = read();
	while (T--) {
		n = read();
		len = 0;
		memset(m, 0, sizeof(m));
		memset(b, 0, sizeof(b));
		for (int i = 1; i <= n; ++i) {
			a[i] = read();
		}
		for (int i = n; i >= 1; --i) {
			m[i] = max(m[i + 1], a[i]);
		}
		int pt = 1;
		while (pt <= n) {
			getMEX(pt);
			maxn = -1;
			for (int i = pt; i <= n; ++i) {
				if (b[i] > maxn) {
					maxn = b[i];
					pt = i;
				}
			}
			d[++len] = b[pt++];
		}
		printf("%d\n", len);
		for (int i = 1; i <= len; ++i) {
			printf("%d ", d[i]);
		}
		putchar('\n');
	}
}
