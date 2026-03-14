//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	set<int>st;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		st.insert(a[i]);
//	}
//	for (int i = 0; i <= 100; i++) {
//		if (!st.count(i)) {
//			cout << i << '\n';
//			return;
//		}
//	}
//
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
//	vector<int>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	int cnt = 1;
//	vector<int>a(n + 1);
//	a[1] = 1;
//	for(int i=2;i<=n;i++){
//		int d = b[i] - b[i - 1];
//		if (d == i) {
//			a[i] = ++cnt;
//		}
//		else {
//			a[i] = a[i - d];
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << a[i] << " ";
//	}cout << "\n";
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
//	bitset<64>a(n);
//	int h = 0;
//	int tmp = n;
//	while (tmp != 0) {
//		tmp >>= 1;
//		h++;
//	}//h «0Œª÷√
//	vector<int>p1;
//	for (int i = 0; i < h; i++) {
//		if (a[i] == 1) {
//			p1.push_back(i);
//		}
//	}
//	if (p1.empty()) {
//		cout << "YES\n";
//		return;
//	}
//	if (p1.size()&1) {
//		cout << "NO\n";
//		return;
//	}
//	int l = 0, r = p1.size()-1;
//	int s = p1[0] + p1.back();
//	while (l <= r) {
//		if (p1[l] + p1[r] != s) {
//			cout << "NO\n";
//			return;
//		}
//		l++, r--;
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
//using namespace std;
//set<int>qry;
//int query() {
//	cout << "? ";
//	cout << qry.size() << " ";
//	for (auto v : qry) {
//		cout << v << " ";
//	}
//	cout << endl;
//	int tmp; cin >> tmp;
//	return tmp;
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>ans(2 * n + 1);
//	qry.clear();
//	qry.insert(1);
//	int unk = 2 * n;
//	set<int>knw;
//	set<int>rst;
//	for (int i = 2; i <= 2 * n; i++) {
//		qry.insert(i);
//		int rly = query();
//		if (rly != 0) {
//			ans[i] = rly;
//			knw.insert(i);
//			qry.erase(i);
//		}
//	}
//	for (int i = 1; i <= 2 * n; i++) {
//		if (!qry.count(i) && !knw.count(i)) {
//			rst.insert(i);
//		}
//	}
//	int tt;
//	for (auto v : qry) {
//		cout << "? ";
//		cout << 1 + knw.size() << " ";
//		cout << v<<" ";
//		for (auto u : knw) {
//			cout << u << " ";
//		}cout << endl;
//		cin >> ans[v];
//	}
//	cout << "! ";
//	for (int i = 1; i <= 2 * n; i++) {
//		cout << ans[i] << " ";
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


//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>g(n + 1, vector<int>(m + 1));
//	string tmp;
//	for (int i = 1; i <= n; i++) {
//		cin >> tmp;
//		for (int j = 1; j <= m; j++) {
//			g[i][j]=tmp[j-1]-'0';
//		}
//	}
//	vector<vector<int>>dp(n + 1, vector<int>(m + 1, INT_MAX));
//	if (n < m) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = i + 1; j <= n; j++) {
//				int lst = 0;
//				for (int k = 1; k <= m; k++) {
//					if (g[i][k] == 1 && g[j][k] == 1) {
//						if (lst != 0) {
//							int S = (k - lst + 1) * (j - i + 1);
//							for (int t = lst; t <= k; t++) {
//								dp[j][t] = min(dp[j][t], S);
//							}
//						}
//						lst = k;
//					}
//				}
//			}
//			for (int k = 1; k <= m; k++) {
//				for (int j = n-1; j >= i; j--) {
//					dp[j][k] = min(dp[j + 1][k], dp[j][k]);
//				}
//			}
//		}
//	}
//	else {
//		for (int i = 1; i <= m; i++) {
//			for (int j = i + 1; j <= m; j++) {
//				int lst = 0;
//				for (int k = 1; k <= n; k++) {
//					if (g[k][i] == 1 && g[k][j] == 1) {
//						if (lst != 0) {
//							int S = (k - lst + 1) * (j - i + 1);
//							for (int t = lst; t <= k; t++) {
//								dp[t][j] = min(dp[t][j], S);
//							}
//						}
//						lst = k;
//					}
//				}
//			}
//			for (int k = 1; k <= n; k++) {
//				for (int j = m - 1; j >= i; j--) {
//					dp[k][j] = min(dp[k][j+1], dp[k][j]);
//				}
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << (dp[i][j] == INT_MAX ? 0 : dp[i][j]) << " ";
//		}cout << "\n";
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