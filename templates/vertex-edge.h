 
struct node {
    int t, nt ,s, v;
}a[xxx];

int head[xxx], len;

void addEdge(int s, int t) {

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
}
