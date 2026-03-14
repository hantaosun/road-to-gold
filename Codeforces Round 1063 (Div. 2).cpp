//#include<bits/stdc++.h>
//using namespace std;
//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	sort(a.begin()+1, a.end());
//	for (int i = 1; i <= n-1; i++) {
//		if (!(i & 1)) {
//			if (a[i] != a[i + 1]) {
//				cout << "NO\n";
//				return;
//			}
//		}
//	}
//	cout << "YES\n";
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
//vector<int>p;
//string x;
//void solve(){
//	int n;
//	cin >> n;
//	p.resize(n + 1);
//	int p1, pn;
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//		if (p[i] == 1) {
//			p1 = i;
//		}
//		if (p[i] == n) {
//			pn = i;
//		}
//	}
//
//	cin >> x;
//	x = " " + x;
//	if (x[p1] == '1' || x[pn] == '1') {
//		cout << -1 << "\n";
//		return;
//	}
//	if (x[1] == '1' || x[n] == '1') {
//		cout << -1 << "\n";
//		return;
//	}
//	cout << 5 << endl;
//	cout << min(p1,pn) << " " << max(p1,pn) << endl;
//	cout << 1 << " " << p1 << endl;
//	cout << 1 << " " << pn << endl;
//	cout << p1 << " " << n << endl;
//	cout << pn << " " << n << endl;
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
//	vector<int>r1(n + 1);
//	vector<int>r2(n + 1);
//	vector<pair<int, int>>p1(n+2,{INT_MAX,INT_MIN});
//	vector<pair<int, int>>p2(n + 2, {INT_MAX,INT_MIN});
//	for (int i = 1; i <= n; i++) {
//		cin >> r1[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> r2[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		p1[i].first = min(r1[i], p1[i-1].first);
//		p1[i].second = max(r1[i], p1[i-1].second);
//	}
//	for (int i = n; i >= 1; i--) {
//		p2[i].first = min(r2[i], p2[i+1].first);
//		p2[i].second = max(r2[i], p2[i+1].second);
//	}
//	vector<int>l(2*n + 2,0);
//	for (int i = 1; i <= n; i++) {
//		int ll = min(p1[i].first, p2[i].first);
//		int rr = max(p1[i].second, p2[i].second);
//		l[ll] = max(l[ll], 2*n - rr + 1);
//		//cout << ll << " " << rr << "&&\n";
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	cout << p1[i].first << "_" << p1[i].second << "  ";
//	//}cout << endl;
//	//for (int i = 1; i <= n; i++) {
//	//	cout << p2[i].first << "_" << p2[i].second << "  ";
//	//}cout << endl;
//	int ans = 0;
//	//for (int i = 1; i <= 2 * n; i++) {
//	//	cout << l[i] << " ";
//	//}cout << "**\n";
//	for (int i = 2 * n; i >= 1; i--) {
//		l[i] = max(l[i],l[i + 1]);
//	}
//
//	for (int i = 1; i <= 2*n; i++) {
//		ans += l[i];
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
//#define int long long
//using namespace std;
//const int N = 2e5 + 5;
//int l;
//int n;
//vector<int>r1;
//vector<int>r2;
//int dp[N][2];
//void solve() {
//	cin >> n;
//	r1.resize(n + 1);
//	r2.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> r1[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> r2[i];
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
//using namespace std;
//int ask(int l, int r) {
//	cout << "? " << l << " " << r << endl;
//	int tmp;
//	cin >> tmp;
//	return tmp;
//}
//void rpl(int id) {
//	cout << "! " << id << endl;
//}
//void solve() {
//	int n, q;
//	cin >> n >> q;
//	vector<int>mxr(n + 1,0);
//	for (int i = 1,l,r; i <= q; i++) {
//		cin >> l >> r;
//		mxr[l] = max(mxr[l], r);
//	}
//	int l = 1,r = n;
//	int mid = l + r >> 1;
//	int tmp = ask(l, mid);
//	int ans = 0;
//	vector<array<int, 2>>qq;
//	int mr = 0;
//	for (int i = 1; i <= n; i++) {
//		if (mxr[i] > mr) {
//			qq.push_back({ i,mxr[i]});
//			mr = mxr[i];
//		}
//	}
//	if (tmp != 0) {
//		for (auto v : qq) {
//			if (v[0] <= mid) {
//				int tt = ask(v[0], v[1]);
//				if (tt > ans) {
//					ans = tt;
//				}
//			}
//		}
//	}
//	else {
//		for (auto v : qq) {
//			if (v[1] > mid) {
//				int tt = ask(v[0], v[1]);
//				if (tt > ans) {
//					ans = tt;
//				}
//			}
//		}
//	}
//	rpl(ans);
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
//int ask(int l, int r) {
//	cout << "? " << l << " " << r << endl;
//	int ans; cin >> ans;
//	return ans;
//}
//void solve() {
//	int n, q;
//	cin >> n >> q;
//	vector<int>mxr(n + 1,-1);
//	for (int i = 1,l,r; i <= q; i++) {
//		cin >> l >> r;
//		mxr[l] = max(mxr[l], r);
//	}
//	vector<pair<int, int>>range;
//	int mr = 0;
//	for (int i = 1; i <= n; i++) {
//		if (mxr[i] > mr) {
//			mr = mxr[i];
//			range.push_back({ i,mr });
//		}
//	}
//	int lo = 0, hi = (int)range.size() - 1;
//	int ans = 0;
//	while (lo <= hi) {
//		int mid = lo + hi >> 1;
//		int l = range[mid].first;
//		int r = range[mid].second;
//		int pre = ask(1, r);
//		int suf = ask(l, n);
//		ans = max(ans, min(pre, suf));
//		if (pre > suf) {
//			hi = mid - 1;
//		}
//		else {
//			lo = mid + 1;
//		}
//	}
//	cout << "! " << ans << endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}