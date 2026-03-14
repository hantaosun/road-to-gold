//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	int y, r;
//	cin >> y >> r;
//	cout << min(n, r + y / 2)<<endl;
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
//	map<int, int>mp;
//	for (int i = 1,u; i <= 2*n; i++) {
//		cin >> u;
//		mp[u]++;
//	}
//	int ans = 0;
//	vector<int>a;
//	int ev = 0;
//	for (auto v : mp) {
//		a.push_back(v.second);
//		if (!(v.second & 1)) {
//			ev++;
//			ans += 2;
//		}
//		else {
//			ans += 1;
//		}
//	}
//	if (ev == a.size() && (n & 1) != (ev & 1))ans -= 2;
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
//	int n,k;
//	cin >> n>>k;
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	vector<int>dpl(n + 2,0);
//	vector<int>dpr(n + 2,0);
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		sum = max(a[i], a[i] + sum);
//		dpl[i] = sum;
//	}
//	sum = 0;
//	for (int i = n; i >= 1; i--) {
//		sum = max(a[i], a[i] + sum);
//		dpr[i] = sum;
//	}
//	int ans = LLONG_MIN;
//	if (!(k & 1)) {
//		for (int i = 1; i <= n; i++) {
//			ans = max(ans, dpl[i]);
//		}
//		cout << ans << endl;
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		ans = max(ans, a[i] + b[i] + max(0ll, dpl[i - 1]) + max(0ll, dpr[i + 1]));
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
//#define pii pair<int,int>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	string s, t;
//	cin >> s >> t;
//	s = " " + s;
//	t = " " + t;
//	int sg2 = 0;
//	int sl = 0,tl=0,bt=-1,bs=-1;
//	for (int i = 1; i <= n-1; i++) {
//		if (s[i] == s[i + 1]) {
//			sl = i;
//		}
//		if (t[i] == t[i + 1]) {
//			tl = i;
//		}
//	}
//	vector<pii>opt;
//	vector<pii>ops;
//	if (tl == 0) {
//		if (n & 1) {
//			opt.push_back({ 1,n-2 });
//			for (int i = 1; i <= n - 2; i++) {
//				if (t[i] == '1')t[i] = '0';
//				else t[i] = '1';
//			}
//			tl = n - 2;
//		}
//		else {
//			opt.push_back({ 1,n - 1 });
//			for (int i = 1; i <= n - 1; i++) {
//				if (t[i] == '1')t[i] = '0';
//				else t[i] = '1';
//			}
//			tl = n - 1;
//		}
//	}
//	if (sl == 0) {
//		if (n & 1) {
//			ops.push_back({ 1,n - 2 });
//			for (int i = 1; i <= n - 2; i++) {
//				if (s[i] == '1')s[i] = '0';
//				else s[i] = '1';
//			}
//			sl = n - 2;
//		}
//		else {
//			ops.push_back({ 1,n - 1 });
//			for (int i = 1; i <= n - 1; i++) {
//				if (s[i] == '1')s[i] = '0';
//				else s[i] = '1';
//			}
//			sl = n - 1;
//		}
//	}
//	int sr = sl + 1,tr=tl+1;
//	bs = s[sl] - '0', bt = t[tl] - '0';
//	while (sr != n) {
//		if (s[sr + 1]-'0' == bs) {
//			sr++;
//		}
//		else {
//			bs ^= 1;
//			ops.push_back({ sl,sr });
//			sr++;
//		}
//	}
//	while (sl != 1) {
//		if (s[sl - 1] - '0' == bs) {
//			sl--;
//		}
//		else {
//			bs ^= 1;
//			ops.push_back({ sl,sr });
//			sl--;
//		}
//	}
//	while (tr != n) {
//		if (t[tr + 1]-'0' == bt) {
//			tr++;
//		}
//		else {
//			bt ^= 1;
//			opt.push_back({ tl,tr });
//			tr++;
//		}
//	}
//	while (tl != 1) {
//		if (t[tl - 1] - '0' == bt) {
//			tl--;
//		}
//		else {
//			bt ^= 1;
//			opt.push_back({ tl,tr });
//			tl--;
//		}
//	}
//	if (bs != bt) {
//		ops.push_back({ 1,n });
//	}
//	cout << ops.size() + opt.size()<<endl;
//	for (int i = 0; i < ops.size(); i++) {
//		cout << ops[i].first << " " << ops[i].second << endl;
//	}
//	for (int i = opt.size() - 1; i >= 0; i--) {
//		cout << opt[i].first << " " << opt[i].second << endl;
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
//int dx[] = {1,0,-1,0};
//int dy[] = {0,1,0,-1};	
//int n, m;
//void bfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& hole,int holeid) {
//	if (i > n || i <= 0 || j >= m || j <= 0 || !hole[i][j] || vis[i][j])return;
//	vis[i][j] = 1;
//	hole[i][j] = holeid;
//	for (int d = 0; d < 4; d++) {
//		bfs(i + dx[d], j + dy[d],vis,hole,holeid);
//	}
//}
//void solve() {
//	cin >> n >> m;
//	vector<vector<int>>g(n + 2, vector<int>(m + 2,LLONG_MAX));
//	vector<vector<int>>hole(n + 2, vector<int>(m + 2,true));
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> g[i][j];
//		}
//	}
//	int cnt = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			hole[i][j] = 1;
//			for (int d = 0; d < 4; d++) {
//				int ni = i + dx[d], nj = j + dy[j];
//				if (g[i][j] > g[ni][nj]) {
//					hole[i][j] = 0;
//				}
//			}
//		}
//	}
//	int holeid = 1;
//	vector<vector<bool>>vis(n + 2, vector<bool>(m + 2, true));
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			if (hole[i][j] && !vis[i][j]) {
//				bfs(i, j,vis,hole,holeid);
//				cnt++;
//				holeid++;
//			}
//		}
//	}
//	int q;
//	cin >> q;
//	cout << cnt << endl;
//	for (int i = 1,r,c,x; i <= q; i++) {
//		cin >> r >> c >> x;
//		g[r][c] -= x;
//		bool flag = 1;
//		for (int d = 0; d < 4; d++) {
//			int nr = r + dx[d];
//			int nc = c + dy[d];
//			if (g[r][c] >= g[nr][nc]) {
//				flag = 0;
//				break;
//			}
//		}
//		if (flag) {
//			cnt += 1;
//			hole[r][c] = 1;
//		}
//		else {
//			set<int>tmp;
//			for (int d = 0; d < 4; d++) {
//				int nr = r + dx[d];
//				int nc = c + dy[d];
//				if (hole[nr][nc]) {
//					tmp.insert(hole[nr][nc]);
//				}
//			}
//			cnt -= tmp.size();
//			bfs(r, c, vis, hole, holeid);
//			holeid++;
//		}
//		cout << cnt << endl;
//	}
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}