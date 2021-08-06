// TODO: Fix bugs
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

#define reg register

const int MAXN = 5e4 + 10, MAXLOG = 20;
int n, q, maxf[MAXN][MAXLOG], minf[MAXN][MAXLOG];

inline const int read(void);
void init();
int query(const int l, const int r);

int main(void) {
    init();
    while (q--) {
        reg int l = read(), r = read();
        l = min(l, r); r = max(l, r);
        printf("%d\n", query(l, r));
    }
    return 0;
}

inline const int read(void) {
    reg int x = 0, f = 1; char ch = getchar();
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

void init() {
    n = read(); q = read();
    for (reg int i = 1; i <= n; i++)
        minf[i][0] = maxf[i][0] = read();
    for (reg int j = 1; j <= MAXLOG; j++)
        for (reg int i = 1; i + (1 << j) - 1 <= n; i++) {
            minf[i][j] = min(minf[i][j - 1], minf[i + (1 << j)][j - 1]);
            maxf[i][j] = max(maxf[i][j - 1], maxf[i + (1 << j)][j - 1]);
        }
}

int query(const int l, const int r) {
    const reg int k = log2(r - l + 1);
    const reg int maxval = max(maxf[l][k], maxf[r - (1 << k) + 1][k]),  \
                  minval = min(minf[l][k], minf[r - (1 << k) + 1][k]);
    return maxval - minval;
}
