//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	set<int>c;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		c.insert(a[i]);
//	}
//	cout << c.size() << '\n';
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
//	string s;
//	cin >> s;
//	int cnt = 0;
//	int cur = 0;
//	int one = 0;
//	for (int i = 0; i < s.size(); i++) {
//		one += s[i] - '0';
//		if (cur != s[i] - '0') {
//			cnt++;
//			cur = s[i] - '0';
//		}
//		cnt++;
//	}
//	if (one == s.size() || one == 0) {
//		cout << cnt << "\n";
//		return;
//	}
//	int mx1 = 0;
//	int c1 = 0;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] == '1') {
//			c1++;
//			mx1 = max(c1, mx1);
//		}
//		else {
//			c1 = 0;
//		}
//	}
//	if (mx1 == one) {
//		if (s[s.size() - 1] == '1')cout << cnt << "\n";
//		else cout << cnt - 1 << '\n';
//	}
//	else {
//		cout << cnt - 2 << "\n";
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
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		if (a[i] <= k)a[i] = -1;
//		else a[i] = 1;
//	}
//	vector<int>psum(n + 2);
//	vector<int>pmax(n + 2,INT_MIN);
//	vector<int>pmin(n + 2,INT_MAX);
//	for (int i = 1; i <= n; i++) {
//		psum[i] = psum[i - 1] + a[i];
//		pmax[i] = max(psum[i], pmax[i - 1]);
//		pmin[i] = min(psum[i], pmin[i - 1]);
//	}
//	vector<int>bsum(n + 2);
//	vector<int>bmax(n + 2,INT_MIN);
//	vector<int>bmin(n + 2,INT_MAX);
//	for (int i = n; i >= 1; i--) {
//		bsum[i] = bsum[i + 1] + a[i];
//		bmax[i] = max(bsum[i], bmax[i + 1]);
//		bmin[i] = min(bsum[i], bmin[i + 1]);
//	}
//	for (int l = 1; l <=n-2; l++) {
//		if (psum[l] > 0) {
//			continue;
//		}
//		else {
//			if (bmin[l + 2] <= 0 || bsum[l + 1] - bmax[l + 2] <= 0) {
//				cout << "YES\n";
//				return;
//			}
//		}
//	}
//	for (int r = n; r >= 3; r--) {
//		if (bsum[r] > 0)continue;
//		else {
//			if (pmin[r - 2] <= 0 || psum[r - 1] - pmax[r - 2] <= 0) {
//				cout << "YES\n";
//				return;
//			}
//		}
//	}
//	cout << "NO\n";
//	return;
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
//int head[N];
//int to[N];
//int nex[N];
//int cnt = 1;
//int n = 0;
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//int siz[N];
//int fa[N];
//int find(int i) {
//	if (i != fa[i]) {
//		fa[i] = find(fa[i]);
//	}
//	return fa[i];
//}
//void merge(int x,int y) {
//	int fx = find(x);
//	int fy = find(y);
//	fa[fy] = fx;
//	siz[fx] += siz[fy];
//}
//void build(int n) {
//	for (int i = 0; i <= n; i++) {
//		fa[i] = i;
//		siz[i] = 1;
//	}
//}
//void solve() {
//	cin >> n;
//	for (int i = 0; i <= n; i++) {
//		head[i] = 0;
//	}
//	cnt = 1;
//	vector<int>a(n + 1);
//	vector<int>nxt(n + 1);
//	vector<int>lst(n + 1);
//	vector<int>ide(n + 1);
//	int hnode = 1;
//	for (int i = 1; i <= n - 1; i++) {
//		nxt[i] = i + 1;
//	}
//	for (int i = 2; i <= n; i++) {
//		lst[i] = i - 1;
//	}
//	int mx = -2;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		mx = max(mx, a[i]);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (a[i] == -1) {
//			a[i] = mx + 1;
//		}
//	}
//	build(n + 1);
//	for (int i = 3; i <= n-1; i++) {
//		if (a[i] == a[i - 1]) {
//			merge(i - 1, i);
//		}
//	}
//	//cout << 2 << " " << nxt[2] << " &*&*\n";
//	//有向边表示去往的点比该点大
//	vector<bool>hasEdge(n + 1, 0);
//	for (int i = 1; i <= mx; i++) {
//		for (int j = hnode; j != 0; j = nxt[j]) {
//			if (a[j] > i) {
//				if (i & 1) {
//					if (nxt[j] != 0) { 
//						int fj = find(j);
//						int fnj = find(nxt[j]);
//						addEdge(fj, fnj);
//						ide[fnj]++;
//						hasEdge[fj] =hasEdge[fnj]=1;
//					}
//					if (lst[j] != 0) {
//						int fj=find(j), flj=find(lst[j]);
//						addEdge(fj, flj);
//						ide[flj]++;
//						hasEdge[fj] = hasEdge[flj] = 1;
//					}
//				}
//				else {
//					if (nxt[j] != 0) {
//						int fj = find(j);
//						int fnj = find(nxt[j]);
//						addEdge(fnj, fj);
//						ide[fj]++;
//						hasEdge[fj] = hasEdge[fnj] = 1;
//					}
//					if (lst[j] != 0) {
//						int fj = find(j), flj = find(lst[j]);
//						addEdge(flj, fj);
//						ide[fj]++;
//						hasEdge[fj] = hasEdge[flj] = 1;
//					}
//				}
//			}
//			else {
//				if (j != 0 && j == hnode && nxt[j] != 0) {
//					if (i & 1) {
//						int fnj = find(nxt[j]), fj = find(j);
//						addEdge(fnj, fj);
//						ide[fj]++;
//						hasEdge[fj] = hasEdge[fnj] = 1;
//					}
//					else {
//						int fnj = find(nxt[j]), fj = find(j);
//						addEdge(fj, fnj);
//						ide[fnj]++;
//						hasEdge[fj] = hasEdge[fnj] = 1;
//					}
//				}
//				else if (j != 0 && nxt[j] == 0 && lst[j] != 0) {
//					if (i & 1) {
//						int flj = find(lst[j]), fj = find(j);
//						addEdge(flj, fj);
//						ide[fj]++;
//						hasEdge[fj] = hasEdge[flj] = 1;
//					}
//					else {
//						int flj = find(lst[j]), fj = find(j);
//						addEdge(fj, flj);
//						ide[flj]++;
//						hasEdge[fj] = hasEdge[flj] = 1;
//					}
//				}
//			}
//		}
//		for (int j = hnode; j != 0; j = nxt[j]) {
//			if (a[j] > i)continue;
//			if (j == hnode) {
//				hnode = nxt[j];
//			}
//			lst[nxt[j]] = lst[j];
//			nxt[lst[j]] = nxt[j];
//			nxt[0] = lst[0] = 0;
//		}
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	cout << i << " : ";
//	//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//	//		cout << to[ui] << " ";
//	//	}cout << "**\n";
//	//}
//	queue<int>qu;
//	vector<int>ans(n + 1);
//	int cn = 0;
//	for (int i = 1; i <= n; i++) {
//		if (fa[i]==i&&ide[i] == 0&&hasEdge[i]) {
//			qu.push(i);
//		}
//	}
//	while (!qu.empty()) {
//		int u = qu.front();
//		for (int i = 0; i < siz[u]; i++) {
//			ans[u+i] = ++cn;
//		}
//		qu.pop();
//		for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//			int v = to[ui];
//			if (--ide[v] == 0) {
//				qu.push(v);
//			}
//		}
//	}
//	//for (int i = 1, j = 1; i <= n;) {
//	//	while (j <= n && a[j] == a[i]) {
//	//		j++;
//	//	}
//	//	if (j != n + 1) {
//	//		if (ans[j] > ans[j - 1]) {
//	//			sort(ans.begin() + i, ans.begin() + j);
//	//		}
//	//		else {
//	//			sort(ans.begin() + i, ans.begin() + j, [&](int x, int y) {
//	//				return x > y;
//	//				});
//	//		}
//
//	//	}
//	//	else {
//	//		if (ans[i] > ans[i - 1]) {
//	//			sort(ans.begin() + i, ans.begin() + j);
//	//		}
//	//		else {
//	//			sort(ans.begin() + i, ans.begin() + j, [&](int x, int y) {
//	//				return x > y;
//	//				});
//	//		}
//	//	}
//	//	i = j;
//	//}
//	for (int i = 1; i <= n; i++) {
//		cout << ans[i] << " ";
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
//using namespace std;
//int p0;
//struct node {
//	int num, p;
//	bool operator<(const node& y)const {
//		if (y.num == num) {
//			if (p > p0 && y.p > p0) {
//				return p > y.p;
//			}
//			return p < y.p;
//		}
//		return num < y.num;
//	}
//};
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n);
//	vector<node>b(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		b[i].num = a[i];
//		b[i].p = i;
//		if (a[i] == -1) {
//			p0 = i;
//		}
//	}
//	sort(b.begin(), b.end());
//	int l = 1, r = n;
//	vector<int>ans(n);
//	for (int i = 1; i < n; i++) {
//		if (b[i].num & 1) {
//			ans[b[i].p] = r--;
//		}
//		else {
//			ans[b[i].p] = l++;
//		}
//	}
//	ans[p0] = r;
//	for (int i = 0; i < n; i++) {
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
