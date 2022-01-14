#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int T, n, t, f;
int a[55];

int main() {
	cin >> T;
	while (T--) {
		memset(a, 0, sizeof(a));
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> t;
			while (t) {
				if (t <= 50) {
					if (a[t] == 50)
					a[t] = 1;
				}
				t /= 2;
			}
		}
		f = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] == 0) {
				cout << "NO\n";
				f = 1;
				break;
			}
		}
		if (f == 0) {
			cout << "YES\n";
		}
	}
}
