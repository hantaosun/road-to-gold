//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5+5;
//int a[N];
//int sum[N << 2];
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//int query(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int ans = 0;
//	int mid = l + r >> 1;
//	if (jl <= mid) {
//		ans += query(jl, jr, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		ans += query(jl, jr, mid+1, r, i << 1|1);
//	}
//	return ans;
//}
//void update(int jl, int jr, int l, int r, int i) {
//	if (sum[i] == r - l + 1)return;
//	if (l == r){
//		sum[i] = (int)(sqrt(sum[i]));
//		return;
//	}
//	int mid = l + r >> 1;
//	if (jl <= mid) {
//		update(jl, jr, l, mid, i<<1);
//	}
//	if (jr > mid) {
//		update(jl, jr, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = a[l];
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid+1, r, i << 1|1);
//		up(i);
//	}
//}
//signed main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int m;
//	cin >> m;
//	build(1, n, 1);
//	for (int i = 1,k,l,r; i <= m; i++) {
//		cin >>k>> l >> r;
//		if (l > r) {
//			swap(l, r);
//		}
//		if (k == 0) {
//			update(l, r, 1, n, 1);
//		}
//		else if (k == 1) {
//			cout << query(l,r, 1, n, 1)<<'\n';
//		}
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	cout << "Alice\n";
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//#define ll long long
//using namespace std;
//const int N = 1e6 + 5;
//const int mod = 1e9 + 7;
//int n, m;
//int id(int i, int j) {
//	return (i - 1) * (m)+j;
//}
//int pa[N];
//int fa[N];
//int hao[N];//当前块的编号
//int find(int x) {
//	while (fa[x] != x) {
//		x = fa[x] = fa[fa[x]];
//	}
//	return fa[x];
//}
//void Union(int x, int y) {
//	int fx = find(x);
//	int fy = find(y);
//	fa[fx] = fy;
//}
//void build(int num) {
//	for (int i = 1; i <= num; i++) {
//		fa[i] = i;
//	}
//}
//int dx[] = { 0,1,0 };
//int dy[] = { -1,0,1 };
//int cnt = 1;
//bool vis[N];
//ll f(int u,vector<set<int>>&g) {
//	vis[u] = true;
//	ll ans = 1;
//	for (int v : g[u]) {
//		ans = ans * f(v, g)%mod;
//	}
//	return ans + 1;
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n >> m;
//	build(n * m);
//	vector<vector<int>>grid(n + 1, vector<int>(m + 1));
//	char o;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j <m ; j++) {
//			cin >> o;
//			if (o == '#') {
//				grid[i][j] = -1;
//			}
//			else {
//				grid[i][j] = 0;
//			}
//		}
//	}
//	if (n <= 2 || m <= 2) {
//		cout << 0 << '\n';
//		return 0;
//	}
//	n-=2; m-=2;
//	for (int i = n; i>=1; i--) {
//		for (int j = 1; j <= m; j++) {
//			if (grid[i][j] == -1)continue;
//			for (int d = 0,ni,nj; d < 3; d++) {
//				ni = i + dx[d];
//				nj = j + dy[d];
//				if (grid[ni][nj] != -1) {
//					Union(id(ni, nj),id(i, j));
//				}
//			}
//		}
//		for (int j = 1; j <= m; j++) {
//			if (grid[i][j] == -1)continue;
//			if (fa[id(i, j)] == id(i, j)) {
//				hao[id(i, j)] = cnt++;
//			}
//		}
//		for (int j = 1; j <= m; j++) {
//			if (grid[i][j] == -1)continue;
//			grid[i][j] = hao[find(id(i, j))];
//		}
//	}
//	vector<set<int>>g(cnt + 5);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			if (grid[i][j] == -1)continue;
//			if (grid[i + 1][j] == -1)continue;
//			g[grid[i][j]].insert(grid[i + 1][j]);
//		}
//	}
//	ll ans = 1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			if (!vis[grid[i][j]] && grid[i][j] != -1) {
//				ans = ans * f(grid[i][j],g)%mod;
//			}
//		}
//	}
//	cout << ans << '\n';
//}


//奶酪
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//struct Point {
//	int x, y, z;
//};
//const int N = 1e3 + 5;
//int fa[N];
//void build(int n) {
//	for (int i = 0; i <= n; i++) {
//		fa[i] = i;
//	}
//}
//int find(int x) {
//	while (fa[x] != x) {
//		x = fa[x] = fa[fa[x]];
//	}
//	return x;
//}
//void merge(int x, int y) {
//	int fx = find(x);
//	int fy = find(y);
//	fa[fx] = fy;
//}
//void solve() {
//	int n, h;
//	int r;
//	cin >> n >> h >> r;
//	vector<Point>p(n+1);
//	build(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i].x >> p[i].y >> p[i].z;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (abs(p[i].z) <= r) {
//			merge(0, i);
//		}
//		if (abs(p[i].z - h) <= r) {
//			merge(i, n + 1);
//		}
//		for (int j = 1; j < i; j++) {
//			if ((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y)
//				+ (p[i].z - p[j].z) * (p[i].z - p[j].z) <= 4 * r * r) {
//				merge(i, j);
//			}
//		}
//	}
//	if (find(0) == find(n + 1)) {
//		cout << "Yes\n";
//	}
//	else cout << "No\n";
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//struct Circle {
//	double x, y;
//	double r;
//};
//struct Edge {
//	int l, r;
//	double x;
//	Edge(int l, int r, double x) {
//		this->l = l;
//		this->r = r;
//		this->x = x;
//	}
//	Edge() {
//
//	}
//};
//const int N = 2050;
//int fa[N];
//void build(int n) {
//	for (int i = 0; i <= n; i++) {
//		fa[i] = i;
//	}
//}
//int find(int x) {
//	while (fa[x] != x) {
//		x = fa[x] = fa[fa[x]];
//	}
//	return x;
//}
//void merge(int x, int y) {
//	int fx = find(x);
//	int fy = find(y);
//	fa[fx] = fy;
//}
//bool isSameSet(int x, int y) {
//	return find(x) == find(y);
//}
//const double eps = 1e-4;
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	double w, h;
//	cin >> w >> h;
//	build(n + 10);
//	vector<Circle>tree(n+1);
//	for (int i = 1; i <= n; i++) {
//		cin >> tree[i].x >> tree[i].y >> tree[i].r;
//	}
//	vector<Edge>edge;
//	//n+1,n+2,n+3,n+4表示上下左右
//	for (int i = 1; i <= n; i++) {
//		edge.emplace_back(Edge(i, n + 1, (h - tree[i].y-tree[i].r)/2 ));
//		edge.emplace_back(Edge(i, n + 2,(tree[i].y-tree[i].r)/2 ));
//		edge.emplace_back(Edge(i, n + 3, (tree[i].x-tree[i].r)/2 ));
//		edge.emplace_back(Edge(i, n + 4, (w - tree[i].x-tree[i].r)/2 ));
//		for (int j = 1; j < i; j++) {
//			edge.emplace_back(Edge(i, j, 
//				(sqrt((tree[i].x - tree[j].x) * (tree[i].x - tree[j].x)
//					+ (tree[i].y - tree[j].y) * (tree[i].y - tree[j].y)) - tree[i].r - tree[j].r) / 2));
//		}
//	}
//
//	vector<array<int, 3>>man(m+1);//0是半径 1是入口
//	for (int i = 1; i <= m; i++) {
//		cin >> man[i][0] >> man[i][1];
//		man[i][2] = i;
//	}
//	vector<vector<int>>ans(m + 1);
//	sort(man.begin() + 1, man.end(), [&](array<int,3>&a,array<int,3>&b) {
//		return a[0] < b[0];
//		});
//	sort(edge.begin(), edge.end(), [&](Edge&a,Edge&b) {
//		return a.x < b.x;
//		});
//	int p = 0;
//	for (int i = 1; i <= m; i++) {
//		while (edge[p].x+eps < man[i][0]) {
//			merge(edge[p].l, edge[p].r);
//			p++;
//		}
//		int id = man[i][2];
//		ans[id].push_back(man[i][1]);
//		if (man[i][1] == 1) {
//			if (!(isSameSet(n + 3, n + 4) || isSameSet(n + 3, n + 1) || isSameSet(n + 3, n + 2))) {
//				ans[id].emplace_back(4);
//			}
//			if (!(isSameSet(n + 2, n + 4) || isSameSet(n + 2, n + 1) || isSameSet(n + 2, n + 3))) {
//				ans[id].emplace_back(2);
//			}
//			if (!(isSameSet(n + 3, n + 4) || isSameSet(n + 3, n + 2) || isSameSet(n + 1, n + 2) || isSameSet(n + 1, n + 4))) {
//				ans[id].emplace_back(3);
//			}
//		}
//		else if (man[i][1] == 2) {
//			if (!(isSameSet(n + 2, n + 4) || isSameSet(n + 2, n + 1) || isSameSet(n + 2, n + 3))) {
//				ans[id].emplace_back(1);
//			}
//			if (!(isSameSet(n + 4, n + 3) || isSameSet(n + 4, n + 1) || isSameSet(n + 4, n + 2))) {
//				ans[id].emplace_back(3);
//			}
//			if (!(isSameSet(n + 2, n + 1) || isSameSet(n + 2, n + 4) || isSameSet(n + 3, n + 4) || isSameSet(n + 3, n + 1))) {
//				ans[id].emplace_back(4);
//			}
//		}
//		
//		else if (man[i][1] == 3) {
//			if (!(isSameSet(n + 1, n + 4) || isSameSet(n + 1, n + 2) || isSameSet(n + 1, n + 3))) {
//				ans[id].emplace_back(4);
//			}
//			if (!(isSameSet(n + 4, n + 3) || isSameSet(n + 4, n + 1) || isSameSet(n + 4, n + 2))) {
//				ans[id].emplace_back(2);
//			}
//			if (!(isSameSet(n + 3, n + 4) || isSameSet(n + 3, n + 2) || isSameSet(n + 1, n + 2) || isSameSet(n + 1, n + 4))) {
//				ans[id].emplace_back(1);
//			}
//		}
//		else  {
//			if (!(isSameSet(n + 3, n + 4) || isSameSet(n + 3, n + 1) || isSameSet(n + 3, n + 2))) {
//				ans[id].emplace_back(1);
//			}
//			if (!(isSameSet(n + 2, n + 1) || isSameSet(n + 2, n + 4) || isSameSet(n + 3, n + 4) || isSameSet(n + 3, n + 1))) {
//				ans[id].emplace_back(2);
//			}
//			if (!(isSameSet(n + 1, n + 4) || isSameSet(n + 1, n + 2) || isSameSet(n + 1, n + 3))) {
//				ans[id].emplace_back(3);
//			}
//		}
//	}
//	for (int i = 1; i <= m; i++) {
//		sort(ans[i].begin(), ans[i].end());
//		for (int j = 0; j < ans[i].size(); j++) {
//			cout << ans[i][j];
//		}cout << '\n';
//	}
//}

