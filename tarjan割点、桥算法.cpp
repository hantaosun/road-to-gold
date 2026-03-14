//注意求割点按道理应该排除父节点干扰,但是由于判断条件是大于等于,其干扰其实并不影响
//tarjan模板
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e4 + 5;
//const int M = 1e5 + 5;
//int head[N];
//int dfn[N];
//int low[N];
//int to[M << 1];
//int nex[M << 1];
//int cntg = 1;
//int cnt = 0;
//bool ap[N];
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//void dfs(int u, bool root) {
//	dfn[u] = low[u] = ++cnt;
//	int son = 0;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		int v = to[ui];
//		if (!dfn[v]) {//尚未访问过
//			dfs(v, false);
//			low[u] = min(low[u], low[v]);
//			//注意根节点不可通过该条件判定是不是割点！
//			if (!root && low[v] >= dfn[u])ap[u] = true;
//			son++;
//		}
//		else {//访问过,说明是返祖边,可能有通往fa的但不影响割点的判定
//			low[u] = min(low[u], dfn[v]);
//		}
//	}
//	if (son >= 2 && root) {
//		ap[u] = true;
//	}
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1, u, v; i <= m; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!dfn[i])dfs(i, true);
//	}
//	int cn = 0;
//	for (int i = 1; i <= n; i++) {
//		if (ap[i])cn++;
//	}
//	cout << cn << '\n';
//	for (int i = 1; i <= n; i++) {
//		if (ap[i])cout << i << " ";
//	}cout << "\n";
//	return 0;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 5;
//const int M = 5e5 + 5;
//int head[N];
//int ans[N];
//bool ap[N];
//int siz[N];
//int dfn[N];
//int low[N];
//int fa[N];
//int to[M<<1];
//int nex[M<<1];
//int cntg = 1;
//int cnt = 0;
//int n, m;
//void addEdge(int u,int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//void tarjan(int u, bool root) {
//	siz[u] = 1;
//	dfn[u] = low[u] = ++cnt;
//	int son = 0;
//	int sum = 0;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		int v = to[ui];
//		if (!dfn[v]) {
//			fa[v] = u;
//			tarjan(v, false);
//			low[u] = min(low[u], low[v]);
//			son++;
//			siz[u] += siz[v];
//			if (low[v] >= dfn[u]) {
//				ans[u] += siz[v] * (n - 1 - siz[v]);
//				sum += siz[v];
//			}
//			if (!root && low[v] >= dfn[u])ap[u] = true;
//		}
//		else if(fa[u]!=v) {
//			low[u] = min(low[u], dfn[v]);
//		}
//	}
//	if (root && son >= 2) {
//		ap[u] = true;
//	}
//	if (!ap[u]) {
//		ans[u] = 2 * n - 2;
//	}
//	else {
//		ans[u] += sum * (n - sum - 1) + 2 * (n - 1);
//	}
//}
//signed main() {
//	cin >> n >> m;
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	tarjan(1, true);
//	for (int i = 1; i <= n; i++) {
//		cout << ans[i] << '\n';
//	}
//}
// 



//tarjan求有向图强连通分量
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e4+5;
//const int M = 1e5 + 5;
//int dfn[N];
//int low[N];
//bool instack[N];
//int belong[N];
//int head[N];
//int to[M];
//int nex[M];
//int sta[N];
//bool vis[N];
//int r = 0;
//int cntg = 1;
//int cnt = 0;
//int cn = 0;
//vector<vector<int>>ans;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//void dfs(int u) {
//	sta[++r] = u;
//	instack[u] = true;
//	dfn[u] = low[u] = ++cnt;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		int v = to[ui];
//		if (!dfn[v]) {
//			dfs(v);
//			low[u] = min(low[u], low[v]);
//		}
//		else if (instack[v]) {
//			low[u] = min(low[u], dfn[v]);
//		}
//	}
//	if (low[u] == dfn[u]) {
//		while (true) {
//			int v = sta[r--];
//			instack[v] = false;
//			ans[cn].push_back(v);
//			belong[v] = cn;
//			if (v == u)break;
//		}
//		cn++;
//	}
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	ans.assign(n + 1, {});
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!dfn[i]) {
//			dfs(i);
//		}
//	}
//	for (int i = 0; i < cn; i++) {
//		sort(ans[i].begin(), ans[i].end());
//	}
//	cout << cn << '\n';
//	for (int i = 1; i <= n; i++) {
//		if (vis[belong[i]])continue;
//		else {
//			vis[belong[i]] = true;
//			for (int j = 0; j < ans[belong[i]].size(); j++) {
//				cout << ans[belong[i]][j] << " ";
//			}cout << '\n';
//		}
//	}
//}




//tarjan求边双连通分量注意faE是走来的边,这样可以处理有重边的情况
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 5e5 + 5;
//const int M = 2e6 + 5;
//int low[N];
//int dfn[N];
//int head[N];
//int nex[M << 1];
//int to[M << 1];
//bool brg[M << 1];
//int cntg=2;
//int cnt = 0;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//void tarjan(int u,int faE) {
//	dfn[u] = low[u] = ++cnt;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		int v = to[ui];
//		if (ui == (faE ^ 1))continue;
//		if (!dfn[v]) {
//			tarjan(v,ui);
//			low[u] = min(low[u], low[v]);
//			if (low[v] > dfn[u]) {
//				brg[ui] = brg[ui ^ 1] = true;
//			}
//		}
//		else {
//			low[u] = min(low[u], dfn[v]);
//		}
//	}
//}
//bool vis[N];
//vector<vector<int>>ans;
//vector<int>tmp;
//void dfs(int u) {
//	tmp.push_back(u);
//	vis[u] = true;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (vis[to[ui]] || brg[ui])continue;
//		dfs(to[ui]);
//	}
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!dfn[i]) {
//			tarjan(i, 0);
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!vis[i]) {
//			tmp.clear();
//			dfs(i);
//			ans.push_back(tmp);
//		}
//	}
//	cout << ans.size() << '\n';
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i].size() << " ";
//		for (auto v : ans[i]) {
//			cout << v << " ";
//		}cout << '\n';
//	}
//}


//点双连通分量
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 5e5 + 5;
//const int M = 2e6 + 5;
//int head[N];
//int nex[M << 1];
//int to[M << 1];
//int cntg = 1;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//int dfn[N];
//int low[N];
//int cnt = 0;
//int sta[N];
//int r = 0;
//vector<vector<int>>ans;
//vector<int>tmp;
//void tarjan(int u,bool root) {
//	sta[++r] = u;
//	dfn[u] = low[u] = ++cnt;
//	int son = 0;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		int v = to[ui];
//		if (!dfn[v]) {
//			tarjan(v,0);
//			low[u] = min(low[u], low[v]);
//			son++;
//			if (low[v] >= dfn[u]) {
//				tmp.clear();
//				int t;
//				do {
//					t = sta[r--];
//					tmp.push_back(t);
//				} while (t!= v);
//				tmp.push_back(u);
//				ans.push_back(tmp);
//			}
//		}
//		else {
//			low[u] = min(low[u], dfn[v]);
//		}
//	}
//	if (root && son == 0) {
//		tmp.clear();
//		tmp.push_back(u);
//		ans.push_back(tmp);
//	}
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		addEdge(u,v);
//		addEdge(v,u);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!dfn[i]) {
//			tarjan(i,true);
//		}
//	}
//	cout << ans.size() << '\n';
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i].size() << ' ';
//		for (auto v : ans[i]) {
//			cout << v << ' ';
//		}cout << '\n';
//	}
//}

//用tarjan直接求边双和求有向图强连通分量并不太一样,要考虑不能回父亲入边了,该题为简单图只考虑不回父亲就行
//#include<bits/stdc++.h>
//using namespace std;
//vector<int>a;
//vector<int>low;
//vector<int>dfn;
//vector<vector<int>>g;
//vector<vector<int>>edcc;
//vector<int>tmp;
//bool insta[200005];
//int sta[200005];
//int p[200005];
//int color[200005];
//int cnt,r;
//const int mod = 998244353;
//void tarjan(int u,int fa) {
//	sta[++r] = u;
//	insta[u] = true;
//	dfn[u] = low[u] = ++cnt;
//	for (auto v : g[u]) {
//		if (v == fa)continue;
//		if (!dfn[v]) {
//			tarjan(v,u);
//			low[u] = min(low[u], low[v]);
//		}
//		else if(insta[v]) {
//			low[u] = min(low[u], dfn[v]);
//		}
//	}
//	if (dfn[u] == low[u]) {
//		tmp.clear();
//		int t;
//		do {
//			t = sta[r--];
//			insta[t] = false;
//			tmp.push_back(t);
//		} while (t!=u);
//		edcc.push_back(tmp);
//	}
//}
//bool check(int u, int c) {//判断图是否为二分图
//	if (!color[u]) {
//		color[u] = c;
//	}
//	else return color[u] == c;
//	for (auto v : g[u]) {
//		if (p[v] != p[u])continue;//不在同一边双跳过
//		if (!check(v, c ^ 1))return false;
//	}
//	return true;
//}
//void solve() {
//	int n, m, V;
//	cin >> n >> m >> V;
//	cnt = 0;
//	r = 0;
//	edcc.clear();
//	memset(insta, 0, sizeof(bool) * (n + 5));
//	memset(p, 0, sizeof(int) * (n + 5));
//	memset(color,0, sizeof(int) * (n + 5));
//	a.assign(n + 1, 0);
//	low.assign(n + 1, 0);
//	dfn.assign(n + 1, 0);
//	g.assign(n + 1, {});
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1, u, v; i <= m; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!dfn[i])tarjan(i,i);
//	}
//	long long ans = 1;
//	for (int i = 0; i < edcc.size();i++) {
//		vector<int>& vec = edcc[i];
//		int x = -1;
//		int t = 0;
//		for (auto v : vec) {
//			p[v] = i+1;
//			if (a[v] == -1)continue;
//			else if (x == -1) {
//				x = a[v];
//			}
//			else if (a[v] != x) {
//				cout << 0 << '\n';
//				return;
//			}
//		}
//		if (check(vec[0], 2)) {//是二分图
//			if (x == -1)ans = ans * V%mod;
//		}
//		else {//有奇环
//			if (x>0) {
//				cout << 0 << '\n';
//				return;
//			}
//		}
//	}
//	cout << ans << '\n';
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}



//tarjan强连通分量缩点
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e4+5;
//const int M = 1e5 + 5;
//int head[N];
//int to[M];
//int nex[M];
//int cntg = 1;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//int a[N];
//int dfn[N];
//int low[N];
//int Bcnt = 0,cnt=0;
//int Bsum[N];
//int sta[N];
//int belong[N];
//bool insta[N];
//int r = 0;
//void tarjan(int u) {
//	sta[++r] = u;
//	dfn[u] = low[u] = ++cnt;
//	insta[u] = true;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		int v = to[ui];
//		if (!dfn[v]) {
//			tarjan(v);
//			low[u] = min(low[u], low[v]);
//		}
//		else if(insta[v]) low[u] = min(low[u], dfn[v]);
//	}
//	if (low[u] == dfn[u]) {
//		int t;
//		Bcnt++;
//		do {
//			t = sta[r--];
//			Bsum[Bcnt] += a[t];
//			insta[t] = false;
//			belong[t] = Bcnt;
//		} while (t != u);
//	}
//
//}
//int dp[N];
//vector<vector<int>>g;
//int dfs(int u) {
//	if (dp[u] != -1)return dp[u];
//	dp[u] = Bsum[u];
//	for (int v:g[u]) {
//		dp[u] = max(dp[u], Bsum[u] + dfs(v));
//	}
//	return dp[u];
//}
//int main() {
//	memset(dp, -1, sizeof(dp));
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!dfn[i])tarjan(i);
//	}
//	g.assign(Bcnt + 1, {});
//	for (int i = 1; i <= n; i++) {
//		for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//			int v = to[ui];
//			if (belong[v] == belong[i])continue;
//			else g[belong[i]].push_back(belong[v]);
//		}
//	}
//	int ans = INT_MIN;
//	for (int i = 1; i <= Bcnt; i++) {
//		if (dp[i] == -1) {
//			dfs(i);
//		}
//		ans = max(ans, dp[i]);
//	}
//	cout << ans << '\n';
//}