#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int T, n, a[105];

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
	int t, c;
	while (T--) {
		memset(a, 0, sizeof(a));
		n = read();
		while (n--) {
			t = read();
			++a[abs(t)];
		}
		c = 0;
		if (a[0] > 0) ++c;
		for (int i = 1; i <= 100; ++i) {
			if (a[i] == 1) ++c;
			else if (a[i] > 1) c += 2;
		}
		printf("%d\n", c);
	}
}
