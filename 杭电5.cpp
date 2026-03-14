//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	map<int, int>mp;
//	map<int, int >mp1;
//	for (int i = 1,u; i <= m; i++) {
//		cin >> u;
//		mp[u]++;
//		if (!mp1.count(u)) {
//			mp1[u] = i;
//		}
//	}
//	vector<pair<int,int>>a;
//	vector<pair<int,int>>b;
//	for (auto p : mp) {
//		a.push_back(p);
//	}
//	for (auto p : mp1) {
//		b.push_back(p);
//	}
//	sort(a.begin(), a.end(), [&](auto x,auto y) {
//		if (x.second == y.second)return x.first < y.first;
//		return x.second > y.second;
//		});
//	sort(b.begin(), b.end(), [&](auto x,auto y) {
//		if (x.second == y.second)return x.first < y.first;
//		return x.second < y.second;
//		});
//	int ans = 0;
//	for (int i = 0; i < a.size(); i++) {
//		if (a[i].first != b[i].first) {
//			ans++;
//		}
//	}
//	cout << ans << '\n';
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
//int cnt[10];
//void solve() {
//	for (int i = 0; i < 10; i++) {
//		cin >> cnt[i];
//	}
//	int ans = cnt[0] + cnt[4]+cnt[8];
//	int odd = cnt[1] + cnt[3] + cnt[5]+cnt[7];
//	int sn = cnt[6] + cnt[9];
//	if (odd  > sn+cnt[2]) {//69全当偶数
//		ans += cnt[2] + sn;
//	}
//	else if(cnt[2] > odd + sn){//全当奇数
//		ans += odd + sn;
//	}
//	else {//可以补平
//		ans += (odd + sn + cnt[2]) / 2;
//	}
//	cout << ans << '\n';
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//manacher算法模板
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 100000;
//int p[MAXN<<1];
//string ss;
//vector<int>kuo;
//void manacherss(string s) {
//	ss.resize(2 * s.size() + 1);
//	for (int i = 0,j=0; i < 2*s.size()+1; i++) {
//		ss[i] = i & 1 ? s[j++] : '#';
//	}
//}
//void manacher(string s) {
//	manacherss(s);
//	int n = s.size()*2+1;
//	//cout << ss << '\n';
//	int ans = 0;
//	for (int i = 0; i < ss.size() - 1; i++) {
//		if (ss[i] == '(' && ss[i + 2] == ')') {
//			kuo.push_back(i);
//		}
//	}
//	//for (auto v : kuo) {
//	//	cout << v << " ";
//	//}cout << '\n';
//	for (int i = 0, c = 0, r = 0, len; i < n; i++) {
//		len = r > i ? min(p[2 * c - i], r - i):1;//被包住则初始长度取决于关于中心位置对称的点的对称半径,否则则是单个字符为1
//		while (i + len < n && i - len >= 0 && ss[i + len] == ss[i - len]) {
//			len++;
//		}
//		if (i + len > r) {
//			r = i+len;
//			c = i;
//		}
//		//cout << i<<" "<< len << endl;
//		auto rs = lower_bound(kuo.begin(), kuo.end(), i);
//		int rLen = rs == kuo.end() ? INT_MAX : min(len,*rs + 1-i);
//		int lt = rs - kuo.begin() - 1;
//		int lLen;
//		if (lt < 0)lLen = INT_MAX;
//		else {
//			lLen = min(len, i - kuo[lt]);
//		}
//		//cout <<i<<" "<< lLen << " " << rLen << '\n';
//		ans += max(0ll, (len - min(lLen, rLen)) / 2);
//		//cout << ans << '\n';
//		p[i] = len;
//	}
//	cout << ans << '\n';
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	string s;
//	cin >> s;
//
//	manacher(s);
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 998244353;
//int qpow(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a;
//		}
//		b >>= 1;
//		a = a * a;
//	}
//	return ans;
//}
//int d, x, y, px, py;
//void exgcd(int a, int b) {
//	if (b == 0) {
//		d = a;
//		x = 1;
//		y= 0;
//	}
//	else {
//		exgcd(b, a%b);
//		px = x;
//		py = y;
//		x = py;
//		y = px - a / b * px;
//	}
//}
//void solve() {
//	int p;
//	cin >> p;
//	int ans = 0;
//	for (int i = 0; i <= p - 1; i++) {
//		exgcd(i, p);
//		int k = (p + 118) / 119;
//		ans =ans^(x+qpow(2, k)) * (i + qpow(4, k));
//	}
//	cout << ans << endl;
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}
//1
//5
//1 0 0 0 0
//1 1 1 1 1
//2 3 4 5 2

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 5e5 + 5;
////int fa[N];
////int tag[N];//当前集合有无非0数
////int siz[N];//当前集合大小
////int find(int x) {
////	while (fa[x] != x) {
////		fa[x] = fa[fa[x]];
////	}
////	return fa[x];
////}
////void build(int n) {
////	for (int i = 0; i <= n; i++) {
////		fa[i] = i;
////		siz[i] = 1;
////	}
////}
////void Union(int x, int y) {
////	int fx = find(x);
////	int fy = find(y);
////	fa[fx] = fa[fy];
////	siz[fy] += siz[fx];
////}
//int ans = 0;
//void dfs(int u, vector<int>& vis, vector<vector<int>>& g, vector<int>& ide) {
//	ans++;
//	vis[u] = 1;
//	for (int i = 0; i < g[u].size(); i++) {
//		int cur = g[u][i];
//		if (!vis[cur] && ide[cur] != 0) {
//			dfs(cur, vis, g, ide);
//		}
//	}
//}
//vector<int>a;
//vector<int>ide;
//vector<int>b;
//vector<vector<int>>g;
//vector<int>vis;
//
//void solve() {
//	int n;
//	cin >> n;
//	ans = 0;
//	a.assign(n + 1, 0);
//	ide.assign(n + 1, 0);
//	b.resize(n + 1);
//	g.assign(n + 1, {});
//	vis.assign(n + 1, 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//		g[i].reserve(b[i] + 1);
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1, u; j <= b[i]; j++) {
//			cin >> u;
//			ide[u]++;
//			g[i].push_back(u);
//		}
//	}
//	queue<int>q;
//	for (int i = 1; i <= n; i++) {
//		if (ide[i] == 0) {
//			q.push(i);
//		}
//	}
//	while (!q.empty()) {
//		int t = q.front();
//		q.pop();
//		for (int i = 0; i < g[t].size(); i++) {
//			a[g[t][i]] += a[t];
//			if (--ide[g[t][i]] == 0) {
//				q.push(g[t][i]);
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!vis[i] && ide[i] != 0 && a[i] != 0) {
//			dfs(i, vis, g, ide);
//		}
//	}
//	cout << ans << '\n';
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
//using namespace std;
//void solve(){
//	int p;
//	cin >> p;
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
//const int base = 799;
//const int mod=998244353;
//int f[1000005];
//int Hash[1000005];
//int dp;
//void solve() {
//	string s;
//	cin >> s;
//	for (int i = 0; i < s.size();i++) {
//		Hash[i] = s[i - 1] * base + s[i] - '0';
//	}
//
//}
//int main() {
//	f[0] = 1;
//	f[1] = 1;
//	for (int i = 2; i <= 1000005; i++) {
//		f[i] = f[i - 1] + 3 * f[i - 2];
//	}
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}