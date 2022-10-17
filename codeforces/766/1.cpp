#include <iostream>
#include <cstdio>

using namespace std;

int T, n, m, x, y;
char a[55][55];

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
		x = read();
		y = read();
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				a[i][j] = getchar();
			}
			getchar();
		}
		if (a[x][y] == 'B') {
			printf("0\n");
		} else {
			int flag = 0;
			for (int i = 1; i <= n; ++i) {
				if (a[i][y] == 'B') {
					flag = 1;
				}
			}
			for (int j = 1; j <= m; ++j) {
				if (a[x][j] == 'B') {
					flag = 1;
				}
			}
			if (flag == 1) {
				printf("1\n");
			} else {
				int flag = 0;
				for (int i = 1; i <= n; ++i) {
					for (int j = 1; j <= m; ++j) {
						if (a[i][j] == 'B') flag = 1;
					}
				}
				if (flag == 1) {
					printf("2\n");
				} else {
					printf("-1\n");
				}
			}
		}
	}
}
