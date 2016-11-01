/*
*@author:cmershen
*@description:基于邻接表的匈牙利算法，求二分图最大匹配数
*/

#include <cstdio>
#include <cstring>
#include <vector>
using std::vector;
vector<int> e[1000];
int N, M, f[1000], u, v, cnt = 0;
bool vis[1000];
bool dfs(int i) {
	vis[i] = 1;
	for (int j = 0; j < (int) e[i].size(); ++j)
		if (f[e[i][j]] == -1 || (!vis[f[e[i][j]]] && dfs(f[e[i][j]]))) {
			f[e[i][j]] = i;
			f[i] = e[i][j];
			return 1;
		}
	return 0;
}
int main() {
	scanf("%d%d", &N, &M);
	memset(f, -1, sizeof(f));
	while (M--) {
		scanf("%d%d", &u, &v);
		--u, --v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 0; i < N; ++i)
		if (f[i] == -1) {
			memset(vis, 0, sizeof(vis));
			cnt += dfs(i);
		}
	printf("%d\n", cnt);
	return 0;
}
