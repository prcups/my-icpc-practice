#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int T, n, m;
struct mem{
	int s, t;
}a[105];

bool cmp(const mem & a, const mem & b) {
	return a.s < b.s;
}

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
			a[i].s = read();
		}
		for (int i = 1; i <= n; ++i) {
			a[i].t = read();
		}
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; ++i) {
			if (a[i].s <= m){
				m += a[i].t;
			} else break;
		}
		printf("%d\n", m);
	}
}
