//#include<bits/stdc++.h>
//using namespace std;
//const int N = 5e5 + 5;
//int fa[N];
//int find(int x) {
//	while (fa[x]!=x) {
//		fa[x] = fa[fa[x]];
//	}
//	return fa[x];
//}
//void solve() {
//	int n, m;
//	cin >> n >> m;
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
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>p(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//	}
//	for (int len = 1; len <= n / 2; len++) {
//
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
//	int a, b, c;
//	cin >> a >> b >> c;
//	int odd = 0, even = 0;
//	if (a & 1)odd++;
//	else even++;
//	if (b & 1)odd++;
//	else even++;
//	if (c & 1)odd++;
//	else even++;
//	if (odd == 3) {
//		cout << "NO\n";
//		return;
//	}
//	/*if (even == 3) {
//		int four = 0;
//		if (a % 4 == 0) {
//			four++;
//		}
//		if (b % 4 == 0) {
//			four++;
//		}
//		if (c % 4 == 0) {
//			four++;
//		}
//	}
//	cout << "YES\n";
//	*/
//	int mx = max({ a,b,c });
//	if (even == 3) {
//		for (int i = 4, cnt; i <17000 ; i *= 2) {
//			cnt = 0;
//			if (a % i != 0) {
//				cnt++;
//			}
//			if (b % i != 0) {
//				cnt++;
//			}
//			if (c % i != 0) {
//				cnt++;
//			}
//			//cout << i << " " << cnt << '\n';
//			if (cnt == 3) { cout << "NO\n"; return; }
//			else if (cnt != 0) {
//				cout << "YES\n";
//				return;
//			}
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
//const int N = 5e5 + 10;
//int man[N];
//
////-------
//int fa[N];
//void build(int n) {
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//	}
//}
//int find(int x) {
//	while (fa[x] != x) {
//		x=fa[x] = fa[fa[x]];
//	}
//	return fa[x];
//}
//bool isSameSet(int a, int b) {
//	return find(a) == find(b);
//}
//bool Union(int x, int y) {
//	int fx = find(x);
//	int fy = find(y);
//	if (fx == fy) {
//		return false;
//	}
//	fa[fx] = fa[fy];
//	return true;
//}
////--------
//
//int head[N];
//int nex[N << 2];
//int to[N << 2];
//int req[N << 2];//该边需求
//int cnt = 1;
//void addEdge(int u, int v, int w) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	req[cnt] = w;
//	head[u] = cnt++;
//}
//
////----------
//int need;
//struct Compare {
//	bool operator()(array<int, 2>& a, array<int, 2>& b) {
//		return a[1] > b[1];
//	}
//};
//vector<array<int, 3>>edge;
//vector<bool>vis;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	memset(head, 0, (n + 5) * sizeof(int));
//	cnt = 1;
//	//查找可能的最小值
//	build(n + 5);
//	for (int i = 1; i <= n; i++) {
//		cin >> man[i];
//	}
//	edge.resize(m + 1);
//	for (int i = 1; i <= m; i++) {
//		cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
//		addEdge(edge[i][0], edge[i][1], edge[i][2]);
//		addEdge(edge[i][1], edge[i][0], edge[i][2]);
//	}
//	sort(edge.begin() + 1, edge.end(), [&](auto x, auto y) {
//		return x[2] < y[2];
//		});
//	need = -1;
//	for (int i = 1; i <= m; i++) {
//		if (Union(edge[i][0], edge[i][1])) {
//			if (isSameSet(1, n)) {
//				need = edge[i][2];
//				break;
//			}
//		}
//	}
//	if (need == -1) {
//		cout << -1 << '\n';
//		return;
//	}
//	//查看达到大于该最小值的最少杀敌数
//	int cur = 0;//当前最多杀敌数
//	priority_queue<array<int, 2>, vector<array<int, 2>>, Compare>pq;
//	vis.assign(n + 1, 0);
//	pq.push({ 1,0 });
//	while (!pq.empty()) {
//		array<int,2> ar = pq.top();
//		int u = ar[0], w = ar[1];
//		pq.pop();
//		if (vis[u])continue;
//		vis[u] = true;
//		if (cur >= w) {
//			cur += man[u];
//			if (cur >= need) {
//				break;
//			}
//		}
//		else {
//			if (cur >= need) {
//				break;
//			}
//			else {
//				cout << -1 << '\n';
//				return;
//			}
//		}
//		for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//			if (!vis[to[ui]]) {
//				pq.push({ to[ui], req[ui] });
//			}
//		}
//	}
//	cout << need << '\n';
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

//3
//4 5
//0 3 1 0
//1 2 6
//2 1 0
//2 2 2
//3 4 5
//3 1 0
//4 5
//0 3 1 0
//1 2 6
//2 1 0
//2 2 2
//3 4 4
//3 1 0
//7 7
//0 3 2 5 0 0 0
//1 2 2 
//2 4 3
//4 5 4
//5 7 9
//1 3 0
//3 6 4
//6 7 3




//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2e5 + 5;
//int need[N];//该节点及其子树至少提前加多少才能应对
//int dfn[N];
//int siz[N];
//int cnt = 0;
//vector<vector<int>>g;
//void dfs(int u, int fa) {
//	dfn[u] = ++cnt;
//	siz[u] = 1;
//	for (auto v : g[u]) {
//		if (v != fa) {
//			dfs(v,u);
//			siz[u] += siz[v];
//		}
//	}
//}
//int sum[N << 2];
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//int query(int jl,int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int mid = l + r >> 1;
//	int ans = 0;
//	if (jl <= mid) {
//		ans += query(jl, jr, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		ans += query(jl, jr, mid + 1, r, i << 1 | 1);
//	}
//	return ans;
//}
//void add(int x, int v,int l, int r, int i) {
//	if (l == r) {
//		sum[i] += v;
//		return;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		add(x, v, l, mid, i << 1);
//	}
//	if (x > mid) {
//		add(x, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//int ans = 0;
//int dfs1(int u, int fa) {//收集该子树上的need
//	int sum = 0;
//	for (int v : g[u]) {
//		if (v != fa) {
//			sum += dfs1(v,u);
//		}
//	}
//	if (sum < need[u]) {
//		ans += need[u] - sum;
//	}
//	return max(sum, need[u]);
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n, q;
//	cin >> n >> q;
//	g.assign(n + 1, {});
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	dfs(1, 0);
//	for (int i = 1,o,u,x; i <= q; i++) {
//		cin >> o >> u >> x;
//		if (o == 1) {
//			add(dfn[u], x, 1, n, 1);
//		}
//		else {
//			int att = query(dfn[u], dfn[u] + siz[u] - 1, 1, n, 1);
//			if (att < x) {
//				need[u] = max(need[u], x - att);
//			}
//		}
//	}
//	dfs1(1, 0);
//	cout << ans << '\n';
//}

//6 5
//1 2
//2 3
//2 4
//4 5
//1 6
//1 4 3
//2 2 4
//1 6 1
//2 6 2
//2 3 2

//8 6
//1 2
//1 3
//3 8
//2 4
//2 5
//5 6 
//5 7
//2 7 2
//2 2 4
//1 5 1
//1 8 1
//2 8 3
//2 3 2

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e6+5;
//const int mod = 998244353;
//int spf[N];
//int prime[N];
//void eular() {
//	int cnt = 0;
//	for (int i = 2; i <= N; i++) {
//		if (!spf[i]) {
//			spf[i] = i;
//			prime[cnt++] = i;
//		}
//		for (int j = 0; j < cnt; j++) {
//			if (i * prime[j] > N)break;
//			spf[i * prime[j]] = prime[j];
//			if (i % prime[j] == 0)break;
//		}
//	}
//}
//int qpow(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a % mod;
//		}
//		b >>= 1;
//		a = a * a % mod;
//	}
//	return ans;
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	eular();
//	int n, a;
//	cin >> n >> a;
//	vector<int>b(n + 1);
//	vector<int>cnt(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//		if (b[i] == 1) {
//			cnt[i] = 0;
//			continue;
//		}
//		while (b[i] != 1) {
//			b[i] /= spf[b[i]];
//			cnt[i]++;
//		}
//	}
//	vector<int>dp(n + 1);//前n个数总和
//	dp[0] = 1;
//	for (int i = 1; i <= n; i++) {
//		dp[i] = (dp[i - 1] + dp[i - 1] * qpow(a, cnt[i])%mod)%mod;
//	}
//	cout << dp[n] << '\n';
//}



//#include<bits/stdc++.h>
//using namespace std;
//struct Point {
//	int x, y;
//	Point(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//	Point() {
//
//	}
//};
//int main() {
//	int n;
//	cin >> n;
//	vector<Point>p(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i].x >> p[i].y;
//	}
//	sort(p.begin()+1, p.end(), [&](Point&a,Point&b) {
//		if (a.x == b.x)return a.y < b.y;
//		return a.x < b.x;
//		});
//	cout << "YES\n";
//	for (int i = 1; i <= n-1; i++) {
//		cout << p[i].x << " " << p[i].y << '\n';
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>p(n + 1);
//	vector<int>pos(n + 1);//i在数组中出现的位置
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//		pos[p[i]] = i;
//	}
//	unordered_set<int>got;
//	int lmin = INT_MAX;
//	for (int i = 1; i <= n; i++) {
//		for (int len = 1; p[i]-2*len >= lmin; len++) {
//			if (got.count(p[i] - len) && got.count(p[i] - 2 * len)
//				&&pos[p[i]-len]>pos[p[i]-2*len]) {
//				cout << "Yes\n";
//				return;
//			}
//		}
//		lmin = min(lmin, p[i]);
//		got.insert(p[i]);
//	}
//	got.clear();
//	lmin = INT_MAX;
//	for (int i = n; i >=1; i--) {
//		for (int len = 1; p[i]-2*len>=lmin; len++) {
//			if (got.count(p[i] - len) && got.count(p[i] - 2 * len)
//				&& pos[p[i] - len] < pos[p[i] - 2 * len]) {
//				cout << "Yes\n";
//				return;
//			}
//		}
//		got.insert(p[i]);
//		lmin = min(lmin, p[i]);
//	}
//	cout << "No\n";
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
//const int N = 1e5 + 5;
//int tree[N];
//int n;
//int lowbit(int i) {
//	return i & (-i);
//}
//int sum(int i) {
//	int ans = 0;
//	while (i > 0) {
//		ans += tree[i];
//		i -= lowbit(i);
//	}
//	return ans;
//}
//void add(int i, int v) {
//	while (i <= n) {
//		tree[i] += v;
//		i += lowbit(i);
//	}
//}
//int tree1[N];
//int sum1(int i) {
//	int ans = 0;
//	while (i > 0) {
//		ans += tree1[i];
//		i -= lowbit(i);
//	}
//	return ans;
//}
//void add1(int i, int v) {
//	while (i <= n) {
//		tree1[i] += v;
//		i += lowbit(i);
//	}
//}
////int biSearch(int tot) {
////	int l = 1, r = n,mid,ans=n;
////	while (l <= r) {
////		mid = l + r >> 1;
////		if (2 * sum(mid) >= tot) {
////			ans = mid;
////			r = mid - 1;
////		}
////		else {
////			l = mid + 1;
////		}
////	}
////	return ans;
////}
//int bit;
//int biSearch(int tot) {
//	int idx = 0;
//	int cur = 0;
//	for (int p = bit; p > 0; p >>= 1) {
//		int nxt = idx + p;
//		if (nxt <= n && 2 * (cur + tree[nxt]) < tot) {
//			idx = nxt;
//			cur += tree[nxt];
//		}
//	}
//	return idx + 1;
//}
//void solve() {
//	memset(tree, 0, sizeof(tree));
//	memset(tree1, 0, sizeof(tree1));
//	cin >> n;
//	bit = 1;
//	while ((bit << 1) <= n)bit <<= 1;
//	vector<array<int, 3>>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i][0];
//		a[i][2] = i;
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i][1];
//	}
//	sort(a.begin() + 1, a.end(), [&](auto x, auto y) {
//		return x[1] < y[1];
//		});
//	for (int i = 1; i <= n; i++) {
//		add(i, a[i][0]);
//		add1(i, a[i][0] * a[i][1]);
//	}
//	vector<int>pos(n + 1);
//	for (int i = 1; i <= n; i++) {
//		pos[a[i][2]] = i;
//	}
//	int q;
//	cin >> q;
//	for (int i = 1, id, y; i <= q; i++) {
//		cin >> id >> y;
//		int pp = pos[id];
//		add(pp, y - a[pp][0]);
//		add1(pp, (y - a[pp][0]) * a[pp][1]);
//		a[pp][0] = y;
//		int p = biSearch(sum(n));
//		cout << a[p][1] * (2 * sum(p - 1) - sum(n)) - (2 * sum1(p - 1) - sum1(n)) << '\n';
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
//#define ull unsigned long long
//using namespace std;
//const int N = 3e5 + 5;
//const int base = 131;
//ull pwr[N];
//int n;
//struct Tr {
//	ull hs[N];
//	int lowbit(int i) {
//		return i & (-i);
//	}
//	void init() {
//		for (int i = 1; i <= n; i++) {
//			hs[i] = 0;
//		}
//	}
//	void upd(int i) {//把i位置改为1
//		int t = i;
//		while (t <= n) {
//			hs[t] =hs[t]+ pwr[t - i];
//			t += lowbit(t);
//		}
//	}
//	ull query(int x) {
//		ull ans = 0;
//		int t = x;
//		while (t > 0) {
//			ans = ans + hs[t] * pwr[x - t];
//			t -= lowbit(t);
//		}
//		return ans;
//	}
//	ull range(int l, int r) {
//		return query(r) - query(l - 1) * (pwr[r - l + 1]);
//	}
//}tr1, tr2;
//void solve() {
//	cin >> n;
//	tr1.init();
//	tr2.init();
//	bool flag = 0;
//	for (int i = 1,p; i <= n; i++) {
//		cin >> p;
//		int m = min(p - 1, n - p);
//		if (!flag) {
//			if (tr1.range(p - m, p) != tr2.range(n - p + 1 - m, n - p + 1)) {
//				flag = 1;
//			}
//			tr1.upd(p);
//			tr2.upd(n - p + 1);
//		}
//	}
//	if (flag) { 
//		cout << "Yes\n";
//	}
//	else cout << "No\n";
//}
//void prepare() {
//	pwr[0] = 1;
//	for (int i = 1; i < N; i++) {
//		pwr[i] = pwr[i - 1] * base;
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	prepare();
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}