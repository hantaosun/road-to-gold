//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//void solve() {
//	int N, M;
//	cin >> N >> M;
//	vector<ll>mi(N+1);
//	vector<ll>ma(N+1);
//	for (int i = 1; i <= N; i++) {
//		cin >> mi[i];
//	}
//	for (int i = 1, u; i <= N; i++) {
//		cin >> ma[i];
//	}
//	ll down = 0;
//	ll pre = -1;
//	for (int i = 1; i <= N; i++) {
//		pre = max(pre, mi[i]);
//		down += pre;
//	}
//	ll up = 0;
//	pre = INT_MAX;
//	for (int i = N; i >= 1; i--) {
//		pre= min(pre, ma[i]);
//		up += pre;
//	}
//	if (down > M || M > up) {
//		cout << "NO\n";
//	}
//	else cout << "YES\n";
//}
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define pii pair<int,int>
//#define endl "\n"
//using namespace std;
//struct cmp {
//	bool operator()(pii&a,pii&b) {
//		return a.second > b.second;
//	}
//};
//void solve() {
//	int n;
//	cin >> n;
//	vector<vector<int>>a(n,vector<int>(2));
//	vector<int>lisan;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i][0] >> a[i][1];
//		lisan.emplace_back(a[i][0]);
//		lisan.emplace_back(a[i][1]);
//	}
//	sort(a.begin(), a.end(), [](vector<int>& a, vector<int>& b) {
//		return a[0] < b[0];
//		});
//	sort(lisan.begin(), lisan.end());
//	lisan.erase(unique(lisan.begin(), lisan.end()), lisan.end());
//	for (int i = 0; i < n; i++) {
//		a[i][0] = (lower_bound(lisan.begin(), lisan.end(), a[i][0]) - lisan.begin() + 1)*2-1;
//		a[i][1] = (lower_bound(lisan.begin(), lisan.end(), a[i][1]) - lisan.begin() + 1)*2-1;
//	}
//	int ans = 1;
//	int cnt = 0;
//	priority_queue<pii, vector<pii>, cmp>pq;
//	vector<int>suoyin(n + 5);
//	vector<int>lastad(n+5,-1);
//	int t = 0;
//	for (int r = 1,i=0; r <= int(lisan.size())*2-1; r++) {
//		bool flag = 0;
//		while (i<n&&a[i][0] <= r) {
//			pq.push(make_pair(++cnt,a[i][1]));
//			lastad[t]=cnt;
//			suoyin[cnt] = t++;
//			flag = 1;
//			i++;
//		}
//		while (!pq.empty()&&pq.top().second<r) {
//			while (t > 0 && lastad[r - 1] == -1) {
//				r--;
//			}
//			if (pq.top().first != lastad[r - 1]) {
//				flag = 1;
//				r--;
//				lastad[r] = -1;
//			}
//			pq.pop();
//		}
//		if (!pq.empty()&&flag)ans++;
//	}
//	cout << ans << endl;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}

//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//#define rep(i,m,n) for(ll i=(m); i<=(n); i++)
//#define gcd(i,j) __gcd(i,j)
//#define lownd lower_bound
//#define upnd upper_bound
//#define endl "\n"
//#define decimal(i) std::fixed << std::setprecision(i)
//
//const int inf = 2147483647;
//
//void solve()
//{
//    int n;
//    cin >> n;
//    string s;
//    cin >> s;
//    int c1 = 0, c2 = 0,c3=0,c4=0;
//    string s1 = s, s2 = s;//s1 101010 s2 010101
//    int ans;
//    for (int i = 0; i <= n - 1; i++)
//    {
//        int j = (i + 1) % n;
//        if (!(i & 1) && s1[i] == '0' && s1[j] == '1')swap(s1[i], s1[j]), c1++;
//        if ((i & 1) && s1[i] == '1' && s1[j] == '0')swap(s1[i], s1[j]), c1++;
//        if (!(i & 1) && s2[i] == '1' && s2[j] == '0')swap(s2[i], s2[j]), c2++;
//        if ((i & 1) && s2[i] == '0' && s2[j] == '1')swap(s2[i], s2[j]), c2++;
//    }
//    rep(i, 0, n - 1)
//    {
//        if ((i & 1) && s1[i] == '1')c1++;
//        if (!(i & 1) && s1[i] == '0')c1++;
//        if ((i & 1) && s2[i] == '0')c2++;
//        if (!(i & 1) && s2[i] == '1')c2++;
//    }
//    s1.resize(s.size());
//    for (int i = 0; i < n - 1; i++) {
//        s1[i] = s[i + 1];
//    }
//    s1[n - 1] = s[0];
//    s2 = s1;
//    for (int i = 0; i <= n - 1; i++)
//    {
//        int j = (i + 1) % n;
//        if (!(i & 1) && s1[i] == '0' && s1[j] == '1')swap(s1[i], s1[j]), c3++;
//        if ((i & 1) && s1[i] == '1' && s1[j] == '0')swap(s1[i], s1[j]), c3++;
//        if (!(i & 1) && s2[i] == '1' && s2[j] == '0')swap(s2[i], s2[j]), c4++;
//        if ((i & 1) && s2[i] == '0' && s2[j] == '1')swap(s2[i], s2[j]), c4++;
//    }
//    rep(i, 0, n - 1)
//    {
//        if ((i & 1) && s1[i] == '1')c3++;
//        if (!(i & 1) && s1[i] == '0')c3++;
//        if ((i & 1) && s2[i] == '0')c4++;
//        if (!(i & 1) && s2[i] == '1')c4++;
//    }
//    ans = min(min(c3,c4), min(c1, c2));
//    cout << ans << endl;
//    return;
//}
//
//
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int t = 1;
//    cin >> t;
//    while (t--)
//    {
//        solve();
//    }
//    return 0;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 1e9 + 7;
//void solve() {
//	int n;
//	cin >> n;
//	vector<vector<int>>a(n + 1,vector<int>(3));
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i][0] >> a[i][1] >> a[i][2];
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j < i; j++) {
//			ans = (ans + max(abs(a[i][0] - a[j][0]), abs(a[i][1] - a[j][1])) * (a[i][2] + a[j][2])) % mod;
//		}
//	}
//	cout << ans << endl;
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}



//#include<iostream>
//#include<vector>
//#define int long long
//#define pii pair<int,int>
//using namespace std;
//const int mod = 1e9 + 7;
//int qmi(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if ((b & 1)) {
//			ans = (ans * a)%mod;
//		}
//		a = (a * a)%mod;
//		b >>=1;
//	}
//	return ans;
//}
//int inv[200005];
//int fac[200005];
//int cnm(int n,int m) {
//	long ans = fac[n];
//	ans = (ans * inv[m]) % mod;
//	ans = (ans * inv[n - m]) % mod;
//	return (int)ans;
//}
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(n+5);
//	vector<int>p(n + 5);
//	vector<vector<pii>>line(n+1);//不同重合次数线段
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//		p[i] = 10 - p[i];
//	}
//	for (int i = 1,u,v; i <=m; i++) {
//		cin >> u >> v;
//		a[u] += 1;
//		a[v + 1] -= 1;
//	}
//	for (int i = 1; i <= n; i++) {
//		a[i] += a[i - 1];
//	}
//	int l = 1;
//	for (int i = 1; i <= n; i++) {
//		if (a[i] != a[l]) {
//			line[a[l]].push_back(make_pair(l, i - 1));
//			l = i;
//		}
//	}
//	int fp = 1;
//	for (int i = 1; i <= n; i++) {
//		for (auto pa : line[i]) {
//			for (int k = pa.first; k <= pa.second; k++) {
//				if (i & 1) {
//					fp = (fp * p[k]) % mod;
//				}
//				else fp = (fp * inv[p[k]]) % mod;
//			}
//		}
//	}
//	int ans = (qmi(10, n) - fp + mod) % mod;
//	ans = ans * qmi(inv[10], n) % mod;
//	cout << ans << endl;
//}
//signed main() {
//	int t;
//	cin >> t;
//	fac[1] = 1;
//	for (int i = 2; i <= 200000; i++) {
//		fac[i] = (fac[i - 1] * i) % mod;
//	}
//	inv[200000] = qmi(fac[200000], mod - 2);
//	for (int i = 199999; i >= 1; i--) {
//		inv[i] = (long long)(i + 1) * inv[i + 1] % mod;
//	}
//	while (t--) {
//		solve();
//	}
//
//}


//性质不同的数字
//#include<bits/stdc++.h>
//#define u64 unsigned long long
//using namespace std;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
//int n;
//void solve() {
//	cin >> n;
//	vector<pair<int, u64>>line;
//	for (int i = 0,l,r; i < n; i++) {
//		cin >> l >> r;
//		r++;//将区间变为左闭右开,因为l与r+1才是使状态改变的关键点
//		u64 s = rng();
//		line.push_back({ l, s });
//		line.push_back({ r,s });
//	}
//	sort(line.begin(),line.end());
//	int lst = -1;
//	u64 cur=0;
//	vector<u64>ans{0};
//	for (auto [i, x] : line) {
//		if (i > lst) {
//			ans.push_back(cur);
//		}
//		lst = i;
//		cur ^= x;
//	}
//	sort(ans.begin(), ans.end());
//	cout << unique(ans.begin(), ans.end()) - ans.begin()<<endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//
//#include<bits/stdc++.h>
//#define i64 long long
//using namespace std;
//int n;
//const int mod = 1e9 + 7;
//i64 qmi(i64 a, i64 b) {
//	i64 ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = (ans * a)%mod;
//		}
//		a = (a * a) % mod;
//		b >>= 1;
//	}
//	return ans;
//}
//int calculate(const vector<array<i64, 3>>& a) {
//	i64 preA = 0, preXY = 0, preAXY = 0;
//	i64 ans = 0;
//	for (i64 i = 1; i <= n; i++) {
//		const auto& node = a[i];
//		i64 p = node[2] % mod;  // p取模
//		i64 b = (node[0] - node[1]) % mod;  // 先算x-y的模
//		b = (b + mod) % mod;  // 正确非负化（关键修复）
//
//		i64 im1 = (i - 1) % mod;  // i-1取模
//
//		// 分步计算term1，避免溢出
//		i64 term1 = (b * im1) % mod;  // b*(i-1)
//		term1 = (p * term1) % mod;    // *p
//
//		// 计算term2：p*preXY，确保非负减法
//		i64 term2 = (p * preXY) % mod;
//		term2 = (mod - term2) % mod;
//
//		// 计算term3：b*preA
//		i64 term3 = (b * preA) % mod;
//
//		// 计算term4：-preAXY
//		i64 term4 = (mod - preAXY) % mod;
//
//		// 累加结果
//		ans = (ans + term1 + term2 + term3 + term4) % mod;
//
//		// 更新前缀和（b已非负，累加后取模也非负）
//		preA = (preA + p) % mod;
//		preXY = (preXY + b) % mod;
//		preAXY = (preAXY + (p * b) % mod) % mod;
//	}
//	return ans;
//}
//int calculate1(const vector<array<i64, 3>>& a) {
//	i64 preA=0, preXY=0, preAXY = 0;
//	i64 ans = 0;
//	for (i64 i = 1; i <= n; i++) {
//		const auto& node = a[i];
//		i64 p = node[2] % mod;  // p取模
//		i64 b = (node[0] + node[1]) % mod;  // 先算x-y的模
//		b = (b + mod) % mod;  // 正确非负化（关键修复）
//
//		i64 im1 = (i - 1) % mod;  // i-1取模
//
//		// 分步计算term1，避免溢出
//		i64 term1 = (b * im1) % mod;  // b*(i-1)
//		term1 = (p * term1) % mod;    // *p
//
//		// 计算term2：p*preXY，确保非负减法
//		i64 term2 = (p * preXY) % mod;
//		term2 = (mod - term2) % mod;
//
//		// 计算term3：b*preA
//		i64 term3 = (b * preA) % mod;
//
//		// 计算term4：-preAXY
//		i64 term4 = (mod - preAXY) % mod;
//
//		// 累加结果
//		ans = (ans + term1 + term2 + term3 + term4) % mod;//term1,2,3,4均已非负
//
//		// 更新前缀和（b已非负，累加后取模也非负）
//		preA = (preA + p) % mod;
//		preXY = (preXY + b) % mod;
//		preAXY = (preAXY + (p * b) % mod) % mod;
//	}
//	return ans;
//}
//void solve() {
//
//	cin >> n;
//	vector<array<i64, 3>>a(n+1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i][0] >> a[i][1] >> a[i][2];
//	}
//	i64 ans = 0;
//	sort(a.begin()+1, a.end(), [&](auto x, auto y) {
//		return x[0] - x[1] < y[0] - y[1];
//		});
//	ans = (ans + calculate(a))%mod;
//	sort(a.begin() + 1, a.end(), [&](auto x, auto y) {
//		return x[0] + x[1] < y[0] + y[1];
//		});
//	ans = (ans + calculate1(a))%mod;
//	cout << (ans * qmi(2, mod - 2))%mod << endl;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}

//#include <bits/stdc++.h>
//
//using i64 = long long;
//using u64 = unsigned long long;
//using u32 = unsigned;
//
//using u128 = unsigned __int128;
//using i128 = __int128;
//
//constexpr int P = 1000000007;
//
//int work(const std::vector<int>& x, const std::vector<int>& a) {
//	int ans = 0;
//	const int n = x.size();
//	std::vector<int> p(n);
//	std::iota(p.begin(), p.end(), 0);//可以对索引按某依据排序
//	std::sort(p.begin(), p.end(),
//		[&](int i, int j) {
//			return x[i] < x[j];
//		});
//
//	i64 sr = std::accumulate(a.begin(), a.end(), 0LL);
//	i64 sl = 0;
//	for (int i = 0; i + 1 < p.size(); i++) {
//		sl += a[p[i]];
//		sr -= a[p[i]];
//		ans = (ans + (sl % P * (n - 1 - i) + sr % P * (i + 1)) % P * (x[p[i + 1]] % P - x[p[i]] % P)) % P;
//	}
//	return ans;
//}
//
//void solve() {
//	int n;
//	std::cin >> n;
//
//	std::vector<int> x(n), y(n), a(n);
//	for (int i = 0; i < n; i++) {
//		std::cin >> x[i] >> y[i] >> a[i];
//		std::tie(x[i], y[i]) = std::make_pair(x[i] + y[i], x[i] - y[i]);
//	}
//
//	int ans = (work(x, a) + work(y, a)) % P;
//	if (ans < 0) {
//		ans += P;
//	}
//	ans = i64(ans) * (P + 1) / 2 % P;
//	std::cout << ans << "\n";
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int T;
//	std::cin >> T;
//
//	while (T--) {
//		solve();
//	}
//
//	return 0;
//}