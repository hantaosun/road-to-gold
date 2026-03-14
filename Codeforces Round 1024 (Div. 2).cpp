//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, m, p, q;
//	cin >> n >> m >> p >> q;
//	if (n%p==0&&n/p*q!=m) {
//		cout << "NO\n";
//	}
//	else cout << "YES\n";
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
//		a[i] = abs(a[i]);
//	}
//	int t = a[1];
//	sort(a.begin()+1, a.end());
//	for (int i = 1; i <= n; i++) {
//		if (a[i] == t) {
//			if (i > n / 2+1) {
//				cout << "NO\n";
//			}
//			else cout << "YES\n";
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
//using namespace std;
//int grid[1005][1005];
//void solve() {
//	int n;
//	cin >> n;
//	int cur = n * n - 1;
//	for (int s = 0; s <= n / 2; s++) {
//		for (int i = s; i <= n - s-1; i++) {
//			grid[s][i] = cur--;
//		}
//		for (int i = s+1; i <= n - s - 1;i++) {
//			grid[i][n - s - 1] = cur--;
//		}
//		for (int i = n - s - 2; i >= s; i--) {
//			grid[n - s - 1][i] = cur--;
//		}
//		for (int i = n - s - 2; i > s; i--) {
//			grid[i][s] = cur--;
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << grid[i][j] << " ";
//		}
//		cout << endl;
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
//int tree[200005];
//int n;
//int lowbit(int x) {
//	return x & (-x);
//}
//void add(int i) {
//	while (i <= n) {
//		tree[i] += 1;
//		i += lowbit(i);
//	}
//}
//int sum(int i) {
//	int ans = 0;
//	while (i > 0){
//		ans += tree[i];
//		i -= lowbit(i);
//	}
//	return ans;
//}
//void solve() {
//	
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		tree[i] = 0;
//	}
//	vector<int>a(n + 1);
//	vector<int>od;
//	vector<int>ev;
//	od.push_back(0);
//	ev.push_back(0);
//	int jo = 0;//数组中逆序对数量奇偶性
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		if (i & 1) {
//			od.push_back(a[i]);
//		}
//		else {
//			ev.push_back(a[i]);
//		}
//		if ((i - 1 - sum(a[i] - 1)) & 1) {
//			//cout << jo << endl;
//			jo ^= 1;
//		}
//		add(a[i]);
//	}
//	sort(od.begin()+1, od.end());
//	sort(ev.begin()+1, ev.end());
//	vector<int>ans;
//	ans.push_back(0);
//	for (int i = 1; i <= n / 2; i++) {
//		ans.push_back(od[i]);
//		ans.push_back(ev[i]);
//	}
//	if (n & 1) {
//		ans.push_back(od[n / 2 + 1]);
//	}
//	for (int i = 1; i <= n; i++) {
//		tree[i] = 0;
//	}
//	int jo1=0;
//	for (int i = 1; i <=n; i++) {
//		if ((i - 1 - sum(ans[i] - 1)) & 1) {
//			//cout << jo1 << endl;
//			jo1 ^= 1;
//		}
//		add(ans[i]);
//	}
//	if (jo!=jo1) {
//		swap(ans[ans.size() - 1], ans[ans.size() - 3]);
//	}
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
//#define int long long
//#define pii pair<int,int>
//#define mkp make_pair
//using namespace std;
//struct Compare1 {
//	bool operator()(pii a,pii b) {
//		if (a.first == b.first) {
//			return a.second < b.second;
//		}
//		return a.first < b.first;
//	}
//};
//struct Compare2 {
//	bool operator()(pii a,pii b) {
//		if (a.first == b.first) {
//			return a.second > b.second;
//		}
//		return a.first < b.first;
//	}
//};
//vector<int>a;
//vector<bool>used;
//vector<bool>got;
//int f(int l, int r) {
//	int ans = 0;
//	int mid = l + r >> 1;
//	set<pii,Compare1>left;
//	set<pii,Compare2>right;
//	for (int i = l; i <= mid; i++) {
//		if (!used[i]) {
//			left.insert(mkp(a[i], i));
//		}
//	}
//	for (int i = r; i > mid; i--) {
//		if (!used[i]) {
//			right.insert(mkp(a[i], i));
//		}
//	}
//	for (auto it = right.begin(); it != right.end(); it++) {
//
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	a.resize(n + 1);
//	used.assign(n + 1, 0);
//	got.assign(n + 1, 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	map<int,int>has;
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
//	vector<int>a(n + 1);
//	vector<int>la(n + 1,-1);
//	vector<int>ra(n + 1,-1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	set<int>h;
//	for (int i = 1; i <= n+1; i++) {
//		h.insert(i);
//	}
//	for (int i = 1; i <= n; i++) {
//		auto it = h.upper_bound(a[i]);
//		if (it != h.begin()) {
//			it--;
//			la[i] = i;
//			h.erase(it);
//		}
//	}
//	h.clear();
//	for (int i = 1; i <= n+1; i++) {
//		h.insert(i);
//	}
//	for (int i = n; i >= 1; i--) {
//		auto it = h.upper_bound(a[i]);
//		if (it != h.begin()) {
//			it--;
//			ra[i] = i;
//			h.erase(it);
//		}
//	}
//	int l = 1, r = n,ans=0;
//	while (l < r) {
//		while (l <= n && la[l] == -1)l++;
//		while (r >= 1 && ra[r] == -1)r--;
//		if (l<r) {
//			ans += r - l;
//			l++;
//			r--;
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