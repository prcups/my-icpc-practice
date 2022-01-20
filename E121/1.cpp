#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int n, m;
char s[1005][65];
int t[150];

int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') w = -w, ch = getchar();
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

int main() {
	n = read();
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i]);
		m = strlen(s[i]);
		for (int j = 0; j < m; ++j) {
			++t[int(s[i][j])];
		}
		for (char j = 'a'; j <= 'z'; ++j) {
			while (t[j]) {
				putchar(j);
				--t[j];
			}
		}
		putchar('\n');
	}
}
