//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	int ones = 0;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] == '1') {
//			ones++;
//		}
//	}
//	int rest = ones;
//	cout << ones << '\n';
//	for (int i = s.size() - 1; i >= max(0, (int)(s.size()) - ones); i--) {
//		if (s[i] == '1') {
//			rest--;
//		}
//	}
//	cout << rest <<'\n';
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
//	int x;
//	cin >> x;
//	cout << 2*x << '\n';
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
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	if (n == 1) {
//		cout << a[1] << '\n';
//		return;
//	}
//	int f = 0;
//	for (int i = 1; i <= n; i++) {
//		if (i & 1) {
//			f += a[i];
//		}
//		else {
//			f -= a[i];
//		}
//	}
//	int mx1 = (n & 1) ? n - 1 : n - 2;
//	int mnod=LLONG_MAX, mxev = LLONG_MIN;
//	vector<int>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		b[i] = 2*a[i] + i;
//		if (i & 1) {
//			mnod = min(mnod, b[i]);
//		}
//		else {
//			mxev = max(mxev, b[i]);
//		}
//	}
//	int mx2 = mxev-mnod;
//	mnod = LLONG_MAX, mxev = LLONG_MIN;
//	for (int i = 1; i <= n; i++) {
//		b[i] = 2 * a[i] - i;
//		if (i & 1) {
//			mnod = min(mnod, b[i]);
//		}
//		else {
//			mxev = max(mxev, b[i]);
//		}
//	}
//	int mx3 = mxev - mnod;
//	cout << f + max({ mx1,mx2,mx3 })<<'\n';
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
//struct seg {
//	int l;
//	int r;
//	int id;//按左端点排序得到的id
//	int id1;//按右端点排序得到的id
//};
//void solve() {
//	int n;
//	cin >> n;
//	vector<seg>a(n + 1);
//	int ans = 0;
//	for (int i = 1, l, r; i <= n; i++) {
//		cin >> a[i].l >> a[i].r;
//		ans += a[i].r - a[i].l;
//	}
//	sort(a.begin() + 1, a.end(), [&](seg& x, seg& y) {
//		if (x.l == y.l)return x.r < y.r;
//		return x.l < y.l;
//		});
//	for (int i = 1; i <= n; i++) {
//		a[i].id = i;
//	}
//	sort(a.begin() + 1, a.end(), [&](seg& x, seg& y) {
//		if (x.r == y.r) return x.l > y.l;
//		return x.r > y.r;
//		});
//	for (int i = 1; i <= n; i++) {
//		a[i].id1 = i;
//	}
//	map<int, seg>ls;
//	map<int, seg>rs;
//	for (int i = 1; i <= n; i++) {
//		ls.insert({ a[i].id, a[i] });
//		rs.insert({ a[i].id1,a[i] });
//	}
//	while (!ls.empty()) {
//		if (ls.size() == 1) {
//			break;
//		}
//		auto it = ls.begin();
//		auto it1 = rs.begin();
//		if ((*it).second.id == (*it1).second.id) {
//			int a = (*next(it)).second.l;
//			int c = (*next(it)).second.r;
//			int b = (*next(it1)).second.r;
//			int d = (*next(it1)).second.l;
//			if ((*it).second.r - a > b - (*it).second.l) {
//				it = next(it);
//			}
//			else if((*it).second.r - a < b - (*it).second.l){
//				it1 = next(it1);
//			}
//			else {
//				if (c - a >= b - d) {
//					it1 = next(it1);
//				}
//				else {
//					it = next(it);
//				}
//			}
//		}
//		ans += max(0ll,(*it1).second.r - (*it).second.l);
//		int a = (*it).second.id;
//		int b = (*it).second.id1;
//		int c = (*it1).second.id;
//		int d = (*it1).second.id1;
//		ls.erase(a);
//		ls.erase(c);
//		rs.erase(b);
//		rs.erase(d);
//	}
//	cout << ans << '\n';
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


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<array<int,2>>seg(n + 1);
//	if ((n & 1) == 0) {
//		int ans = 0;
//		for (int i = 1; i <= n; i++) {
//			cin >> seg[i][0] >> seg[i][1];
//			ans += seg[i][1]+seg[i][1]-seg[i][0];
//		}
//
//		sort(seg.begin() + 1, seg.end(), [&](auto x, auto y) {
//			return x[0] + x[1] < y[0] + y[1];
//			});
//		for (int i = 1; i <= n/2; i++) {
//			ans -= seg[i][0] + seg[i][1];
//		}
//		cout << ans << '\n';
//	}
//	else {
//		int finalans = 0;
//		int ans = 0;
//		for (int i = 1; i <= n; i++) {
//			cin >> seg[i][0] >> seg[i][1];
//			ans += seg[i][1]+ seg[i][1] - seg[i][0];
//		}
//		sort(seg.begin() + 1, seg.end(), [&](auto x, auto y) {
//			return x[0] + x[1] < y[0] + y[1];
//			});
//		int mid = (n - 1) / 2;
//		for (int i = 1; i <= mid; i++) {
//			ans -= seg[i][0] + seg[i][1];
//		}
//		for (int i = 1; i <= mid; i++) {
//			finalans = max(finalans, ans +seg[i][0]-seg[mid+1][0]-seg[mid+1][1]);
//		}
//		for (int i = mid + 1; i <= n; i++) {
//			finalans = max(finalans,ans-seg[i][1]);
//		}
//		cout << finalans << '\n';
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
//const int mod = 1e9 + 7;
//int qpow(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a % mod;
//		}
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ans;
//}
//int popcount(int x) {
//	int ans = 0;
//	while (x != 0) {
//		if (x & 1) {
//			ans++;
//		}
//		x >>= 1;
//	}
//	return ans;
//}
//const int N = 25;
//int dp[25][1100000][2];//场上有多少颗棋子，目前棋子状态，谁先手
//int cnt[2][N][N];//i先手,j堆石子中有k对大于等于k且最终结果为1的方案数
////1表示2 0 表示1
//int removeBit(int x, int i) {
//	int msk = 1 << 22;
//	int filtermsk = msk - (1 << i);
//	return ((x >> 1) & filtermsk) | (x & ((1 << i) - 1));
//}
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	int k;
//	cin >> k;
//	vector<int>a(k + 1);
//	for (int i = 1; i <= k; i++) {
//		cin >> a[i];
//	}
//	if (m == 1) {
//		cout << 1<<'\n';
//		return;
//	}
//	memset(cnt, 0, sizeof(cnt));
//	dp[1][1][1] = dp[1][1][0] = 1;//这里设为0与1仅是为了在转移时方便位运算
//	dp[1][0][1] = dp[1][0][0] = 0;
//	cnt[0][1][1] = 1;
//	cnt[1][1][1] = 1;
//	for (int i = 2; i <= n; i++) {
//		for (int j = 0; j < (1 << i); j++) {
//			bool ans0 = 1;//只要前面的状态有一个是0就为0
//			bool ans1 = 0;//只要前面的状态有一个是1就为1
//			for (int l = 1; l <= k; l++) {
//				if (a[l] <= i) {
//					int msk = removeBit(j, a[l] - 1);
//					ans0 &= dp[i - 1][msk][1];
//					ans1 |= dp[i - 1][msk][0];
//				}
//				else break;
//			}
//			dp[i][j][0] = ans0;
//			dp[i][j][1] = ans1;
//			cnt[0][i][popcount(j)] += ans0;
//			cnt[1][i][popcount(j)] += ans1;
//		}
//	}
//	int ans = 0;
//	for (int r = 1; r <= n; r++) {
//		for (int k = 1; k <= m; k++) {
//			ans = (ans + qpow(k - 1, n - r) * qpow(m - k + 1, r) % mod * cnt[1][n][r] % mod)%mod;
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