//#include<bits/stdc++.h>	
//#define int long long
//using namespace std;
//const int N = 2e5 + 10;
//int dp[N];//删完当前子树最少操作次数
//int sum[N];
////当前树所有子树删除完的最少次数
//vector<vector<int>>g;
//void dfs(int u, int fa) {
//	if (g[u].size()==1&&g[u][0]==fa) {
//		dp[u] = 2;
//		sum[u] = 0;
//		return;
//	}
//	for (auto v : g[u]) {
//		if (v == fa)continue;
//		dfs(v, u);
//		sum[u] += dp[v];
//	}
//	for (auto v : g[u]) {
//		if (v == fa)continue;
//		dp[u] = min(dp[u], 1 + sum[u] - dp[v] + sum[v]);
//	}
//	dp[u] = min(dp[u], 2 + sum[u]);
//}
//signed main() {
//	int n;
//	cin >> n;
//	g.assign(n + 1, {});
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	for (int i = 1; i <= n; i++) {
//		dp[i] = INT_MAX;
//		sum[i] = 0;
//	}
//	dfs(1, 0);
//	cout << dp[1]<<'\n';
//}



//多个操作先判断顺序和操作次数
//位运算必考虑逐位计算
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int log2(int a) {
//	int ans = 0;
//	while (1 << ans <= a >> 1) {
//		ans++;
//	}
//	return ans;
//}
//const int N = 5e6;
//int tree[N];
//int n;
//int lowbit(int x) {
//	return x & (-x);
//}
//void add(int x, int v) {
//	while (x <= n) {
//		tree[x] += v;
//		x += lowbit(x);
//	}
//}
//int sum(int x) {
//	int ans = 0;
//	while (x > 0) {
//		ans += tree[x];
//		x -= lowbit(x);
//	}
//	return ans;
//}
//int query(int l, int r) {
//	if (l > r)return 0;
//	return sum(r) - sum(l - 1);
//}
//signed main() {
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int p = log2(n);
//	bool flag = 0;
//	for (int m = 0; m < p; m++) {
//		int b = 1 << m;
//		memset(tree, 0, sizeof(int) * (n + 5));
//		int c1 = 0, c2 = 0;
//		for (int j = 1; j <= n; j++) {
//			c1 += j - 1 - sum(a[j]);
//			add(a[j]+1,1);
//		}
//		memset(tree, 0, sizeof(int) * (n + 5));
//		for (int j = 1; j <= n; j++) {
//			a[j] ^= b;
//			c2 += j-1-sum(a[j]);
//			add(a[j]+1, 1);
//		}
//		if (c2 >= c1) {
//			for (int j = 1; j <= n; j++) {
//				a[j] ^= b;
//			}
//		}
//		else flag = 1;
//	}
//	int ans = 0;
//	memset(tree, 0, sizeof(int) * (n + 5));
//	for (int j = 1; j <= n; j++) {
//		ans += j - 1 - sum(a[j]);
//		add(a[j]+1, 1);
//	}
//	cout << ans + flag << '\n';
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 6005;
//bool vis[N][N];
//bool got[N][N];
//int dp[N][N];
//vector<vector<int>>le;
//vector<array<int, 2>>a;
//vector<int>vsort;
//void f(int l, int r) {
//	if (vis[l][r])return;
//	if (l > r)return;
//	vis[l][r] = 1;
//	dp[l][r] = got[l][r];
//	if (l < r) {
//		f(l + 1, r);
//		dp[l][r] = max(dp[l][r], dp[l + 1][r] + got[l][r]);
//	}
//	for (auto v : le[l]) {
//		if (v >= r)break;
//		f(l, v);
//		f(v + 1, r);
//		dp[l][r] = max(dp[l][r], got[l][r] + dp[l][v] + dp[v + 1][r]);
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	a.assign(n + 1,{});
//	vsort.clear();
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i][0] >> a[i][1];
//		vsort.push_back(a[i][0]);
//		vsort.push_back(a[i][1]);
//	}
//	sort(vsort.begin(), vsort.end());
//	vsort.erase(unique(vsort.begin(), vsort.end()), vsort.end());
//	le.assign(vsort.size()+5,{});
//	for (int i = 0; i <= min(N, int(le.size())); i++) {
//		for (int j = 0; j <= min(N, int(le.size())); j++) {
//			vis[i][j] = 0;
//			dp[i][j] = 0;
//			got[i][j] = 0;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		a[i][0] = lower_bound(vsort.begin(), vsort.end(), a[i][0]) - vsort.begin();
//		a[i][1] = lower_bound(vsort.begin(), vsort.end(), a[i][1]) - vsort.begin();
//		le[a[i][0]].push_back(a[i][1]);
//		got[a[i][0]][a[i][1]] = 1;
//	}
//	for (int i = 0; i < vsort.size(); i++) {
//		sort(le[i].begin(), le[i].end());
//	}
//	f(0, vsort.size()-1);
//	cout << dp[0][vsort.size()-1] << '\n';
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N= 4e5 + 5;
//int mx[N << 2];
//void up(int i) {
//	mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
//}
//void upd(int x, int v, int l, int r, int i) {
//	if (l == r) {
//		mx[i] = v;
//		return;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		upd(x, v, l, mid, i << 1);
//	}
//	if (x > mid) {
//		upd(x, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//int query(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return mx[i];
//	}
//	int mid = l + r >> 1;
//	int ans = INT_MIN;
//	if (jl <= mid) {
//		ans = max(ans, query(jl, jr, l, mid, i << 1));
//	}
//	if (jr > mid) {
//		ans = max(ans, query(jl, jr, mid + 1, r, i << 1 | 1));
//	}
//	return ans;
//}
//void debug(int l, int r, int i) {
//	if (l == r) {
//		cout << l << ":" << mx[i] << ' ';
//		return;
//	}
//	int mid = l + r >> 1;
//	debug(l, mid, i << 1);
//	debug(mid + 1, r, i << 1 | 1);
//}
//int main() {
//	int n;
//	cin >> n;
//	vector<array<int, 2>>a(n+1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i][0] >> a[i][1];
//		if (a[i][0] > a[i][1])swap(a[i][0], a[i][1]);
//	}
//	sort(a.begin()+1, a.end(), [&](auto x,auto y) {
//		return x[1] < y[1];
//		});
//	vector<int>dp(n + 1);
//	for (int i = 1; i <= n; i++) {
//		int t = query(a[i][0]+1, 2*n, 1, 2*n, 1);
//		upd(a[i][0], t + 1, 1, 2*n, 1);
//		dp[i] = t + 1;
//		//cout << a[i][0] << '\n';
//		//debug(1,2*n,1); cout << '\n';
//	}
//	int ans = INT_MIN;
//	for (int i = 1; i <= n; i++) {
//		ans = max(ans, dp[i]+query(a[i][1], 2*n, 1, 2 * n, 1));
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	cout << a[i][0] << " " << a[i][1] << " " << dp[i] << '\n';
//	//}
//	cout << ans << '\n';
//}