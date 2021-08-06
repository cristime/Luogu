// 修改码风
#include <bits/stdc++.h>
#define reg register
#ifndef ONLINE_JUDGE
#pragma GCC optimize(2)
#endif
using namespace std;
const int MAXN = 5e5 + 10;
int n, m, root, ans, f[MAXN][21], deep[MAXN];
vector<int> g[MAXN];
inline int read() {
	reg int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void dfs(int u, int fa) {
	deep[u] = deep[fa] + 1;
	f[u][0] = fa;
	for (reg int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == fa) continue;
		dfs(v, u);
	}
}
int query(int u, int v) {
	if (deep[u] < deep[v]) swap(u, v);
	for (reg int i = 20; i >= 0; i--)
		if (deep[u] - deep[v] >= (1 << i))
			u = f[u][i];
	if (u == v) return u;
	for (reg int i = 20; i >= 0; i--)
		if (f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}
signed main(void) {
	n = read(), m = read(), root = read();
	for (int i = 1; i < n; i++) {
		reg int u = read(), v = read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(root, 0);
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
			f[i][j] = f[f[i][j - 1]][j - 1];
	while (m--) {
		reg int u = read(), v = read();
		printf("%d\n", query(u, v));
	}
	return 0;
}