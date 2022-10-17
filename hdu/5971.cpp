#include <iostream>
#include <cstring>

using namespace std;

int read() {
    int s = 0;
    char ch = getchar();
    if (ch < '0' || ch > '9') ch = getchar();
    if (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s;
}

int n, m, x, y;

struct {
    int t, nt;
}e[20005];

int head[1005], len, v[1005], f;

void dfs(int x) {
    int t = (v[x] == 1 ? 2 : 1);
    for (int i = head[x]; i; i = e[i].nt) {
        if (v[e[i].t]) {
            if (v[e[i].t] != t) {
                f = 0;
                return;
            }
        } else {
            v[e[i].t] = t;
            dfs(e[i].t);
        }
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        m = read();
        x = read();
        y = read();
        if (x == 0 && y == 0) {
            printf("NO\n");
            continue;
        }
        len = 0;
        memset(head, 0, sizeof(head));
        memset(e, 0, sizeof(e));
        int s, t;
        for (int i = 1; i <= m; ++i) {
            s = read();
            t = read();
            e[++len].t = t;
            e[len].nt = head[s];
            head[s] = len;
            e[++len].t = s;
            e[len].nt = head[t];
            head[t] = len;
        }
        for (int i = 1; i <= x; ++i) {
            s = read();
            v[s] = 1;
        }
        for (int i = 1; i <= y; ++i) {
            t = read();
            v[t] = 2;
        }
        f = 1;
        for (int i = 1; i <= n; ++i) {
            if (v[i] != 0) {
                dfs(i);
                if (f == 0) {
                    printf("NO\n");
                    continue;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (v[i] == 0) {
                printf("NO\n");
                continue;
            }
        }
        printf("YES\n");
        continue;
    }
}
