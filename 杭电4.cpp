//#include<bits/stdc++.h>
//using namespace std;
//int mp[100][100];
//const int mov = 20;
//void print(int i,int j,int id) {
//	mp[i][j]=id;
//	mp[i - 1][j]=id;
//	mp[i - 2][j]=id;
//	mp[i - 3][j]=id;
//	mp[i - 4][j]=id;
//	mp[i - 2][j - 1]=id;
//	mp[i - 3][j - 1]=id;
//	mp[i - 2][j - 2]=id;
//	mp[i - 2][j + 1]=id;
//	mp[i - 3][j + 1]=id;
//	mp[i - 2][j + 2]=id;
//}
//void solve() {
//	memset(mp, 0, sizeof(mp));
//	int n, m,k;
//	cin >> n >> m>>k;
//	vector<vector<int>>draw;
//	for (int i = 1, x, y; i <= k; i++) {
//		cin >> x >> y;
//		draw.push_back({x + mov, y + mov, i});
//	}
//	sort(draw.begin(), draw.end(), [&](auto a,auto b) {
//		return a[0] < b[0];
//		});
//	for (int i = 0; i < draw.size(); i++) {
//		print(draw[i][0], draw[i][1], draw[i][2]);
//	}
//	for (int i = mov + 1; i <= n+mov; i++) {
//		for (int j = mov + 1; j <= m + mov; j++) {
//			if (mp[i][j] == 0)cout << '.';
//			else cout << mp[i][j];
//		}
//		cout << endl;
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
//using namespace std;
//vector<vector<vector<int>>>d(4000,vector<vector<int>>(15,vector<int>(40)));
//int days[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
//void solve() {
//	int k, l, r;
//	cin >> k >> l >> r;
//	vector<int>date;
//	for (int i = 1; i <= 12; i++) {
//		for (int j = 1; j <= 31; j++) {
//			date.push_back(d[r][i][j] -d[l-1][i][j]);
//		}
//	}
//	sort(date.begin(), date.end(), [&](auto x,auto y) {
//		return x < y;
//		});
//	int ans = 0;
//	for (int i = 0; i < k; i++) {
//		ans += date[i];
//	}
//	cout << ans << endl;
//}
//void prepare() {
//	for (int i = 2025; i <= 2075; i++) {
//		for (int j = 1; j <= 12; j++) {
//			int da = j == 2 && i % 4 != 0 ? 28 : days[j];
//			for (int k = 1; k <= da; k++) {
//				int w = (k + 2 * j + 3 * (j + 1) / 5 + i + i / 4 - i / 100 + i / 400) % 7;
//				d[i][j][k] = d[i - 1][j][k]+(w!=6&&w!=7);
//			}
//		}
//	}
//}
//int main() {
//	prepare();
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//int gcd(int a, int b) {
//	while (b != 0) {
//		int temp = b;
//		b = a % b;
//		a = temp;
//	}
//	return a;
//}
//void solve() {
//	int k, n, a, b, c, d;
//	cin >> k >> n >> a >> b >> c >> d;
//	int mo = -1;
//	if (a * n > b * k) {//l>s
//		int g2 = gcd(c, d);
//		cout << c/g2 << '/' << d/g2 << endl;
//		return;
//	}
//	int l = 1, r = (k / n) * (b / a)+2;
//	int bei = -1;
//	while (l <= r) {
//		int mid = l + r >> 1;
//		if (mid * n * c >= k * d) {
//			mo = mid * n;
//			bei = mid;
//			r = mid - 1;
//		}
//		else l = mid + 1;
//	}
//	int nm = d, ns = c;int nei = (int)(double(k) / ((double(c) / d) * n))*100;
//	if (mo*a>k*b) {
//		int g1 = gcd(ns * nei, nm);
//		cout << ns * nei / g1 << "/" << nm / g1 << endl;
//		return;
//	}
//	int am = k * (1 + bei), as = mo;
//	int g = gcd(am, as);
//	if (ns * nei * as > am * nm) {
//		int g1 = gcd(ns * nei, nm);
//		cout << ns * nei / g1 << "/" << nm / g1<< endl;
//	}
//	else cout << am / g << "/" << as / g << endl;
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
//	int n, k;
//	cin >> n >> k;
//	vector<array<int,p>>
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//矩形框选
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e4+5;
//int ma[N<<2];//记录所有高度为h的区间内点的和的最大值
//int lzt[N << 2];//lazy tag 增加多少
//void up(int i) {
//	ma[i] = max(ma[i << 1], ma[i << 1 | 1]);
//}
//void lazy(int i, int v) {
//	ma[i] += v;
//	lzt[i] += v;
//}
//void down(int i) {
//	if (lzt[i] != 0) {
//		lazy(i << 1, lzt[i]);
//		lazy(i << 1 | 1, lzt[i]);
//		lzt[i] = 0;
//	}
//}
//void change(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v);
//		return;
//	}
//	int mid = l + r >> 1;
//	down(i);
//	if (jl <= mid) {
//		change(jl, jr, v, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		change(jl, jr, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//void build(int l, int r, int i) {
//	memset(ma, 0, sizeof(ma));
//	memset(lzt, 0, sizeof(lzt));
//}
//int x[N],y[N],v[N];
//vector<vector<array<int, 3>>>ev;
//void solve() {
//	int n, S;
//	cin >> n >> S;
//	ev.assign(n + 2, {});
//	for (int i = 1; i <= n; i++) {
//		cin >> x[i] >> y[i] >> v[i];
//	}
//	int ans = 0;
//	for (int w = 1; w * w <= S; w++) {
//		int h = S / w;
//		//加入所有事件
//		ev.assign(n + 2, {});
//		for (int i = 1; i <= n; i++) {
//			int L = max(1,x[i] - w+1);
//			int yL = max(1,y[i] - h+1);
//			int yR = y[i];
//			ev[L].push_back({yL,yR,v[i]});
//			ev[x[i]+1].push_back({yL,yR,-v[i]});
//		}
//		build(1, n, 1);
//		for (int i = 1; i <= n; i++) {
//			for (auto [l, r, v] : ev[i]) {
//				change(l, r, v, 1, n, 1);
//			}
//			ans = max(ans, ma[1]);
//		}
//	}
//
//	for (int h = 1; h * h <= S; h++) {
//		int w = S / h;
//		ev.assign(n + 2, {});
//		for (int i = 1; i <= n; i++) {
//			int L = max(1, x[i] - w+1);
//			int yL = max(1,y[i] - h+1);
//			int yR = y[i];
//			ev[L].push_back({ yL,yR,v[i] });
//			ev[x[i] + 1].push_back({ yL,yR,-v[i] });
//		}
//		build(1, n, 1);
//		for (int i = 1; i <= n; i++) {
//			for (auto [l, r, v] : ev[i]) {
//				change(l, r, v, 1, n, 1);
//			}
//			ans = max(ans, ma[1]);
//		}
//	}
//	cout << ans << endl;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int gcd(int a,int b) {
//	while (b != 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//void solve() {
//	int k, n, a, b, c, d;
//	cin >> k >> n >> a >> b >> c >> d;
//	int num1 = c, den1 = d;
//	int y1 = k *d/ (c  * n) + 1;
//	int num2 = k, den2 = n * y1;
//	int y2 = y1 + 1;
//	if (num1 * y1 * den2 > num2 * y2 * den1||k*b<n*y1*a) {
//		int g = gcd(num1 * y1, den1);
//		cout << num1 * y1 / g << "/" << den1 / g << endl;
//	}
//	else {
//		int g = gcd(num2 * y2, den2);
//		cout << num2 * y2 / g << "/" << den2 / g << endl;
//	}
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
//const int N = 1e5 + 10;
//int q[N];
//int r[N];
//int s[N];
//void solve() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> q[i] >> r[i] >> s[i];
//	}
//
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}