//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	string s;
//	cin >> s;
//	int n = s.size();
//	s = " " + s;
//	int cn = 0;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == 'Y')cn++;
//	}
//	if (cn>=2) {
//		cout << "NO\n";
//	}
//	else {
//		cout << "YES\n";
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
//	string t;
//	cin >> t;
//	int n = t.size();
//	t = " " + t;
//	int ans = 0;
//	if (t[1] == 'u')ans++;
//	if (t[n] == 'u')ans++;
//	t[1] = t[n] = 's';
//	int cu = 0;
//	for (int i = 1; i <= n; i++) {
//		if (t[i] == 's') {
//			ans += cu / 2;
//			cu = 0;
//		}
//		else {
//			cu++;
//		}
//	}
//	cout << ans << endl;
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
//	vector<int>dp(n + 2);//从i往后能选到的最大价值
//	vector<int>bsum(n + 2, 0);
//	vector<int>asum(n + 2, 0);
//	int pmx = LLONG_MIN;
//	for (int i = n; i >= 1; i--) {
//		bsum[i] = abs(a[i]) + bsum[i + 1];
//		asum[i] = a[i] + asum[i + 1];
//	}
//	pmx = 0;
//	for (int i = n-1; i >= 1; i--) {
//		dp[i] = max(-asum[i+1], pmx+a[i]);
//		pmx = max(pmx - a[i], dp[i]);
//	}
//	cout << dp[1] <<"\n";
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
//struct cmp {
//	bool operator()(pair<int,int>&a,pair<int,int>&b) {
//		return a.second < b.second;
//	}
//};
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<pair<int,int>>a(n + 1);
//	vector<int>bsum(n+2);
//	vector<int>psum(n + 2);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i].second;
//		a[i].first = i;
//	}
//	if (m > n / 2) {
//		cout << -1 << endl;
//		return;
//	}
//	sort(a.begin() + 1, a.end(), [&](auto x, auto y) {
//		return x.second < y.second;
//		});	
//	vector<pair<int, int>>op;
//	if (m == 0) {
//		int sum = 0;
//		for (int i = 1; i <= n - 1; i++) {
//			sum += a[i].second;
//		}
//		if (sum < a[n].second) {
//			cout << -1 << endl;
//			return;
//		}
//		int k = n-1;
//		sum = 0;
//		while (sum < a[n].second) {
//			sum += a[k].second;
//			k--;
//		}
//		for (int i = 1; i <= k; i++) {
//			op.push_back({ a[i].first,a[i + 1].first });
//		}
//		for (int i = n - 1; i > k; i--) {
//			op.push_back({a[i].first, a[n].first});
//		}
//		cout << op.size() << endl;
//		for (auto p : op) {
//			cout << p.first << " " << p.second << endl;
//		}
//		return;
//	}
//	if (m == 1) {
//		cout << n - 1 << endl;
//		for (int i = 1; i <= n - 1; i++) {
//			cout << a[i].first << " " << a[i + 1].first << endl;
//		}
//		return;
//	}
//	for (int i = 1; i <= n - 2 * m; i++) {
//		op.push_back({ a[i].first,a[i + 1].first });
//	}
//	for (int i = n - m+1; i <= n; i++) {
//		op.push_back({ a[i].first,a[i - m].first });
//	}
//	cout << op.size() << endl;
//	for (auto p : op) {
//		cout << p.first << " " << p.second << endl;
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
//int ask(int l, int r) {
//	cout << "? " << l << " " << r << endl;
//	int tmp;
//	cin >> tmp;
//	return tmp;
//}
//void gotAns(int ans) {
//	cout << "! " << ans << endl;
//}
//int sum;
//int bs(int l, int r, int tar) {
//	int ll = l, rr = r;
//	while (ll <= rr) {
//		int mid = ll + rr >> 1;
//		int t = ask(l, mid);
//		if (t == tar)return mid;
//		if (t > tar) {
//			rr = mid - 1;
//		}
//		else {
//			ll = mid + 1;
//		}
//	}
//	return -1;
//}
//void solve() {
//	int n;
//	cin >> n;
//	sum = ask(1, n);
//	int l = 1, r = n;
//	int cur = sum / 2;
//	while (l < r) {
//		int m = bs(l, r, cur);
//		if (m - l + 1 <= r - m) {
//			r = m;
//		}
//		else {
//			l = m + 1;
//		}
//		cur /= 2;
//	}
//	gotAns(ask(l, l));
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--){
//		solve();
//	} 
//}


