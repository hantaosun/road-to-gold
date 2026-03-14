//#include<bits/stdc++.h>
//const int inf = 20;
//const double sml = 1e-6;
//using namespace std;
//int bits[20][20];//由i号和j号小猪确定的抛物线能消灭哪些小猪
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<double>x(n);
//	vector<double>y(n);
//	for (int i = 0; i < n; i++) {
//		cin >> x[i] >> y[i];
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = i; j < n; j++) {
//			if (j == i) {
//				bits[i][j] = 1 << i;
//				continue;
//			}
//			double f = x[i] * x[j] * (x[i] - x[j]);
//			double a = x[j] * y[i] - x[i] * y[j];
//			double b = x[i] * x[i] * y[j] - x[j] * x[j] * y[i];
//			bits[i][j] = 0;
//			if (a * f < 0) {
//				for (int k = 0; k < n; k++) {
//					if (fabs(a * x[k] * x[k] + b * x[k] - f * y[k]) < sml)bits[i][j] |= 1 << k;//这是解二元二次方程，加减消原搞一搞就好了。  
//				}
//			}
//		}
//	}
//	//for (int i = 0; i < n; i++) {
//	//	for (int j = i; j < n; j++) {
//	//		cout << bitset<32>(bits[i][j]) << '\n';
//	//	}
//	//}
//	vector<int>dp((1 << n) + 1, 20);//完成当前消灭状态最少花几只鸟
//	dp[0] = 0;
//	for (int s = 0; s < 1 << n; s++) {
//		if (dp[s] == 20)continue;
//		for (int i = 0; i < n; i++) {
//			for (int j = i; j < n; j++) {
//				if ((bits[i][j] | s) != s) {
//					dp[bits[i][j] | s] = min(dp[bits[i][j] | s], 1 + dp[s]);
//				}
//			}
//		}
//	}
//	cout << dp[(1 << n) - 1] << '\n';
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
//int popcount(int x) {
//	int ans = 0;
//	while (x != 0) {
//		if (x & 1) {
//			ans++;
//		}
//		x >>= 1;
//	}
//	return ans;
//}
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>adj(n, vector<int>(n,LLONG_MAX));
//	vector<vector<int>>g(n, vector<int>(n, LLONG_MAX));
//	for (int i = 1,u,v,w; i <= m; i++) {
//		cin >> u >> v>>w;
//		u--;
//		v--;
//		adj[u][v] = min(adj[u][v], w);
//		adj[v][u] = min(adj[v][u], w);
//		g[u][v] = g[v][u] = 1;
//	}
//	//Floyd预处理两点间最短距离(视长度为1)
//	for (int i = 0; i < n; i++) {
//		g[i][i] = 0;
//		adj[i][i] = 0;
//	}
//	for (int brg = 0; brg < n; brg++) {
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				if (g[i][brg] != LLONG_MAX && g[brg][j] != LLONG_MAX&&g[i][brg]+g[brg][j]<g[i][j]) {
//					g[i][j] = g[i][brg] + g[brg][j];
//				}
//			}
//		}
//	}
//	/*for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << adj[i][j] << " ";
//		}cout << '\n';
//	}*/
//	int Ans = LLONG_MAX;
//	auto run = [&](int bg) {
//		vector<int>dp((1 << n) + 1,LLONG_MAX);
//		int fina = ((1 << n) - 1) ^ (1 << bg);
//		int subset = popcount(fina);
//		dp[1ll << bg] = 0;
//		for (int i = 0, s = 0; i < (1ll << subset); i++, s = (s - fina)&fina) {//从小到大枚举所有子集
//			//cout << bitset<32>(fina)<<'\n';
//			//cout << bitset<32>(s)<<'\n';
//			int cur = s | (1ll << bg);
//			//cout << bitset<32>(cur)<<'\n';
//			if (dp[cur] == LLONG_MAX) {
//				//cout << "haha\n";
//				continue;
//			}
//			//cout << "xixi\n";
//			for (int j = 0; j < n; j++) {
//				if ((cur >> j) & 1) {
//					for (int k = 0; k < n; k++) {
//						if (g[j][k] != LLONG_MAX && !((cur >> k) & 1)&&adj[j][k]!=LLONG_MAX) {
//							/*cout << bg<<" "<<j<<" "<<g[bg][j] << "****\n";
//							cout << bitset<32>(cur | (1 << k)) << '\n';
//							cout << adj[j][k] <<" "<<dp[cur | (1 << k)] << " " << dp[cur] + (g[bg][j] + 1) * adj[j][k]<< '\n';*/
//							dp[cur | (1ll << k)] = min(dp[cur | (1ll << k)], dp[cur] + (g[bg][j] + 1) * adj[j][k]);
//						}
//					}
//				}
//			}
//		}
//		return dp[(1ll << n) - 1];
//	};
//	for (int i = 0; i < n; i++) {
//		Ans = min(Ans, run(i));
//	}
//	cout << Ans << '\n';
//}


//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>g(n, vector<int>(n, INT_MAX));
//	for (int i = 0, u, v, w; i < m; i++) {
//		cin >> u >> v >> w;
//		--u, --v;
//		g[u][v] = min(g[u][v], w);
//		g[v][u] = min(g[v][u], w);
//	}
//	vector<int>dp;
//	vector<int>dep;
//	int ans = INT_MAX;
//	function<void(int)> dfs;
//	dfs = [&](int st) {
//		for (int i = 0; i < n; i++) {
//			if (!((1 << i) & st))continue;
//			for (int j = 0; j < n; j++) {
//				if (g[i][j] == INT_MAX || i == j)continue;
//				if (dp[st | (1 << j)] > dp[st] + g[i][j] * dep[i]) {
//					int tmp = dep[j];
//					dep[j] = dep[i] + 1;
//					dp[st | (1 << j)] = dp[st] + g[i][j] * dep[i];
//					dfs(st | (1 << j));
//					dep[j] = tmp;
//				}
//			}
//		}
//		};
//	for (int i = 0; i < n; i++) {
//		dep.assign(n + 1, INT_MAX);
//		dp.assign((1 << n) + 1, INT_MAX);
//		dep[i] = 1;
//		dp[1 << i] = 0;
//		dfs(1 << i);
//		ans = min(ans, dp[(1 << n) - 1]);
//	}
//	cout << ans << '\n';
//}



//错误逻辑,外卖员可以先领订单但不送
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//signed main() {
//	int n, m,q;
//	cin >> n >> m>>q;
//	vector<vector<int>>g(n+1, vector<int>(n+1, LLONG_MAX));
//	for (int i = 1,u,v,w; i <= m; i++) {
//		cin >> u >> v >> w;
//		g[u][v] = w;
//	}
//	vector<array<int,4>>job;
//	for (int i = 1; i <= n; i++) {
//		g[i][i] = 0;
//	}
//	for (int brg = 1; brg <= n; brg++) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {  // 这里应该是j，不是r
//				if (g[i][brg] != LLONG_MAX && g[brg][j] != LLONG_MAX &&  // 这里应该是j
//					g[i][j] > g[i][brg] + g[brg][j]) {  // 这里应该是j
//					g[i][j] = g[i][brg] + g[brg][j];
//				}
//			}
//		}
//	}
//	for (int i = 1, s, t, l, r; i <= q; i++) {
//		cin >> s >> t >> l >> r;
//		job.push_back({s,t,l,r});
//	}
//	auto f = [&](auto self,int p, int state, int t)->int {
//		//cout << p << " " << bitset<10>(state) << " " << t << '\n';
//		int ans = 0;
//		for (int i = 0; i < q; i++) {
//			auto [s, e, l, r] = job[i];
//			//cout << g[s][e] << " " << g[p][s] << '\n';
//			//这单没送过且有机会送
//			if (!((state >> i) & 1) && g[p][s] != LLONG_MAX&&g[s][e]!=LLONG_MAX) {
//				int gets = max(l, t + g[p][s]);
//				if (gets + g[s][e] <= r) {
//					ans = max(ans, 1 + self(self, e, state | (1 << i),
//						gets + g[s][e]));
//				}
//			}
//		}
//		return ans;
//	};
//	cout << f(f,1,0,0) << '\n';
//}




//#include<bits/stdc++.h>
//#define i64 long long
//using namespace std;
//int mod;
//signed main() {
//	int n,k;
//	cin >> n >> mod;
//	cin >> k;
//	vector<bool>isdecode(k, false);
//	vector<string>decode(k);
//	vector<string>code(k);
//	string t;
//	for (int i = 0; i < k; i++) {
//		cin >> t;
//		code[i].assign(t.begin() + 3, t.end());
//	}
//	auto Decode = [&](auto self, int id)->string {
//		if (isdecode[id])return decode[id];
//		isdecode[id] = true;
//		string ans="";
//		for (int i = 0; i < code[id].size(); i++) {
//			if (isdigit(code[id][i])) {
//				ans += code[id][i];
//			}
//			else {
//				ans += self(self, code[id][i] - 'A');
//			}
//		}
//		decode[id] = ans;
//		return ans;
//	};
//	string s = Decode(Decode, 0);
//	i64 ans = count(s.begin(), s.end(), '0');
//	s = "0" + s;
//	vector<int>prev(n + 1);
//	vector<int>curr(n + 1);
//	for (int i = 1; i < s.size(); i++) {
//		int cur = s[i] - '0';
//		if (s[i] != '0') {
//			curr[cur % n] = (curr[cur % n] + 1ll) % mod;
//		}
//		for (int j = 0;j < n; j++) {
//			curr[(j * 10 + cur) % n] = (curr[(j * 10 + cur) % n]*1ll + prev[j]) % mod;
//		}
//		ans = (ans + curr[0])%mod;
//		prev = curr;
//		curr.assign(n+1,0);
//	}
//	cout << ans << '\n';
//}

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int INF = 0x3f3f3f3f;
//int eval[1 << 16];
//int val[105];
//int dp[2][55][1 << 16];
//signed main() {
//	int n, m, a, b;
//	cin >> n >> m >> a >> b;
//	for (int i = 0; i < n; i++)cin >> val[i];
//	for (int i = 0; i < b; i++) {
//		int x, y;
//		int tem = 0;
//		int t = 0;
//		cin >> x >> y;
//		while (x--) {
//			cin >> t;
//			t--;
//			tem = tem | (1 << t);
//		}
//		eval[tem] += y;
//	}
//	for (int i = (1 << a) - 1; i >= 0; i--) {
//		if (eval[i] != 0) {
//			int j = (1 << a) - 1 - i;
//			for (int s = j; s > 0; s = (s - 1) & j) {
//				eval[i | s] += eval[i];
//			}
//		}
//	}
//	for (int i = 0; i <= m; i++) {
//		for (int j = 0; j < (1 << a); j++) {
//			dp[0][i][j] = -INF;
//		}
//	}
//	for (int j = 0; j < (1 << a); j++) {//枚举前a位要或不要的状态
//		int tem = 0;
//		int cnt = 0;
//		for (int k = 0; k < a; k++) {
//			if (j & (1 << k)) {
//				tem += val[k];
//				cnt++;
//			}
//		}
//		dp[0][cnt][j] = max(dp[0][cnt][j], tem + eval[j]);
//	}
//	int f = 0;
//	for (int i = a; i < n; i++) {
//		for (int j = 0; j <= m; j++) {
//			for (int k = 0; k < (1 << a); k++) {
//				dp[f ^ 1][j][k] = -INF;
//			}
//		}
//		for (int j = 0; j <= m; j++) {
//			for (int k = 0; k < (1 << a); k++) {
//				if (dp[f][j][k] == -INF)continue;
//				int tem = (k >> 1) | (1 << (a - 1));
//				dp[f ^ 1][j][k >> 1] = max(dp[f ^ 1][j][k >> 1], dp[f][j][k] + eval[k >> 1]);
//				dp[f ^ 1][j + 1][tem] = max(dp[f ^ 1][j + 1][tem], dp[f][j][k] + eval[tem] + val[i]);
//			}
//		}
//		f = f ^ 1;
//	}
//	int ans = -INF;
//	for (int i = 0; i <= m; i++)
//	{
//		for (int j = 0; j < (1 << a); j++)
//		{
//			ans = max(ans, dp[f][i][j]);
//		}
//	}
//	cout << ans << '\n';
//	return 0;
//}