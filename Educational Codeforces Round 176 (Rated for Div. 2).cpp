//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	if (n & 1) {
//		cout << 1 + (n - k+k-1-1) / (k - 1) << "\n";
//	}
//	else {
//		cout << ((n + k - 2) / (k - 1)) << "\n";
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
//#define int long long
//using namespace std;
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	if (k == 1) {
//		int mx = -1;
//		for (int i = 2; i <n; i++) {
//			mx = max(a[i], mx);
//		}
//		cout << max(a[1] + a[n], mx + max(a[1], a[n])) << '\n';
//		return;
//	}
//	sort(a.begin() + 1, a.end(), [&](int x, int y) {
//		return x > y;
//		});
//	int ans = 0;
//	for (int i = 1; i <= k + 1; i++) {
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
//#define int long long
//using namespace std;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(m + 1);
//	for (int i = 1; i <= m; i++) {
//		cin >> a[i];
//	}
//	sort(a.begin() + 1, a.end());
//	int ans = 0;
//	for (int i = 1; i < n; i++) {//左侧涂i格的方案数加起来
//		int it = m + 1 - (lower_bound(a.begin() + 1, a.end(), i) - a.begin());
//		int it1 = m + 1 - (lower_bound(a.begin() + 1, a.end(), n - i) - a.begin());
//		ans += it * it1;
//		ans -= i <= n - i ? it1 : it;
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
//#define int long long
//using namespace std;
////bool used[100];
//int f(int x) {
//	//cout << "x:" << x << '\n';
//	int ans = 0;
//	int sum = 0;
//	int i;
//	for (i = 1; sum + i <= x; i++) {
//		sum += i;
//		ans += 1ll << i;
//		//used[i] = true;
//	}
//	if (sum != x) {
//		for (int j = i-1; j >= i - (x - sum); j--) {
//			ans -= (1ll << j);
//			//used[i] = false;
//			ans += (1ll << (j + 1));
//			//used[i + 1] = true;
//		}
//	}
//	return ans;
//}
//void solve() {
//	//memset(used, 0, sizeof(used));
//	unsigned long long x, y;
//	cin >> x >> y;
//	bitset<100>a(x);
//	bitset<100>b(y);
//	int sa=-1,sb=-1;
//	for (int i = a.size()-1; i>=0; i--) {
//		if (a[i] != 0) {
//			sa = i;
//			break;
//		}
//	}
//	for (int i = b.size()-1; i>=0; i--) {
//		if (b[i] != 0) {
//			sb = i;
//			break;
//		}
//	}	
//	//if (sa == -1 && sb == -1) {
//	//	cout << 0 << '\n';
//	//	return;
//	//}
//	//if (sa == -1) {
//	//	cout << f(sb+1) << '\n';
//	//	return;
//	//}
//	//if (sb == -1) {
//	//	cout << f(sa+1) << '\n';
//	//	return;
//	//}
//	while (sa>=0&&sb>=0&&a[sa] == b[sb]) {
//		sa--;
//		sb--;
//	}
//	sa++;
//	sb++;
//	//cout << sa << " " << sb << " \n";
//	//cout << a << "\n" << b << "\n";
//	cout << f(sa+sb)<<"\n";
//	//for (int i = 1; i < 100; i++) {
//	//	if (used[i])cout << i << " ";
//	//}
//	//cout << "\n";
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
//const int inf = 1e17;
//int dp[150][128][128];
//void solve() {
//	int x, y;
//	cin >> x >> y;
//	int ans = LLONG_MAX;
//	for (int i = 0; i <= 64; i++) {
//		for (int j = 0; j <= 64; j++) {
//			//cout <<"("<< i << " " << j << " "<<dp[18][i][j] << ")  ";
//			if (x >> i == y >> j) {
//				ans = min(ans, dp[18][i][j]);
//			}
//		}
//		//cout << "\n";
//	}
//	cout << ans << '\n';
//}
//void prepare() {
//	for (int i = 0; i <= 64; i++) {
//		for (int j = 0; j <= 64; j++) {
//			for (int k = 0; k <= 64; k++) {
//				dp[i][j][k] = LLONG_MAX;
//			}
//		}
//	}
//	dp[0][0][0] = 0;
//	for (int i = 1; i <= 40; i++) {
//		for (int j = 0; j <= 64; j++) {
//			for (int k = 0; k <= 64; k++) {
//				dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
//			}
//		}
//		for (int j = 0; j <= 64; j++) {
//			for (int k = 0; k <= 64; k++) {
//				if (dp[i - 1][j][k] != LLONG_MAX) {
//					dp[i][j + i][k] = min(dp[i - 1][j][k] + (1ll << i), dp[i][j + i][k]);
//					dp[i][j][k + i] = min(dp[i - 1][j][k] + (1ll << i), dp[i][j][k + i]);
//				}
//			}
//		}
//	}
//}
//signed main() {
//	int t;
//	cin >> t;
//	prepare();
//	while (t--) {
//		solve();
//	}
//}