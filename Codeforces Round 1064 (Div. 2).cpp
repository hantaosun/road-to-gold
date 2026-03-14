//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s = " " + s;
//	int t = s[n]-'a';
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] - 'a' != t) {
//			ans++;
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
//	int a, b, n;
//	cin >> a >> b >> n;
//	if (a>=b*n||b==a) {
//		cout << 1 << endl;
//	}
//	else {
//		cout << 2 << endl;
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
//	int mx = -1;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		mx = max(mx, a[i]);
//	}
//	int ans = 0;
//	for (int i = 1; i < n; i++) {
//		ans += max(a[i], a[i + 1]);
//	}
//	ans += max(a[1], a[n]);
//	ans -= mx;
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
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	list<int>alive;
//	vector<list<int>::iterator>w(n + 1);
//	for (int i = 1, u; i <= n; i++) {
//		cin >> a[i];
//		w[i]=alive.insert(alive.end(), i);
//	}
//	
//	auto nexp = [&](const list<int>::iterator& it) {
//		return next(it) == alive.end() ? alive.begin() : next(it);
//		};
//	auto prep = [&](const list<int>::iterator& it) {
//		return it == alive.begin() ? --alive.end() : prev(it);
//		};
//	auto hole = [&](list<int>::iterator& it) {
//		return a[*it] <= min(a[*(nexp(it))], a[*(prep(it))]);
//		};
//	queue<int>q;
//	{
//		int i = 1;
//		for (auto it = alive.begin(); it != alive.end(); ++it,i++) {
//			if (hole(it)) {
//				q.push(i);
//			}
//		}
//	}
//	long long ans = 0;
//	vector<bool>mark(n + 1,false);
//	while (alive.size() > 1) {
//		auto i = q.front();
//		q.pop();
//		if (mark[i])continue;
//		mark[i] = true;
//		auto it = w[i];
//		ans += min(a[*prep(it)], a[*nexp(it)]);
//		auto jt = nexp(it);
//		alive.erase(it);
//		it = jt;
//		if (hole(it))q.push(*it);
//		it = prep(it);
//		if (hole(it))q.push(*it);
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
//using namespace std;
//const int N = 5005;
//void solve() {
//	int n;
//	cin >> n;
//	map<int, int>mp;
//	vector<int>dp(n + 1);
//	for (int i = 1,u; i <= n; i++) {
//		cin >> u;
//		mp[u]++;
//	}
//	for (auto v : mp) {
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