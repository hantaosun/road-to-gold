//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	if (n >= 2 && m >= 3||n>=3&&m>=2) {
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
//#define int long long
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	int ans = 0;
//	for (int i = 1,a,b,c,d; i <= n; i++) {
//		cin >> a >> b >> c >> d;
//		if (b > d) {
//			ans += a+b - d;
//		}
//		else if (a > c) {
//			ans += a - c;
//		}
//	}
//	cout << ans << endl;
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
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<array<int, 3>>p;
//	for (int i = 1,x,y; i <= n; i++) {
//		cin >> x >> y;
//		p.push_back({ x,y,i });
//	}
//	sort(p.begin(), p.end(), [](auto a, auto b) {
//		return a[0] < b[0];
//		});
//	int midx = p[n / 2-1][0];
//	sort(p.begin(), p.end(), [&](auto a, auto b) {
//		return a[1]<b[1];
//		});
//	int midx = p[n / 2-1][1];
//	vector<int>ur;
//	vector<int>ul;
//	vector<int>dr;
//	vector<int>dl;
//	for(int i)
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}