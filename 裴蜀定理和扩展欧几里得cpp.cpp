//斐蜀定理
//#include<bits/stdc++.h>
//using namespace std;
//int gcd(int a, int b) {
//	while (b != 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//int main() {
//	int n;
//	cin >> n;
//	int ans;
//	cin >> ans;
//	ans = abs(ans);
//	for (int i = 2, u; i <= n; i++) {
//		cin >> u;
//		ans = gcd(ans, abs(u));
//	}
//	cout << ans << endl;
//}


//修复古塔
//#include<bits/stdc++.h>
//using namespace std;
//int gcd(int a, int b) {
//	while (b != 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//void solve(int id) {
//	int n,a,b;
//	cin >> n >> a >> b;
//	int cnt = 0,g=gcd(a,b);
//	for (int i = 1; i <= n; i++) {
//		if (i % g == 0) {
//			cnt++;
//		}
//	}
//	cout << "Case #" << id << ": ";
//	if (cnt & 1) {
//		cout << "Yuwgna\n";
//	}
//	else cout << "Iaka\n";
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	for (int i = 1; i <= t; i++) {
//		solve(i);
//	}
//}


//随机数生成器
//#include<bits/stdc++.h>
//using namespace std;
//int gcd(int a, int b) {
//	while (b != 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//int main() {
//	int step, mod;
//	while (cin >> step >> mod) {
//		if (gcd(step, mod) == 1) {
//			cout <<setw(10)<<step<<setw(10)<<mod << "    Good Choice\n";
//		
//		}
//		else {
//			cout << setw(10) << step << setw(10) << mod << "    Bad Choice\n";
//		}
//	}
//}


//同余方程
//#include<bits/stdc++.h>
//using namespace std;
//int d, x, y, px, py;
//void exgcd(int a, int b) {
//	if (b==0) {
//		d = a;
//		x = 1;//最后系数是1*a+0*b=d;
//		y = 0;
//	}
//	else {
//		exgcd(b, a % b);
//		px = x;//将前一步得到你的系数记入临时变量中
//		py = y;
//		x = py;//下一步的a就是这一步的b
//		y = px - py * (a / b);//推导得出这一步系数与下一步的关系
//	}
//}//此题保证a,b互质所以得到的a的系数就是a在%b意义下的逆元,b的系数同样
//int main() {
//	int a, b;
//	cin >> a >> b;
//	exgcd(a, b);
//	cout << (x % b + b)%b << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int d, x, y, px, py;
//int mul(int a, int b, int mod) {
//	int ans = 0;
//	while (b != 0) {
//		if (b & 1) {
//			ans = (ans + a) % mod;
//		}
//		a = (a + a) % mod;//不能直接左移，会溢出
//		b >>= 1;
//	}
//	return ans;
//}
//void exgcd(int a, int b) {
//	if (b == 0) {
//		d = a;
//		x = 1;
//		y = 0;
//	}
//	else {
//		exgcd(b, a % b);
//		px = x;
//		py = y;
//		x = py;
//		y = px - py * (a / b);
//	}
//}
//int qpow(int a,int b,int mod) {
//	int ans = 1;
//	while (b!=0) {
//		if (b & 1) {
//			ans = mul(ans , a , mod);
//		}
//		a = mul(a, a,mod);
//		b >>= 1;
//	}
//	return ans;
//}
//signed main() {
//	int n, m, l;
//	cin >> n >> m >> l;
//	int mod = n + 1;
//	exgcd(qpow(2,m,mod), mod);
//	cout << mul((x % mod + mod) % mod,l,mod) << '\n';
//}