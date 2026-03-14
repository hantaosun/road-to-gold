//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int x, y;
//	cin >> x >> y;
//	if ((x + y) % 12 == 0) {
//		cout << 12 << '\n';
//	}
//	else cout << (x + y) % 12 << '\n';
//}


//#include<bits/stdc++.h>
//using namespace std;
//int score[105];
//string vote[105];
//int win[105];
//int main() {
//	int n, m;
//	cin >> n >> m;
//	string s;
//	for (int i = 1; i <= n; i++) {
//		cin >> vote[i];
//	}
//	for (int i = 0; i < m; i++) {
//		int one = 0;
//		int zero = 0;
//		for (int j = 1; j <= n; j++) {
//			if (vote[j][i] == '0') {
//				zero++;
//			}
//			else one++;
//		}
//		if (zero > one) {
//			win[i] = 1;
//		}
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		int got = 0;
//		for (int j = 0; j < m; j++) {
//			if (win[j] == vote[i][j] - '0') {
//				got++;
//			}
//		}
//		ans = max(ans, got);
//		score[i] = got;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (ans == score[i]) {
//			cout << i << " ";
//		}
//	}cout << '\n';
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2e5 + 5;
//int a[N];
//int b[N];
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		sum += min(a[i], b[i]);
//	}
//	char op;
//	for (int i = 1,x,v; i <= m; i++) {
//		cin >> op >> x >> v;
//		if (op == 'A') {
//			sum -= min(a[x], b[x]);
//			a[x] = v;
//			sum += min(a[x], b[x]);
//		}
//		else {
//			sum -= min(a[x],b[x]);
//			b[x] = v;
//			sum += min(a[x], b[x]);
//		}
//		cout << sum << '\n';
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//char g[505][505];
//bool vis[505][505][2];
//int dx[] = {1,0,-1,0};
//int dy[] = { 0,-1,0,1 };
//int gs(char c) {
//	if (c == 'o')return 1;
//	else return 0;
//}
//int main() {
//	int h, w;
//	cin >> h >> w;
//	int sx, sy;
//	for (int i = 1; i <= h; i++) {
//		for (int j = 1; j <= w; j++) {
//			cin >> g[i][j];
//			if (g[i][j] == 'S') {
//				sx = i;
//				sy = j;
//			}
//		}
//	}
//	queue<array<int, 3>>q;
//	q.push({ sx,sy,1 });
//	vis[1][1][1] = true;
//	int level = 0;
//	while (!q.empty()) {
//		int siz = q.size();
//		while (siz--) {
//			auto [x, y, s] = q.front();
//			q.pop();
//			for (int d = 0; d < 4; d++) {
//				int nx = x + dx[d];
//				int ny = y + dy[d];
//				if (nx >= 1 && nx <= h && ny >= 1 && ny <= w) {
//					if (g[nx][ny] == '#')continue;
//					if (g[nx][ny] == 'G') {
//						cout << level + 1 << '\n';
//						return 0;
//					}
//					int t = s;
//					if (g[nx][ny] == '?') {
//						t =s^ 1;
//					}
//					else if (g[nx][ny] != '.'&&g[nx][ny]!='S'&& gs(g[nx][ny]) != t) {
//						continue;
//					}
//					if (vis[nx][ny][t])continue;
//					q.push({ nx,ny,t });
//					vis[nx][ny][t] = true;
//				}
//			}
//		}
//		level++;
//	}
//	cout << -1<<'\n';
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5+5;
//int fa[N];
//int black[N];//当前节点所在集合黑色点数量
//int color[N];
//int find(int x) {
//	while (x != fa[x]) {
//		x = fa[x] = fa[fa[x]];
//	}
//	return x;
//}
//void prepare() {
//	for (int i = 1; i < N; i++) {
//		fa[i] = i;
//		black[i] = 0;
//		color[i] = 0;
//	}
//}
//void merge(int x, int y) {
//	int fx = find(x);
//	int fy = find(y);
//	fa[fx] = fy;
//	black[fy] += black[fx];
//}
//int main() {
//	int n, q;
//	cin >> n >> q;
//	prepare();
//	for (int i = 1,op,u,v; i <= q; i++) {
//		cin >> op;
//		if (op == 1) {
//			cin >> u >> v;
//			if (find(u) == find(v))continue;
//			merge(u, v);
//		}
//		else if (op == 2) {
//			cin >> v;
//			int fv = find(v);
//			if (color[v] == 0) {
//				color[v] = 1;
//				black[fv]++;
//			}
//			else {
//				color[v] = 0;
//				black[fv]--;
//			}
//		}
//		else {
//			cin >> v;
//			int fv = find(v);
//			if (black[fv] != 0) {
//				cout << "Yes\n";
//			}
//			else {
//				cout << "No\n";
//			}
//		}
//	}
//}