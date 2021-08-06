// TODO: Fix bugs
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> Pair;
#define reg register
#define mkpr make_pair

inline int read();
inline bool validpos(const int x, const int y, const int t);
int bfs();

const int MAXN = 3e2 + 10,
          dx[] = { 1, 0, -1, 0 },
          dy[] = { 0, 1, 0, -1 };
int m, g[MAXN][MAXN], time[MAXN][MAXN];
bool vis[MAXN][MAXN];

int main(void) {
    memset(g, -1, sizeof(g));
    scanf("%d", &m);
    for (reg int i = 1; i <= m; i++) {
        reg int x, y, t;
        scanf("%d%d%d", &x, &y, &t);
        g[x][y] = t;
        for (reg int j = 0; j < 4; j++) {
            reg int x1 = x + dx[j], y1 = y + dy[j];
            if (validpos(x1, y1, t)) g[x1][y1] = t;
        }
    }
    printf("%d\n", bfs());
    return 0;
}

inline int read() {
    reg int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

inline bool validpos(const int x, const int y, const int t) {
    return (x > 0) && (y > 0) && (g[x][y] == -1 || g[x][y] > t);
}

int bfs() {
    queue<pair<int, int> > Q;
    vis[0][0] = true;
    Q.push(mkpr(0, 0));
    while (!Q.empty()) {
        reg int x = Q.front().first, y = Q.front().second;
        Q.pop();
        reg int s = time[x][y] + 1;
        if (g[x][y] == -1) return s - 1;
        for (reg int i = 0; i < 4; i++) {
            reg int x1 = x + dx[i], y1 = y + dy[i];
            if (!x1 || !y1 || vis[x1][y1] || s >= (g[x1][y1] == -1 ? INT_MAX : g[x1][y1]))
                continue;
            Q.push(mkpr(x1, y1));
            vis[x1][y1] = true;
            time[x1][y1] = s;
        }
    }
    return -1;
}
