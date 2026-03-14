//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2;
//	cin >> sx1 >> sy1 >> sx2 >> sy2 >> tx1 >> ty1 >> tx2 >> ty2;
//	double mx1 = (sx1 + sx2) / 2;
//	double my1 = (sy1 + sy2) / 2;
//	double mx2 = (tx1 + tx2) / 2;
//	double my2 = (ty1 + ty2) / 2;
//	//cout << int(fabs((mx1 + my1)  - (mx2 + my2)) + abs((mx1 - my1) - (mx2 - my2)))<<'\n';
//	cout << (abs(sx1 + sx2 + sy1 + sy2 - tx1 - tx2 - ty1 - ty2) + abs(sx1 + sx2 - sy1 - sy2 - tx1 - tx2 + ty1 + ty2)) / 2 << '\n';
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
//const int N = 2e5 + 10;
//int lson[N];
//int rson[N];
//int siz[N];
//int g[31];//高度为N的AVL树至少需要几个节点
//int dp[N][31];
//void dfs(int cur) {
//	siz[cur] = 1;
//	if (lson[cur] != 0) {
//		dfs(lson[cur]);
//		siz[cur] += siz[lson[cur]];
//	}
//	if (rson[cur] != 0) {
//		dfs(rson[cur]);
//		siz[cur] += siz[rson[cur]];
//	}
//	dp[cur][0] = siz[cur];
//	dp[cur][1] = siz[cur]-1;
//	for (int i = 2; i <= 30; i++) {
//		dp[cur][i] = min(
//			{
//				dp[lson[cur]][i - 1] + dp[rson[cur]][i - 2],
//				dp[lson[cur]][i - 2] + dp[rson[cur]][i - 1],
//				dp[lson[cur]][i - 1] + dp[rson[cur]][i - 1]
//			});
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> lson[i] >> rson[i];
//	}
//	for (int i = 0; i <= 30; i++) {
//		dp[0][i] = g[i];
//	}
//	dfs(1);
//	int ans = INT_MAX;
//	for (int i = 0; i <= 30; i++) {
//		ans = min(ans, dp[1][i]);
//	}
//	cout << ans << '\n';
//}
//void prepare() {
//	g[0] = 0;
//	g[1] = 1;
//	for (int i = 2; i <= 30;i++) {
//		g[i] = g[i - 1] + g[i - 2] + 1;
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


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	vector<array<int,2>>q(8*n + 5);
//	vector<int>ans(n + 1,0);
//	for (int i = 1; i <= n; i++) {
//		cin >> q[i][0];
//		q[i][1] = i;
//	}
//	int ma = INT_MIN,mapos=-1;
//	int sma = INT_MIN,smapos=-1;
//	for (int i = 1; i <= n; i++) {
//		if (q[i][0] > ma) {
//			ma = q[i][0];
//			mapos = i;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		if (q[i][0] > sma&&i!=mapos) {
//			sma = q[i][0];
//			smapos = i;
//		}
//	}
//	int head = 1;
//	int tail = n + 1;
//	int win = 0;
//	auto run = [&]() {
//		if (q[head][0] > q[head + 1][0]&&win!=n-1) {
//			q[tail++] = q[head + 1];
//			q[head + 1] = q[head];
//			head++;
//			win++;
//		}
//		else {
//			win = 1;
//			q[tail++] = q[head];
//			head++;
//		}
//	};
//	auto cal = [&]() {
//		ans[q[head][1]]++;
//		ans[q[head+1][1]]++;
//	};
//	for (int i = 1; i <= 4 * n&&k>0; i++,k--) {
//		cal();
//		run();
//	}
//	int cnt = k / (2 * n - 2);
//	ans[mapos] += cnt*n;
//	ans[smapos] += cnt * n;
//	for (int i = 1; i <= n; i++) {
//		if (i != mapos && i != smapos) {
//			ans[i] += 2 * cnt;
//		}
//	}
//	k %= (2 * n - 2);
//	while (k--) {
//		cal();
//		run();
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << ans[i] << " ";
//	}
//	cout << '\n';
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
//const int inf = 1e18;
//using namespace std;
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int>w(n);
//	vector<int>need(n,0);
//	vector<int>cost(1ll << (n + 1),inf);
//	for (int i = 0; i <n; i++) {
//		cin >> w[i];
//	}
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		--u, --v;
//		need[v] |= 1ll << u;
//	}
//	cost[0] = 0;
//	for (int s = 0; s < 1ll << n ; s++) {//从子集更新到超集 因为超集的1只会比子集的多
//		if (cost[s] == inf)continue;//自动过滤了不可达状态
//		vector<int>deal;
//		for (int j = 0; j < n; j++) {
//			if ((s & (1ll << j)) == 0 && (s & need[j]) == need[j]) {
//				deal.push_back(j);//当前组件未执行且当前组件前置条件已满足
//			}
//		}
//		int msk = 0,prc=0;
//		sort(deal.begin(), deal.end(), [&](int i,int j) {
//			return w[i] < w[j];
//			});
//		for (int i = 0; i < deal.size(); i++) {
//			msk |= 1ll << deal[i];
//			cost[s | msk] = min(cost[s | msk], cost[s]+w[deal[i]]);
//		}
//	}
//	cout << cost[(1ll << n) - 1] << '\n';
//}