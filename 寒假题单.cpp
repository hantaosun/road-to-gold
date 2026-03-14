////1A
//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n, a, b;
//	cin >> n >> a >> b;
//	vector<int>k(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> k[i];
//	}
//	vector<bool>vis(n + 1);
//	queue<int>q;
//	q.push(a);
//	int level = 0;
//	while (!q.empty()) {
//		int siz = q.size();
//		for (int i = 1; i <= siz; i++) {
//			int cur = q.front();
//			if (cur == b) {
//				cout << level << endl;
//				return 0;
//			}
//			q.pop();
//			if (cur + k[cur] <= n && !vis[cur + k[cur]]) {
//				q.push(cur + k[cur]);
//				vis[cur + k[cur]] = 1;
//			}
//			if (cur - k[cur] >= 1 && !vis[cur - k[cur]]) {
//				q.push(cur - k[cur]);
//				vis[cur - k[cur]] = 1;
//			}
//		}
//		level++;
//	}
//	cout << -1 << endl;
//}

////1B
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1005;
//int g[N][N];
//int vis[N][N];
//int num[N][N];
//int n, m;
//int cnt = 0;
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//void dfs(int i, int j, int to) {
//	if (i <= 0 || i > n || j <= 0 || j > n ||vis[i][j]|| g[i][j] != to)return;
//	cnt++;
//	vis[i][j] = 1;
//	for (int d = 0; d < 4; d++) {
//		int ni = i + dx[d];
//		int nj = j + dy[d];
//		dfs(ni, nj, to ^ 1);
//	}
//}
//void dfs1(int i, int j, int to, int c) {
//	if (i <= 0 || i > n || j <= 0 || j > n ||num[i][j]||g[i][j] != to)return;
//	num[i][j] = c;
//	for (int d = 0; d < 4; d++) {
//		int ni = i + dx[d];
//		int nj = j + dy[d];
//		dfs1(ni, nj, to ^ 1, c);
//	}
//}
//int main() {
//	cin >> n >> m;
//	string tmp;
//	for (int i = 1; i <= n; i++) {
//		cin >> tmp;
//		for (int k = 0; k < n; k++) {
//			g[i][k + 1] = tmp[k]-'0';
//		}
//	}
//	for (int i = 1, x, y; i <= m; i++) {
//		cin >> x >> y;
//		if (!num[x][y]) {
//			cnt = 0;
//			dfs(x, y, g[x][y]);
//			dfs1(x, y, g[x][y], cnt);
//		}
//		cout << num[x][y] << endl;
//	}
//}


////1c
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//vector<string>ans;
//void dfs(int i, int col, int lcol, int rcol, string& path) {
//	if (i > n) { ans.push_back(path); return; }
//	for (int j = 1; j <= n; j++) {
//		if (!((col >> j) & 1) && !((lcol >> j) & 1) && !((rcol >> j) & 1)) {
//			path.push_back(char(j + '0'));
//			dfs(i + 1, col | (1 << j), (lcol | (1 << j)) << 1, (rcol | (1 << j)) >> 1, path);
//			path.pop_back();
//		}
//	}
//}
//int main() {
//	cin >> n;
//	string p = "";
//	dfs(1, 0, 0, 0, p);
//	sort(ans.begin(), ans.end());
//	int cnt = 0;
//	for (auto v : ans) {
//		if (cnt == 3)break;
//		for (int i = 0; i < v.size(); i++) {
//			cout << v[i]-'0' << " ";
//		}
//		cout << endl;
//		cnt++;
//	}
//	cout << ans.size() << endl;
//}

//1d
//#include<bits/stdc++.h>
//using namespace std;
//string g[5];
//string t[5];
//bool vis[5][5];
//bool used[5][5];
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,1,0,-1 };
//vector<string>ans;
//struct cmp {
//	bool operator()(pair<pair<int, int>, pair<pair<int, int>, int>>& a, pair<pair<int, int>, pair<pair<int, int>, int>>& b) {
//		return a.second.second > b.second.second;
//	}
//};
//void mov(int cx, int cy, int tx, int ty) {
//	//cout << cx << " " << cy << " " << tx << " " << ty << "\n";
//	if (cx != tx) {
//		int to = cx < tx ? 1 : -1;
//		if (g[cx + to][cy] == g[cx][cy]) {
//			mov(cx + to, cy, tx, ty);
//			swap(g[cx + to][cy], g[cx][cy]);
//			ans.push_back(to_string(cx + to) + to_string(cy) + to_string(cx) + to_string(cy));
//		}
//		else {
//			swap(g[cx + to][cy], g[cx][cy]);
//			ans.push_back(to_string(cx + to) + to_string(cy) + to_string(cx) + to_string(cy));
//			mov(cx + to, cy, tx, ty);
//		}
//	}
//	else if (cy != ty) {
//		int to = cy < ty ? 1 : -1;
//		if (g[cx][cy + to] == g[cx][cy]) {
//			mov(cx, cy + to, tx, ty);
//			swap(g[cx][cy + to], g[cx][cy]);
//			ans.push_back(to_string(cx) + to_string(cy + to) + to_string(cx) + to_string(cy));
//		}
//		else {
//			swap(g[cx][cy + to], g[cx][cy]);
//			ans.push_back(to_string(cx) + to_string(cy + to) + to_string(cx) + to_string(cy));
//			mov(cx, cy + to, tx, ty);
//
//		}
//	}
//}
//pair<pair<int, int>, int> bfs(int i, int j) {//找到最近的未放置的1
//	for (int i = 1; i < 5; i++) {
//		for (int j = 1; j < 5; j++) {
//			vis[i][j] = 0;
//		}
//	}
//	queue<pair<int, int>>q;
//	vis[i][j] = 1;
//	q.push({ i, j });
//	int level = 0;
//	while (!q.empty()) {
//		int siz = q.size();
//		for (int i = 1; i <= siz; i++) {
//			auto [x, y] = q.front();
//			q.pop();
//			if (g[x][y] == '0' && t[x][y] == '1') {
//				return { {x,y},level };
//			}
//			for (int d = 0; d < 4; d++) {
//				int nx = x + dx[d];
//				int ny = y + dy[d];
//				if (nx <= 0 || nx > 4 || ny < 0 || ny>4 || vis[nx][ny])continue;
//				vis[nx][ny] = 1;
//				q.push({ nx,ny });
//			}
//		}
//		level++;
//	}
//	return { { -1,-1},-1 };
//}
//int main() {
//	for (int i = 1; i <= 4; i++) {
//		cin >> g[i];
//		g[i] = " " + g[i];
//	}
//	for (int j = 1; j <= 4; j++) {
//		cin >> t[j];
//		t[j] = " " + t[j];
//	}
//	priority_queue<pair<pair<int, int>, pair<pair<int, int>, int>>, vector<pair<pair<int, int>, pair<pair<int, int>, int>>>, cmp>pq;
//	for (int i = 1; i <= 4; i++) {
//		for (int j = 1; j <= 4; j++) {
//			if (g[i][j] == '1'&&t[i][j]!='1') {
//				//cout << i << " " << j << "^^^\n";
//				pq.push({ {i,j},bfs(i,j) });
//			}
//		}
//	}
//	vector<pair<pair<int, int>, pair<pair<int, int>, int>>>tmp;
//	while (!pq.empty()) {
//		//cout << pq.size() << endl;
//		auto v = pq.top();
//		pq.pop();
//		//cout << v.first.first << " " << v.first.second << " " << v.second.first.first << " " << v.second.first.second << endl;
//		mov(v.first.first, v.first.second, v.second.first.first, v.second.first.second);
//		while (!pq.empty()) {
//			tmp.push_back(pq.top());
//			pq.pop();
//
//		}
//		for (auto u : tmp) {
//			pq.push({ { u.first.first,u.first.second }, bfs(u.second.first.first, u.first.second) });
//		}
//		tmp.clear();
//	}
//	//for (int i = 1; i <= 4; i++) {
//	//	for (int j = 1; j <= 4; j++) {
//	//		if (g[i][j] == '1' && t[i][j] == '0') {
//	//			auto [tx, ty] = bfs(i, j);
//	//			//cout << i << " " << j << " " << tx << " " << ty << "**\n";
//	//			mov(i, j, tx, ty);
//	//			//cout << "---------------\n";
//	//		}
//	//	}
//	//}
//	cout << ans.size() << endl;
//	for (auto v : ans)cout << v << endl;
//}
//#include<bits/stdc++.h>
//using namespace std;
//bool vis[(1 << 16) + 5];
//array<int,4> from[(1 << 16) + 5];
//int c=0;
//int t=0;
//struct cmp {
//	bool operator()(pair<int,int>&a,pair<int,int>&b) {
//		return a.second > b.second;
//	}
//};
//int gotp(int i, int j) {
//	int id = i * 4 + j;
//	return 16 - id-1;
//}
//int swap(int u, int x, int y, int xx, int yy) {
//	int px = gotp(x, y), pxx= gotp(xx, yy);
//	int cx = (u >> px) & 1;
//	int cxx = (u >> pxx) & 1;
//	return u & (~(1 << px)) & (~(1 << pxx)) ^ (cx << pxx) ^ (cxx << px);
//}
//void backtrace() {
//	stack<string>sta;
//	int x = t;
//	while (x != c) {
//		sta.push(to_string(from[x][0]+1) + to_string(from[x][1]+1) + to_string(from[x][2]+1) + to_string(from[x][3]+1));
//		x = swap(x, from[x][0], from[x][1], from[x][2], from[x][3]);
//	}
//	cout << sta.size() << endl;
//	while (!sta.empty()) {
//		cout << sta.top() << endl;
//		sta.pop();
//	}
//}
//int main() {
//	from[30946] = { 0,0,0,0 };
//	string tmp;
//	for (int i = 1; i <= 4; i++) {
//		cin >> tmp;
//		for (int j = 0; j < 4; j++) {
//			if (tmp[j] == '1') {
//				c = (c << 1) | 1;
//			}
//			else c <<= 1;
//		}
//	}
//	for (int i = 1; i <= 4; i++) {
//		cin >> tmp;
//		for (int j = 0; j < 4; j++) {
//			if (tmp[j] == '1') {
//				t = (t << 1) | 1;
//			}
//			else t <<= 1;
//		}
//	}
//	queue<int>q;
//	q.push(c);
//	while (!q.empty()) {
//		int siz = q.size();
//		for (int i = 1; i <= siz; i++) {
//			int u = q.front();
//			q.pop();
//			if (u == t) {
//				backtrace();
//				return 0;
//			}
//			for (int i = 0; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					if (i + 1 < 4) {
//						int nu = swap(u,i,j,i+1,j);
//						if (!vis[nu]) {
//							vis[nu] = 1;
//							from[nu] = { i,j,i + 1,j };
//							q.push(nu);
//						}
//					}
//					if (j + 1 < 4) {
//						int nu = swap(u,i,j,i,j+1);
//						if (!vis[nu]) {
//							vis[nu] = 1;
//							from[nu] = { i,j,i,j+1 };
//							q.push(nu);
//						}
//					}
//				}
//			}
//		}
//	}
//}


//1e
//#include<bits/stdc++.h>
//using namespace std;
//int dx[] = {1,-1,1,-1,2,-2,2,-2};
//int dy[] = {2,-2,-2,2,-1,1,1,-1};
//bool vis[405][405];
//int ans[405][405];
//int main() {
//	int n, m,x,y;
//	cin >> n >> m>>x>>y;
//	vis[x][y];
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			ans[i][j] = -1;
//		}
//	}
//	queue<pair<int, int>>q;
//	q.push({ x,y });
//	vis[x][y] = 1;
//	int level = 0;
//	while (!q.empty()) {
//		int siz = q.size();
//		for (int i = 1; i <= siz; i++) {
//			auto [x, y] = q.front();
//			q.pop();
//			ans[x][y] = level;
//			for (int d = 0; d < 8; d++) {
//				int nx = x + dx[d];
//				int ny = y + dy[d];
//				if (nx <= 0 || nx > n || ny <= 0 || ny > m || vis[nx][ny])continue;
//				q.push({ nx,ny });
//				vis[nx][ny] = 1;
//			}
//		}
//		level++;
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << ans[i][j] << " ";
//		}cout << "\n";
//	}
//}


//1f
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//bool g[15][15];
//pair<int, int> mch[15][15];
//int rh[15][15];
//vector<pair<int, int>>hole;
//vector<int>vx;
//vector<int>vy;
//int ans = 0;
//void check() {
//	//cout << "xixi\n";
//	//cout << mch[5][1].first << " " << mch[5][1].second << endl;
//	 for (int j = 1; j <= vy.size() + 1; j++) {
//		for (int i = vx.size()+1; i>= 0; i--) {
//			int cx = i, cy = j;
//			int cnt = 0;
//			while (true) {
//				if (cnt > n+5) {
//					ans++;
//					return;
//					break;
//				}
//				//cout << cx << " " << cy << endl;
//				cx = rh[cx][cy];
//				//cout << cx << " " << cy << "^^\n";
//				if (cx == -1)break;
//				auto nxt = mch[cx][cy];
//				cx = nxt.first, cy = nxt.second;
//				//cout << cx << " " << cy << "^\n---------------\n";
//				cnt++;
//			}
//		}
//	}
//	 //cout << "over\n";
//}
//void dfs(int cur) {
//	if (cur >= hole.size()) {
//		check();
//		return;
//	}
//	if (mch[hole[cur].first][hole[cur].second] != make_pair(-1, -1)) {
//		dfs(cur + 1); return;
//	}
//	for (int i = cur + 1; i < hole.size(); i++) {
//		if (mch[hole[i].first][hole[i].second] == make_pair(-1, -1)) {
//			mch[hole[cur].first][hole[cur].second] = hole[i];
//			mch[hole[i].first][hole[i].second] = hole[cur];
//			dfs(cur + 1);
//			mch[hole[i].first][hole[i].second] = { -1,-1 };
//			mch[hole[cur].first][hole[cur].second] = { -1,-1 };
//		}
//	}
//}
//int main() {
//	for (int i = 1; i <= 14; i++) {
//		for (int j = 1; j <= 14; j++) {
//			mch[i][j] = { -1,-1 };
//		}
//	}
//	cin >> n;
//
//	for (int i = 1, x, y; i <= n; i++) {
//		cin >> x >> y;
//		vx.push_back(x);
//		vy.push_back(y);
//		hole.push_back({ x,y });
//	}
//	sort(vx.begin(), vx.end());
//	sort(vy.begin(), vy.end());
//	vx.erase(unique(vx.begin(), vx.end()), vx.end());
//	vy.erase(unique(vy.begin(), vy.end()), vy.end());
//	for (auto& p : hole) {
//		p.first = lower_bound(vx.begin(), vx.end(), p.first) - vx.begin() + 1;
//		p.second = lower_bound(vy.begin(), vy.end(), p.second) - vy.begin() + 1;
//		g[p.first][p.second] = 1;
//	}
//	for (int i = 1; i <= 13; i++) {
//		int rr = -1;
//		for (int j = 13; j >= 0; j--) {
//			rh[j][i] = rr;
//			if (g[j][i])rr = j;
//		}
//	}
//	//for (auto [x, y] : hole)cout << x << " " << y << "*\n";
//	dfs(0);
//	cout << ans << endl;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int n, m;
//string g[305];
//bool vis[305][305];
//pair<int, int>lst[27];
//pair<int,int> to[305][305];
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,-1,0,1 };
//int main() {
//	cin >> n >> m;
//	queue<pair<int,int>>q;
//	for (int i = 0; i < 27; i++) {
//		lst[i] = { -1,-1 };
//	}
//	int tx, ty;
//	for (int i = 1; i <= n; i++) {
//		cin >> g[i];
//		g[i] = " " + g[i];
//		for (int j = 1; j <= m; j++) {
//			if (g[i][j] == '@') {
//				q.push({ i,j });
//				vis[i][j] = 1;
//			}
//			else if (g[i][j] == '=') {
//				tx = i;
//				ty = j;
//			}
//			else if (g[i][j] <= 'Z' && g[i][j] >= 'A') {
//				if (lst[g[i][j] - 'A'] == make_pair(-1, -1)) {
//					lst[g[i][j] - 'A'] = { i,j };
//				}
//				else {
//					to[i][j] = lst[g[i][j] - 'A'];
//					to[lst[g[i][j] - 'A'].first][lst[g[i][j] - 'A'].second] = { i,j };
//				}
//			}
//		}
//	}
//	int level = 0;
//	while (!q.empty()) {
//		int siz = q.size();
//		//cout << level << "**\n";
//		for (int i = 1; i <= siz; i++) {
//			auto [x,y] = q.front();
//			q.pop();
//			//cout << x << " " << y << endl;
//			if (x == tx && y == ty) {
//				cout << level << endl;
//				return 0;
//			}
//			if (g[x][y] <= 'Z' && g[x][y] >= 'A') {
//				auto p = to[x][y];
//				x = p.first;
//				y = p.second;
//			}
//			for (int d = 0; d < 4; d++) {
//				int nx = x + dx[d];
//				int ny = y + dy[d];
//				if (nx > n || nx < 1 || ny > m || ny < 1 || vis[nx][ny] || g[nx][ny] == '#')continue;
//				q.push({ nx,ny });
//				vis[nx][ny] = 1;	
//			}
//		}
//		level++;
//	}
//	cout << -1 << endl;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int m;
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,1,0,-1 };
//int safe[305][305];
//int des[305][305];
//bool vis[305][305];
//int main() {
//	cin >> m;
//	for (int i = 0; i < 305; i++) {
//		for (int j = 0; j < 305; j++) {
//			safe[i][j] = 1;
//			des[i][j] = INT_MAX;
//		}
//	}
//	for (int i = 1, x, y, t; i <= m; i++) {
//		cin >> x >> y >> t;
//		des[x][y] = min(des[x][y], t);
//		safe[x][y] = false;
//		for (int d = 0; d < 4; d++) {
//			int nx = x + dx[d];
//			int ny = y + dy[d];
//			if (nx >= 0 && ny >= 0) {
//				des[nx][ny] = min(des[nx][ny], t);
//				safe[nx][ny] = false;
//			}
//		}
//	}
//	queue<pair<int, int>>q;
//	q.push({ 0,0 });
//	int tim = 0;
//	vis[0][0] = 1;
//	while (!q.empty()) {
//		int siz = q.size();
//		while (siz--) {
//			auto [x, y] = q.front();
//			q.pop();
//			if (safe[x][y]) {
//				cout << tim << endl;
//				return 0;
//			}
//			for (int d = 0; d < 4; d++) {
//				int nx = x + dx[d];
//				int ny = y + dy[d];
//				if (nx < 0 || ny < 0||tim+1>=des[nx][ny]||vis[nx][ny])continue;
//				q.push({ nx,ny });
//				vis[nx][ny] = 1;
//			}
//		}
//		tim++;
//	}
//	cout << -1 << endl;
//}



////1i
//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int r;
//	cin >> r;
//	vector<vector<int>>row(r + 1);
//	vector<vector<int>>dp(r + 1,vector<int>(r+1,0));
//	for (int i = 1; i <= r; i++) {
//		row[i].resize(i + 1);
//		for (int j = 1; j <= i; j++) {
//			cin >> row[i][j];
//			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + row[i][j];
//		}
//	}
//	int mx = -1;
//	for (int i = 1; i <= r; i++) {
//		mx = max(mx, dp[r][i]);
//	}
//	cout << mx << endl;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n;
//	cin>>n;
//	int ans = INT_MIN;
//	int pre = 0;
//	for (int i = 1,v; i <= n; i++) {
//		cin >> v;
//		if (pre < 0) {
//			pre = v;
//		}
//		else {
//			pre = v + pre;
//		}
//		ans = max(ans, pre);
//	}
//	cout << ans << endl;
//}



//#include<bits/stdc++.h>
//using namespace std;
//int p1[100005];
//int p2[100005];
//int val[100005];	
//int n;
//int lowbit(int x) {
//	return x & (-x);
//}
//void upd(int p, int x) {
//	while (p <= n) {
//		val[p] = max(val[p], x);
//		p += lowbit(p);
//	}
//}
//int query(int p) {
//	int ans = 0;
//	while (p > 0) {
//		ans = max(ans, val[p]);
//		p -= lowbit(p);
//	}
//	return ans;
//}
//int main() {
//	cin >> n;
//	vector<int>pi(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> p1[i];
//		pi[p1[i]] = i;
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> p2[i];
//	}
//	int ans = 0;
//	for (int i = 1,tmp; i <= n; i++) {
//		tmp = query(pi[p2[i]] - 1) + 1;
//		upd(pi[p2[i]], tmp);
//		ans = max(ans, tmp);
//	}
//	cout << ans << endl;
//}



//#include<bits/stdc++.h>
//using namespace std;
//int mx[100005];
//int n;
//int lowbit(int x) {
//	return x & (-x);
//}
//void upd(int x, int v) {
//	while (x <= n) {
//		mx[x] = max(mx[x], v);
//		x += lowbit(x);
//	}
//}
//int query(int x) {
//	int ans = 0;
//	while (x > 0) {
//		ans = max(ans, mx[x]);
//		x -= lowbit(x);
//	}
//	return ans;
//}
//int main() {
//	vector<int>a;
//	a.push_back(0);
//	int tmp;
//	vector<int>vsort;
//	while (cin >> tmp) {
//		a.push_back(tmp);
//		vsort.push_back(tmp);
//	}
//	n = a.size()-1;
//	sort(vsort.begin(), vsort.end());
//	vsort.erase(unique(vsort.begin(), vsort.end()), vsort.end());
//	for (int i = 1; i <= n; i++) {
//		a[i] = lower_bound(vsort.begin(), vsort.end(), a[i]) - vsort.begin() + 1;
//	}
//	int ans = 0;
//	for (int i = 0; i < 100005; i++) {
//		mx[i] = INT_MIN;
//	}
//	reverse(a.begin() + 1, a.end());
//	for (int i = 1; i <= n; i++) {
//		int cur = query(a[i]) + 1;
//		ans = max(ans,cur);
//		upd(a[i], cur);
//		//cout << cur << " " << ans << "**\n";
//	}
//	cout << ans << endl;
//	ans = 0;
//	for (int i = 0; i < 100005; i++) {
//		mx[i] = INT_MIN;
//	}
//	reverse(a.begin() + 1, a.end());
//	for (int i = 1; i <= n; i++) {
//		int cur = query(a[i]-1) + 1;
//		ans = max(ans, cur);
//		upd(a[i], cur);
//	}
//	cout << ans << endl;
//}

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int inf = 1e18;
//int a[105][105];
//int dp[105][105];
//int from[105][105];
//int f, v;
//signed main() {
//	cin >> f >> v;
//	for (int i = 1; i <= f; i++) {
//		for (int j = 1; j <= v; j++) {
//			dp[i][j] = -inf;
//			cin >> a[i][j];
//		}
//	}
//	for (int j = 1; j <= v; j++) {
//		dp[1][j] = a[1][j];
//	}
//	for (int i = 2; i <= f; i++) {
//		for (int j = 1; j <= v; j++) {
//			for (int k = 1; k < j; k++) {
//				if (dp[i-1][k] + a[i][j] > dp[i][j]) {
//					dp[i][j] = dp[i-1][k] + a[i][j];
//					from[i][j] = k;
//				}
//			}
//		}
//	}
//	int mx = -inf;
//	int c = -1;
//	for (int j = 1; j <= v; j++) {
//		if (dp[f][j] > mx) {
//			mx = dp[f][j];
//			c = j;
//		}
//	}
//	stack<int>sta;
//	for (int i = f; i >= 1; i--) {
//		sta.push(c);
//		c = from[i][c];
//	}
//	cout << mx << endl;
//	while (!sta.empty()) {
//		cout << sta.top() << " ";
//		sta.pop();
//	}cout << endl;
//}
//


//#include<bits/stdc++.h>
//using namespace std;
//int dp[1005];
//int main() {
//	int T, m;
//	cin >> T >> m;
//	for (int i = 1,t,v; i <= m; i++) {
//		cin >> t >> v;
//		for (int j = T; j >= t; j--) {
//			dp[j] = max(dp[j - t] + v, dp[j]);
//		}
//	}
//	cout << dp[T] << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int g[10][10];
//int n;
//int dp[10][10][10];
//signed main() {
//	cin >> n;
//	int x, y, v;
//	while (true) {
//		cin >> x>> y >> v;
//		if (x == 0)break;
//		g[x][y] = v;
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			for (int k = 1; k <= min(n,i+j-1); k++) {
//				int l = i + j - k;
//				dp[i][j][k] = max({ dp[i - 1][j][k], dp[i - 1][j][k - 1], dp[i][j - 1][k], dp[i][j-1][k - 1] }) + g[i][j]+(i==k?0:g[k][l]);
//			}
//		}
//	}
//	cout << dp[n][n][n] << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int dp[10000005];
//signed main() {
//	int t, m;
//	cin >> t >> m;
//	for (int i = 1,a,b; i <= m; i++) {
//		cin >> a >> b;
//		for (int j = a; j <= t; j++) {
//			dp[j] = max(dp[j - a]+b, dp[j]);
//		}
//	}
//	cout << dp[t] << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int dp[405][405];
//signed main() {
//	int h, t,n;
//	cin >> h >> t >> n;
//	for (int i = 1,hi,ti,ki; i <= n; i++) {
//		cin >> hi >> ti >> ki;
//		for (int j = h; j >= hi; j--) {
//			for (int k = t; k >= ti; k--) {
//				dp[j][k] = max(dp[j][k], dp[j - hi][k - ti] + ki);
//			}
//		}
//	}
//	cout << dp[h][t] << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int dp[100005];
//signed main() {
//	int n, w;
//	cin >> n >> w;
//	for (int i = 1,vi,wi,mi; i <= n; i++) {
//		cin >> vi >> wi >> mi;
//		for (int m = 0; m < wi; m++) {
//			deque<int>dq;
//			int l = w - m - (mi + 1) * wi;
//			auto cal = [&](int p,int j)->int {
//				//cout << p << " " << j << " "<<dp[p] + (j - p) / wi * vi<<"\n";
//				return dp[p] + (j - p) / wi * vi;
//				};
//			for (int j = 0; j <= mi; j++) {
//				int tmp = w - m - j * wi;
//				if (tmp < 0)break;
//				while (!dq.empty() && cal(tmp, w-m) >= cal(dq.back(), w-m)) {
//					dq.pop_back();
//				}
//				//cout << l << "%\n";
//				dq.push_back(tmp);
//				//cout << w - m - j * wi << "*\n";
//			}
//			for (int j =w- m; j >=0; j -= wi,l-=wi) {
//				//cout << i << " "<<m<<" " << j << " " << l << endl;
//				while (!dq.empty() && dq.front() > j)dq.pop_front();
//				dp[j] = dp[dq.front()] + (j - dq.front()) / wi * vi;
//				//cout <<dq.front()<<" "<< dp[j] << endl;
//				if (l >= 0) {
//					while (!dq.empty() && cal(l,j) >= cal(dq.back(),j)) {
//						dq.pop_back();
//					}
//					//cout << l << "%\n";
//					dq.push_back(l);
//				}
//			}
//		}
//		//for (int j = 0; j <= w; j++) {
//		//	cout << dp[j] << " ";
//		//}cout << endl;
//	}
//	cout << dp[w] << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//signed main() {
//	string ts, te;
//	int n;
//	cin >> ts >> te>>n;
//	int start=0, end = 0,tmp=0;
//	for (int i = 0; i < ts.size(); i++) {
//		if (ts[i] == ':') {
//			start += tmp * 60;
//			tmp = 0;
//			continue;
//		}
//		tmp *= 10;
//		tmp += ts[i] - '0';
//	}
//	start += tmp;
//	tmp = 0;
//	for (int i = 0; i < te.size(); i++) {
//		if (te[i] == ':') {
//			end += tmp * 60;
//			tmp = 0;
//			continue;
//		}
//		tmp *= 10;
//		tmp += te[i] - '0';
//	}
//	end += tmp;
//	int cap = end - start;
//	vector<pair<int, int>>item;
//	for (int i = 1,ti,ci,pi; i <= n; i++) {
//		cin >> ti >> ci >> pi;
//		if (pi == 0) {
//			for (int u = 1; u * ti <= cap; u <<= 1) {
//				item.push_back({ u * ci,u * ti });
//			}
//		}
//		else {
//			for (int u = 1; pi >= u; u <<= 1) {
//				item.push_back({ u * ci,u * ti });
//				pi -= u;
//			}
//			item.push_back({ pi * ci,pi * ti });
//		}
//	}
//	vector<int>dp(cap + 1);
//	for (auto [v, w] : item) {
//		for (int i = cap; i >= w; i--) {
//			dp[i] = max(dp[i], dp[i - w] + v);
//		}
//	}
//	cout << dp[cap] << endl;
//}

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int dp[1005];
//signed main() {
//	int m, n;
//	cin >> m >> n;
//	vector <array<int, 3>>item;
//	for (int i = 1,a,b,c; i <= n; i++) {
//		cin >> a >> b >> c;
//		item.push_back({ a,b,c });
//	}
//	sort(item.begin(), item.end(), [&](auto x, auto y) {
//		return x[2] < y[2];
//		});
//	for (int l = 0,r=0; l < item.size();) {
//		while (r<item.size() && item[r][2] == item[l][2]) {
//			r++;
//		}
//		for (int i = m; i >= 0; i--) {
//			for (int j = l; j < r; j++) {
//				if (i < item[j][0])continue;
//				dp[i] = max(dp[i], dp[i - item[j][0]] + item[j][1]);
//			}
//		}
//		l = r;
//	}
//	cout << dp[m] << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//struct item {
//	int v;
//	int k;
//	vector<item>son;
//	item(int v, int k) {
//		this->v = v;
//		this->k = k;
//	}
//	item() {
//
//	}
//};
//int dp[32005];
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	map<int, item>mp;
//	for (int i = 1, v, p, q; i <= m; i++) {
//		cin >> v >> p >> q;
//		if (q == 0) {
//			if (!mp.count(i))
//				mp[i] = item(v, p*v);
//			else {
//				mp[i].v = v;
//				mp[i].k = p*v;
//			}
//		}
//		else {
//			if (!mp.count(q)) {
//				mp[q] = item(0, 0);
//				mp[q].son.push_back(item(v, p * v));
//			}
//			else {
//				mp[q].son.push_back(item(v, p * v));
//			}
//		}
//
//	}
//	for (auto& [a, item] : mp) {
//		for (int i = n; i >= 0; i--) {
//			if (i >= item.v) {
//				dp[i] = max(dp[i - item.v] + item.k, dp[i]);
//				for (auto& t : item.son) {
//					if (i - item.v - t.v >= 0) {
//						dp[i] = max(dp[i], dp[i - item.v - t.v] + item.k + t.k);
//					}
//				}
//				if (item.son.size() > 1) {
//					if (i - item.v - item.son[0].v - item.son[1].v >= 0) {
//						dp[i] = max(dp[i], dp[i - item.v - item.son[0].v - item.son[1].v] + item.k + item.son[0].k + item.son[1].k);
//					}
//				}
//			}
//		}
//	}
//	cout << dp[n] << endl;
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int a[305];
//int psum[305];
//int n;
//int dp[305][305];
//signed main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		psum[i] = a[i] + psum[i - 1];
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			dp[i][j] = INT_MAX;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		dp[i][i] = 0;
//	}
//	for (int len = 2; len <= n; len++) {
//		for (int l = 1; l <= n - len+1; l++) {
//			int r = l + len-1;
//			for (int k = l; k < r; k++) {
//				dp[l][r] = min(dp[l][k] + dp[k + 1][r] + psum[r] - psum[l - 1], dp[l][r]);
//			}
//		}
//	}
//	cout << dp[1][n] << endl;
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 19650827;
//int a[1005];
//int dp[1005][1005][2];
//signed main() {
//	//doneky
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		dp[i][i][0] =dp[i][i][1]= 1;
//	}
//	for (int len = 2; len <= n; len++) {
//		for (int l = 1; l <= n - len + 1; l++) {
//			int r = l + len - 1;
//			if (a[l] < a[l + 1]) {
//				dp[l][r][0] += dp[l + 1][r][0];
//			}
//			dp[l][r][0] %= mod;
//			if (a[l] < a[r]&&l+1!=r) {
//				dp[l][r][0] += dp[l + 1][r][1];
//			}
//			if (a[r] > a[r - 1]) {
//				dp[l][r][1] += dp[l][r - 1][1];
//			}
//			dp[l][r][1] %= mod;
//			if (a[r] > a[l] && r - 1 != l) {
//				dp[l][r][1] += dp[l][r - 1][0];
//			}
//			dp[l][r][0] %= mod;
//			dp[l][r][1] %= mod;
//		}
//	}
//	cout << (dp[1][n][0] + dp[1][n][1]) % mod << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int dp[105][105];
//int n;
//int a[105];
//signed main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	for (int len = 2; len <= n; len++) {
//		for (int l = 0; l < n; l++) {
//			int r = (l + len - 1) % n;
//			for (int k = l; k != r; k = (k + 1) % n) {
//				dp[l][r] = max(dp[l][k] + dp[(k + 1) % n][r] + a[l] * a[(k + 1) % n] * a[(r + 1)%n], dp[l][r]);
//			}
//		}
//	}
//	int ans = -1;
//	for (int i = 0; i < n; i++) {
//		ans = max(ans, dp[i][(i + n - 1) % n]);
//	}
//	cout << ans << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int g[85][85];
//int dp[85][85];
//int n, m;
//int run(int row) {
//	for (int i = 1; i <= m; i++) {
//		dp[i][i] = g[row][i] * (1ll << m);
//	}
//	for (int len = 2; len <= m; len++) {
//		for (int l = 1; l <= m - len + 1; l++) {
//			int r = l + len - 1;
//			dp[l][r] = max(dp[l][r - 1] + (1ll << (m - len + 1)) * g[row][r], dp[l + 1][r] + (1ll << (m - len + 1)) * g[row][l]);
//		}
//	}
//	return dp[1][m];
//}
//signed main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> g[i][j];
//		}
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++)ans+=run(i);
//	cout << ans << endl;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int dp[250][250];
//bool to1[250][250];
//int a[250];
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		dp[i][i] = a[i];
//		to1[i][i] = 1;
//	}
//	for (int len = 2; len <= n; len++) {
//		for (int l = 1; l <= n - len + 1; l++) {
//			int r = l + len - 1;
//			for (int k = l; k < r; k++) {
//				dp[l][r] = max({ dp[l][r],dp[l][k], dp[k + 1][r] });
//				if (to1[l][k] && to1[k + 1][r] && dp[l][k] == dp[k + 1][r]) {
//					dp[l][r] = dp[l][k] + 1;
//					to1[l][r] = 1;
//				}
//			}
//		}
//	}
//	cout << dp[1][n] << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int inf = 1e17;
//int a[55];
//int p[55];
//int psum[55];
//int asum[55];
//int dp[55][55][2];
//int n,c;
//int sump(int l, int r) {
//	return psum[r] - psum[l - 1];
//}
//signed main() {
//	cin >>n>>c;
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i]>>p[i];
//		sum += p[i];
//		psum[i] = p[i] + psum[i - 1];
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			dp[i][j][0] = dp[i][j][1] = inf;
//		}
//	}
//	dp[c][c][0] =dp[c][c][1]= 0;
//	for (int l = c; l >= 1; l--) {
//		for (int r = max(l+1,c); r <= n; r++) {
//			dp[l][r][0] = min({
//				dp[l + 1][r][0] + (sum - sump(l + 1, r))*(a[l+1]-a[l]),
//				dp[l + 1][r][1] + (sum - sump(l + 1,r)) * (a[r] - a[l])
//				});
//			dp[l][r][1] = min({
//				dp[l][r - 1][1] + (sum - sump(l,r - 1)) * (a[r] - a[r - 1]),
//				dp[l][r - 1][0] + (sum - sump(l,r - 1)) * (a[r]-a[l])
//				});
//		}
//	}
//	cout << min(dp[1][n][0], dp[1][n][1]) << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int a[16005];
//int n;
//vector<vector<int>>g;
//pair<int,int> dfs(int u, int fa) {
//	pair<int, int>ans = { INT_MIN,a[u]};
//	for (auto v : g[u])if (v != fa) {
//		auto p = dfs(v, u);
//		ans.first = max({ans.first, p.first, p.second});
//		ans.second += max(0ll, p.second);
//	}
//	return ans;
//}
//signed main() {
//	cin >> n;
//	g.assign(n + 1, {});
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1,a,b; i < n; i++) {
//		cin >> a >> b;
//		g[a].push_back(b);
//		g[b].push_back(a);
//	}
//	auto p=dfs(1, 0);
//	cout << max(p.first, p.second) << endl;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int n;
//int a[6005];
//int fa[6005];
//vector<vector<int>>son;
//pair<int,int> dfs(int u) {
//	pair<int, int>ans = { 0,a[u] };
//	for (auto v : son[u]) {
//		auto p = dfs(v);
//		ans.first += max({p.first, p.second,0 });
//		ans.second += max(0,p.first);
//	}
//	//cout << u << " " << ans.first << " " << ans.second << endl;
//	return ans;
//}
//int main() {
//	cin >> n;
//	son.assign(n + 1, {});
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1,l,k; i < n; i++) {
//		cin >> l >> k;
//		fa[l] = k;
//		son[k].push_back(l);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!fa[i]) {
//			auto p=dfs(i);
//			cout << max(p.first, p.second) << endl;
//			break;
//		}
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//int n, q;
//struct edg {
//	int to;
//	int ap;
//	edg() {
//
//	}
//	edg(int to,int ap) {
//		this->to = to;
//		this->ap = ap;
//	}
//};
//int dp[105][105];
//int brh[105];
//vector<vector<edg>>g;
//void dfs(int u, int fa) {
//	vector<edg>son;
//	for (auto v : g[u]) {
//		if (v.to != fa) {
//			dfs(v.to, u);
//			son.push_back(v);
//			brh[u] += brh[v.to];
//			brh[u]++;
//		}
//	}
//	if (son.empty()) {
//		return;
//	}
//	if (son.size() == 1) {
//		for (int i = 0; i <= brh[son[0].to]; i++) {
//			dp[u][i] = dp[son[0].to][i]+son[0].ap;
//		}
//	}
//	else if (son.size() == 2) {
//		for (int i = 0; i <= brh[u]-2; i++) {
//			for(int j=0;j<=i&&j<=brh[son[0].to];j++){
//				int k = i - j;
//				if (k > brh[son[1].to])continue;
//				dp[u][i] = max(dp[u][i], dp[son[0].to][j] + dp[son[1].to][k] + son[0].ap + son[1].ap);
//			}
//		}
//		for (int i = 0; i <brh[u]; i++) {
//			int mustcut = max(0,i - 1 - brh[son[1].to]);
//			dp[u][i] = max(dp[u][i],dp[son[0].to][mustcut] + son[0].ap);
//		}
//		for (int i = 0; i < brh[u]; i++) {
//			int mustcut = max(0, i - 1 - brh[son[0].to]);
//			dp[u][i] = max(dp[u][i],dp[son[1].to][mustcut] + son[1].ap);
//		}
//	}
//	
//}
//int main() {
//	cin >> n >> q;
//	g.assign(n + 1, {});
//	for (int i = 1,x,y,apple; i < n; i++) {
//		cin >> x >> y >> apple;
//		g[x].push_back(edg(y, apple));
//		g[y].push_back(edg(x, apple));
//	}
//	dfs(1, 0);
//	cout << dp[1][n - 1 - q] << endl;
//	//for (int i = 1; i <= n; i++) {
//	//	cout << brh[i] << "*\n";
//	//	for (int j = 0; j <= brh[i]; j++) {
//	//		cout << dp[i][j] << " ";
//	//	}cout << endl;
//	//}
//}


//#include<bits/stdc++.h>
//using namespace std;
//int dp[305][305];
//int n, m;
//int a[305];
//int siz[305];
//int fa[305];
//vector<vector<int>>g;
//void dfs(int u) {
//	siz[u] = 1;
//	dp[u][1] = a[u];
//	for (auto v : g[u]) {
//		dfs(v);
//		siz[u] += siz[v];
//	}
//	for (auto v : g[u]) {
//		for (int i = min(m,siz[u]); i >= 1; i--) {
//			for (int j = 0; j <= min(i-1, siz[v]); j++)
//				dp[u][i] = max(dp[u][i], dp[v][j] + dp[u][i - j]);
//		}
//	}
//}
//int main() {
//	cin >> n>>m;
//	g.assign(n + 1, {});
//	for (int i = 1; i <= n; i++) {
//		cin >> fa[i] >> a[i];
//		g[fa[i]].push_back(i);
//	}
//	m++;
//	dfs(0);
//	cout << dp[0][m] << endl;
//	//for (int i = 0; i <= n; i++) {
//	//	for (int j = 0; j <= m+1; j++) {
//	//		cout << dp[i][j] << " ";
//	//	}cout << endl;
//	//}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n, m;
//vector<vector<pair<int,int>>>g;
//int a[3005];
//bool gotfa[3005];
//int dp[3005][3005];//u子树内，为得到i个用户会花(赚)的钱,数值尽可能大
//int leaf[3005];
//void dfs(int u) {
//	if (u > n - m) {
//		leaf[u] = 1;
//		dp[u][1] = a[u];
//	}
//	for (auto v : g[u]) {
//		dfs(v.first);
//		leaf[u] += leaf[v.first];
//	}
//	for (auto [v,c] : g[u]) {
//		for (int i = leaf[u]; i >= 0; i--) {
//			for (int j = 0; j <= min(i,leaf[v]); j++) {
//				dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[v][j] - c);
//			}
//		}
//	}
//}
//signed main() {
//	cin >> n >> m;
//	g.assign(n + 1, {});
//	for (int i = 1,k; i <= n - m; i++) {
//		cin >> k;
//		for (int j = 1,u,c; j <= k; j++) {
//			cin >> u >> c;
//			g[i].push_back({ u,c });
//			gotfa[u] = 1;
//		}
//	}
//	for (int i = n-m+1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			dp[i][j] = INT_MIN;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!gotfa[i]) {
//			dfs(i);
//			break;
//		}
//	}
//	for (int i = leaf[1]; i >= 0; i--) {
//		if (dp[1][i] >= 0) {
//			cout << i << endl;
//			break;
//		}
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	for (int j = 0; j <= m; j++) {
//	//		cout << dp[i][j] << " ";
//	//	}cout << endl;
//	//}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//vector<vector<pair<int,int>>>g;
//int mn[500005];
//int mx[500005];
//int ans = 0;
//void dfs(int u,int fa) {
//	for (auto [v, c] : g[u]) {
//		if (v == fa)continue;
//		dfs(v, u);
//		mx[u] = max(mx[u], mx[v]+c);
//	}
//	for (auto [v, c] : g[u]) {
//		if (v == fa)continue;
//		ans += max(0ll, mx[u] - mx[v]-c);
//	}
//}
//signed main() {
//	int n;
//	cin >> n;
//	g.assign(n + 1, {});
//	int s;
//	cin >> s;
//	for (int i = 1,a,b,t; i < n; i++) {
//		cin >> a >> b >> t;
//		g[a].push_back({ b,t });
//		g[b].push_back({a,t});
//	}
//	dfs(s, 0);
//	cout << ans << endl;
//}
//1
//|
//2
//|
//3
//|
//4
//|
//5
//|
//6
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//vector<vector<int>>g;
//int dp[1005][5];
//int dpm[1005][5];
////0自己有且全覆盖
////1儿子有且全覆盖
////2孙子有且全覆盖
////3自己未覆盖但其余全覆盖
////4自己儿子未覆盖其余全覆盖
//signed main() {
//	int n;
//	cin >> n;
//	g.assign(n + 1, {});
//	for (int i = 2,u; i <= n; i++) {
//		cin >> u;
//		g[u].push_back(i);
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= 4; j++) {
//			dp[i][j]=dpm[i][j] = INT_MAX;
//		}
//	}
//	for (int i = n; i >= 1; i--) {
//		dp[i][0] = 1;
//		//cout << dp[i][0] << " " << i << "&&\n";
//		int sum1 = 0;
//		int sum2 = 0;
//		int sum3 = 0;
//		int sum4 = 0;
//		for (auto v : g[i]) {
//			//cout << v << "v!\n";
//			//cout<<dpm[v][4]<<""
//			dp[i][0] += dpm[v][4];
//			sum1 += dpm[v][3];
//			sum2 += dpm[v][2];
//			sum3 += dp[v][2];
//			sum4 += dp[v][3];
//		}
//		//cout << dp[i][0] << "try1\n";
//		//cout << sum1 << " " << sum2 << " " << sum3 << " " << sum4 << " __\n";
//		dp[i][3] = sum3;
//		dp[i][4] = sum4;
//		for (auto v : g[i]) {
//			dp[i][1] = min(dp[i][1], sum1 - dpm[v][3] + dp[v][0]);
//			//cout << sum1 << " " << dp[v][3] << " " << dp[v][0] << endl;
//			//cout << sum1 - dp[v][3] + dp[v][0] << "%%\n";
//			dp[i][2] = min(dp[i][2], sum2 - dpm[v][2] + dp[v][1]);
//		}
//		for (int j = 0; j <= 4; j++) {
//			dpm[i][j] = dp[i][j];
//		}
//		for (int j = 1; j <= 4; j++) {
//			dpm[i][j] = min(dpm[i][j],dpm[i][j-1]);
//			dp[i][j] = dpm[i][j];
//		}
//		//cout << dp[i][0] << "\n-------------\n";
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	for (int j = 0; j <= 4; j++) {
//	//		cout << '('<<dp[i][j] << "," << dpm[i][j]<<") ";
//	//	}cout << endl;
//	//}
//	cout << dpm[1][2] << endl;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	deque<int>dqmn;
//	deque<int>dqmx;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	auto pushmn = [&](int i) {
//		while (!dqmn.empty() && a[dqmn.back()] > a[i]) {
//			dqmn.pop_back();
//		}
//		dqmn.push_back(i);
//		};
//	auto pushmx = [&](int i) {
//		while (!dqmx.empty() && a[dqmx.back()] < a[i]) {
//			dqmx.pop_back();
//		}
//		dqmx.push_back(i);
//		};
//	auto popmn = [&](int i) {
//		while (!dqmn.empty() && dqmn.front() < i) {
//			dqmn.pop_front();
//		}
//		};
//	auto popmx = [&](int i) {
//		while (!dqmx.empty() && dqmx.front() < i) {
//			dqmx.pop_front();
//		}
//		};
//	for (int i = 1; i <= k-1; i++) {
//		pushmn(i);
//		pushmx(i);
//	}
//	vector<int>mn;
//	vector<int>mx;
//	for (int r = k,l=1; r <= n; r++,l++) {
//		pushmn(r);
//		pushmx(r);
//		popmn(l);
//		popmx(l);
//		mx.push_back(a[dqmx.front()]);
//		mn.push_back(a[dqmn.front()]);
//	}
//	for (auto v : mn)cout << v << " ";
//	cout << endl;
//	for (auto v : mx)cout << v << " ";
//	cout << endl;
//}



//#include<bits/stdc++.h>
//using namespace std;
//int cnt[2005];
//int main() {
//	int n, m, ap = 0;
//	cin >> n >> m;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int ans = INT_MAX, x = -1, y = -1;
//	for (int i = 1, r = 1; i <= n; i++) {
//		while (r<=n&&ap != m) {
//			cnt[a[r]]++;
//			if (cnt[a[r]] == 1)ap++;
//			r++;
//		}
//		if (r - i < ans&&ap==m) {
//			ans = r - i;
//			x = i, y = r-1;
//		}
//		if (--cnt[a[i]] == 0) {
//			ap--;
//		}
//	}
//	cout << x << " " << y << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int g[1005][1005];
//int gmx[1005][1005];
//int gmn[1005][1005];
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int a, b, n;
//	cin >> a >> b >> n;
//	for (int i = 1; i <= a; i++) {
//		for (int j = 1; j <= b; j++) {
//			cin >> g[i][j];
//		}
//	}
//	deque<pair<int, int>>mx;
//	deque<pair<int, int>>mn;
//	auto pushmx = [&](int i, int j) {
//		while (!mx.empty() && g[mx.back().first][mx.back().second] < g[i][j]) {
//			mx.pop_back();
//		}
//		mx.push_back({ i,j });
//		};
//	auto pushmx1 = [&](int i, int j) {
//		while (!mx.empty() && gmx[mx.back().first][mx.back().second] < gmx[i][j]) {
//			mx.pop_back();
//		}
//		mx.push_back({ i,j });
//		};
//	auto popmx = [&](int i, int j) {
//		while (!mx.empty() && (mx.front().first < i || mx.front().second < j)) {
//			mx.pop_front();
//		}
//		};
//	auto pushmn = [&](int i, int j) {
//		while (!mn.empty() && g[mn.back().first][mn.back().second] > g[i][j]) {
//			mn.pop_back();
//		}
//		mn.push_back({ i,j });
//		};
//	auto pushmn1 = [&](int i, int j) {
//		while (!mn.empty() && gmn[mn.back().first][mn.back().second] > gmn[i][j]) {
//			mn.pop_back();
//		}
//		mn.push_back({ i,j });
//		};
//	auto popmn = [&](int i, int j) {
//		while (!mn.empty() && (mn.front().first < i || mn.front().second < j)) {
//			mn.pop_front();
//		}
//		};
//
//	for (int j = 1; j<= b; j++) {
//		int i;
//		for (i = 1; i <= n - 1; i++) {
//			pushmx(i, j);
//			pushmn(i, j);
//		}
//		for (; i <= a; i++) {
//			pushmx(i, j);
//			pushmn(i, j);
//			popmx(i-n+1, j);
//			popmn(i-n+1, j);
//			gmx[i-n+1][j] = g[mx.front().first][j];
//			gmn[i-n+1][j] = g[mn.front().first][j];
//		}
//		while (!mx.empty()) {
//			mx.pop_back();
//		}
//		while (!mn.empty()) {
//			mn.pop_back();
//		}
//	}
//	//for (int i = 1; i <= a; i++) {
//	//	for (int j = 1; j <= b; j++) {
//	//		cout << "(" << gmx[i][j] << "," << gmn[i][j] << ") ";
//	//	}cout << endl;
//	//}
//	int ans = LLONG_MAX;
//	for (int i = 1; i + n - 1 <= a; i++) {
//		int j;
//		while (!mx.empty()) {
//			mx.pop_back();
//		}
//		while (!mn.empty()) {
//			mn.pop_back();
//		}
//		for (j = 1; j <= n - 1; j++) {
//			pushmx1(i, j);
//			pushmn1(i, j);
//		}
//		for (; j <= b; j++) {
//			pushmx1(i, j);
//			pushmn1(i, j);
//			popmx(i, j - n + 1);
//			popmn(i, j - n + 1);
//			ans = min(ans, gmx[mx.front().first][mx.front().second] - gmn[mn.front().first][mn.front().second]);
//		}
//	}
//	cout << ans << endl;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int fa[200005];
//int siz[200005];
//int find(int x) {
//	if (x != fa[x]) {
//		fa[x] = find(fa[x]);
//	}
//	return fa[x];
//}
//void merge(int x, int y) {
//	int fx = find(x);
//	int fy = find(y);
//	if (fx == fy) {
//		return;
//	}
//	if (siz[fx] > siz[fy])swap(fx, fy);
//	fa[fx] = fy;
//	siz[fy] += siz[fx];
//}
//bool isSame(int x, int y) {
//	return find(x) == find(y);
//}
//int main(){
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)fa[i] = i,siz[i]=1;
//	for (int i = 1,z,x,y; i <= m; i++) {
//		cin >> z >> x >> y;
//		if (z == 1)merge(x, y);
//		else {
//			cout << (isSame(x, y) ? 'Y' : 'N') << endl;
//		}
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//int fa[1005];
//int siz[1005];
//int n, k;
//pair<double, double>a[1005];
//const double eps = 1e-5;
//void build() {
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//		siz[i] = 1;
//	}
//}
//int find(int x) {
//	if (x != fa[x]) {
//		fa[x] = find(fa[x]);
//	}
//	return fa[x];
//}
//bool isSame(int x, int y) {
//	return find(x) == find(y);
//}
//void merge(int x, int y) {
//	int fx = find(x);
//	int fy = find(y);
//	if (fx == fy)return;
//	if (siz[fx] > siz[fy])swap(fx, fy);
//	fa[fx] = fy;
//	siz[fy] += siz[fx];
//}
//bool check(double m) {
//	build();
//	for (int i = 1; i <= n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			if ((a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second)* (a[i].second - a[j].second) <= m * m) {
//				merge(i, j);
//			}
//		}
//	}
//	int cnt = 0;
//	for (int i = 1; i <= n; i++) {
//		if (fa[i] == i) {
//			cnt++;
//		}
//	}
//	return cnt >= k;
//}
//int main() {
//	cin >> n >> k;
//	for (int i = 1,x,y; i <= n; i++) {
//		cin >> a[i].first>>a[i].second;
//	}
//	double l = 0, r = 1e9,ans=0;
//	while (l + eps <= r) {
//		double mid = (l + r) / 2;
//		if (check(mid)) {
//			l = mid;
//			ans = mid;
//		}
//		else {
//			r = mid;
//		}
//	}
//	cout << fixed<<setprecision(2)<<ans << endl;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int fa[1000010];
//int siz[1000010];
//void build(int n) {
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//		siz[i] = 1;
//	}
//}
//int find(int x) {
//	if (x != fa[x]) {
//		fa[x] = find(fa[x]);
//	}
//	return fa[x];
//}
//bool isSame(int x, int y) {
//	return find(x) == find(y);
//}
//void merge(int x, int y) {
//	int fx = find(x);
//	int fy = find(y);
//	if (fx == fy)return;
//	if (siz[fx] > siz[fy])swap(fx, fy);
//	fa[fx] = fy;
//	siz[fy] += siz[fx];
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<array<int, 3>>bind;
//	vector<int>vsort;
//	for (int i = 1, x, y, e; i <= n; i++){
//		cin >> x>>y >> e;
//		bind.push_back({ x,y,e });
//		vsort.push_back(x);
//		vsort.push_back(y);
//	}
//	sort(vsort.begin(), vsort.end());
//	sort(bind.begin(), bind.end(), [&](auto x,auto y) {
//		return x[2] > y[2];
//		});
//	vsort.erase(unique(vsort.begin(), vsort.end()), vsort.end());
//	build(vsort.size() + 5);
//	for (auto [x, y, e] : bind) {
//		x = lower_bound(vsort.begin(), vsort.end(), x) - vsort.begin() + 1;
//		y = lower_bound(vsort.begin(), vsort.end(), y) - vsort.begin() + 1;
//		if (e == 1) {
//			merge(x, y);
//		}
//		else {
//			if (isSame(x, y)) {
//				cout << "NO\n";
//				return;
//			}
//		}
//	}
//	cout << "YES\n";
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
//const int N = 1e5 + 5;
//int sum[N << 2];
//int tag[N << 2];
//int a[N];
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//void lazy(int i, int v,int n) {
//	sum[i] += v * n;
//	tag[i] += v;
//}
//void down(int i, int ln, int rn) {
//	if (tag[i] != 0) {
//		lazy(i << 1, tag[i], ln);
//		lazy(i << 1|1, tag[i], rn);
//		tag[i] = 0;
//	}
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = a[l];
//		return;
//	}
//	int mid = l + r >> 1;
//	build(l, mid,i<<1);
//	build(mid + 1, r,i<<1|1);
//	up(i);
//}
//void rangeAdd(int v, int l, int r, int jl, int jr ,int i) {
//	if (l > jr || r < jl)return;
//	if (l >= jl && r <= jr) {
//		lazy(i, v, r - l + 1);
//		return;
//	}
//	int m = l + r >> 1;
//	down(i, m - l + 1, r - m);
//	rangeAdd(v, l, m, jl, jr, i << 1);
//	rangeAdd(v, m+1, r, jl, jr, i << 1|1);
//	up(i);
//}
//int query(int l, int r, int jl, int jr, int i) {
//	if (l > jr || r < jl) {
//		return 0;
//	}
//	if (l >= jl && r <= jr)return sum[i];
//	int m = l + r >> 1;
//	down(i, m - l + 1, r - m);
//	return query(l, m, jl, jr, i << 1) + query(m + 1, r, jl, jr, i << 1 | 1);
//}
//signed main() {
//	int n,m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	build(1, n, 1);
//	for (int i = 1,op,x,y,k; i <= m; i++) {
//		cin >> op;
//		if (op == 1) {
//			cin >> x >> y >> k;
//			rangeAdd(k, 1, n, x, y, 1);
//		}
//		else {
//			cin >> x >> y;
//			cout << query(1,n, x, y, 1) << endl;
//		}
//	}
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 5;
//int mod;
//int sum[N<<2];
//int tagM[N << 2];
//int tagA[N << 2];
//int a[N];
//void lazyM(int i, int v) {
//	tagM[i] =tagM[i]* v%mod;
//	tagA[i] =tagA[i]* v%mod;
//	sum[i] = sum[i] * v % mod;
//}
//void lazyA(int i, int v,int n) {
//	tagA[i] = (tagA[i] + v) % mod;
//	sum[i] = (sum[i] + n * v % mod) % mod;
//}
//void up(int i) {
//	sum[i] = (sum[i << 1] + sum[i << 1 | 1])%mod;
//}
//void down(int i,int ln,int rn) {
//	if (tagM[i] != 1) {
//		lazyM(i << 1, tagM[i]);
//		lazyM(i << 1|1, tagM[i]);
//		tagM[i] = 1;
//	}
//	if (tagA[i] != 0) {
//		lazyA(i << 1, tagA[i], ln);
//		lazyA(i << 1|1, tagA[i], rn);
//		tagA[i] = 0;
//	}
//}
//void build(int l, int r, int i) {
//	tagM[i] = 1;
//	tagA[i] = 0;
//	if (l == r) {
//		sum[i] = a[l];
//		return;
//	}
//	int m = l + r >> 1;
//	build(l, m,i<<1);
//	build(m + 1, r, i<<1|1);
//	up(i);
//}
//void rmul(int v, int jl, int jr, int l, int r, int i) {
//	if (l > jr || r < jl)return;
//	if (l >= jl && r <= jr) {
//		lazyM(i, v);
//		return;
//	}
//	int m = l + r >> 1;
//	down(i, m - l + 1, r - m);
//	rmul(v, jl, jr, l, m, i << 1);
//	rmul(v, jl, jr, m+1, r, i << 1|1);
//	up(i);
//}
//void radd(int v, int jl, int jr, int l, int r, int i) {
//	if (l > jr || r < jl)return;
//	if (l >= jl && r <= jr) {
//		lazyA(i, v,r-l+1);
//		return;
//	}
//	int m = l + r >> 1;
//	down(i, m - l + 1, r - m);
//	radd(v, jl, jr, l, m, i << 1);
//	radd(v, jl, jr, m+1, r, i << 1|1);
//	up(i);
//}
//int query(int jl, int jr, int l, int r, int i) {
//	if (l > jr || r < jl)return 0;
//	if (l >= jl && r <= jr)return sum[i];
//	int m = l + r >> 1;
//	down(i, m - l + 1, r - m);
//	return (query(jl, jr, l, m, i << 1) + query(jl, jr, m + 1, r, i << 1 | 1))%mod;
//}
//signed main() {
//	int n, q, m;
//	cin >> n >> q >> mod;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	build(1, n, 1);
//	for (int i = 1,op,x,y,k; i <= q; i++) {
//		cin >> op;
//		if (op == 1) {
//			cin >> x >> y >> k;
//			rmul(k, x, y, 1, n, 1);
//		}
//		else if (op == 2) {
//			cin >> x >> y >> k;
//			radd(k, x, y, 1, n, 1);
//		}
//		else {
//			cin >> x >> y;
//			cout << query(x, y, 1, n, 1)<<"\n";
//		}
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 5e5 + 5;
//int a[N];
//int n, m;
//inline int lowbit(int x) {
//	return x & (-x);
//}
//void add(int x, int v) {
//	for (int i = x; i <= n; i += lowbit(i)) {
//		a[i] += v;
//	}
//}
//int sum(int x) {
//	int ans = 0;
//	for (int i = x; i > 0; i -= lowbit(i)) {
//		ans += a[i];
//	}
//	return ans;
//}
//int range(int l, int r) {
//	return sum(r) - sum(l - 1);
//}
//signed main() {
//	cin >> n >> m;
//	for (int i = 1,u; i <= n; i++) {
//		cin >> u;
//		add(i, u);
//	}
//	for(int i=1,op,x,y;i<=m;i++){
//		cin >> op >> x >> y;
//		if (op == 1) {
//			add(x, y);
//		}
//		else {
//			cout << range(x, y) << "\n";
//		}
//	}
//}

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 5e5 + 5;
//int n, m;
//int a[N];
//int d[N];
//int lowbit(int i) {
//	return i & (-i);
//}
//void add(int x, int v) {
//	for (int i = x; i <= n; i += lowbit(i)) {
//		d[i] += v;
//	}
//}
//int sum(int x) {
//	int ans = 0;
//	for (int i = x; i > 0; i -= lowbit(i)) {
//		ans += d[i];
//	}
//	return ans;
//}
//signed main() {
//	cin >> n>>m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		add(i, a[i]-a[i-1]);
//	}
//	for (int i = 1,op,x,y,k; i <= m; i++){
//		cin >> op;
//		if (op == 1) {
//			cin >> x >> y >> k;
//			add(x, k);
//			add(y + 1, -k);
//		}
//		else {
//			cin >> x;
//			cout << sum(x)<<endl;
//		}
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 5;
//int n, m;
//int a[N];
//int b[N];
//int d[N];
//int lowbit(int i) {
//	return i & (-i);
//}
//void add(int x, int p) {
//	for (int i = x; i <= n; i+=lowbit(i)) {
//		d[i] += p;
//	}
//}
//void add1(int x, int p) {
//	for (int i = x; i <= n; i+=lowbit(i)) {
//		b[i] += p;
//	}
//}
//int sum(int x) {
//	int ans = 0;
//	for (int i = x; i > 0; i -= lowbit(i)) {
//		ans += d[i];
//	}
//	return ans;
//}
//int sum1(int x) {
//	int ans = 0;
//	for (int i = x; i > 0; i -= lowbit(i)) {
//		ans += b[i];
//	}
//	return ans;
//}
//signed main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1,op,l,r,k,d,p; i <= m; i++) {
//		cin >> op;
//		if (op == 1) {
//			cin >> l >> r >> k>>d;
//			add(l, k*l);
//			add(l + 1, (d - k)*(l+1));
//			add(r + 1, -(k + (r - l+1) * d)*(r+1));
//			add(r + 2, (k + (r - l) * d) * (r + 2));
//			add1(l, k);
//			add1(l + 1, (d - k));
//			add1(r + 1, -(k + (r - l+1) * d));
//			add1(r + 2, (k + (r - l) * d));		
//		}
//		else {
//			cin >> p;
//			cout << a[p] + (p + 1) * sum1(p) - sum(p) << endl;
//		}
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 5;
//int n, l, r;
//int a[N];
//int sub[N];
//int lowbit(int i) {
//	return i & (-i);
//}
//void add(int x) {
//	for (int i = x; i <= n+1; i+=lowbit(i)) {
//		sub[i] += 1;
//	}
//}
//int sum(int x) {
//	int ans = 0;
//	for (int i = x; i > 0; i -= lowbit(i)) {
//		ans += sub[i];
//	}
//	return ans;
//}
//int gsub(int l,int r) {
//	return sum(r) - sum(l-1);
//}
//signed main() {
//	cin >> n >> l >> r;
//	vector<pair<int, int>>p;
//	vector<int>psum(n+1);	
//	p.push_back({ -1,-1 });
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		psum[i]=psum[i-1]+ a[i];
//		p.push_back({ i,psum[i] });
//	}
//	p.push_back({ 0,psum[0] });
//	sort(p.begin()+1, p.end(), [&](auto x, auto y) {
//		return x.second < y.second;
//		});
//	vector<int>to(n + 1);
//	for (int i = 1; i <= n+1; i++) {
//		to[p[i].first] = i;
//	}
//	int ans = 0;
//	//for (int i = 1; i <= n; i++) {
//	//	cout << psum[i] << " ";
//	//}cout << " psum\n";
//	for (int i = 0; i <= n; i++) {
//		add(to[i]);
//		//cout << to[i]<< "^\n";
//		int lo = l + psum[i], hi = r + psum[i];
//		pair<int, int>lo1 = { -1,lo };
//		pair<int, int>hi1 = { -1,hi };
//		int bl = lower_bound(p.begin() + 1, p.end(), lo1, [&](auto x,auto y) {
//			return x.second < y.second;
//			})-p.begin();
//		int br = upper_bound(p.begin() + 1, p.end(), hi1, [&](auto x,auto y) {
//			return x.second < y.second;
//			}) - p.begin() - 1;
//		if (br<1 || bl>n+1)continue;//不可以是空数组
//		//cout << lo << " " << hi << " " << bl << " " << br << " " << gsub(bl+1, br+1) << " " << psum[i] << " &&\n";
//		ans += br - bl + 1 - gsub(bl, br);
//	}
//	cout << ans << endl;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int m, n;
//struct sma {
//	bool operator()(int a, int b) {
//		return a > b;
//	}
//};
//struct big {
//	bool operator()(int a, int b) {
//		return a < b;
//	}
//};
//int main() {
//	int n, m;
//	cin >> m >> n;
//	vector<int>a;
//	for (int i = 1, u; i <= m; i++) {
//		cin >> u;
//		a.push_back(u);
//	}
//	map<int, int>q;
//	for (int i = 1, u; i <= n; i++) {
//		cin >> u;
//		q[u]++;
//	}
//	int cnt = 0;
//	priority_queue<int, vector<int>, sma>mnpq;
//	priority_queue<int, vector<int>, big>mxpq;
//	int od = 1;
//	for (auto v : a) {
//		cnt++;
//		if (!mxpq.empty()&&v < mxpq.top()) {
//			mxpq.push(v);
//			//cout << v << " mx push\n";
//		}
//		else {
//			mnpq.push(v);
//			//cout << v << " mn push\n";
//		}
//		if (q.count(cnt)) {
//			for (int i = 1; i <= q[cnt]; i++) {
//				while (mxpq.size() != od - 1) {
//					if (mxpq.size() < od - 1) {
//						mxpq.push(mnpq.top());
//						mnpq.pop();
//						//cout << v << " mn pop\n";
//					}
//					else {
//						mnpq.push(mxpq.top());
//						mxpq.pop();
//						//cout << v << " mx pop\n";
//					}
//				}
//				cout << mnpq.top() << endl;
//				od++;
//			}
//		}
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 3e4 + 5;
//int n;
//int a[N];
//int rr[N];
//int ll[N];
//int lowbit(int i) {
//	return  i & (-i);
//}
//void addl(int x, int v) {
//	for (int i = x; i <= n; i+=lowbit(i)) {
//		ll[i] += v;
//	}
//}
//int suml(int x) {
//	int ans = 0;
//	for (int i = x; i > 0; i -= lowbit(i)) {
//		ans += ll[i];
//	}
//	return ans;
//}
//void addr(int x, int v) {
//	for (int i = x; i <= n; i+=lowbit(i)) {
//		rr[i] += v;
//	}
//}
//int sumr(int x) {
//	int ans = 0;
//	for (int i = x; i > 0; i -= lowbit(i)) {
//		ans += rr[i];
//	}
//	return ans;
//}
//signed main() {
//	cin >> n;
//	vector<int>vsort;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		vsort.push_back(a[i]);
//	}
//	sort(vsort.begin(), vsort.end());
//	vsort.erase(unique(vsort.begin(), vsort.end()), vsort.end());
//	for (int i = 1; i <= n; i++) {
//		a[i] = lower_bound(vsort.begin(), vsort.end(), a[i]) - vsort.begin() + 1;
//		addr(a[i], 1);
//	}
//	addl(a[1], 1);
//	addr(a[1], -1);
//	int ans = 0;
//	for (int i = 2; i < n; i++) {
//		int l = suml(a[i]-1);
//		int r = sumr(n) - sumr(a[i]);
//		ans += l * r;
//		addl(a[i], 1);
//		addr(a[i], -1);
//	}
//	cout << ans << endl;
//}

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 5;
//int sum[N << 2];
//int a[N];
//int n;
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = a[l];
//		return;
//	}
//	int m = l + r >> 1;
//	build(l, m,i<<1);
//	build(m + 1, r, i << 1 | 1);
//	up(i);
//}
//int query(int jl, int jr, int l, int r, int i) {
//	if (l > jr || r < jl)return 0;
//	if (l >= jl && r <= jr)return sum[i];
//	int m = l + r >> 1;
//	return query(jl, jr, l, m, i << 1) + query(jl, jr, m + 1, r, i << 1 | 1);
//}
//void upd(int jl, int jr, int l, int r, int i) {
//	if (l > jr || r < jl)return;
//	if (sum[i]<=r-l+1)return;
//	if (l == r) {
//		sum[i] = (sqrt(sum[i]));
//		return;
//	}
//	int m = l + r >> 1;
//	upd(jl, jr, l, m, i << 1);
//	upd(jl, jr, m+1, r, i << 1|1);
//	up(i);
//}
//signed main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	build(1, n, 1);
//	int m;
//	cin >> m;
//	for (int i = 1,k,l,r; i <= m; i++) {
//		cin >> k >> l >> r;
//		if (l > r)swap(l, r);
//		if (k == 0) {
//			upd(l, r, 1, n, 1);
//		}
//		else {
//			cout << query(l, r, 1, n, 1) << endl;
//		}
//	}
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n, k;
//const int N = 1e5 + 5;
//int a[N];
//int sub[N];
//int lowbit(int i) {
//	return i & (-i);
//}
//void add(int x, int v) {
//	for (int i = x; i <= n+1; i += lowbit(i)) {
//		sub[i] += v;
//	}
//}
//int sum(int x) {
//	int ans = 0;
//	for (int i = x; i > 0; i -= lowbit(i)) {
//		ans += sub[i];
//	}
//	return ans;
//}
//int range(int l, int r) {
//	return sum(r) - sum(l - 1);
//}
//signed main() {
//	cin >> n >> k;
//	vector<int>psum(n + 1);
//	vector<pair<int, int>>b;
//	b.push_back({ -1,-1 });
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		a[i] = a[i] - k;
//		psum[i] = a[i] + psum[i - 1];
//		b.push_back({ i,psum[i] });
//	}b.push_back({ 0,0 });
//	sort(b.begin()+1, b.end(), [&](auto x,auto y) {
//		return x.second < y.second;
//		});
//	vector<int>to(n + 1);
//	for (int i = 1; i <= n + 1; i++) {
//		to[b[i].first] = i;
//	}
//	int ans = 0;
//	//for (int i = 0; i <= n; i++) {
//	//	cout << psum[i] << " ";
//	//}cout << " psum\n";
//	for (int i = 0; i <= n; i++) {
//		add(to[i], 1);
//		pair<int, int>bd = { -1, psum[i] };
//		int bl = lower_bound(b.begin() + 1, b.end(), bd, [&](auto a, auto b) {
//			return a.second < b.second;
//			})-b.begin();
//		if (bl > n+1)continue;
//		//cout << bl << " " << range(bl,n+1) << " " << n + 1 <<" "<<to[i] << endl;
//		ans += max(0ll,n+1 - bl + 1 - range(bl, n+1));
//	}
//	cout << ans << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2e5 + 5;
//int n;
//vector<array<int, 4>>ev;
//vector<int>vsort;
//int val[N];
//int sum[N << 4];
//int cnt[N << 4];
//int cover[N << 4];
//int tag[N << 2];
//void build(int l, int r, int i){
//	if (l == r) {
//		cnt[i] = 0;
//		sum[i] = val[l];
//		cover[i]=0;
//		return;
//	}
//	int m = l + r >> 1;
//	build(l, m,i<<1);
//	build(m + 1, r, i << 1 | 1);
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//void up(int i) {
//	cover[i] = cnt[i]>0?sum[i]:cover[i << 1] + cover[i << 1 | 1];
//}
//void add(int v,int jl, int jr, int l, int r, int i) {
//	if (l > jr || r < jl)return;
//	if (l >= jl && r <= jr) {
//		cnt[i] += v;
//	}
//	else {
//		int m = l + r >> 1;
//		add(v, jl, jr, l, m, i << 1);
//		add(v, jl, jr, m+1, r, i << 1|1);
//	}
//	up(i);
//}
//
//signed main(){
//	cin >> n;
//	for (int i = 1,x1,y1,x2,y2; i <= n; i++) {
//		cin >> x1 >> y1 >> x2 >> y2;
//		vsort.push_back(y1);
//		vsort.push_back(y2);
//		ev.push_back({ x1,1,y1,y2 });
//		ev.push_back({ x2,-1,y1,y2 });
//	}
//	sort(ev.begin(), ev.end(), [&](auto& x, auto& y) {
//		if (x[0] == y[0]) {
//			return x[1] < y[1];
//		}
//		return x[0] < y[0];
//		});
//	
//	sort(vsort.begin(), vsort.end());
//	vsort.erase(unique(vsort.begin(), vsort.end()), vsort.end());
//	for (int i = 0; i < vsort.size()-1; i++) {
//		val[i + 1] = vsort[i+1] - vsort[i];
//	}
//	n = vsort.size()+1;
//	build(1, n, 1);
//	int pre = ev[0][0];
//	int ans = 0;
//	for (auto [x,ad,y1,y2] : ev) {
//		y1 = lower_bound(vsort.begin(), vsort.end(), y1) - vsort.begin() + 1;
//		y2 = lower_bound(vsort.begin(), vsort.end(), y2) - vsort.begin() + 1;
//		ans += cover[1] * (x - pre);
//		add(ad,y1, y2-1, 1, n, 1);
//		pre = x;
//	}
//	cout << ans << endl;
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 5;
//double a[N];
//int n,m;
//double sum[N<<2];
//double qsum[N << 2];
//double tag[N << 2];
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//	qsum[i] = qsum[i << 1] + qsum[i << 1 | 1];
//}
//void lazy(int i, double v,int n) {
//	qsum[i] += sum[i] * 2 * v+v*v*n;
//	sum[i] += v * n;
//	tag[i] += v;
//}
//void down(int i, int ln, int rn) {
//	if (tag[i] != 0) {
//		lazy(i << 1, tag[i],ln);
//		lazy(i << 1|1, tag[i],rn);
//		tag[i] = 0;
//	}
//}
//void add(double v, int jl, int jr, int l, int r, int i) {
//	if (l > jr || r < jl)return;
//	if (l >= jl && r <= jr) {
//		lazy(i, v, r - l + 1);
//		return;
//	}
//	int m = l + r >> 1;
//	down(i,m-l+1,r-m);
//	add(v, jl, jr, l, m, i << 1);
//	add(v, jl, jr, m+1, r, i << 1|1);
//	up(i);
//}
//double query(int jl,int jr,int l,int r,int i) {
//	if (l > jr || r < jl)return 0;
//	if (l >= jl && r <= jr)return sum[i];
//	int m = l + r >> 1;
//	down(i, m - l + 1, r - m);
//	return query(jl, jr, l, m, i << 1) + query(jl, jr, m + 1, r, i << 1 | 1);
//}
//double query1(int jl,int jr,int l,int r,int i) {
//	if (l > jr || r < jl)return 0;
//	if (l >= jl && r <= jr)return qsum[i];
//	int m = l + r >> 1;
//	down(i, m - l + 1, r - m);
//	return query1(jl, jr, l, m, i << 1) + query1(jl, jr, m + 1, r, i << 1 | 1);
//}
//void build(int l, int r, int i) {
//	tag[i] = 0;
//	if (l == r) {
//		sum[i] = a[l];
//		qsum[i] = a[l] * a[l];
//		return;
//	}
//	int m = l + r >> 1;
//	build(l, m, i << 1);
//	build(m+1, r, i << 1|1);
//	up(i);
//}
//int main() {
//	cin >> n>>m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	build(1, n, 1);
//	cout << fixed << setprecision(4);
//	double k;
//	for (int i = 1,op,x,y; i <= m; i++) {
//		cin >> op>>x>>y;
//		if (op == 1) {
//			cin >> k;
//			add(k, x, y, 1, n, 1);
//		}
//		else if (op == 2) {
//			cout << query(x, y, 1, n, 1) / (y - x + 1) << endl;
//		}
//		else {
//			double avg = query(x, y, 1, n, 1) / (y - x + 1);
//			cout << query1(x, y, 1, n, 1) / (y - x + 1) - avg * avg << endl;
//		}
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 105;
//vector<vector<int>>g;
//int ide[N];
//int main() {
//	int n;
//	cin >> n;
//	g.assign(n+1,{});
//	for (int i = 1,u; i <= n; i++) {
//		while (cin >> u) {
//			if (u == 0)break;
//			g[i].push_back(u);
//			ide[u]++;
//		}
//	}
//	queue<int>q;
//	for (int i = 1; i <= n; i++) {
//		if (ide[i] == 0) {
//			q.push(i);
//		}
//	}
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//		cout << u << " ";
//		for (auto v : g[u]) {
//			if (--ide[v] == 0)q.push(v);
//		}
//	}
//	cout << endl;
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 105;
//int g[N][N];
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			g[i][j] = INT_MAX;
//		}
//		g[i][i] = 0;
//	}
//	for (int i = 1,u,v,w; i <= m; i++) {
//		cin >> u >> v >> w;
//		g[u][v] = min(g[u][v], w);
//		g[v][u] = min(g[v][u], w);
//	}
//	for (int brg = 1; brg <= n; brg++) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				if(g[i][brg]!=INT_MAX&&g[brg][j]!=INT_MAX)
//				g[i][j] = min(g[i][j], g[i][brg] + g[brg][j]);
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for(int j=1;j<=n;j++)
//		cout << g[i][j] << " ";
//		cout << endl;
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 5;
//int dis[N];
//bool vis[N];
//int n, m, s;
//vector<vector<pair<int,int>>>g;
//struct cmp {
//	bool operator()(pair<int,int>&x,pair<int,int>&y) {
//		return x.second > y.second;
//	}
//};
//signed main() {
//	cin >> n >> m >> s;
//	g.assign(n + 1, {});
//	for (int i = 1,u,v,w; i <= m; i++) {
//		cin >> u >> v >> w;
//		g[u].push_back({ v,w });
//	}
//	for (int i = 1; i <= n; i++) {
//		dis[i] = LLONG_MAX;
//	}
//	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>pq;
//	pq.push({ s,0 });
//	dis[s] = 0;
//	while (!pq.empty()) {
//		auto [u, ww] = pq.top();
//		pq.pop();
//		if (vis[u])continue;
//		vis[u] = true;
//		for (auto [v, w] : g[u]) {
//			if (!vis[v]&&dis[u] + w < dis[v]) {
//				dis[v] = dis[u] + w;
//				pq.push({v,dis[v]});
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << dis[i] << " ";
//	}cout << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1005;
//const int K = 10005;
//int n, p, k;
//vector<vector<pair<int,int>>>g;
//int dis[N][K];
//bool vis[N][K];
//struct cmp {
//	bool operator()(array<int,3>&a,array<int,3>&b) {
//		return a[1] > b[1];
//	}
//};
//signed main() {
//	cin >> n >> p >> k;
//	g.assign(n + 1, {});
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= k; j++) {
//			dis[i][j] = LLONG_MAX;
//		}
//	}
//	for (int i = 1,a,b,l; i <= p; i++) {
//		cin >> a >> b >> l;
//		g[a].push_back({b,l});
//		g[b].push_back({ a,l });
//	}
//	priority_queue<array<int, 3>, vector<array<int, 3>>, cmp>pq;
//	pq.push({ 1,0,k });
//	dis[1][k] = 0;
//	while (!pq.empty()) {
//		auto [u, d, kk] = pq.top();
//		pq.pop();
//		if (vis[u][kk])continue;
//		vis[u][kk] = 1;
//		for (auto [v,w] : g[u]) {
//			if (max(w,dis[u][kk])<dis[v][kk]) {
//				dis[v][kk] = max(w,dis[u][kk]);
//				pq.push({ v,dis[v][kk],kk });
//			}
//			if (kk > 0  && dis[u][kk] < dis[v][kk - 1]) {
//				dis[v][kk - 1] = dis[u][kk];
//				pq.push({ v,dis[v][kk - 1],kk - 1 });
//			}
//		}
//	}
//	int ans = LLONG_MAX;
//	for (int i = 0; i <= k; i++) {
//		ans = min(ans, dis[n][i]);
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	for (int j = 0; j <= k; j++) {
//	//		cout << dis[i][j] << " ";
//	//	}cout << endl;
//	//}
//	if (ans == LLONG_MAX) {
//		cout << -1 << endl;
//	}
//	else cout << ans << endl;
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 3e5 + 5;
//int n, m;
//int a[N];
//int dis[N];
//bool inq[N];
//vector<vector<pair<int,int>>>g;
//void spfa() {
//	for (int i = 1; i <= 3*n; i++) {
//		dis[i] = INT_MIN;
//	}
//	dis[1] = 0;
//	inq[1] = 1;
//	queue<int>q;
//	q.push(1);
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//		inq[u] = false;
//		for (auto [v, w] : g[u]) {
//			if (dis[v] < dis[u] + w) {
//				dis[v] = dis[u] + w;
//				if (!inq[v]) {
//					q.push(v);
//					inq[v] = 1;
//				}
//			}
//		}
//	}
//}
//int main() {
//	cin >> n >> m;
//	g.assign(3*n + 1, {});
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		g[i].push_back({i + n,-a[i]});
//		g[i+n].push_back({i + 2 * n,a[i]});
//	}
//	for (int i = 1, x, y, z; i <= m; i++) {
//		cin >> x >> y >> z;
//		g[x].push_back({y,0});
//		g[x+n].push_back({y + n,0});
//		g[x+2*n].push_back({y + 2 * n,0});
//		if (z == 2) {
//			g[y].push_back({ x,0 });
//			g[y + n].push_back({ x + n,0 });
//			g[y + 2 * n].push_back({ x + 2 * n,0 });
//		}
//	}
//	spfa();
//	cout << max({ dis[n],dis[2 * n],dis[3 * n] }) << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int T = 25005;
//int t, p, r, s;
//vector<vector<pair<int, int>>>g;
//int dis[T];
//bool inq[T];
//void spfa() {
//	for (int i = 1; i <= t; i++)dis[i] = LLONG_MAX;
//	deque<int>q;
//	dis[s] = 0;
//	inq[s] = 1;
//	q.push_back(s);
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop_front();
//		inq[u] = false;
//		for (auto [v, w] : g[u]) {
//			if (dis[v] > dis[u] + w) {
//				dis[v] = dis[u] + w;
//				if (!inq[v]) {
//					if (!q.empty()&&dis[v] < dis[q.front()]) {
//						q.push_front(v);
//					}
//					else {
//						q.push_back(v);
//					}
//					inq[v] = 1;
//				}
//			}
//		}
//	}
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> t >> r >> p >> s;
//	g.assign(t + 1, {});
//	for (int i = 1, a, b, c; i <= r; i++) {
//		cin >> a >> b >> c;
//		g[a].push_back({ b,c });
//		g[b].push_back({ a,c });
//	}
//	for (int i = 1,a,b,c; i <= p; i++) {
//		cin >> a >> b >> c;
//		g[a].push_back({ b,c });
//	}
//	spfa();
//	for (int i = 1; i <= t; i++) {
//		if (dis[i] == LLONG_MAX) {
//			cout << "NO PATH\n";
//		}
//		else {
//			cout << dis[i] << "\n";
//		}
//	}
//}

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 6005;
//int n;
//int fa[N];
//int siz[N];
//void build() {
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//		siz[i] = 1;
//	}
//}
//int find(int x) {
//	if (x != fa[x]) {
//		fa[x]=find(fa[x]);
//	}
//	return fa[x];
//}
//bool isSame(int x, int y) {
//	return find(x) == find(y);
//}
//void merge(int x, int y) {
//	int fx = find(x), fy = find(y);
//	if (fx == fy)return;
//	if (siz[fx] > siz[fy])swap(fx, fy);
//	fa[fx] = fy;
//	siz[fy] += siz[fx];
//}
//void solve() {
//	cin >> n;
//	build();
//	vector<array<int, 3>>edg;
//	int mx = -1;
//	for (int i = 1,x,y,z; i < n; i++) {
//		cin >> x >> y >> z;
//		edg.push_back({ x,y,z });
//	}
//	sort(edg.begin(), edg.end(), [&](auto x,auto y) {
//		return x[2] < y[2];
//		});
//	int ans = 0;
//	for (auto [u, v, w] : edg) {
//		int fu = find(u);
//		int fv = find(v);
//		ans += (siz[fu] * siz[fv] - 1) * (w + 1);
//		merge(u, v);
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


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1005;
//int n, m;
//struct cmp {
//	bool operator()(pair<int, int>& a, pair<int, int>& b) {
//		return a.second > b.second;
//	}
//};
//vector<vector<pair<int, int>>>g;
//const int mod = (1ll << 31) - 1;
//int dis[N];
//bool vis[N];
//void dijkstra() {
//	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>pq;
//	pq.push({ 1,0 });
//	for (int i = 1; i <= n; i++) {
//		dis[i] = INT_MAX;
//	}
//	dis[1] = 0;
//	while (!pq.empty()) {
//		auto [u, d] = pq.top();
//		pq.pop();
//		if (vis[u])continue;
//		vis[u] = 1;
//		for (auto [v, w] : g[u]) {
//			if (dis[v] > dis[u] + w) {
//				dis[v] = dis[u] + w;
//				pq.push({ v,dis[v] });
//			}
//		}
//	}
//}
//void solve() {
//	vector<vector<int>>g1(n + 1);
//	vector<int>ide(n + 1);
//	for (int i = 1; i <= n; i++) {
//		for (auto [v, w] : g[i]) {
//			if (dis[i] + w == dis[v]) {
//				g1[v].push_back(i);
//				ide[v]++;
//			}
//		}
//	}
//	int ans = 1;
//	for (int i = 2; i <= n; i++) {
//		ans = ans * ide[i] % mod;
//	}cout << ans << endl;
//}
//signed main() {
//	cin >> n >> m;
//	g.assign(n + 1, {});
//	for (int i = 1, x, y, w; i <= m; i++) {
//		cin >> x >> y >> w;
//		g[x].push_back({ y,w });
//		g[y].push_back({ x,w });
//	}
//	dijkstra();
//	//for (int i = 1; i <= n; i++) {
//	//	cout << dis[i] << " ";
//	//}cout << endl;
//	solve();
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2e5 + 5;
//int n;
//vector<vector<pair<int,int>>>g;
//int pre[N],nex[N];
//int dis[N];
//int dis1[N];
//pair<int,int> fa[N];
//int son[N];
//int ls[N];
//int rs[N];
//bool in[N];
//void dfs(int u, int pa) {
//	for (auto [v,w] : g[u]) {
//		if (v == pa)continue;
//		fa[v] = { u,w };
//		dis[v] = dis[u] + w;
//		dfs(v, u);
//	}
//}
//int dfs1(int u,int pa) {
//	int ans = 0;
//	for (auto [v, w] : g[u]) {
//		if (in[v] || v == pa)continue;
//		ans = max(w + dfs1(v, u), ans);
//	}
//	return ans;
//}
//signed main() {
//	cin >> n;
//	g.assign(n + 1, {});
//	for (int i = 1,a,b,w; i < n; i++) {
//		cin >> a >> b >> w;
//		g[a].push_back({ b,w });
//		g[b].push_back({ a,w });
//	}
//	dis[1] = 0;
//	dfs(1, 0);
//	int mx = -1, x=-1;
//	for (int i = 1; i <= n; i++) {
//		if (dis[i] > mx) {
//			x = i;
//			mx = dis[i];
//		}
//	}
//	dis[x] = 0;
//	dfs(x, 0);
//	mx = -1;
//	int y = -1;
//	for (int i = 1; i <= n; i++) {
//		if (dis[i] > mx) {
//			y = i;
//			mx = dis[i];
//		}
//	}
//	cout << dis[y] << endl;
//	ls[x] = 0; rs[x] = dis[y];
//	ls[y] = dis[y]; rs[y] = 0;
//	int cur = y;
//	int ll = dis[y], rr = 0;
//	fa[x].first = 0;
//	while (cur != 0) {
//		ls[cur] = ll;
//		rs[cur] = rr;
//		in[cur] = 1;
//		ll -= fa[cur].second;
//		rr += fa[cur].second;
//		cur = fa[cur].first;
//	}
//	cur = y;
//	int cnt = 0;
//	while (cur != 0) {
//		//cout << cur << " " << cnt << "\n";
//		int d = dfs1(cur, 0);
//		//cout << d << " " << ls[cur] << " " << rs[cur] << "^^\n";
//		if (d == ls[cur]) {
//			break;
//		}
//		else if(d==rs[cur]) {
//			cnt=1;
//		}
//		else {
//			cnt++;
//		}
//
//
//		cur = fa[cur].first;
//	}
//	cout << cnt << endl;
//}

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2e3 + 5;
//int n, m;
//vector<vector<pair<int,int>>>g;
//int dis[N];
//bool inq[N];
//int cnt[N];
//bool spfa() {
//	for (int i = 1; i <= n; i++) {
//		dis[i] = LLONG_MAX;
//		inq[i] = 0;
//		cnt[i] = 0;
//	}
//	queue<int>q;
//	q.push(1);
//	inq[1] = 1;
//	dis[1] = 0;
//	++cnt[1];
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//		inq[u] = 0;
//		for (auto [v,w] : g[u]) {
//			if (dis[v] > dis[u] + w) {
//				dis[v] = dis[u] + w;
//				if (!inq[v]) {
//					if (++cnt[v] > n) {
//						return true;
//					}
//					inq[v] = 1;
//					q.push(v);
//				}
//			}
//		}
//	}
//	return false;
//}
//void solve() {
//	cin >> n >> m;
//	g.assign(n + 1,{});
//	for (int i = 1,u,v,w; i <= m; i++) {
//		cin >> u >> v >> w;
//		if (w >= 0) {
//			g[u].push_back({v,w});
//			g[v].push_back({ u,w });
//		}
//		else {
//			g[u].push_back({ v,w });
//		}
//	}
//	if (spfa()) {
//		cout << "YES\n";
//	}
//	else cout << "NO\n";
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
//const int N = 5e5 + 5;
//const int P = 22;
//int n, m, s;
//vector<vector<int>>g;
//int st[N][23];
//int dep[N];
//void dfs(int u, int fa) {
//	dep[u] = dep[fa] + 1;
//	st[u][0] = fa;
//	for (int p = 1; p <= P; p++) {
//		st[u][p] = st[st[u][p - 1]][p - 1];
//	}
//	for (auto v : g[u]) {
//		if (v != fa) {
//			dfs(v, u);
//		}
//	}
//}
//int lca(int u, int v) {
//	if (dep[u] < dep[v])swap(u, v);
//	for (int p = P; p >= 0; p--) {
//		if (dep[st[u][p]] >= dep[v]) {
//			u = st[u][p];
//		}
//	}
//	if (u == v)return u;
//	for (int p = P; p >= 0; p--) {
//		if (st[u][p] != st[v][p]) {
//			u = st[u][p];
//			v = st[v][p];
//		}
//	}
//	return st[u][0];
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n >> m >> s;
//	g.assign(n + 1, {});
//	for (int i = 1,x,y; i < n; i++) {
//		cin >> x >> y;
//		g[x].push_back(y);
//		g[y].push_back(x);
//	}
//	dfs(s, 0);
//	for (int i = 1,a,b; i <= m; i++) {
//		cin >> a >> b;
//		cout << lca(a, b) << "\n";
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 5e4 + 5;
//const int P = 20;
//int n, k;
//vector<vector<int>>g;
//int st[N][21];
//int dep[N];
//int ad[N];
//void dfs(int u, int fa) {
//	dep[u] = dep[fa] + 1;
//	st[u][0] = fa;
//	for (int p = 1; p <= P; p++) {
//		st[u][p] = st[st[u][p - 1]][p - 1];
//	}
//	for (auto v : g[u]) {
//		if (v != fa) {
//			dfs(v, u);
//		}
//	}
//}
//int lca(int u, int v) {
//	if (dep[u] < dep[v])swap(u, v);
//	for (int p = P; p >= 0; p--) {
//		if (dep[st[u][p]] >= dep[v]) {
//			u = st[u][p];
//		}
//	}
//	if (u == v)return u;
//	for (int p = P; p >= 0; p--) {
//		if (st[u][p] != st[v][p]) {
//			u = st[u][p];
//			v = st[v][p];
//		}
//	}
//	return st[u][0];
//}
//int mx = -1;
//int dfs1(int u, int fa) {
//	int aa = ad[u];
//	for (auto v : g[u]) {
//		if(v!=fa)
//		aa+=dfs1(v, u);
//	}
//	mx=max(mx,aa);
//	return aa;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n >> k;
//	g.assign(n + 1, {});
//	for (int i = 1, x, y; i < n; i++) {
//		cin >> x >> y;
//		g[x].push_back(y);
//		g[y].push_back(x);
//	}
//	dfs(1, 0);
//	for (int i = 1,u,v; i <= k; i++) {
//		cin >> u >> v;
//		int uv = lca(u, v);
//		ad[u]++;
//		ad[v]++;
//		ad[uv]--;
//		ad[st[uv][0]]--;
//	}
//	dfs1(1, 0);
//	cout << mx << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 5;
//int n, m;
//vector<vector<pair<int,int>>>g;
//vector<array<int, 4>>edg;
//int fa[N];
//int siz[N];
//int dep[N];
//int st[N][21];
//int stmx[N][21];
//int stsmx[N][21];
//int getsmx(int a, int b, int c, int d) {//a>b c>d返回次大值
//	vector<int>aa;
//	aa.push_back(a);
//	aa.push_back(b);
//	aa.push_back(c);
//	aa.push_back(d);
//	sort(aa.begin(), aa.end());
//	int mx = aa[3];
//	for (int i = 2; i >=0; i--) {
//		if (aa[i] < mx) {
//			return aa[i];
//		}
//	}
//	return -1;
//}
//void dfs(int u, int pa) {
//	dep[u] = dep[pa] + 1;
//	//cout << u << ":----------------\n";
//	for (int p = 1; p <= 20; p++) {
//		st[u][p] = st[st[u][p - 1]][p - 1];
//		int a = stmx[u][p - 1], b = stmx[st[u][p - 1]][p - 1];
//		int c = stsmx[u][p - 1], d = stsmx[st[u][p - 1]][p - 1];
//		//cout << p << " " << a << " " << b << " " << c << " " << d << endl;
//		stmx[u][p] = max(a, b);
//		stsmx[u][p] = getsmx(a,c,b,d);
//	}
//	for (auto [v,w] : g[u]) {
//		if (v != pa) {
//			st[v][0] = u;
//			stmx[v][0] = w;
//			stsmx[v][0] = -1;
//			dfs(v, u);
//		}
//	}
//}
//int lca(int u, int v) {
//	if (dep[u] < dep[v])swap(u, v);
//	for (int p = 20; p >= 0; p--) {
//		if (dep[st[u][p]] >= dep[v]) {
//			u = st[u][p];
//		}
//	}
//	if (u == v)return u;
//	for (int p = 20; p >= 0; p--) {
//		if (st[u][p] != st[v][p]) {
//			u = st[u][p];
//			v = st[v][p];
//		}
//	}
//	return st[u][0];
//}
//void build() {
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//		siz[i] = 1;
//	}
//}
//int find(int x) {
//	if (x != fa[x]) {
//		fa[x] = find(fa[x]);
//	}
//	return fa[x];
//}
//void merge(int x, int y) {
//	int fx = find(x), fy = find(y);
//	if (fx == fy)return;
//	if (siz[fx] > siz[fy])swap(fx, fy);
//	fa[fx] = fy;
//	siz[fy] += siz[fx];
//}
//bool isSame(int x, int y) {
//	return find(x) == find(y);
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n >> m;
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= 20; j++) {
//			stmx[i][j] = stsmx[i][j] = -1;
//		}
//	}
//	g.assign(n + 1, {});
//	map<pair<int, int>, int>mp;
//	for (int i = 1,x,y,z; i <= m; i++) {
//		cin >> x >> y >> z;
//		if (x == y)continue;
//		edg.push_back({ x,y,z,0 });
//	}
//	sort(edg.begin(), edg.end(), [&](auto x, auto y) {
//		return x[2] < y[2];
//		});
//	int ans = INT_MAX;
//	int sum = 0;
//	build();
//	for (auto &[x, y, w, u] : edg) {
//		if (!isSame(x, y)) {
//			merge(x, y);
//			g[x].push_back({y,w});
//			g[y].push_back({x,w});
//			sum += w;
//			u = 1;
//		}
//	}
//	//for (auto& [x, y, w, u] : edg) {
//	//	if (u) {
//	//		cout << x << " " << y << " " << w << " " << u << endl;
//	//	}
//	//}
//	//cout << sum << "**\n";
//	dfs(1, 0);
//	//for (int i = 1; i <= n; i++) {
//	//	for (int j = 0; j <= 20; j++) {
//	//		cout << st[i][j] << " ";
//	//	}cout << endl;
//	//}cout << endl;
//	//for (int i = 1; i <= n; i++) {
//	//	for (int j = 0; j <= 20; j++) {
//	//		cout << stmx[i][j] << " ";
//	//	}cout << endl;
//	//}cout << endl;
//	//for (int i = 1; i <= n; i++) {
//	//	for (int j = 0; j <= 20; j++) {
//	//		cout << stsmx[i][j] << " ";
//	//	}cout << endl;
//	//}cout << endl;
//	for (auto& [x, y, w, u] : edg) {
//		if (!u) {
//			//cout << x << " " << y << " " << w << " " << u << endl;
//			int mx = -1;
//			int smx = -1;
//			int xy = lca(x, y);
//			if (dep[x] > dep[y])swap(x, y);
//			if (x == xy) {
//				if (y == xy)continue;
//				for (int p = 0; p <= 20; p++) {
//					if (dep[st[y][p]] >= dep[x]) {
//						//cout << y << " "<<st[y][p]<<" " << p << " " << x << "@\n";
//						smx = getsmx(mx,smx,stmx[y][p],stsmx[y][p]);
//						mx = max(mx, stmx[y][p]);
//						y = st[y][p];
//					}
//				}
//				//cout << mx << " " << smx << " " << stmx[y][0] << " " << stsmx[y][0] << "xixi\n";
//				//smx = getsmx(mx, smx, stmx[y][0], stsmx[y][0]);
//				//mx = max(mx, stmx[y][0]);
//			}
//			else {
//				for (int p = 0; p <= 20; p++) {
//					if (st[y][p] != xy) {
//						smx = getsmx(mx, smx, stmx[y][p], stsmx[y][p]);
//						mx = max(mx, stmx[y][p]);
//						y = st[y][p];
//					}
//				}
//				smx = getsmx(mx, smx, stmx[y][0], stsmx[y][0]);
//				mx = max(mx, stmx[y][0]);
//				for (int p = 0; p <= 20; p++) {
//					if (st[x][p] != xy) {
//						smx = getsmx(mx, smx, stmx[x][p], stsmx[x][p]);
//						mx = max(mx, stmx[x][p]);
//						x = st[x][p];
//					}
//				}
//				smx = getsmx(mx, smx, stmx[x][0], stsmx[x][0]);
//				mx = max(mx, stmx[x][0]);
//			}
//			//cout << mx << " **\n";
//			//cout << smx << " &&\n";
//			if ((mx < w && mx != -1))ans = min(ans, sum - mx + w);
//			else if(smx!=-1&&smx<w){
//				ans = min(ans, sum - smx + w);
//			}
//			//cout << ans << " ans\n";
//		}
//	}
//	cout << ans << endl;
//}


//#include<bits/stdc++.h>
//using ll = long long;
//using namespace std;
//const int N = 5e4 + 5;
//int n, m;
//int st[N][21];
//ll st1[N][21];//往上跳1<<i个单位要多少时间
//int dep[N];
//vector<vector<pair<int, ll>>>g;
//vector<int>a;
//bool ok[N];
//int belong[N];
//struct cmp {
//	bool operator()(ll x, ll y) {
//		return x > y;
//	}
//};
//bool dfs2(int u, int fa) {
//	if (ok[u])return true;
//	if (g[u].size() == 1)return false;
//	int okk = 1;
//	for (auto [v, w] : g[u]) {
//		if (v != fa) {
//			okk &= dfs2(v, u);
//		}
//	}
//	ok[u] = okk;
//	return okk;
//}
//bool check(ll t) {
//	memset(ok, 0, sizeof(ok));
//	int atrt = 0;
//	vector<array<ll, 3>>arm;
//	vector<pair<int, int>>rst;
//	arm.reserve(m);
//	rst.reserve(m);
//	for (auto u : a) {
//		int bl = belong[u];
//		ll tim = t;;
//		for (int p = 20; p >= 0; p--) {
//			if (st1[u][p] <= tim) {
//				tim -= st1[u][p];
//				u = st[u][p];
//			}
//		}
//		if (u == 0 || u == 1) {
//			arm.push_back({ tim,bl,0 });
//		}
//		else {
//			ok[u] = 1;
//		}
//	}
//	for (auto [v, w] : g[1]) {
//		if (!dfs2(v, 1)) {
//			rst.push_back({ w,v });
//		}
//	}
//	sort(arm.begin(), arm.end(), [&](auto x, auto y) {
//		return x[0] < y[0];
//		});
//	for (auto& [t, b, u] : arm) {
//		if (!u && !ok[b] && t < st1[b][0]) {
//			//cout << t << " " << b << " " << u << "!" << endl;
//			u = 1;
//			ok[b] = 1;
//		}
//	}
//	sort(rst.begin(), rst.end());
//	priority_queue<ll, vector<ll>, cmp>pq;
//	for (auto [t, b, u] : arm) {
//		if (!u) {
//			pq.push(t);
//		}
//	}
//	//cout << t << " t\n";
//	//for (auto [t,b,u] : arm) {
//	//	cout << '('<<t<<','<<b<<","<<u << ")  ";
//	//}cout << " arm\n";
//	//for (auto [nd,b] : rst) {
//	//	cout << '('<<nd<<","<<b<<")  ";
//	//}cout << " rst\n----------\n";	
//	if (arm.size() < rst.size()) {
//		return false;
//	}
//	for (auto [nd, b] : rst) {
//		if (ok[b])continue;
//		while (!pq.empty() && pq.top() < nd) {
//			pq.pop();
//		}
//		if (pq.empty())return false;
//		else pq.pop();
//	}
//	return true;
//}
//void dfs(int u, int fa) {
//	dep[u] = dep[fa] + 1;
//	st[u][0] = fa;
//	for (int p = 1; p <= 20; p++) {
//		st[u][p] = st[st[u][p - 1]][p - 1];
//		st1[u][p] = st1[u][p - 1] + st1[st[u][p - 1]][p - 1];
//	}
//	for (auto [v, w] : g[u]) {
//		if (v != fa) {
//			st1[v][0] = w;
//			dfs(v, u);
//		}
//	}
//}
//void dfs1(int u, int fa, int top) {
//	belong[u] = top;
//	for (auto [v, w] : g[u]) {
//		if (v != fa) {
//			dfs1(v, u, top);
//		}
//	}
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n;
//	g.assign(n + 1, {});
//	for (int i = 1, u, v, w; i < n; i++) {
//		cin >> u >> v >> w;
//		g[u].push_back({ v,w });
//		g[v].push_back({ u,w });
//	}
//	cin >> m;
//	a.resize(m);
//	for (int i = 0, u; i < m; i++) {
//		cin >> a[i];
//	}
//	dfs(1, 0);
//	for (auto [v, w] : g[1]) {
//		dfs1(v, 1, v);
//	}
//	sort(a.begin(), a.end(), [&](int x, int y) {
//		return dep[x] > dep[y];
//		});
//	//for (int i = 1; i <= n; i++) {
//	//	for (int p = 0; p <= 20; p++) {
//	//		cout << st[i][p] << " ";
//	//	}cout << endl;
//	//}cout << endl;
//	//for (int i = 1; i <= n; i++) {
//	//	for (int p = 0; p <= 20; p++) {
//	//		cout << st1[i][p] << " ";
//	//	}cout << endl;
//	//}cout << endl;
//	ll l = 0, r = 1e17;
//	ll ans = -1;
//	while (l <= r) {
//		ll mid = l + r >> 1;
//		if (check(mid)) {
//			ans = mid;
//			r = mid - 1;
//		}
//		else {
//			l = mid + 1;
//		}
//	}
//	cout << ans << endl;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n;
//	cin >> n;
//	vector<int>a;
//	vector<pair<int,int>>b;
//	int rr = INT_MAX;
//	for (int i = 1,k,l,r; i <= n; i++) {
//		cin >>k>>l >> r;
//		rr = min(r, rr);
//		a.resize(k + 1);
//		a.push_back(l);
//		for (int j = 1,u; j <= k; j++) {
//			cin >> a[j];
//		}
//		for (int i = 1; i <= k; i++) {
//			a[i] = a[i] + a[i - 1];
//		}
//		b.push_back({ l,-1 });
//		for (int i = 1; i <= k; i++) {
//			b.push_back({ l + a[i],r - (a[k] - a[i-1]) });
//		}
//		b.push_back({INT_MAX,r });
//	}
//	sort(b.begin(), b.end());
//	vector<int>bmn(b.size() + 2,INT_MAX);
//	bmn[b.size()] = rr;
//	for (int i = b.size() - 1; i >= 0; i--) {
//		bmn[i] = min(bmn[i + 1], b[i].second);
//	}
//	//for (auto [r, l] : b) {
//	//	cout << "(" << r << "," << l << ")  ";
//	//}cout << endl;
//	int ans = -1;
//	for (int i = 0; i < b.size(); i++) {
//		ans = max(ans, bmn[i + 1] - b[i].first);
//		//cout << b[i].first << " " << bmn[i + 1] << " " << ans << "*\n";
//	}
//	ans = max(0ll, ans);
//	cout << ans << endl;
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>x(n + 1);
//	vector<int>mx(n + 1);
//	vector<int>mn(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> x[i];
//	}
//	if (n == 1) {
//		cout << 0 << endl;
//		return;
//	}
//
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