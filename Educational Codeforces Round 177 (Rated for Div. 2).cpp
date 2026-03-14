//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	cout << n * 2<<"\n";
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
//	int n, k, x;
//	cin >> n >> k >> x;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int sum = 0,p=0;
//	for (int i = n; i >= 1; i--) {
//		sum += a[i];
//	}
//	int tsum = 0;
//	for (int i = n; i >= 1; i--) {
//		tsum += a[i];
//		if (tsum < x % sum) {
//			p++;
//		}
//	}
//	if (sum == 0&&x==0) {
//		cout << n*k << "\n";
//		return;
//	}
//	if (x> k*sum) {
//		cout << 0 << "\n";
//		return;
//	}
//	int zero = 0;
//	for (int i = 1; i <= n; i++) {
//		if (a[i] == 0)zero++;
//		else break;
//	}
//	if (x % sum == 0) {
//		cout << n * k - (x / sum) * n + zero+1<<"\n";
//		return;
//	}
//	cout << n * k - ((x / sum) * n + p) << "\n";
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
//	vector<int>d(n + 1);
//	vector<int>pos(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//		pos[p[i]] = i;
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> d[i];
//	}
//	int ans = 0;
//	vector<int>op;
//	set<int>st;
//	set<int>nst;
//	for (int i = 1; i <= n; i++) {
//		int cur = d[i];//cur表示当前要去的位置
//		while (!nst.count(cur)) {
//			//cout << cur <<" "<<p[cur]<< "**\n";
//			nst.insert(cur);
//			cur = pos[cur];
//			//cout << cur << "&&\n";
//		}
//		for (auto v : nst) {
//			pos[v] = v;
//			p[v] = v;
//			st.insert(v);
//		}
//		nst.clear();
//		cout << st.size() << " ";
//	}
//	cout << "\n";
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}

//5
//2 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 998244353;
//vector<int>c;
//const int N = 5e5 + 5;
//int fac[N];
//int finv[N];
//int qpow(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a % mod;
//		}
//		b >>= 1;
//		a = a * a % mod;
//	}
//	return ans;
//}
//int C(int n, int m) {
//	return fac[n] * finv[m]%mod * finv[n - m]%mod;
//}
//void solve() {
//	c.resize(27);
//	int sum = 0;
//	for (int i = 1; i <= 26; i++) {
//		cin >> c[i];
//		sum += c[i];
//	}
//	int od = (sum + 1) / 2;
//	vector<vector<int>>dp(27, vector<int>(od+1,0));//前i个字符用完奇数x个的方案数
//	dp[0][0] = 1;
//	int psum = 0;
//	for (int i = 1; i <= 26; i++) {
//		if (c[i] == 0) {
//			for (int j = 0; j <= od; j++) {
//				dp[i][j] = dp[i - 1][j];
//			}
//		}
//		else {
//			for (int j = 0; j <= od; j++) {
//				int ev = sum - od - (psum - j);
//				if (ev >= c[i]) {
//					dp[i][j] = (dp[i][j] + dp[i - 1][j] * C(ev, c[i]) % mod) % mod;
//				}
//				if (od - j >= c[i]) {
//					dp[i][j + c[i]] = (dp[i][j + c[i]] + dp[i - 1][j] * C(od - j, c[i]) % mod) % mod;
//				}
//			}
//		}
//		psum += c[i];
//		//for (int j = 0; j <= od; j++) {
//		//	cout << dp[i][j] << " ";
//		//}cout << "*\n";
//	}
//	int ans = 0;
//	for (int i = 0; i <= od; i++) {
//		ans = (ans + dp[26][i]) % mod;
//	}
//	cout << ans << "\n";
//
//}
//void prepare() {
//	fac[0] = 1;
//	for (int i = 1; i < N; i++) {
//		fac[i] = i * fac[i - 1]%mod;
//	}
//	finv[N - 1] = qpow(fac[N-1], mod - 2);
//	for (int i = N - 2; i >= 1; i--) {
//		finv[i] = finv[i + 1] * (i + 1) % mod;
//	}
//	finv[0] = 1;
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
//int znum[33];
//int l, r, k;
//string ll, rr;
//string s;
//int dp[33][150][2][2][2];
//int dfs(int cur, int sum, int fix, int free, int got4) {
//	//cout << k << "haha\n";
//	if (dp[cur][sum][fix][free][got4] != -1) {
//		return dp[cur][sum][fix][free][got4];
//	}
//	int ans = 0;
//	if (cur == s.size()) {
//		//cout << cur << " " << sum << " " << fix << " " << free << "**\n";
//		if (sum == k && fix)ans++;
//	}
//	else if (got4) {
//		ans+=dfs(cur + 1, sum, fix, free, got4);
//	}
//	else {
//		int digi = s[cur] - '0';
//		if (!fix) {
//			if (digi !=0)ans += dfs(cur + 1, sum, 0, 1, got4);
//			else ans += dfs(cur + 1, sum, 0, free, got4);
//		}
//		//cout << digi << "**\n";
//		if (free) {
//			for (int i = 1 - fix; sum + i <= k && i <= 4; i++) {
//				ans += dfs(cur + 1, sum + i, 1, 1, i == 4);
//			}
//		}
//		else {
//			for (int i = 1 - fix; sum + i <= k && i < digi && i <= 4; i++) {
//				ans += dfs(cur + 1, sum + i, 1, 1, i == 4);
//			}
//			if (sum + digi <= k && digi <= 4) {
//				ans += dfs(cur + 1, sum + digi, 1, 0, digi == 4);
//			}
//		}
//	}
//	return dp[cur][sum][fix][free][got4] = ans;
//}
//void solve() {
//	cin >> l >> r >> k;
//	ll = "";
//	rr = "";
//	l--;
//	bool gotn0 = 0;
//	for (int i = 32; i >= 1; i--) {
//		int cur = 0;
//		while (l >= znum[i]) {
//			cur++;
//			l -= znum[i];
//		}
//		if (cur != 0)gotn0 = true;
//		if (gotn0) {
//			ll += char(cur + '0');
//		}
//	}
//	gotn0 = 0;
//	for (int i = 32; i >= 1; i--) {
//		int cur = 0;
//		while (r >= znum[i]) {
//			cur++;
//			r -= znum[i];
//		}
//		if (cur != 0)gotn0 = true;
//		if (gotn0) {
//			rr += char(cur + '0');
//		}
//	}
//	int fans = 0;
//	s = rr;
//	memset(dp, -1, sizeof(dp));
//	fans += dfs(0, 0, 0, 0, 0);
//	s = ll;
//	memset(dp, -1, sizeof(dp));
//	fans -= dfs(0, 0, 0, 0, 0);
//	cout << fans << "\n";
//}
//void prepare() {
//	znum[1] = 1;
//	for (int i = 2; i <= 32; i++) {
//		znum[i] = (znum[i - 1] << 2) + 1;
//	}
//}
//signed main() {
//	prepare();
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}