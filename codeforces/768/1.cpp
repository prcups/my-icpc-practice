#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int T, n, ma, mb;
int a[105], b[105];

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
		ma = mb = 0;
		for (int i = 1; i <= n; ++i) {
			a[i] = read();
		}
		for (int i = 1; i <= n; ++i) {
			b[i] = read();
			if (a[i] < b[i]) swap(a[i], b[i]);
			if (a[i] > ma) ma = a[i];
			if (b[i] > mb) mb = b[i];
		}
		printf("%d\n", ma * mb);
	}
}
