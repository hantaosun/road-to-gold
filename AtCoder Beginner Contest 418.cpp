//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n;
//	string s;
//	cin >> n >> s;
//	if (s.size() < 3) {
//		cout << "No\n";
//		return 0;
//	}
//	if (s[s.size() - 1] == 'a' && s[s.size() - 2] == 'e' && s[s.size() - 3] == 't') {
//		cout << "Yes\n";
//	}
//	else {
//		cout << "No\n";
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	string s;
//	cin >> s;
//	int n = s.size();
//	s = " " + s;
//	vector<int>pos;
//	vector<int>presum(s.size());
//	for (int i = 1; i < n; i++) {
//		presum[i] = presum[i - 1];
//		if (s[i] == 't') {
//			pos.push_back(i);
//			presum[i]++;
//		}
//	}
//	double ans = 0;
//	for (int i = 0; i < pos.size(); i++) {
//		for (int j = i + 1; j < pos.size(); j++) {
//			if (pos[j] - pos[i]+1 < 3)continue;
//			else {
//				ans = max(ans, (1.0 * presum[pos[j]] - presum[pos[i]]-1) / (pos[j] - pos[i] - 1));
//			}
//		}
//	}
//	cout << fixed << setprecision(19) << ans << '\n';
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//signed main() {
//	int n, q;
//	cin >> n>>q;
//	vector<int>a(n + 1);
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		sum += a[i];
//	}
//	vector<int>sufsum(n + 2);
//
//	sort(a.begin() + 1, a.end());
//	for (int i = n; i>=1; i--) {
//		sufsum[i] = sufsum[i + 1] + a[i];
//	}
//
//	for (int i = 1,b; i <= q; i++) {
//		cin >> b;
//		auto it = lower_bound(a.begin() + 1, a.end(),b);
//		if (it == a.end()) {
//			cout << -1 << '\n';
//			continue;
//		}
//		int t = it - a.begin();
//		//cout <<sufsum[t]<<" "<<t<<" "<<b - 1 << " " << (n - t + 1) << "***\n";
//		cout << sum - sufsum[t] + (b - 1) * (n - t + 1)+1 << '\n';
//	}
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//signed main() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	int ans = 0;
//	int cntji = 0;
//	int cntou = 1;
//	int zero = 0;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] == '0') {
//			zero ^= 1;
//		}
//		if (zero == 1) {
//			ans+=cntji;
//			cntji++;
//		}
//		else {
//			ans += cntou;
//			cntou++;
//		}
//	}
//	cout << ans << '\n';
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//struct Point {
//	int x, y;
//};
//int gcd(int a, int b) {
//	while (b != 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//signed main() {
//	int n;
//	cin >> n;
//	vector<Point>a(n + 1);
//	map<array<int, 2>, int>mp;
//	map<array<int, 3>, int>mp1;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i].x >> a[i].y;
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			int dy = a[j].y - a[i].y;
//			int dx = a[j].x - a[i].x;
//			int g = gcd(dy, dx);
//			dy /= g;
//			dx /= g;
//			if (dy < 0) {
//				dy = -dy;
//				dx = -dx;
//			}
//			mp[{dx, dy}]++;
//			if (dx == 0) {
//				mp1[{dx, dy, dy* g}]++;
//			}
//			else if (dy==0) {
//				mp1[{dx, dy, dx* g}]++;
//			}
//			else mp1[{dx, dy, g}]++;
//
//		}
//	}
//	int ans = 0;
//	for (auto &p : mp) {
//		//cout << p.first[0] << " " << p.first[1] <<" "<<p.second<< '\n';
//		ans += p.second * (p.second - 1) / 2;
//	}
//	int tmp = 0;
//	for (auto& p : mp1) {
//		//cout << p.first[0] << " " << p.first[1] << " "<<p.first[2]<<" " << p.second << '\n';
//		tmp += p.second * (p.second - 1) / 2;
//	}
//	ans -= tmp / 2;
//	cout << ans << '\n';
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 998244353;
//const int N = 2e5 + 5;
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
//int finv[N];
//int fac[N];
//int C(int n, int m) {
//	return fac[n] * finv[m] % mod * finv[n - m] % mod;
//}
//void prepare() {
//	fac[0] = finv[0] = 1;
//	for (int i = 1; i < N; i++) {
//		fac[i] = fac[i - 1] * i % mod;
//	}
//	finv[N - 1] = qpow(fac[N - 1], mod - 2);
//	for (int i = N - 2; i >= 1; i--) {
//		finv[i] = finv[i + 1] * (i + 1) % mod;
//	}
//}
//int mn[N << 2];
//void up(int i) {
//	mn[i] = min(mn[i << 1], mn[i << 1 | 1]);
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		mn[i] = INT_MAX;
//		return;
//	}
//	int mid = l + r >> 1;
//	build(l, mid, i << 1);
//	build(mid + 1, r, i << 1 | 1);
//	up(i);
//}
//void change(int x, int v, int l, int r, int i) {
//	if (l == r) {
//		mn[i] = v;
//		return;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		change(x, v, l, mid, i << 1);
//	}
//	else {
//		change(x, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//int query(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return mn[i];
//	}
//	int mid = l + r >> 1;
//	int ans = INT_MAX;
//	if (jl <= mid) {
//		ans = min(ans, query(jl, jr, l, mid, i << 1));
//	}
//	if (jr > mid) {
//		ans = min(ans, query(jl, jr, mid + 1, r, i << 1 | 1));
//	}
//	return ans;
//}
//signed main() {
//	prepare();
//	int n, q;
//	cin >> n >> q;
//	for (int i = 0, id, val; i < q; i++) {
//		cin >> id >> val;
//	}
//	build(1,n,1);
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N=2e5 + 10;
//const int mod = 998244353;
//using mat = array<array<int, 2>, 2>;
//const mat unity = { array<int,2>{1,0},array<int,2>{0,1}};
//mat operator*(const mat& l, const mat& r) {
//	mat x = { array<int,2>{0,0},array<int,2>{0,0} };
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 2; j++) {
//			for (int k = 0; k < 2; k++) {
//				x[i][j] = (x[i][j] + l[i][k] * r[k][j] % mod)%mod;
//			}
//		}
//	}
//	return x;
//}
//mat mul[N << 2];
//void up(int i) {
//	mul[i] = mul[i << 1] * mul[i << 1 | 1];
//}
//void build(int l,int r,int i) {
//    if (l == r) {
//        mul[i] = unity;
//        return;
//    }
//    int mid = l + r >> 1;
//    build(l,mid, i << 1);
//    build(mid+1,r, i << 1|1);
//    up(i);
//}
//int noadj(int a, int b);
//void update(int x, int n, int v, int l, int r, int i) {
//	if (l == r) {
//		mat& a = mul[i];
//		a[0][0] = noadj(n - 1, v);
//		if (n == 1) {
//			a[0][1] = noadj(0, v - 1);
//		}
//		else {
//			a[0][1] = noadj(n - 2, v - 1);
//		}
//		if (n == 1) {
//			a[1][0] = noadj(0, v);
//		}
//		else {
//			a[1][0] = noadj(n - 2, v);
//		}
//		if (n == 1) {
//			a[1][1] = 0;
//		}
//		else if (n == 2) {
//			a[1][1] = noadj(0, v - 1);
//		}
//		else {
//			a[1][1] = noadj(n - 3, v - 1);
//		}
//		return;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		update(x, n, v, l, mid, i << 1);
//	}
//	else {
//		update(x, n, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//void update(int x, int l, int r, int i) {
//	if (l == r) {
//		mul[i] = unity;
//		return;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		update(x, l, mid, i << 1);
//	}
//	if (x > mid) {
//		update(x, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//
//}
//int fac[N];
//int finv[N];
//int fib[N];
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
//void prepare() {
//	fac[0] = finv[0] = 1;
//	for (int i = 1; i < N; i++) {
//		fac[i] = fac[i - 1] * i % mod;
//	}
//	finv[N - 1] = qpow(fac[N - 1], mod - 2);
//	for (int i = N - 2; i >= 1; i--) {
//		finv[i] = finv[i + 1] * (i + 1) % mod;
//	}
//	fib[0] = 1;
//	fib[1] = 2;
//	for (int i = 2; i < N; i++) {
//		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
//	}
//}
//int C(int n, int m) {
//	if (n < 0 || m < 0 || n < m)return 0;
//	return((fac[n] * finv[m]) % mod * finv[n - m]) % mod;
//}
//int noadj(int n, int r) {
//	if (n < r || r < 0)return 0;
//	return C(n + 1 - r, r);
//}
//map<int, int>stidx;
//signed main() {
//	prepare();
//	int n, q;
//	cin >> n >> q;
//	stidx.insert({ 0,0 });
//	stidx.insert({ n+1,0 });
//	build(1,n,1);
//	for (int i = 1,x,y; i <= q; i++) {
//		cin >> x >> y;
//		{
//			auto it = stidx.find(x);
//			if (it != stidx.end()) {
//				auto prev_it = prev(it);
//				int ilow = prev_it->first, vlow = prev_it->second;
//				auto next_it = next(it);
//				int ihigh = next_it->first, vhigh = next_it->second;
//
//				// 重置当前位置为单位矩阵
//				update(x,1,n,1);
//
//				// 更新右邻居的矩阵
//				if (ihigh <= n) {
//					update(ihigh, ihigh - ilow, vhigh - vlow,1,n,1);
//				}
//
//				stidx.erase(it);  // 从集合中删除
//			}
//			if (y != -1) {
//				stidx.insert({ x, y });
//				it = stidx.find(x);
//
//				// 找到左右邻居
//				auto prev_it = prev(it);
//				int ilow = prev_it->first, vlow = prev_it->second;
//				auto next_it = next(it);
//				int ihigh = next_it->first, vhigh = next_it->second;
//
//				// 更新当前位置的矩阵
//				update( x, x - ilow, y - vlow,1,n,1);
//
//				// 更新右邻居的矩阵
//				if (ihigh <= n) {
//					update(ihigh, ihigh - x, vhigh - y,1,n,1);
//				}
//			}
//			mat whole = mul[1];
//			int remain;
//			{
//				auto it = prev(stidx.find(n + 1));
//				int idx = (*it).first;
//				remain = n - idx;
//			}
//			if (remain >= N)remain - N - 1;
//			int ans = 0;
//			ans = (ans + whole[0][0] * fib[remain]%mod) % mod;
//			ans = (ans + whole[0][1] * fib[max(remain - 1, 0ll)]%mod) % mod;
//			cout << ans << '\n';
//		}
//	}
//}
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//
//const int N = 2e5 + 10;  // 扩大数组避免越界
//const int mod = 998244353;
//
//using mat = array<array<int, 2>, 2>;
//// 单位矩阵显式取模（虽然1和0不影响，但保持一致性）
//const mat unity = { array<int,2>{1 % mod, 0 % mod}, array<int,2>{0 % mod, 1 % mod} };
//
//// 矩阵乘法（确保每步取模，防止溢出）
//mat operator*(const mat& l, const mat& r) {
//	mat x = { array<int,2>{0, 0}, array<int,2>{0, 0} };
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 2; j++) {
//			for (int k = 0; k < 2; k++) {
//				x[i][j] = (x[i][j] + (l[i][k] * r[k][j]) % mod) % mod;
//			}
//		}
//	}
//	return x;
//}
//
//mat mul[N << 2];  // 线段树数组
//int fac[N], finv[N], fib[N];
//// 向上合并节点
//void up(int i) {
//	mul[i] = mul[i << 1] * mul[i << 1 | 1];
//}
//
//// 构建线段树
//void build(int l, int r, int i) {
//	if (l == r) {
//		mul[i] = unity;
//		return;
//	}
//	int mid = (l + r) >> 1;
//	build(l, mid, i << 1);
//	build(mid + 1, r, i << 1 | 1);
//	up(i);
//}
//
//// 计算组合数（添加中间取模，防止溢出）
//int C(int n, int m) {
//	if (n < 0 || m < 0 || n < m) return 0;
//	// 分步取模，避免中间结果溢出
//	int res = fac[n] * finv[m] % mod;
//	res = res * finv[n - m] % mod;
//	return res;
//}
//
//// 无相邻咖啡的方案数
//int noadj(int n, int r) {
//	if (n < r || r < 0) return 0;
//	return C(n + 1 - r, r);
//}
//
//// 函数名修改：明确区分更新矩阵和重置矩阵，避免重载冲突
//void update_matrix(int x, int n_len, int r_val, int l, int r, int i) {
//	if (l == r) {
//		mat& a = mul[i];
//		a[0][0] = noadj(n_len - 1, r_val) % mod;
//		if (n_len == 1) {
//			a[0][1] = noadj(0, r_val - 1) % mod;
//		}
//		else {
//			a[0][1] = noadj(n_len - 2, r_val - 1) % mod;
//		}
//		if (n_len == 1) {
//			a[1][0] = noadj(0, r_val) % mod;
//		}
//		else {
//			a[1][0] = noadj(n_len - 2, r_val) % mod;
//		}
//		if (n_len == 1) {
//			a[1][1] = 0 % mod;
//		}
//		else if (n_len == 2) {
//			a[1][1] = noadj(0, r_val - 1) % mod;
//		}
//		else {
//			a[1][1] = noadj(n_len - 3, r_val - 1) % mod;
//		}
//		return;
//	}
//	int mid = (l + r) >> 1;
//	if (x <= mid) {
//		update_matrix(x, n_len, r_val, l, mid, i << 1);
//	}
//	else {
//		update_matrix(x, n_len, r_val, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//
//// 重置矩阵为单位矩阵（独立函数名）
//void reset_matrix(int x, int l, int r, int i) {
//	if (l == r) {
//		mul[i] = unity;
//		return;
//	}
//	int mid = (l + r) >> 1;
//	if (x <= mid) {
//		reset_matrix(x, l, mid, i << 1);
//	}
//	else {
//		reset_matrix(x, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//
//
//
//// 快速幂（确保底数取模）
//int qpow(int a, int b) {
//	int ans = 1;
//	a %= mod;  // 底数先取模
//	while (b > 0) {
//		if (b & 1) ans = ans * a % mod;
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ans;
//}
//
//// 预处理（扩大范围，确保fib不越界）
//void prepare() {
//	// 阶乘与逆阶乘
//	fac[0] = finv[0] = 1;
//	for (int i = 1; i < N; i++) {
//		fac[i] = fac[i - 1] * i % mod;
//	}
//	finv[N - 1] = qpow(fac[N - 1], mod - 2);
//	for (int i = N - 2; i >= 0; i--) {  // 从0开始，确保finv[0]正确
//		finv[i] = finv[i + 1] * (i + 1) % mod;
//	}
//	// 斐波那契数列（扩大到N，避免越界）
//	fib[0] = 1;
//	fib[1] = 2;
//	for (int i = 2; i < N; i++) {
//		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
//	}
//}
//
//map<int, int> stidx;  // 存储特殊点 (位置, 值)
//
//signed main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	prepare();
//
//	int n, q;
//	cin >> n >> q;
//
//	// 初始化特殊点：左边界0，右边界n+1
//	stidx.insert({ 0, 0 });
//	stidx.insert({ n + 1, 0 });
//
//	// 构建线段树（1-based）
//	build(1, n, 1);
//
//	while (q--) {
//		int x, y;
//		cin >> x >> y;  // x是1-based位置
//
//		// 移除旧的特殊点（若存在）
//		auto it = stidx.find(x);
//		if (it != stidx.end()) {
//			auto prev_it = prev(it);  // 左侧邻居
//			int ilow = prev_it->first, vlow = prev_it->second;
//			auto next_it = next(it);  // 右侧邻居
//			int ihigh = next_it->first, vhigh = next_it->second;
//
//			// 重置当前位置为单位矩阵（使用明确函数名）
//			reset_matrix(x, 1, n, 1);
//
//			// 更新右侧邻居的矩阵
//			if (ihigh <= n) {
//				update_matrix(ihigh, ihigh - ilow, vhigh - vlow, 1, n, 1);
//			}
//
//			stidx.erase(it);  // 从集合中删除
//		}
//
//		// 添加新的特殊点（若y≠-1）
//		if (y != -1) {
//			stidx.insert({ x, y });
//			it = stidx.find(x);
//
//			auto prev_it = prev(it);  // 左侧邻居
//			int ilow = prev_it->first, vlow = prev_it->second;
//			auto next_it = next(it);  // 右侧邻居
//			int ihigh = next_it->first, vhigh = next_it->second;
//
//			// 更新当前位置的矩阵（使用明确函数名）
//			update_matrix(x, x - ilow, y - vlow, 1, n, 1);
//
//			// 更新右侧邻居的矩阵
//			if (ihigh <= n) {
//				update_matrix(ihigh, ihigh - x, vhigh - y, 1, n, 1);
//			}
//		}
//
//		// 计算答案
//		mat whole = mul[1];  // 线段树总乘积
//
//		// 找到最后一个特殊点
//		auto last_it = prev(stidx.find(n + 1));
//		int idx = last_it->first;
//		int remain = n - idx;
//
//		// 确保remain在fib数组范围内（防止越界）
//		if (remain >= N) remain = N - 1;  // 极端情况处理
//		int ans = 0;
//		ans = (ans + whole[0][0] * fib[remain]) % mod;
//		int rem1 = max(remain - 1, 0LL);
//		if (rem1 >= N) rem1 = N - 1;  // 极端情况处理
//		ans = (ans + whole[0][1] * fib[rem1]) % mod;
//
//		cout << ans << '\n';
//	}
//
//	return 0;
//}

