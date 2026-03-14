//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int a, b, x, y;
//	cin >> a >> b >> x >> y;
//	if (a == b) {
//		cout << 0 << endl;
//		return;
//	}
//	if (a > b ) {
//		if ((a ^ 1) != b) {
//			cout << -1 << endl;
//		}
//		else {
//			cout << y << endl;
//		}
//		return;
//	}
//	int ans = 0;
//	if (x <= y) {
//		cout << (b - a) *x << endl;
//		return;
//	}
//	while (a != b) {
//		if (a & 1) {
//			a += 1;
//			ans += x;
//		}
//		else {
//			a ^= 1;
//			ans += y;
//		}
//	}
//	cout << ans << endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//int dp[100][100];
//void solve() {
//	int n;
//	cin >> n;
//	vector<ll>a(n + 1);
//	ll px, py, qx, qy;
//	cin >> px >> py >> qx >> qy;
//	ll sum = 0;
//	ll ma = -1;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		sum += a[i];
//		ma = max(ma, a[i]);
//	}
//	ll mindis = sum>=ma*2?0:2*ma-sum;
//	if ((qx - px) * (qx - px) + (qy - py) * (qy - py) <= sum * sum 
//		&& (qx - px) * (qx - px) + (qy - py) * (qy - py) >= mindis*mindis) {
//		cout << "YES\n";
//	}
//	else {
//		cout << "NO\n";
//	}
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//int bits(ll x) {
//	int ans = 0;
//	while (x != 0) {
//		ans++;
//		x >>= 1;
//	}
//	return ans;
//}
//void solve() {
//	ll n, l, r, k;
//	cin >> n >> l >> r >> k;
//	//cout << bitset<64>(l) << "\n";
//	//cout << bitset<64>(r) << "\n";
//	if (n & 1) {
//		cout << l << endl;
//		return;
//	}
//	if (l == r||n==2) {
//		cout << -1 << endl;
//		return;
//	}
//	if (bits(r) == bits(l)) {
//		cout << -1 << endl;
//		return ;
//	}
//	if (bits(r) > bits(l)) {
//		if (k <= n - 2)cout << l<<endl;
//		else {
//			cout << ((ll)(1) << bits(l)) << endl;
//		}
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define i64 long long
//using namespace std;
//void solve() {
//	i64 n, m;
//	cin >> n >> m;
//	vector<vector<i64>>dp(n + 1, vector<i64>(n + 1, 0));
//	dp[n][0] = 1;
//	dp[n][1] = n;
//	for (int i = n-1; i >= 1; i--) {
//		for (int j = 0; j <= n - i + 1; j++) {
//			dp[i][j] = (dp[i][j] + dp[i + 1][j])%m;
//			if (j + 1 <= n - i + 1) {
//				dp[i][j + 1] = (dp[i][j + 1] + ((dp[i + 1][j] * (n - i + 1 - j)) % m * i)%m) % m;
//			}
//		}
//	}
//	i64 ans = 0;
//	for (int i = 0; i < dp[1].size(); i++) {
//		ans = (ans + dp[1][i]) % m;
//	}
//	cout << ans << endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}