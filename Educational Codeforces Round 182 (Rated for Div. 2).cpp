//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		a[i] = (a[i - 1] + a[i]) % 3;
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			int x = a[i], y = (a[j] - a[i] + 3) % 3, z = (a[n] - a[j] + 3)%3;
//			if (a[i] == (a[j] - a[i] + 3) % 3 && a[i] == (a[n] - a[j] + 3) % 3) {
//				cout << i << " " << j << '\n';
//				return;
//			}
//			else if (x != y && y != z && x != z) {
//				cout << i << " " << j << '\n';
//				return;
//			}
//		}
//	}
//	cout << 0 << " " << 0 << '\n';
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
//	vector<int>p(n + 1);
//	vector<int>appear(n + 1, 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//	}
//	int l = n+1, r = 0;
//	int f0=-1, l0=-1;
//	for (int i = 1; i <= n; i++) {
//		appear[p[i]] = true;
//		if (p[i] != 0 && p[i] != i) {
//			l = min({ p[i], i, l });
//			r = max({ p[i],i,r });
//		}
//		else if (p[i] == 0) {
//			if (f0 == -1) {
//				f0 = i;
//			}
//			l0 = i;
//		}
//	}
//	int ans = 0;
//	if (r > l) {
//		ans = r - l + 1;
//	}
//	if (l0 == -1 || f0 == -1) {
//		cout << ans << '\n';
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!appear[i]) {
//			if(l0!=i)ans = max(ans, l0 - i + 1);
//			if(f0!=i)ans = max(ans, i - f0 + 1);
//		}
//	}
//	if (l0 != f0) {
//		r = max(l0, r);
//		l = min(f0, l);
//	}
//	ans = max(r - l + 1, ans);
//	cout << (ans == 1 ? 0 : ans) << '\n';
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
//const int mod = 998244353;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	for (int i = 1; i <=n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <=n; i++) {
//		cin >> b[i];
//	}
//	vector<int>dp(n + 1,0);
//	dp[1] = 2;
//	for (int i = 2; i <= n; i++) {
//		if (a[i - 1] <= a[i] && b[i - 1] <= b[i]) {
//			dp[i] = dp[i - 1];
//		}
//		if (a[i - 1] <= b[i] && b[i - 1] <= a[i]) {
//			dp[i] = (dp[i] + dp[i - 1]) % mod;
//		}
//	}
//	cout << dp[n] << '\n';
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
//const int N = 2e5 + 5;
//int pref[N];
//int cnt[N];
//void solve() {
//	int n, y;
//	cin >> n >> y;
//	memset(pref, 0, sizeof(pref));
//	memset(cnt, 0, sizeof(cnt));
//	int mx = -1;
//	for (int i =1,u; i <= n; i++) {
//		cin >> u;
//		mx = max(mx, u);
//		pref[u]++;
//		cnt[u]++;
//	}
//	for (int i = 1; i <= N; i++) {
//		pref[i] += pref[i - 1];
//	}
//	int ans = LLONG_MIN;
//	for (int x = 2; x <= mx+1; x++) {
//		int sum = -n*y;
//		for (int j = 1; j <= (mx + x - 1) / x; j++) {
//			int l = (j - 1) * x, r = min(mx, j * x);
//			if (l > mx)break;
//			//cout <<x<<" "<< l << " " << r <<" " << sum<< "**\n";
//			sum += y * min(cnt[j], pref[r] - pref[l]);
//			sum += j * (pref[r] - pref[l]);
//		}
//		ans = max(ans, sum);
//	}
//	cout << ans << "\n";
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
//#define int long long
//using namespace std;
//const int N = 5e3 + 5;
//const int mod = 998244353;
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
//int dp[N][N];//必选该位置为止匹配到j位置的方案数
//int dp1[N][N];
//int n=0;
//void solve() {
//	for (int i = 0; i <= n + 5; i++) {
//		for (int j = 0; j <= n + 5; j++) {
//			dp[i][j] = dp1[i][j] = 0;
//		}
//	}
//	cin >> n;
//	vector<int>a(n + 1);
//	vector<int>vsort;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		vsort.push_back(a[i]);
//	}
//	sort(vsort.begin(), vsort.end());
//	vsort.erase(unique(vsort.begin(), vsort.end()), vsort.end());
//	int mx = -1;
//	for (int i = 1; i <= n; i++) {
//		a[i] = lower_bound(vsort.begin(), vsort.end(),a[i]) - vsort.begin() + 1;
//		mx = max(mx, a[i]);
//	}
//	vector<int>sta;
//	sta.push_back(-1);
//	for (int i = 1; i <= n; i++) {
//		if (a[i] > sta.back())sta.push_back(a[i]);
//	}
//	dp[0][0] = 1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j < sta.size()-1; j++) {
//			if (a[i]==sta[j+1]) {
//				dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j])%mod;
//			}
//			else if(a[i]<=sta[j]) {
//				dp[i][j] = (dp[i][j] + dp[i - 1][j])%mod;
//			}
//		}
//		for (int j = 0; j < sta.size(); j++) {
//			dp[i][j] = (dp[i][j] + dp[i - 1][j])%mod;
//		}
//	}
//	int t1 = sta.size()-1;
//	sta.clear();
//	sta.push_back(-1);
//	for (int i = n; i >=1; i--) {
//		if (a[i] > sta.back())sta.push_back(a[i]);
//	}
//	int t2 = sta.size()-1;
//	dp1[n + 1][0] = 1;
//	for (int i = n; i >=1; i--) {
//		for (int j = 0; j < sta.size() - 1; j++) {
//			if (a[i] == sta[j + 1]) {
//				dp1[i][j + 1] = (dp1[i][j+1] + dp1[i + 1][j])%mod;
//			}
//			else if (a[i] <= sta[j]) {
//				dp1[i][j] = (dp1[i][j] + dp1[i + 1][j])%mod;
//			}
//		}
//		for (int j = 0; j < sta.size(); j++) {
//			dp1[i][j] = (dp1[i][j] + dp1[i + 1][j])%mod;
//		}
//	}
//	vector<int>mxpos;
//	for (int i = 1; i <= n; i++) {
//		if (a[i] == mx) {
//			mxpos.push_back(i);
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i < mxpos.size(); i++) {
//		for (int j = i; j < mxpos.size(); j++) {
//			ans = (ans + dp[mxpos[i] - 1][t1 - 1] * dp1[mxpos[j] + 1][t2 - 1] %mod* qpow(2, max(0ll,mxpos[j]-mxpos[i]-1))%mod)%mod;
//		}
//	}
//	cout << ans << '\n';
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
//#define int long long
//const int N = 3e5 + 5;
//const int mod = 998244353;
//struct SegTree {
//	vector<int> sum;
//	vector<int> lzt;
//	SegTree(int n) {
//		sum.resize((n << 2) + 5);
//		lzt.resize((n << 2) + 5);
//	}
//	void up(int i) {
//		sum[i] = (sum[i << 1] + sum[i << 1 | 1]) % mod;
//	}
//	void lazy(int i, int v) {
//		sum[i] = sum[i] * v % mod;
//		lzt[i] = lzt[i] * v % mod;
//	}
//	void down(int i) {
//		if (lzt[i] != 1) {
//			lazy(i << 1, lzt[i]);
//			lazy(i << 1 | 1, lzt[i]);
//			lzt[i] = 1;
//		}
//	}
//	void mul(int jl, int jr, int v, int l, int r, int i) {
//		if (jl <= l && jr >= r) {
//			lazy(i, v);
//			return;
//		}
//		int mid = l + r >> 1;
//		down(i);
//		if (jl <= mid) {
//			mul(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			mul(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//	void add(int x, int v, int l, int r, int i) {
//		if (l == r) {
//			sum[i] = (sum[i] + v) % mod;
//			return;
//		}
//		int mid = l + r >> 1;
//		down(i);
//		if (x <= mid) {
//			add(x, v, l, mid, i << 1);
//		}
//		else {
//			add(x, v, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//	int query(int jl, int jr, int l, int r, int i) {
//		if (jl <= l && jr >= r) {
//			return sum[i];
//		}
//		int mid = l + r >> 1;
//		down(i);
//		int ans = 0;
//		if (jl <= mid) {
//			ans = (ans + query(jl, jr, l, mid, i << 1)) % mod;
//		}
//		if (jr > mid) {
//			ans = (ans + query(jl, jr, mid + 1, r, i << 1 | 1)) % mod;
//		}
//		return ans;
//	}
//	int query(int x, int l, int r, int i) {
//		if (l == r) {
//			return sum[i];
//		}
//		int mid = l + r >> 1;
//		down(i);
//		if (x <= mid) {
//			return query(x, l, mid, i << 1);
//		}
//		else {
//			return query(x, mid + 1, r, i << 1 | 1);
//		}
//	}
//	void build(int l, int r, int i) {
//		if (l == r) {
//			sum[i] = 0;
//			lzt[i] = 1;
//			return;
//		}
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		lzt[i] = 1;
//		up(i);
//	}
//	void debug(int l, int r, int i) {
//		if (l == r) {
//			cout << '(' << l-1 << ',' << sum[i] << ") ";
//			return;
//		}
//		down(i);
//		int mid = l + r >> 1;
//		debug(l, mid, i << 1);
//		debug(mid+1, r, i << 1|1);
//	}
//};
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
//SegTree dp(N);
//SegTree dp1(N);
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	vector<int>vsort;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		vsort.push_back(a[i]);
//	}
//	sort(vsort.begin(), vsort.end());
//	vsort.erase(unique(vsort.begin(), vsort.end()), vsort.end());
//	int mx = -1;
//	for (int i = 1; i <= n; i++) {
//		a[i] = lower_bound(vsort.begin(), vsort.end(), a[i]) - vsort.begin() + 1;
//		mx = max(mx, a[i]);
//	}
//	vector<int>sta;
//	sta.push_back(-1);
//	for (int i = 1; i <= n; i++) {
//		if (a[i] > sta.back())sta.emplace_back(a[i]);
//	}
//
//	vector<int>ll(n + 2,0);
//	vector<int>rr(n + 2,0);
//	int nn = sta.size();
//	dp.build(1, nn, 1);//1对应匹配上0个
//	dp.add(1, 1, 1, nn, 1);
//	//dp.debug(1,nn,1);
//	//cout << "----\n";
//	for (int i = 1; i <= n; i++) {
//		int x = lower_bound(sta.begin(), sta.end(), a[i]) - sta.begin();
//		if(x+1<=nn)dp.mul(x + 1, nn,2, 1, nn, 1);		
//		if (x + 1 <= nn&&a[i]==sta[x]) {
//			dp.add(x + 1, dp.query(x, 1, nn, 1), 1, nn, 1);
//		}
//		if (i + 1 <= n && a[i + 1] == mx) {
//			ll[i] = dp.query(nn - 1, 1, nn, 1);
//		}
//
//		//cout << i << " " << a[i] << " " << x << "&&&\n";
//		//dp.debug(1,nn,1);
//		//cout << "^^\n";
//	}
//	sta.clear();
//	sta.push_back(-1);
//	for (int i = n; i >= 1; i--) {
//		if (a[i] > sta.back())sta.emplace_back(a[i]);
//	}
//	int nn1 = sta.size();
//	dp1.build(1, nn1, 1);
//	dp1.add(1, 1, 1, nn1, 1);
//	for (int i = n; i >= 1; i--) {
//		int x = lower_bound(sta.begin(), sta.end(), a[i]) - sta.begin();
//		if (x + 1 <= nn1)dp1.mul(x + 1, nn1,2, 1, nn1, 1);
//		if (x + 1 <= nn1&&a[i]==sta[x]) {
//			dp1.add(x + 1, dp1.query(x, 1, nn1, 1), 1, nn1, 1);
//		}
//		if (i - 1 >= 1 && a[i - 1] == mx) {
//			rr[i] = dp1.query(nn1 - 1, 1, nn1, 1);
//		}
//		//cout << i <<" "<<a[i]<<" "<<x<<"&&&\n";
//		//dp1.debug(1, nn, 1);
//		//cout << "^^\n";
//	}
//	ll[0] = 1;
//	rr[n + 1] = 1;
//	int ans = 0;
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		if (a[i] == mx) {
//			//cout << rr[i + 1]<<"rr\n";
//			ans = (ans + rr[i + 1] * (sum + ll[i - 1]) % mod) % mod;
//		}
//		sum =sum* 2%mod;
//		if (a[i] == mx) {
//			//cout << ll[i - 1] << "ll\n";
//			sum = (sum + ll[i - 1]) % mod;
//		}
//	}
//	cout << ans << '\n';
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