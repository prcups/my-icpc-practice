#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

int T, n, l, len, maxn, pt;
int a[200005], d[200005], m[200005], c[200005];

inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') w = -w, ch = getchar();
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

inline int getMEX() {
	int ans = 0;
	l = 0;
	memset(c, 0, sizeof(c));
	int p = pt;
	for (; pt <= n; ++pt) {
		c[a[pt]] = 1;
		if (l == a[pt]) {
			for (;c[l] != 0; ++l);
		}
		ans = l;
		if (ans == m[p]) {
			++pt;
			break;
		}
	}
	return ans;
}

int main() {
	T = read();
	while (T--) {
		n = read();
		len = 0;
		memset(m, 0, sizeof(m));
		for (int i = 1; i <= n; ++i) {
			a[i] = read();
		}
		l = 0;
		memset(c, 0, sizeof(c));
		for (int i = n; i >= 1; --i) {
			c[a[i]] = 1;
			if (l == a[i]) {
				for (;c[l] != 0; ++l);
			}
			m[i] = l;
		}
		pt = 1;
		while (pt <= n) {
			maxn = getMEX();
			d[++len] = maxn;
		}
		printf("%d\n", len);
		for (int i = 1; i <= len; ++i) {
			printf("%d ", d[i]);
		}
		putchar('\n');
	}
}
