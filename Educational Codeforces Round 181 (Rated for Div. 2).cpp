//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	string s;
//	cin >> s;
//	int t = 0;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] == 'T') {
//			t++;
//		}
//	}
//	for (int i = 1; i <= t; i++) {
//		cout << 'T';
//	}
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] != 'T')cout << s[i];
//	}
//	cout << endl;
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
//int gcd(int a, int b) {
//	while (b != 0) {
//		int temp = b;
//		b = a % b;
//		a = temp;
//	}
//	return a;
//}
//void solve() {
//	int a, b, k;
//	cin >> a >> b >> k;
//	int g = gcd(a, b);
//	if (max(a / gcd(a, b) , b / gcd(a, b)) <= k) {
//		cout << 1 << endl;
//	}
//	else cout << 2 << endl;
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define i64 long long
//i64 f(i64 x) {
//	return x - x / 2 - x / 3 - x / 5 - x / 7 +x/6+x/10+x/14+x/15+x/21+x/35-x/30-x/42-x/70-x/105+x/210;
//}
//using namespace std;
//
//void solve() {
//	i64 l, r;
//	cin >> l >> r;
//	cout<<f(r) - f(l - 1)<<endl;
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
//vector<array<int, 4>>a;
//int n, m;
//vector<array<int, 2>>pp;
//int qmi(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = (ans * a) % mod;
//		}
//		a = (a * a) % mod;
//		b >>= 1;
//	}
//	return ans;
//}
//void dfs(int cur, int son, int nson) {
//	//cout << "cur:" << cur << endl;
//	auto ls = lower_bound(a.begin() + 1, a.end(),cur, [](const array<int, 4>& seg, int val) {
//		return seg[0] < val;
//		});
//	if (ls == a.end())return;
//	int l = ls- a.begin();
//	if (a[l][0] > cur)return;
//	int r = upper_bound(a.begin() + 1, a.end(),cur, [](int val, const array<int, 4>& seg) {
//		return val < seg[0];
//		}) - a.begin();
//	for (int i = l; i < r; i++) {
//		if (a[i][1] == m) {
//			//cout << son * a[i][2] << " " << nson * (a[i][3] - a[i][2]) << "***\n";
//			pp.push_back({ (son * a[i][2]) % mod,(nson * (a[i][3] - a[i][2])) % mod });
//			continue;
//		}
//		else if (a[i][1] > m)continue;
//		dfs(a[i][1] + 1, (son * a[i][2]) % mod, (nson * (a[i][3] - a[i][2])) % mod);
//	}
//}
//signed main() {
//	cin >> n >> m;
//	int tson = 1, tmot = 1;a.resize(n + 1);
//	for (int i = 1, l, r, p, q; i <= n; i++) {
//		cin >> l >> r >> p >> q;
//		a[i] = { l,r,p,q };
//		tson = (tson * (q - p)) % mod;
//		tmot = (tmot * q) % mod;
//	}
//	sort(a.begin() + 1, a.end(), [&](auto x, auto y) {
//		if (x[0] == y[0]) {
//			return x[1] < y[1];
//		}
//		return x[0] < y[0];
//		});
//	dfs(1, 1, 1);
//	int ans = 0;
//	//cout << tson << endl;
//	//cout << tmot << endl;
//	for (int i = 0; i < pp.size(); i++) {
//		auto [son, nson] = pp[i];
//		ans = (ans + (tson * (qmi(tmot, mod - 2) * (son * qmi(nson, mod - 2)) % mod) % mod)%mod) % mod;
//	}
//	cout << ans << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 998244353;
//int qmi(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a % mod;
//		}
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ans;
//}
//
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	int tson = 1,tmot=1;
//	vector<vector<array<int,4>>>a(m+ 1);
//	for (int i = 1,l,r,p,q; i <= n; i++) {
//		cin >> l >> r >> p >> q;
//		a[r].push_back({ l,r,p,q });
//		tson = tson * (q - p) % mod;
//		tmot = tmot * q % mod;
//	}
//	vector<int>dp(m + 1);
//	dp[0] = 1;
//	for (int i = 1; i <= m; i++) {
//		for (auto [l, r, p, q] : a[i]) {
//			dp[i] = (dp[i] + dp[l - 1]%mod * qmi((q - p), mod - 2)%mod * p%mod)%mod;
//		}
//	}
//	cout << tson * qmi(tmot, mod - 2) % mod * dp[m]%mod << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 998244353;
//int qmi(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a % mod;
//		}
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ans;
//}
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<array<int, 4>>>a(m+1);
//	int tson = 1, tmot = 1;
//	for (int i = 1,l,r,p,q; i <= n; i++) {
//		cin >> l >> r >> p >> q;
//		a[l].push_back({ l,r,p,q });
//		tson = tson * (q - p) % mod;
//		tmot = tmot * q % mod;
//	}
//	vector<int>dp(m + 1);
//	dp[0] = 1;
//	for (int i = 0; i <= m-1; i++) {
//		if (dp[i] == 0)continue;
//		for (auto [l, r, p, q] : a[i+1]) {
//			dp[r] = (dp[r] + dp[i] * p % mod * qmi((q - p), mod - 2) % mod)%mod;
//		}
//	}
//	cout << tson * qmi(tmot, mod - 2)%mod * dp[m] % mod << endl;
//}