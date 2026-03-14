//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	long long n;
//	cin >> n;
//	if (!(n & 1)) {
//		cout << (n + 1) * 2 + n;
//	}
//	else {
//		cout << n * 2 + n + 1 << endl;
//	}
//}


//#include<bits/stdc++.h>
//#define i64 long long
//using namespace std;
//int newxor(int a, int b) {
//	int x = a ^ b;
//	int cnt = 0;
//	for (int i = 0; (x >> i) != 0; i++) {
//		if ((x >> i) & 1) {
//			cnt++;
//			if (!(cnt & 1)) {
//				x ^= (1 << i);
//			}
//		}
//	}
//	return x;
//}
//int main() {
//	int N;
//	cin >> N;
//	vector<int>a(N+1);
//	i64 ans=0;
//	for (int i = 1; i <= N; i++) {
//		cin >> a[i];
//		cout << bitset<32>(a[i])<<endl;
//		for (int j = 1; j < i; j++) {
//			ans += newxor(a[i],a[j]);
//		}
//	}
//	cout << bitset<32>(ans) <<"***"<< endl;
//	//int a, b,c;
//	//while (cin >> a >> b>>c) {
//	//	cout << bitset<32>(a) << endl;
//	//	cout << bitset<32>(b) << endl;
//	//	cout << bitset<32>(c) << endl;
//	//	cout << bitset<32>(newxor(c, a+b)) << endl;
//	//	cout << bitset<32>(newxor(c, a)+newxor(c,b)) << endl;
//	//}
//}


//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//
//}
//
// Created by admin on 2025/7/29.
//



//#include<bits/stdc++.h>
//using namespace std;
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,1,0,-1 };
//vector<vector<int>>g;
//vector<vector<int>>vis;
//vector<vector<int>>step;
//vector<vector<array<int, 2>>>point;
//int n, m;
//int level = 0;
//bool check(const int t) {//检查最小答案能不能是t
//	vector<vector<int>>vis(n+1, vector<int>(m+1,0));
//	int maX=INT_MIN, maY=INT_MIN, miX=INT_MAX, miY=INT_MAX;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			if (step[i][j] > t) {
//				maX = max(maX, i + j);
//				maY = max(maY, i - j);
//				miX = min(miX, i + j);
//				miY = min(miY, i - j);
//			}
//		}
//	}
//	//cout << maX << " " << maY << " " << miX << " " << miY << endl;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			int x = i + j;
//			int y = i - j;
//			if (abs(maX - x) <= t && abs(maY - y) <= t && abs(miX - x) <= t && abs(miY - y) <= t) {
//				return true;
//			}
//		}
//	}
//	return false;
//}
//int main() {
//	cin >> n >> m;
//	g.assign(n + 1, vector<int>(m + 1));
//	vis.assign(n + 1, vector<int>(m + 1, 0));
//	step.assign(n + 1, vector<int>(m + 1));
//	queue<array<int,2>>q;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> g[i][j];
//			if (g[i][j] == 1) {
//				q.push({ i,j });
//				vis[i][j] = 1;
//				step[i][j] = 0;
//			}
//		}
//	}
//	while (!q.empty()) {
//		level++;
//		int siz = q.size();
//		//cout << level << " " << q.size() << endl;
//		for (int i = 1; i <= siz; i++) {
//			auto [x, y] = q.front();
//			q.pop();
//			for (int d = 0, nx, ny; d < 4; d++) {
//				nx = x + dx[d];
//				ny = y + dy[d];
//				if (nx >= 1 && nx <= n
//					&& ny >= 1 && ny <= m && !vis[nx][ny]) {
//					q.push({ nx,ny });
//					vis[nx][ny] = 1;
//					step[nx][ny] = level;
//				}
//			}
//		}
//	}
//
//	//debug
//	//for (int i = 1; i <= n; i++) {
//	//	for (int j = 1; j <= m; j++) {
//	//		cout << step[i][j] << " ";
//	//	}
//	//	cout << endl;
//	//}
//
//	//cout << level << endl;
//	int l = 1, r = level-1,m,ans=level-1;
//	while (l <= r) {
//		m = l + r >> 1;
//		//cout << m << endl;
//		if (check(m)) {
//			ans = m;
//			r = m - 1;
//		}
//		else {
//			l = m + 1;
//		}
//	}
//	cout << ans << endl;
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 2e5 + 10;
//int nex[MAXN];
//int to[MAXN];
//int head[MAXN];
//int siz[MAXN];
//int dfn[MAXN];
//int dep[MAXN];
//int cnt = 1;
//int cn = 1;
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//void dfs(int cur, int fa) {
//	dfn[cur] = cn++;
//	siz[cur] = 1;
//	dep[cur] = dep[fa] + 1;
//	for (int ui = head[cur]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		dfs(to[ui], cur);
//	}
//	for (int ui = head[cur]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		siz[cur] += siz[to[ui]];
//	}
//}
//bool isson(int x, int y) {
//	if (dfn[x] >= dfn[y] && dfn[x] <= dfn[y] + siz[y] - 1)return true;
//	return false;
//}
//int main() {
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<array<int, 2>>road(n);
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		road[i]={ u,v };
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs(1, 0);
//
//	for (int i = 1; i <= n; i++) {
//		cout << dfn[i] << " ";
//	}cout << endl;
//	for (int i = 1; i <= n; i++) {
//		cout << siz[i] << " ";
//	}cout << endl;
//	vector<int>key;
//	for (int i = 1,x; i <= m; i++) {
//		cin >> x;
//		key.push_back(x);
//	}
//	vector<array<int,2>>route;
//	for (int i = 1,s,t; i <= k; i++) {
//		cin >> s >> t;
//		route.push_back({ s,t });
//	}
//	vector<vector<int>>contain(route.size());
//	for (int i = 0; i < key.size(); i++) {
//		auto [u, v] = road[key[i]];
//		if (dep[u] < dep[v])swap(u, v);
//		for (int j = 0; j < route.size(); j++) {
//
//			auto [x, y] = route[j];
//			cout << "u:" << u << " v:" << v << endl;
//			cout << "x:" << x << " y:" << y << endl;
//			cout << "isson(x,u):" << isson(x, u) << " isson(y,u):" << isson(y, u) << endl;
//		
//			if (isson(x, u) && !isson(y, u)||isson(y,u)&&!isson(x,u)) {
//				contain[j].push_back(i);
//			}
//		}
//	}
//	for (auto v : contain) {
//		for (auto j : v) {
//			cout << j << " ";
//		}cout << endl;
//	}
//	//统计从cotain数组中最少选几个数能覆盖0-key.size()-1中的所有数，且方案是多少。
//}


//
//#include<bits/stdc++.h>
//using namespace std;
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,1,0,-1 };
//vector<vector<int>>g;
//vector<vector<int>>vis;
//vector<vector<int>>step;
//// vector<vector<array<int, 2>>>point;
//int n, m;
//int level = 0;
//bool check(const int t) {//检查最小答案能不能是t
//    //queue<array<int,2>>q;
//    // vector<vector<int>>cnt(n + 1, vector<int>(m + 1));
//    // vector<vector<int>>vis(n+1, vector<int>(m+1,0));
//    // queue<array<int,2>>q;
//    bool flag = 0;
//    int maX = INT_MIN, maY = INT_MIN, miX = INT_MAX, miY = INT_MAX;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            if (step[i][j] > t) {
//                maX = max(maX, i + j);
//                maY = max(maY, i - j);
//                miX = min(miX, i + j);
//                miY = min(miY, i - j);
//                flag = 1;
//            }
//        }
//    }
//    if (!flag)return true;
//    // cout << maX << " " << maY << " " << miX << " " << miY << endl;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            int x = i + j;
//            int y = i - j;
//            if (abs(maX - x) <= t && abs(maY - y) <= t && abs(miX - x) <= t && abs(miY - y) <= t) {
//                return true;
//            }
//        }
//    }
//    return false;
//}
//int main() {
//    cin >> n >> m;
//    g.assign(n + 1, vector<int>(m + 1));
//    vis.assign(n + 1, vector<int>(m + 1, 0));
//    step.assign(n + 1, vector<int>(m + 1));
//    queue<array<int, 2>>q;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cin >> g[i][j];
//            if (g[i][j] == 1) {
//                q.push({ i,j });
//                vis[i][j] = 1;
//                step[i][j] = 0;
//            }
//        }
//    }
//    while (!q.empty()) {
//        level++;
//        int siz = q.size();
//        //cout << level << " " << q.size() << endl;
//        for (int i = 1; i <= siz; i++) {
//            auto [x, y] = q.front();
//            q.pop();
//            for (int d = 0, nx, ny; d < 4; d++) {
//                nx = x + dx[d];
//                ny = y + dy[d];
//                if (nx >= 1 && nx <= n
//                    && ny >= 1 && ny <= m && !vis[nx][ny]) {
//                    q.push({ nx,ny });
//                    vis[nx][ny] = 1;
//                    step[nx][ny] = level;
//                }
//            }
//        }
//    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cout << step[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    cout << level << endl;
//    int l = 0, r = level, m, ans = level;
//    while (l <= r) {
//        m = l + r >> 1;
//        //cout << m << endl;
//        if (check(m)) {
//            ans = m;
//            r = m - 1;
//        }
//        else {
//            l = m + 1;
//        }
//    }
//    // cerr<<check(2);
//    if (ans == -1)ans = 0;
//    cout << ans << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int cnt[200100];
//signed main() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int ans = 0;
//	for (int i = 0; i <= 30; i++) {
//		int cnt00=0, cnt10=0, cnt11=0, cnt01=0;
//		for (int j = 1; j <= n; j++) {
//			if ((a[j] >> i) & 1) {
//				if (cnt[j] % 2) {
//					cnt11++;
//				}
//				else cnt10++;
//				cnt[j]++;
//			}
//			else {
//				if (cnt[j] % 2) {
//					cnt01++;
//				}
//				else cnt00++;
//			}
//		}
//		ans += ((cnt10 * cnt00 + cnt11 * cnt01) << i);
//	}
//	cout << ans << endl;
//	return 0;
//}