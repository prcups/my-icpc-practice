#include <stdio.h>

int read() {
    int s = 0, w = 1;
    char ch = getchar();
    if (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') w = -w, ch = getchar();
    if (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}


int read_no_negative() {
    int s = 0;
    char ch = getchar();
    if (ch < '0' || ch > '9') ch = getchar();
    if (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s;
}
