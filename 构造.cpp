//F. Minimize Fixed Points
//#include<bits/stdc++.h>
//using namespace std;
//vector<int>ans;
//vector<int>vis;
//vector<int>fa;
//void eular(int n) {
//	for (int i = 2; i <= n; i++) {
//		if (vis[i])continue;
//		fa[i] = i;
//		for (int j = i*2; j <= n; j += i) {
//			vis[j] = 1;
//			fa[j]=i;
//		}
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	vis.assign(n + 1, 0);
//	ans.assign(n + 1, 0);
//	fa.assign(n + 2, 0);
//	iota(fa.begin(), fa.end(),0);
//	eular(n);
//	vector<int>b(n+2);
//	iota(b.begin(), b.end(), 0);
//	sort(b.begin() + 1, b.begin()+n+1, [&](int a, int b) {
//		return fa[a] < fa[b];
//		});
//	int start = 1;
//	//for (int i = 1; i <= n; i++) {
//	//	cout << b[i] << " ";
//	//}cout << endl;
//	//for (int i = 1; i <= n; i++) {
//	//	cout << fa[b[i]] << " ";
//	//}cout << endl;
//
//	for (int i = 1; i <= n; i++) {
//		if (fa[b[i]] == fa[b[i + 1]]) {
//			ans[b[i]] = b[i + 1];
//		}
//		else {
//			ans[b[i]] = b[start];
//			start = i + 1;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << ans[i] << " ";
//	}cout << endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//C. Divine Tree
//#include<bits/stdc++.h>
//#define i64 long long
//using namespace std;
//void solve() {
//	i64 n, m;
//	cin >> n >> m;
//	if (n * (n + 1) / 2 < m) { cout << -1 << endl; return; }
//	if (n > m) { cout << -1 << endl; return; }
//	int last = -1;
//	vector<int>a;
//	vector<int>vis(n + 1);
//	m -= n;
//	for (int i = n - 1; i >= 0; i--) {
//		if (m >= i) {
//			vis[i + 1] = 1;
//			a.push_back(i + 1);
//			m -= i;
//		}
//	}
//	cout << a[0]<<endl;
//	for (int i = 0; i < a.size() - 1; i++) {
//		cout << a[i] << " " << a[i + 1] << endl;
//	}
//	int pre = a.back();
//	for (int i = 1; i <= n; i++) {
//		if (!vis[i]) {
//			cout << pre << " " << i<<endl;
//			pre = i;
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


//C. Smilo and Minecraft
//#include<bits/stdc++.h>
//using namespace std;
//string grid[505];
//int g[505][505];
//void solve() {
//	int n, m, k;
//	cin >> n >> m >> k;
//	memset(g, 0, sizeof(g));
//	for (int i = 0; i <n; i++) {
//		cin >> grid[i];
//	}
//	int golds = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			if (grid[i-1][j-1] == 'g') {
//				golds++;
//				int a = max(i - k + 1, 1), b = max(j - k + 1, 1);
//				int c = min(n, i + k - 1), d = min(m, j + k - 1);
//				g[a][b] += 1;
//				g[c + 1][b] -= 1;
//				g[a][d + 1] -= 1;
//				g[c + 1][d + 1] += 1;
//			}
//		}
//	}
//	int ans = INT_MAX;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			g[i][j] = g[i][j] + g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
//			if(grid[i-1][j-1]=='.')ans = min(ans, g[i][j]);
//		}
//	}
//	cout << golds - ans << endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//D. Reachability and Tree
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 2e5 + 10;
//int head[MAXN];
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int siz[MAXN];
//int cnt = 1;
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
////void dfs(int i, int fa) {
////	if (root) {
////		return;
////	}
////	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
////		if (to[ui] == fa)continue;
////		son++;
////		dfs(to[ui], i);
////	}
////	cout << i << " " << son << " " << fa << endl;
////	if (son == 0 && siz[fa] == 2) {
////		root = i;
////		for (int ui = head[i]; ui != 0; ui = nex[ui]) {
////			if (to[ui] == fa)continue;
////			rfa = to[ui];
////		}
////	}
////}
//void dfs2(int i, int fa, int s) {//s为1父到子0子到父
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		if (s)cout << i << " " << to[ui] << endl;
//		else cout << to[ui] << " " << i << endl;
//		dfs2(to[ui], i, 1 - s);
//	}
//}
//void solve() {
//	int n;
//	memset(head, 0, sizeof(head));
//	memset(siz, 0, sizeof(siz));
//	cnt = 1;
//	cin >> n;
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		siz[u]++;
//		siz[v]++;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	int root = 0;
//	int rfa = 0;
//	for (int i = 1; i <= n; i++) {
//		//cout << i << " " << siz[i] << " " << to[head[i]] << " " << siz[to[head[i]]] << endl;
//		if (siz[i] == 2) {
//			root = i;
//			break;
//		}
//	}
//	if (root == 0) {
//		cout << "NO\n";
//		return;
//	}
//	cout << "YES\n";
//	int a = to[head[root]];
//	int b = to[nex[head[root]]];
//	cout << root << " "<<a << endl;
//	cout << b << " " << root << endl;
//	dfs2(a, root, 0);
//	dfs2(b, root, 1);
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//C. Maximum Subarray Sum
//#include<bits/stdc++.h>
//#define i64 long long
//const i64 INF = -1e18 + 10;
//using namespace std;
//void solve() {
//	i64 n, k;
//	cin >> n >> k;
//	string s;
//	cin >> s;
//	s = " " + s;
//	vector<i64>a(n + 1);
//	bool has0 = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i < s.size(); i++) {
//		if (s[i] == '0')has0 = 1;
//	}
//	i64 pre = 0;
//	i64 MAX = INT_MIN;
//	for (int i = 1; i <s.size(); i++) {
//		if (s[i]-'0' == 0) {
//			pre = 0;
//			continue;
//		}
//		pre = pre > 0 ? pre + a[i] : a[i];
//		MAX = max(MAX, pre);
//	}
//	if (MAX > k||MAX!=k&&!has0) {
//		cout << "NO\n";
//		return;
//	}
//	bool flag = 0;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] - '0' == 0) {
//			if (flag) {
//				a[i] = INF; continue;
//			}
//			i64 sum = 0;
//			int j = i - 1;
//			i64 ml = 0;
//			i64 mr = 0;
//			while (j >= 1 && s[j] - '0' != 0) {
//				sum += a[j];
//				ml = max(ml, sum);
//				j--;
//			}
//			j = i + 1;
//			sum = 0;
//			while (j <= n && s[j] - '0' != 0 ) {
//				sum += a[j];
//				mr = max(mr, sum);
//				j++;
//			}
//			a[i] = k - ml-mr;
//			//cout << sum << endl;
//			flag = 1;
//		}
//	}
//	cout << "YES\n";
//	for (int i = 1; i <= n; i++)cout << a[i] << " ";
//	cout << endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//F. Trulimero Trulicina
//#include<bits/stdc++.h>
//using namespace std;
//int gcd(int a, int b) {
//	while (b != 0) {
//		int temp = b;
//		b = a % b;
//		a = temp;
//	}
//	return a;
//}
//void print(int x, int y, int lx, int ly, vector<vector<int>>&ans) {
//	for (int i = 1; i <= lx; i++) {
//		for (int j = 1; j <= ly; j++) {
//			ans[x + i - 1][y + j - 1] = (i - 1) * ly + j;
//		}
//	}
//}
//void solve() {
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<vector<int>>ans(n+1,vector<int>(m+1));
//	int gnk = gcd(n, k);
//	int gmk = gcd(m, k);
//	if (gnk==1) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) {
//				ans[i][j] = (i - 1 + j - 1) % k + 1;
//			}
//		}
//	}
//	else if (gmk==1) {
//		for (int i = 1; i <= m; i++) {
//			for (int j = 1; j <= n; j++) {
//				ans[j][i] = (i - 1 + j - 1) % k + 1;
//			}
//		}
//	}
//	else {
//		int t = gnk * gmk/k;
//		int x = gnk;
//		int y = gmk;
//		if (x % t) {
//			x /= t;
//		}
//		else if (y % t == 0) {
//			y /= t;
//		}
//		if (x == 1) {
//			for (int i = 1; i <= n; i++) {
//				for (int j = 1; j <= m; j++) {
//					ans[i][j] = (i - 1 + j - 1) % k + 1;
//				}
//			}
//		}
//		else if (y == 1) {
//			for (int i = 1; i <= m; i++) {
//				for (int j = 1; j <= n; j++) {
//					ans[j][i] = (i - 1 + j - 1) % k + 1;
//				}
//			}
//		}
//		else {
//			for (int i = 1; i <= n; i += x) {
//				for (int j = 1; j <= m; j += y) {
//					print(i, j, x, y, ans);
//				}
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << ans[i][j] << " ";
//		}
//		cout << "\n";
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//D.Mishkin Energizer
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s = " " + s;
//	array<pair<char, int>, 3 >a;
//	a[0].first = 'L';
//	a[0].second = 0;
//	a[1].first = 'I';
//	a[1].second = 0;
//	a[2].first = 'T';
//	a[2].second = 0;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == 'L') {
//			a[0].second++;
//		}
//		else if (s[i] == 'I') {
//			a[1].second++;
//		}
//		else a[2].second++;
//	}
//	sort(a.begin(), a.end(), [&](auto x, auto y) {
//		return x.second < y.second;
//		});
//	//cout << a[0].first << " " << a[0].second << endl;
//	//cout << a[1].first << " " << a[1].second << endl;
//	//cout << a[2].first << " " << a[2].second << endl;
//	int zero = 0;
//	for (int i = 0; i <= 2; i++) {
//		if (a[i].second == 0)zero++;
//	}
//	if (zero == 2) {
//		cout << -1 << endl;
//		return;
//	}
//	int diff = a[1].second - a[0].second;
//	int diff1 = a[2].second + diff - a[1].second;
//	cout << (diff + diff1) * 2 << endl;
//	if (diff == 0) {
//		for (int i = 1; i <= n;i++){
//			if (i + 1 <= n && s[i] == a[2].first && s[i + 1] != a[2].first) {
//				for (int j = 1; j <= a[2].second - a[0].second; j++) {
//					cout << i << "\n" << i << "\n";
//				}
//				break;
//			}
//			if (i - 1 >= 1 && s[i] == a[2].first && s[i - 1] != a[2].first) {
//				int c = i - 1;
//				for (int j = 1; j <= a[2].second - a[0].second; j++) {
//					cout << c << "\n" << c + 1 << "\n";
//					c += 2;
//				}
//				break;
//			}
//		}
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		//cout << i << " " << s[i] << " " << s[i + 1] << " " << a[1].first << endl;
//		if (i + 1 <= n && s[i] == a[1].first && s[i + 1] != a[1].first) {
//			for (int j = 1; j <= diff; j++) {
//				cout << i << "\n" << i << "\n";
//			}
//			if (s[i + 1] == a[2].first) {
//				for (int j = 1; j <= diff1; j++) {
//					cout << i + 1 << "\n" << i + 1 << "\n";
//				}
//			}
//			else {
//				for (int j = 1; j <= diff1; j++) {
//					cout << i + 2 << "\n" << i + 2 << "\n";
//				}
//			}
//			break;
//		}
//		if (i - 1 >= 1 && s[i] == a[1].first && s[i - 1] != a[1].first) {
//			int c = i - 1;
//			for (int j = 1; j <= diff; j++) {
//				cout << c << "\n" << c + 1 << "\n";
//				c += 2;
//			}
//			if (s[i - 1] == a[2].first) {
//				for (int j = 1; j <= diff1; j++) {
//					cout << c  << "\n" << c  << "\n";
//				}
//			}
//			else {
//				for (int j = 1; j <= diff1; j++) {
//					cout << c - 1 << "\n" << c - 1 << "\n";
//				}
//			}
//			break;
//		}
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


//这题不会
// 引理（伯特兰假设）：对于任意正整数 x，区间[x, 2x]内存在至少一个质数p。
//A.Simple Permutation
//#include<bits/stdc++.h>
//using namespace std;
//int prime[100005];
//int Notprime[100005];
//int cnt = 0;
//void eular(int n) {
//	for (int i = 2; i <= n; i++) {
//		if (!Notprime[i])prime[cnt++] = i;
//		for (int j = 0; j < cnt; j++) {
//			if (prime[j] * i > n)break;
//			Notprime[prime[j] * i] = 1;
//			if (i % prime[j] == 0)break;
//		}
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<bool>vis(n + 1);
//	vector<int>ans;
//	int p;
//	for (int x=1;; ++x) {
//		if (!Notprime[n / 2 + x]) {
//			p = n / 2 + x;
//			break;
//		}
//		if (!Notprime[n / 2 - x]) {
//			p = n / 2 - x;
//			break;
//		}
//	}
//	ans.push_back(p);
//	for (int i = 1; i <= n; i++) {
//		if (p - i >= 1) {
//			ans.push_back(p - i);
//		}
//		if (p + i <= n) {
//			ans.push_back(p + i);
//		}
//	}
//	for (auto i : ans) {
//		cout << i << " ";
//	}
//	cout << endl;
//}
//int main() {
//	int t;
//	eular(100005);
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//	
//}


//不会666
//C. Serval and The Formula
//#include<bits/stdc++.h>
//#define i64 long long
//using namespace std;
//int bits(int x) {
//	int cnt = 0;
//	while (x != 0) {
//		x >>= 1;
//		cnt++;
//	}
//	return cnt;
//}
//void solve() {
//	i64 x, y;
//	cin >> x >> y;
//	if (x == y) {
//		cout << -1 << endl;
//		return;
//	}
//	if (x < y)swap(x, y);
//	int ans = 1;
//	while (ans < x) {
//		ans <<= 1;
//	}
//	ans = ans-x;
//	cout << ans << endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//推理
//D. Arcology On Permafrost
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, m, k;
//	cin >> n >> m >> k;
//	int sav = n / ((m + 1) * k) * k;
//	if (n >= ((m + 1) * k)) {
//		sav += n % ((m + 1) * k) / (m + 1);
//		for (int i = 1; i <=n; i++) {
//			cout << (i - 1) % sav << " ";
//		}cout << endl;
//	}
//	else {
//		vector<int>ans(n + 1, -1);
//		int cur = 0;
//		for (int i = 1; i <= n; i++) {
//			if (ans[i] != -1)continue;
//			for (int j = i, c = 0; c <= m && j <= n; c++, j += k) {
//				ans[j] = cur;
//			}
//			cur++;
//		}
//		for (int i = 1; i <= n; i++) {
//			cout << ans[i] << " ";
//		}cout << endl;
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//简单推理 coding
//C. You Soared Afar With Grace
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	vector<int>posA(n + 1);
//	vector<int>posB(n + 1);
//	int same = 0;
//	int samepos = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		posA[a[i]] = i;
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//		posB[b[i]] = i;
//		if (b[i] == a[i]) { same++; samepos = i; }
//	}
//	if (same > 1||(n&1)&&same==0||!(n&1)&&same!=0) {
//		cout << -1 << endl;
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		//cout << a[i] << " " << posB[a[i]] << " " << b[posB[a[i]]] << endl;
//		if (a[posB[a[i]]] != b[i]) {
//			cout << -1 << endl;
//			return;
//		}
//	}
//	vector<pair<int,int>>ans;
//	if ((n & 1) && samepos != (n + 1) / 2) {
//		ans.push_back(make_pair(samepos, (n + 1) / 2));
//		int p1 = samepos, p2 = (n + 1) / 2;
//		int x = a[p1], y = a[p2];
//		a[p1] = y;
//		a[p2] = x;
//		posA[y] = p1;
//		posA[x] = p2;
//		int t = b[p1];
//		b[p1] = b[p2];
//		b[p2] = t;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (posA[b[i]] == n - i + 1)continue;
//		ans.push_back(make_pair(posA[b[i]], n - i + 1));//交换posA[b[i]]位置与n-i+1位置
//		int p1 = posA[b[i]], p2 = n - i + 1;
//		int x = a[posA[b[i]]], y = a[n - i + 1];
//		//cout << posA[b[i]] << " " << n - i + 1 << endl;
//		//cout << x << " " << y << endl;
//		a[p1] = y;
//		a[p2] = x;
//		posA[y] = p1;
//		posA[x] = p2;
//		int t = b[p1];
//		b[p1] = b[p2];
//		b[p2] = t;
//		//for (int i = 1; i <= n; i++) {
//		//	cout << a[i] << " ";
//		//}cout << endl;
//		//for (int i = 1; i <= n; i++) {
//		//	cout << b[i] << " ";
//		//}cout << endl;
//	}
//	cout << ans.size() << endl;
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i].first << " " << ans[i].second << endl;
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//新思路 公式变形
//A. Breach of Faith
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>b(2 * n +1);
//	unordered_set<int>ele;
//	for (int i = 1; i <= 2*n; i++) {
//		cin >> b[i];
//		ele.insert(b[i]);
//	}
//	sort(b.begin(), b.end());
//	vector<int>a(2 * n + 2);
//
//	a[1] = b[2 * n];
//	for (int i = 1; i <=n-1; i++) {
//		a[2*i] = b[i];
//		a[2 * i+1] = b[i + n];
//	}
//	a[2 * n + 1] =b[n] ;
//	a[2 * n] = a[1] + a[2 * n + 1];
//	for (int i = 1; i <= n - 1; i++) {
//		a[2 * n] -= a[2*i];
//		a[2 * n] += a[2*i+1];
//	}
//	for (int i = 1; i <= 2*n + 1; i++) {
//		cout << a[i] << " ";
//	}
//	cout << endl;
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//新思路
//F.Goodbye, Banker Life
//要快速判断组合数 C(n, k)（即从n个元素中选k个的组合数）是奇数还是偶数，可以利用卢卡斯定理（Lucas' Theorem） 推导的结论，
// 核心是通过二进制表示判断。关键结论组合数C(n, k)为奇数的充要条件是：k的二进制表示中，每一位的数字都不大于n对应位的数字。
// 换句话说，若将n和k转化为二进制后，k中所有为1的位，在n中对应的位也必须为1，则C(n, k)是奇数；否则为偶数。
// k!中因子 2 的幂次ck可通过递推计算：基础：c0​= c1​= 0（0!和 1!中没有因子 2）；
// 递推：ck= ck−1+ f(k)，其中f(k)是k中含有的因子 2 的最高幂次（即最大的m使得2m∣k）。
// 用公式表示为：(n& k) == k
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	//if (n == 1) {
//	//	cout << k << endl;
//	//	return;
//	//}
//	for (int i = 0; i <= n - 1; i++) {
//		if (((n - 1) & i) == i) {
//			cout << k << " ";
//		}
//		else cout << 0 << " ";
//	}
//	cout << endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//凑数字
//E.Do You Love Your Hero and His Two - Hit Multi - Target Attacks ?
//这样不好,应该每次都找最大的
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int k;
//	cin >> k;
//	vector<int>a(32);
//	vector<int>ans;
//	int sum = 0;
//	for (int i = 500; i >= 2; i--) {
//		if (k >= i * (i - 1) / 2) {
//			k -= i * (i - 1) / 2;
//			sum += i;
//			ans.push_back(i);
//		}
//	}
//	while (k != 0){
//		ans.push_back(2);
//		sum += 2;
//		k -= 1;
//	}
//	cout << sum << endl;
//	int curx = 1;
//	for (int i = 0; i < ans.size(); i++) {
//		for (int j = 1; j <= ans[i]; j++) {
//			cout << i + 1 << " " << curx << endl;
//			curx++;
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
//这样好
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int k;
//	cin >> k;
//	vector<int>a(32);
//	vector<int>ans;
//	int sum = 0;
//	while (k != 0) {
//		for (int i = int(sqrt(2 * k)+5); i >= 2; i--) {
//			if (i * (i - 1) / 2 <= k) {
//				k -= i * (i - 1) / 2;
//				ans.push_back(i);
//				sum += i;
//				break;
//			}
//		}
//	}
//	cout << sum << endl;
//	int curx = 1;
//	for (int i = 0; i < ans.size(); i++) {
//		for (int j = 1; j <= ans[i]; j++) {
//			cout << i + 1 << " " << curx << endl;
//			curx++;
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


//666 新思路
//C. Trapmigiano Reggiano
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1e5 + 5;
//vector<vector<int>>g;
//vector<vector<int>>dep;
//int maxDep = -1;
//void dfs(int i, int fa,int de) {
//	maxDep = max(maxDep, de);
//	dep[de].push_back(i);
//	for (auto v : g[i]) {
//		if (v == fa)continue;
//		dfs(v, i, de+ 1);
//	}
//}
//void solve() {
//	int n, st, en;
//	cin >> n >> st >> en;
//	g.assign(n + 1, {});
//	dep.assign(n, {});
//	maxDep = 0;
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	dfs(en, 0, 0);
//	for (int i = maxDep; i >= 0; i--) {
//		for (auto v : dep[i]) {
//			cout << v << " ";
//		}
//	}
//	cout << endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//简单推导
//E.Skibidus and Rizz
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, m, k;
//	cin >> n >> m >> k;
//	char a = '0', b = '1';
//	if (abs(n - m) > k||max(n,m)<k) {
//		cout << -1<<endl;
//		return;
//	}
//	if (n < m) {
//		swap(n, m);
//		swap(a, b);
//	}
//	for (int i = 1; i <= k; i++) {
//		cout << a;
//	}
//	for (int i = 1; i <= n - k; i++) {
//		cout << b << a ;
//	}
//	for (int i = 1; i <= m - n + k; i++) {
//		cout << b;
//	}cout << endl;
//
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//666 **推理分析
//C. Customer Service
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<vector<int>>event(n + 1,vector<int>(n+1));
//	vector<int>back1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cin >> event[i][j];
//		}
//		int t = 0;
//		for (int j = n; j >= 1 && event[i][j] == 1; j--,t++) {
//		}
//		back1.push_back(t);
//	}
//	sort(back1.begin(), back1.end());
//	int ans = 1;
//	for (int i = 0; i < back1.size(); i++) {
//		if (back1[i] >= ans) {
//			ans++;
//		}
//	}
//	cout << min(ans, n)<<endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//666操你妈
//C. Trip to the Olympiad
//#include<bits/stdc++.h>
//using namespace std;
//int bits(int x) {
//	if (x == 0)return -1;
//	int ans = 0;
//	while ((x >> 1) != 0) {
//		ans++;
//		x >>= 1;
//	}
//	return ans;
//}
//void solve() {
//	int l,r,a,b,c;
//	cin >> l >> r;
//	int h = bits(r);
//	int d = bits(l);
//	int ans = 0;
//	bool flag = 0;
//	if (h - d > 1) {
//		ans |= (1 << (h - 1));
//		for (int i = h - 2; i >= 0; i--) {
//			if ((((l >> i) & 1) == ((r >> i) & 1)) && (l >> i) & 1) {
//				continue;
//			}
//			ans |= 1 << i;
//		}
//	}
//	if (h - d == 1) {
//		if ((r >> (h - 1)) & 1) {
//			ans |= 1 << h;
//			for (int i = h - 2; i >= 0; i--) {
//				if ((((l >> i) & 1) == ((r >> i) & 1)) && (l >> i) & 1) {
//					continue;
//				}
//				ans |= 1 << i;
//			}
//		}
//		else {
//			int a1 = 0,a2=0;
//			cout << "haha\n";
//			a1 |= 1 << h;
//			for (int i = h - 2; i >= 0; i--) {
//				if ((((l >> i) & 1) == ((r >> i) & 1)) && !((l >> i) & 1)) {
//					a1 |= 1;
//				}
//			}
//			a2 |= 1 << (h - 1);
//			for (int i = h - 2; i >= 0; i--) {
//				if ((((l >> i) & 1) == ((r >> i) & 1)) && (l >> i) & 1) {
//					continue;
//				}
//				a2 |= 1;
//			}
//			if (a1 > l && a1 < r)ans = a1;
//			if (a2 > l && a2 < r)ans = a2;
//		}
//	}
//	else {
//		for (int i = h; i >= 0; i--) {
//			if (flag) {
//				if ((((l >> i) & 1) == ((r >> i) & 1)) && (l >> i) & 1) {
//					continue;
//				}
//				ans |= 1 << i;
//			}
//			else {
//				//cout << i << " :" << (((l >> i) & 1) == ((r >> i) & 1)) << endl;
//				if ((((l >> i) & 1) == ((r >> i) & 1))) {
//					if (((l >> i) & 1)) {
//						ans |= 1 << i;
//					}
//				}
//				else {
//					flag = 1;
//				}
//			}
//		}
//	}
//	cout << l << " " << ans << " " << r << endl;
//	cout << bitset<32>(l) << endl;
//	cout << bitset<32>(ans) << endl;
//	cout << bitset<32>(r) << endl;
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
//	int l, r;
//	cin >> l >> r;
//	int ans = 0;
//	for (int i = 30; i >= 0; i--) {
//		if ((r >> i) & 1)ans |= 1 << i;
//		if (r >> i != l >> i) {
//			break;
//		}
//	}
//	int c = ans == r ? ans - 2 : ans + 1;
//	cout << c << " " << ans << " " << ans-1<< endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//C. The Trail
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	string s;
//	vector<vector<int>>grid(n + 1, vector<int>(m + 1));
//	vector<int>sumR(n + 1);
//	vector<int>sumC(m + 1);
//	cin >> s;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> grid[i][j];
//			sumR[i] += grid[i][j];
//			sumC[j] += grid[i][j];
//		}
//	}
//	int x = 1, y = 1;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] == 'D') {
//			grid[x][y] = -sumR[x];
//			sumC[y] += -sumR[x];
//			sumR[x] = 0;
//			x++;
//		}
//		else {
//			grid[x][y] = -sumC[y];
//			sumR[x] += -sumC[y];
//			sumC[y] = 0;
//			y++;
//		}
//	}
//	grid[x][y] = -sumC[y];
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << grid[i][j] << " ";
//		}
//		cout << "\n";
//	}
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//F.Fix Flooded Floor
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	string g[2];
//	cin >> g[0];
//	cin >> g[1];
//	bool none = 0;
//	bool multiple = 0;
//	for (int i = 0; i < n; i++) {//填到i位置时左侧均以填好
//		if (g[0][i] == '.' && g[1][i] != '.' && (i+1>=n||g[0][i+1]!='.')|| g[1][i] == '.' && g[0][i] != '.' && (i + 1 >= n || g[1][i + 1] != '.')) {
//			none = 1;
//		}
//		else if (i + 1 < n && g[0][i] == '.' && g[0][i + 1] == '.' && g[1][i] == '.' && g[1][i + 1] == '.') {
//			multiple = 1;
//			g[0][i] = '1';
//			g[0][i + 1] = '1';
//			g[1][i] = '1';
//			g[1][i + 1] = '1';
//		}
//		if (g[0][i] == '.' && g[1][i] == '.') {
//			g[0][i] = '1';
//			g[1][i] = '1';
//		}
//		else if (g[0][i] == '.' && g[0][i + 1] == '.') {
//			g[0][i] = '1';
//			g[0][i + 1] = '1';
//		}
//		else if (g[1][i] == '.' && g[1][i + 1] == '.') {
//			g[1][i] = '1';
//			g[1][i + 1] = '1';
//		}
//	}
//	if (none)cout << "None\n";
//	else if (multiple)cout << "Multiple\n";
//	else cout << "Unique\n";
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


////A. Adrenaline Rush
//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	vector<int>pos(n + 1);
//	iota(b.begin(), b.end(), 0);
//	iota(pos.begin(), pos.end(), 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	vector<array<int,2>>ans;
//	for (int i = n; i >= 1; i--) {
//		for (int j = pos[a[i]] - 1; j >= 1; j--) {
//			swap(pos[b[j]],pos[b[j + 1]]);
//			swap(b[j], b[j + 1]);
//			ans.push_back({ b[j + 1], b[j] });
//		}
//		for (int j = 2; j <= i; j++) {
//			swap(pos[b[j]], pos[b[j-1]]);
//			swap(b[j], b[j-1]);
//			ans.push_back({ b[j], b[j-1] });
//		}
//		//for (auto v : b) {
//		//	cout << v << " ";
//		//}cout << endl;
//		//for (auto v : pos) {
//		//	cout << v << " ";
//		//}cout << endl; cout << endl;
//	}
//	cout << ans.size() << endl;
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i][1] << " " << ans[i][0] << "\n";
//	}
//}


//C. MEX Cycle
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, x, y;
//	cin >> n >> x >> y;
//	if (!(n & 1)) {
//		if (x % 2 == y % 2) {
//			for (int i = 1; i <= n; i++) {
//				if (i == x)cout << 2 << " ";
//				else {
//					cout << (i & 1) << " ";
//				}
//			}
//			cout << endl;
//		}
//		else {
//			for (int i = 1; i <= n; i++) {
//				cout << (i & 1) << " ";
//			}
//			cout << endl;
//		}
//		return;
//	}
//	else {
//		for (int i = 1; i <= n; i++) {
//			if (i == x)cout << 2 << " ";
//			else {
//				cout << (abs((x - i) + (i > x)) & 1) << " ";
//			}
//		}cout << endl;
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//C. Ordered Permutations
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	if (n<60&&k > (long long)(1) << (n - 1)) {
//		cout << -1 << endl;
//		return;
//	}
//	int l = 1, r = n;
//	vector<int>ans(n + 1);
//	for (int i = n - 2; i >= 0; i--) {
//		if (i > 60) {
//			ans[l++] = n - i - 1;
//			continue;
//		}
//		if (k > ((long long)(1) << i)) {
//			ans[r--] = n - i - 1;
//			k -= ((long long)(1) << i);
//		}
//		else {
//			ans[l++] = n - i - 1;
//		}
//	}
//
//	for (int i = 1; i <= n; i++) {
//		if (ans[i] == 0)cout << n << " ";
//		else cout << ans[i] << " ";
//	}cout << endl;
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//666
//D. Shohag Loves GCD
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 10;
//int p[N];
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(m + 1);
//	vector<int>ans(n + 1);
//	for (int i = 1; i <= m; i++) {
//		cin >> a[i];
//	}
//	int nex=a[1];
//	if (m < int(log2(n)) + 1) {
//		cout << -1 << '\n';
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << a[m - p[i]] << ' ';
//	}
//	cout << '\n';
//
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	for (int i = 2; i < N; i++) {
//		if (p[i])continue;
//		for (int j = i; j < N; j+=i) {
//			int x = j;
//			while (x % i == 0)x /= i,++p[j];
//		}
//	}
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}