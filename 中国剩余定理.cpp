//中国剩余定理
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int gcd(int a, int b) {
//	while (b != 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//int d, x, y, px, py;
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
//int mul(int a, int b, int mod) {
//	a = (a % mod + mod) % mod;
//	b = (b % mod + mod) % mod;
//	int ans = 0;
//	while (b != 0) {
//		if (b & 1) {
//			ans = (ans + a) % mod;
//		}
//		b >>= 1;
//		a = a + a % mod;
//	}
//	return ans;
//}
//signed main() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	vector<int>r(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i] >> r[i];
//	}
//	int lcm = 1;
//	for (int i = 1; i <= n; i++) {
//		lcm = lcm * a[i] / (gcd(lcm, a[i]));
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		exgcd(lcm/a[i], a[i]);
//		ans = (ans + mul(mul(r[i], lcm / a[i], lcm), x, lcm)) % lcm;
//	}
//	cout << ans << endl;
//}



//扩展中国定理
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int d, x, y, px, py;
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
//int mul(int a, int b, int mod) {
//	a = (a % mod + mod) % mod;
//	b = (b % mod + mod) % mod;
//	int ans = 0;
//	while (b != 0) {
//		if (b & 1) {
//			ans += a;
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
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i] >> r[i];
//	}
//	int lcm = 1, tail = 0, b, c,tmp,x0;
//	for (int i = 1; i <= n; i++) {
//		b = a[i];
//		c = ((r[i] - tail) % b + b) % b;
//		exgcd(lcm, b);
//		if (c % d != 0) {
//			cout<<-1<<'\n';
//		}
//		x0 = mul(x, c / d, b / d);//x0为最小非负特解%b/d就是为了得到非负特解
//		tmp = lcm * (b / d);//最新的最小公倍数
//		tail = (tail + mul(x0, lcm, tmp)) % tmp;//推导的得出的公式(将x0带入即可) %lcm防溢出
//		lcm = tmp;//更新lcm
//	}
//	cout << tail << '\n';
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int d, x, y, px, py;
//int gcd(int a, int b) {
//	while (b != 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//int Lcm(int a, int b) {
//	return a * b / gcd(a, b);
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
//int mul(int a, int b, int mod) {
//	a = (a % mod + mod) % mod;
//	b = (b % mod + mod) % mod;
//	int ans = 0;
//	while (b != 0) {
//		if (b & 1) {
//			ans = (ans + a) % mod;
//		}
//		b >>= 1;
//		a = (a + a) % mod;
//	}
//	return ans;
//}
//signed main() {
//	int k;
//	cin >> k;
//	vector<int>a(k + 1);
//	vector<int>r(k + 1);
//	int lcm = 1;
//	for (int i = 1; i <= k; i++) {
//		cin >> r[i];
//	}
//	for (int i = 1; i <= k; i++) {
//		cin >> a[i];
//		lcm = Lcm(lcm, a[i]);
//	}
//	int ans = 0;
//	for (int i = 1; i <= k; i++) {
//		exgcd(lcm / a[i], a[i]);
//		ans = (ans + mul(mul(r[i], lcm / a[i], lcm) ,x, lcm))%lcm;
//	}
//	cout << ans << '\n';
//}



//#include<bits/stdc++.h>
//#define ll long long
//#define int long long
//using namespace std;
//ll mul(ll a, ll b, int mod) {
//	a = (a % mod + mod) % mod;
//	b = (b % mod + mod) % mod;
//	ll ans = 0;
//	while (b != 0) {
//		if (b & 1) {
//			ans = (ans + a) % mod;
//		}
//		b >>= 1;
//		a = (a + a) % mod;
//	}
//	return ans;
//}
//int d, x, y, px, py;
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
//vector<int>hp;
//vector<int>recovery;
//vector<int>reward;
//vector<int>att;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	hp.resize(n + 1);
//	recovery.resize(n + 1);
//	reward.resize(n + 1);
//	att.resize(n + 1);
////对应的龙使用哪吧剑
//	multiset<int>init;
//	for (int i = 1; i <= n; i++) {
//		cin>>hp[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin>>recovery[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin>>reward[i];
//	}
//	for (int i = 1, u; i <= m; i++) {
//		cin>>u;
//		init.insert(u);
//	}	
//	int ma = INT_MIN;
//	for (int i = 1; i <= n; i++) {
//		auto it = upper_bound(init.begin(), init.end(), hp[i]);
//		if (it != init.begin()) {
//			it--;
//		}
//		att[i] = *it;
//		init.erase(it);
//		init.insert(reward[i]);		
//		ma = max(ma, (hp[i] + att[i] - 1) / att[i]);
//		hp[i] = hp[i] % recovery[i];
//	}
//	ll lcm = 1, tail = 0,tmp, a, b, c, x0;
//	for (int i = 1; i <= n; i++) {
//		a = mul(lcm, att[i], recovery[i]);
//		b = recovery[i];
//		c = (hp[i] - mul(tail, att[i], b) + b) % b;
//		exgcd(a, b);
//		if (c % d != 0) {
//			cout << -1 << '\n';
//			return;
//		}
//		x0 = mul(x, c / d, b / d);
//		tmp = lcm * b / d;
//		tail = (tail + mul(x0, lcm, tmp)) % tmp;
//		lcm = tmp;
//	}
//	ll ans = (ma - tail + lcm - 1) / lcm * lcm + tail;
//	cout << max(tail, ans) << '\n';
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


