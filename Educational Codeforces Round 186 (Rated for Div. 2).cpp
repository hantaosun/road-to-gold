//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	string s;
//	cin >> n;
//	cin >> s;
//	s = " " + s;
//	bool g2025=0;
//	bool g2026 = 0;
//	for (int i = 1; i <= n - 3; i++) {
//		if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2') {
//			if (s[i + 3] == '5')g2025 = 1;
//			if (s[i + 3] == '6')g2026 = 1;
//		}
//	}
//	if (!g2025 || g2026) {
//		cout << 0 << endl;
//		return;
//	}
//	else {
//		cout << 1 << endl;
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


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int a, b;
//	cin >> a >> b;
//	int a1 =0 ;
//
//	int b1 =0 ;
//	int ta = a, tb = b;
//	int cur = 1, turn = 0,rd=0;
//	while (true) {
//		if (turn == 0) {
//			if (ta >= cur) {
//				ta -= cur;
//			}
//			else break;
//		}
//		else {
//			if (tb >= cur){
//				tb -= cur;
//			}
//			else {
//				break;
//			}
//		}
//		rd++;
//		turn ^= 1;
//		cur *= 2;
//	}
//	a1 = rd;
//	ta = a;
//	tb = b;
//	turn = 0;
//	cur = 1;
//	rd = 0;
//	while (true) {
//		if (turn == 0) {
//			if (tb >= cur) {
//				tb -= cur;
//			}
//			else break;
//		}
//		else {
//			if (ta >= cur) {
//				ta -= cur;
//			}
//			else {
//				break;
//			}
//		}
//		rd++;
//		turn ^= 1;
//		cur *= 2;
//	}
//	b1 = rd;
//	cout << max(a1, b1) << endl;
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
//	vector<int>b(n + 1);
//	vector<int>c(n + 1);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 0; i < n; i++) {
//		cin >> b[i];
//	}
//	for (int i = 0; i < n; i++) {
//		cin >> c[i];
//	}
//	int ab=0, bc = 0;
//	for (int i = 0; i < n; i++) {
//		int flag = 1;
//		for (int j = 0; j < n; j++) {
//			if (a[j] >= b[(j + i) % n]) {
//				flag = 0;
//				break;
//			}
//		}
//		ab += flag;
//	}
//	for (int i = 0; i < n; i++) {
//		int flag = 1;
//		for (int j = 0; j < n; j++) {
//			if (b[j] >= c[(j + i) % n]) {
//				flag = 0;
//				break;
//			}
//		}
//		bc += flag;
//	}
//	cout << ab * bc*n << endl;
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
//const int mod = 998244353;
//const int N = 55;
//using namespace std;
//int fac[N];
//int finv[N];
//int qpow(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a % mod;
//		}
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ans;
//}
//void prepare() {
//	fac[0] =finv[0]= 1;
//	for (int i = 1; i <= 50; i++) {
//		fac[i] = fac[i - 1] * i%mod;
//	}
//	finv[50] = qpow(fac[50], mod - 2);
//	for (int i = 49; i >= 1; i--) {
//		finv[i] = finv[i + 1] * (i + 1) % mod;
//	}
//}
//int C(int n, int m) {
//	return fac[n] * finv[n - m]%mod * finv[m]%mod;
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	int a0;
//	cin >> a0;
//	int mx = -1;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		mx = max(mx, a[i]);
//	}
//	int mxc = 0;
//	int diff = 0;
//	int diff1 = 0;
//	for (int i = 1; i <= n; i++) {
//		if (a[i] == mx) {
//			mxc++;
//		}
//		else diff += mx - 1 - a[i];
//		diff1 += mx - a[i];
//	}
//	if (diff > a0) {
//		cout << 0 << endl;
//		return;
//	}
//	if (diff1 <= a0) {
//		cout << fac[n] << endl;
//		return;
//	}
//	//cout << C(a0 - diff + mxc, mxc) << "**\n";
//	//cout << n << " " << mxc << " " << a0 << " " << diff << "&&\n";
//	cout << fac[n - mxc] * fac[mxc] % mod * C(a0 - diff + mxc, mxc) % mod << endl;
//}
//signed main() {
//	prepare();
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 4e5 + 5;
//void solve() {
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<int>a(m+1);
//	vector<pair<int, int>>c(n + 1);
//	vector<int>x(n + 1);
//	vector<int>y(n + 1);
//	vector<int>z(n + 1);
//	for (int i = 1; i <= m; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> x[i] >> y[i] >> z[i];
//		c[i].first = x[i];
//		c[i].second = z[i] - y[i];
//		k -= y[i];
//	}
//	sort(c.begin() + 1, c.end(), [&](auto px,auto py) {
//		if (px.first == py.first)return px.second < py.second;
//		return px.first < py.first;
//		});
//	sort(a.begin() + 1, a.end());
//	int r = 1;
//	priority_queue<int, vector<int>>pq;
//	int ans = 0;
//	for (int i = 1; i <= m; i++) {
//		while (r <= n && c[r].first <= a[i]) {
//			pq.push(c[r].second);
//			r++;
//		}
//		if(!pq.empty())pq.pop(),ans++;
//	}
//	for (int i = r; i <= n; i++)pq.push(c[i].second);
//	stack<int>tmp;
//	while (!pq.empty()) {
//		tmp.push(pq.top());
//		pq.pop();
//	}
//	while (!tmp.empty()) {
//		if (k < tmp.top())break;
//		k -= tmp.top();
//		tmp.pop();
//		ans++;
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
