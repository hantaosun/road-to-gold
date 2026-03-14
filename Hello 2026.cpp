//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	int c1 = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		c1 += a[i];
//	}
//	if (c1 == n) {
//		cout << "Alice\n";
//		return;
//	}
//	if (c1 == 0) {
//		cout << "Bob\n";
//		return;
//	}
//	if (a[1] == 0 && a[n] == 0) {
//		cout << "Bob\n";
//		return;
//	}
//	cout << "Alice\n";
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
//	int n,k;
//	cin >> n >> k;
//	set<int>st;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		st.insert(a[i]);
//	}
//	for (int i = 0; i < k; i++) {
//		if (!st.count(i)) {
//			cout << i << endl;
//			return;
//		}
//	}
//	cout << k-1 << endl;
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
//int n, m, k;
//bool check(int mid) {
//	mid--;
//	int ll = k - 1;
//	int rr = n - k;
//	if (ll <= mid / 2) {
//		rr = mid - ll;
//	}
//	else if (rr <= mid / 2) {
//		ll = mid - rr;
//	}
//	else {
//		ll = mid / 2;
//		rr = mid - ll;
//	}
//
//	int mn = min(ll, rr), mx = max(ll, rr);
//	int nd = mn * 2 - 1 + mx * 2 - 1 - mn + 1;
//	//cout <<mid<<" "<< mn << " " << mx << " " << nd << endl;
//	return nd <= m;
//}
//void solve() {
//
//	cin >> n >> m >> k;
//	int ans = 1;
//	int l = 1, r = n;
//	while (l <= r) {
//		int mid = l + r >> 1;
//		if (check(mid)) {
//			ans = mid;
//			l = mid + 1;
//		}
//		else {
//			r = mid - 1;
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



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//vector<vector<int>>g;
//int dep[N];
//int cnt[N];
//int fa[N];
//
//int mxdep = 1;
//void dfs(int u, int pa) {
//	dep[u] = dep[pa] + 1;
//	cnt[dep[u]]++;
//	mxdep = max(mxdep, dep[u]);
//	for (auto v : g[u]) {
//		if (v == pa)continue;
//		dfs(v, u);
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	g.assign(n + 1, {});
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	dep[0] = 0;
//	mxdep = 1;
//	int mxdrg = g[1].size();
//	for (int i = 2; i <= n; i++) {
//		mxdrg = max(mxdrg, (int)g[i].size() - 1);
//	}
//	dfs(1, 0);
//	int ans = 0;
//	for (int i = 1; i <= mxdep;i++) {
//		ans = max(ans, cnt[i]);
//	}
//	if (mxdrg == ans) {
//		cout << ans + 1 << "\n";
//	}
//	else {
//		cout << ans << "\n";
//	}
//	for (int i = 1; i <= mxdep;i++) {
//		cnt[i] = 0;
//	}
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
//const int N = 2e5 + 5;
//vector<vector<int>>g;
//int dep[N];
//int cnt[N];
//int fa[N];
//int mxdep = 1;
//void dfs(int u, int pa) {
//	dep[u] = dep[pa] + 1;
//	cnt[dep[u]]++;
//	fa[u] = pa;
//	mxdep = max(mxdep, dep[u]);
//	for (auto v : g[u]) {
//		if (v == pa)continue;
//		dfs(v, u);
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	g.assign(n + 1, {});
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	dep[0] = 0;
//	mxdep = 1;
//	int mxdrg = g[1].size();
//	for (int i = 2; i <= n; i++) {
//		mxdrg = max(mxdrg, (int)g[i].size() - 1);
//	}
//	dfs(1, 0);
//	int ans = 0;
//	for (int i = 1; i <= mxdep; i++) {
//		ans = max(ans, cnt[i]);
//	}
//	if (mxdrg == ans) {
//		cout << ans + 1 << "\n";
//	}
//	else {
//		cout << ans << "\n";
//	}
//	vector<set<int>>adep(mxdep + 1);
//	vector<vector<int>>op;
//	for (int i = 1; i <= n; i++) {
//		adep[dep[i]].insert(i);
//	}
//	int tdep = -1;
//	vector<int>bind(n + 1);
//	for (int i = 1; i <= mxdep; i++) {
//		if (cnt[i] == ans) {
//			tdep = i;
//			break;
//		}
//	}
//	for (int i = 1; i <= mxdep; i++) {
//		if (cnt[i] == ans &&i > 1) {
//			for (auto u : adep[i]) {
//				for (auto v : adep[i - 1]) {
//					if (!bind[v]&&fa[u]!=v) {
//						bind[v] = u;
//						bind[u] = v;
//						break;
//					}
//				}
//			}
//		}
//	}
//	vector<int>tmp;
//	for (int o = 1; o <= ans; o++) {
//		int lc = -1, lcp = -1;
//		for (int i = 1; i <= mxdep; i++) {
//			if (i <= lc)continue;
//			if (adep[i].empty())continue;
//			int got = 0;
//			for (auto v : adep[i]) {
//				if (fa[v] != lcp && fa[bind[v]] != lcp) {
//					lc = i;
//					lcp = v;
//					tmp.push_back(v);
//					got = v;
//					int bv = bind[v];
//					if (bv && adep[dep[bv]].count(bv)) {
//						lc = max(dep[v], dep[bv]);
//						lcp = dep[v] > dep[bv] ? v : bv;
//						tmp.push_back(bv);
//						adep[dep[bv]].erase(bv);
//					}
//					break;
//				}
//			}
//			if (got) {
//				adep[i].erase(got);
//			}
//
//		}
//		cout << tmp.size() << " ";
//		for (auto v : tmp) {
//			cout << v << " ";
//		}
//		tmp.clear();
//		cout << endl;
//	}
//	adep[tdep].clear();
//	if (mxdrg == ans) {
//		for (int i = 1; i <= mxdep; i++) {
//			for (auto v : adep[i]) {
//				tmp.push_back(v);
//				int bv = bind[v];
//				if (bv && dep[bv] > dep[v] && adep[dep[bv]].count(bv)) {
//					tmp.push_back(bv);
//				}
//			}
//		}
//		cout << tmp.size();
//		for (auto v : tmp) {
//			cout << v << " ";
//		}
//		tmp.clear();
//		cout << endl;
//	}
//	for (int i = 1; i <= mxdep; i++) {
//		cnt[i] = 0;
//	}
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
//const int N = 2e5 + 5;
//vector<vector<int>>g;
//int dep[N];
//int cnt[N];
//int fa[N];
//int mxdep = 1;
//void dfs(int u, int pa) {
//	dep[u] = dep[pa] + 1;
//	cnt[dep[u]]++;
//	fa[u] = pa;
//	mxdep = max(mxdep, dep[u]);
//	for (auto v : g[u]) {
//		if (v == pa)continue;
//		dfs(v, u);
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	g.assign(n + 1, {});
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	dep[0] = 0;
//	mxdep = 1;
//	int mxdrg = g[1].size();
//	for (int i = 2; i <= n; i++) {
//		mxdrg = max(mxdrg, (int)g[i].size() - 1);
//	}
//	dfs(1, 0);
//	int ans = 0;
//	for (int i = 1; i <= mxdep; i++) {
//		ans = max(ans, cnt[i]);
//	}
//	if (mxdrg == ans) {
//		cout << ans + 1 << "\n";
//	}
//	else {
//		cout << ans << "\n";
//	}
//	vector<set<int>>adep(mxdep + 1);
//	vector<vector<int>>op;
//	for (int i = 1; i <= n; i++) {
//		adep[dep[i]].insert(i);
//	}
//	
//
//
//	for (int i = 1; i <= mxdep; i++) {
//		cnt[i] = 0;
//	}
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
//const int mod = 998244353;
//double gcd(int a, int b) {
//	while (b != 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(n + 1);
//	int lst = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		if (a[i] != 0) {
//			if (a[i] <= lst) {
//				cout << 0 << endl;
//				return;
//			}
//			lst = a[i];
//		
//		}
//	}
//	if (a[1] != 0 || a[1] != 1) {
//		cout << 0 << endl;
//		return;
//	}
//	vector<vector<int>>dp(n + 1,vector<int>(m+1));
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			for()
//		}
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