//E
//一般的试除法会超时
//#include<bits/stdc++.h>
//#include<unordered_map>
//using namespace std;
//const int MAXN = 5e6 + 10;
//unordered_map<int, int>cont;
//int spf[MAXN];
//int cnt = 0;
//void SPF() {
//	for (int i = 1; i <= MAXN; i++) {
//		spf[i] = i;
//	}
//	for (int i = 2; i * i < MAXN; ++i) {
//		if (spf[i] == i) {
//			for (int j = i; j * i < MAXN; j++) {
//				if (spf[i * j] == i * j) {
//					spf[i * j] = i;
//				}
//			}
//		}
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	cont.clear();
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	if (n == 2) {
//		cout << (a[1] == a[2] ? "YES\n" : "NO\n");
//		return;
//	}
//	if (n % 2) {
//		cout << "YES\n";
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		while (a[i] > 1) {
//			cont[spf[a[i]]]^=1;
//			a[i] /= spf[a[i]];
//		}
//	}
//	for (auto p : cont) {
//		if (p.second) {
//			cout << "NO\n";
//			return;
//		}
//	}
//	cout << "YES\n";
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	SPF();
//	while (t--) {
//		solve();
//	}
//}

//哈希法
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 5e6 + 10;
//int ha[MAXN];
//bool visi[MAXN];
//int prime[MAXN];
//void eular() {
//	int cnt = 0;
//	mt19937_64 rnd(time(0));
//	for (int i = 2; i < MAXN; i++) {
//		if (!visi[i]) {
//			prime[cnt++] = i;
//			ha[i] = rnd();
//		}
//		for (int j = 0; j < cnt; j++) {
//			if (i * prime[j] >= MAXN) {
//				break;
//			}
//			visi[i * prime[j]] = 1;
//			ha[i * prime[j]] = ha[i] ^ ha[prime[j]];
//			if (!(i % prime[j]))break;
//		}
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	if (n & 1) {
//		cout << "YES\n";
//		return;
//	}
//	if (n == 2) {
//		cout << (a[1] == a[2] ? "YES\n" : "NO\n");
//		return;
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		ans ^= ha[a[i]];
//	}
//	if (ans == 0)cout << "YES\n";
//	else cout << "NO\n";
//}
//int main() {
//	int t;
//	cin >> t;
//	eular();
//	while (t--) {
//		solve();
//	}
//}


////J
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int x, y;
//	cin >> x >> y;
//	int round = 0;
//	while (x != 0&&y!=0) {
//		if (x >= y) {
//			x -= y;
//			y += y;
//		}
//		else {
//			y -= x;
//			x += x;
//		}
//		round++;
//		if (round >= 50) {
//			cout << -1 << endl;
//			return;
//		}
//	}
//	cout << round << endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//A
//#include<bits/stdc++.h>
//#define pii pair<int,int>
//#define mkp make_pair
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<pii>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i].first;
//		a[i].second = i;
//	}
//	sort(a.begin()+1, a.end());
//	//for (int i = 1; i <= n; i++)cout << a[i].first << " "; cout << endl;
//	vector<int>b(n + 1);
//	vector<int>visi(n + 1,0);
//	for (int i = 1; i <= n; i++) {
//		visi[a[i].first] = 1;
//		if (a[i].first != a[i - 1].first) {
//			b[i] = a[i-1].first ;
//		}
//		else b[i] = -1;
//	}
//	//for (int i = 1; i <= n; i++)cout << visi[i] << " "; cout << endl;
//	int cur = 1;
//	for (int i = 1; i <= n; i++) {
//		if (b[i] == -1) {
//			while (visi[cur]) {
//				cur++;
//			}
//			b[i] = cur;
//			visi[cur] = 1;
//		}
//	}
//	vector<vector<int>>grid(n + 1, vector<int>(n + 1));
//	vector<vector<int>>ans(n + 1, vector<int>(n + 1));
//	//for (int i = 1; i <= n; i++)cout << b[i] << " "; cout << endl;
//	for (int i = 1; i <= n; i++) {
//		for (int j = i; j <= n; j++) {
//			//grid[i][j] = b[i];
//			//grid[j][i] = b[i];
//			grid[a[i].second][a[j].second] = b[i];//注意行和列都要对应回原坐标
//			grid[a[j].second][a[i].second] = b[i];
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << grid[i][j] << " ";
//		}
//		cout << "\n";
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//H
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 1e6 + 10;
//int pwr;
//int log2(int x) {
//	int ans = 0;
//	while (((int)(1) << ans) <= (x >> 1)) {
//		ans++;
//	}
//	return ans;
//}
//int n, k;
//int st[MAXN][22];
//int dep[MAXN];
//bool arrive[MAXN];
//vector<vector<int>>son;
//void dfs(int u, int fa) {
//	dep[u] = dep[fa] + 1;
//	for (int i = 0; i < son[u].size(); i++) {
//		if (son[u][i] == fa)continue;
//		dfs(son[u][i], u);
//	}
//}
//signed main() {
//	cin >> n >> k;
//	st[1][0] = 1;
//	pwr = log2(n);
//	son.resize(n + 1, {});
//	arrive[1] = 1;
//	int ans = INT_MAX;
//	st[1][0] = 1;
//	for (int i = 2; i <= n; i++) {
//		cin >> st[i][0];
//		son[st[i][0]].push_back(i);
//	}
//	for (int p = 1; p <= pwr; p++) {
//		for (int i = 1; i <= n; i++) {
//			st[i][p] = st[st[i][p - 1]][p - 1];
//		}
//	}
//	dfs(1, 1);
//	bool flag = 0;
//	for (int o = 1, u, l, r; o <= k; o++) {
//		cin >> u >> l >> r;
//		if (flag)continue;
//		if (arrive[u]) {
//			ans = min(ans, l);
//			flag = 1;
//			continue;
//		}
//		//cout << u << " " << l << " " << r << "***\n";
//		int v = u;
//		//让v向上跳到最近的可arrive节点
//		for (int p = pwr; p >= 0; p--) {
//			if (!arrive[st[v][p]]) {
//				v = st[v][p];
//			}
//		}
//		v = st[v][0];
//
//
//		int diff = dep[u] - dep[v];//u需要跳几步到达v
//
//		//让b跳到离v(r-l+1)步的距离 即向上跳diff-(r-l+1)步
//		int b = u;
//		//cout << u << " " << v << " " << b << " " << diff << " " << diff - (r - l + 1) << endl;
////         for(int p=pwr;p>=0;p--){
////             if(dep[st[b][p]]-dep[v]>=r-l+1){
////                 b=st[b][p];
////             }
////         }
//		for (int p = log2(diff - (r - l + 1)), t = 0; p >= 0; p--) {
//			if (t + ((int)(1) << p) <= diff - (r - l + 1)) {
//				b = st[b][p];
//				t += ((int)(1) << p);//t记录跳了几步了
//			}
//		}
//
//		//cout << u << " " << v << " " << b << " " << diff << " " << diff - (r - l + 1) << endl;
//		//标记
//		while (b != v) {
//			arrive[b] = 1;
//			b = st[b][0];
//		}
//
//		//更新ans
//		if (arrive[u]) {
//			ans = min(ans, l + dep[u] - dep[v] - 1);
//			flag = 1;
//		}
//
//
//	}
//	cout << (ans == INT_MAX ? -1 : ans) << endl;
//}


//B
//#include<bits/stdc++.h>
//using namespace std;
//int highzero(int x) {
//	if (x == 0)return 0;//一定要返回0不知道为什么 1 0 0可能吧
//	int cnt = 1;
//	while (x >> 1 != 0) {
//		cnt++;
//		x >>= 1;
//	}
//	return cnt;
//}
//vector<int>opt;
//void f(int x) {
//	opt.push_back(x);
//}
//void solve() {
//	int a, b, c;
//	cin >> a >> b >> c;
//	if (a == 0 && b == 0) {
//		if (c == 0) {
//			cout << "0\n";
//		}
//		else {
//			cout << "-1\n";
//		}
//		return;
//	}
//	if (a == b && b == c) {
//		cout << "0\n";
//		return;
//	}
//	opt.clear();
//	int ha = highzero(a), hb = highzero(b), hc = highzero(c);
//	//cout << ha << " " << hb << " " << hc << endl;
//	if (ha < hb) {
//		a = a ^ b; f(3);
//		ha = hb;
//	}
//	else if (hb < ha) {
//		b = a ^ b; f(4);
//		hb = ha;
//	}
//	//cout << ha << " " << hb << " " << hc << endl;
//	if (hc >= ha) {
//		int cur = 1;//当前比的是a与c高位往后的第几位
//		while (ha < hc) {
//			//cout << bitset<32>(a) << " " << bitset<32>(b) << " " << bitset<32>(c) << "$" << endl;
//			//cout << (a >> (ha - cur)) << " " << (c >> (hc - cur)) << endl;
//			if (((a >> (ha - cur)) ^ (c >> (hc - cur))) != 0) {
//				a = a ^ b; f(3);
//			}
//			a <<= 1; f(1);
//			ha++;
//			cur++;
//		}
//		while (hb != 0) {
//			//cout << bitset<32>(a) << " " << bitset<32>(b) << " " << bitset<32>(c) << "#" << endl;
//			if (((a >> (ha - cur)) ^ (c >> (hc - cur))) != 0) {
//				a = a ^ b; f(3);
//			}
//			b >>= 1; f(2);
//			hb--;
//			cur++;
//		}
//		b = b ^ a; f(4);
//		//cout << bitset<32>(a) << " " << bitset<32>(b) << " " << bitset<32>(c) << endl;
//	}
//	else {
//		int cur = ha - 1;
//		while (cur >= 0) {
//			if (((a >> cur) ^ (c >> cur)) != 0) {
//				a = a ^ b; f(3);
//			}
//			b >>= 1; f(2);
//			cur--;
//			//cout << bitset<32>(a) << " " << bitset<32>(b) << " " << bitset<32>(c) << endl;
//		}
//		b = b ^ a; f(4);
//		//cout << bitset<32>(a) << " " << bitset<32>(b) << " " << bitset<32>(c) << endl;
//	}
//	cout << opt.size() << endl;
//	for (int i = 0; i < opt.size(); i++) {
//		cout << opt[i] << " ";
//	}cout << endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}