//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n, a, b;
//	cin >> n >> a >> b;
//	string s;
//	cin >> s;
//	cout << s.substr(a, n - a - b)<<'\n';
//}


//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n, m;
//	cin >> n >> m;
//	multiset<int>a;
//	for (int i = 1,u; i <= n; i++) {
//		cin >> u;
//		a.insert(u);
//	}
//	for (int i = 1,u; i <= m; i++) {
//		cin >> u;
//		auto it = a.find(u);
//		if(it!=a.end())a.erase(a.find(u));
//	}
//	for (auto v : a) {
//		cout << v << ' ';
//	}cout << '\n';
//}


//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	map<int, int>mp;
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		int cur = i - a[i];
//		ans += mp[cur];
//		mp[i+a[i]]++;
//	}
//	cout << ans << '\n';
//}


//#include<bits/stdc++.h>
//using namespace std;
//int dp[10005][1005];//当前位置心情为x时最终心情是多少
//int main() {
//	int n;
//	cin >> n;
//	vector<array<int, 3>>gift(n+1);
//	int sum = 0;
//	int mx = INT_MIN;
//	for (int i = 1; i <= n; i++) {
//		cin >> gift[i][0] >> gift[i][1] >> gift[i][2];
//		sum += gift[i][2];
//		mx = max(mx, gift[i][0]);
//	}
//	for (int j = 0; j < 1005; j++) {
//		dp[n+1][j] = j;
//	}
//	for (int i = n; i >= 1; i--) {
//		for (int j = 0; j < 1005; j++) {
//			if (j > gift[i][0]) {
//				dp[i][j] = dp[i+1][max(0,j-gift[i][2])];
//			}
//			else {
//				dp[i][j] = dp[i+1][j+gift[i][1]];
//			}
//		}
//	}
//	vector<int>presum(n + 1);
//	for (int i = 1; i <= n; i++) {
//		presum[i] = presum[i - 1] + gift[i][2];
//	}
//	int q;
//	cin >> q;
//	
//	for (int i = 1,x; i <= q; i++) {
//		cin >> x;
//		if (x < 1005) {
//			cout << dp[1][x]<<'\n';
//			continue;
//		}
//		if (x - sum > mx) {
//			cout << x - sum << '\n';
//			continue;
//		}
//		auto it = lower_bound(presum.begin()+1, presum.end(), x - 1000);
//		int id = it - presum.begin()+1;
//		cout << dp[id][x - presum[id-1]] << "\n";
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//stack<int>path;
//bool vis[1005];
//bool flag = 0;
//void dfs(int u, int tar,vector<set<int>>&g) {
//	if (vis[u]||flag)return;
//	if (u == tar) {
//		path.push(tar);
//		flag = 1;
//		return;
//	}
//	vis[u] = 1;
//	path.push(u);
//	for (auto v : g[u]) {
//		dfs(v, tar, g);
//	}
//	if (flag)return;
//	path.pop();
//}
//void solve() {
//	memset(vis, 0, sizeof(vis));
//	int n, m, x, y;
//	flag = 0;
//	cin >> n >> m >> x >> y;
//	vector<set<int>>g(n + 1);
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		g[u].insert(v);
//		g[v].insert(u);
//	}
//	dfs(x, y, g);
//	stack<int>tmp;
//	while (!path.empty()) {
//		tmp.push(path.top()); path.pop();
//	}
//	while (!tmp.empty()) {
//		cout << tmp.top() << ' ';
//		tmp.pop();
//	}cout << '\n';
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
//using namespace std;
//const int mod = 998244353;
//const int N = 2e5 + 5;
//int a[N];
//int sum[N << 2];
//int lzt[N << 2];
//int qpow(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a % mod;
//		}
//		b >>= 1;
//		a = a * a % mod;
//	}
//	return ans;
//}
//void lazy(int i, int v, int n) {
//	sum[i] = n * v % mod;
//	lzt[i] = v;
//}
//void up(int i) {
//	sum[i] = (sum[i << 1] + sum[i << 1 | 1]) % mod;
//}
//void down(int i, int ln, int rn) {
//	if (lzt[i] != -1) {
//		lazy(i << 1, lzt[i], ln);
//		lazy(i << 1 | 1, lzt[i], rn);
//		lzt[i] = -1;
//	}
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = a[l];
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	lzt[i] = -1;
//}
//void upd(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v, r - l + 1);
//		return;
//	}
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	if (jl <= mid) {
//		upd(jl, jr, v, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		upd(jl, jr, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//int query(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	int ans = 0;
//	if (jl <= mid) {
//		ans = (ans + query(jl, jr, l, mid, i << 1)) % mod;
//	}
//	if (jr > mid) {
//		ans = (ans + query(jl, jr, mid + 1, r, i << 1 | 1)) % mod;
//	}
//	up(i);
//	return ans;
//}
//int inv[N];
//void prepare() {
//	inv[1] = 1;
//	for (int i = 2; i < N; i++) {
//		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
//	}
//}
//signed main() {
//	prepare();
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	build(1, n, 1);
//	for (int i = 1, l, r; i <= m; i++) {
//		cin >> l >> r;
//		int tot = query(l, r, 1, n, 1);
//		int val = tot * inv[r - l + 1] % mod;
//		upd(l, r, val, 1, n, 1);
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << query(i, i, 1, n, 1) << ' ';
//	}cout << '\n';
//	return 0;
//}


