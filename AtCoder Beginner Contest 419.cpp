//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	string s;
//	cin >> s;
//	if (s == "red") {
//		cout << "SSS\n";
//	}
//	else if (s == "blue") {
//		cout << "FFF\n";
//	}
//	else if (s == "grenn") {
//		cout << "MMM\n";
//	}
//	else {
//		cout << "Unknown\n";
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//struct Compare {
//	bool operator()(int a, int b) {
//		return a > b;
//	}
//};
//int main() {
//	int q;
//	cin >> q;
//	priority_queue<int, vector<int>,Compare>pq;
//	for (int i = 0,o,x; i < q; i++) {
//		cin >> o;
//		if (o == 1) {
//			cin >> x;
//			pq.push(x);
//		}
//		else {
//			cout << pq.top() << '\n';
//			pq.pop();
//		}
//	}
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//signed main() {
//	int n;
//	cin >> n;
//	vector<array<int, 2>>a(n);
//	vector<array<int, 3>>b(n);
//	int mxx=INT_MIN, mxy=INT_MIN, mnx=INT_MAX, mny =INT_MAX;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i][0] >> a[i][1];
//		mxx = max(a[i][0], mxx);
//		mnx = min(a[i][0], mnx);
//		mxy = max(a[i][1], mxy);
//		mny = min(a[i][1], mny);
//	}
//	cout << max((abs(mxx - mnx) + 1) / 2, (abs(mxy - mny) + 1) / 2) << '\n';
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	string s,t;
//	cin >> s >> t;
//	s = " " + s;
//	t = " " + t;
//	vector<int>flip(n+2,0);
//	for (int i = 1,l,r; i <= m; i++) {
//		cin >> l >> r;
//		flip[l] ^= 1;
//		flip[r+1] ^= 1;
//	}
//	for (int i = 1; i <= n; i++) {
//		flip[i] ^= flip[i - 1];
//	}
//	for (int i = 1; i <= n; i++) {
//		if (flip[i]) {
//			cout << t[i];
//		}
//		else cout << s[i];
//	}cout << '\n';
//}



//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n, m, l;
//	cin >> n>>m>>l;
//	vector<int>a(n+1);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		a[i] %= m;
//	}
//	//模l为i的位置的数都变成模m为j的代价
//	vector<vector<int>>val(l + 1, vector<int>(m+1));
//	for (int i = 0; i < l; i++) {
//		for (int j = i; j < n; j += l) {
//			for (int k = 0; k < m; k++) {
//				val[i][k] += ((k - a[j]) % m + m) % m;
//			}
//		}
//	}
//	//for (int i = 0; i < l; i++) {
//	//	for (int j = 0; j < m; j++) {
//	//		cout << val[i][j] << " ";
//	//	}
//	//	cout << endl;
//	//}
//	//前i个数总和模m为j的最小代价
//	vector<vector<int>>dp(l+1, vector<int>(m+1,INT_MAX));
//	for (int i = 0; i < m; i++) {
//		dp[0][i] = val[0][i];
//	}
//	for (int i = 1; i < l; i++) {
//		for (int j = 0; j < m; j++) {
//			for (int k = 0; k < m; k++) {
//				dp[i][j] = min(dp[i][j], dp[i - 1][k] + val[i][(j - k + m)%m]);
//			}
//		}
//	}
//	cout << dp[l - 1][0] << '\n';
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 10;
//set<pair<int,int>>g[N];
//int ide[N];
//bool vis[N];
//int cnt[N];
//int n, m;
//void dfs(int u,int l) {
//	if (u == n) {
//		cnt[l]++;
//		return;
//	}
//	vis[u] = 1;
//	for (auto v : g[u]) {
//		if(!vis[v.first])
//		dfs(v.first, l + v.second);
//	}
//	vis[u] = 0;
//}
//int main() {	
//	cin >> n >> m;
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		g[u].insert({ v,1 });
//		g[v].insert({ u,1 });
//		ide[v]++;
//		ide[u]++;
//	}
//	queue<int>q;
//	for (int i = 2; i <= n-1; i++) {
//		if (g[i].size() == 1)q.push(i);
//	}
//	while (!q.empty()) {
//		int v = q.front();
//		q.pop();
//		int to = g[v].begin()->first;
//		g[to].erase({ v ,1});
//		if (to != 1 && to != n && g[to].size() == 1)q.push(to);
//	}
//	for (int i = 2; i <= n-1; i++) {
//		if (g[i].size() == 2) {
//			auto [u, w1] = *g[i].begin();
//			auto [v, w2] = *next(g[i].begin());
//			g[u].erase(g[u].find({ i, w1 }));
//			g[v].erase(g[v].find({ i, w2 }));
//			g[u].insert({ v,w1 + w2 });
//			g[v].insert({ u,w1 + w2 });
//		}
//	}
//	dfs(1,0);
//	for (int i = 1; i < n; i++) {
//		cout << cnt[i] << " ";
//	}cout << '\n';
//}