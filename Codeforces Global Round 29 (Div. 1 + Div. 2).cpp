//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int x, y;
//	cin >> x >> y;
//	if (y > x) {
//		cout << 2 << '\n';
//		return;
//	}
//	else {
//		if (2+y<=x&&y>=2) {
//			cout << 3 << '\n';
//		}
//		else {
//			cout << -1 << '\n';
//		}
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
//	int n;
//	cin >> n;
//	vector<int>a;
//	for (int i = n - 1; i >= 1; i -= 2) {
//		a.push_back(i);
//	}
//	for (int i = n; i >= 1; i -= 2) {
//		a.push_back(i);
//	}
//	cout << n << " ";
//	for (int i = n - 1; i >= 1; i--) {
//		cout << i << " ";
//	}
//	cout << n << " ";
//	for (int i = 1; i <= n - 1; i++) {
//		cout << i << " ";
//	}
//	cout << '\n';
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
//	string s;
//	cin >> s;
//	s = "1" + s;
//	s = s + "10";
//	for (int i = 2; i <= n-1; i++) {
//		if (s[i] == '0'
//			&& s[i - 1] == '1' && (i == 2 || s[i - 2] == '1')
//			&& s[i + 1] == '1' && (i == n - 1 || s[i + 2] == '1')) {
//			cout << "NO\n";
//			return;
//		}
//	}
//	int one = 0;
//	int last = -1;
//	for (int i = 0; i <= n+2; i++) {
//		if (s[i] == '1') {
//			one++;
//		}
//		else {
//			if (one >= 2) {
//				if (last != -1) {
//					//cout << i << " " << one << " " << last << "**\n";
//					bool flag = 1;
//					int c0 = 0;
//					for (int j = last; j < i - one-1; j++) {
//						if (s[j] == s[j + 1]) {
//							flag = 0;
//							break;
//						}
//					}
//					if (flag) {
//						for (int j = last; j < i - one; j++) {
//							if (s[j] == '0') {
//								c0++;
//							}
//						}
//						if (c0 % 2 == 1) {
//							cout << "NO\n";
//							return;
//						}
//					}
//				}
//				last = i;
//			}
//			one = 0;
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
//#define int long long
//using namespace std;
//struct Compare {
//	bool operator()(pair<int,int>&a,pair<int,int>&b) {
//		return a.second < b.second;
//	}
//};
//void solve() {
//	int n;
//	cin >> n;
//	int sum = 0;
//	map<int, int>mp;
//	for (int i = 1,u; i <= n; i++) {
//		cin >> u;
//		mp[u]++;
//		sum +=u;
//	}
//	vector<int>od;
//	for (auto v : mp) {
//		if (v.first % 2 == 1) {
//			od.push_back(v.second);
//		}
//	}
//	sort(od.begin(), od.end());
//	int delta = 0;
//	int sig=1;
//	for (int i = od.size() - 1; i >= 0; i--) {
//		delta += od[i] * sig;
//		sig *= -1;
//	}
//	//cout << delta << " " << sum << "***\n";
//	cout << (sum + delta) / 2 << ' ';
//	cout << (sum - delta) / 2 << "\n";
//
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}