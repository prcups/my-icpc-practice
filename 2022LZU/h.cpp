#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

multiset <int> a, b;

int read() {
    int s = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s;
}

struct node {
    int l, r;
}c[200005];

int n;

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        c[i].l = read();
        c[i].r = read();
        a.insert(c[i].l);
    }
    sort(c + 1, c + n + 1, [](const node & a, const node & b){
        return a.r < b.r;
    });

    for (int i = 1; i <= n; ++i) {
        int ans = 0;
        ans += (b.size() - (count_if(b.begin(), b.end(), c[i].l) - b.begin()));
        ans += upper_bound(a.begin(), a.end(), c[i].r) - a.begin();
        a.erase(find(a.begin(), a.end(), c[i].l));
        b.insert(c[i].r);
        printf("%d ", ans);
    }

}
