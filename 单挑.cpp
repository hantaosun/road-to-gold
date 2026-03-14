//#include<bits/stdc++.h>
//using namespace std;
//int fa[10005];
//int find(int x) {
//	while (x != fa[x]) {
//		x = fa[x] = fa[fa[x]];
//	}
//	return x;
//}
//void Union(int x, int y) {
//	int fx = find(x);
//	int fy = find(y);
//	fa[fx] = fa[fy];
//}
//int main() {
//	int n;
//	cin >> n;
//	vector<int>p(n + 1);
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//		Union(i, p[i]);
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		if (fa[i] == i)ans++;
//	}
//	cout << ans << endl;
//}


//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>rock(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> rock[i];
//	}
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		a[i] = a[i - 1] + rock[i];
//	}
//	int l = 1, r = n;
//	int num;
//	while (l <= r) {
//		int mid = l + r >> 1;
//		cout << "? "<<mid-l+1<<" ";
//		for (int i = l; i <= mid; i++) {
//			cout << i << " ";
//		}cout << endl;
//		cin >> num;
//		if (num != a[mid] - a[l - 1]) {
//			if (mid == l) {
//				cout << "! " << l << endl;
//				return;
//			}
//			r = mid;
//		}
//		else {
//			if (mid + 1 == r) {
//				cout << "! " << r << endl;
//				return;
//			}
//			l = mid + 1;
//		}
//	}
//	cout << l << endl;
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
//int main() {
//	int n;
//	cin >> n;
//
//}


//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n, k;
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (i == j)cout << k << " ";
//			else cout << 0 << " ";
//		}
//		cout << endl;
//	}
//}

//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	int cnt = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		if (a[i] == 0) {
//			cnt++;
//		}
//	}
//	vector<int>b(n + 1);
//	int cnt1 = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//		if (b[i] == 0)cnt1++;
//	}
//	cout << abs(cnt1 - cnt) + 1 << endl;
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
//	string a;
//	cin >> a;
//	string b;
//	cin >> b;
//	sort(a.begin(), a.end());
//	sort(b.begin(), b.end());
//	string c = "";
//	int sa = 0, sb = 0;
//	int tsa = 0, tsb;
//	while (sa < a.size()&&sb<b.size()) {
//		if (a[sa] < b[sb]&&tsa<=k) {
//			c += a[sa];
//			sa++;
//			tsb == 0;
//		}
//		else {
//			c += b[sb];
//			sb++;
//			tsa = 0;
//		}
//	}
//	while (sa < a.size()) {
//		c += a[sa];
//		sa++;
//	}
//	while (sb < b.size()) {
//		c += b[sb];
//		sb++;
//	}
//	cout << c << endl;
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