//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	int ans = -1;
//	for (int i = 1,u; i <= n; i++) {
//		cin >> u;
//		ans = max(ans, u);
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
//	int n;
//	string s;
//	cin >> n >> s;
//	vector<int>ans;
//	s = " " + s;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == '0') {
//			ans.push_back(i);
//		}
//	}
//	cout << ans.size() << "\n";
//	for (auto v : ans)cout << v << " ";
//	cout << "\n";
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
//void solve() {
//	int a, b;
//	cin >> a >> b;
//	vector<int>op;
//	if (high(b) > high(a)) {
//		cout << -1 << "\n";
//		return;
//	}
//	for (int i = 0; i <= 31; i++) {
//		int x = (a >> i) & 1;
//		int y = (b >> i) & 1;
//		if (x != y) {
//			op.push_back(1 << i);
//		}
//	}
//	cout << op.size() << "\n";
//	for (int i = 0; i < op.size(); i++) {
//		cout << op[i] << " ";
//	}
//	if(op.size()!=0)cout << "\n";
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}
//


//#include<bits/stdc++.h>
//using namespace std;
//int ask1(int l, int r) {
//	cout << "1 " << l << " " << r << endl;
//	int tmp;
//	cin >> tmp;
//	return tmp;
//}
//int ask2(int l, int r) {
//	cout << "2 " << l << " " << r << endl;
//	int tmp;
//	cin >> tmp;
//	return tmp;
//}
//void solve() {
//	int n;
//	cin >> n;
//	int l = 1, r = n;
//	int diff = ask2(l, r) - ask1(l, r);
//	int qry1=0, qry2 = 0;
//	int ans = -1;
//	while (l<=r) {
//		int mid = l + r >> 1;
//		qry1 = ask1(l, mid);
//		qry2 = ask2(l, mid);
//		if (qry2 - qry1 != diff&&qry2!=qry1) {
//			cout << "! " << mid - (qry2 - qry1)+1 << " " << mid + diff - (qry2 - qry1) << endl;
//			return;
//		}
//		else if(qry2==qry1){
//			l = mid+1;
//		}
//		else {
//			ans = mid;
//			r = mid-1;
//		}
//	}
//	cout << "! " << ans << " " << ans << "\n";
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
//	vector<int>vis(n + 1,0);
//	int vised = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		vis[a[i]] = 1;
//	}
//	for (int i = 1; i <= n; i++) {
//		vised += vis[i];
//	}
//	if (vised == n) {
//		int cnt = 0;
//		for (int i = 1; cnt < k;cnt++, i++) {
//			if (i > n)i = 1;
//			cout << a[i] << " ";
//		}cout << '\n';
//	}
//	else {
//		int cnt = 1;
//		int first = 0;
//		for (int i = 1; i <= n; i++) {
//			if (!vis[i]) {
//				cout << i << " ";
//				first = i;
//				break;
//			}
//		}
//		int start = a[n] + 1;
//		if (start == first)start++;
//		if (start > n)start = 1;
//		for (int i = start; cnt < k; cnt++, i++) {
//			if (i > n)i = 1;
//			cout << i << " ";
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


//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, m;
//	vector<int>d(n+2);
//	for (int i = 1,l,r; i <= m; i++) {
//		cin >> l >> r;
//		d[l] += 1;
//		d[r + 1] -= 1;
//	}
//	vector<int>p(n + 1);
//	iota(p.begin()+1, p.end(), 0);
//	for (int i = 1; i <= n; i++) {
//		d[i] += d[i - 1];
//	}
//	for (int i = 1; i <= n; i++) {
//		if (d[i] == n) {
//			swap(p[1], p[i]);
//		}
//		for (int j = 1; j <= n; j++) {
//			cout << p[j] << " ";
//		}
//		cout << "\n";
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (d[i] == 0) {
//			swap(p[1], p[i - 1]);
//		}
//		for (int j = 1; j <= n; j++) {
//			cout << p[j] << " ";
//		}cout << "\n";
//		return;
//	}
//
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}