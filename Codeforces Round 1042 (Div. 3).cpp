//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int big = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//		if (a[i] > b[i]) {
//			big += a[i] - b[i];
//		}
//
//	}
//	cout << big+1<< endl;
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
//	if (n & 1) {
//		for (int i = 1; i <= n; i++) {
//			if (i & 1) {
//				cout << -1 << " ";
//			}
//			else {
//				cout << 3 << " ";
//			}
//		}cout << '\n';
//	}
//	else {
//		for (int i = 1; i < n; i++) {
//			if (i & 1) {
//				cout << -1 << " ";
//			}
//			else {
//				cout << 3 << " ";
//			}
//		}
//		cout << 2 << endl;
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
//	vector<int>S(n+1);
//	vector<int>T(n+1);
//	map<int, int>m;
//	map<int, int>m1;
//	for (int i = 1; i <= n; i++) {
//		cin >> S[i];
//		m[S[i] % k]++;
//		m[k - S[i] % k]++;
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> T[i];
//		m1[T[i] % k]++;
//		m1[k - T[i] % k]++;
//	}
//	bool flag = 1;
//	for (auto [a, cnt] : m1) {
//		if (cnt != m[a]) {
//			flag = 0;
//			break;
//		}
//	}
//	if (flag) {
//		cout << "YES\n";
//	}
//	else {
//		cout << "NO\n";
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
//	vector<vector<int>>g(n + 1);
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	if (n == 2) {
//		cout << 0 << endl;
//		return;
//	}
//	int leaf = 0;
//	int ma = -1;
//	for (int i = 1; i <= n; i++) {
//		if (g[i].size() == 1) {
//			leaf++;
//		}
//		int cnt = 0;
//		for (auto v : g[i]) {
//			if (g[v].size() == 1)cnt++;
//		}
//		ma = max(ma, cnt);
//	}
//	cout << leaf - ma << endl;
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
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	if (a[n] != b[n]) {
//		cout << "NO\n";
//		return;
//	}
//	for (int i = n - 1; i >= 1; i--) {
//		if (a[i]!=b[i]&&((a[i] ^ a[i + 1]) != b[i]) && ((a[i] ^ b[i + 1]) != b[i])){
//			cout << "NO\n";
//			return;
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
//void solve() {
//	int n;
//	cin >> n;
//	string a, b;
//	cin >> a >> b;
//	a = " " + a;
//	b = " " + b;
//	vector<int>prea(n + 1);
//	vector<int>preb(n + 1);
//	for (int i = 1; i <= n; i++) {
//		if (a[i] == '0') {
//			prea[i] = prea[i - 1] + 1;
//		}
//		else {
//			prea[i] = prea[i - 1] - 1;
//		}
//		if (b[i] == '1') {
//			preb[i] = preb[i - 1] + 1;
//		}
//		else {
//			preb[i] = preb[i - 1] - 1;
//		}
//	}
//	int ans = 0;
//	sort(prea.begin() + 1, prea.end());
//	sort(preb.begin() + 1, preb.end());
//	for (int i = 1; i <= n; i++) {
//		int t = lower_bound(preb.begin()+1, preb.end(), prea[i]) - preb.begin()-1;
//		//cout << "t:" << t <<" "<<prea[i] << endl;
//		ans +=prea[i]*t;
//		t = upper_bound(preb.begin() + 1,preb.end(), prea[i]) - preb.begin();
//		//cout << "t:" << t << endl;
//		ans -= prea[i] * (n - t + 1);
//	}
//	//cout << ans << "\n";
//	for (int i = 1; i <= n; i++) {
//		int t = lower_bound(prea.begin()+1, prea.end(), preb[i]) - prea.begin()-1;
//		//cout << "t:" << t <<" "<<preb[i] << endl;
//		ans +=preb[i]*t;
//		t = upper_bound(prea.begin() + 1,prea.end(), preb[i]) - prea.begin();
//		//cout << "t:" << t << endl;
//		ans -= preb[i] * (n - t + 1);
//	}
//	//cout << ans << endl;
//	ans = abs(((n) * (n) * (n + 1) - ans) / 2);
//	cout << ans << '\n';
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
//#define int long long
//using namespace std;
//const int mod = 1e9 + 7;
//int biao[33];
//int ans = 1;
//int log2(int x) {
//	int an = 0;
//	while ((1ll << an) <= (x >> 1)) {
//		an++;
//	}
//	return an;
//}
//void f(int k,int c) {
//	//cout <<"k:"<< k << endl;
//	if (k == 0)return;
//	for (int i = 1;i<=c; i++) {
//		//cout << k << " " << i << endl;
//		//cout << log2(k) << endl;
//		if (i-1 <= log2(k)) {
//			ans = ans * biao[i]%mod;
//			k -= (1ll << i - 1);
//		}
//		else {
//			k -= 1;
//			ans = ans * i%mod;
//			f(k, i - 1);
//			break;
//		}
//		if (k == 0)break;
//	}
//}
//void solve() {
//	int n,k;
//	cin >> n>>k;
//	vector<int>s(n+1);
//	for (int i = 1; i <= n; i++) {
//		cin >> s[i];
//	}
//	sort(s.begin() + 1, s.end());
//	ans = 1;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] - 1 <= log2(k)) {
//			k -= 1ll << (s[i] - 1);
//			ans =ans* biao[s[i]]%mod;
//		}
//		else {
//			k -= 1;
//			ans = ans * s[i]% mod;
//			f(k, s[i] - 1);
//			break;
//		}
//		if (k == 0) {
//			break;
//		}
//	}
//	cout << ans << '\n';
//}
//void prepare() {
//	biao[1] = 1;
//	int sum = 1;
//	for (int i = 2; i <= 32; i++) {
//		biao[i] = i * sum % mod;
//		sum =sum* biao[i]%mod;
//	}
//}
//signed main() {
//	prepare();
//	//for (int i = 1; i <= 32; i++) {
//	//	cout << biao[i] << " ";
//	//}cout << '\n';
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}