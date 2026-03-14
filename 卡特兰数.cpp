//卡特兰数公式
//f(n) = C(2n, n) - C(2n, n - 1);阶乘余数表,阶乘逆元表
//f(n) = C(2n, n) / (n + 1);阶乘余数表,阶乘逆元表
//f(n) = f(n - 1) * (4n - 2) / (n + 1);连续数逆元表
//f(n) = 对i从0-n-1求和f(i)*f(n-1-i);//不需要表,简单的加法乘法同余
//进出栈
//#include<bits/stdc++.h>
//using namespace std;
//int catalan[20];
//int main() {
//	int n;
//	cin >> n;
//	catlan[0] = 1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j < i; j++) {
//			catalan[i] += catalan[j] * catalan[i - j - 1];
//		}
//	}
//	cout << catalan[n];
//}

//四个计算函数
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 1e8 + 7;
//const int N = 3002;
//int finv[N << 1];
//int inv[N << 1];
//int fac[N << 1];
//int c[N << 1][N << 1];
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
//	return fac[n] * finv[m] % mod * finv[n - m]%mod;
//}
//void prepare(int n) {
//	fac[0] = 1;
//	finv[0] = 1;
//	for (int i = 1; i <= n; i++) {
//		fac[i] = fac[i - 1] * i%mod;
//	}
//	finv[n] = qpow(fac[n], mod - 2);
//	for (int i = n - 1; i >= 1; i--) {
//		finv[i] = finv[i + 1] * (i + 1) % mod;
//	}
//	for (int i = 0; i <= n; i++) {
//		c[i][0] = 1;
//		for (int j = 1; j <= i; j++) {
//			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
//		}
//	}
//	inv[1] = 1;
//	for (int i = 2; i <= n + 1; i++) {
//		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
//	}
//}
//int compute1(int n) {
//	prepare(2 * n);
//	return (C(2 * n, n) - C(2 * n, n - 1) + mod) % mod;
//}
//int compute2(int n) {
//	prepare(2 * n);
//	return C(2 * n, n) * qpow(n + 1, mod - 2) % mod;
//}
//int compute3(int n) {
//	if (n == 0 || n == 1)return 1;
//	prepare(n);
//	int pre = 1;
//	for (int i = 2; i <= n; i++) {
//		pre = pre * (4 * i - 2) % mod * inv[i + 1] % mod;
//	}
//	return pre;
//}
//int compute4(int n) {
//	vector<int>catalan(n + 1);
//	catalan[0] = 1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j < i; j++) {
//			catalan[i] = (catalan[i] + catalan[j] * catalan[i - j - 1]%mod) % mod;
//		}
//	}
//	return catalan[n];
//}
//signed main() {
//	int n;
//	cin >> n;
//	cout << compute4(n) << '\n';
//}


//因子计数法
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int mod;
//int n;
//int spf[2000005];
//int prime[2000005];
//int cont[2000005];
//int cnt = 0;
//void eular(int n) {
//	for (int i = 2; i <= n; i++) {
//		if (spf[i] == 0) {
//			prime[cnt++] = i;
//		}
//		for (int j = 0; j < cnt; j++) {
//			if (i * prime[j] > n)break;
//			spf[i * prime[j]] = prime[j];
//			if (i % prime[j]==0)break;
//		}
//	}
//}
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
//	cin >> n >> mod;
//	memset(spf, 0, sizeof(spf));
//	eular(2 * n);
//	for (int i = 2; i <= n; i++) {
//		cont[i] = -1;
//	}
//	for (int i = n + 2; i <= 2 * n; i++) {
//		cont[i] = 1;
//	}
//	for (int i = 2 * n; i >= 2; i--) {
//		if (spf[i] != 0) {
//			cont[spf[i]]+=cont[i];
//			cont[i / spf[i]] += cont[i];
//			cont[i] = 0;
//		}
//	}
//	int ans = 1;
//	for (int i = 2; i <= 2*n; i++) {
//		if (cont[i] != 0) {
//			ans = ans * qpow(i, cont[i])%mod;
//		}
//	}
//	cout << ans << '\n';
//}




//生成字符串
//用网格路径分析
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e6 + 10;
//const int mod = 20100403;
//int fac[N << 1];
//int finv[N << 1];
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
//void prepare(int n) {
//	fac[0] = 1;
//	finv[0] = 1;
//	for (int i = 1; i <= n; i++) {
//		fac[i] = fac[i - 1] * i % mod;
//	}
//	finv[n] = qpow(fac[n], mod - 2);
//	for (int i = n - 1; i >= 1; i--) {
//		finv[i] = finv[i + 1] * (i + 1) % mod;
//	}
//}
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	prepare(n + m);
//	cout << (C(m + n, m) - C(m + n, m - 1) + mod) % mod << '\n';
//}



//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	double n;
//	cin >> n;
//	cout << fixed << setprecision(9) << n * (n + 1) / ((2 * n - 1) * 2) << '\n';
//}