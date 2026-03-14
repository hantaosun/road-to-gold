//a、b、mod
//b|a b与mod互质 mod是质数 (a/b)%mod==(a*pow(b,mod-2,mod))%mod
//逆元的线性递推
//inv[1]=1;
//inv[i]=(int)(p-long(inv[p%i])*(p/i)%p);
//可用于处理组合数
//连续阶乘逆元的线性递推
//fac[i]代表i!在%mod下的余数
//inv[i]表示i!在%mod下的逆元
//inv[0]=1;
//从右往左递推
// inv[i]=(long(i+1)*(intv[i+1]))%mod
//int c(int n,int m) {
//	long ans = fac[n];
//	ans = (ans * inv[m]) % mod;
//	ans = (ans * inv[n - m]) % mod;
//	return (int)ans;
//}组合数

//逆元的线性递推
//#include<bits/stdc++.h>
//using namespace std;
//int inv[3000005];
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n, p;
//	cin >> n >> p;
//	inv[1] = 1;
//	for (int i = 2; i <= n; i++) {
//		inv[i] = (p - (long long)(inv[p % i]) * (p / i) % p);
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << inv[i] << "\n";
//	}
//}


//Comprime Subsequences
//#include<bits/stdc++.h>
//const int mod = 1e9 + 7;
//int a[100005];
//int power[100005];
//int dp[100005];
//using namespace std;
//int main() {
//	int n;
//	cin >> n;
//	power[0] = 1;
//	for (int i = 1,u; i <= n; i++) {
//		cin >> u;
//		power[i] = (power[i - 1] * 2)%mod;
//		a[u]++;
//	}
//	for (int i = 100005; i >= 1; i--) {
//		int cnt = 0;
//		for (int j = i; j <= 100005; j += i) {
//			cnt += a[j];
//		}
//		dp[i] = (power[cnt] + mod - 1) % mod;
//		for (int j = 2 * i; j <= 100005; j += i) {
//			dp[i] = (dp[i] - dp[j] + mod) % mod;
//		}
//	}
//	cout << dp[1] << endl;
//}


//硬币购物****
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int dp[100005];
//int c[4];
//int nc[4];
//int tar;
//int query() {
//	int ans = 0;
//	for (int s = 1; s <= 15; s++) {
//		int sign = -1;
//		int cur = 0;
//		for (int i = 0; i <= 3;i++) {
//			if (((s >> i) & 1) != 0) {
//				sign = -sign;
//				cur += (nc[i] + 1) * c[i];
//			}
//		}
//		ans += (tar - cur>= 0 ? dp[tar - cur] : 0) * sign;
//	}
//	return dp[tar]-ans;
//}
//signed main() {
//	int c1, c2, c3, c4, n;
//	cin >> c[0] >> c[1] >> c[2] >> c[3] >> n;
//	dp[0] = 1;
//	for (int j = 0; j < 4; j++) {
//		for (int i = c[j]; i<100005; i++) {
//			dp[i] += dp[i - c[j]];
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> nc[0] >> nc[1] >> nc[2] >> nc[3]>>tar;
//		cout << query() << endl;
//	}
//}