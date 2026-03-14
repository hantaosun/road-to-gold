//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	string x;
//	cin >> x;
//	int mn = 10;
//	for (int i = 0; i < x.size(); i++) {
//		mn = min(mn, x[i] - '0');
//	}
//	cout << mn << '\n';
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
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int sun = 0;
//	bool rest = false;
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		if (rest) {
//			rest = false;
//			continue;
//		}
//		if (a[i] == 0) {
//			sun++;
//		}
//		else {
//			sun = 0;
//		}
//		if (sun == k) {
//			ans++;
//			sun = 0;
//			rest = true;
//		}
//	}
//	cout << ans << '\n';
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
//	vector<int>h(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> h[i];
//	}
//	int cur = h[k];
//	sort(h.begin() + 1, h.end());
//	int pos = 0;
//	for (int i = 1; i <= n; i++) {
//		if (cur == h[i]) {
//			pos = i;
//			break;
//		}
//	}
//	int water = 1;
//	for (int j = pos; j <= n-1; j++) {
//		if (water + h[j + 1] - h[j]-1 > h[j]) {
//			cout << "NO\n";
//			return;
//		}
//		water += h[j + 1] - h[j];
//	}
//	cout << "YES\n";
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
//struct du {
//	int l;
//	int r;
//	int real;
//};
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	vector<du>a(n + 1);
//	vector<bool>vis(n + 1,0);
//	queue<int>q;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i].l >> a[i].r >> a[i].real;
//	}
//	sort(a.begin() + 1, a.end(), [&](du&x,du&y) {
//		if (x.l == y.l) {
//			return x.r < y.r;
//		}
//		return x.l < y.l;
//		});
//	for (int i = 1; i <= n; i++) {
//		if (k >= a[i].l && k <= a[i].r) {
//			if (a[i].real >= k) {
//				k = a[i].real;
//			}
//		}
//	}
//	cout << k << '\n';
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
//int gcd(int a, int b) {
//	while (b != 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>p(n + 1);
//	vector<int>s(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> s[i];
//	}
//	for (int i = 1; i <= n-1; i++) {
//		if (p[i] % p[i + 1] != 0) {
//			cout << "NO\n";
//			return;
//		}
//	}
//	for (int i = n; i >= 2; i--) {
//		if (s[i] % s[i - 1] != 0) {
//			cout << "NO\n";
//			return;
//		}
//	}
//	if (s[1] != p[n]) {
//		cout << "NO\n";
//		return;
//	}
//	int tgcd = s[1];
//	for (int i = 1; i <= n-1; i++) {
//		if (gcd(p[i], s[i + 1]) != tgcd) {
//			cout << "NO\n";
//			return;
//		}
//	}
//	cout << "YES\n";
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
//vector<map<int, int>>a;//当前节点变成x颜色会省去的钱数
//vector<int>c;
//int head[N];
//int nex[N << 1];
//int to[N << 1];
//int weight[N << 1];
//int fa[N];
//int cfa[N];
//int cnt = 1;
//int cost = 0;	
//int n=0, q=0;
//void dfs(int u, int pa) {
//	fa[u] = pa;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		int v = to[ui];
//		if (v == pa)continue;
//		cfa[v] = weight[ui];
//		dfs(v, u);
//		a[u][c[v]] += weight[ui];
//		if (c[v] != c[u]) {
//			cost += weight[ui];
//		}
//	}
//}
//void addEdge(int u, int v, int w) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	weight[cnt] = w;
//	head[u] = cnt++;
//}
//void solve() {
//	memset(head, 0, sizeof(int)*(n+5));
//	cin >> n >> q;
//	cost = 0;
//	cnt = 1;
//	a.assign(n + 1, {});
//	c.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> c[i];
//	}
//	for (int i = 1,u,v,w; i < n; i++) {
//		cin >> u >> v >> w;
//		addEdge(u, v, w);
//		addEdge(v, u, w);
//	}
//	dfs(1, 0);
//	for (int i = 1,v,x; i <= q; i++) {
//		cin >> v >> x;
//		if (x == c[v]) { 
//			cout << cost << '\n';
//			continue;
//		}
//		cost -= a[v][x];
//		cost += a[v][c[v]];
//		if (c[v] == c[fa[v]]) {
//			cost += cfa[v];
//		}
//		else {
//			if (x == c[fa[v]]) {
//				cost -= cfa[v];
//			}
//		}
//		int f = fa[v];
//		a[f][x] += cfa[v];
//		a[f][c[v]] -= cfa[v];
//		c[v] = x;
//		cout << cost << '\n';
//	}
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//枚举中位数，再枚举最小值，第二个枚举很关键，正常考虑枚举数组吗，这里枚举最小值位置，一定要挑好枚举的枚举
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int ans = 0;
//	for (int j = 1; j <= 100; j++) {
//		vector<int>b(n + 1);
//		for (int i = 1; i <= n; i++) {
//			if (a[i] >= j) {
//				b[i] = 1;
//			}
//			else {
//				b[i] = -1;
//			}
//		}
//		vector<int>presum(n + 2), premn(n + 2);
//		vector<int>sufmx(n + 2);
//		premn[0] = 0;
//		sufmx[n + 1] = INT_MIN;//注意n+1用不到但0能用到
//		for (int i = 1; i <= n; i++) {
//			presum[i] = presum[i - 1] + b[i];
//			premn[i] = min(premn[i - 1], presum[i]);
//		}
//		for (int i = n; i >= 1; i--) {
//			sufmx[i] = max(sufmx[i + 1], presum[i]);
//		}
//		for (int i = 1; i <= n; i++) {
//			if (premn[i - 1] <= presum[i] || presum[i -1] <= sufmx[i]) {
//				ans = max(ans, j - a[i]);
//			}
//		}
//	}
//	cout << ans << '\n';
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}