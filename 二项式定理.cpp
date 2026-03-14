//#include<bits/stdc++.h>
//using namespace std;
//int dp[30][30];
//int main() {
//	int n;
//	cin >> n;
//	dp[0][1] = 1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= i; j++) {
//			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]; \
//				cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 10007;
//int dp[1001][1001];
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
//signed main() {
//	int a, b, k, n, m;
//	cin >> a >> b >> k >> n >> m;
//	dp[0][0] = 1;
//	for (int i = 1; i <= k; i++) {
//		dp[i][0] = 1;
//	}
//	for (int i = 1; i <= k; i++) {
//		for (int j = 1; j <= i; j++) {
//			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1])%mod;
//		}
//	}
//	cout << dp[k][n] * qpow(b, m) % mod * qpow(a, n) % mod << '\n';
//}


//#include<bits/stdc++.h>
//using namespace std;
//int k;
//int dp[2001][2001];
//int presum[2001][2001];
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	if (k == 1) {
//		cout << n * (n - 1) / 2 + m << '\n';
//	}
//	else {
//		cout << presum[n][min(n,m)] << '\n';
//	}
//}
//
//int main() {
//	int t,k;
//	cin >> t>>k;
//	for (int i = 0; i < 2001; i++) {
//		dp[i][0] = 1;
//	}
//	for (int i = 1; i <= 2000; i++) {
//		for (int j = 1; j <=i; j++) {
//			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % k;
//		}
//	}
//	//for (int i = 0; i <= 20; i++) {
//	//	for (int j = 0; j <= i; j++) {
//	//		cout << dp[i][j];
//	//	}
//	//	cout << endl;
//	//}
//	for (int i = 1; i <= 2000; i++) {
//		for (int j = 1; j <=i; j++) {
//			presum[i][j] = (dp[i][j] == 0) + presum[i][j - 1]+ (j<=i-1?presum[i - 1][j]- presum[i - 1][j - 1]:0);
//		}
//	}
//	while (t--) {
//		solve();
//	}
//}