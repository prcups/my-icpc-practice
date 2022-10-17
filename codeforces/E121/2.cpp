#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int T, n, m;
char s[200005];

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
		scanf("%s", s);
		n = strlen(s);
		m = -1;
		int f = 0, t;
		for (int i = n - 1; i > 0; --i) {
			t = s[i] - '0' + s[i - 1] - '0';
			if (t >= 10) {
				s[i - 1] = t / 10 + '0';
				s[i] = t % 10 + '0';
				printf("%s\n", s);
				f = 1;
				break;
			}
		}
		if (f) continue;
		else {
			s[1] += s[0] - '0';
			printf("%s\n", s + 1);
		}
	}
}
