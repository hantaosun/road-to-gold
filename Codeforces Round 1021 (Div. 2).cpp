//#include<bits/stdc++.h>
//using namespace std;
//int cnt[11];
//void solve() {
//	memset(cnt, 0, sizeof(cnt));
//	string s;
//	cin >> s;
//	for (int i = 0; i < s.size(); i++) {
//		cnt[s[i] - '0']++;
//	}
//	for (int i = 0; i <= 9; i++) {
//		int sma = 9 - i;
//		for (int j = sma; j <= 9; j++) {
//			if (cnt[j] != 0) {
//				cout << j;
//				cnt[j]--;
//				break;
//			}
//		}
//	}
//	cout << '\n';
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
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	sort(a.begin() + 1, a.end());
//	int l = (n - k+1) / 2;
//	int r = k + (n - k) / 2+1;
//	cout << a[r] - a[l] + 1 << '\n';
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
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	map<int, int>cnt;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		cnt[a[i]]++;
//	}
//	for (auto v : cnt) {
//		if (v.second >= 4) {
//			cout << "YES\n";
//			return;
//		}
//	}
//	int last = -1;
//	int l = -1, r = -1;
//	int got2 = 0;
//	for (auto [d, v] : cnt) {
//		//cout << d << " " << v << "***\n";
//		if (l == -1||r==-1) {
//			l = d;
//			r = d;
//			if (v >= 2) {
//				if (++got2 >= 2) {
//					cout << "YES\n";
//					return;
//				}
//			}
//		}
//		else {
//			if (d == last+ 1) {
//				r = d;
//				if (v >= 2) {
//					if (++got2 >= 2) {
//						cout << "YES\n";
//						return;
//					}
//				}
//			}
//			else {
//				got2 = 0;
//				l = d;
//				r = d;
//				if (v >= 2) {
//					got2++;
//				}
//			}
//		}
//		last = d;
//	}
//	if (l != -1 && r != -1) {
//		if (r > l && cnt[r] >= 2 && cnt[l] >= 2) {
//			cout << "YES\n";
//			return;
//		}
//	}
//	cout << "NO\n";
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
//const int mod = 1e9 + 7;
//const int N = 2005;
//int g[N][N];
//int n=0, m=0, k;
//int id(int x, int y) {
//	return x * m + y;
//}
//void solve() {
//	for (int i = 0; i <= n+5; i++) {
//		for (int j = 0; j <= m+5; j++) {
//			g[i][j] = 0;
//		}
//	}
//	cin >> n >> m >> k;
//	vector<int>x(k + 2);
//	vector<int>y(k + 2);
//	vector<vector<int>>need(k + 1);
//	for (int i = 1; i <= k + 1; i++) {
//		cin >> x[i] >> y[i];
//	}
//	for (int i = 2; i <= k + 1; i++) {
//		int px = x[i - 1], py = y[i - 1];
//		int tx = x[i], ty = y[i];
//		if (tx == px) {
//			if (abs(ty - py) != 2) {
//				cout << 0 << "\n";
//				return;
//			}
//			need[i - 1].push_back(id(tx, (ty + py) / 2));
//		}
//		else if (ty == py) {
//			if (abs(tx - px) != 2) {
//				cout << 0 << "\n";
//				return;
//			}
//			need[i - 1].push_back(id((tx + px) / 2, ty));
//		}
//		else {
//			if (abs(ty - py) != 1 || abs(tx - px) != 1) {
//				cout << 0 << "\n";
//				return;
//			}
//			need[i - 1].push_back(id(tx, py));
//			need[i - 1].push_back(id(px, ty));
//		}
//	}
//
//	
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
//#define int long long
//using namespace std;
//const int mod = 1e9 + 7;
//const int N = 1e6 + 5;
//int head[N];
//int nex[N<<2];
//int to[N<<2];
//int cnt = 1;
//int n=0, m=0, k=0;
//int cntid=0;
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//	nex[cnt] = head[v];
//	to[cnt] = u;
//	head[v] = cnt++;
//}
//bool vis[N];
//int outdegree[N];
//int cn1 = 0;
//int cn2 = 0;
//bool got1 = false;
//void dfs(int u) {
//	if (vis[u])return;
//	vis[u] = true;
//	if (outdegree[u] == 1) {
//		got1 = true;
//	}
//	if (u <= k) {
//		cn1++;
//	}
//	else {
//		cn2++;
//	}
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		dfs(to[ui]);
//	}
//}
//void solve() {
//	for (int i = 0; i <= cntid; i++) {
//		outdegree[i] = 0;
//		vis[i] = 0;
//		head[i] = 0;
//	}
//	cnt = 1;
//	cin >> n >> m >> k;
//	vector<int>x(k + 2);
//	vector<int>y(k + 2);
//	vector<vector<int>>id(n + 1, vector<int>(m + 1,0));
//	cntid = k+1;
//	for (int i = 1; i <= k + 1; i++) {
//		cin >> x[i] >> y[i];
//	}
//	for (int i = 1; i <=k; i++) {
//		int cx = x[i], cy = y[i], nx = x[i + 1], ny = y[i + 1];
//		if (cx == nx) {
//			if (abs(cy - ny) != 2) {
//				cout << 0 << '\n';
//				return;
//			}
//			if (id[cx][(cy + ny) / 2] == 0) {
//				id[cx][(cy + ny) / 2] = cntid++;
//			}
//			addEdge(i, id[cx][(cy + ny) / 2]);
//			outdegree[i] = 1;
//		}
//		else if (cy == ny) {
//			if (abs(cx - nx) != 2) {
//				cout << 0 << "\n";
//				return;
//			}
//			if (id[(cx + nx) / 2][cy] == 0) {
//				id[(cx + nx) / 2][cy] = cntid++;
//			}
//			addEdge(i, id[(cx + nx) / 2][cy]);
//			outdegree[i] = 1;
//		}
//		else {
//			if (abs(nx - cx) != 1 || abs(ny - cy) != 1) {
//				cout << 0 << "\n";
//				return;
//			}
//			if (id[cx][ny] == 0) {
//				id[cx][ny] = cntid++;
//			}
//			if (id[nx][cy] == 0) {
//				id[nx][cy] = cntid++;
//			}
//			addEdge(i, id[cx][ny]);
//			addEdge(i, id[nx][cy]);
//			outdegree[i] = 2;
//		}
//	}
//	int ans = 1;
//	for (int i = 1; i <= k; i++) {
//		if (vis[i])continue;
//		cn1 = 0;
//		cn2 = 0;
//		got1 = false;
//		dfs(i);
//		if (cn1 == cn2) {
//			if(!got1)ans = ans * 2 % mod;
//		}
//		else if (cn1 > cn2) {
//			ans = 0;
//			break;
//		}
//		else {
//			ans = ans * (cn1 + 1) % mod;
//		}
//	}
//	cout << ans << "\n";
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