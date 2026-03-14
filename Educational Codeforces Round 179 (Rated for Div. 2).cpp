//A
//#include<iostream>
//using namespace std;
//void solve() {
//	int e;
//	cin >> e;
//	int cnt = 0;
//	int m = 0;
//	while (m < e) {
//		m = m * 2 + 1;
//		cnt++;
//	}
//	cout << cnt * 2 + 1<<endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}
//B
//#include<iostream>
//#include<vector>
//using namespace std;
//int f[] = { 0,1,2,3,5,8,13,21,34,55,89,144 };
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>box(m + 5, vector<int>(3));
//	for (int i = 1; i <= m; i++) {
//		cin >> box[i][0] >> box[i][1] >> box[i][2];
//	}
//	if (n > 11) {
//		for (int i = 1; i <= m; i++)
//			cout << 0;
//		cout << endl;
//		return;
//	}	
//	vector<int>ans(m+5);
//	for (int i = 1; i <= m;i++) {
//		if (max(max(box[i][0], box[i][1]), box[i][2]) < f[n] + f[n - 1] || min(min(box[i][0], box[i][1]), box[i][2]) < f[n])ans[i] = 0;
//		else ans[i] = 1;
//	}
//	for (int i = 1; i <= m; i++) {
//		cout << ans[i];
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
//C
//#include<iostream>
//#include<vector>
//#include<climits>
//#define int long long
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 5);
//	vector<pair<int,int>>ltk;
//	int ans = LLONG_MAX;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int l = 1, r = 1;
//	for (; r <= n; r++) {
//		if (a[r] != a[l]) {
//			ltk.push_back(make_pair(a[l], r - l));
//			l = r;
//		}
//	}
//	if (l != r)ltk.push_back(make_pair(a[l],r-l));
//	for (int i = 0; i < ltk.size(); i++) {
//		ans = min(ans, ltk[i].first * (n - ltk[i].second));
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
//D
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//bool f(int a, int b) {
//	return a / 100 < b / 100;
//}
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(m);
//	for (int i = 0; i < m; i++) {
//		cin >> a[i];
//	}
//	sort(a.begin(), a.end()); a.push_back(0);
//	int t = n / 2;
//	vector<int>b(n);
//	for (int i = 0; i < t; i++) {
//		b[i] = i;
//	}
//	for (int i = t; i < n; i++) {
//		b[i] = m - (i - t) - 1;
//	}
//	for (int i = 0; i < n; i++) {
//		for (int k = 1; k <= 6; k++) {
//			if (k & 1) {
//				cout << a[b[i]] << " ";
//			}
//			else {
//				cout << a[m - b[i] - 1] << " ";
//			}
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