//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>p(n + 1);
//	vector<int>pos(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//		pos[p[i]] = i;
//	}
//	int l = INT_MAX, r = INT_MIN;
//	for (int i = n; i >=1 ; i--) {
//		l = min(l, pos[i]);
//		r = max(r, pos[i]);
//		if (r - l + 1 > n - i + 1) {
//			cout << "NO\n";
//			return;
//		}
//	}
//	cout << "YES\n";
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
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+1);
//	vector<int>b(k + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= k; i++) {
//		cin >> b[i];
//	}
//	sort(a.begin() + 1, a.end(), [&](int x, int y) {
//		return x > y;
//		});
//	sort(b.begin() + 1, b.end());
//	int p = 1;
//	for (int i = 1; i <= k; i++) {
//		if (p > n)break;
//		int lastp = p;
//		while (p - lastp + 1 < b[i]) {
//			p++;
//		}
//		if (p > n)break;
//		a[p] = 0;
//		p++;
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		ans += a[i];
//	}
//	cout << ans << '\n';
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<vector<int>>g(n + 1);
//	vector<int>ide(n + 1);
//	for (int i = 1,u,v,x,y; i < n; i++) {
//		cin >> u >> v >> x >> y;
//		if (x > y) {
//			g[v].push_back(u);
//			ide[u]++;
//		}
//		else {
//			g[u].push_back(v);
//			ide[v]++;
//		}
//	}
//	queue<int>q;
//	int cnt = 1;
//	vector<int>ans(n + 1);
//	for (int i = 1; i <= n; i++) {
//		if (ide[i] == 0) {
//			q.push(i);
//		}
//	}
//	while (!q.empty()) {
//		int x = q.front();
//		q.pop();
//		ans[x] = cnt++;
//		for (auto v : g[x]) {
//			if (--ide[v] == 0) {
//				q.push(v);
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << ans[i] << ' ';
//	}
//	cout << '\n';
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
//const int mod = 1e9 + 7;
//int qpow(int x, int y) {
//	int ans = 1;
//	while (y != 0) {
//		if (y & 1) {
//			ans = ans * x % mod;
//		}
//		x = x * x % mod;
//		y >>= 1;
//	}
//	return ans;
//}
//int dp[305][305][305];//i位置及以前，合法且下降后缀最大为j的子序列数量,0表示还没有逆序对
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	memset(dp, 0, sizeof(dp));
//	dp[1][0][0] = 1;
//	dp[1][0][a[1]] = 1;
//	for (int i = 1; i < n; i++) {
//		for (int j = 0; j <= n; j++) {
//			if (j == 0) {
//				for (int k = 0; k <= n; k++) {
//					if (a[i + 1] >= k) {
//						dp[i + 1][0][a[i + 1]] = (dp[i + 1][0][a[i + 1]] + dp[i][j][k])%mod;
//					}
//					else {
//						dp[i + 1][a[i + 1]][k] = (dp[i + 1][a[i + 1]][k] + dp[i][j][k]) % mod;
//					}
//				}
//			}
//			else {
//				for (int k = 0; k <= n; k++) {
//					if (a[i + 1] < j)continue;
//					if (a[i + 1] < k) {
//						dp[i + 1][a[i + 1]][k] = (dp[i + 1][a[i + 1]][k] + dp[i][j][k])%mod;
//					}
//					else if (a[i + 1] >= k) {
//						dp[i + 1][j][a[i + 1]] = (dp[i + 1][j][a[i + 1]] + dp[i][j][k])%mod;
//					}
//				}
//			}
//		}
//		for (int j = 0; j <= n; j++) {
//			for (int k = 0; k <= n; k++) {
//				dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k])%mod;
//			}
//		}
//	}
//	int ans = 0;
//	for (int j = 0; j <= n; j++) {
//		for (int k = 1; k <= n; k++) {
//			ans = (ans + dp[n][j][k])%mod;
//		}
//	}
//	cout << (ans + 1)%mod << '\n';
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}
// 
// 
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N = 2005;
//const int mod = 1e9 + 7;
//int dp[N][N];//当前来到i位置，前一个下降的最大值为j,总最大值为k,方案数
//int col[N][N];//col[i]维护第i列的树状数组
//int row[N][N];//row[i[维护第i行的树状数组
//int lowbit(int i) {
//	return i & (-i);
//}
//void add(int x,int y, int v) {//给第x行第y列加v
//	int t = y;
//	while (t < N) {
//		row[x][t] = (row[x][t] + v)%mod;
//		t += lowbit(t);
//	}
//	t = x;
//	while (t < N) {
//		col[y][t] = (col[y][t] + v)%mod;
//		t += lowbit(t);
//	}
//}
//int queryRow(int x, int p) {//询问第x行前p列的和
//	int ans = 0;
//	while (p > 0) {
//		ans = (ans + row[x][p])%mod;
//		p -= lowbit(p);
//	}
//	return ans;
//}
//int queryCol(int x, int p) {//询问第x列前p行的和
//	int ans = 0;
//	while (p > 0) {
//		ans = (ans + col[x][p])%mod;
//		p -= lowbit(p);
//	}
//	return ans;
//}
//void solve() {
//	int n;
//	cin >> n;
//	memset(dp, 0, sizeof(dp));
//	memset(row, 0, sizeof(row));
//	memset(col, 0, sizeof(col));
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	dp[0][0] = 1;
//	add(1, 1, 1);
//	for (int i = 1; i <= n; i++) {
//		int x = a[i];
//		//x大于最大值时,枚举次大
//		for (int y = 0; y <= a[i];y++) {
//			int v = queryCol(y+1, x+1);
//			dp[x][y] = (dp[x][y] + v)%mod;
//			add(x+1, y+1, v);
//		}
//		//x小于最大值，大于次大值时枚举最大
//		for (int y = a[i] + 1; y <= n; y++) {
//			int v = queryRow(y+1, x+1);
//			dp[y][x] = (dp[y][x] + v)%mod;
//			add(y+1, x+1, v);
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= n; j++) {
//			ans = (ans + dp[i][j])%mod;
//		}
//	}
//	cout << ans << "\n";
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	string s;
//	cin >> s;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}