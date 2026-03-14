//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	string s;
//	cin >> s;
//	s = " " + s;
//	int cnt = 0;
//	int ans = 0;
//	for (int i = 1; i <= n; i++,cnt--) {
//		if (s[i] == '0')continue;
//		if (s[i] == '1') {
//			if (cnt <=0) {
//				ans++;
//			}
//			cnt = k;
//		}
//	}
//	cout << ans << "\n";
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
//	vector<int>a(n + 2);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	vector<int>pmax(n + 2);
//	for (int i = 1; i <= n; i++) {
//		pmax[i] = max(pmax[i - 1], a[i]);
//	}
//	for (int i = 1; i <= n; i++) {
//		if ((i & 1) == 0) {
//			a[i] = pmax[i];
//		}
//	}
//	int ans = 0;
//	a[0] = a[n + 1] = INT_MAX;
//	for (int i = 1; i <= n; i++) {
//		if (i & 1) {
//			ans += max({0ll,a[i]-a[i-1]+1,a[i]-a[i+1]+1});
//		}
//	}
//	cout << ans << "\n";
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
//int spf[N];
//int prime[N];
//int cnt = 0;
//void eular(int n) {
//	for (int i = 1; i <= n; i++) {
//		spf[i] = i;
//	}
//	for (int i = 2; i <= n; i++) {
//		if (spf[i] == i) {
//			prime[++cnt] = i;
//		}
//		for (int j = 1; j <= cnt; j++) {
//			if (prime[j] * i > N-5)break;
//			spf[prime[j] * i] = prime[j];
//			if (i % prime[j] == 0)break;
//		}
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	map<int,int>yin;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		int t = a[i];
//		while (spf[t] != 1) {
//			if (yin.count(spf[t])) {
//				cout << 0 << "\n";
//				return;
//			}
//			t /= spf[t];
//		}
//		t = a[i];
//		while (spf[t] != 1) {
//			yin[spf[t]]++;
//			t /= spf[t];
//		}
//	}
//	long long ans = LLONG_MAX;
//	map<int, int>tmp;
//	for (int i = 1; i <= n; i++) {
//		int t = a[i];
//		while (spf[t] != 1) {
//			tmp[spf[t]]++;
//			t /= spf[t];
//		}
//		t = a[i] + 1;
//		while (spf[t] != 1) {
//			if (yin.count(spf[t])&&yin[spf[t]]-tmp[spf[t]]>0) {
//				ans = min(ans, (long long)b[i]);
//			}
//			t /= spf[t];
//		}
//		tmp.clear();
//	}
//	map<int, int>mp;//得到当前因数的最小代价
//	for (int i = 1; i <= n; i++) {
//		int t = a[i] + 1;
//		while (spf[t] != 1) {
//			if (mp.count(spf[t])) {
//				ans = min(ans, (long long)b[i] + mp[spf[t]]);
//			}
//			t /= spf[t];
//		}
//		t = a[i] + 1;
//		while (spf[t] != 1) {
//			if (mp.count(spf[t])) {
//				mp[spf[t]] = min(mp[spf[t]], b[i]);
//			}
//			else {
//				mp[spf[t]] = b[i];
//			}
//			t /= spf[t];
//		}
//	}
//	vector<int>idx(n + 1);
//	for (int i = 1; i <= n; i++) {
//		idx[i] = i;
//	}
//	sort(idx.begin() + 1, idx.end(), [&](int x,int y) {
//		return b[x] < b[y];
//		});
//	//考虑一个加多次
//	for (int j = 1; j <= n; j++) {
//		int i = idx[j];
//		if (b[i] >= ans)break;
//		int t = a[i];
//		while (spf[t] != 1) {
//			tmp[spf[t]]++;
//			t /= spf[t];
//		}
//		for (auto v : yin) {
//			if (v.second - tmp[v.first] > 0) {
//				ans = min((v.first - a[i] % v.first) * (long long)b[i], ans);
//			}
//			if (v.first > a[i])break;
//		}
//		tmp.clear();
//	}
//	cout << ans << "\n";
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	eular(2e5);
//	while (t--) {
//		solve();
//	}
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int spf[N];
//int prime[N];
//int cnt = 0;
//void eular(int n) {
//	for (int i = 1; i <= n; i++) {
//		spf[i] = i;
//	}
//	for (int i = 2; i <= n; i++) {
//		if (spf[i] == i) {
//			prime[++cnt] = i;
//		}
//		for (int j = 1; j <= cnt; j++) {
//			if (prime[j] * i > N)break;
//			spf[prime[j] * i] = prime[j];
//			if (i % prime[j] == 0)break;
//		}
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	unordered_map<int, int>yin;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		int t = a[i];
//		while (spf[t] != 1) {
//			if (yin.count(spf[t])) {
//				cout << 0 << "\n";
//				return;
//			}
//			t /= spf[t];
//		}
//		t = a[i];
//		while (spf[t] != 1) {
//			yin[spf[t]]++;
//			t /= spf[t];
//		}
//	}
//	long long ans = LLONG_MAX;
//	unordered_map<int, int>tmp;
//	for (int i = 1; i <= n; i++) {
//		int t = a[i];
//		while (spf[t] != 1) {
//			tmp[spf[t]]++;
//			t /= spf[t];
//		}
//		t = a[i] + 1;
//		while (spf[t] != 1) {
//			if (yin.count(spf[t]) && yin[spf[t]] - tmp[spf[t]] > 0) {
//				ans = min(ans, (long long)b[i]);
//			}
//			t /= spf[t];
//		}
//		tmp.clear();
//	}
//	unordered_map<int, int>mp;//得到当前因数的最小代价
//	for (int i = 1; i <= n; i++) {
//		int t = a[i] + 1;
//		while (spf[t] != 1) {
//			if (mp.count(spf[t])) {
//				ans = min(ans, (long long)b[i] + mp[spf[t]]);
//			}
//			t /= spf[t];
//		}
//		t = a[i] + 1;
//		while (spf[t] != 1) {
//			if (mp.count(spf[t])) {
//				mp[spf[t]] = min(mp[spf[t]], b[i]);
//			}
//			else {
//				mp[spf[t]] = b[i];
//			}
//			t /= spf[t];
//		}
//	}
//	vector<int>idx(n + 1);
//	for (int i = 1; i <= n; i++) {
//		idx[i] = i;
//	}
//	sort(idx.begin() + 1, idx.end(), [&](int x, int y) {
//		return b[x] < b[y];
//		});
//	b[0] = INT_MAX;
//	//考虑一个加多次
//	int i = idx[1];
//	int t = a[i];
//	while (spf[t] != 1) {
//		tmp[spf[t]]++;
//		t /= spf[t];
//	}
//	for (auto v : yin) {
//		if (v.second - tmp[v.first] > 0) {
//			ans = min((v.first - a[i] % v.first) * (long long)b[i], ans);
//		}
//	}
//	cout << ans << "\n";
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	eular(2e5 + 1);
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int head[N];
//int to[N<<1];
//int nex[N<<1];
//int fa[N];
//int dep[N];
//bool onway[N];
//int cntg = 0;
//vector<array<int, 2>>op;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//
//void dfs(int u, int pa) {
//	dep[u] = dep[pa] + 1;
//	fa[u] = pa;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == pa)continue;
//		dfs(to[ui],u);
//	}
//}
//int od = 1;//当前u可能在的节点的深度奇偶性
//void dfs1(int u) {
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa[u])continue;
//		dfs1(to[ui]);
//	}
//	if (onway[u])return;
//	if (od == (dep[u] & 1)) {
//		op.push_back({ 1,0 });
//		od ^= 1;
//	}
//	op.push_back({ 2,u });
//	op.push_back({ 1,0 });
//	od ^= 1;
//}	
//
//int n=0;
//int ton[N];
//void clear(int n) {
//	for (int i = 1; i <= n; i++) {
//		head[i] = 0;
//		fa[i] = 0;
//		ton[i] = 0;
//		onway[i] = false;
//	}
//	od = 1;
//	cntg = 1;
//	op.clear();
//}
//void solve() {
//	clear(n + 5);
//	cin >> n;
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs(1, 0);
//	int cur = n;
//	while (cur != 1) {
//		onway[cur] = true;
//		ton[fa[cur]] = cur;
//		cur = fa[cur];
//	}
//	onway[1] = true;
//	cur = 1;
//	dfs1(1);
//	while (cur != n) {
//		if (od == dep[cur]) {
//			op.push_back({ 1,0 });
//			od^=1;
//			if (cur == fa[n])break;
//		}
//		op.push_back({ 2,cur });
//		op.push_back({ 1,0 });
//		od ^= 1;
//		cur = ton[cur];
//	}
//	cout << op.size() << "\n";
//	for (int i = 0; i < op.size(); i++) {
//		if (op[i][0] == 1)cout << 1 << "\n";
//		else {
//			cout << op[i][0] << " " << op[i][1] << "\n";
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