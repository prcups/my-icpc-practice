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
		for (int i = 1; i <= n; ++i) {
			s[i] = getchar();
		}
		if (n == 1) {
			for (int j = 1; j <= n; ++j) {
				putchar(s[j]);
			}
			for (int j = n; j >= 1; --j) {
				putchar(s[j]);
			}
			putchar('\n');
			continue;
		}
		for (int i = 2; i <= n; ++i) {
			if (s[i - 1] < s[i]) {
				for (int j = 1; j < i; ++j) {
					putchar(s[j]);
				}
				for (int j = i - 1; j >= 1; --j) {
					putchar(s[j]);
				}
				putchar('\n');
				break;
			} else if (s[i - 1] == s[i]) {
				f = 0;
				for (int j = 1; j < i; ++j) {
					if (s[i - j] < s[i + j - 1]) {
						for (int k = 1; k < i; ++k) {
							putchar(s[k]);
						}
						for (int k = i - 1; k >= 1; --k) {
							putchar(s[k]);
						}
						putchar('\n');
						f = 1;
						break;
					} else if (s[i - j] > s[i + j - 1]) {
						break;
					}
					if (j == i - 1) {
						for (int k = 1; k < i; ++k) {
							putchar(s[k]);
						}
						for (int k = i - 1; k >= 1; --k) {
							putchar(s[k]);
						}
						putchar('\n');
						f = 1;
						break;
					}
				}
				if (f == 1) break;
			}
			if (i == n) {
				for (int j = 1; j <= n; ++j) {
					putchar(s[j]);
				}
				for (int j = n; j >= 1; --j) {
					putchar(s[j]);
				}
				putchar('\n');
			}
		}
	}
	return 0;
}
