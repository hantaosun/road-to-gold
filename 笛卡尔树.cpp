//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e7 + 5;
//int p[N];
//int lson[N];
//int rson[N];
//int sta[N];
//int n;
//void build() {
//	int top = 0;
//	for (int i = 1; i <= n; i++) {
//		int pos = top;
//		while (pos > 0 && p[sta[pos]] > p[i]) {
//			pos--;
//		}
//		if (pos > 0) {
//			rson[sta[pos]] = i;
//		}
//		if (pos < top) {
//			lson[i] = sta[pos + 1];
//		}
//		sta[++pos] = i;
//		top = pos;
//	}
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//	}
//	build();
//	long long ans1 = 0, ans2 = 0;
//	for (int i = 1; i <= n; i++) {
//		ans1 ^= 1ll * i * (lson[i] + 1);
//		ans2 ^= 1ll * i * (rson[i] + 1);
//	}
//	cout << ans1 << " " << ans2 << '\n';
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 5;
//int cnt = 0;
//int head = 0;
//int key[N];
//int cont[N];
//int lson[N];
//int rson[N];
//int siz[N];
//double priority[N];
//void up(int i) {
//	siz[i] = siz[lson[i]] + siz[rson[i]] + cont[i];
//}
//int leftRotate(int i) {
//	int r = rson[i];
//	rson[i] = lson[r];
//	lson[r] = i;
//	up(i);
//	up(r);
//	return r;
//}
//int rightRotate(int i) {
//	int l = lson[i];
//	lson[i] = rson[l];
//	rson[l] = i;
//	up(i);
//	up(l);
//	return l;
//}
//int add(int i, int num) {
//	if (i == 0) {
//		key[++cnt] = num;
//		cont[cnt] = siz[cnt] = 1;
//		priority[cnt] = static_cast<double>(rand()) / RAND_MAX;
//		return cnt;
//	}
//	if (key[i] == num) {
//		cont[i]++;
//	}
//	else if (key[i] > num) {
//		lson[i]=add(lson[i], num);
//	}
//	else {
//		rson[i] = add(rson[i], num);
//	}
//	up(i);
//	if (lson[i] != 0 && priority[lson[i]] > priority[i]) {
//		return rightRotate(i);
//	}
//	if (rson[i] != 0 && priority[rson[i]] > priority[i]) {
//		return leftRotate(i);
//	}
//	return i;
//}
//void add(int num) {
//	head = add(head, num);
//}
//int small(int i, int num) {
//	if (i == 0) {
//		return 0;
//	}
//	if (key[i] >= num) {
//		return small(lson[i], num);
//	}
//	else {
//		return siz[lson[i]] + cont[i] + small(rson[i], num);
//	}
//}
//int getRank(int num) {
//	return small(head, num) + 1;
//}
//int index(int i, int x) {
//	if (siz[lson[i]] >= x) {
//		return index(lson[i], x);
//	}
//	else if (siz[lson[i]] + cont[i] < x) {
//		return index(rson[i], x - siz[lson[i]] - cont[i]);
//	}
//	return key[i];
//}
//int index(int x) {
//	return index(head, x);
//}
//int pre(int i, int num) {
//	if (i == 0) {
//		return INT_MIN;
//	}
//	if (key[i] >= num) {
//		return pre(lson[i], num);
//	}
//	else {
//		return max(key[i], pre(rson[i], num));
//	}
//}
//int pre(int num) {
//	return pre(head, num);
//}
//int post(int i, int num) {
//	if (i == 0) {
//		return INT_MAX;
//	}
//	if (key[i] <= num) {
//		return post(rson[i], num);
//	}
//	else {
//		return min(key[i], post(lson[i], num));
//	}
//}
//int post(int num) {
//	return post(head, num);
//}
//int remove(int i,int num) {
//	if (key[i] < num) {
//		rson[i]= remove(rson[i], num);
//	}
//	else if (key[i] > num) {
//		lson[i]= remove(lson[i], num);
//	}
//	else {
//		if (cont[i] > 1) {
//			cont[i]--;
//		}
//		else {
//			if (lson[i] == 0 && rson[i] == 0) {
//				return 0;
//			}
//			else if (lson[i] != 0 && rson[i] == 0) {
//				return lson[i];
//			}
//			else if (lson[i] == 0 && rson[i] != 0) {
//				return rson[i];
//			}
//			else {
//				if (priority[lson[i]] >= priority[rson[i]]) {
//					i = rightRotate(i);
//					rson[i] = remove(rson[i], num);
//				}
//				else {
//					i = leftRotate(i);
//					lson[i] = remove(lson[i], num);
//				}
//			}
//		}
//	}
//	up(i);
//	return i;
//}
//void remove(int num) {
//	if (getRank(num) != getRank(num + 1)) {
//		head = remove(head, num);
//	}
//}
//void clear() {
//	memset(key + 1, 0, cnt * sizeof(int));
//	memset(cont + 1, 0, cnt * sizeof(int));
//	memset(lson + 1, 0, cnt * sizeof(int));
//	memset(rson + 1, 0, cnt * sizeof(int));
//	memset(siz + 1, 0, cnt * sizeof(int));
//	memset(priority + 1, 0, cnt * sizeof(int));
//	cnt = 0;
//	head = 0;
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	srand(time(0));
//	int n;
//	cin >> n;
//	for (int i = 1,op,x; i <= n; i++) {
//		cin >> op >> x;
//		switch (op) {
//		case 1:add(x); break;
//		case 2:remove(x); break;
//		case 3:cout << getRank(x) << '\n'; break;
//		case 4:cout << index(x) << '\n'; break;
//		case 5:cout << pre(x) << '\n'; break;
//		case 6:cout << post(x) << '\n'; break;
//		}
//	}
//	clear();
//	return 0;
//}






//6666
//树的序
//#include<bits/stdc++.h>
//using namespace std;
//int lson[100005];
//int rson[100005];
//int main() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1,u; i <= n; i++) {
//		cin >> u;
//		a[u] = i;
//	}
//	vector<int>sta(n + 1);
//	int top = 0;
//	int pos = 0;
//	for (int i = 1; i <= n; i++) {
//		pos = top;
//		while (pos>0&&a[sta[pos]] > a[i]) {
//			pos--;
//		}
//		if (pos > 0) {
//			rson[sta[pos]] = i;
//		}
//		if (pos < top) {
//			lson[i] = sta[pos + 1];
//		}
//		sta[++pos] = i;
//		top = pos;
//	}
//	auto dfs = [&](auto&self, int u) ->void{
//		if (u == 0)return;
//		cout << u<<" ";
//		self(self, lson[u]);
//		self(self, rson[u]);
//		};
//	dfs(dfs, sta[1]);
//	cout << '\n';
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 1e9 + 7;
//const int N = 2e5 + 5;
//int lson[N];
//int rson[N];
//int sta[N];
//int n, m;
//vector<int>f;//该节点严格等于val的方案数
//vector<vector<int>>dp;//当前树上该节点小于等于m的所有情况数
//void dfs(int u) {
//	if (u == 0) {
//		return;
//	}
//	dfs(lson[u]);
//	dfs(rson[u]);
//	for (int i = 1; i <= m; i++) {
//		f[i] = dp[lson[u]][i - 1] * dp[rson[u]][i]%mod;
//	}
//	for (int i = 1; i <= m; i++) {
//		dp[u][i] = (dp[u][i - 1] + f[i])%mod;
//	}
//}
//void solve() {
//	cin >> n >> m;
//	memset(lson, 0, sizeof(int) * (n + 10));
//	memset(rson, 0, sizeof(int) * (n + 10));
//	dp.assign(n + 5, vector<int>(m + 5,0));
//	vector<int>a(n + 1);
//	f.assign(m + 1, 0);
//	for (int i = 0; i <= m; i++) {
//		dp[0][i] = 1;
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int top = 0, pos = 0;
//	for (int i = 1; i <= n; i++) {
//		pos = top;
//		while (pos > 0 && a[sta[pos]] < a[i]) {
//			pos--;
//		}
//		if (pos > 0) {
//			rson[sta[pos]] = i;
//		}
//		if (pos < top) {
//			lson[i] = sta[pos + 1];
//		}
//		sta[++pos] = i;
//		top = pos;
//	}
//	dfs(sta[1]);
//	//cout << '\n';
//	//for (int i = 1; i <= n; i++) {
//	//	cout << lson[i] << " " << rson[i] << '\n';
//	//}
//	//for (int i = 1; i <= n; i++) {
//	//	for (int j = 1; j <= m; j++) {
//	//		cout << dp[i][j] << " ";
//	//	}cout << '\n';
//	//}
//	//cout << sta[1] << '\n';
//	cout << dp[sta[1]][m] << '\n';
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
//const int mod = 1e9 + 7;
//const int H = 1e6 + 5;
//const int N = 505;
//int lson[N];
//int rson[N];
//int siz[N];
//int sta[N];
//int a[N];
//int n, k;
//int tmp[N];//当前节点及其之前节点严格放i个的方案数
//int dp[N][N];//当前节点及其之前节点放小于等于i个的方案数
//int fac[H];
//int finv[H];
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
//int C(int n, int m) {
//	if (n < 0 || m < 0 || n < m)return 0;
//	return fac[n] * finv[m]%mod * finv[n - m] % mod;
//}
//void dfs(int u,int fa) {
//	if (u == 0)return;
//	dfs(lson[u],u);
//	dfs(rson[u],u);
//	siz[u] = siz[lson[u]] + siz[rson[u]] + 1;
//	memset(tmp, 0, sizeof(int) * k + 5);
//	for (int l = 0; l <= min(siz[lson[u]], k); l++) {
//		for (int r = 0; r <= min(siz[rson[u]], k-l); r++) {
//			tmp[l + r] = (tmp[l + r] + dp[lson[u]][l] * dp[rson[u]][r]%mod) % mod;
//		}
//	}
//	for (int i = 0; i <= min(siz[u], k); i++) {//总共选i个
//		for (int p = 0; p <= i; p++) {//前面选p个
//			dp[u][i] = (dp[u][i] + C(siz[u] - p, i - p) * C(a[u] - a[fa], i - p) % mod *fac[i-p]%mod* tmp[p] % mod)%mod;
//		}
//	}
//}
//void prepare() {
//	fac[0] = finv[0] = 1;
//	for (int i = 1; i < H; i++) {
//		fac[i] = i * fac[i - 1] % mod;
//	}
//	finv[H - 1] = qpow(fac[H - 1], mod - 2);
//	for (int i = H - 2; i >= 1; i--) {
//		finv[i] = finv[i + 1] * (i + 1) % mod;
//	}
//}
//signed main() {
//	prepare();
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int top = 0, pos = 0;
//	for (int i = 1; i <= n; i++) {
//		pos = top;
//		while (pos > 0 && a[sta[pos]] > a[i]) {
//			pos--;
//		}
//		if (pos > 0) {
//			rson[sta[pos]] = i;
//		}
//		if (pos< top) {
//			lson[i] = sta[pos + 1];
//		}
//		sta[++pos] = i;
//		top = pos;
//	}
//	dp[0][0] = 1;
//	dfs(sta[1],0);
//	cout << dp[sta[1]][k] << '\n';
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 5;
//const int mod = 1e9 + 7;
//int a[N];
//int inv[N];
//int sum[N];
//void prepare() {
//	inv[1] = 1;
//	for (int i = 2; i < N; i++){
//		inv[i] = (mod - inv[mod % i] * (mod / i) % mod);
//	}
//	for (int i = 1; i < N; i++) {
//		sum[i] = (sum[i - 1] + inv[i]) % mod;
//	}
//}
//signed main() {
//	prepare();
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		ans = (ans + (sum[i] + sum[n - i + 1] - 1) * a[i]) % mod;
//	}
//	for (int i = 1; i <= n; i++) {
//		ans = ans * i % mod;
//	}
//	cout << ans << '\n';
//}