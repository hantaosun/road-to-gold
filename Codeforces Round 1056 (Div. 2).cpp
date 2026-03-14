//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	int ans = 0;
//	int win = n, lose = 0;
//	int nwin=0, nlose=0;
//	while (true) {
//		nwin = (win + 1) / 2;
//		nlose += win - nwin;
//		ans += win/2;
//		nlose += (lose + 1) / 2;
//		ans += lose / 2;
//		win = nwin;
//		lose = nlose;
//		nwin = 0;
//		nlose = 0;
//		if (win == 1 && lose == 1) {
//			ans++;
//			break;
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
//using namespace std;
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	if (n * n - k >= 2||n*n-k==0) {
//		cout << "YES\n";
//	}
//	else {
//		cout << "NO\n";
//		return;
//	}
//	int trap = n * n - k;
//	int r = trap / n;
//	int c = trap % n;
//	for (int i = 1; i <= r; i++) {
//		for (int j = 1; j < n; j++) {
//			cout << "R";
//		}cout << "L\n";
//	}
//	if (c != 0) {
//		if (r == 0) {
//			for (int j = 1; j < c; j++) {
//				cout << "R";
//			}cout << "L";
//			for (int j = c + 1; j <= n; j++) {
//				cout << "D";
//			}cout << "\n";
//		}
//		else {
//			for (int j = 1; j <= c; j++) {
//				cout << "U";
//			}
//			for (int j = c + 1; j <= n; j++) {
//				cout << "D";
//			}cout << "\n";
//		}
//	}
//	for (int i = r + 1 + (c != 0); i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << "D";
//		}cout << "\n";
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
//#define int long long
//using namespace std;
//const int mod = 676767677;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	vector<int>dir(n + 1, -1);//1ÓÒ0×ó
//	dir[0] = -2;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 2; i <= n; i++) {
//		if (a[i] == a[i - 1] + 1) {
//			if (dir[i - 1] == 1) {
//				cout << 0 << "\n";
//				return;
//			}
//			dir[i] = dir[i - 1] = 0;
//		}
//		else if (a[i] == a[i - 1] - 1) {
//			if (dir[i - 1] == 0) {
//				cout << 0 << "\n";
//				return;
//			}
//			dir[i] = dir[i - 1] = 1;
//		}
//		else if (a[i] != a[i - 1]) {
//			cout << 0 << "\n";
//			return;
//		}
//	}
//
//	for (int i = 2; i <= n; i++) {
//		if (a[i] == a[i - 1]) {
//			if (dir[i] == -1 && dir[i - 1] != -1) {
//				dir[i] = dir[i - 1] ^ 1;
//			}
//			else if (dir[i] != -1 && dir[i - 1] == -1) {
//				dir[i - 1] = dir[i] ^ 1;
//			}
//			else if (dir[i] != -1 && dir[i - 1] != -1) {
//				if (dir[i] == dir[i - 1]) {
//					cout << 0 << "\n";
//					return;
//				}
//			}
//		}
//	}
//	for (int i = n-1; i >= 1; i--) {
//		if (a[i] == a[i + 1]) {
//			if (dir[i] == -1 && dir[i + 1] != -1) {
//				dir[i] = dir[i + 1] ^ 1;
//			}
//			else if (dir[i] != -1 && dir[i + 1] == -1) {
//				dir[i + 1] = dir[i] ^ 1;
//			}
//			else if (dir[i] != -1 && dir[i + 1] != -1) {
//				if (dir[i] == dir[i + 1]) {
//					cout << 0 << "\n";
//					return;
//				}
//			}
//		}
//	}
//	bool gotm1 = false;
//	for (int i = 1; i <= n; i++) {
//		if (dir[i] == -1) {
//			gotm1 = true;
//			break;
//		}
//	}
//	if (!gotm1) {
//		vector<int>lsum(n + 2);
//		vector<int>rsum(n + 2);
//		for (int i = 1; i <= n; i++) {
//			if (dir[i] == 0)lsum[i] = lsum[i - 1] + 1;
//			else lsum[i] = lsum[i - 1];
//		}
//		for (int i = n; i >= 1; i--) {
//			if (dir[i] == 1)rsum[i] = rsum[i + 1] + 1;
//			else rsum[i] = rsum[i + 1];
//		}
//		for (int i = 1; i <= n; i++) {
//			if (lsum[i - 1] + rsum[i + 1] + 1 != a[i]) {
//				cout << 0 << "\n";
//				return;
//			}
//		}
//		cout << 1 << "\n";
//		return;
//	}
//	else {
//		int ans = 0;
//		for (int i = 1; i <= n; i++) {
//			if (i & 1) {
//				dir[i] = 1;
//			}
//			else {
//				dir[i] = 0;
//			}
//		}
//		bool flag = true;
//		vector<int>lsum(n + 2);
//		vector<int>rsum(n + 2);
//		for (int i = 1; i <= n; i++) {
//			if (dir[i] == 0)lsum[i] = lsum[i - 1] + 1;
//			else lsum[i] = lsum[i - 1];
//		}
//		for (int i = n; i >= 1; i--) {
//			if (dir[i] == 1)rsum[i] = rsum[i + 1] + 1;
//			else rsum[i] = rsum[i + 1];
//		}
//		for (int i = 1; i <= n; i++) {
//			if (lsum[i - 1] + rsum[i + 1] + 1 != a[i]) {
//				flag = false;
//				break;
//			}
//		}
//		if (flag)ans++;
//		
//		for (int i = 1; i <= n; i++) {
//			if (i & 1) {
//				dir[i] = 0;
//			}
//			else {
//				dir[i] = 1;
//			}
//		}
//		flag = true;
//		lsum.assign(n + 2,0);
//		rsum.assign(n + 2,0);
//		for (int i = 1; i <= n; i++) {
//			if (dir[i] == 0)lsum[i] = lsum[i - 1] + 1;
//			else lsum[i] = lsum[i - 1];
//		}
//		for (int i = n; i >= 1; i--) {
//			if (dir[i] == 1)rsum[i] = rsum[i + 1] + 1;
//			else rsum[i] = rsum[i + 1];
//		}
//		for (int i = 1; i <= n; i++) {
//			if (lsum[i - 1] + rsum[i + 1] + 1 != a[i]) {
//				flag = false;
//				break;
//			}
//		}
//		if (flag)ans++;
//		cout << ans << "\n";
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
//using namespace std;
//set<pair<int,int>>asked;
//int ask(int u, int v) {
//	if (u > v)swap(u, v);
//	if (asked.count({ u,v }))return 0;
//	cout << u << " " << v << endl;
//	int rly;
//	cin >> rly;
//	asked.insert({ u,v });
//	return rly;
//}
//int n;
//bool flag = false;
//void f(int m) {
//	int step = (n + m - 1) / m;
//	int l = 1;
//
//	while (l <= n) {
//		int r = min(n + 1, l + step);
//		for (int i = l; i < r; i++) {
//			for (int j = i + 1; j < r; j++) {
//				if (ask(i, j) == 1) {
//					flag = true;
//					break;
//				}
//			}
//			if (flag)break;
//		}
//		if (flag)break;
//		l += step;
//	}
//}
//void solve() {
//	cin >> n;
//	for (int i = n/2; i >= 1; i--) {
//		f(i);
//		if (flag)break;
//	}
//	asked.clear();
//	flag = false;
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
//	int n, m, k;
//	cin >> n >> m >> k;
//	map<int, int>mp;
//	int mxc = -1;
//	for (int i = 1, x, y; i <= k; i++) {
//		cin >> x >> y;
//		mxc = max(mxc, y);
//		mp[y]++;
//	}
//	if (mxc == 1) {
//		cout << "Yuyu\n";
//		return;
//	}
//	else if (n >= 2) {
//		for (auto v : mp) {
//			if (v.first != 1 && (v.second & 1)) {
//				cout << "Mimo\n";
//				return;
//			}
//		}
//		cout << "Yuyu\n";
//	}
//	else {
//		for (auto v : mp) {
//			if (v.first == 2 && (v.second & 1)) {
//				cout << "Mimo\n";
//				return;
//			}
//		}
//		cout << "Yuyu\n";
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}