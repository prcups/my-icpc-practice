#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int T, n, t, ans;
struct node{
	int t, v;
} c[150005];

int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') w = -w, ch = getchar();
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

bool cmp(const node & a, const node & b) {
	return (a.v < b.v) || (a.v == b.v && a.t < b.t);
}

int main() {
	T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= n; ++i) {
			c[i].t = i;
			c[i].v = read();
		}
		sort(c + 1, c + n + 1, cmp);
		int ans = -1;
		for (int i = 1; i < n; ++i) {
			if (c[i].v == c[i + 1].v) {
				ans = max(ans, n - c[i + 1].t + c[i].t);
			}
		}
		printf("%d\n", ans);
	}
}
