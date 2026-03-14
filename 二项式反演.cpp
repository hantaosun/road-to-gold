//全错排
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//signed main() {
//	int n;
//	cin >> n;
//	int facn = 1;
//	for (int i = 1; i <=n; i++) {
//		facn = i * facn;
//	}
//	int ans = facn;
//	int faci = 1;
//	for (int i = 1; i <= n; i++) {
//		faci = faci * i;
//		if (i & 1) {
//			ans -= facn / faci;
//		}
//		else {
//			ans += facn / faci;
//		}
//	}
//	cout << ans << endl;
//}


//集合计数
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e6 + 5;
//const int mod = 1e9 + 7;
//int g[N];
//int finv[N];
//int fac[N];
//int qpow(int a,int b) {
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
//int C(int n, int m) {
//	return fac[n] * finv[n - m]%mod * finv[m] % mod;
//}
//void prepare(int n) {
//	fac[0] = 1;
//	finv[0] = 1;
//	for (int i = 1; i <= n; i++) {
//		fac[i] = i * fac[i - 1]%mod;
//	}
//	finv[n] = qpow(fac[n], mod - 2);
//	for (int i = n - 1; i >= 1; i--) {
//		finv[i] = finv[i + 1] * (i + 1)%mod;
//	}
//	g[n] = 2;
//	for (int i = n-1; i >=0; i--) {
//		g[i] = g[i + 1] * g[i + 1] % mod;
//	}
//	for (int i = 0; i <= n; i++) {
//		g[i] = (g[i] + mod - 1) % mod * C(n, i) % mod;
//	}
//	
//}
//int calculate(int n,int k) {
//	int ans = 0;
//	for (int i = k; i <= n; i++) {
//		if ((i - k) & 1) {
//			ans = (ans + (mod - 1)* C(i, k)%mod * g[i]%mod) % mod;//不要写减号因为+一个mod不一定能加正,乘以与-1同余的mod-1即可
//		}
//		else {
//			ans = (ans + C(i, k) * g[i])%mod;
//		}
//	}
//	return (ans + mod)%mod;
//}
//signed main() {
//	int n, k;
//	cin >> n >> k;
//	prepare(n);
//	cout << calculate(n,k) << '\n';
//}


//分特产
//O(n2)规模使用预处理组合数可能更好
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e3 + 5;
//const int mod = 1e9 + 7;
//int g[N << 1];
//int finv[N << 1];
//int fac[N << 1];
//vector<int>item;
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
//int C(int n, int m) {
//	return fac[n] * finv[n - m] % mod * finv[m] % mod;
//}
//void prepare(int n, int m) {
//	fac[0] = 1;
//	finv[0] = 1;
//	for (int i = 1; i <= 2000; i++) {
//		fac[i] = fac[i - 1] * i % mod;
//	}
//	finv[2000] = qpow(fac[2000], mod - 2);
//	for (int i = 1999; i >= 1; i--) {
//		finv[i] = finv[i + 1] * (i + 1) % mod;
//	}
//	g[n] = 0;
//	for (int i = 0; i < n; i++) {
//		g[i] = C(n,i);
//		for (int j = 1; j <= m; j++) {
//			g[i] = g[i] * C(item[j] + n - i - 1, n - i - 1) % mod;
//		}
//	}
//}
//int calculate(int n) {
//	int ans = 0;
//	for (int i = 0; i <= n; i++) {
//		if (i & 1) {
//			ans = (ans + (mod - 1) * g[i] % mod) % mod;
//		}
//		else {
//			ans = (ans + g[i]) % mod;
//		}
//	}
//	return ans;
//}
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	item.resize(m + 1);
//	for (int i = 1; i <= m; i++) {
//		cin >> item[i];
//	}
//	prepare(n, m);
//	cout << calculate(n) << '\n';
//}



//已经没有什么好害怕的了
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2005;
//const int mod = 1e9 + 9;
//vector<int>candy;
//vector<int>pill;
//int C[N][N];
//int dp[N][N];//前i个糖果里选j个形成糖果大的方案数
//int sma[N];//有几个药片比这个糖果小
//int g[N];
//int fac[N];
//void prepare(int n,int k) {
//	fac[0] = 1;
//	for (int i = 1; i <= n; i++) {
//		fac[i]=fac[i-1]*i%mod;
//	}
//	for (int i = 0; i <= n; i++) {
//		C[i][0] = 1;
//		for (int j = 1; j <= i; j++) {
//			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		sma[i] = lower_bound(pill.begin() + 1, pill.begin() + n + 1, candy[i]) - (pill.begin() + 1);
//	}
//	dp[0][0] = 1;
//	for (int i = 1; i <= n; i++) {
//		dp[i][0] = dp[i - 1][0];
//		for (int j = 1; j <= i; j++) {
//			long long t = 0;
//			if (sma[i] >= j - 1) {
//				t = (long long)dp[i - 1][j - 1] * (sma[i] - (j - 1)) % mod;
//			}
//			dp[i][j] = (dp[i - 1][j] + t) % mod;
//		}
//	}
//	for (int i = 0; i <= n; i++) {
//		g[i] = dp[n][i] * fac[n - i] % mod;
//	}
//}
//int calculate(int n, int k) {
//	int ans = 0;
//	int tar = (n + k) / 2;
//	for (int i = tar; i <= n; i++) {
//		long long t = (long long)C[i][tar] * g[i] % mod;
//		if ((i - tar) % 2 == 0) {
//			ans = (ans + t) % mod;
//		}
//		else {
//			ans = (ans - t + mod) % mod;
//		}
//	}
//	ans = (ans % mod + mod) % mod;
//	return ans;
//}
//signed main() {
//	int n, k;
//	cin >> n >> k;
//	
//	candy.resize(n + 1);
//	pill.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> candy[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> pill[i];
//	}
//	if ((n - k) % 2 != 0) {
//		cout << 0 << endl;
//		return 0;
//	}
//	sort(candy.begin()+1, candy.end());
//	sort(pill.begin()+1, pill.end());
//	prepare(n,k);
//	cout << calculate(n, k) << '\n';
//}