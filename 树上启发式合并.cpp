//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 5;
//
//int head[N];
//int nex[N << 1];
//int to[N << 1];
//int cnt = 1;
//
//int color[N];
//int siz[N];
//int fa[N];//父节点
//int son[N];//重儿子
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//void dfs1(int u,int pa) {//
//	fa[u] = pa;
//	siz[u] = 1;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == pa)continue;
//		dfs1(to[ui], u);
//		if (siz[to[ui]] > siz[son[u]]) {
//			son[u] = to[ui];
//		}
//		siz[u] += siz[to[ui]];
//	}
//}
//
//int ans[N];
//int colorCnt[N];
//int diff = 0;
//void effect(int u) {
//	if (colorCnt[color[u]]++ == 0) {
//		diff++;
//	}
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa[u])continue;
//		effect(to[ui]);
//	}
//}
//void cancel(int u) {
//	if (--colorCnt[color[u]] == 0) {
//		diff--;
//	}
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa[u])continue;
//		cancel(to[ui]);
//	}
//}
//void dfs2(int u,bool keep) {
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == son[u] || to[ui] == fa[u])continue;
//		dfs2(to[ui], false);
//	}
//	if(son[u]!=0)dfs2(son[u], true);
//	if (colorCnt[color[u]]++ == 0) {
//		diff++;
//	}
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa[u] || to[ui] == son[u])continue;
//		effect(to[ui]);
//	}
//	ans[u] = diff;
//	if (!keep) {
//		cancel(u);
//	}
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> color[i];
//	}
//	dfs1(1, 0);
//	dfs2(1, 1);
//	int m;
//	cin >> m;
//	for (int i = 1,u; i <= m; i++) {
//		cin >> u;
//		cout << ans[u] << "\n";
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int color[N];
//int siz[N];
//int head[N];
//int nex[N];
//int to[N];
//int cnt = 1;
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//int fa[N];
//int son[N];
//int colorCnt[N];
//int most = 0;
//int diff = 0;
//int ans = 0;
//void dfs1(int u) {
//	siz[u] = 1;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		dfs1(to[ui]);
//		if (siz[to[ui]] > siz[son[u]]) {
//			son[u] = to[ui];
//		}
//		siz[u] += siz[to[ui]];
//	}
//}
//void effect(int u) {
//	if (colorCnt[color[u]]++==0) {
//		diff++;
//	}
//	most = max(most, colorCnt[color[u]]);
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		effect(to[ui]);
//	}
//}
//void cancel(int u) {
//	if (--colorCnt[color[u]] == 0) {
//		diff--;
//	}
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		cancel(to[ui]);
//	}
//}
//void dfs2(int u,bool keep) {
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == son[u])continue;
//		dfs2(to[ui], false);
//	}
//	if(son[u]!=0)dfs2(son[u], true);
//	if (colorCnt[color[u]]++ == 0) {
//		diff++;
//	}
//	most = max(most, colorCnt[color[u]]);
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == son[u])continue;
//		effect(to[ui]);
//	}
//	if (siz[u] == diff * most)ans++;
//	if (!keep) {
//		most = 0;
//		cancel(u);
//	}
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> color[i] >> fa[i];
//		addEdge(fa[i], i);
//	}
//	dfs1(1);
//	dfs2(1, 1);
//	cout << ans << "\n";
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 5;
//int color[N];
//int head[N];
//int nex[N << 1];
//int to[N << 1];
//int cnt = 1;
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//int colorCnt[N];
//int fa[N];
//int son[N];
//int siz[N];
//int ans[N];
//int mx = 0;
//int sumMax = 0;
//void dfs1(int u, int pa) {
//	fa[u] = pa;
//	siz[u] = 1;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == pa)continue;
//		dfs1(to[ui], u);
//		if (siz[to[ui]] > siz[son[u]]) {
//			son[u] = to[ui];
//		}
//		siz[u] += siz[to[ui]];
//	}
//}
//void effect(int u) {
//	int c = color[u];
//	colorCnt[c]++;
//	if (colorCnt[c] > mx) {
//		sumMax = c;
//		mx = colorCnt[c];
//	}
//	else if (colorCnt[c] == mx) {
//		sumMax += c;
//	}
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa[u])continue;
//		effect(to[ui]);
//	}
//}
//void cancel(int u) {
//	colorCnt[color[u]]--;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa[u])continue;
//		cancel(to[ui]);
//	}
//}
//void dfs2(int u, bool keep) {
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa[u] || to[ui] == son[u])continue;
//		dfs2(to[ui], false);
//	}
//	if(son[u]!=0)dfs2(son[u], true);
//	int c = color[u];
//	colorCnt[c]++;
//	if (colorCnt[c] > mx) {
//		sumMax = c;
//		mx = colorCnt[c];
//	}
//	else if (colorCnt[c] == mx) {
//		sumMax += c;
//	}
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa[u] || to[ui] == son[u])continue;
//		effect(to[ui]);
//	}
//	ans[u] = sumMax;
//	if (!keep) {
//		mx = 0;
//		sumMax = 0;
//		cancel(u);
//	}
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> color[i];
//	}
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs1(1, 0);
//	dfs2(1, 1);
//	for (int i = 1; i <= n; i++) {
//		cout << ans[i] << " ";
//	}
//	cout << "\n";
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 5;
//int cntid = 1;//用于给名字分配id
//int cnt = 1;
//int name[N];
//int fa[N];
//int head[N];
//int nex[N];
//int to[N];
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//int siz[N];
//int son[N];
//int dep[N];
//void dfs1(int u) {
//	dep[u] = dep[fa[u]] + 1;
//	siz[u] = 1;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		dfs1(to[ui]);
//		if (siz[to[ui]] > siz[son[u]]) {
//			son[u] = to[ui];
//		}
//		siz[u] += siz[to[ui]];
//	}
//}
//vector<vector<array<int, 2>>>qry;
//vector<int>ans;
//map<int, set<int>>li;
//void effect(int u) {
//	li[dep[u]].insert(name[u]);
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		effect(to[ui]);
//	}
//}
//void cancel(int u) {
//	li[dep[u]].erase(name[u]);
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		cancel(to[ui]);
//	}
//}
//void dfs2(int u, int keep) {
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == son[u])continue;
//		dfs2(to[ui], false);
//	}
//	if (son[u] != 0)dfs2(son[u], true);
//	li[dep[u]].insert(name[u]);
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == son[u])continue;
//		effect(to[ui]);
//	}
//	for (auto v : qry[u]) {
//		ans[v[1]] = li[dep[u] + v[0]].size();
//	}
//	if (!keep) {
//		cancel(u);
//	}
//}
//int main() {
//	int n;
//	cin >> n;
//	map<string, int>id;
//	{
//		string s;
//		for (int i = 1, r; i <= n; i++) {
//			cin >> s >> r;
//			if (!id.count(s)) {
//				id[s] = cntid++;
//			}
//			if (r == 0)r = n + 1;
//			name[i] = id[s];
//			fa[i] = r;
//			addEdge(r, i);
//		}
//	}
//	qry.assign(n + 2, {});
//	int m;
//	cin >> m;
//	ans.assign(m + 1, 0);
//	for (int i = 1, v, k; i <= m; i++) {
//		cin >> v >> k;
//		qry[v].push_back({ k,i });
//	}
//	dep[n + 1] = 1;
//	dfs1(n + 1);
//	dfs2(n + 1, true);
//	for (int i = 1; i <= m; i++) {
//		cout << ans[i] << "\n";
//	}
//}