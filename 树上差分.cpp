//Max Flow P
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 50010;
//int pwr;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN];
//int st[MAXN][16];
//int di[MAXN];
//int dep[MAXN];
//int cnt = 1;
//int log2(int x){
//	int ans = 0;
//	while ((1 << ans) <= (x >> 1)) {
//		ans++;
//	}
//	return ans;
//}
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//void dfs(int i, int fa) {
//	dep[i] = dep[fa] + 1;
//	st[i][0] = fa;
//	for (int p = 1;p<=pwr; p++) {
//		st[i][p] = st[st[i][p - 1]][p - 1];
//	}
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		dfs(to[ui], i);
//	}
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
//	if (u == v)return u;
//	for (int p = pwr; p >= 0; p--) {
//		if (st[u][p] != st[v][p]) {
//			u = st[u][p];
//			v = st[v][p];
//		}
//	}
//	return st[u][0];
//}
//void dfs1(int i, int fa) {
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		dfs1(to[ui], i);
//	}
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		di[i] += di[to[ui]];
//	}
//}
//int main() {
//	int n, k;
//	cin >> n >> k;
//	pwr = log2(n);
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs(1, 0);
//	for (int i = 1,u,v; i <= k; i++) {
//		cin >> u >> v;
//		di[u]++;
//		di[v]++;
//		int uv = lca(u, v);
//		di[uv]--;
//		di[st[uv][0]]--;
//	}
//	dfs1(1, 0);
//	int ans = di[1];
//	for (int i = 1; i <= n; i++) {
//		if (di[i] > ans) {
//			ans = di[i];
//		}
//	}
//	cout << ans << endl;
//}


//松鼠的新家
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 3e5+10;
//int pwr;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN];
//int st[MAXN][19];
//int dep[MAXN];
//int cnt = 1;
//int a[MAXN];
//int di[MAXN];
//int log2(int x){
//	int ans = 0;
//	while ((1 << ans) <= (x >> 1)) {
//		ans++;
//	}
//	return ans;
//}
//void addEdge(int u, int v) {
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
//	for (int ui = head[i]; ui != 0; ui = nex[ui]){
//		if (to[ui] != fa)dfs(to[ui], i);
//	}
//}
//void dfs2(int i, int fa) {
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		dfs2(to[ui], i);
//	}
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		di[i] += di[to[ui]];
//	}
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
//	if (u == v)return u;
//	for (int p = pwr; p >= 0; p--) {
//		if (st[u][p] != st[v][p]) {
//			u = st[u][p];
//			v = st[v][p];
//		}
//	}
//	return st[u][0];
//}
//int main() {
//	int n;
//	cin >> n ;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	pwr = log2(n);
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs(1, 0);
//	for (int i = 2; i <= n; i++) {
//		int u = a[i - 1];
//		int v = a[i];
//		int uv = lca(u, v);
//		di[u]++;
//		di[v]++;
//		di[uv]--;
//		di[st[uv][0]]--;
//	}
//	dfs2(1, 0);
//	for (int i = 1; i <= n; i++) {
//		if (i != a[1])cout << di[i]-1 << endl;
//		else {
//			cout << di[i] << endl;
//		}
//	}
//}


//最小化旅行总价格
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 60;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN];
//int di[MAXN];
//int dep[MAXN];
//int st[MAXN][6];
//int cnt = 1;
//void dfs(int i, int fa) {
//	dep[i] = dep[fa] + 1;
//	st[i][0] = fa;
//	for (int p = 1; p <= 5; p++) {
//		st[i][p] = st[st[i][p - 1]][p - 1];
//	}
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] != fa) {
//			dfs(to[ui], i);
//		}
//	}
//}
//int lca(int u, int v) {
//	if (dep[u] < dep[v]) {
//		int t = u;
//		u = v;
//		v = t;
//	}
//	for (int p = 5; p >= 0; p--) {
//		if (dep[st[u][p]] >= dep[v]) {
//			u = st[u][p];
//		}
//	}
//	if (u == v)return u;
//	for (int p = 5; p >= 0; p--) {
//		if (st[u][p] != st[v][p]) {
//			u = st[u][p];
//			v = st[v][p];
//		}
//	}
//	return st[u][0];
//}
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//void add(int u, int v) {
//	int uv = lca(u, v);
//	di[u]++;
//	di[v]++;
//	di[uv]--;
//	di[st[uv][0]]--;
//};
//void dfs2(int i, int fa) {
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		dfs2(to[ui], i);
//	}
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		di[i] += di[to[ui]];
//	}
//}
//struct info {
//	int y, n;
//	info(int y, int n) {
//		this->y = y;
//		this->n = n;
//	}
//};
//int f(int i, int ok, int fa, vector<int>& pro) {
//	int ans = 0;
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		ans += f(to[ui], 1, i, pro);
//	}
//	if (!ok)return ans;
//	int ans1 = pro[i];
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		ans1 += f(to[ui], 0, i, pro);
//	}
//	return max(ans, ans1);
//}
//class Solution {
//public:
//	int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
//		memset(head, 0, sizeof(head));
//		memset(di, 0, sizeof(di));
//		cnt = 1;
//		price.insert(price.begin(), 0);
//		for (auto v : edges) {
//			addEdge(v[0] + 1, v[1] + 1);
//			addEdge(v[1] + 1, v[0] + 1);
//		}
//		dfs(1, 0);
//		for (auto v : trips) {
//			add(v[0] + 1, v[1] + 1);
//		}
//		dfs2(1, 0);
//		vector<int>pro(n + 5);
//		// for(int i=1;i<=n;i++){
//		//     cout<<price[i]<<" "<<di[i]<<endl;
//		// }
//		int sum = 0;
//		for (int i = 1; i <= n; i++) {
//			sum += price[i] * di[i];
//			pro[i] = price[i] / 2 * di[i];
//		}
//		// for(int i=1;i<=n;i++){
//		//     cout<<pro[i]<<endl;
//		// }
//		return sum - f(1, 1, 0, pro);
//	}
//};


//边差分
//被卡常
//可能必须要用tarjan吧
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 3e5 + 10;
//int n, m;
//int log2(int x) {
//	int ans = 0;
//	while ((1 << ans) <= (x >> 1)) {
//		ans++;
//	}
//	return ans;
//}
//int pwr;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int weight[MAXN << 1];
//int powe[MAXN];
//int wefa[MAXN];
//int dep[MAXN];
//int st[MAXN][17];
//int disTo1[MAXN];
//int stval[MAXN][17];
//int head[MAXN << 1];
//int cnt = 1;
//vector<vector<int>>plan;
//void dfs(int u, int fa, int we,int d) {
//	wefa[u] = we;
//	dep[u] = dep[fa] + 1;
//	st[u][0] = fa;
//	stval[u][0] = we;
//	disTo1[u] = d;
//	for (int p = 1; p <= pwr; p++) {
//		st[u][p] = st[st[u][p - 1]][p - 1];
//		stval[u][p] = stval[u][p - 1] + stval[st[u][p - 1]][p - 1];
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa)continue;
//		dfs(to[e], u, weight[e],d+weight[e]);
//	}
//}
//inline int lca(int u, int v) {
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
//	if (u == v)return u;
//	for (int p = pwr; p >= 0; p--) {
//		if (st[u][p] != st[v][p]) {
//			u = st[u][p];
//			v = st[v][p];
//		}
//	}
//	return st[u][0];
//}
//bool dfs2(int u, int fa, int num, int weneed) {
//	bool ans = 0;
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa)continue;
//		ans |= dfs2(to[e], u, num, weneed);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa)continue;
//		powe[u] += powe[to[e]];
//	}
//	if (powe[u] >= num && wefa[u] >= weneed)
//		ans = true;
//	return ans;
//}
//inline void add(int u, int v,int uv) {
//	powe[u]++;
//	powe[v]++;
//	powe[uv] -= 2;
//}
//inline bool f(int m) {
//	if (m >= plan.back()[2])return 1;
//	memset(powe, 0, sizeof(powe));
//	int pos;
//	for (pos = plan.size() - 1; pos >= 0 && plan[pos][2] > m; pos--) {
//		add(plan[pos][0], plan[pos][1],plan[pos][3]);
//	}
//	//if (startPos == pos+1)cout << "equal\n";
//	return dfs2(1, 0, plan.size() - pos - 1, plan.back()[2] - m);
//}
//inline void addEdge(int u, int v, int w) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	weight[cnt] = w;
//	head[u] = cnt++;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n >> m;
//	pwr = log2(n);
//	for (int i = 1, u, v, w; i < n; i++) {
//		cin >> u >> v >> w;
//		addEdge(u, v, w);
//		addEdge(v, u, w);
//	}
//	dfs(1, 0, 0,0);
//
//
//	/*for (int p = 0; p <= pwr; p++) {
//		for (int i = 1; i <= n; i++) {
//			cout << stval[i][p] << " ";
//		}
//		cout << endl;
//	}*/
//
//
//	for (int i = 1, u, v; i <= m; i++) {
//		cin >> u >> v;
//		int ou=u, ov=v;
//		int uv = lca(u, v);
//		plan.push_back({ ou,ov ,disTo1[u]+disTo1[v]-2*disTo1[uv] ,uv});
//	}
//	sort(plan.begin(), plan.end(), [](vector<int>& a, vector<int>& b) {
//		return a[2] < b[2];
//		});
//
//
//	//for (int i = 0; i < plan.size(); i++) {
//	//	cout <<plan[i][0]<<" "<<plan[i][1]<<" "<<plan[i][2] << "* \n";
//	//}
//	//cout << endl;
//
//
//	int l = 0, r = plan.back()[2], ans = 0;
//
//
//	//cout << l << " and " << r << endl;
//
//
//	while (l <= r) {
//		int m = (l + r) >> 1;
//		if (f(m)) {
//			//cout << m << " is ok \n";
//			ans = m;
//			r = m - 1;
//		}
//		else {
//			//cout << m << " is not ok \n";
//			l = m + 1;
//		}
//	}
//	cout << ans << endl;
//}