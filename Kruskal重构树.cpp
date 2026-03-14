//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 5;
//int head[N << 1];
//int to[N << 1];
//int nex[N << 1];
//int cntg = 1;
//int fa[N<<1];
//int st[N<<1][23];
//int wp[N<<1];
//int dep[N<<1];
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//void build(int n) {
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//	}
//}
//int find(int x) {
//	if (fa[x] != x) {
//		fa[x] = find(fa[x]);
//	}
//	return fa[x];
//}
//int cntnew;
//void dfs(int u, int fa) {
//	st[u][0] = fa;
//	dep[u] = dep[fa] + 1;
//	for (int p = 1; p <= 22; p++) {
//		st[u][p] = st[st[u][p - 1]][p - 1];
//	}
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		dfs(to[ui], u);
//	}
//}
//int lca(int u, int v) {
//	if (dep[u] < dep[v])swap(u, v);
//	for (int p = 22; p >= 0; p--) {
//		if (dep[st[u][p]] >= dep[v]) {
//			u = st[u][p];
//		}
//	}
//	if (u == v)return u;
//	for (int p = 22; p >= 0; p--) {
//		if (st[u][p] != st[v][p]) {
//			u = st[u][p];
//			v = st[v][p];
//		}
//	}
//	return st[u][0];
//}
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	cntnew = n;
//	vector<array<int, 3>>edge;
//	for (int i = 1,u,v,w; i <= m; i++) {
//		cin >> u >> v>>w;
//		edge.push_back({ u,v,w });
//	}
//	build(n);
//	sort(edge.begin(), edge.end(), [&](auto x,auto y) {
//		return x[2] < y[2];
//		});
//	for (int i = 0; i < edge.size(); i++) {
//		int u = edge[i][0], v = edge[i][1], w = edge[i][2];
//		int fu = find(u), fv = find(v);
//		if (fu != fv) {
//			fa[fu] = fa[fv] = ++cntnew;
//			fa[cntnew] = cntnew;
//			wp[cntnew] = w;
//			addEdge(cntnew, fu);
//			addEdge(cntnew, fv);
//		}
//	}
//	for (int i = 1; i <= cntnew; i++) {
//		if (fa[i] == i)dfs(i, 0);
//	}
//	int q;
//	cin >> q;
//	for (int i = 1,u,v; i <= q; i++) {
//		cin >> u >> v;
//		if (find(u) != find(v))cout << "impossible\n";
//		else cout << wp[lca(u, v)] << "\n";
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 8e5 + 5;
//int n, m, q;
//int head[N];
//int nex[N];
//int to[N];
//int fa[N];
//int wp[N];
//int st[N][23];
//int dep[N];
//int siz[N];
//int cntg = 1;
//int find(int x) {
//	if (fa[x] != x) {
//		fa[x] = find(fa[x]);
//	}
//	return fa[x];
//}
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//void prepare() {
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//		wp[i] = 0;
//	}
//}
//void dfs(int u, int pa) {
//	st[u][0] = pa;
//	dep[u] = dep[pa] + 1;
//	if (wp[u] == 0)siz[u] = 1;
//	for (int p = 1; p <= 22; p++) {
//		st[u][p] = st[st[u][p - 1]][p - 1];
//	}
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		dfs(to[ui], u);
//		siz[u] += siz[to[ui]];
//	}
//}
//int main() {
//	cin >> n >> m >> q;
//	prepare();
//	vector<array<int, 4>>edge;
//	for (int i = 1, x, y, k; i <= m; i++) {
//		cin >> x >> y >> k;
//		edge.push_back({ x,y,k,i });
//	}
//	sort(edge.begin(), edge.end(), [&](auto x, auto y) {
//		return x[2] > y[2];
//		});
//	int cntnew = n;
//	map<int, int>p;
//	for (int i = 0; i < edge.size(); i++) {
//		int u = edge[i][0], v = edge[i][1], w = edge[i][2], id = edge[i][3];
//		int fu = find(u), fv = find(v);
//		if (fu == fv)continue;
//		int uv = ++cntnew;
//		fa[fu] = fa[fv] = fa[uv] = uv;
//		p[id] = uv;
//		wp[uv] = w;
//		addEdge(uv, fv);
//		addEdge(uv, fu);
//	}
//	for (int i = 1; i <= cntnew; i++) {
//		if (fa[i] == i)dfs(i, 0);
//	}
//	vector<array<int, 2>>opt;
//	for (int i = 1, op, x, y, t = INT_MIN; i <= q; i++) {
//		cin >> op;
//		if (op == 1) {
//			cin >> t;
//			for (auto v : opt) {
//				wp[p[v[0]]] = v[1];
//			}
//			opt.clear();
//		}
//		else if (op == 2) {
//			cin >> x;
//			for (int p = 22; p >= 0; p--) {
//				if (st[x][p]!=0&&wp[st[x][p]] >= t) {
//					x = st[x][p];
//				}
//			}
//			cout << siz[x] << "\n";
//		}
//		else {
//			cin >> x >> y;
//			if (p.count(x)) {
//				opt.push_back({ x,y });
//			}
//		}
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int head[N];
//int nex[N<<1];
//int to[N << 1];
//int wp[N];
//int cntg = 1;
//int fa[N];
//int dep[N];
//int st[N][23];
//int siz[N];
//int n, m;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//void prepare(int n) {
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//	}
//}
//int find(int u) {
//	if (fa[u] != u) {
//		fa[u] = find(fa[u]);
//	}
//	return fa[u];
//}
//void dfs(int u, int pa) {
//	//cout << u << " " << pa << "%\n";
//	st[u][0] = pa;
//	dep[u] = dep[pa] + 1;
//	if (u <= n && u >= 1)siz[u] = 1;
//	for (int p = 1; p <= 22; p++) {
//		st[u][p] = st[st[u][p - 1]][p - 1];
//	}
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		dfs(to[ui], u);
//		siz[u] += siz[to[ui]];
//	}
//}
//bool check(int u,int v,int m,int k) {
//	//cout << u << " " << v << " " << m << " " << k << "##\n";
//	for (int p = 22; p >= 0; p--) {
//		if (st[u][p]!=0&&wp[st[u][p]] <=m) {
//			u = st[u][p];
//		}
//		if (st[v][p]!=0&&wp[st[v][p]] <=m) {
//			v = st[v][p];
//		}
//	}
//	//cout << u << ' ' << v << "$\n";
//	//cout << siz[u] << "\n";
//	if (u != v) {
//		return siz[u] + siz[v] >= k;
//	}
//	else {
//		return siz[u] >= k;
//	}
//}
//int query(int u, int v, int k) {
//	int l = 1, r = m,ans=-1,mid;
//	while (l <= r) {
//		mid = l + r >> 1;
//		//cout << l << " " << r << "^&\n";
//		if (check(u,v,mid,k)) {
//			ans = mid;
//			r = mid - 1;
//		}
//		else {
//			l = mid + 1;
//		}
//		//cout << l << "_" << r << "\n";
//	}
//	return ans;
//}
//int main() {
//	cin >> n >> m;
//	prepare(n);
//	vector<array<int,3>>edge;
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		edge.push_back({ u,v,i });
//	}
//	sort(edge.begin(), edge.end(), [&](auto x, auto y) {
//		return x[2] < y[2];
//		});
//	int cntnew = n;
//	for (int i = 0; i < edge.size(); i++) {
//		int u = edge[i][0], v = edge[i][1], w = edge[i][2];
//		int fu = find(u), fv = find(v);
//		if (fu == fv)continue;
//		int uv = ++cntnew;
//		fa[fu] = fa[fv] = fa[uv] = uv;
//		wp[uv] = w;
//		addEdge(uv, fu);
//		addEdge(uv, fv);
//	}
//	for (int i = 1; i <= cntnew;i++) {
//		if (fa[i] == i) {
//			dfs(i, 0);
//		}
//	}
//	//for (int i = 1; i <= cntnew; i++) {
//	//	cout << st[i][0] << " ";
//	//}cout << "**\n";
//	//for (int i = 1; i <= cntnew; i++) {
//	//	cout << wp[i] << " ";
//	//}cout << "**\n";
//	int q;
//	cin >> q;
//	for (int i = 1,u,v,k; i <= q; i++) {
//		cin >> u >> v >> k;
//		cout << query(u, v, k) << "\n";
//	}
//}


