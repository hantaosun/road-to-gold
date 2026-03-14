//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	string a;
//	cin >> a;
//	int m;
//	cin >> m;
//	string b, c;
//	cin >> b >> c;
//	string s;
//	for (int i = 0; i < c.size(); i++) {
//		if (c[i] == 'V') {
//			a = b[i] + a;
//		}
//		else {
//			a = a + b[i];
//		}
//	}
//	cout << a << '\n';
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
//	int n;
//	cin >> n;
//	vector<int>tmp;
//	bool flag = 0;
//	for (int i = 10; i>=0&&i + 1 <= n; i *= 10) {
//		if (n % (i + 1) == 0) {
//			tmp.push_back(n / (i + 1));
//		}
//	}
//	if (tmp.size() == 0) {
//		cout << 0 << '\n';
//		return;
//	}
//	else {
//		cout << tmp.size() << '\n';
//		for (int i = tmp.size()-1; i >=0; i--) {
//			cout << tmp[i] << ' ';
//		}cout << '\n';
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
//#define int long long
//using namespace std;
//int price[21];//买3的n次方的西瓜要多少钱
//void prepare() {
//	for (int i = 0; i <= 20; i++) {
//		price[i] = pow(3, i + 1) + i * pow(3, i - 1);
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	int cur = 0;
//	int ans = 0;
//	while (n != 0) {
//		ans += n % 3 * price[cur];
//		cur++;
//		n /=3;
//	}
//	cout << ans << '\n';
//}
//signed main() {
//	prepare();
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int price[21];//买3的n次方的西瓜要多少钱
//int thr[21];
//void prepare() {
//	for (int i = 0; i <= 20; i++) {
//		price[i] = pow(3, i + 1) + i * pow(3, i - 1);
//	}
//}
//void solve() {
//	int n,k;
//	cin >> n>>k;
//	memset(thr, 0, sizeof(thr));
//	int cur = 0;
//	int ans = 0;
//	while (n != 0) {
//		ans += n % 3 ;
//		thr[cur] = n % 3;
//		cur++;
//		n /= 3;
//	}
//	if (ans > k) {
//		cout << -1 << '\n';
//		return;
//	}
//	int rst = k - ans;
//	for (int i = 20; i >= 1; i--) {
//		int tui = min(thr[i], rst / 2);
//		thr[i] -= tui;
//		thr[i - 1] += tui * 3;
//		rst -= tui * 2;
//	}
//	int an = 0;
//	for (int i = 0; i < 21; i++) {
//		an += price[i] * thr[i];
//	}
//	cout << an << '\n';
//}
//signed main() {
//	prepare();
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}

//1 1000
//3738
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//string s;
//int sum[21];//所有i位数字总和
//int pwr[21];
//int f(int i,int prs) {//1-s所有数字数位的总和
//	//来到第i位(i+1位)
//	if (i == s.size() - 1) {
//		int cur = s[i] - '0';
//		return prs * (cur+1)+(1+cur)*cur/2;
//	}
//	int ans = 0;
//	int cur = s[i] - '0';
///*	cout << "cur:" << cur << '\n';
//	cout << "prs:" << prs << "\n";
//	cout << ((cur - 1) * cur / 2 + prs) * pwr[s.size() - i - 1] << '\n';
//	cout << sum[s.size() - i - 1] * (cur) << "\n";
//	cout << ((cur - 1) * cur / 2 + prs) * pwr[s.size() - i - 1] + sum[s.size() - i - 1] * (cur)<<"*\n";
//	*///      0-cur-1的总和                            cur-1数字后续位对应的贡献                
//	ans += ((cur-1) * cur / 2 + prs*cur) * pwr[s.size()-i-1] + sum[s.size()-i-1] * (cur);
//	ans += f(i + 1, prs + cur);
//	return ans;
//}
//void prepare() {
//	sum[0] = 0;
//	pwr[0] = 1;
//	for (int i = 1; i < 21; i++) {
//		pwr[i] = pwr[i - 1] * 10;
//	}
//	for (int i = 1; i < 21; i++) {
//		sum[i] = 45 * pwr[i - 1] + 10* sum[i - 1];
//	}
//}
//void solve() {
//	int k;
//	cin >> k;
//	int len, num;
//	for (len = 1, num = 9; len < 21; len++, num *= 10) {
//		if (k >= num * len) {
//			k -= num * len;
//		}
//		else break;
//	}
//	int a = pow(10, len - 1);
//	//cout << "k:" << k << " " << len << '\n';
//	int tmp = k / len;
//	a += tmp;
//	tmp = k % len;
//	string ss = to_string(a);
//	int ans = 0;
//	for (int i = 0; i < tmp; i++) {
//		ans += ss[i] - '0';
//	}
//	//cout << ans << " ans***\n" << a << " a&&\n";
//	s = to_string(a-1);
//	//cout << "s:" << s << '\n';
//		ans += f(0, 0);
//	cout << ans << '\n';
////	cout << "------------\n";
//}
//signed main() {
//	/*int ans = 0;
//	for (int i = 1; i <= 99; i++) {
//		int t = i;
//		while (t != 0) {
//			ans += t % 10;
//			t /= 10;
//		}
//	}
//	cout << ans << "*(**(*\n";
//	*/
//	prepare();
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
//	int n, m, q;
//	cin >> n >> m >> q;
//	vector<int>a(n + 1);
//	vector<int>b(m + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= m; i++) {
//		cin >> b[i];
//	}
//	sort(a.begin() + 1, a.end(), [&](int x, int y) {
//		return x > y;
//		});
//	sort(b.begin() + 1, b.end(), [&](int x, int y) {
//		return x > y;
//		});
//	vector<array<int, 2>>c(n + m + 1);
//	for (int i = 1; i <= n; i++) {
//		c[i] = { a[i],1 };
//	}
//	for (int i = 1; i <= m; i++) {
//		c[i + n] = { b[i],0 };
//	}
//	sort(c.begin() + 1, c.end(), [&](auto x, auto y) {
//		return x[0] > y[0];
//		});
//	vector<int>sumC(n + m + 1);
//	vector<int>presumC(n + m + 1);
//	vector<int>sumA(n + 1);
//	vector<int>sumB(m + 1);
//	
//	for (int i = 1; i <= n; i++) {
//		sumA[i] = sumA[i - 1] + a[i];
//	}
//	for (int i = 1; i <= m; i++) {
//		sumB[i] = sumB[i - 1] + b[i];
//	}
//	for (int i = 1; i <= n + m; i++) {
//		sumC[i] = sumC[i - 1] + c[i][1];
//		presumC[i] = presumC[i - 1] + c[i][0];
//	}
//	for (int i = 0, x, y, z; i < q; i++) {
//		cin >> x >> y >> z;
//		if (z == x + y) {
//			cout << sumA[x] + sumB[y] << '\n';
//			continue;
//		}
//		if (x == 0) {
//			cout << sumB[min(y,z)] << '\n';
//			continue;
//		}
//		if (y == 0) {
//			cout << sumA[min(x,z)] << '\n';
//			continue;
//		}
//		else {
//			int got = min(n + m, z);//实际拿了几个
//			int na = sumC[got];
//			int nb = got-na;
//			int ans = presumC[got];
//			if (na > x&&nb>y) {
//				ans -= sumA[na] - sumA[x - 1];
//				ans -= sumB[nb] - sumB[y - 1];
//				cout << ans << '\n';
//				continue;
//			}
//			else if (na > x) {
//				ans -= sumA[na] - sumA[x];
//				ans += sumB[min(nb+na-x,y)] - sumB[nb];
//				cout << ans << '\n';
//				continue;
//			}
//			else if(nb>y){
//				ans -= sumB[nb] - sumB[y];
//				ans += sumA[min(x, na + nb - y)] - sumA[na];
//				cout << ans << '\n';
//				continue;
//			}
//			else {
//				cout << ans << '\n';
//				continue;
//			}
//		
//		}
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
//const int N = 2e5 + 5;
//const int M = 2e5 + 5;
//int head[N];
//int to[M<<1];
//int nex[M << 1];
//int from[M << 1];
//int idx[M << 1];
//int cntg;
//int cnt;
//bool brg[M << 1];
//int n=0, m=0;
//void addEdge(int u, int v,int id) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	from[cntg] = u;
//	idx[cntg] = id;
//	head[u] = cntg++;
//}
//int dfn[N];
//int low[N];
//int path[M<<1];
//int mark;
//void tarjan(int u,int faE) {
//	dfn[u] = low[u] = ++cnt;
//	if (u == n)mark = 0;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (ui == (faE^1))continue;
//		int v = to[ui];
//		if (!dfn[v]) {
//			path[ui] ^= mark;
//			path[ui ^ 1] ^= mark;
//			tarjan(v, ui);
//			path[ui] ^= mark;
//			path[ui ^ 1] ^= mark;
//			low[u] = min(low[u], low[v]);
//			if (low[v] > dfn[u]) {
//				brg[ui] = brg[ui ^ 1] = true;
//			}
//		}
//		else low[u] = min(low[u], dfn[v]);
//	}
//}
//int belong[N];
//int dis[N];
//void clear() {
//	memset(head, 0, sizeof(int) * (n+10));
//	memset(brg, 0, sizeof(bool) * (cntg + 10) );
//	memset(dfn, 0, sizeof(int) * (n + 10));
//	memset(low, 0, sizeof(int) * (n + 10));
//	memset(path, 0, sizeof(int) * (cntg+10));
//	cntg = 2;
//	cnt = 0;
//	mark = 1;
//}
//void solve() {
//	clear();
//	cin >> n >> m;	
//	for (int i = 1; i <= n; i++) {
//		belong[i] = dis[i] = INT_MAX;
//	}
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		addEdge(u, v,i);
//		addEdge(v, u,i);
//	}
//	tarjan(1, 0);
//	queue<int>q;
//	for (int i = 2; i <cntg; i++) {
//		if (brg[i]&&path[i]) {
//			int u = from[i], v = to[i];
//			if (belong[u] == INT_MAX) {
//				q.push(u);
//			}
//			if (belong[v] == INT_MAX) {
//				q.push(v);
//			}
//			belong[u] = min(belong[u], idx[i]);
//			belong[v] = min(belong[v], idx[i]);
//			dis[u] = dis[v] = 0;
//		}
//	}
//	int level = 1;
//	while (!q.empty()) {
//		int siz = q.size();
//		while (siz--) {
//			int u = q.front();
//			q.pop();
//			for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//				if (brg[ui]&&path[ui])continue;
//				int v = to[ui];
//				if (dis[v]>level||dis[v] == INT_MAX || dis[v] == level && belong[v] > belong[u]) {
//					belong[v] = belong[u];
//					dis[v] = level;
//					q.push(v);
//				}
//			}
//		}
//		level++;
//	}
//	//for (int i = 2; i < cntg; i++) {
//	//	cout << from[i] << " " << to[i] << " " << brg[i] << " " << path[i] << " "<<idx[i]<<" "<<belong[i] << '\n';
//	//}
//	int qry;
//	cin >> qry;
//	vector<int>query;
//	for (int i = 1, c; i <= qry; i++) {
//		cin >> c;
//		query.push_back(c);
//	}
//	for (int i = 0; i < query.size(); i++) {
//		cout << (belong[query[i]] == INT_MAX ? -1 : belong[query[i]]) << ' ';
//	}cout << '\n';
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}