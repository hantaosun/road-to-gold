//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n, l, r;
//	cin >> n >> l >> r;
//	string s;
//	cin >> s;
//	for (int i = l - 1; i < r; i++) {
//		if (s[i] != 'o') { cout << "No\n"; return 0; }
//	}
//	cout << "Yes\n";
//}


//#include<bits/stdc++.h>
//using namespace std;
//int n, k, x;
//vector<string>s;
//vector<string>a;
//void dfs(int i, string cur) {
//	if (i == k){
//		a.emplace_back(cur);
//		return;
//	}
//	for (int j = 1; j <= n; j++) {
//		dfs(i + 1, cur + s[j]);
//	}
//}
//int main() {
//	cin >> n >> k >> x;
//	s.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> s[i];
//	}
//	dfs(0, "");
//	sort(a.begin(), a.end());
//	cout << a[x - 1] << '\n';
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	multiset<int>a;
//	vector<int>b(n + 1);
//	int ans = 0;
//	for (int i = 1,v; i <= n; i++) {
//		cin >> v;
//		ans += v;
//		a.insert(v);
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//		ans += b[i];
//	}
//	sort(b.begin()+1, b.end());
//	for (int i = n; i >= 1; i--) {
//		auto it = a.lower_bound(m - b[i]);
//		if (it !=a.end()){
//			ans -= m;
//			a.erase(it);
//		}
//	}
//	cout << ans << '\n';
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//6666
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 505;
//int g[N][N];
//int n, m;
//void relax(int x,int y) {
//	for (int i = 1; i <= n + 1; i++) {
//		for (int j = 1; j <= n + 1; j++){
//			if (g[i][x] != LLONG_MAX && g[y][j] != LLONG_MAX&&g[x][y]+g[i][x]+g[y][j]<g[i][j]) {
//				g[i][j] = g[i][x] + g[y][j]+g[x][y];
//			}
//		}
//	}
//}
//int cal() {
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			ans += g[i][j] == LLONG_MAX ? 0 : g[i][j];
//		}
//	}
//	return ans;
//}
//signed main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n+1; i++) {
//		for (int j = 1; j <= n+1; j++) {
//			g[i][j] = i==j?0:LLONG_MAX;
//		}
//	}
//	for (int i = 1,a,b,c; i <= m; i++) {
//		cin >> a >> b >> c;
//		if(c<g[a][b])g[a][b] = g[b][a]=c;
//	}
//	int k, T;
//	cin >> k >> T;
//	for (int i = 0,v; i < k; i++) {
//		cin >> v;
//		g[v][n + 1] = 0;
//		g[n + 1][v] = T;
//	}
//	for (int brg = 1; brg <= n+1; brg++) {
//		for (int i = 1; i <= n+1; i++) {
//			for (int j = 1; j <= n+1; j++) {
//				if (g[i][brg] != LLONG_MAX && g[brg][j] != LLONG_MAX && g[i][brg] + g[brg][j] < g[i][j]) {
//					g[i][j] = g[i][brg] + g[brg][j];
//				}
//			}
//		}
//	}
//	int q;
//	cin >> q;
//	for (int to = 1,o,x,y,t; to <= q; to++) {
//		cin >> o;
//		if (o == 1) {
//			cin >> x >> y>>t;
//			if (g[x][y] > t) {
//				g[x][y] = g[y][x] = t;
//				relax(x,y);
//				relax(y, x);
//			}
//		}
//		else if (o == 2) {
//			cin >> x;
//			g[x][n + 1] = 0;
//			g[n + 1][x] = T;
//			y = n + 1;
//			relax(x,y);
//			relax(y,x);
//		}
//		else {
//			cout << cal() << '\n';
//		}
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2e5 + 5;
//const int K = 11;
//int dp[N][K][3];//0无链接到根节点,1有一条未闭合链,2有一条闭合链
//int tmp[K][3];
//int f[N][10];
//vector<vector<int>>g;
//vector<int>a;
//int n, k;
//void dfs(int u, int fa) {
//	for (int i = 0; i <= k; i++) {
//		dp[u][i][0] = dp[u][i][1] = dp[u][i][2] = LLONG_MIN;
//	}
//	dp[u][0][0] = 0;
//	dp[u][1][1] = a[u];
//	for (int v : g[u]) {
//		if (v != fa) {
//			dfs(v, u);
//		}
//	}
//
//	for (int i = 0; i <= k; i++) {
//		f[u][i] = max({ dp[u][i][0],dp[u][i][1],dp[u][i][2] });
//	}
//
//	for (int v : g[u]) {
//		if (v == fa)continue;
//		//for (int i = 0; i <= k; i++) {
//		//	tmp[i][0] = dp[u][i][0];
//		//	tmp[i][1] = dp[u][i][1];
//		//	tmp[i][2] = dp[u][i][2];
//		//}
//		for (int i = 0; i <= k; i++) {
//			tmp[i][0] = tmp[i][1] = tmp[i][2] = LLONG_MIN;
//		}
//		for (int i = 0; i <= k; i++) {
//			for (int j = 0; j <= k; j++) {
//				tmp[i + j][0] = max(tmp[i+j][0],dp[u][i][0] + f[v][j]);
//				tmp[i + j][1] = max({ tmp[i + j][1],dp[u][i][1] + f[v][j]});
//				tmp[i + j][2] = max(tmp[i + j][2], dp[u][i][2] + f[v][j]);
//				if (i + j <= k)tmp[i + j][1] = max(tmp[i + j][1], dp[u][i][0] + dp[v][j][1] + a[u]);
//				if(i!=0&&j!=0&&i+j-1<=k)tmp[i + j - 1][2] = max({ tmp[i + j - 1][2], dp[u][i][1] + dp[v][j][1] });
//			}
//		}
//		for (int i = 0; i <= k; i++) {
//			dp[u][i][0] = tmp[i][0];
//			dp[u][i][1] = tmp[i][1];
//			dp[u][i][2] = tmp[i][2];
//		}
//		for (int i = 0; i <= k; i++) {
//			f[u][i] = max({ dp[u][i][0],dp[u][i][1],dp[u][i][2] });
//		}
//	}
//}
//signed main() {	
//	cin >> n >> k;
//	g.assign(n + 1,{});
//	a.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		g[u].emplace_back(v);
//		g[v].emplace_back(u);
//	}
//	dfs(1, 0);
//	int ans = 0;
//	for (int i = 0; i <= k; i++) {
//		ans = max({ ans,dp[1][i][0],dp[1][i][1],dp[1][i][2] });
//	}
//	cout << ans << '\n';
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2e5 + 5;
//const int K = 11;
//int dp[N][K][3];//0无链接到根节点,1有一条未闭合链,2有一条闭合链
//int tmp[K][3];
//vector<vector<int>>g;
//vector<int>a;
//int n, k;
//void dfs(int u, int fa) {
//	for (int i = 0; i <= k; i++) {
//		dp[u][i][0] = dp[u][i][1] = dp[u][i][2] = LLONG_MIN;
//	}
//	for (int v : g[u]) {
//		if (v != fa) {
//			dfs(v, u);
//		}
//	}
//	dp[u][0][0] = 0;
//	dp[u][1][1] = a[u];
//	for (int v : g[u]) {
//		if (v == fa)continue;
//		for (int i = 0; i <= k; i++) {
//			tmp[i][0] = tmp[i][1] = tmp[i][2] = LLONG_MIN;
//		}
//		for (int i = 0; i <= k; i++) {
//			int mx = max({ dp[v][i][0],dp[v][i][1],dp[v][i][2] });
//			for (int j = 0; j <= k - i + 1; j++) {
//				tmp[i + j][0] = max(tmp[i + j][0], dp[u][j][0] + mx);
//				tmp[i + j][1] = max({ tmp[i + j][1],dp[u][j][1] + mx });
//				tmp[i + j][2] = max(tmp[i + j][2], dp[u][j][2] + mx);
//				if (i + j <= k)tmp[i + j][1] = max(tmp[i + j][1], dp[u][j][0] + dp[v][i][1] + a[u]);
//				if (i != 0 && j != 0 && i + j - 1 <= k)tmp[i + j - 1][2] = max({ tmp[i + j - 1][2], dp[u][j][1] + dp[v][i][1] });
//			}
//		}
//		for (int i = 0; i <= k; i++) {
//			dp[u][i][0] = tmp[i][0];
//			dp[u][i][1] = tmp[i][1];
//			dp[u][i][2] = tmp[i][2];
//		}
//	}
//}
//signed main() {
//	cin >> n >> k;
//	g.assign(n + 1, {});
//	a.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		g[u].emplace_back(v);
//		g[v].emplace_back(u);
//	}
//	dfs(1, 0);
//	int ans = 0;
//	for (int i = 0; i <= k; i++) {
//		ans = max({ ans,dp[1][i][0],dp[1][i][1],dp[1][i][2] });
//	}
//	cout << ans << '\n';
//}
