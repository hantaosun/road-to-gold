//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, a, b;
//	cin >> n >> a >> b;
//	if (n & 1) {
//		if (b & 1) {
//			if (a & 1) {
//				cout << "YES\n";
//				return;
//			}
//			else {
//				if (a < b) {
//					cout << "YES\n";
//				}
//				else {
//					cout << "NO\n";
//				}
//				return;
//			}
//		}
//		else {
//			cout << "NO\n";
//			return;
//		}
//	}
//	else {
//		if (!(b & 1)) {
//			if (!(a & 1)) {
//				cout << "YES\n";
//			}
//			else {
//				if (a < b) {
//					cout << "YES\n";
//				}
//				else {
//					cout << "NO\n";
//				}
//			}
//		}
//		else {
//			cout << "NO\n";
//			return;
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
//#define int long long
//using namespace std;
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	if (k & 1) {
//		for (int i = 1; i <= n; i++) {
//			if (a[i] & 1) {
//				cout << a[i] + k << " ";
//			}
//			else cout << a[i] << " ";
//		}cout << "\n";
//		return;
//	}
//	else {
//		if (k == 2) {
//			for (int i = 1; i <= n; i++) {
//				if (a[i] % 3 == 0) {
//					cout << a[i] << " ";
//				}
//				else {
//					if ((a[i] + k) % 3 == 0) {
//						cout << a[i] + k << " ";
//					}
//					else {
//						cout << a[i] + 2 * k << " ";
//					}
//				}
//			}cout << '\n';
//			return;
//		}
//		else {
//			for (int i = 1; i <= n; i++) {
//				if (a[i] % (k - 1) == 0) {
//					cout << a[i] << " ";
//				}
//				else {
//					cout << a[i] + k * (k - 1 - a[i] % (k - 1)) << " ";
//				}
//			}cout << '\n';
//			return;
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
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 2);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	vector<int>need(n + 1);
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		if (!(i & 1)) {
//			int need = max(0ll, (i == n ? 0 : a[i + 1]) + a[i - 1] - a[i]);
//			ans += need;
//			if (i!=n&&a[i + 1] >= need) {
//				a[i + 1] -= need;
//			}
//			else {
//				a[i + 1] = 0;
//			}
//		}
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
//vector<vector<int>>g;
//const int N = 2e5 + 5;
//int dep[N];
//int p;
//int clen;
//int fa[N];
//void dfs(int u, int pa,int len) {
//	if (len > clen) {
//		clen = len;
//		p = u;
//	}
//	fa[u] = pa;
//	for (int v : g[u]) {
//		if (v == pa)continue;
//		dfs(v,u,len+1);
//	}
//}
//
//void solve() {
//	int n;
//	cin >> n;
//	g.assign(n + 1, {});
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	bool flag = 1;
//	for (int i = 1; i <= n; i++) {
//		if (g[i].size() > 2) {
//			flag = 0;
//			break;
//		}
//	}
//	if (flag) {
//		cout << -1 << "\n";
//		return;
//	}
//	clen = 0;
//	p = 1;
//	dfs(1, 0,0);
//	int a = p;
//	clen = 0;
//	p = a;
//	dfs(a, 0,0);
//	int b = p;
//	unordered_set<int>got;
//	int len = 0;
//	for (int cur = b; cur != a; cur = fa[cur]) {
//		got.insert(cur);
//		len++;
//	}
//	got.insert(a);
//	int cnt = 1;
//	for (int cur = fa[b],pre=b; cur != a; cur = fa[cur],pre=fa[pre],cnt++) {
//		if (g[cur].size() > 2) {
//			cout <<  pre << " " << cur << " ";
//			for (auto v : g[cur]) {
//				if (!got.count(v)) {
//					cout << v << "\n";
//					return;
//				}
//			}
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
//vector<array<int, 2>>box;
//void swap(int x) {
//	cout << "swap " << x << endl;
//	swap(box[x], box[x + 1]);
//}
//int thro(int x) {
//	cout << "throw " << x << endl;
//	int t;
//	cin >> t;
//	return t;
//}
//void solve() {
//	int n;
//	cin >> n;
//	box.assign(n + 1, {});
//	vector<int>dp(n + 1);
//	for (int i = 0; i <= n; i++) {
//		box[i][0] = 0;
//		box[i][1] = i;
//	}
//	int t = thro(n - 1);
//	if (t == 1) {
//		box[n - 1][0] = 2;
//	}
//	else {
//		box[n - 1][0] = 1;
//	}
//	dp[n] = 1;
//	swap(n - 1);
//	t = thro(n - 1);
//	if (t == 1) {
//		box[n - 1][0] = 2;
//	}
//	else {
//		box[n - 1][0] = 1;
//	}
//	dp[n - 1] = t;
//	for (int i = n - 2; i >= 1; i--) {
//		if (dp[i + 1] != dp[i + 2]) {
//			t = thro(i);
//			dp[i] = t;
//			if (t == dp[i + 1] + 1) {
//				box[i][0] = 1;
//			}
//			else {
//				box[i][0] = 2;
//			}
//		}
//		else {
//			dp[i] = 1 + dp[i + 1];
//		}
//	}
//	for (int i = 1; i <= n - 2; i++) {
//		if (box[i][0] == 0) {
//			swap(i);
//			t = thro(i + 1);
//			dp[i + 1] = t;
//			if (box[i][0] == 1) {
//				dp[i] = 1 + dp[i + 1];
//			}
//			else {
//				dp[i] = 1 + dp[i + 2];
//			}
//			if (t == dp[i + 2] + 1) {
//				box[i + 1][0] = 1;
//			}
//			else {
//				box[i + 1][0] = 2;
//			}
//		}
//	}
//	sort(box.begin() + 1, box.end(), [&](auto a, auto b) {
//		return a[1] < b[1];
//		});
//	cout << "! ";
//	for (int i = 1; i <= n; i++) {
//		cout << box[i][0] << " ";
//	}cout << '\n';
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}