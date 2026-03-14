//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int k, x;
//	cin >> k >> x;
//	for (int i = 1; i <= k; i++) {
//		x = x * 2;
//	}
//	cout << x << '\n';
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
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>p(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << n - p[i]+1 << " ";
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
//	int a, b;
//	cin >> a >> b;
//	if (((a * b + 1) % 2) == 0) {
//		cout << a * b + 1<<'\n';
//		return;
//	}
//	if (a % 2 == 0 && b % 2 == 1) {
//		cout << -1 << '\n';
//		return;
//	}
//	if (a % 2 == 1 && b % 2 == 0) {
//		a *= 2; b /= 2;
//		if (b % 2 != 0) {
//			cout << -1 << '\n';
//			return;
//		}
//		else {
//			cout << a * (b / 2) + 2<<'\n';
//			return;
//		}
//	}
//	if (a % 2 == 0 && b % 2 == 0) {
//		cout << a*b/2+2 << '\n';
//		return;
//	}
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
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	vector<vector<int>>pos(n + 1);
//	for (int i = 1; i <= n; i++) {
//		pos[b[i]].push_back(i);
//	}
//	vector<int>ans(n + 1);
//	int cn = 0;
//	for (int i = 1; i <= n; i++) {
//		if (pos[i].size() % i != 0) {
//			cout << -1 << '\n';
//			return;
//		}
//		else {
//			for (int j = 0; j < pos[i].size(); j++) {
//				if (j % i == 0) {
//					cn++;
//				}
//				ans[pos[i][j]] = cn;
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << ans[i] << " ";
//	}
//	cout << '\n';
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
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	int zero = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		if (a[i] == 0)zero++;
//	}
//	if (zero == 0) {
//		cout << ((k & 1) ?0:n) << '\n';
//		return;
//	}
//	if (zero > 1) {
//		if (k != 1) {
//			cout << ((k & 1) ? n : 0) << '\n';
//			return;
//		}
//		map<int, int>mp;
//		for (int i = 1; i <= n; i++) {
//			mp[a[i]]++;
//		}
//		int mex = 0;
//		for (int i = 0; i <= n; i++) {
//			if (mp.count(i)) {
//				mex = i + 1;
//			}
//			else {
//				break;
//			}
//		}
//		int ans = 0;
//		for (int i = 1; i <= n; i++) {
//			if (mp[a[i]] == 1 && a[i] < mex) {
//				ans += a[i];
//			}
//			else {
//				ans += mex;
//			}
//		}
//		cout << ans << '\n';
//		return;
//	}
//	if (zero == 1) {
//		map<int, int>mp;
//		for (int i = 1; i <= n; i++) {
//			mp[a[i]]++;
//		}
//		int mex = 0;
//		for (int i = 0; i <= n; i++) {
//			if (mp.count(i)) {
//				mex = i + 1;
//			}
//			else {
//				break;
//			}
//		}
//		int ans = 0;
//		for (int i = 1; i <= n; i++) {
//			if (mp[a[i]] == 1 && a[i] < mex) {
//				ans += a[i];
//			}
//			else {
//				ans += mex;
//			}
//		}
//		if (k == 1) {
//			cout << ans << '\n';
//			return;
//		}
//		int tar = mex;
//		ans = 0;
//		for (int i = 0; i <mex; i++) {
//			if (mp[i] > 1) {
//				tar = i;
//				break;
//			}
//			ans += i;
//		}
//		if (tar == mex) {
//			if (n - tar != 1) {
//				if (k & 1) {
//					cout << ans + tar * (n - tar) << '\n';
//				}
//				else {
//					cout << ans + (tar + 1) * (n - tar) << '\n';
//				}
//			}
//			if (n - tar == 1) {
//				cout << ans + tar << '\n';
//			}
//		}
//		else {
//			if ((k & 1) == 0) {
//				cout << ans + tar * (n - tar) << '\n';
//			}
//			else {
//				cout << ans + (tar + 1) * (n - tar) << '\n';
//			}
//		}
//	}
//}
//signed main() {
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
//int n = 0;
//int sum[N << 3];
//int lzt[N << 3];
//void lazy(int i, int v,int n) {
//	sum[i] = v*n;
//	lzt[i] = v;
//}
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//void down(int i,int ln,int rn) {
//	if (lzt[i] != 0) {
//		lazy(i << 1, lzt[i],ln);
//		lazy(i << 1 | 1, lzt[i],rn);
//		lzt[i] = 0;
//	}
//}
//void upd(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v,r-l+1);
//		return;
//	}
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	if (jl <= mid) {
//		upd(jl, jr, v, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		upd(jl, jr, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//int query(int x, int l, int r, int i) {
//	if (l == r) {
//		return sum[i];
//	}
//	int mid = l + r >> 1;
//	down(i,mid-l+1,r-mid);
//	if (x <= mid) {
//		return query(x, l, mid, i << 1);
//	}
//	else {
//		return query(x, mid + 1, r, i << 1 | 1);
//	}
//}
//void debug(int l, int r, int i) {
//	if (l == r) {
//		cout <<"("<<l << "," << sum[i] << ") ";
//		return;
//	}
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	debug(l, mid, i << 1);
//	debug(mid+1, r, i << 1|1);
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = 0;
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid,i<<1);
//		build(mid+1, r,i<<1|1);
//		up(i);
//	}
//	lzt[i] = 0;
//}
//void solve() {
//	cin >> n;
//	build(1, 2 * n, 1);
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		if (a[i] == b[i]) {
//			ans += (n - i + 1) * i;
//		}
//		else {
//			int tmp = query(max(b[i],a[i]), 1, 2 * n, 1);
//			ans += tmp  * (n - i + 1);
//			//cout << tmp << " " << n - i + 1 << " " << b[i] << "**\n";
//		}
//		upd(1, a[i], i, 1, 2 * n, 1);
//		//debug(1,2*n,1);
//	}
//	cout << ans << '\n';
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
//const int N = 2e5 + 10;
//bool dp1[N];//在当前点Cry先手Cry能赢吗
//bool dp2[N];//在当前点River先手Cry能赢吗
//int t[N];
//int f[N];
//int n=0, m=0, q=0;
//void solve() {
//	cin >> n >> m >> q;
//	for (int i = 0; i <=n+5; i++) {
//		dp1[i] = false;
//		dp2[i] = true;
//		t[i] = f[i] = 0;
//	}
//	vector<vector<int>>g(n+1);
//	vector<vector<int>>gr(n + 1);
//	vector<int>ide(n+1);
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		gr[v].push_back(u);
//	}
//	queue<int>qu;
//	for (int i = 1; i <= n; i++) {
//		ide[i] = g[i].size();
//		if (g[i].size() == 0) {
//			qu.push(i);
//			dp1[i] = 1;
//			dp2[i] = 1;
//		}
//	}
//	while (!qu.empty()) {
//		int u = qu.front();
//		qu.pop();
//		for (auto v : gr[u]) {
//			dp1[v] |= dp2[u];
//			if (dp2[u])t[v]++;
//			dp2[v] &= dp1[u];
//			if (!dp1[u]) f[v]++;
//			if (--ide[v] == 0) {
//				qu.push(v);
//			}
//		}
//	}
//	queue<array<int, 3>>q1;
//	for (int i = 1,x1,u; i <= q; i++) {
//		cin >> x1 >> u;
//		if (x1 == 1) {
//			if (dp1[u] == 0 && dp2[u] == 0)continue;
//			q1.push({ u,0,0 });
//			while (!q1.empty()) {
//				auto [x, d1, d2] = q1.front();
//				q1.pop();
//				for (auto v : gr[x]) {
//					int dv1=dp1[v], dv2=dp2[v];
//					if (dp2[x] && !d2) {
//						if (--t[v] == 0) {
//							dv1 = false;
//						}
//					}
//					if (dp1[x] && !d1) {
//						if (f[v]++ == 0) {
//							dv2 = false;
//						}
//					}
//					if (dv1 != dp1[v] || dv2 != dp2[v])q1.push({ v, dv1, dv2 });
//				}
//				dp1[x] = d1;
//				dp2[x] = d2;
//			}
//		}
//		else {
//			cout << (dp1[u] ? "YES\n" : "NO\n");
//		}
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
//int n, m, q;
//void solve() {
//	cin >> n >> m >> q;
//	vector<vector<int>>g(n + 1);
//	vector<vector<int>>gr(n + 1);
//	vector<int>ide(n + 1);
//	vector<int>dp1(n + 1, 0);//cry走cry能赢？
//	vector<int>dp2(n + 1, 1);//river走cry能赢？
//	vector<int>t(n + 1, 0);//当前节点去往节点中dp2为1的个数
//	vector<int>f;
//	for (int i = 1, u, v; i <= m; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		gr[v].push_back(u);
//		ide[u]++;
//	}
//	queue<int>q1;
//	for (int i = 1; i <= n; i++) {
//		t[i] = g[i].size();
//		if (ide[i] == 0) {
//			q1.push(i);
//			dp1[i] = dp2[i] = 1;
//		}
//	}
//	while (!q1.empty()) {
//		int u = q1.front();
//		q1.pop();
//		for (auto v : gr[u]) {
//			dp1[v] |= dp2[u];
//			dp2[v] &= dp1[u];
//			if (--ide[v] == 0) {
//				q1.push(v);
//			}
//		}
//	}
//	queue<array<int, 2>>q2;
//	for (int i = 1, op, u; i <= q; i++) {
//		cin >> op >> u;
//		if (op == 1) {
//			if (dp1[u] != 0) { 
//				dp1[u] = 0;
//				q2.push({ u,0 });
//			}
//			if (dp2[u] != 0) {
//				dp2[u] = 0;
//				q2.push({ u,1 });
//			}
//			while (!q2.empty()) {
//				auto [x, w] = q2.front();
//				q2.pop();
//				for (auto v : gr[x]) {
//					if (w == 0) {
//						if (dp2[v] != 0) {
//							dp2[v] = 0;
//							q2.push({ v, 1 });
//						}
//					}
//					else {
//						if (--t[v] == 0) {
//							dp1[v] = 0;
//							q2.push({ v,0 });
//						}
//					}
//				}
//			}
//		}
//		else {
//			cout << (dp1[u] == 1 ? "YES" : "NO") << "\n";
//		}
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}