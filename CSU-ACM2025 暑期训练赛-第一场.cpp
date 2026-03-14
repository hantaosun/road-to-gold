//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 998244353;
//const int N = 5005;
//int fac[N];
//int finv[N];
//int n, m;
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
//	return fac[n] * finv[m]%mod * finv[n - m] % mod;
//}
//void prepare() {
//	finv[0] = fac[0] = 1;
//	for (int i = 1; i < N; i++) {
//		fac[i] = fac[i - 1] * i % mod;
//	}
//	finv[N - 1] = qpow(fac[N - 1], mod - 2);
//	for (int i = N - 2; i >= 1; i--) {
//		finv[i] = finv[i + 1] * (i + 1) % mod;
//	}
//}
//int cal(int x,vector<int>&t) {
//	int ans = 1;
//	for (int i = 0; i < m; i++) {
//		//cout << fac[x] << " " << finv[x - t[i]] << "***\n";
//		ans = ans*fac[x]%mod * finv[x - t[i]]%mod;
//	}
//	return ans;
//}
//signed main() {
//	prepare();
//	cin >> n >> m;
//	vector<int>t(m);
//	for (int i = 1; i <= n; i++) {
//		t[i % m]++;
//	}
//	int ans = 0,mx=INT_MIN;
//	for (int i = 0; i < m; i++) {
//		mx = max(mx, t[i]);
//	}
//	vector<int>an(n + 1);
//	//一定分i个组的方案数
//	int sum = 0;//记录前面的方案数
//	for (int i = 1; i <= n; i++) {
//		if (i < mx) {
//			an[i] = 0;
//			cout << an[i] << '\n';
//		}
//		else {
//			//cout << cal(i, t) << " " << an[i - 1] << '\n';
//			an[i] = cal(i, t);
//			for (int j = i - 1; j >= 1; j--) {
//				an[i] = (an[i] - an[j] * C(i, j) + mod) % mod;
//			}
//			cout << an[i]*finv[i]%mod << "\n";
//		}
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2e5 + 10;
//const int mod = 998244353;
//int dis[N];
//int dep[N];
//int finv[N];
//int fac[N];
//int fa[N];
//vector<vector<int>>g;
//void dfs(int i, int pa) {
//	dep[i] = dep[pa] + 1;
//	fa[i] = pa;
//	for (auto v : g[i]) {
//		if (v != pa) {
//			dfs(v, i);
//		}
//	}
//}
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
//int cnt = 0;
//void dfs1(int p, int pa, set<int>& dia, int len, int c) {
//	if (c == len){
//		cnt++;
//		return;
//	}
//	for (auto v : g[p]) {
//		if (dia.count(v)||v==pa)continue;
//		dfs1(v,p, dia,len,c+1);
//	}
//}
//signed main() {
//	int n;
//	cin >> n;
//	g.assign(n + 1, {});
//	
//	//找到一条直径
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	dfs(1, 0);
//	int a = 0, md = -1;
//	for (int i = 1; i <= n; i++) {
//		if (dep[i] > md) {
//			a = i;
//			md = dep[i];
//		}
//	}
//	dfs(a, a);
//	int b = 0; md = -1;
//	for (int i = 1; i <= n; i++) {
//		if (dep[i] > md) {
//			b = i;
//			md = dep[i];
//		}
//	}
//	//a为左b为右
//	set<int>dia;
//	int diam = 0;
//	for (int t = b; t != a; t = fa[t]) {
//		dia.insert(t);
//		diam++;
//	}
//	dia.insert(a);
//	int ca=1, cb=1,cs=0;
//	//cout << "a:" << a << " " << "b:" << b << '\n';
//	for (int p = fa[b],len=1; p != a; p = fa[p],len++) {
//		cnt = 0;
//		dfs1(p,p,dia,min(len,diam-len),0);
//		//cout << p << " " << cnt << " " << len<<" "<<diam - len << "***\n";
//		if (len == diam - len) {
//			cs += cnt;
//		}
//		else {
//			if (min(len, diam - len) == diam) {
//				ca += cnt;
//			}
//			else {
//				cb += cnt;
//			}
//		}
//	}
//	//cout << ca << " " << cb << " " << cs << " " << '\n';
//	////      a b选c任意           c选ab不选  c选 ab选1                    
//	//int ans = ca * cb%mod * qpow(2, cs)%mod;
//	//if (cs != 0) {
//	//	ans = (ans + (ca + cb) % mod * (qpow(2, cs) - 1) % mod)%mod;
//	//}
//	//if (cs != 1) {
//	//	ans = (ans + ((qpow(2, cs) + mod - 1 - cs * (cs - 1)))%mod) % mod;
//	//}
//	//cout << ans << '\n';
//
//}

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2e5 + 10;
//const int mod = 998244353;
//int dis[N];
//int dep[N];
//int finv[N];
//int fac[N];
//int fa[N];
//vector<vector<int>>g;
//void dfs(int i, int pa) {
//	dep[i] = dep[pa] + 1;
//	fa[i] = pa;
//	for (auto v : g[i]) {
//		if (v != pa) {
//			dfs(v, i);
//		}
//	}
//}
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
//int cnt = 0;
//void dfs1(int p, int pa, set<int>& dia, int len, int c) {
//	if (c == len) {
//		cnt++;
//		return;
//	}
//	for (auto v : g[p]) {
//		if (dia.count(v) || v == pa)continue;
//		dfs1(v, p, dia, len, c + 1);
//	}
//}
//int siz[N];
//int num[N];
//void dfs2(int u, int fa,int len,int c) {
//	siz[u] = 1;
//	if (c == len)num[u]++;
//	for (auto v : g[u]) {
//		if (v == fa)continue;
//		dfs2(v, u, len, c+1);
//	}
//	for (auto v : g[u]) {
//		if (v == fa)continue;
//		siz[u] += siz[v];
//		num[u] += num[v];
//	}
//	return;
//}
//signed main() {
//	int n;
//	cin >> n;
//	g.assign(n + 1, {});
//
//	//找到一条直径
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	dfs(1, 0);
//	int a = 0, md = -1;
//	for (int i = 1; i <= n; i++) {
//		if (dep[i] > md) {
//			a = i;
//			md = dep[i];
//		}
//	}
//	dfs(a, a);
//	int b = 0; md = -1;
//	for (int i = 1; i <= n; i++) {
//		if (dep[i] > md) {
//			b = i;
//			md = dep[i];
//		}
//	}
//	//a为左b为右
//	set<int>dia;
//	int diam = 0;
//	for (int t = b; t != a; t = fa[t]) {
//		dia.insert(t);
//		diam++;
//	}
//	dia.insert(a);
//	int ca = 1, cb = 1, cs = 0;
//	int mid;
//	//cout << "a:" << a << " " << "b:" << b << '\n';
//	for (int p = fa[b], len = 1; p != a; p = fa[p], len++) {
//		cnt = 0;
//		dfs1(p, p, dia, min(len, diam - len), 0);
//		//cout << p << " " << cnt << " " << len<<" "<<diam - len << "***\n";
//		if (len == diam - len) {
//			cs += cnt;
//			mid = p;
//		}
//		else {
//			if (min(len, diam - len) == diam-len) {
//				ca += cnt;
//			}
//			else {
//				cb += cnt;
//			}
//		}
//	}
//	if (cs == 0) {
//		cout << ca * cb %mod<< "\n";
//		return 0;
//	}
//	dfs2(mid, mid,diam/2,0);
//	int sum = 0;
//	int ans = 1;
//	for (auto v : g[mid]) {
//		//cout << num[v] << '\n';
//		ans = ans * (num[v] + 1) % mod;
//		sum += num[v];
//	}
//	ans--;//去掉都不选
//	int diff = 0;//去掉只选一个
//	for (auto v : g[mid]) {
//		ans = (ans + mod - num[v])%mod;
//	}
//	cout << (ans)%mod << '\n';
//}
//16
//1 2
//2 3
//2 4
//4 5
//5 6
//6 7
//7 8
//5 14
//14 15
//15 16
//5 9
//9 10
//10 11
//9 12
//12 13
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 998244353;
//const int N = 420;
//int fnd[N][N];
//int n, m;
//int dp[N][N];
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
//	return fac[n] * finv[m]%mod * finv[n - m] % mod;
//}
//void prepare() {
//	finv[0] = fac[0] = 1;
//	for (int i = 1; i < N; i++) {
//		fac[i] = fac[i - 1] * i % mod;
//	}
//	finv[N - 1] = qpow(fac[N - 1], mod - 2);
//	for (int i = N - 2; i >= 1; i--) {
//		finv[i] = finv[i + 1] * (i + 1) % mod;
//	}
//}
//int f(int l, int r) {//l-r上选完的方案数
//	if (dp[l][r] != -1)return dp[l][r];
//	if (l + 1 == r) {
//		return dp[l][r]=fnd[l][r];
//	}
//	if (l > r)return 1;
//	int ans = 0;
//	for (int j = l + 1; j <= r; j+=2) {
//		if (fnd[l][j]) {
//			//cout << C((r - l + 1) / 2, (r - j) / 2) << '\n';
//			ans = (ans + f(l + 1, j - 1) * f(j + 1, r)%mod * C((r - l+1) / 2, (r - j) / 2) % mod) % mod;
//		}
//	}
//	//for (int j = r - 1; j > l; j-=2) {
//	//	if (fnd[j][r]) {
//	//		cout << C((r - l + 1) / 2, (j - l) / 2) % mod << '\n';
//	//		ans = (ans + f(j + 1, r - 1) * f(l, j - 1)%mod * C((r - l+1) / 2, (j - l) / 2) % mod) % mod;
//	//	}
//	//}
//	dp[l][r] = ans;
//	return ans;
//}
//signed main() {
//	prepare();
//	cin >> n >> m;
//	for (int i = 1,a,b; i <= m; i++) {
//		cin >> a >> b;
//		fnd[a][b] = 1;
//		fnd[b][a] = 1;
//	}
//	memset(dp, -1, sizeof(dp));
//	cout << f(1, 2*n)<<'\n';
//}