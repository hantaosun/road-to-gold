//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, h, l;
//	cin >> n >> h >> l;
//	vector<int>a(n + 1);
//	int mn = min(h, l), mx = max(h, l);
//	int c = 0, b = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		if (a[i] <= mx&&a[i]>mn) {
//			b++;
//		}
//		else if(a[i]<=mn) {
//			c++;
//		}
//	}
//	int ans = 0;
//	ans += min(b, c);
//	if (b > c) {
//		cout << ans << endl;
//		return;
//	}
//	else {
//		ans += (c - b) / 2;
//		cout << ans << endl;
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
//#define int long long
//using namespace std;
//void solve() {
//	int n, x;
//	cin >> n >> x;
//	vector<int>a(n+1);
//	vector<int>b(n+1);
//	vector<int>c(n+1);
//	int s = 0;
//	int mx = INT_MIN;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i] >> b[i] >> c[i];
//		s += a[i] * (b[i] - 1);
//	}
//	if (s >= x) {
//		cout << 0 << endl;
//		return;
//	}
//	int rst = x - s;
//	int ans = LLONG_MAX;
//	for (int i = 1; i <= n; i++) {
//		int rr = rst+c[i]-a[i];
//		int d = a[i] * b[i] - c[i];
//		if (rr < 0) {
//			cout << 1 << endl;
//			return;
//		}
//		if (d > 0) {
//			rr -= a[i] * (b[i] - 1);
//			if (rr <= 0) {
//				cout << 1 << endl;
//				return;
//			}
//			else {
//				ans = min(ans, (rr + d - 1) / d + 1);
//			}
//		}
//	}
//	if (ans == LLONG_MAX) {
//		cout << -1 << endl;
//		return;
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
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<bool>ap(n + 1,0);
//	vector<int>a(n + 1);
//	a[n] = 1;
//	for(int i=2;i<n;i++){
//		ap[i ^ 1] = 1;
//		a[i] = i ^ 1;
//	}
//	for (int i = 2; i <= n; i++) {
//		if (!ap[i]) {
//			a[1] = i;
//			break;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << a[i] << " ";
//	}cout << endl;
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
//	if (((n - 1) & 1) == 0) {
//		cout << n - 1 << " ";
//		for (int i = 2; i < n - 1; i++) {
//			cout << (i ^ 1)<<" ";
//		}
//		cout << 1 << " ";
//		cout << n << endl;
//	}
//	else {
//		vector<bool>ap(n + 1, 0);
//		a[n] = n - 2;
//		a[n - 1] = 1;
//		a[n - 2] = n - 1;
//		ap[n - 2] = ap[1] = ap[n - 1] = 1;
//		for (int i = n - 3; i >= 2; i--) {
//			if (ap[n] || ((n ^ i) > n) || (!ap[n ^ i])) {
//				a[i] = i ^ 1;
//				ap[i ^ 1] = 1;
//			}
//			else {
//				a[i] = n;
//				ap[n] = 1;
//			}
//		}
//		for (int i = 1; i <= n; i++) {
//			if (!ap[i]) {
//				a[1] = i;
//				break;
//			}
//		}
//		if (!ap[n]) {
//			cout << -1 << endl;
//			return;
//		}
//		for (int i = 1; i <= n; i++) {
//			cout << a[i] << " ";
//		}cout << endl;
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
//#define int long long
//using namespace std;
//const int mod = 1e9 + 7;
//const int N = 2e5 + 5;
//int fac[N];
//int finv[N];
//int C(int n, int m) {
//	return fac[n] * finv[m] * finv[n - m];
//}
//void solve() {
//	int n, c;
//	cin >> n >> c;
//	string s;
//	cin >> s;
//	s = " " + s;
//	if (s[1] != '1') {
//		cout << -1 << endl;
//	}
//	int state = 1;
//	int fans=LLONG_MAX;
//	int c1 = 0;
//	for (int i = 2; i <= n; i++) {
//		if (s[i] == '1')c1++;
//		if (state == 1 && s[i] != '1') {
//			state++;
//		}
//		else if (state == 2 && s[i] != '0') {
//			state++;
//		}
//		if(state==3&&s[i]=='-')
//		if (state == 3) {
//			int ans = C(n - 2, c1) * 2 * fac[n - 2 - c1];
//			if (ans % c != 0) {
//				fans = min(ans, fans);
//			}
//		}
//	}
//	cout << fans << endl;
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
//const int mod = 1e9 + 7;
//int gcd(int a, int b) {
//	return b > 0 ? gcd(b, a % b) : a;
//}
//void solve() {
//	int n, c;
//	cin >> n >> c;
//	string s;
//	cin >> s;
//	s = " " + s;
//	int ans = 1;
//	if (s[1] != '1' || s[n] != '1') {
//		cout << -1 << endl;
//		return;
//	}
//	for (int i = 1; i <= n-1; i++) {
//		if (s[i] == '1') {
//			ans = ans * 2 % mod;
//			c /= gcd(c, 2);
//		}
//		else {
//			ans = ans * (i - 1) % mod;
//			c /= gcd(c, i - 1);
//		}
//	}
//	if (c == 1||ans==0) {
//		cout << -1 << endl;
//		return;
//	}
//	else {
//		cout << ans << endl;
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
//const int mod = 1e9 + 7;
//int gcd(int a, int b) {
//	return b > 0 ? gcd(b, a % b) : a;
//}
//void solve() {
//	int n, c;
//	cin >> n >> c;
//	string s;
//	cin >> s;
//	s = " " + s;
//	vector<int>unk;
//	if (s[1] == '0' || s[n] == '0') {
//		cout << -1 << endl;
//		return;
//	}
//	s[1] = s[n] = '1';
//	int ans = 1;
//	for (int i = 1; i <= n - 1; i++) {
//		if (s[i] == '?') {
//			unk.push_back((i - 1));
//		}
//		else if (s[i] == '1') {
//			ans = ans * 2 % mod;
//			c /= gcd(c, 2);
//		}
//		else {
//			ans = ans * (i - 1) % mod;
//			c /= gcd(c, i - 1);
//		}
//	}
//	if (c == 1 || ans == 0) {
//		cout << -1 << endl;
//		return;
//	}
//	if (c != (c & (-c))) {
//		for (int i = 0; i < unk.size(); i++) {
//			if(unk[i]>=2)ans = ans * 2 % mod;
//		}
//		cout << ans << endl;
//		return;
//	}
//	else {
//		int num = 0;
//		while (c != 2) {
//			num++;
//			c >>= 1;
//		}
//		sort(unk.begin(), unk.end());
//		vector<int>od;
//		for (auto v : unk) {
//			if (v & 1)od.push_back(v);
//		}		
//		int ev = (int)(unk.size()) - (int)(od.size());
//		if (ev > num) {
//			cout << -1 << endl;
//			return;
//		}
//		num -= ev;
//		for (int i = 0; i < (int)(od.size()) - num; i++) {
//			ans =ans*od[i]%mod;
//		}
//		for (int i = 1; i <= (int)unk.size() - (int)od.size(); i++) {
//			ans = ans * 2 % mod;
//		}
//		for (int i = max(0ll, (int)(od.size()) - num); i < od.size(); i++) {
//			if(od[i]>2)ans = ans * 2 % mod;
//		}
//		cout << ans << endl;
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
//using namespace std;
//vector<int>dep;
//vector<int>fson;
//vector<vector<int>>g;
//vector<vector<int>>t;
//vector<int>in;
//vector<int>pa;
//int md;
//void dfs(int u, int fa) {
//	dep[u] = dep[fa] + 1;
//	pa[u] = fa;
//	md = max(dep[u], md);
//	fson[fa] = u;
//	t[dep[u]].push_back(u);
//	for (auto v : g[u])if (v != fa) {
//		dfs(v, u);
//	}
//
//}
//void solve() {
//	int n;
//	cin >> n;
//	g.assign(n + 1, {});
//	for (int i = 1,u,v; i <= n; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	int T, tt = 0;
//	for (int i = 1; i <= md; i++) {
//		if (t[i].size() > tt) {
//			T = i;
//			tt = t[i].size();
//		}
//	}
//	int rd=tt;
//	for (int i = 1; i <= n; i++) {
//		if (g[i].size() >= tt + 1 || i == 1 && g[i].size() >= tt) {
//			rd = tt + 1;
//		}
//	}
//	vector<vector<int>>S(tt + 1);
//	for (int i = 1; i <= tt; i++) {
//		in[t[T][i-1]]= i;
//		S[i].push_back(t[T][i - 1]);
//	
//	}
//	for (int i = 1; i <= md; i++) {
//		sort(t[i].begin(), t[i].end(), [&](int x,int y) {
//			return g[x].size() > g[y].size();
//			});
//	}
//	for (int i = tt + 1; i <= md; i++) {
//		vector<int>& tmp = t[i];
//		if (g[tmp[0]].size() == 1)continue;
//		for (int j = 0; j < tmp.size(); j++) {
//			int nd = tmp[j];
//			if(tmp[j])
//		}
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}