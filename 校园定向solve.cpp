//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//struct Edge {
//	int u, v;
//	int w1, w2;
//};
//int dfs(int u, int fa, vector<vector<int>>& g, vector<bool>& vis) {
//	int ans = 1;
//	vis[u] = 1;
//	for (auto v : g[u]) {
//		if (v != fa) {
//			ans += dfs(v, u, g, vis);
//		}
//	}
//	return ans;
//}
//void solve(int n, vector<Edge>a) {
//	vector<vector<int>>g(n + 1);
//	vector<bool>vis(n + 1, false);
//	int mx = -1;
//	for (auto v : a) {
//		mx = max(v.w1 + v.w2, mx);
//	}
//	for (auto v : a) {
//		if (v.w1 + v.w2 != mx) {
//			g[v.u].push_back(v.v);
//			g[v.v].push_back(v.u);
//		}
//	}
//	int ans = n * n;
//	for (int i = 1; i <= n; i++) {
//		if (!vis[i]) {
//			int tmp = dfs(i, 0, g, vis);
//			ans -= tmp * tmp;
//		}
//	}
//	cout << ans << endl;
//}
//signed main() {
//	int n;
//	cin >> n;
//	vector<Edge>edg;
//	for (int i = 1,u,v,w1,w2; i < n; i++) {
//		cin >> u >> v >> w1 >> w2;
//		edg.push_back({ u,v,w1,w2 });
//	}
//	solve(n, edg);
//}