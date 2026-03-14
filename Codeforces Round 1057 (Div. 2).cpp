//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>b(n);
//	for (int i = 0; i < n; i++) {
//		cin >> b[i];
//	}
//	sort(b.begin(), b.end());
//	b.erase(unique(b.begin(), b.end()), b.end());
//	cout << b.size() << "\n";
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
//	int x, y, z;
//	cin >> x >> y >> z;
//	int a = x | z,b=x|y,c=z|y;
//	if (((a & b) != x) || ((b & c) != y) || ((a & c) != z)) {
//		cout << "NO\n";
//	}
//	else {
//		cout << "YES\n";
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
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	map<int, int>mp;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		mp[a[i]]++;
//	}
//	vector<int>tmp;
//	int ans = 0;
//	int cnt = 0;
//	for (auto v : mp) {
//		if(v.second%2==0){
//			ans += v.second * v.first;
//			cnt += v.second;
//		}
//		else {
//			ans += (v.second - 1) * v.first;
//			tmp.push_back(v.first);
//			cnt += v.second - 1;
//		}
//	}
//	if (ans == 0||cnt==0) {
//		cout << 0 << "\n";
//		return;
//	}
//	sort(tmp.begin(), tmp.end());
//	if (tmp.size() == 1) {
//		if (tmp.back() < ans) {
//			cout << ans + tmp.back() << "\n";
//		}
//		else {
//			if (cnt > 2)cout << ans << "\n";
//			else {
//				cout << 0 << "\n";
//			}
//		}
//		return;
//	}
//	for (int i = tmp.size() - 1; i >= 1; i--) {
//		if (ans > tmp[i] - tmp[i - 1]) {
//			cout << ans + tmp[i] + tmp[i - 1] << "\n";
//			return;
//		}
//	}
//	for (int i = tmp.size()-1; i >= 0; i--) {
//		if (ans > tmp[i]) {
//			cout << ans + tmp[i] << "\n";
//			return;
//		}
//	}
//	if (cnt > 2) {
//		cout << ans << "\n";
//	}
//	else {
//		cout << 0 << "\n";
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
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(2*n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		a[i + n] = a[i];
//	}
//	int ans = LLONG_MAX;
//	for (int p = 0; p <= 3; p++) {
//		vector<int>dp(2 * n + 1,LLONG_MAX);
//		dp[1 + p] = 1e15;
//		dp[p] = 0;
//		for (int i = 2 + p; i <= n + p; i++) {
//			if (i >= p + 2) {
//				dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 1]));
//			}
//			if (i >= p + 3) {
//				dp[i] = min(dp[i], dp[i - 3] + max({ a[i],a[i - 1],a[i - 2] }) - min({ a[i],a[i - 1],a[i - 2] }));
//			}
//		}
//		ans = min(ans, dp[n + p]);
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