//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(m+1);
//	for (int i = 1; i <= m; i++) {
//		cin >> a[i];
//	}
//	for (int i = 2; i <= m; i++) {
//		if (a[i] <= a[i - 1]) {
//			cout << 1 << '\n';
//			return;
//		}
//	}
//	int mx = a[m];
//	cout << n - mx + 1<<'\n';
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	string s;
//	cin >> s;
//	set<int>a;
//	for (int i = 1,u; i <= m; i++) {
//		cin >> u;
//		a.insert(u);
//	}
//	vector<int>tmp;
//	s = " " + s;
//	int cur = 1;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == 'A') {
//			cur = cur + 1;
//			tmp.push_back(cur);
//		}
//		if (s[i] == 'B') {
//			int j = cur+1;
//			while (a.count(j)) {
//				j++;
//			}
//			tmp.push_back(j);
//			j = j + 1;
//			while (a.count(j)) {
//				j++;
//			}
//			cur = j;
//		}
//	}
//	for (auto v : tmp) {
//		a.insert(v);
//	}
//	cout << a.size() << '\n';
//	for (auto v : a) {
//		cout << v << " ";
//	}cout << '\n';
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
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(2*n + 1);
//	for (int i = 1; i <= 2 * n; i++) {
//		cin >> a[i];
//	}
//	int p1 = 0;
//	int p2 = 0;
//	for (int i = 2; i <= 2*n; i+=2) {
//		p1 += a[i] - a[i-1];
//	}
//	for (int i = 3; i <= 2*n; i += 2) {
//		p2 += a[i] - a[i - 1];
//	}
//	int sum = 0;
//	cout << p1 << ' ';
//	for (int i = 2; i <= n; i++) {
//		sum += a[2*n + 2 - i] - a[i-1];
//		if (i & 1) { 
//			cout << sum + p1 << ' ';
//			p2 -= a[i] - a[i-1] + a[2*n + 2 - i] - a[2*n+1- i];
//		}
//		else {
//			cout << sum + p2 << ' ';
//			p1 -= a[i] - a[i-1] + a[2*n + 2 - i] - a[2*n +1- i];
//		}
//		//cout << ans << ' ';
//	}
//	cout << '\n';
//}
//signed main() {
//	int t;
//	cin >> t;
//	//cout<< 910238130+913669539+ 36124499 +43993239-(6149048+26582657+ 813829899+860114890)<<"
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 998244353;
//const int N = 2e5 + 5;
//int fac[N];
//int finv[N];
//int qpow(int a, int b) {
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
//int C(int n, int m) {
//	return fac[n] * finv[m]%mod * finv[n - m]%mod;
//}
//void prepare(){
//	finv[0] = 1;
//	fac[0] = 1;
//	for (int i = 1; i < N; i++) {
//		fac[i] = fac[i - 1] * i % mod;
//	}
//	finv[N - 1] = qpow(fac[N - 1], mod - 2);
//	for (int i = N - 2; i >= 1; i--) {
//		finv[i] = finv[i + 1] * (i + 1) % mod;
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		sum += a[i];
//	}
//	if (sum != n) {
//		cout << 0 << '\n';
//		return;
//	}
//	int ans = 1;
//	for (int i = n; i > (n + 1) /2 ; i--) {
//		if (a[i] != 0) {
//			cout << 0 << '\n';
//			return;
//		}
//	}
//	sum = 0;
//	for (int i = (n + 1) / 2,x=0; i >= 1; i--,x++) {
//		if (a[i] == 0) {
//			continue;
//		}
//		int r, l;
//		if (n & 1) {
//			r = (n + 1) / 2 + x;
//			l = (n + 1) / 2 - x;
//		}
//		else {
//			l = (n + 1) / 2-x;
//			r = (n + 1) / 2 + x + 1;
//		}
//		if (a[i] > r - l - sum + 1) {
//			cout << 0 << '\n';
//			return;
//		}
//		ans = ans * C(r - l-sum + 1, a[i]) % mod;
//		sum += a[i];
//	}
//	cout << ans << "\n";
//}
//signed main() {
//	prepare();
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int dp[N];//alice一定要拿第i个物品能获得的最大价值
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>v(n + 1);
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> v[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//
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
//const int N = 2e5 + 5;
//int mx[N << 2];
//int lzt[N << 2];
//void up(int i) {
//	mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
//}
//void lazy(int i, int v) {
//	mx[i] += v;
//	lzt[i] += v;
//}
//void down(int i) {
//	if (lzt[i] != 0) {
//		lazy(i << 1, lzt[i]);
//		lazy(i << 1|1, lzt[i]);
//		lzt[i] = 0;
//	}
//}
//void add(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v);
//		return;
//	}
//	int mid = l + r >> 1;
//	down(i);
//	if (jl <= mid) {
//		add(jl, jr, v, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		add(jl, jr, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//void upd(int x, int v, int l, int r, int i) {
//	if (l == r) {
//		mx[i] = max(mx[i],v);
//		return;
//	}
//	int mid = l + r >> 1;
//	down(i);
//	if (x <= mid) {
//		upd(x, v, l, mid, i << 1);
//	}
//	else {
//		upd(x, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//int queryMax(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return mx[i];
//	}
//	int ans = LLONG_MIN;
//	int mid = l + r >> 1;
//	down(i);
//	if (jl <= mid) {
//		ans = max(ans, queryMax(jl, jr, l, mid, i << 1));
//	}
//	if (jr > mid) {
//		ans = max(ans, queryMax(jl, jr, mid + 1, r, i << 1 | 1));
//	}
//	return ans;
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		mx[i] = 0;
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid+1, r, i << 1|1);
//		up(i);
//	}
//	lzt[i] = 0;
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>v(n + 1);
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	vector<int>pos(n + 1);
//	build(1, n+1, 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> v[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//		pos[b[i]] = i;
//	}
//	vector<int>dp(n + 1,0);
//	for (int i = 1; i <= n; i++) {
//		int p = pos[a[i]];
//		upd(p+1,queryMax(1, p, 1, n+1, 1), 1, n+1, 1);
//		add(1, p, v[a[i]], 1, n+1, 1);
//	}
//	cout << queryMax(1, n+1, 1, n+1, 1) << '\n';
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}