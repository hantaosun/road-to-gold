//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	int ans = 0;
//	int maxMinus = INT_MIN+5;
//	int minZ = INT_MAX-5;
//	int minu = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		if (a[i] == 0) {
//			ans++;
//		}
//		if (a[i] <0) {
//			minu++;
//			maxMinus = max(a[i], maxMinus);
//		}
//		if (a[i] > 0) {
//			minZ = min(a[i], minZ);
//		}
//	}
//	if (minu & 1&&ans==0) {
//		ans += min(minZ+1,1 - maxMinus);
//	}
//	cout << ans << endl;
//}
//signed main() {
//	int T;
//	cin >> T;
//	while (T--) {
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
//	int maxv = INT_MIN, maxpos = -1;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		if (a[i] > maxv||i==n&&a[i]==maxv) {
//			maxv = a[i];
//			maxpos = i;
//		}
//	}	
//	if (n == 1 || n == 2) {
//		cout << 0 << '\n';
//		return;
//	}
//	if (maxpos == 1 || maxpos == n) {
//		cout << maxv * (n - 2) << '\n';
//		return;
//	}
//	else {
//		cout << maxv * (n - 3) + max(a[1], a[n])<<'\n';
//		return;
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
//int main() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	vector<int>pos(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		pos[a[i]] = i;
//	}
//	int max 
//}