#include <iostream>
using namespace std;

int T, n, a, b, t;

int main() {
	cin >> T;
	while (T--) {
		a = -1000000005, b = 1000000005;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> t;
			if (t > a) a = t;
			if (t < b) b = t;
		}
		cout << a - b << endl;
	}
}
