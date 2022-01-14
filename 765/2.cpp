#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int T, n, t, ans;
int c[150005];

int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') w = -w, ch = getchar();
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

inline int calc(int l, int pt) {
	return min(pt * 2 > l ? pt * 2 - 1: pt * 2, (l - pt + 1) * 2 - 1);

}

int main() {
	T = read();
	while (T--) {
		ans = -1;
		memset(c, 0, sizeof(c));
		n = read();
		for (int i = 1; i <= n; ++i) {
			t = read();
			if (c[t]) {
				int d = calc(n, i);
				ans = max(ans, min(c[t], d));
				c[t] = max(c[t], d);
			} else {
				c[t] = calc(n, i);
			}
		}
		printf("%d\n", ans);
	}
}
