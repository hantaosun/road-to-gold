//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 5;
//const int M = 2e5 + 5;
//const int T = N * 100;
//int n, m;
//int fa[T];
//int siz[T];
//int lson[T];
//int rson[T];
//int root[M];
//int cnt = 0;
//int copy(int x) {
//	int rt = ++cnt;
//	fa[rt] = fa[x];
//	siz[rt] = siz[x];
//	lson[rt] = lson[x];
//	rson[rt] = rson[x];
//	return rt;
//}
//int build(int l, int r) {
//	int rt = ++cnt;
//	if (l == r) {
//		siz[rt] = 1;
//		fa[rt] = l;
//		return rt;
//	}
//	int mid = l + r >> 1;
//	lson[rt] = build(l, mid);
//	rson[rt] = build(mid + 1, r);
//	return rt;
//}
//int upd(int x, int v, int who, int l, int r, int i) {
//	int rt = copy(i);
//	if (l == r) {
//		if (who) {
//			fa[rt] = v;
//		}
//		else {
//			siz[rt] = v;
//		}
//		return rt;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		lson[rt] = upd(x, v, who, l, mid, lson[i]);
//	}
//	else {
//		rson[rt] = upd(x, v, who, mid + 1, r, rson[i]);
//	}
//	return rt;
//}
//int queryX(int x, int l, int r, int i) {
//	if (l == r) {
//		return i;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		return queryX(x, l, mid, lson[i]);
//	}
//	else {
//		return queryX(x, mid + 1, r, rson[i]);
//	}
//}
//int find(int x, int i) {
//	int f = queryX(x, 1, n, i);
//	while (fa[f] != x) {
//		x = fa[f];
//		f = queryX(x, 1, n, i);
//	}
//	return f;
//}
//int merge(int u, int v, int rt) {
//	int fu = find(u, rt), fv = find(v, rt);
//	if (fa[fu] == fa[fv])return rt;
//	if (siz[fu] >= siz[fv]) {
//		int r1 = upd(fa[fv], fa[fu], 1, 1, n, rt);
//		int r2 = upd(fa[fu], siz[fu] + siz[fv], 0, 1, n, r1);
//		return r2;
//	}
//	else {
//		int r1 = upd(fa[fu], fa[fv], 1, 1, n, rt);
//		int r2 = upd(fa[fv], siz[fu] + siz[fv], 0, 1, n, r1);
//		return r2;
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	root[0] = build(1, n);
//	for (int i = 1, op, k, a, b; i <= m; i++) {
//		cin >> op;
//		if (op == 1) {
//			cin >> a >> b;
//			root[i] = merge(a, b, root[i - 1]);
//		}
//		else if (op == 2) {
//			cin >> k;
//			root[i] = root[k];
//		}
//		else {
//			cin >> a >> b;
//			root[i] = root[i - 1];
//			if (fa[find(a, root[i])] == fa[find(b, root[i])]) {
//				cout << 1 << "\n";
//			}
//			else {
//				cout << 0 << "\n";
//			}
//		}
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int n;
//int head[N];
//int to[N << 1];
//int nex[N << 1];
//int cntg = 1;
//int ball[N][2];
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//int fa[N];
//int siz[N];
//int edg[N];
//struct info {
//	int id1, siz1, edg1,pa1;
//	int id2, siz2, edg2,pa2;
//	info(int id1,int siz1,int edg1,int pa1,int id2,int siz2,int edg2,int pa2){ 
//		this->id1 = id1;
//		this->siz1 = siz1;
//		this->edg1 = edg1;
//		this->pa1 = pa1;
//		this->id2 = id2;
//		this->siz2 = siz2;
//		this->edg2 = edg2;
//		this->pa2 = pa2;
//	}
//};
//int cur = 0;//走到当前节点的答案
//stack<info>sta;
//int ans[N];
//int find(int u) {
//	while (fa[u] != u) {
//		u = fa[u];
//	}
//	return fa[u];
//}
//void merge(int fu, int fv) {
//	siz[fu] += siz[fv];
//	edg[fu] += edg[fv]+1;
//	fa[fv] = fu;
//}
//void withdraw(info t) {
//	fa[t.id1] = t.pa1;
//	siz[t.id1] = t.siz1;
//	edg[t.id1] = t.edg1;
//	fa[t.id2] = t.pa2;
//	siz[t.id2] = t.siz2;
//	edg[t.id2] = t.edg2;
//}
//void dfs(int u, int pa) {
//	//cout << u<<" "<<cur << "*\n";
//	int fp1 = find(ball[u][0]), fp2 = find(ball[u][1]);
//	if (siz[fp1] < siz[fp2])swap(fp1, fp2);
//	int pcur = cur;
//	sta.push(info(fp1, siz[fp1], edg[fp1],fa[fp1], fp2, siz[fp2], edg[fp2],fa[fp2]));
//	if (fp1 == fp2) {
//		if (siz[fp1] > edg[fp1]) {
//			cur++;
//		}
//		edg[fp1]++;
//	}
//	else {
//		if (siz[fp1] > edg[fp1] || siz[fp2] > edg[fp2]) {
//			cur++;
//		}
//		merge(fp1, fp2);
//	}
//	//cout << cur << "**\n";
//	ans[u] = cur;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == pa)continue;
//		dfs(to[ui], u);
//		cur = ans[u];
//	}
//	withdraw(sta.top());
//	sta.pop();
//	cur = pcur;
//	//cout << u<<" "<<cur << "*\n";
//}
//void build(int n) {
//	for (int i = 0; i <= n; i++) {
//		fa[i] = i;
//		edg[i] = 0;
//		siz[i] = 1;
//	}
//}
//int main() {
//	cin >> n;
//	build(n + 5);
//	for (int i = 1; i <= n; i++) {
//		cin >> ball[i][0] >> ball[i][1];
//	}
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs(1, 0);
//	for (int i = 2; i <= n; i++) {
//		cout << ans[i] << " ";
//	}cout << "\n";
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 5e5 + 5;
//int fa[N];
//int siz[N];
//struct info {
//	int id1, fa1, siz1;
//	int id2, fa2, siz2;
//	info(int id1, int fa1, int siz1, int id2, int fa2, int siz2) {
//		this->id1 = id1;
//		this->fa1 = fa1;
//		this->siz1 = siz1;
//		this->id2 = id2;
//		this->fa2 = fa2;
//		this->siz2 = siz2;
//	}
//};
//int find(int x) {
//	while (fa[x] != x) {
//		x = fa[x];
//	}
//	return fa[x];
//}
//void merge(int fu, int fv) {
//	fa[fv] = fu;
//	siz[fu] += siz[fv];
//}
//void withdraw(info t) {
//	fa[t.id1] = t.fa1;
//	siz[t.id1] = t.siz1;
//	fa[t.id2] = t.fa2;
//	siz[t.id2] = t.siz2;
//}
//stack<info>sta;
//void build(int n) {
//	for (int i = 0; i <= n; i++) {
//		fa[i] = i;
//		siz[i] = 1;
//	}
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n, m;
//	cin >> n >> m;
//	build(n + 5);
//	vector<array<int, 4>>edge;
//	for (int i = 1, u, v, w; i <= m; i++) {
//		cin >> u >> v >> w;
//		edge.push_back({ u,v,w,i });
//	}
//	int q;
//	cin >> q;
//	vector<array<int, 4>>edg1;
//	for (int i = 1, k; i <= q; i++) {
//		cin >> k;
//		for (int j = 1, id; j <= k; j++) {
//			cin >> id;
//			edg1.push_back({ edge[id - 1][0],edge[id - 1][1],edge[id - 1][2],i });
//		}
//	}
//	vector<bool>ans(q + 1, true);
//	sort(edg1.begin(), edg1.end(), [&](auto x, auto y) {
//		if (x[2] == y[2])return x[3] < y[3];
//		return x[2] < y[2];
//		});
//	sort(edge.begin(), edge.end(), [&](auto x, auto y) {
//		return x[2] < y[2];
//		});
//	int pc = 0;
//	for (int i = 0, j = 0; i < edg1.size() && j < edg1.size(); i = j) {
//		int w = edg1[i][2];
//		while (pc<edge.size()&&edge[pc][2] < w) {
//			int fu = find(edge[pc][0]);
//			int fv = find(edge[pc][1]);
//			if (fu != fv) {
//				if (siz[fu] < siz[fv])swap(fu, fv);
//				merge(fu, fv);
//			}
//			pc++;
//		}
//		while (j < edg1.size() && edg1[j][3] == edg1[i][3]&&edg1[i][2]==edg1[j][2]) {
//			int fu = find(edg1[j][0]);
//			int fv = find(edg1[j][1]);
//			sta.push({ fu,fa[fu],siz[fu],fv,fa[fv],siz[fv] });
//			if (fu == fv)ans[edg1[j][3]] = false;
//			else {
//				if (siz[fu] < siz[fv])swap(fu, fv);
//				merge(fu, fv);
//			}
//			j++;
//		}
//		for (int k = j - 1; k >= i; k--) {
//			withdraw(sta.top());
//			sta.pop();
//		}
//	}
//	for (int i = 1; i <= q; i++) {
//		if (ans[i]) {
//			cout << "YES\n";
//		}
//		else cout << "NO\n";
//	}
//}