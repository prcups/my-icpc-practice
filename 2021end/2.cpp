#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int T, n, f;
char s[100005];

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
		scanf("%s", s + 1);
		if (s[1] == s[2]) {
			printf("%c%c\n", s[1], s[2]);
			continue;
		}
		f = 0;
		for (int i = 1; i <= n; ++i) {
			if (s[i] < s[i + 1]) {
				f = 1;
				for (int j = 1; j <= i; ++j) {
					putchar(s[j]);
				}
				for (int j = i; j >= 1; --j) {
					putchar(s[j]);
				}
				putchar('\n');
				break;
			}
		}
		if (f == 0) {
			for (int j = 1; j <= n; ++j) {
				putchar(s[j]);
			}
			for (int j = n; j >= 1; --j) {
				putchar(s[j]);
			}
			putchar('\n');
		}
	}
	return 0;
}
