//高斯消元法模板
//不区分多解与无解版
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 102;
//vector<vector<double>> mat;
//const double sml = 1e-7;
//int gauss(int n) {
//	for (int i = 1; i <= n; i++) {
//		
//		//将最大行交换至本行
//		int max = i;
//		for (int j = i + 1; j <= n; j++) {
//			if (abs(mat[j][i]) > abs(mat[max][i])) {
//				max = j;
//			}
//		}
//		swap(mat[i], mat[max]);
//		
//		//将mat[i][i]化为1 为0则跳过
//		if (abs(mat[i][i]) < sml)return 0;
//		double tmp = mat[i][i];
//		for (int j = i; j <= n+1; j++) {
//			mat[i][j] /= tmp;
//		}
//
//		//
//		for (int j = 1; j <= n; j++) {
//			if (i != j) {
//				double rate = mat[j][i] / mat[i][i];
//				for (int k = i; k <= n + 1; k++) {
//					mat[j][k] -= rate * mat[i][k];
//				}
//			}
//		}
//	}
//	return 1;
//}
//int main() {
//	int n;
//	cin >> n;
//	mat.assign(n + 5, vector<double>(n + 5));
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n + 1; j++) {
//			cin >> mat[i][j];
//		}
//	}
//	int sign = gauss(n);
//	if (sign == 0)cout << "No Solution\n";
//	else {
//		for (int i = 1; i <= n; i++) {
//			cout << fixed << setprecision(2) << mat[i][n + 1]<<'\n';
//		}
//	}
//}
//区分多解和无解版
//#include<bits/stdc++.h>
//using namespace std;
//const double sml = 1e-7;
//vector<vector<double>>mat;
//void gauss(int n) {
//	for (int i = 1; i <= n; i++) {
//		int max = i;
//		for (int j = 1; j <= n; j++) {
//			if (j < i && abs(mat[j][j]) >= sml) {
//				continue;
//			}
//			if (abs(mat[j][i]) > abs(mat[max][i])) {
//				max = j;
//			}
//		}
//		swap(mat[i], mat[max]);
//		if (abs(mat[i][i]) >= sml) {
//			double tmp = mat[i][i];
//			for (int j = i; j <= n+1; j++) {
//				mat[i][j] /= tmp;
//			}
//			for (int j = 1; j <= n; j++) {
//				if (i != j) {
//					double rate = mat[j][i] / mat[i][i];
//					for (int k = i; k <= n + 1; k++) {
//						mat[j][k] -= rate * mat[i][k];
//					}
//				}
//			}
//		}
//	}
//}
//int main() {
//	int n;
//	cin >> n;
//	mat.assign(n+2,vector<double>(n+2));
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n + 1; j++) {
//			cin >> mat[i][j];
//		}
//	}
//	gauss(n);
//	int sign = 1;
//	for (int i = 1; i <= n; i++) {
//		if (abs(mat[i][i]) < sml && abs(mat[i][n + 1]) > sml) {
//			sign = -1;
//			break;
//		}
//		if (abs(mat[i][i]) < sml) {
//			sign = 0;
//		}
//	}
//	if (sign == 1) {
//		for (int i = 1; i <= n; i++) {
//			cout << "x" << i << "=" << fixed << setprecision(2) << mat[i][n + 1] << '\n';
//		}
//	}
//	else cout << sign << '\n';
//}


////球形空间产生器
//#include<bits/stdc++.h>
//using namespace std;
//vector<vector<double>>mat;
//const double sml = 1e-7;
//void gauss(int n) {
//	for (int i = 1; i <= n; i++) {
//		int max = i;
//		for (int j = 1; j <= n; j++) {
//			if (j < i && abs(mat[j][j]) >= sml) {
//				continue;
//			}
//			if (abs(mat[j][i]) > abs(mat[max][i])) {
//				max = i;
//			}
//		}
//		swap(mat[i], mat[max]);
//		if (abs(mat[i][i]) >= sml) {
//			double tmp = mat[i][i];
//			for (int j = i; j <= n + 1; j++) {
//				mat[i][j] /= tmp;
//			}
//			for (int j = 1; j <= n; j++) {
//				if (j != i) {
//					double rate = mat[j][i] / mat[i][i];
//					for (int k = i; k <= n + 1;k++) {
//						mat[j][k] -= rate * mat[i][k];
//					}
//				}
//			}
//		}
//	}
//}
//int main() {
//	int n;
//	cin >> n;
//	mat.assign(n + 2, vector<double>(n + 2));
//	vector<double>base(n + 2);
//	for (int i = 1; i <= n; i++) {
//		cin >> base[i];
//		base[n + 1] += base[i] * base[i];
//		base[i] *= 2;
//	}
//	for (int i = 1; i <= n; i++) {
//		double tmp = 0;
//		for (int j = 1; j <= n; j++) {
//			cin >> mat[i][j];
//			tmp += mat[i][j] * mat[i][j];
//			mat[i][j] = base[j] - 2 * mat[i][j];
//		}
//		mat[i][n + 1] = base[n + 1] - tmp;
//	}
//	gauss(n);
//	cout << fixed << setprecision(3);
//	for (int i = 1; i <= n; i++) {
//		cout << mat[i][n + 1] << " ";
//	}
//}


//Barracuda
//#include<bits/stdc++.h>
//using namespace std;
//const double sml = 1e-7;
//vector<vector<double>>mat;
//int n;
//void gauss(int n) {
//	for (int i = 1; i <= n; i++) {
//		int max = i;
//		for (int j = 1; j <= n; j++) {
//			if (j < i && abs(mat[j][j]) >= sml) {
//				continue;
//			}
//			if (abs(mat[j][i]) >= abs(mat[max][i])) {
//				max = j;
//			}
//		}
//		swap(mat[i], mat[max]);
//		if (abs(mat[i][i]) >= sml) {
//			double tmp = mat[i][i];
//			for (int j = i; j <= n + 1; j++) {
//				mat[i][j] /= tmp;
//			}
//			for (int j = 1; j <= n; j++) {
//				if (i != j) {
//					double rate = mat[j][i] / mat[i][i];
//					for (int k = i; k <= n + 1; k++) {
//						mat[j][k] -= rate * mat[i][k];
//					}
//				}
//			}
//		}
//	}
//	
//}
//int check() {
//	double maxv = -100000000;
//	int maxt = 0;
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		if (abs(mat[i][i]) < sml)return 0;
//		if (mat[i][n + 1] <= 0 || abs(mat[i][n + 1] - int(mat[i][n + 1])) >= sml) {
//			return 0;
//		}
//		if (maxv < mat[i][n + 1]) {
//			maxv = mat[i][n + 1];
//			maxt = 1;
//			ans = i;
//		}
//		else if (maxv == mat[i][n + 1]) {
//			maxt++;
//		}
//	}
//	if (maxt > 1)return 0;
//	return ans;
//}
//int main() {
//	
//	cin >> n;
//	mat.resize(n+2, vector<double>(n + 2,0));
//	vector<vector<double>>grid(n+2,vector<double>(n+2));
//	for (int i = 1,m,w; i <= n + 1; i++) {
//		cin >> m;
//		for (int j = 1,u; j <= m; j++) {
//			cin >> u;
//			grid[i][u] = 1;
//		}
//		cin >> w;
//		grid[i][n + 1] = w;
//	}
//	int times = 0;
//	int ans = 0;
//	for (int i = 1; i <= n+1; i++) {
//		swap(grid[i], grid[n+1]);
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n + 1; j++) {
//				mat[i][j] = grid[i][j];
//			}
//		}
//		swap(grid[i], grid[n+1]);
//		gauss(n);
//		int cur = check();
//		if (cur != 0) {
//			times++;
//			ans = cur;
//		}
//	}
//	if (times != 1) {
//		cout << "illegal\n";
//	}
//	else cout << ans << '\n';
//}


//高斯消元解决异或方程组
//#include<bits/stdc++.h>
//#define i64 long long
//using namespace std;
//const int mod = 1e9 + 7;
//int prime[3000];
//bool visi[3000];
//int cnt = 0;
//vector<vector<int>>mat(306, vector<int>(306, 0));
//void eular(int n) {
//	for (int i = 2; i <= n; i++) {
//		if (!visi[i]) {
//			prime[++cnt] = i;
//			visi[i] = 1;
//		}
//		for (int j = 1; j <= cnt; j++) {
//			if (i * prime[j] > n)break;
//			visi[i * prime[j]] = 1;
//			if (!(i % prime[j]))break;
//		}
//	}
//}
//void gauss(int n) {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (j < i && mat[j][j]) {
//				continue;
//			}
//			if (mat[j][i] == 1) {
//				swap(mat[i], mat[j]);
//				break;
//			}
//		}
//		if (mat[i][i] == 1) {
//			for (int j = 1; j <= n; j++) {
//				if (i != j && mat[j][i] == 1) {
//					for (int k = i; k <= n + 1; k++) {
//						mat[j][k] ^= mat[i][k];
//					}
//				}
//			}
//		}
//	}
//}
//i64 qpow(i64 a, i64 b) {
//	i64 ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = (ans * a) % mod;
//		}
//		b >>= 1;
//		a = a * a % mod;
//	}
//	return ans;
//}
//void solve(int t) {
//	for (int i = 1; i <= cnt; i++) {
//		for (int j = 1; j <= cnt; j++) {
//			mat[i][j] = 0;
//		}
//	}
//	int n;
//	cin >> n;
//	vector<i64>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		i64 cur = a[i];
//		for (int j = 1; j<=cnt&&cur>1; j++) {
//			while (!(cur % prime[j])) {
//				cur /= prime[j];
//				mat[j][i] ^= 1;
//			}
//		}
//	}
//	gauss(cnt);
//	int cn = 0;
//	for (int i = 1; i <= cnt; i++) {
//		if (mat[i][i] != 0)cn++;
//	}
//	cout << "Case #" << t << ":\n";
//	cout << (qpow(2, n - cn) + mod - 1)%mod << '\n';
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int T;
//	cin >> T;
//	eular(2005);
//	for (int i = 1; i <= T; i++) {
//		solve(i);
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//vector<vector<int>>grid(50,vector<int>(50));
//int opt[50];
//int n, m;
//void gauss(int n) {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (j < i && grid[j][j]) {
//				continue;
//			}
//			if (grid[j][i]) {
//				swap(grid[j],grid[i]);
//				break;
//			}
//		}
//		if (grid[i][i]) {
//			for (int j = 1; j <= n; j++) {
//				if (i!=j&&grid[j][i]) {
//					for (int k = i; k <= n + 1; k++) {
//						grid[j][k] ^= grid[i][k];
//					}
//				}
//			}
//		}
//	}
//}
//int ans = INT_MAX;
//void dfs(int cur, int cnt) {
//	if (cnt >= ans)return;
//	if (cur == 0) {
//		ans = min(ans, cnt);
//		return;
//	}
//	if (grid[cur][cur] == 0) {
//		dfs(cur - 1, cnt);
//		opt[cur] = 1;
//		dfs(cur - 1, cnt + 1);
//		opt[cur] = 0;
//	}
//	else {
//		int a = 0;
//		for (int i = cur + 1; i <= n; i++) {
//			if (grid[cur][i]) {
//				a ^= opt[i];
//			}
//		}
//		a ^= grid[cur][n+1];
//		dfs(cur - 1, cnt + a);
//	}
//}
//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		grid[i][i] = 1;
//		grid[i][n + 1] = 1;
//	}
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		grid[u][v] = 1;
//		grid[v][u] = 1;
//	}
//	gauss(n);
//	//for (int i = 1; i <= n; i++) {
//	//	for (int j = 1; j <= n + 1; j++) {
//	//		cout << grid[i][j] << " ";
//	//	}cout << endl;
//	//}
//	dfs(n, 0);
//	cout << ans << endl;
//}


//外星千足虫
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 2005;
//const int BIT = 64;
//vector<vector<long long>>mat(MAXN, vector<long long>(MAXN / BIT+1));
//int n, m, nm, need;
//void setv(int i, int j, int v) {
//	if (v == 1) {
//		mat[i][j / BIT] |= 1L << (j % BIT);
//	}
//	else {
//		mat[i][j / BIT] &= ~(1L << (j % BIT));
//	}
//}
//int get(int row, int col) {
//	return ((mat[row][col / BIT]) >> (col % BIT) & 1) == 1;
//}
//void eor(int a, int b, int n) {
//	for (int i = 0; i <= n / BIT; i++) {
//		mat[b][i] ^= mat[a][i];
//	}
//}
//void gauss(int n) {
//	need = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = i; j <= n; j++) {
//			if (get(j, i) == 1) {
//				swap(mat[i], mat[j]);
//				need = max(need, j);
//				break;
//			}
//		}
//		if (get(i, i) == 0) {
//			return;
//		}
//		for (int j = 1; j <= n; j++) {
//			if (i != j && get(j, i) == 1) {
//				eor(i, j, n + 2);
//			}
//		}
//	}
//}
//int main() {
//
//	cin >> n >> m;
//	nm = max(n, m);
//	string s;
//	for (int i = 1, z; i <= m; i++) {
//		cin >> s;
//		for (int j = 0; j < s.size(); j++) {
//			setv(i, j + 1, s[j] - '0');
//		}
//		cin >> z;
//		setv(i, nm + 1, z);
//	}
//	gauss(nm);
//	int sign = 1;
//	for (int i = 1; i <= n; i++) {
//		if (get(i, i) == 0) {
//			sign = 0;
//			break;
//		}
//	}
//	if (sign == 0) {
//		cout << "Cannot Determine\n";
//	}
//	else {
//		cout << need << '\n';
//		for (int i = 1; i <= n; i++) {
//			if (get(i, nm + 1))cout << "?y7M#\n";
//			else cout << "Earth\n";
//		}
//	}
//}




//解决同余方程组
//#include<bits/stdc++.h>
//using namespace std;
//vector<vector<int>>mat(905, vector<int>(905));
//vector<vector<int>>grid(35, vector<int>(35));
//int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//const int mod = 3;
//int inv[3];
//void Inv() {
//	inv[1] = 1;
//	for (int i = 2; i < mod; i++) {
//		inv[i] = int(mod - (long long)(inv[mod % i]) * (mod / i) % mod);
//	}
//}
//int gcd(int a, int b) {
//	while (b != 0) {
//		int temp = b;
//		b = a % b;
//		a = temp;
//	}
//	return a;
//}
//void gauss(int n) {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (j < i && mat[j][j] != 0)continue;
//			if (mat[j][i] != 0) {
//				swap(mat[i], mat[j]);
//				break;
//			}
//		}
//		if (mat[i][i] != 0) {
//			for (int j = 1; j <= n; j++) {
//				if (j != i && mat[j][i] != 0) {
//					int g = gcd(mat[i][i], mat[j][i]);
//					int a = mat[i][i] / g;
//					int b = mat[j][i] / g;
//					if (j < i && mat[j][j] != 0) {
//						mat[j][j] = mat[j][j] * a % mod;
//					}
//					for (int k = i; k <= n + 1; k++) {
//						mat[j][k] = ((mat[j][k] * a - mat[i][k] * b) % mod + mod) % mod;
//					}
//				}
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		if (mat[i][i] != 0) {
//			mat[i][n + 1] = (mat[i][n + 1] *inv[mat[i][i]]) % mod;
//		}
//	}
//}
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	mat.assign(n * m + 5, vector<int>(n * m + 5, 0));
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			int id = (i - 1) * m + j;
//			cin >> grid[i][j];
//			mat[id][id] = 2;
//			for (int d = 0; d < 4; d++) {
//				int ni = i + dx[d];
//				int nj = j + dy[d];
//				if (ni >= 1 && ni <= n && nj >= 1 && nj <= m) {
//					mat[id][(ni - 1) * m + nj] = 1;
//				}
//			}
//			mat[id][n * m + 1] = (3 - grid[i][j]) % 3;
//		}
//	}
//	gauss(n * m);
//	int ans = 0;
//	for (int i = 1; i <= n * m; i++) {
//		ans += mat[i][n * m + 1];
//	}
//	cout << ans << endl;
//	for (int i = 1, id = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++, id++) {
//			while (mat[id][n*m + 1]-- > 0) {
//				cout << i << " " << j << endl;
//			}
//		}
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int T;
//	cin >> T;
//	Inv();
//	while (T--) {
//		solve();
//	}
//}


//部件工场
//#include<bits/stdc++.h>
//using namespace std;
//const int mod = 7;
//int inv[7];
//vector<vector<int>>mat;
//void Inv() {
//	inv[1] = 1;
//	for (int i = 2; i < mod; i++) {
//		inv[i] = int(mod - (long long)(inv[mod % i]) * (mod / i) % mod);
//	}
//}
//int gcd(int a, int b) {
//	while (b != 0) {
//		int temp = b;
//		b = a % b;
//		a = temp;
//	}
//	return a;
//}
//int days(string s) {
//	if (s == "MON")return 1;
//	if (s == "TUE")return 2;
//	if (s == "WED")return 3;
//	if (s == "THU")return 4;
//	if (s == "FRI")return 5;
//	if (s == "SAT")return 6;
//	if (s == "SUN")return 7;
//}
//void gauss(int n) {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (j < i && mat[j][j] != 0)continue;
//			if(mat[j][i]!=0){
//				swap(mat[j], mat[i]);
//				break;
//			}
//		}
//		if (mat[i][i] != 0) {
//			for (int j = 1; j <= n; j++) {
//				if (j != i && mat[j][i] != 0) {
//					int g = gcd(mat[j][i], mat[i][i]);
//					int a = mat[i][i] / g;
//					int b = mat[j][i] / g;
//					for (int k = 1; k <= n+1; k++) {
//						mat[j][k] = ((mat[j][k] * a - mat[i][k] * b) + mod) % mod;
//					}
//				}
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		if (mat[i][i] != 0)mat[i][n + 1] = mat[i][n + 1] * inv[mat[i][i]]%mod;
//	}
//}
//bool solve() {
//	int n, m;
//	cin >> n >> m;
//	mat.assign(305, vector<int>(305,0));
//	string st, en;
//	if (n == 0 && m == 0)return true;
//	int nm = max(n, m);
//	for (int i = 1, k; i <= m; i++) {
//		cin >> k >> st >> en;
//		for (int j = 1, t; j <= k; j++) {
//			cin >> t;
//			++mat[i][t];
//		}
//		mat[i][nm + 1] = (7 - days(st) + 1 + days(en)) % mod;
//	}
//	/*for (int i = 1; i <= nm; i++) {
//		for (int j = 1; j <= nm+1; j++) {
//			cout << mat[i][j] << " ";
//		}
//		cout << endl;
//	}*/
//	gauss(nm);
//	//for (int i = 1; i <= nm; i++) {
//	//	for (int j = 1; j <= nm + 1; j++) {
//	//		cout << mat[i][j] << " ";
//	//	}
//	//	cout << endl;
//	//}
//	int sign = 1;
//	for (int i = 1; i <= n*m; i++) {
//		if (mat[i][i] == 0 && mat[i][nm + 1] != 0 ) {//检查矛盾要检查所有行
//			sign = -1;
//			break;
//		}
//		if (i<=n&&mat[i][i] == 0 && mat[i][nm + 1] == 0) {//检查多解只用检查关键元(前n行)
//			sign = 0;
//		}
//	}
//	if (sign == 0) {
//		cout << "Multiple solutions\n";
//	}
//	else if (sign == -1) {
//		cout << "Inconsistent data\n";
//	}
//	else {
//		for (int i = 1; i <= n; i++) {
//			cout << (mat[i][nm + 1] < 3 ? mat[i][nm + 1] + 7 : mat[i][nm + 1]) << " ";
//		}cout << '\n';
//	}
//	return false;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	Inv();
//	while (true) {
//		if (solve())break;
//	}
//	return 0;
//}