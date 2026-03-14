//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	int ans = (n / 15) * 3;
//	if (n % 15 == 1) {
//		ans++;
//	}
//	else if (n % 15 >= 2) {
//		ans += 2;
//	}
//	cout << ans + 1 << '\n';
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
//	int n, x, k;
//	cin >> n >> x >> k;
//	string s;
//	cin >> s;
//	s = " " + s;
//	int lmax=0, rmax = 0;
//	int ss = 0;
//	for (int i = 1; i <= min(n, k); i++) {
//		if (s[i] == 'L') {
//			ss--;
//		}
//		else {
//			ss++;
//		}
//		lmax = min(lmax, ss);
//		rmax = max(rmax, ss);
//	}
//	for (int i = 1; i <= min(n, k); i++) {
//		if (s[i] == 'L') {
//			x--;
//		}
//		else {
//			x++;
//		}
//		if (x == 0)break;
//	}
//	if (x == 0) {
//		int psum = 0;
//		int pos = 0;
//		for (int i = 1; i <= n; i++) {
//			if (s[i] == 'L') {
//				psum++;
//			}
//			else {
//				psum--;
//			}
//			if (psum == 0) {
//				pos = i;
//				break;
//			}
//		}
//		if (!pos) {
//			cout << 1 << '\n';
//			return;
//		}
//		else {
//			cout << 1 + k / pos<<'\n';
//		}
//	}
//	else {
//
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
//	int n,k;
//	cin >> n>>k;
//	string s;
//	cin >> s;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
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