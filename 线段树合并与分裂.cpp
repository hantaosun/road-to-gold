//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 5;
//const int T = N * 20;
//int p[N];
//int n;
//int m;
//int head[N];
//int nex[N];
//int to[N];
//int cntg = 1;
//int rt[N];
//int ans[N];
//int lson[T];
//int rson[T];
//int sum[T];
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//int cnt = 0;
//void up(int i) {
//	sum[i] = sum[lson[i]] + sum[rson[i]];
//}
//void add(int x, int l, int r, int i) {
//	if (l == r) {
//		sum[i]++;
//		return;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		if (lson[i] == 0) {
//			lson[i] = ++cnt;
//		}
//		add(x, l, mid, lson[i]);
//	}
//	else {
//		if (rson[i] == 0) {
//			rson[i] = ++cnt;
//		}
//		add(x, mid + 1, r, rson[i]);
//	}
//	up(i);
//}
//int merge(int rt1, int rt2) {
//	if (rt1 == 0 || rt2 == 0) {
//		return rt1 + rt2;
//	}
//	sum[rt1] += sum[rt2];
//	lson[rt1] = merge(lson[rt1], lson[rt2]);
//	rson[rt1] = merge(rson[rt1], rson[rt2]);
//	return rt1;
//}
//int query(int jl,int jr,int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int an = 0,mid=l+r>>1;
//	if (jl <= mid) {
//		an += query(jl, jr, l, mid, lson[i]);
//	}
//	if (jr > mid) {
//		an += query(jl, jr, mid + 1, r, rson[i]);
//	}
//	return an;
//}
//void dfs(int u) {
//	if (rt[u] == 0) {
//		rt[u] = ++cnt;
//	}
//	add(p[u], 1, m, rt[u]);
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		dfs(to[ui]);
//		rt[u]=merge(rt[u], rt[to[ui]]);
//	}
//	ans[u] = query(p[u] + 1, m, 1, m, rt[u]);
//}
//int main() {
//	cin >> n;
//	vector<int>vsort;
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//		vsort.push_back(p[i]);
//	}
//	sort(vsort.begin(), vsort.end());
//	vsort.erase(unique(vsort.begin(), vsort.end()), vsort.end());
//	for (int i = 1; i <= n; i++) {
//		p[i] = lower_bound(vsort.begin(), vsort.end(), p[i]) - vsort.begin() + 1;
//	}
//	m = vsort.size();
//	for (int i = 2, f; i <= n; i++) {
//		cin >> f;
//		addEdge(f, i);
//	}
//	dfs(1);
//	for (int i = 1; i <= n; i++) {
//		cout << ans[i] << "\n";
//	}
//}