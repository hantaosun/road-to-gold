//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int l, r;
//	cin >> l >> r;
//	if (r == l && r == 1) {
//		cout << 1 << endl;
//		return;
//	}
//	cout << r - l << endl;
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
//	int n, lll, rrr;
//	cin >> n >> lll >> rrr;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++){
//		cin >> a[i];
//	}
//	vector<int>mid;
//	vector<int>ll;
//	vector<int>rr;
//	int sum = 0;
//	for (int i = lll; i <= rrr; i++) {
//		mid.push_back(a[i]);
//		sum += a[i];
//	}
//	for (int i = 1; i < lll; i++) {
//		ll.push_back(a[i]);
//	}
//	for (int i = rrr + 1; i <= n; i++) {
//		rr.push_back(a[i]);
//	}
//	sort(mid.begin(), mid.end());
//	sort(ll.begin(), ll.end());
//	sort(rr.begin(), rr.end());
//	int r = mid.size() - 1;
//	int l = 0;
//	int tmp = sum;
//	int ans = LLONG_MAX;
//	while (r >= 0&&l<ll.size()) {
//		if (mid[r] >ll[l]) {
//			tmp +=ll[l]-mid[r];
//			r--;
//			l++;
//		}
//		else {
//			break;
//		}
//	}
//	ans = min(ans, tmp);
//	tmp = sum;
//	r = mid.size() - 1;
//	l = 0;
//	while (r >= 0 && l < rr.size()) {
//		if (mid[r] > rr[l]) {
//			tmp += rr[l] - mid[r];
//			l++;
//			r--;
//		}
//		else {
//			break;
//		}
//	}
//	ans = min(ans, tmp);
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
//#define int long long
//using namespace std;
//vector<bool>vis;
//vector<set<int>>g;
//int mxs, wh;
//void dfs(int u) {
//	if (vis[u])return;
//	vis[u] = true;
//	if ((int)(g[u].size()) > mxs) {
//		mxs = g[u].size();
//		wh = u;
//	}
//	for (auto v : g[u]) {
//		dfs(v);
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	vis.assign(n + 1, 0);
//	g.clear();
//	g.assign(n+1,{});
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		g[u].insert(v);
//		g[v].insert(u);
//	}
//	int mxsiz=-1, who=0;
//	for (int i = 1; i <= n; i++) {
//		//cout << g[i].size() << "***\n";
//		//cout << mxsiz << endl;
//		if ((int)(g[i].size()) > mxsiz) {
//			//cout << "xixi\n";
//			mxsiz = g[i].size();
//			who = i;
//		}
//	}
//	for (auto v : g[who]) {
//		g[v].erase(who);
//	}
//	g[who].clear();
//	mxs = -1;
//	for (int i = 1; i <= n; i++) {
//		if (!vis[i] && i != who)dfs(i);
//	}
//	int who1 = wh;
//	for (auto v : g[wh]) {
//		g[v].erase(wh);
//	}
//	g[wh].clear();
//	vis.assign(n + 1, false);
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		if (!vis[i]&&i!=who&&i!=who1) {
//			dfs(i);
//			ans++;
//		}
//	}
//	//cout << who << " " << who1 << "^^^\n";
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
//	vector<pair<int, int>>edg;
//	vector<set<int>>g(n + 1);
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		g[u].insert(v);
//		g[v].insert(u);
//		edg.push_back({ u, v });
//	}
//	int ans = INT_MIN;
//	for (auto v : edg) {
//		ans = max((int)g[v.first].size() + (int)g[v.second].size() - 2,ans);
//	}
//	int mx1 = 0, mx2 = 0;
//	for (int i = 1; i <= n; i++) {
//		int siz = g[i].size();
//		if (siz > mx1) {
//			mx2 = mx1;
//			mx1 = siz;
//		}
//		else if (siz > mx2) {
//			mx2 = siz;
//		}
//	}
//	vector<int>b1;
//	vector<int>b2;
//	for (int i = 1; i <= n; i++) {
//		if (g[i].size() == mx1) {
//			b1.push_back(i);
//		}
//		else if (g[i].size() == mx2) {
//			b2.push_back(i);
//		}
//	}
//	if (b1.size() > 2||b1.size()==2&&!g[b1[0]].count(b1[1])) {
//		ans = max(ans, mx1 * 2-1);
//	}
//	else {
//		for (auto v : b1) {
//			for (auto u : b2) {
//				if (!g[v].count(u)) {
//					ans = max(mx1 + mx2-1, ans);
//				}
//			}
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
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(n + 1);
//	vector<int>b(m + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= m; i++) {
//		cin >> b[i];
//	}	
//	sort(a.begin() + 1, a.end());
//	sort(b.begin() + 1, b.end());
//	vector<int>pa(n + 1);
//	vector<int>pb(m + 1);
//	for (int i = 1; i < n - i + 1; i++) {
//		pa[i] = pa[i - 1] + a[n - i + 1] - a[i];
//	}
//	for (int i = 1; i < m - i + 1; i++) {
//		pb[i] = pb[i - 1] + b[m - i + 1] - b[i];
//	}
//	vector<int>ans;
//	{
//		for (int k = 1;; k++) {
//			auto f = [&](int x) {
//				return pa[x] + pb[k - x];
//				};
//			int L = max(0ll, 2 * k - m), R = min(k, n - k);
//			if (L > R)break;
//
//			while (R - L > 3) {
//				int ml = (L * 2 + R) / 3,mr=(L+R*2)/3;
//				if (f(ml) > f(mr))R = mr;
//				else {
//					L = ml;
//				}
//			}
//			int tans = 0;
//			for (int i = L; i <= R; i++) {
//				tans = max(tans, f(i));
//			}
//			ans.push_back(tans);
//		}
//	}
//	cout << ans.size() << endl;
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i] << " ";
//	}cout << "\n";
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
//	map<int, int>mp;
//	for (int i = 1, u; i <= n; i++) {
//		cin >> u;
//		mp[u]++;
//	}
//	int mxc = 0;
//	for (auto v : mp) {
//		mxc = max(mxc, v.second);
//	}
//	vector<int>dp(n + 1, 0);
//	dp[0] = 1;
//	for (auto v : mp) {
//		for (int i = n; i >= v.second; i--) {
//			dp[i] = (dp[i] + dp[i - v.second] * v.second % mod) % mod;
//		}
//	}
//	int ans = 0;
//	for (int i = mxc; i <= n; i++) {
//		ans = (ans + dp[i]) % mod;
//	}
//	cout<<ans<<"\n";
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}