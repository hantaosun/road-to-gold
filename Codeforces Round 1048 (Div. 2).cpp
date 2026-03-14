//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int a, b;
//	cin >> a >> b;
//	if (a == b) {
//		cout << 0 << '\n';
//		return;
//	}
//	else {
//		if (max(a, b) % min(a, b) == 0) {
//			cout << 1 << '\n';
//		}
//		else {
//			cout<<2<<'\n';
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
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	sort(a.begin() + 1, a.end());
//	int ans = 0;
//	for (int i = n; i >= 1; i--) {
//		ans += a[i] * m;
//		m--;
//		if (m == 0)break; 
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
//#define int long long
//using namespace std;
//void solve() {
//	int k, x;
//	cin >> k >> x;
//	int s = pow(2, k);
//	int a=1;//x给出
//	int b=2;//x获得
//	if (x > 2*s - x) {
//		x = 2*s - x;
//		swap(a, b);
//	}
//	if (x == s) {
//		cout << 0 << '\n';
//		cout << '\n';
//		return;
//	}
//	vector<int>op;
//	while ((x & 1) == 0) {
//		x >>= 1;
//		k--;
//	}
//	x >>= 1;
//	while (k != 0) {
//		if (x & 1) {
//			op.push_back(b);
//		}
//		else {
//			op.push_back(a);
//		}
//		x >>= 1;
//		k--;
//	}
//	cout << op.size() << '\n';
//	for (int i = 0; i < op.size(); i++) {
//		cout << op[i] << " ";
//	}cout << '\n';
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
//const int N = 5e5 + 5;
//int mn[N << 2];
//void build(int l, int r, int i, vector<int>& a) {
//	if (l == r) {
//		mn[i] = a[l];
//		return;
//	}
//	int mid = l + r >> 1;
//	build(l, mid, i << 1, a);
//	build(mid + 1, r, i << 1 | 1, a);
//	mn[i] = min(mn[i << 1], mn[i << 1 | 1]);
//}
//int queryMin(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return mn[i];
//	}
//	int ans = INT_MAX;
//	int mid = l + r >> 1;
//	if (jl <= mid) {
//		ans = min(ans, queryMin(jl, jr, l, mid, i << 1));
//	}
//	if (jr > mid) {
//		ans = min(ans, queryMin(jl, jr, mid + 1, r, i << 1 | 1));
//	}
//	return ans;
//}
//void solve() {//其实可以不用线段树,处理一个信息为L[r]表示所有右边界<=r的三元组中的最大l值即可
//	int n, q;
//	cin >> n >> q;
//	vector<int>a(n + 1);
//	vector<int>ls(n + 1);
//	vector<int>rs(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	stack<int>sta;
//	for (int i = 1; i <= n; i++) {
//		while (!sta.empty() && a[sta.top()] < a[i]) {
//			sta.pop();
//		}
//		if (sta.empty()) {
//			ls[i] = 0;
//		}
//		else {
//			ls[i] = sta.top();
//		}
//		sta.push(i);
//	}
//	while (!sta.empty())sta.pop();
//	for (int i = n; i >= 1; i--) {
//		while (!sta.empty() && a[sta.top()] > a[i]) {
//			sta.pop();
//		}
//		if (sta.empty()) {
//			rs[i] = n + 1;
//		}
//		else {
//			rs[i] = sta.top();
//		}
//		sta.push(i);
//	}
//	vector<int>rst(n + 1, n + 1);
//	for (int i = 1; i <= n; i++) {
//		rst[ls[i]] = min(rst[ls[i]], rs[i]);
//	}
//	build(1, n, 1, rst);
//	for (int i = 1, l, r; i <= q; i++) {
//		cin >> l >> r;
//		int rr = queryMin(l, r, 1, n, 1);
//		if (rr > r) {
//			cout << "YES\n";
//		}
//		else {
//			cout << "NO\n";
//		}
//	}
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
//vector<vector<int>>g;
//const int N = 1e3 + 5;
//int dep[N];//当前深度的节点有几个
//int minleafdep;
//void dfs(int u, int fa, int d) {
//	dep[d]++;
//	bool gotson=false;
//	for (int v : g[u]) {
//		if (v == fa)continue;
//		dfs(v, u, d + 1);
//		gotson = true;
//	}
//	if (!gotson) {
//		minleafdep = min(minleafdep, d);
//	}
//}
//bool dp[N][N];
//void solve() {
//	minleafdep = INT_MAX;
//	memset(dep, 0, sizeof(dep));
//	memset(dp, 0, sizeof(dp));
//	int n, k;
//	cin >> n >> k;
//	g.assign(n + 1, {});
//	for (int i = 2, pa; i <= n; i++) {
//		cin >> pa;
//		g[pa].push_back(i);
//	}
//	dfs(1, 0, 1);
//	int rest = 0;
//	for (int i = minleafdep + 1; i <= n; i++) {
//		rest += dep[i];
//	}
//	dp[0][0] = true;
//	for (int i = 1; i <= minleafdep; i++) {
//		for (int j = 0; j <dep[i]; j++) {
//			dp[i][j] = dp[i - 1][j];
//		}
//		for (int j = dep[i]; j <= k; j++) {
//			dp[i][j] = (dp[i - 1][j] |dp[i - 1][j - dep[i]]);
//		}
//	}
//	bool ok = 0;
//	for (int i = max(0, k - rest); i <= k; i++) {
//		if (dp[minleafdep][i]) {
//			ok = 1;
//			break;
//		}
//	}
//	if (ok) {
//		cout << minleafdep << '\n';
//	}
//	else {
//		cout << minleafdep - 1<<'\n';
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
//int dep[N];//当前深度的节点有几个
//int minleafdep;
//vector<vector<int>>g;
//void dfs(int u, int fa, int d) {
//	dep[d]++;
//	bool gotson=false;
//	for (int v : g[u]) {
//		if (v == fa)continue;
//		dfs(v, u, d + 1);
//		gotson = true;
//	}
//	if (!gotson) {
//		minleafdep = min(minleafdep, d);
//	}
//}
//bitset<N>dp;
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	dp.reset();
//	g.assign(n + 1, {});
//	memset(dep, 0, sizeof(dep));
//	for (int i = 2, pa; i <= n; i++) {
//		cin >> pa;
//		g[pa].push_back(i);
//	}
//	minleafdep = INT_MAX;
//	dfs(1, 0, 1);
//	int rest = 0;
//	for (int i = minleafdep + 1; i <= n; i++) {
//		rest += dep[i];
//	}
//	sort(dep + 1, dep + minleafdep);
//	vector<int>group;
//	for (int i = 1,j=1; i <= minleafdep;) {
//		while (j<=minleafdep&&dep[j] == dep[i]) {
//			j++;
//		}
//		int t = j - i;
//		for (int z = 1; z <= t; z *= 2) {
//			group.push_back(z * dep[i]);
//			t -= z;
//		}
//		if (t > 0) {
//			group.push_back(t * dep[i]);
//		}
//		i = j;
//	}
//	dp[0] = 1;
//	for (auto val : group) {
//		dp |= (dp << val);
//	}
//	for (int i = max(0, k - rest); i <= k; i++) {
//		if (dp[i]) {
//			cout << minleafdep << '\n';
//			return;
//		}
//	}
//	cout << minleafdep - 1 << '\n';
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}