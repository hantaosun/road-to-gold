//扩展欧几里得
//int d,x, y,px,py;//px py是临时变量
//void exgcd(int a, int b) {//a和b保证没有负数
//	if (b == 0) {
//		d = a;
//		x = 1; y = 0;
//	}
//	else {
//		exgcd(b, a % b);
//		px = x;
//		py = y;
//		x = py;//对应b(把py看作b,px看作a)
//		y = px - py * (a / b);//对应a%b
//		//x,y表示最大公因数d是由xa+yb得到的
//		//px,py是b,a%b的表示
//	}
//}
//若a,b互质,则exgcd后x是a在模b意义下的逆元，不严格要求a或b是质数
// 
// 
//ax + by = d; d = gcd(a, b);
//x0, y0为一组特解
//则通解
//x = x0 + (b / d) * n;
//y = y - (a / d) * n;
//
//ax + by = c; c为d的整数倍
//x0’ = x0 * (c / d), y0’ = y0 * (c / d);
//x = x0’ + (b / d) * n;
//y = y0’ + (a / d) * n;
//
// 
// 中国剩余定理
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int x, y,d, px, py;
//void exgcd(int a, int b) {
//	if (b == 0) {
//		d = a;
//		x = 1, y = 0;
//	}
//	else {
//		exgcd(b, a % b);
//		px = x;
//		py = y;
//		x = py;
//		y = px - py * (a / b);
//	}
//}
//int gcd(int a, int b) {
//	while (b != 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//int mul(int a, int b, int mod) {
//	a = (a % mod + mod) % mod;//注意扩展欧几里得可能算出负数结果
//	b = (b % mod + mod) % mod;
//	int ans = 0;
//	while (b != 0) {
//		if (b & 1) {
//			ans = (ans + a)%mod;
//		}
//		b >>= 1;
//		a = (a + a) % mod;
//	}
//	return ans;
//}
//signed main() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	vector<int>r(n + 1);
//	int lcm = 1;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i]>>r[i];
//		lcm *= a[i];
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		int ai = lcm / a[i];
//		exgcd(ai, a[i]);
//		ans = (ans + mul(r[i], mul(ai, x, lcm), lcm))%lcm;
//	}
//	cout << ans%lcm<< "\n";
//}
//扩展中国剩余定理
//逐步推导扩展即可，每步%当前lcm
//二项式反演
