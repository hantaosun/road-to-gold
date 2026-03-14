//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	bool ok = 1;
//	int last = -1;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		if (a[i] == -1)continue;
//		if (last == -1 && a[i] != -1) {
//			last = a[i];
//			continue;
//		}
//		if (a[i] != last) {
//			ok = 0;
//		}
//	}
//	if (ok&&last!=0) {
//		cout << "YES\n";
//	}
//	else cout << "NO\n";
//		
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
//	int n, x;
//	cin >> n >> x;
//	string s;
//	cin >> s;
//	s = " " + s;
//	if (x == 1 || x == n) {
//		cout << 1 << endl;
//		return;
//	}
//	int r = 0, l = 0;
//	for (r = x; r<= n; r++) {
//		if (s[r] == '#') {
//			break;
//		}
//	}
//	for (l = x; l>=1; l--) {
//		if (s[l] == '#') {
//			break;
//		}
//	}
//	cout << min({ x,n - x + 1,max(l + 1, n - r + 2)}) << endl;
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
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	vector<array<int,3>>p(n + 1);
//	int ans = 0;
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//		p[i][0] = a[i] + b[i];
//		p[i][1] = a[i] - b[i];
//		p[i][2] = i;
//		sum += abs(a[i] - b[i]);
//	}
//	int minDis = INT_MAX;
//	int ni, nj;
//	sort(p.begin()+1, p.end(), [&](auto x,auto y) {
//		return x[0] < y[0];
//		});
//	for (int i = 1; i < n; i++) {
//		int ci = p[i][2];
//		int cj = p[i + 1][2];
//		if (abs(a[ci] - a[cj])+abs(b[ci]-b[cj]) < minDis) {
//			minDis = abs(a[ci] - a[cj]) + abs(b[ci] - b[cj]);
//			ni = ci;
//			nj = cj;
//		}
//	}
//	sort(p.begin()+1, p.end(), [&](auto x,auto y) {
//		return x[1] < y[1];
//		});
//	for (int i = 1; i < n; i++) {
//		int ci = p[i][2];
//		int cj = p[i + 1][2];
//		if (abs(a[ci] - a[cj]) + abs(b[ci] - b[cj]) < minDis) {
//			minDis = abs(a[ci] - a[cj]) + abs(b[ci] - b[cj]);
//			ni = ci;
//			nj = cj;
//		}
//	}
//	//cout << ni << " " << nj << endl;
//	ans += max(abs(a[ni] - b[ni]) + abs(a[nj] - b[nj]), minDis);
//	for (int i = 1; i <= n; i++) {
//		if (i != ni && i != nj) {
//			ans += abs(a[i] - b[i]);
//		}
//	}
//	cout << max(ans,sum) << endl;
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}
// 
// 
// 
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	vector<array<int, 2>>c(n + 1);
//	vector<array<int, 2>>d(n + 1);
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	int mi = LLONG_MAX;
//	int ni, nj;
//	for (int i = 1; i <= n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			if (mi < max({}))
//		}
//	}
//	ans += max(mi, abs(a[ni] - b[ni]) + abs(a[nj] - b[nj]));
//	for (int i = 1; i <= n; i++) {
//		if (i == ni || i == nj)continue;
//		ans += abs(a[i] - b[i]);
//	}
//	cout << ans << endl;
//}
//signed main() {
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
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//		if (a[i] < b[i])swap(a[i], b[i]);
//	}
//	vector<int>idx(n + 1);
//	iota(idx.begin(), idx.end(), 0);
//	sort(idx.begin(), idx.end(), [&](int x, int y) {return b[x] < b[y]; });
//	int mi = INT_MAX;
//	int ni, nj;
//	for (int i = 1; i < n; i++) {
//		int id = idx[i];
//		int id1 = idx[i + 1];
//		if (abs(a[id] - b[id1]) + abs(a[id1] - b[id]) - (abs(a[id] - b[id]) + abs(a[id1] - b[id1])) < mi) {
//			mi = abs(a[id] - b[id1]) + abs(a[id1] - b[id]) - (abs(a[id] - b[id]) + abs(a[id1] - b[id1]));
//			ni = id;
//			nj = id1;
//		}
//	}
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		sum += abs(a[i] - b[i]);
//	}
//	if (mi < 0) {
//		cout << sum << endl;
//	}
//	else {
//		cout << sum + mi << endl;
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
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	for(int i)
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//struct Point {
//    int x, y, idx;
//};
//
//int manhattan(const Point& p1, const Point& p2) {
//    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
//}
//
//pair<int, int> findMinPair(const vector<Point>& points) {
//    int n = points.size();
//    if (n < 2) return { -1, -1 };
//
//    int min_dist = INT_MAX;
//    pair<int, int> best;
//
//    // 按x + y排序，检查相邻点
//    vector<Point> sorted_s = points;
//    sort(sorted_s.begin(), sorted_s.end(), [](const Point& a, const Point& b) {
//        return (a.x + a.y) < (b.x + b.y);
//        });
//    for (int i = 0; i < n - 1; i++) {
//        int d = manhattan(sorted_s[i], sorted_s[i + 1]);
//        if (d < min_dist) {
//            min_dist = d;
//            best = { sorted_s[i].idx, sorted_s[i + 1].idx };
//        }
//    }
//
//    // 按x - y排序，检查相邻点
//    vector<Point> sorted_d = points;
//    sort(sorted_d.begin(), sorted_d.end(), [](const Point& a, const Point& b) {
//        return (a.x - a.y) < (b.x - b.y);
//        });
//    for (int i = 0; i < n - 1; i++) {
//        int d = manhattan(sorted_d[i], sorted_d[i + 1]);
//        if (d < min_dist) {
//            min_dist = d;
//            best = { sorted_d[i].idx, sorted_d[i + 1].idx };
//        }
//    }
//
//    return best;
//}
//
//void solve() {
//    int n, k;
//    cin >> n >> k;
//    vector<Point> points(n);
//    for (int i = 0; i < n; i++) {
//        cin >> points[i].x;
//        points[i].idx = i + 1; // 保持1-based索引
//    }
//    for (int i = 0; i < n; i++) {
//        cin >> points[i].y;
//    }
//
//    // 寻找最小曼哈顿距离的点对
//    auto [ni, nj] = findMinPair(points);
//    if (ni > nj) swap(ni, nj); // 确保i < j
//
//    // 计算结果（注：此逻辑仅为示例，需根据题目实际规则调整）
//    int original = abs(points[ni - 1].x - points[ni - 1].y) + abs(points[nj - 1].x - points[nj - 1].y);
//    int min_dist = manhattan(points[ni - 1], points[nj - 1]);
//    int pair_contribution = max(min_dist, original);
//
//    int ans = pair_contribution;
//    for (int i = 1; i <= n; i++) {
//        if (i == ni || i == nj) continue;
//        ans += abs(points[i - 1].x - points[i - 1].y);
//    }
//
//    cout << ans << endl;
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int t;
//    cin >> t;
//    while (t--) {
//        solve();
//    }
//    return 0;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//		if (a[i] > b[i])swap(a[i], b[i]);
//		sum += abs(a[i] - b[i]);
//	}
//	vector<int>idx(n+1);
//	iota(idx.begin(), idx.end(),0);
//	sort(idx.begin(), idx.end(), [&](int x,int y) {
//		return b[x] < b[y];
//		});
//	int r = b[idx[1]];
//	int minDiff = INT_MAX;
//	for (int i = 2; i <= n; i++) {
//		int cur = idx[i];
//		if (a[cur] < r) {
//			cout << sum << endl;
//			return;
//		}
//		else{
//			minDiff = min(minDiff,a[cur] - r);
//			r = b[cur];
//		}
//	}
//	cout << sum + 2 * minDiff << endl;
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define i64 long long
//using namespace std;
//const int N = 2e5 + 1;
//const int mod = 1e9 + 7;
//i64 fac[N];
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>g(n + 1);
//	for (int i = 1, u, v; i <= m; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	if (m != n - 1) {
//		cout << 0 << '\n';
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (g[i].size() > 2) {
//			int cnt = 0;
//			for (auto v : g[i]) {
//				if (g[v].size() >= 2)cnt++;
//			}
//			if (cnt > 2) {
//				cout << 0 << '\n';
//				return;
//			}
//		}
//	}
//	vector<int>collect;
//	for (int i = 1; i <= n; i++) {
//		if (g[i].size() >= 2) {
//			collect.push_back(i);
//		}
//	}
//	if (collect.empty()) {
//		cout << 2 << '\n';
//		return;
//	}
//	if (collect.size() == 1) {
//		cout << fac[n - 1] * 2 % mod << '\n';
//		return;
//	}
//	if (collect.size() == 2) {
//		cout << fac[g[collect[0]].size() - 1] * fac[g[collect[1]].size() - 1] % mod * 4 % mod<<'\n';
//		return;
//	}
//	i64 ans = 1;
//	for (auto v : collect) {
//		int cnt = 0;
//		for (auto p : g[v]) {
//			if (g[p].size() == 1) {
//				cnt++;
//			}
//		}
//		ans = ans*fac[cnt]%mod;
//	}
//	cout << ans * 4 % mod << '\n';
//}
//void prepare() {
//	fac[0] = 1;
//	for (int i = 1; i <= 200000; i++) {
//		fac[i] = fac[i - 1] * i%mod;
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