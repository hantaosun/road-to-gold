//#include<bits/stdc++.h>
//using namespace std;
//int gcd(int a, int b) {
//	if (a == 0 || b == 0)return 1;
//	while (b != 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//bool judege(int mx, int mn) {
//	return mx -2*mn<=2;
//}
//void solve() {
//	int a, b, c,d;
//	cin >> a >> b >> c >> d;
//	if (judege(max(a,b), min(a,b)) && judege(max(c-a,d-b), min(c-a,d-b))) {
//		cout << "YES\n";
//	}
//	else {
//		cout << "NO\n";
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
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	string s;
//	cin >> s;
//	int mx1 = 0;
//	int one = 0;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] == '1') {
//			one++;
//			mx1 = max(mx1, one);
//		}
//		else {
//			one = 0;
//		}
//	}
//	if (mx1 >= k) {
//		cout << "NO\n";
//		return;
//	}
//	else {
//		cout << "Yes\n";
//	}
//	int r = n, l = 1;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] == '1') {
//			cout << l << " ";
//			l++;
//		}
//		else {
//			cout << r << " ";
//			r--;
//		}
//	}cout << '\n';
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
//
//void solve() {
//	int n;
//	cin >> n ;
//	vector<int>a(n + 1);
//	vector<int>cont(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	vector<vector<int>>pos(n + 1);
//	vector<int>dp(n + 1,0);//必须要以i位置结尾的整洁子序列长度
//	for (int i = 1; i <= n; i++) {
//		pos[a[i]].emplace_back(i);
//		cont[a[i]]++;
//		if (cont[a[i]] < a[i]||a[i]>i) {
//			dp[i] = 0;
//		}
//		else {
//			dp[i] = a[i] + dp[pos[a[i]][pos[a[i]].size() - a[i]]-1];
//		}
//		dp[i] = max(dp[i], dp[i - 1]);
//	}
//	cout << dp[n] << '\n';
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
//struct Point {
//	int x, y;
//};
//const int N = 1e9;
//int ask(char c, int step) {
//	cout << "? " << c << " " << step << endl;
//	int t;
//	cin >> t;
//	return t;
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<Point>p(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i].x >> p[i].y;
//	}
//	ask('R', N);
//	ask('R', N);
//	ask('D', N);
//	ask('D', N);
//	int v=ask('D', N);
//	ask('U', N);
//	ask('U', N);
//	ask('U', N);
//	ask('U', N);
//	int w=ask('U', N);
//	sort(p.begin() + 1, p.end(), [&](Point x, Point y) {
//		return x.y - x.x < y.y - y.x;
//		});
//	int a = p[1].x;
//	int b = p[1].y;
//	sort(p.begin() + 1, p.end(), [&](Point x, Point y) {
//		return x.x + x.y > y.x + y.y;
//		});
//	int c = p[1].x;
//	int d = p[1].y;
//	cout << "! " << (a + v-5*N - b + w + c + d-4*N) / 2 << " " << (w + c + d-4*N - a - v + b+5*N) / 2 << endl;
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
//const int mod = 998244353;
//const int N = 2e5 + 5;
//const int M = 4e5 + 5;
//int head[N];
//int nex[M<<1];
//int to[M<<1];
//int w[N];
//int ide[N];
//int box[N];
//int l, r;
//int cnt = 1;
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//void solve() {
//	int n, m, V;
//	cin >> n >> m >> V;
//	memset(ide, 0, sizeof(int) * (n + 5));
//	memset(head, 0, sizeof(int) * (n + 5));
//	memset(w, 0, sizeof(int) * (n + 5));
//	cnt = 1;
//	for (int i = 1; i <= n; i++) {
//		cin >> w[i];
//	}
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		ide[u]++;
//		ide[v]++;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	l = 0, r = 0;
//	for (int i = 1; i <= n; i++) {
//		if (ide[i] == 1) {
//			box[r++] = i;
//		}
//	}
//	int ans = 1;
//	while (l != r) {
//		int u = box[l++];
//		if (w[u] == -1) {
//			ans = ans * V % mod;
//		}
//		for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//			if (--ide[to[ui]] == 1) {
//				box[r++] = to[ui];
//			}
//		}
//	}
//	cout << ans << '\n';
//
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
//const int N = 1e5;
//void solve() {
//	int tmp;
//	cout << "? "<<N<<" ";
//	for (int i = 1; i <= N; i++) {
//		cout << 1 << ' ';
//	}
//	cout << endl;
//	cin >> tmp;
//	int lo = (N + tmp - 1) / tmp;
//	tmp--;
//	int hi;
//	if (tmp == 0) {
//		hi = N;
//	}
//	else hi=(N + tmp - 1) / tmp-1;
//	if (hi == lo) {
//		cout << "! " << lo << endl;
//		return;
//	}
//	cout << "? " << (hi - lo) *2<< " ";
//	for (int i = lo + 1; i <= hi; i++) {
//		cout << lo << " " << i - lo<<" ";
//	}
//	cout << endl;
//	cin >> tmp;
//	cout << "! "<<2*hi-lo-tmp << endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


