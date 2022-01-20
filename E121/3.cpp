#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int T, n, c, len, lt;
int k[105], h[105], t[105];

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
		lt = 0;
		len = 0;
		n = read();
		for (int i = 1; i <= n; ++i) {
			k[i] = read();
		}
		for (int i = 1; i <= n; ++i) {
			h[i] = read();
		}
		t[++len] = h[n];
		lt = n;
		for (int i = n - 1; i >= 1; --i) {
			if (t[len] - k[lt] + k[i] <= 0) {
				t[++len] = h[i];
				lt = i;
			} else if (t[len] - k[lt] + k[i] < h[i]) {
				t[len] = h[i] + k[lt] - k[i];
			}
		}
		c = 0;
		for (int i = 1; i <= len; ++i) {
			c += (1 + t[i]) * t[i] / 2;
		}
		printf("%d\n", c);
	}
}
