#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int T, a, b, len;
int c[100005];

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
		a = read();
		b = read();
		len = 0;
		for (int i = 1; i <= a; ++i) {
			for (int j = 1; j <= b; ++j) {
				c[++len] = max(i - 1, a - i) + max(j - 1, b - j);
			}
		}
		sort(c + 1, c + len + 1);
		for (int i = 1; i <= len; ++i) {
			printf("%d ", c[i]);
		}
		printf("\n");
	}
}
