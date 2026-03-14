//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	int mn = INT_MAX, mx = INT_MIN;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		mn = min(mn, a[i]);
//		mx = max(mx, a[i]);
//	}
//	int x;
//	cin >> x;
//	if (x<mn || x>mx) {
//		cout << "NO\n";
//	}
//	else {
//		cout << "YES\n";
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
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int ev = -1;
//	vector<int>aod;
//	for (int i = 1; i <= n; i++) {
//		if (a[i] & 1) {
//			for (auto v : aod) {
//				if ((a[i] / v) & 1) {
//					cout << v << " " << a[i] << "\n";
//					return;
//				}
//			}
//			aod.push_back(a[i]);
//		}
//		else {
//			if (ev != -1) {
//				cout << ev << " " << a[i] << "\n";
//				return;
//			}
//			for (auto v : aod) {
//				if (!((a[i] / v) & 1)) {
//					cout << v << " " << a[i] << "\n";
//					return;
//				}
//			}
//			ev = a[i];
//		}
//		
//	}
//	cout << -1 << "\n";
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


//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	multiset<int>a;
//	
//	vector<pair<int, int>>b(m+1);
//	int mx = -1;
//	for (int i = 1,u; i <= n; i++) {
//		cin >> u;
//		a.insert(u);
//	}
//	for (int i = 1; i <= m; i++) {
//		cin >> b[i].first;
//	}
//	for (int i = 1; i <= m; i++) {
//		cin >> b[i].second;
//	}
//	multiset<pair<int, int>>bb;
//	multiset<pair<int, int>>aa;
//	for (int i = 1; i <= m; i++) {
//		if(b[i].second>0)bb.insert(b[i]);
//		else {
//			aa.insert(b[i]);
//		}
//	}
//	multiset<pair<int,int>>nxt;
//	while (!bb.empty()) {
//		bool kill = 0;
//		for (auto v : bb) {
//			auto it = a.lower_bound(v.first);
//			if (it==a.end())nxt.insert(v);
//			else {
//				int ins = max(*it, v.second);
//				a.erase(it);
//				a.insert(ins);
//			}
//			
//		}
//		bb = nxt;
//		nxt.clear();
//		if (!kill) {
//			break;
//		}
//	}
//	//cout << b.size() << "***\n";
//	//for (auto v : a) {
//	//	cout << v << " ";
//	//}cout << "**\n";
//	multiset<pair<int,int>>aaa;
//	for (auto v : aa) {
//		auto it = a.lower_bound(v.first);
//		if (it==a.end())aaa.insert(v);
//		else {
//			a.erase(it);
//		}
//	}
//	cout << m - bb.size()-aaa.size() << "\n";
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
//	string s, t;
//	cin >> n>>k;
//	cin >> s >> t;
//	if (s == t) {
//		cout << 0 << "\n";
//		return;
//	}
//	vector<int>from(n + 1);
//	int i = n-1, j = n-1;
//	while (j>=0) {
//		while (i >= 0 && t[j] != s[i]) {
//			i--;
//		}
//		if (i == -1) {
//			cout << -1 << "\n";
//			return;
//		}
//		from[j] = i;
//		j--;
//		i = min(i, j);
//	}
//	vector<string>ans;
//	while (k--) {
//		string ss = s;
//		bool ok = 0;
//		for (int i = n - 1; i >= 0; i--) {
//			if (from[i] < i) {
//				ss[from[i] + 1] = s[from[i]];
//				from[i]++;
//			}
//		}
//		for (int i = n - 1; i >= 0; i--) {
//			if (from[i] < i)ok = true;
//		}
//		ans.push_back(ss);
//		s = ss;
//		if (!ok) {
//			cout << ans.size() << '\n';
//			for (auto v : ans)cout << v << "\n";
//			return;
//		}
//	}
//	cout << -1 << "\n";
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
//const int N = 2e6 + 5;
//int lson[N], rson[N], fa[N],we[N],deg[N];
//int ans,n,m;
//int find(int x) {
//	if (fa[x] != x) {
//		fa[x] = find(fa[x]);
//	}
//	return fa[x];
//}
//int dfs(int u, int w) {
//	if (u == 0)return 0;
//	we[u] = min(w, we[u]);
//	deg[u] += dfs(lson[u], we[u]);
//	deg[u] += dfs(rson[u], we[u]);
//	if (u > n) {
//		ans += deg[u] / 2 * we[u];
//	}
//	return deg[u] & 1;
//}
//void solve() {
//	cin >> n >> m;
//	for (int i = 1; i <= n + m; i++) {
//		fa[i] = i;
//		lson[i] = rson[i] = deg[i] = 0;
//	}
//	ans = 0;
//	int ct = n;
//	for (int i = 1, u, v, w; i <= m; i++) {
//		cin >> u >> v >> w;
//		ans += w;
//		ct++;
//		deg[u]++;
//		deg[v]++;
//		int fu = find(u);
//		int fv = find(v);
//		lson[ct] = fu;
//		if (fu != fv) {
//			rson[ct] = fv;
//		}
//		we[ct] = w;
//		if (lson[ct])fa[lson[ct]] = ct;
//		if (rson[ct])fa[rson[ct]] = ct;
//	}
//	dfs(ct, LLONG_MAX);
//	cout << ans << endl;
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




//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 998244353;
//const int N = 5005;
//int ans = 1;
//int f[N][N];
//int finv[N], fac[N],a[N];
//vector<vector<int>>g;
//int n;
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
//void dfs(int u) {
//	for (auto v : g[u]) {
//		dfs(v);
//		for (int i = 0; i <= n; i++) {
//			f[u][i] += f[v][i];
//			ans = ans * finv[f[v][i]]%mod;
//		}
//	}
//	for (int i = 0; i <= n; i++) {
//		ans = ans * (fac[f[u][i]])%mod;
//	}
//	for (int i = a[u]+1; i <= n; i++) {
//		f[u][i - 1] += f[u][i];
//		f[u][i] = 0;
//	}
//	f[u][a[u]]++;
//}
//void prepare() {
//	fac[0] = finv[0] = 1;
//	for (int i = 1; i < N; i++) {
//		fac[i] = fac[i - 1] * i % mod;
//	}
//	finv[N - 1] = qpow(fac[N - 1], mod - 2);
//	for (int i = N - 2; i >= 1; i--) {
//		finv[i] = finv[i + 1] * (i + 1) % mod;
//	}
//}
//void solve() {
//	cin >> n;
//	g.assign(n + 1,{});
//	for (int i = 2,f; i <= n; i++) {
//		cin >> f;
//		g[f].push_back(i);
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 0; i <= n + 1; i++) {
//		for (int j = 0; j <= n + 1; j++) {
//			f[i][j] = 0;
//		}
//	}
//	ans = 1;
//	dfs(1);
//	for (int i = 1; i <= n; i++) {
//		if (f[1][i]) {
//			cout << 0 << "\n";
//			return;
//		}
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