#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int T, n, len;
int head[100005], vis[100005], f[100005];
struct node {
	int t, nt, v;
} e[200005];

int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') w = -w, ch = getchar();
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

void dfs(int pt, int v) {
	for (int i = head[pt]; i; i = e[i].nt) {
		if (!vis[e[i].t]) {
			vis[e[i].t] = 1;
			e[i].v = e[i % 2 ? i + 1 : i - 1].v = v;
			dfs(e[i].t, 5 - v);
		}
	}
}

int main() {
	T = read();
	while (T--) {
		len = 0;
		memset(head, 0, sizeof(head));
		memset(e, 0, sizeof(e));
		memset(vis, 0, sizeof(vis));
		memset(f, 0, sizeof(f));
		n = read();
		int u, v;
		for (int i = 1; i < n; ++i) {
			u = read();
			v = read();
			++f[u];
			++f[v];
			e[++len].t = v;
			e[len].nt = head[u];
			head[u] = len;
			e[++len].t = u;
			e[len].nt = head[v];
			head[v] = len;
		}
		int flag = 0, s = 0;
		for (int i = 1; i <= n; ++i) {
			if (f[i] > 2) {
				printf("-1\n");
				flag = 1;
				break;
			} else if (f[i] == 1) s = i;
		}
		if (flag == 1) continue;
		vis[s] = 1;
		dfs(s, 2);
		for (int i = 1; i < n; ++i) {
			printf("%d ", e[i * 2].v);
		}
		printf("\n");
	}
}
