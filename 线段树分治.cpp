//#include<bits/stdc++.h>
//using namespace std;
//int n, m, k;
//const int N=1e5+5;
//const int M=2e5+5;
//const int T=M*20;
//int cnt = 1;
//int head[M << 2];
//int nex[T];
//int tox[T];
//int toy[T];
//int fa[N << 1];
//int siz[N << 1];
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
//stack<info>sta;
//void build(int n) {
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//		siz[i] = 1;
//	}
//}
//void addEdge(int u,int x,int y) {
//	tox[cnt] = x;
//	toy[cnt] = y;
//	nex[cnt] = head[u];
//	head[u] = cnt++;
//}
//int find(int x) {
//	while (fa[x] != x) {
//		x = fa[x];
//	}
//	return x;
//}
//void Union(int x, int y) {
//	int fx = find(x);
//	int fy = find(y);
//	if (siz[fx] < siz[fy]) {
//		swap(fx, fy);
//	}
//	sta.push(info(fx, fa[fx], siz[fx], fy, fa[fy], siz[fy]));
//	fa[fy] = fx;
//	siz[fx] += siz[fy];
//}
//void undo(int cnt) {
//	for (int i = 1; i <= cnt; i++) {
//		info tmp = sta.top();
//		sta.pop();
//		fa[tmp.id1] = tmp.fa1;
//		siz[tmp.id1] = tmp.siz1;
//		fa[tmp.id2] = tmp.fa2;
//		siz[tmp.id2] = tmp.siz2;
//	}
//}
//void add(int jl, int jr, int x, int y,int l,int r, int i) {
//	if (jl <= l && jr >= r) {
//		addEdge(i, x, y);
//		return;
//	}
//	int mid = l + r >> 1;
//	if (jl <= mid) {
//		add(jl, jr, x, y, l, mid, i << 1);
//	}
//	if(jr>mid){
//		add(jl, jr, x, y, mid + 1, r, i << 1 | 1);
//	}
//}
//bool ans[N];
//void dfs(int l, int r, int i) {
//	int ecnt = 0;
//	bool check = true;
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		int x = tox[ui];
//		int y = toy[ui];
//		int fx = find(x);
//		int fy = find(y);
//		if (fx == fy) {
//			check = false;
//			break;
//		}
//		else {
//			Union(x, y + n);
//			Union(y, x + n);
//			ecnt += 2;
//		}
//	}
//	if (check) {
//		if (l == r) {
//			ans[l] = true;
//		}
//		else {
//			int mid = l + r >> 1;
//			dfs(l, mid, i << 1);
//			dfs(mid + 1, r, i << 1 | 1);
//		}
//	}
//	else {
//		for (int j = l; j <= r; j++) {
//			ans[j] = false;
//		}
//	}
//	undo(ecnt);
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n >> m >> k;
//	build(2 * n + 5);
//	for (int i = 1,x,y,l,r; i <= m; i++) {
//		cin >> x >> y >> l >> r;
//		l++;
//		add(l, r, x, y, 1, k, 1);
//	}
//	dfs(1, k, 1);
//	for (int i = 1; i <= k; i++) {
//		if (ans[i]) {
//			cout << "Yes\n";
//		}
//		else cout << "No\n";
//	}
//}