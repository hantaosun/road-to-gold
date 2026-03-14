//普通消元得到线性基求异或最大值
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int base[33];
//bool zero = 0;
//bool insert(int x) {
//	for (int i=63; i >= 0; i--) {
//		if ((x >> i) & 1) {
//			if (base[i] == 0) {
//				base[i] = x;
//				return true;
//			}
//			else {
//				x ^= base[i];
//			}
//		}
//	}
//	return false;
//}
//signed main() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		if (!insert(a[i]))zero = 1;
//	}
//	int ans = 0;
//	for (int i = 31; i >= 0; i--) {
//		ans = max(ans, ans ^ base[i]);
//	}
//	cout << ans << endl;
//}


//高斯消元解决k大异或和
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int BIT = 62;
//int mat[100005];
//int len = 1;
//bool zero = 0;
//void gauss(int n) {
//	for (int i = BIT; i >=0; i--) {
//		for (int j = len; j <= n; j++) {
//			if ((mat[j] >> i) & 1) {
//				swap(mat[j], mat[len]);
//				break;
//			}
//		}
//		if ((mat[len] >> i) & 1) {
//			for (int j = 1; j <= n; j++) {
//				if (j != len && ((mat[j] >> i) & 1)) {
//					mat[j] ^= mat[len];
//				}
//			}
//			len++;
//		}
//	}
//	len--;
//	zero = len != n;
//}
//int query(int k) {
//	if (zero && k == 1)return 0;
//	if (zero) {
//		k--;
//	}
//	if (k >= (1L << len))return -1;//不能全不选所以是等号
//	int ans = 0;
//	for (int i = len,j=0; i>=1; i--,j++) {
//		if ((k >> j) & 1) {
//			ans ^= mat[i];
//		}
//	}
//	return ans;
//}
//signed main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> mat[i];
//	}
//	gauss(n);
//	int m;
//	cin >> m;
//	for (int i = 1,k; i <= m; i++) {
//		cin >> k;
//		cout << query(k) << '\n';
//	}
//}


//元素
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int BIT = 63;
//int base[65];
//bool insert(int x) {
//	for (int i = BIT; i >= 0; i--) {
//		if ((x >> i) & 1) {
//			if (base[i]) {
//				x ^= base[i];
//			}
//			else {
//				base[i] = x;
//				return true;
//			}
//		}
//	}
//	return false;
//}
//signed main() {
//	int n;
//	cin >> n;
//	vector<array<int, 2>>a;
//	for (int i = 1,u,v; i <= n; i++) {
//		cin >> u >> v;
//		a.push_back({ u,v });
//	}
//	sort(a.begin(), a.end(), [&](auto a,auto b) {
//		return a[1] > b[1];
//		});
//	int ans = 0;
//	for (int i = 0; i < a.size(); i++) {
//		if (insert(a[i][0])) {
//			ans += a[i][1];
//		}
//	}
//	cout << ans << endl;
//}


//彩灯
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 2008;
//int mat[60];
//bool zero = 0;
//const int BIT = 62;
//int len = 1;
//void gauss(int n) {
//	for (int i = BIT; i >= 0; i--) {
//		for (int j = len; j <= n; j++) {
//			if ((mat[j] >> i) & 1) {
//				swap(mat[len], mat[j]);
//				break;
//			}
//		}
//		if ((mat[len] >> i) & 1) {
//			for (int j = 1; j <= n; j++) {
//				if (j != len && (mat[j] >> i) & 1) {
//					mat[j] ^= mat[len];
//				}
//			}
//			len++;
//		}
//	}
//	len--;
//	zero = len != n;
//}
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
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	string s;
//	for (int i = 1; i <= m; i++) {
//		cin >> s;
//		for (int j = 0; j < n; j++) {
//			mat[i] = mat[i] * 2 + (s[j] == 'O');
//		}
//	}
//	gauss(m);
//	//for (int i = 1; i <= len; i++) {
//	//	cout << bitset<32>(mat[i]) << endl;
//	//}
//	cout << (1LL << len) % mod << endl;
//}


//装备购买
//#include<bits/stdc++.h>
//using namespace std;
//int n, m;
//const double sml = 1e-5;
//vector<vector<double>>base;
//bool insert(vector<double>& a) {
//	for (int i = 0; i < m; i++) {
//		if (abs(a[i]) >= sml) {
//			if (base[i].empty()) {
//				base[i] = a;
//				return true;
//			}
//			else {
//				double rate = a[i] / base[i][i];
//				for (int j = i; j < m; j++) {
//					a[j] -= rate*base[i][j];
//				}
//			}
//		}
//	}
//	return false;
//}
//int main() {
//	cin >> n >> m;
//	base.assign(m, {});
//	vector <vector<double>>eqp(n, vector<double>(m + 1));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> eqp[i][j];
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		cin >> eqp[i][m];
//	}
//	sort(eqp.begin(), eqp.end(), [&](auto x, auto y) {
//		return x[m] < y[m];
//		});
//	int ans = 0, cnt = 0;
//	for (int i = 0; i < n; i++) {
//		if (insert(eqp[i])) {
//			ans += eqp[i][m];
//			cnt++;
//		}
//	}
//	cout << cnt<< " " << ans << '\n';
//}


//P哥的桶
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 5e4 + 2;
//const int BIT = 31;
//int a[MAXN << 2][BIT+5];
//bool insert(int i, int v) {
//	for (int j = BIT; j >= 0; j--) {
//		if ((v >> j) & 1) {
//			if (a[i][j]==0) {
//				a[i][j] = v;
//				return true;
//			}
//			v ^= a[i][j];
//		}
//	}
//	return false;
//}
//void add(int x, int v, int l, int r, int i) {
//	insert(i, v);
//	if (l < r) {
//		int mid = l + r >> 1;
//		if (x <= mid) {
//			add(x, v, l, mid, i << 1);
//		}
//		if (x > mid) {
//			add(x, v, mid + 1, r, i << 1 | 1);
//		}
//	}
//}
//int basis[BIT+5];
//bool insert1(int v) {
//	for (int j = BIT; j >= 0; j--) {
//		if ((v >> j) & 1) {
//			if (basis[j]==0) {
//				basis[j] = v;
//				return true;
//			}
//			v ^= basis[j];
//		}
//	}
//	return false;
//}
//
//void merge(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		for (int j = BIT; j >= 0; j--) {
//			if (a[i][j] != 0)
//				insert1(a[i][j]);
//		}
//	}
//	else {
//		int mid = l + r >> 1;
//		if (jl <= mid) {
//			merge(jl, jr, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			merge(jl, jr, mid + 1, r, i << 1 | 1);
//		}
//	}
//}
//int query(int jl, int jr, int m) {
//	memset(basis, 0, sizeof(basis));
//	merge(jl, jr, 1, m, 1);
//	int ans = 0;
//	for (int i = BIT; i >= 0; i--) {
//		ans = max(ans, ans ^ basis[i]);
//	}
//	return ans;
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1, a, b, c; i <= n; i++) {
//		cin >> a >> b >> c;
//		if (a == 1) {
//			add(b, c, 1, m, 1);
//		}
//		else {
//			cout << query(b, c, m) << '\n';
//		}
//	}
//}


//幸运数字
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2e4 + 2;
//const int BIT = 61;
//int pwr;
//int nex[N << 1];
//int to[N << 1];
//int head[N];
//int lucky[N];
//int dep[N];
//int st[N][17];
//int stxor[N][17][BIT+1];
//int cnt = 1;
//int log2(int N) {
//	int ans = 0;
//	while ((1ll << ans) <= N >> 1) {
//		ans++;
//	}
//	return ans;
//}
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//bool insert(int i,int p,int v) {
//	//cout << i << " " << p << " " << v << endl;
//	for (int j = BIT; j >= 0; j--) {
//		if (v >> j & 1) {
//			if (stxor[i][p][j] == 0) {
//				stxor[i][p][j] = v;
//				return true;
//			}
//			v ^= stxor[i][p][j];
//		}
//	}
//	return false;
//}
//void dfs(int u, int pa) {
//	st[u][0] = pa;
//	dep[u] = dep[pa] + 1;
//	insert(u, 0, lucky[u]);
//	for (int p = 1; p <= pwr; p++) {
//		st[u][p] = st[st[u][p-1]][p - 1];
//	}
//	for (int p = 1; p <= pwr; p++) {
//		for (int j = BIT; j >= 0; j--) {
//			if (stxor[u][p-1][j] != 0)
//			insert(u, p, stxor[u][p - 1][j]);
//			if (stxor[st[u][p-1]][p-1][j] != 0)
//			insert(u, p, stxor[st[u][p - 1]][p - 1][j]);
//		}
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == pa)continue;
//		dfs(to[e], u);
//	}
//}
//int basis[BIT + 1];
//bool insert1(int v) {
//	for (int i = BIT; i >= 0; i--) {
//		if ((v >> i) & 1) {
//			if (basis[i] == 0) {
//				basis[i] = v;
//				return true;
//			}
//			v ^= basis[i];
//		}
//	}
//	return false;
//}
//int query(int x, int y) {
//	memset(basis, 0, sizeof(basis));
//	//cout << x <<" "<<y<< endl;
//	if (dep[x] < dep[y]) {
//		swap(x, y);
//	}
//	//cout << x << endl;
//	for (int p = pwr; p >= 0; p--) {
//		if (dep[st[x][p]]>=dep[y]) {
//			for (int i = BIT; i >= 0; i--) {
//				if (stxor[x][p][i] != 0) {
//					//cout << bitset<32>(stxor[x][p][i]) << '\n';
//					insert1(stxor[x][p][i]);
//				}
//			}
//			x = st[x][p];
//		}
//	}
//	//cout << x <<" "<<y << endl;
//	if (x == y) {
//		insert1(lucky[x]);
//		//cout << endl;
//		int ans = 0;
//		for (int i = BIT; i >= 0; i--) {
//			//if(basis[i]!=0)cout << bitset<32>(basis[i]) << '\n';
//			ans = max(ans, ans ^ basis[i]);
//		}
//		return ans;
//	}
//	//cout << x<<" "<<y << endl;
//	for (int p = pwr; p >= 0; p--) {
//		if (st[x][p] != st[y][p]) {
//
//			for (int i = BIT; i >= 0; i--) {
//				if(stxor[x][p][i]!=0)
//				insert1(stxor[x][p][i]);
//				if (stxor[y][p][i] != 0)
//				insert1(stxor[y][p][i]);
//			}
//			x = st[x][p];
//			y = st[y][p];
//		}
//	}
//	//cout << x <<" "<<y << endl;
//	for (int i = BIT; i >= 0; i--) {
//		if (stxor[x][0][i] != 0) insert1(stxor[x][0][i]);
//		if (stxor[y][0][i] != 0) insert1(stxor[y][0][i]);
//
//	}
//	insert1(lucky[st[x][0]]);
//	int ans = 0;
//	//cout << endl;
//	for (int i = BIT; i >= 0; i--) {
//		ans = max(ans, ans^basis[i]);
//	}
//	return ans;
//}
//signed main() {
//	int n, q;
//	cin >> n >> q;
//	pwr = log2(n);
//	for (int i = 1; i <= n; i++) {
//		cin >> lucky[i];
//	}
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dep[1] = 0;
//	dfs(1, 0);
//	//for (int i = 1; i <= n; i++) {
//	//	for(int j=BIT;j>=0;j--)cout << bitset<32>(stxor[i][1][j]) << endl;
//	//	cout << endl;
//	//}
//	for (int i = 1, x, y; i <= q; i++) {
//		cin >> x >> y;
//		cout << query(x, y)<<'\n';
//	}
//}