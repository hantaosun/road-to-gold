//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int r0, x, d, n;
//	cin >> r0 >> x >> d >> n;
//	string s;
//	cin >> s;
//	s = " " + s;
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == '2') {
//			if (r0 >= x)continue;
//			else {
//				r0 -= d;
//				ans++;
//			}
//		}
//		else {
//			r0 -= d;
//			ans++;
//		}
//	}
//	cout << ans << endl;
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
//const int N = 100;
//void solve() {
//	int n;
//	cin >> n;
//	vector<string>g(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> g[i];
//		g[i] = " " + g[i];
//	}
//	int tot = 0;
//	for (int i = 1; i <= n; i++) {
//		int b = 0, b1 = 0;
//		for (int j = 1; j <= n; j++) {
//			//if (g[i][j] == '#' && j > 1 && g[i][j - 1] != '#' && b != 0) {
//			//	cout << "NO\n";
//			//	return;
//			//}
//			//if (g[j][i] == '#' && j > 1 && g[j - 1][i] != '#' && b1 != 0) {
//			//	cout << "NO\n";
//			//	return;
//			//}
//			if (g[i][j] == '#')b++, tot++;
//			if (g[j][i] == '#')b1++;
//		}
//		if (b >= 3 || b1 >= 3) {
//			cout << "NO\n";
//			return;
//		}
//	}
//	auto check = [&](int x, int y, int cx, int cy, int tot)->bool {
//		int cnt = 0;
//		while (x <= n && y <= n&&x>=1&&y>=1) {
//			if (g[x][y] == '#') {
//				cnt++;
//			}
//			x += cx;
//			y += cy;
//			swap(cx, cy);
//		}
//		return cnt == tot;
//	};
//	auto check1 = [&](int x, int y, int cx, int cy, int tot)->bool {
//		int cnt = 0;
//		while (x <= n && y <= n&&x>=1&&y>=1) {
//			if (g[x][y] == '#') {
//				cnt++;
//			}
//			x += cx;
//			y += cy;
//			swap(cx, cy);
//			cx = -cx;
//			cy = -cy;
//		}
//		return cnt == tot;
//	};
//	if (tot == 4) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				if (i<n&&j<n&&g[i][j] == '#'&&g[i][j+1]=='#'&&g[i][j+1]=='#'&&g[i+1][j+1]=='#') {
//					cout << "YES\n";
//					return;
//				}
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (g[i][j] == '#') {
//				if (check(i, j, 1, 0, tot) ||
//					check(i, j, 0, 1, tot) ||
//					check(i, j, -1, 0, tot) ||
//					check(i, j, 0, -1, tot) ||
//					check1(i, j, 1, 0, tot) ||
//					check1(i, j, 0, 1, tot) ||
//					check1(i, j, -1, 0, tot) ||
//					check1(i, j, 0, -1, tot)) {
//					cout << "YES\n";
//					return;
//				}
//			}
//		}
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	for (int j = n; j >=1; j--) {
//	//		if (g[i][j] == '#') {
//	//			if (check(i, j, 1, 0, tot) ||
//	//				check(i, j, 0, 1, tot) ||
//	//				check(i, j, -1, 0, tot) ||
//	//				check(i, j, 0, -1, tot) ||
//	//				check1(i, j, 1, 0, tot) ||
//	//				check1(i, j, 0, 1, tot) ||
//	//				check1(i, j, -1, 0, tot) ||
//	//				check1(i, j, 0, -1, tot)) {
//	//				cout << "YES\n";
//	//				return;
//	//			}
//	//			else {
//	//				break;
//	//			}
//	//		}
//	//	}
//	//}
//	//for (int i = n; i >= 1; i--) {
//	//	for (int j = n; j >=1; j--) {
//	//		if (g[i][j] == '#') {
//	//			if (check(i, j, 1, 0, tot) ||
//	//				check(i, j, 0, 1, tot) ||
//	//				check(i, j, -1, 0, tot) ||
//	//				check(i, j, 0, -1, tot) ||
//	//				check1(i, j, 1, 0, tot) ||
//	//				check1(i, j, 0, 1, tot) ||
//	//				check1(i, j, -1, 0, tot) ||
//	//				check1(i, j, 0, -1, tot)) {
//	//				cout << "YES\n";
//	//				return;
//	//			}
//	//			else {
//	//				break;
//	//			}
//	//		}
//	//	}
//	//}
//	//for (int i = n; i >= 1; i--) {
//	//	for (int j = 1; j <=n; j++) {
//	//		if (g[i][j] == '#') {
//	//			if (check(i, j, 1, 0, tot) ||
//	//				check(i, j, 0, 1, tot) ||
//	//				check(i, j, -1, 0, tot) ||
//	//				check(i, j, 0, -1, tot) ||
//	//				check1(i, j, 1, 0, tot) ||
//	//				check1(i, j, 0, 1, tot) ||
//	//				check1(i, j, -1, 0, tot) ||
//	//				check1(i, j, 0, -1, tot)) {
//	//				cout << "YES\n";
//	//				return;
//	//			}
//	//			else {
//	//				break;
//	//			}
//	//		}
//	//	}
//	//}
//	if (tot == 0) {
//		cout << "YES\n";
//	}
//	else cout << "NO\n";
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
//#define int long long
//using namespace std;
//void solve() {
//	int n, x;
//	cin >> n >> x;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	sort(a.begin() + 1, a.end());
//	int l = 1;
//	int sum = 0;
//	vector<int>ord;
//	int ans = 0;
//	for (int i = n; i >= l; i--) {
//		sum += a[i];
//		while (sum < x&&l<i) {
//			ord.push_back(a[l]);
//			sum += a[l++];
//		}
//		ord.push_back(a[i]);
//		if (sum >= x) {
//			ans+=a[i];
//		}
//		sum -= x;
//	}
//	cout << ans << endl;
//	for (auto v : ord)cout << v << " "; cout << endl;
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
//const int N = 100;
//void solve(int ttt) {
//	int n;
//	cin >> n;
//	vector<string>g(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> g[i];
//		g[i] = " " + g[i];
//	}
//	//if (ttt == 76) {
//	//	for (int i = 1; i <= n; i++) {
//	//		cout << g[i] << endl;
//	//	}
//	//}
//	int tot = 0;
//	for (int i = 1; i <= n; i++) {
//		int b = 0, b1 = 0;
//		for (int j = 1; j <= n; j++) {
//			//if (g[i][j] == '#' && j > 1 && g[i][j - 1] != '#' && b != 0) {
//			//	cout << "NO\n";
//			//	return;
//			//}
//			//if (g[j][i] == '#' && j > 1 && g[j - 1][i] != '#' && b1 != 0) {
//			//	cout << "NO\n";
//			//	return;
//			//}
//			if (g[i][j] == '#')b++, tot++;
//			if (g[j][i] == '#')b1++;
//		}
//		if (b >= 3 || b1 >= 3) {
//			cout << "NO\n";
//			return;
//		}
//	}
//	auto check = [&](int x, int y, int cx, int cy, int tot)->bool {
//		int cnt = 0;
//		//int ttx = x, tty = y, ttcx = cx, ttcy = cy;
//		while (x <= n && y <= n && x >= 1 && y >= 1) {
//			if (g[x][y] == '#') {
//				cnt++;
//			}
//			x += cx;
//			y += cy;
//			swap(cx, cy);
//		}
//		//if (cnt == tot) {
//		//	cout << ttx << " " << tty << " " << ttcx << " " << ttcy << endl;
//		//}
//		return cnt == tot;
//		};
//	auto check1 = [&](int x, int y, int cx, int cy, int tot)->bool {
//		int cnt = 0;
//		//int ttx=x, tty=y, ttcx=cx, ttcy = cy;
//		while (x <= n && y <= n && x >= 1 && y >= 1) {
//			if (g[x][y] == '#') {
//				cnt++;
//			}
//			x += cx;
//			y += cy;
//			swap(cx, cy);
//			cx = -cx;
//			cy = -cy;
//		}
//		//if (cnt == tot) {
//		//	cout << ttx << " " << tty << " " << ttcx << " " << ttcy << endl;
//		//}
//		return cnt == tot;
//		};
//	if (tot == 4) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				if (i < n && j < n && g[i][j] == '#' && g[i][j + 1] == '#' && g[i+1][j] == '#' && g[i + 1][j + 1] == '#') {
//					cout << "YES\n";
//					return;
//				}
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (g[i][j] == '#') {
//				if (check(i, j, 1, 0, tot) ||
//					check(i, j, 0, 1, tot) ||
//					check(i, j, -1, 0, tot) ||
//					check(i, j, 0, -1, tot) ||
//					check1(i, j, 1, 0, tot) ||
//					check1(i, j, 0, 1, tot) ||
//					check1(i, j, -1, 0, tot) ||
//					check1(i, j, 0, -1, tot)) {
//					cout << "YES\n";
//					return;
//				}
//			}
//		}
//	}
//	if (tot == 0) {
//		cout << "YES\n";
//	}
//	else cout << "NO\n";
//}
//int main() {
//	int t;
//	cin >> t;
//	for (int i = 1; i <= t; i++) {
//		solve(i);
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 2);
//	vector<vector<int>>t(n + 2);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		t[a[i]].push_back(i);
//	}
//	vector<int>ans(n + 2);
//	vector<int>dp(n + 2);
//	for (int i = 1; i <= n; i++) {
//		reverse(t[i].begin(), t[i].end());
//		int maxc = 0;
//		for (int j : t[i]) {
//			dp[j] = max(maxc + 1, dp[j]);
//			if (i > 2) {
//				dp[j] = max(ans[i - 2]+1, dp[j]);
//			}
//			auto tt = upper_bound(t[i - 1].begin(), t[i - 1].end(), j);
//			if (tt != t[i - 1].end()) {
//				dp[j] = max(dp[*tt] + 1, dp[j]);
//				//这个dp是按值随位置递减的，因为按位置由小到大处理
//			}
//			maxc = max(maxc, dp[j]);
//		}
//		ans[i] = max(ans[i - 1], maxc);
//		reverse(t[i].begin(), t[i].end());
//	}
//	cout << n - ans[n] << endl;
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
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<pair<int,int>>qry;
//	for (int i = 1,l,r; i <= m; i++) {
//		cin >> l >> r;
//		qry.push_back({ l,r });
//	}
//	for (int i = 1; i <= n; i++) {
//		int cnt = 0;
//		for (auto p : qry) {
//			if (p.first <= i && p.second >= i) {
//				cnt++;
//			}
//		}
//		if (cnt == m) {
//			for (int j = 1,c=1; j <= n; j++) {
//				if (j == i) {
//					cout << 0 << " ";
//				}
//				else {
//					cout << c << " ";
//					c++;
//				}
//			}
//			cout << endl;
//			return;
//		}
//	}
//	for (int i = 1; i < n; i++) {
//		bool ok = true;
//		for (auto p : qry) {
//			if (i+1<=p.second&&i+1>=p.first&&(i<p.first||i>p.second)) {
//				ok = false;
//				break;
//			}
//		}
//		if (ok) {
//			for (int j = 1, c = 2; j <= n; j++) {
//				if (j == i) {
//					cout << 1 <<" ";
//				}
//				else if (j == i + 1) {
//					cout << 0 << " ";
//				}
//				else {
//					cout << c << " ";
//					c++;
//				}
//			}
//			cout << endl;
//			return;
//		}
//		ok = true;
//		for (auto p : qry) {
//			if (i<= p.second && i>= p.first && (i+1<p.first || i+1>p.second)) {
//				ok = false;
//				break;
//			}
//		}
//		if (ok) {
//			for (int j = 1, c = 2; j <= n; j++) {
//				if (j == i) {
//					cout << 0 << " ";
//				}
//				else if (j == i + 1) {
//					cout << 1 << " ";
//				}
//				else {
//					cout << c << " ";
//					c++;
//				}
//			}
//			cout << endl;
//			return;
//		}
//	}
//	for (int i = 1,c=2; i <= n; i++) {
//		if (i == 1) {
//			cout << 0 << " ";
//		}
//		else if(i==n) {
//			cout << 1 << " ";
//		}
//		else {
//			cout << c << " ";
//			c++;
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