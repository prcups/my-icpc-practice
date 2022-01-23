#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int T, a, b, c;

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
		c = read();
		if (b == a) {
			printf("%s\n", a == 1 ? "NO" : "YES");
			continue;
		}
		if ((b - a + 1) % 2) {
			if (a % 2) {
				printf("%s\n", (b - a + 1) / 2 + 1 > c ? "NO" : "YES");
				continue;
			} else {
				printf("%s\n", (b - a + 1) / 2 > c ? "NO" : "YES");
				continue;
			}
		} else {
			printf("%s\n", (b - a + 1) / 2 > c ? "NO" : "YES");
			continue;
		}
	}
}
