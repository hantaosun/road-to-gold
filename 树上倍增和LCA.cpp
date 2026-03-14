//树节点的第K个祖先
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 5 * 1e4 + 10;
//int st[MAXN][20];
//int log2(int x) {
//    int ans = 0;
//    while ((1 << ans) <= (x >> 1)) {
//        ans++;
//    }
//    return ans;
//}
//class TreeAncestor {
//public:
//    TreeAncestor(int n, vector<int>& parent) {
//        for (int i = 0; i < parent.size(); i++) {
//            st[i][0] = parent[i];
//        }
//        for (int p = 1; p <= log2(n); p++) {
//            st[0][p] = -1;
//        }
//        for (int p = 1; p <= log2(n); p++) {
//            for (int i = 1; i <= n; i++) {
//                if (st[i][p - 1] == -1) {
//                    st[i][p] = -1;
//                }
//                else {
//                    st[i][p] = st[st[i][p - 1]][p - 1];
//                }
//            }
//        }
//    }
//
//    int getKthAncestor(int node, int k) {
//        int cur = node;
//        for (int i = log2(k); i >= 0; i--) {
//            if (k > (1 << i)) {
//                cur = st[cur][i];
//                k -= (1 << i);
//            }
//            if (cur == -1)return -1;
//        }
//        return st[cur][0];
//    }
//};


//最近公共祖先LCA
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 5e5 + 10;
//int st[MAXN][20];
//int nex[MAXN<<1];
//int to[MAXN << 1];
//int head[MAXN];
//int dep[MAXN];
//int cnt = 1;
//void addEdge(int v, int u) {
//	nex[cnt] = head[v];
//	to[cnt] = u;
//	head[v] = cnt++;
//}
//void dfs(int i, int fa,int level) {
//	st[i][0] = fa;
//	dep[i] = level;
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		dfs(to[ui], i,level+1);
//	}
//}
//int log2(int x) {
//	int ans = 0;
//	while ((1 << ans) <= (x >> 1)) {
//		ans++;
//	}
//	return ans;
//}
//int jump(int v, int k) {
//	int cur = v;
//	for (int i = log2(k); i >= 0; i--) {
//		if (k>= (1<<i)) {
//			cur = st[cur][i];
//			k -= (1 << i);
//		}
//	}
//	return cur;
//}
//int query(int u, int v) {
//	if (dep[u] < dep[v]) {
//		u = u ^ v;
//		v = u ^ v;
//		u = u ^ v;
//	}
//	u = jump(u, dep[u] - dep[v]);
//	if (u == v) {
//		return v;
//	}
//	for (int i = log2(dep[u]); i >= 0; i--) {
//		if (st[v][i] != st[u][i]) {
//			v = st[v][i];
//			u = st[u][i];
//		}
//	}
//	return st[u][0];
//}
//
//int main() {
//	int n, m, s;
//	cin >> n >> m >> s;
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		if (u == v)continue;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs(s, s,0);
//	for (int p = 1; p <= log2(n); p++) {
//		for (int i = 1; i <=n ; i++) {
//			st[i][p] = st[st[i][p - 1]][p - 1];
//		}
//	}
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		cout << query(u, v)<<endl;
//	}
//}
//精简版
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 5*1e5 + 10;
//int power;
//int st[MAXN][20];
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN];
//int dep[MAXN];
//int cnt = 1;
//void addEdge(int v, int u) {
//	nex[cnt] = head[v];
//	to[cnt] = u;
//	head[v] = cnt++;
//}
//void dfs(int i, int fa) {
//	st[i][0] = fa;
//	dep[i] = dep[fa] + 1;
//	for (int p = 1; p <= power; p++) {
//		st[i][p] = st[st[i][p - 1]][p - 1];
//	}
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		dfs(to[ui], i);
//	}
//}
//int log2(int x) {
//	int ans = 0;
//	while ((1 << ans) <= (x >> 1)) {
//		ans++;
//	}
//	return ans;
//}
//int lca(int u, int v) {
//	if (dep[u] < dep[v]) {
//		u = u ^ v;
//		v = u ^ v;
//		u = u ^ v;
//	}
//	for (int i = power; i >= 0; i--) {
//		if (dep[st[u][i]] >= dep[v]) {
//			u = st[u][i];
//		}
//	}
//	if (u == v) {
//		return v;
//	}
//	for (int i = power; i >= 0; i--) {
//		if (st[v][i] != st[u][i]) {
//			v = st[v][i];
//			u = st[u][i];
//		}
//	}
//	return st[u][0];
//}
//
//int main() {
//	int n, m, s;
//	cin >> n >> m >> s;
//	power = log2(n);
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		if (u == v)continue;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dep[s] = 0;
//	dfs(s, s);
//	for (int i = 1, u, v; i <= m; i++) {
//		cin >> u >> v;
//		cout << lca(u, v) << endl;
//	}
//}


//tarjan算法解决lca
//#include<bits/stdc++.h>
//using namespace std;
//int n, m, s;
//vector<vector<pair<int,int>>>task;
//vector<int>visi;
//vector<int>ans;
//const int MAXN = 5 * 1e5 + 10;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN];
//int cnt = 1;
//int fa[MAXN];
//int find(int x) {
//	if (fa[x] != x) {
//		fa[x] = find(fa[x]);
//	}
//	return fa[x];
//}
//void addEdge(int v, int u) {
//	nex[cnt] = head[v];
//	to[cnt] = u;
//	head[v] = cnt++;
//}
//void dfs(int i, int pa) {
//	for (auto j : task[i]) {
//		if (visi[j.first]) {
//			ans[j.second] = find(j.first);
//		}
//	}
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == pa)continue;
//		dfs(to[ui], i);
//		fa[to[ui]] = i;
//	}
//}
//int main() {
//	cin >> n >> m >> s;
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//	}
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		if (u == v)continue;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	task.resize(n + 1);
//	visi.resize(n + 1, 1);
//	ans.resize(m + 1);
//	for (int i = 1, u, v; i <= m; i++) {
//		cin >> u >> v;
//		task[u].push_back(make_pair(v,i));
//		task[v].push_back(make_pair(u,i));
//	}
//	dfs(s, s);
//	for (int i = 1; i <= m; i++) {
//		cout << ans[i] << endl;
//	}
//}


//紧急集合
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 5 * 1e5 + 10;
//int head[MAXN];
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int cnt = 1;
//int pwr;
//int dep[MAXN];
//int st[MAXN << 1][20];
//void addEdge(int u,int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//void dfs(int i, int fa) {
//	dep[i] = dep[fa] + 1;
//	st[i][0] = fa;
//	for (int p = 1; p <= pwr; p++) {
//		st[i][p] = st[st[i][p - 1]][p - 1];
//	}
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa) {
//			continue;
//		}
//		dfs(to[ui], i);
//	}	
//}
//int log2(int x) {
//	int ans = 0;
//	while ((1 << ans) <= (x >> 1)) {
//		ans++;
//	}
//	return ans;
//}
//int lca(int u, int v) {
//	if (dep[u] < dep[v]) {
//		int t = u;
//		u = v;
//		v = t;
//	}
//	for (int p = pwr; p >= 0; p--) {
//		if (dep[st[u][p]] >= dep[v]) {
//			u = st[u][p];
//		}
//	}
//	if (u == v)return v;
//	for (int p = pwr; p >= 0; p--) {
//		if (st[u][p] != st[v][p]) {
//			u = st[u][p];
//			v = st[v][p];
//		}
//	}
//	return st[u][0];
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	pwr = log2(n);
//	dep[1] = 0;
//	dfs(1, 1);
//	for (int i = 1,x,y,z; i <= m; i++) {
//		cin >> x >> y >> z;
//		int xz = lca(x, z);
//		int yz = lca(y, z);
//		int xy = lca(x, y);
//		// 选择深度最大的LCA作为集合点
//		int p = xy;
//		if (dep[xz] > dep[p]) p = xz;
//		if (dep[yz] > dep[p]) p = yz;
//		// 通用花费公式
//		int cost = dep[x] + dep[y] + dep[z] - dep[xy] - dep[xz] - dep[yz];
//		cout << p << " " << cost << endl;
//	}
//}


//货车运输
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1e4 + 10;
//const int MAXM = 5 * 1e4 + 10;
//vector<vector<int>>edge;
//vector<vector<vector<int>>>g;
//int n, m, q;
//int pwr;
//int fa[MAXN];
//int stlca[MAXN][15];
//int stmin[MAXN][15];//当前节点往上走1<<p步中最小边的权值
//int dep[MAXN];
//int find(int x) {
//	if (fa[x] != x) {
//		fa[x] = find(fa[x]);
//	}
//	return fa[x];
//}
//bool isSameSet(int a, int b) {
//	return find(a) == find(b);
//}
//void Union(int a, int b) {
//	fa[find(a)] = fa[find(b)];
//}
//void dfs(int i, int fa, int path) {
//	stlca[i][0] = fa;
//	stmin[i][0] = path;//往上走一步即其父节点到其路径权值
//	dep[i] = dep[fa] + 1;
//	for (int p = 1; p <= pwr; p++) {
//		stlca[i][p] = stlca[stlca[i][p - 1]][p - 1];
//		stmin[i][p] = min(stmin[i][p - 1], stmin[stlca[i][p - 1]][p - 1]);
//	}
//	for (auto to : g[i]) {
//		if (to[0] == fa)continue;
//		dfs(to[0], i, to[1]);
//	}
//}
//int lca(int u, int v) {
//	if (dep[u] < dep[v]) {
//		int t = u;
//		u = v;
//		v = t;
//	}
//	for (int p = pwr; p >= 0; p--) {
//		if (dep[stlca[u][p]] >= dep[v]) {
//			u = stlca[u][p];
//		}
//	}
//	if (u == v) {
//		return u;
//	}
//	for (int p = pwr; p >= 0; p--) {
//		if (stlca[u][p] != stlca[v][p]) {
//			u = stlca[u][p];
//			v = stlca[v][p];
//		}
//	}
//	return stlca[u][0];
//}
//int log2(int x) {
//	int ans = 0;
//	while ((1 << ans) <= (x >> 1)) {
//		ans++;
//	}
//	return ans;
//}
//int main() {
//	cin >> n >> m;
//	pwr = log2(n);
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//	}
//	for (int i = 1, u, v, w; i <= m; i++) {
//		cin >> u >> v >> w;
//		edge.push_back({ u,v,w });
//	}
//	sort(edge.begin(), edge.end(), [](vector<int>& a, vector<int>& b) {
//		return a[2] > b[2];
//		});
//	g.resize(n + 1);
//	for (int i = 0; i < edge.size(); i++) {
//		//cout << edge[i][0] << " " << edge[i][1] << " ee" << endl;
//		if (!isSameSet(edge[i][0], edge[i][1])) {//仅保留各联通分块中形成最大生成树的边
//			Union(edge[i][0], edge[i][1]);
//			g[edge[i][0]].push_back({ edge[i][1],edge[i][2] });
//			g[edge[i][1]].push_back({ edge[i][0],edge[i][2] });
//		}
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	cout << i << " : ";
//	//	for (int j = 0; j < g[i].size(); j++) {
//	//		cout << "(" << g[i][j][0] << " " << g[i][j][1] << ") ";
//	//	}
//	//	cout << endl;
//	//}
//	for (int i = 1; i <= n; i++) {//每个联通分块以其代表节点为根跑dfs为lca做准备
//		if (fa[i] == i) {
//			dep[i] = 0;
//			dfs(i, i, INT_MAX);
//		}
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	cout << fa[i] << " ";
//	//}
//	//cout << "fa[i]" << endl;
//	//cout << "-----------" << endl;
//	//for (int p = 0; p <= pwr; p++) {
//	//	for (int i = 0; i <= n; i++) {
//	//		cout << stmin[i][p] << " ";
//	//	}
//	//	cout << endl;
//	//}
//	//cout << "-----------" << endl;
//	//for (int p = 0; p <= pwr; p++) {
//	//	for (int i = 0; i <= n; i++) {
//	//		cout << stlca[i][p] << " ";
//	//	}
//	//	cout << endl;
//	//}
//	cin >> q;
//	for (int i = 1, u, v; i <= q; i++) {
//		cin >> u >> v;
//		if (!isSameSet(u, v))cout << -1 << endl;//不在同一连通分块
//		else {
//			int uv = lca(u, v);
//			//cout << uv <<" lca for u v"<< endl;
//			int stepU = log2(dep[u] - dep[uv]);
//			int stepV = log2(dep[v] - dep[uv]);
//			int minU = INT_MAX, minV = INT_MAX;
//			for (int p = stepU; p >= 0; p--) {
//				if (dep[stlca[u][p]] >= dep[uv]) {
//					minU = min(minU, stmin[u][p]);
//					u = stlca[u][p];
//				}
//			}
//			for (int p = stepV; p >= 0; p--) {
//				if (dep[stlca[v][p]] >= dep[uv]) {
//					minV = min(minV, stmin[v][p]);
//					v = stlca[v][p];
//				}
//			}
//			cout << min(minU, minV) << endl;
//		}
//	}
//}
//自制测试案例
//10 8
//1 2 4
//2 4 6
//2 3 5
//4 5 2
//4 6 8
//7 8 8
//8 10 1
//7 9 4
//100
 

//边权重均等查询
//做法不好应统计到根节点每个权重数量再进行差分
//#include<bits/stdc++.h>
//using namespace std;
//vector<vector<vector<int>>>g;
//const int MAXN = 1e4 + 10;
//int pwr;
//int stlca[MAXN][14];
//int stcnt[MAXN][14][27];
//int dep[MAXN];
//int log2(int x) {
//	int ans = 0;
//	while ((1 << ans) <= (x >> 1)) {
//		ans++;
//	}
//	return ans;
//}
//void dfs(int i, int fa, int w) {
//	dep[i] = dep[fa] + 1;
//	stlca[i][0] = fa;
//	stcnt[i][0][w] = 1;
//	for (int p = 1; p <= pwr; p++) {
//		stlca[i][p] = stlca[stlca[i][p - 1]][p - 1];
//		for (int j = 1; j <= 26; j++) {
//			stcnt[i][p][j] = stcnt[i][p - 1][j] + stcnt[stlca[i][p - 1]][p - 1][j];
//		}
//	}
//	for (auto v : g[i]) {
//		if (v[0] != fa) {
//			dfs(v[0], i, v[1]);
//		}
//	}
//}
//int lca(int u, int v) {
//	if (dep[u] < dep[v]) {
//		int t = u;
//		u = v;
//		v = t;
//	}
//	for (int p = pwr; p >= 0; p--) {
//		if (dep[stlca[u][p]] >= dep[v]) {
//			u = stlca[u][p];
//		}
//	}
//	if (u == v)return u;
//	for (int p = pwr; p >= 0; p--) {
//		if (stlca[u][p] != stlca[v][p]) {
//			u = stlca[u][p];
//			v = stlca[v][p];
//		}
//	}
//	return stlca[u][0];
//}
//int cnt[27];
//class Solution {
//public:
//	vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
//		g.assign(n + 1, vector<vector<int>>());
//		for (int i = 0; i < n; i++) {
//			dep[i] = 0;
//			for (int p = 0; p < 14; p++) {
//				stlca[i][p] = 0;
//				for (int w = 0; w < 27; w++) {
//					stcnt[i][p][w] = 0;
//				}
//			}
//		}
//		pwr = log2(n);
//		for (auto v : edges) {
//			g[v[0]].push_back({ v[1], v[2] });
//			g[v[1]].push_back({ v[0], v[2] });
//		}
//		dfs(0, 0, 0);
//		vector<int>ans(queries.size());
//		for (int i = 0; i < queries.size(); i++) {
//			auto q = queries[i];
//			for (int i = 1; i <= 26; i++) {
//				cnt[i] = 0;
//			}
//			int u = q[0], v = q[1];
//			int uv = lca(u, v);
//			int stepU = log2(dep[u] - dep[uv]);
//			int stepV = log2(dep[v] - dep[uv]);
//			ans[i] = dep[u] + dep[v] - 2 * dep[uv];
//			for (int p = stepU; p >= 0; p--) {
//				if (dep[stlca[u][p]] >= dep[uv]) {
//					for (int i = 1; i <= 26; i++) {
//						cnt[i] += stcnt[u][p][i];
//					}
//					u = stlca[u][p];
//				}
//			}
//			for (int p = stepV; p >= 0; p--) {
//				if (dep[stlca[v][p]] >= dep[uv]) {
//					for (int i = 1; i <= 26; i++) {
//						cnt[i] += stcnt[v][p][i];
//					}
//					v = stlca[v][p];
//				}
//			}
//			int MAX = 0;
//			for (int i = 1; i <= 26; i++) {
//				MAX = max(MAX, cnt[i]);
//			}
//			ans[i]-=MAX;
//		}
//		return ans;
//	}
//};


//在传球游戏中最大化函数值
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const ll MAXN = 1e5 + 10;
//const ll LIMIT = 40;
//ll pwr, n;
//ll log2(ll x) {
//    ll ans = 0;
//    while ((1ll << ans) <= (x >> 1)) {
//        ans++;
//    }
//    return ans;
//}
//ll stfa[MAXN][LIMIT];
//ll stsum[MAXN][LIMIT];
//class Solution {
//public:
//    long long getMaxFunctionValue(vector<int>& rec, long long k) {
//        n = rec.size();
//        for (int i = 0; i < rec.size(); i++) {
//            stfa[i][0] = rec[i];
//            stsum[i][0] = rec[i];
//        }
//        pwr = log2(k);
//        for (int p = 1; p <= pwr; p++) {
//            for (int i = 0; i < n; i++) {
//                stfa[i][p] = stfa[stfa[i][p - 1]][p - 1];
//                stsum[i][p] = stsum[i][p - 1] + stsum[stfa[i][p - 1]][p - 1];
//            }
//        }
//        ll MAX = LLONG_MIN;
//        for (int i = 0; i < n; i++) {
//            ll s = i;
//            ll t = k;
//            ll cur = i;
//            for (int p = pwr; p >= 0; p--) {
//                if (t - (1ll << p) >= 0) {
//                    s += stsum[cur][p];
//                    cur = stfa[cur][p];
//                    t -= (1ll << p);
//                }
//            }
//            MAX = max(MAX, s);
//        }
//        return MAX;
//    }
//};