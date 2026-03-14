//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	vector<int>cnt(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		cnt[a[i]]++;
//	}
//	int ans = 0;
//	int sum = 0;
//	vector<int>cn(n + 1,0);
//	for (int i = 1; i <= n; i++) {
//		cn[cnt[i]]++;
//	}
//	for (int i = n; i >= 1; i--) {
//		sum += cn[i];
//		ans = max(ans, sum * i);
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
//using namespace std;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<int>apcnt(m + 1);
//	vector<int>appear(m + 1);
//	for (int i = 1,l; i <= n; i++) {
//		cin >> l;
//		for (int j = 1,u; j <= l; j++) {
//			cin >> u;
//			apcnt[u]++;
//			appear[u] = i;
//		}
//	}
//	int one = 0;
//	set<int>c;
//	for (int i = 1; i <= m; i++) {
//		if (apcnt[i] == 0) {
//			cout << "NO\n";
//			return;
//		}
//		else if (apcnt[i] == 1&&!c.count(appear[i])) {
//			one++;
//			c.insert(appear[i]);
//		}
//	}
//	if (one <= n - 2) {
//		cout << "YES\n";
//		return;
//	}
//	cout << "NO\n";
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
//	s = " " + s;
//	vector<int>ans(n + 1);
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == '1') {
//			ans[i] = i;
//		}
//	}
//	int last1 = 0;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == '1') {
//			int up = i - 1;
//			for (int j = last1 + 1; j < i; j++) {
//				ans[j] = up;
//				up--;
//			}
//			last1 = i;
//		}
//	}
//	int up = n;
//	for (int j = last1 + 1; j <= n; j++) {
//		ans[j] = up;
//		up--;
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	cout << ans[i] << " ";
//	//}cout << "*\n";
//	vector<int>pre(n+2,INT_MIN);
//	vector<int>suf(n+2,INT_MAX);
//	for (int i = 1; i <= n; i++) {
//		pre[i] = max(pre[i - 1], ans[i]);
//	}
//	for (int j = n; j >= 1; j--) {
//		suf[j] = min(suf[j + 1], ans[j]);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == '1') {
//			if (pre[i - 1] >= ans[i] || suf[i + 1] <= ans[i]) {
//				cout << "NO\n";
//				return;
//			}
//		}
//		else {
//			if (pre[i - 1]<ans[i] && suf[i + 1]>ans[i]) {
//				cout << "NO\n";
//				return;
//			}
//		}
//	}
//	cout << "YES\n";
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
//int high(int x) {
//	int ans = 0;
//	while (x != 0) {
//		ans++;
//		x >>= 1;
//	}
//	return ans;
//}
//map<int, int>used;
//int ans;
//void f(int l, int r,int w) {
//	//cout << l << " " << r <<" "<<w << "***\n";
//	if (l >= r)return;
//	int nr=INT_MIN, nl=INT_MAX;
//	for (int j = r; j >= l; j--) {
//		if (used.count(j))continue;
//		int h = high(j);
//		int tmp = j ^ ((1 << (h-w)) - 1);
//		if (tmp < l||tmp>r) {
//			nr = max(nr, j);
//			nl = min(nl, j);
//			continue;
//		}
//		ans += 2 * (tmp | j);
//		used.insert({ j,tmp });
//		used.insert({ tmp,j });
//	}
//	f(nl, nr,w+1);
//}
//void solve() {
//	int l, r;
//	cin >> l >> r;
//	int n = r - l + 1;
//	ans = 0;
//	used.clear();
//	vector<int>an;
//	f(l, r,0);
//	for (int i = l; i <= r; i++) {
//		if (!used.count(i))ans += i;
//	}
//	cout << ans << "\n";
//	for (int i = l; i <= r; i++) {
//		if (!used.count(i))cout << i << " ";
//		else cout << used[i] << " ";
//	}
//	cout << '\n';
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
//const int N = 3e5 + 5;
//int mx[N << 2];
//int lzt[N << 2];
//void up(int i) {
//	mx[i] = max(mx[i << 1],mx[i<<1|1]);
//}
//void lazy(int i, int v) {
//	mx[i] += v;
//	lzt[i] += v;
//}
//void down(int i) {
//	if (lzt[i] != 0) {
//		lazy(i << 1, lzt[i]);
//		lazy(i << 1|1, lzt[i]);
//		lzt[i] = 0;
//	}
//}
//void upd(int x,int v, int l, int r, int i) {
//	if (l == r) {
//		mx[i] = v;
//		lzt[i] = 0;
//		return;
//	}
//	int mid = l + r >> 1;
//	down(i);
//	if (x <= mid) {
//		upd(x, v, l, mid, i << 1);
//	}
//	else {
//		upd(x, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//void add(int jl, int jr, int v, int l, int r, int i) {
//	if (jl > jr)return;
//	if (jl <= l && jr >= r) {
//		lazy(i, v);
//		return;
//	}
//	int mid = l + r >> 1;
//	down(i);
//	if (jl <= mid) {
//		add(jl, jr, v, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		add(jl, jr, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//int query(int x, int l, int r, int i) {
//	if (l == r) {
//		return mx[i];
//	}
//	int mid = l + r >> 1;
//	down(i);
//	if (x <= mid) {
//		return query(x,l, mid, i << 1);
//	}
//	else {
//		return query(x, mid + 1, r, i << 1 | 1);
//	}
//}
//int query(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return mx[i];
//	}
//	int mid = l + r >> 1;
//	down(i);
//	int ans = INT_MIN;
//	if (jl <= mid) {
//		ans = max(ans, query(jl, jr, l, mid, i << 1));
//	}
//	if (jr > mid) {
//		ans = max(ans, query(jl, jr, mid + 1, r, i << 1 | 1));
//	}
//	return ans;
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		mx[i] = 0;
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid+1, r, i << 1|1);
//		up(i);
//	}
//	lzt[i] = 0;
//}
//void debug(int l, int r, int i) {
//	if (l == r) {
//		cout << '(' << l-1 << "," << mx[i] << ')' << " ";
//		return;
//	}
//	int mid = l + r >> 1;
//	debug(l, mid, i << 1);
//	debug(mid + 1, r, i << 1 | 1);
//}
//void solve() {
//	int n;
//	cin >> n;
//	build(1, n+1, 1);
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		upd(a[i]+1, 0, 1, n+1, 1);//注意偏移一位，因为0位置有效
//		add(1, a[i], 1, 1, n + 1, 1);
//		cout << query(1, n + 1, 1, n + 1, 1) << ' ';
//		//debug(1, n + 1, 1); cout << "\n-----\n";
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