// TODO: Fix bugs
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

#define reg register
#ifndef ONLINE_JUDGE
#pragma GCC optimize(2)
#endif

const int MAXN = 1e5 + 10, MAXLOG = 25;
int n, m, f[MAXN][MAXLOG];

inline int read(void);
void rmq_init(void);
inline int query(const int l, const int r);

int main(void) {
    rmq_init();
    while (m--) {
        reg int l = read(), r = read();
        printf("%d\n", query(min(l, r), max(l, r)));
    }
    return 0;
}

inline int read(void) {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void rmq_init(void) {
    n = read(); m = read();
    for (reg int i = 1; i <= n; i++)
        scanf("%d", &f[i][0]);
    for (int j = 1; j <= MAXLOG; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}

inline int query(const int l, const int r) {
    const int k = log2(r - l + 1);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}
