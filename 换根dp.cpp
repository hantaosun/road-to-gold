//STA-Station
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 1e6 + 10;
//int n;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN];
//int siz[MAXN];//以1为根该节点子树大小
//int cnt = 1;
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//int dp[MAXN];
//void dfs(int u,int fa,int l) {
//	dp[1] += l;
//	for (int e = head[u]; e != 0; e = nex[e]){
//		if (to[e] == fa)continue;
//		dfs(to[e], u,l+1);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa)continue;
//		siz[u] += siz[to[e]];
//	}
//	siz[u] += 1;
//}
//void f(int i, int fa) {
//	if(i!=1)dp[i] = dp[fa] - siz[i] + n - siz[i];
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		f(to[ui], i);
//	}
//}
//signed main() {
//	cin >> n;
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs(1, 0,0);
//	int ma = dp[1];
//	int ans = 1;
//	f(1, 0);
//	for (int i = 1; i <= n; i++) {
//		if (dp[i] > ma) {
//			ma = dp[i];
//			ans = i;
//		}
//	}
//	cout << ans << endl;
//}


//Tree Painting
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 2e5 + 2;
//int n;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN];
//int dp[MAXN];
//int siz[MAXN];
//int cnt = 1;
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//void dfs(int u, int fa) {
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa)continue;
//		dfs(to[e], u);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa)continue;
//		siz[u] += siz[to[e]];
//	}
//	siz[u]++;
//	dp[1] += siz[u];
//}
//void f(int u, int fa) {
//	if (u != 1) {
//		dp[u] = dp[fa] - siz[u] + n - siz[u];
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa)continue;
//		f(to[e], u);
//	}
//}
//signed main() {
//	cin >> n;
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs(1, 0);
//	f(1, 0);
//	int ma = -1;
//	for (int i = 1; i <= n; i++) {
//		ma = max(ma, dp[i]);
//	}
//	cout << ma << endl;
//}


//Choosing Capital for Treeland
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//const int MAXN = 2e5 + 2;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//bool zheng[MAXN << 1];
//int head[MAXN];
//int siz[MAXN];
//int dp[MAXN];
//int cnt = 1;
//void dfs(int u, int fa) {
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa)continue;
//		dfs(to[e], u);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa)continue;
//		if (zheng[e])dp[1]++;
//		siz[u]+=siz[to[e]];
//	}
//	siz[u]++;
//}
//void f(int u, int fa,int z) {
//	if (u != 1) {
//		if (z)dp[u] =dp[fa]-1;
//		else {
//			dp[u] = dp[fa] + 1;
//		}
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa)continue;
//		f(to[e], u, zheng[e]);
//	}
//}
//void addEdge(int u, int v, int w) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	zheng[cnt] = w;
//	head[u] = cnt++;
//}
//int main() {
//	cin >> n;
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v, 0);
//		addEdge(v, u, 1);
//	}
//	dfs(1, 0);
//	f(1, 0,0);
//	int mi = INT_MAX;
//	for (int i = 1; i <= n; i++) {
//		mi = min(mi, dp[i]);
//	}
//	cout << mi << endl;
//	for (int i = 1; i <= n; i++) {
//		if (dp[i] == mi)cout << i << " ";
//	}
//	cout << endl;
//}


//Nearby Cows G
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1e5 + 2;
//int n, k;
//int nex[MAXN<<1];
//int to[MAXN << 1];
//int head[MAXN];
//int cows[MAXN];
//int disK[MAXN];
//int disK1[MAXN];
//int disK_1[MAXN];
//int dp[MAXN];//到某一节点距离为k的牛的和
//int dk[MAXN][22];//该子树往下i以内的和
//int cnt = 1;
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//void dfs(int u, int fa, int len) {
//	if (len <= k)dp[1] += cows[u];
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa)continue;
//		dfs(to[e], u, len + 1);
//	}
//	dk[u][0] = cows[u];
//	for (int i = 1; i <= k; i++) {
//		dk[u][i] = cows[u];
//		for (int e = head[u]; e != 0; e = nex[e]) {
//			if (to[e] == fa)continue;
//			dk[u][i] += dk[to[e]][i - 1];
//		}
//	}
//}
//void f(int u, int fa) {
//	if (u != 1) {
//		dp[u] = dp[fa] - (dk[fa][k] - (k > 0 ? dk[fa][k - 1] : 0))
//			- (k > 1 ? dk[u][k - 2] : 0) + dk[u][k];
//		for (int i = k;i>=2; i--) {
//			dk[u][i] += dk[fa][i - 1] - dk[u][i - 2];//好tm丑的方程
//		}
//		dk[u][1] += dk[fa][0];
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa)continue;
//		f(to[e], u);
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n >> k;
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> cows[i];
//	}
//	dfs(1, 0, 0);
//	f(1, 0);
//	for (int i = 1; i <= n; i++) {
//		cout << dp[i]<<endl;
//	}
//}


//Centroids
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 4e5 + 2;
//int n;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN << 1];
//int chose[MAXN];
//int inner1[MAXN];
//int inner2[MAXN];
//int outer[MAXN];
//int siz[MAXN];
//int maxsub[MAXN];
//int cnt = 1;
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//void dfs1(int u,int fa) {
//	siz[u] = 1;
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa)continue;
//		dfs1(to[e], u);
//		siz[u] += siz[to[e]];
//		if (siz[maxsub[u]] < siz[to[e]]) {
//			maxsub[u] = to[e];
//		}
//		int innersize = siz[to[e]] <= n / 2 ? siz[to[e]] : inner1[to[e]];
//		if (inner1[u] < innersize) {
//			inner2[u] = inner1[u];
//			chose[u] = to[e];
//			inner1[u] = innersize;
//		}
//		else if (inner2[u] < innersize) {
//			inner2[u] = innersize;
//		}
//	}
//}
//void dfs2(int u, int fa) {
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa)continue;
//		if (n - siz[to[e]] <= n / 2) {
//			outer[to[e]] = n - siz[to[e]];
//		}
//		else if (chose[u]!=to[e]) {
//			outer[to[e]] = max(inner1[u], outer[u]);
//		}
//		else {
//			outer[to[e]] = max(outer[u], inner2[u]);
//		}
//		dfs2(to[e], u);
//	}
//}
//bool check(int i) {
//	if (n - siz[i] > n / 2) {
//		return n - siz[i] - outer[i] <= n / 2;
//	}
//	if (siz[maxsub[i]] > n / 2) {
//		return siz[maxsub[i]] - inner1[maxsub[i]] <= n / 2;
//	}
//	return true;
//}
//int main() {
//	cin >> n;
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs1(1, 0);
//	dfs2(1, 0);
//	for (int i = 1; i <= n; i++) {
//		cout << (check(i) ? 1 : 0) << " ";
//	}
//	cout << endl;
//}


//Kamp**************************************************
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 5e5 + 2;
//int n, k;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int weight[MAXN << 1];
//int head[MAXN];
//int cnt = 1;
//int people[MAXN];
//int inner1[MAXN];
//int inner2[MAXN];
//int incost[MAXN];
//int chose[MAXN];
//int outcost[MAXN];
//int outer[MAXN];
//void addEdge(int u,int v,int w) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	weight[cnt] = w;
//	head[u] = cnt++;
//}
//void dfs1(int u, int fa) {
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa)continue;
//		int v = to[e];
//		int w = weight[e];
//		dfs1(v, u);
//		people[u] += people[v];
//		if (people[v] > 0) {
//			incost[u] += incost[v] + w * 2;
//			if (inner1[u] < inner1[v] + w) {
//				chose[u] = v;
//				inner2[u] = inner1[u];
//				inner1[u] = inner1[v] + w;
//			}
//			else if (inner2[u] < inner1[v] + w) {
//				inner2[u] = inner1[v] + w;
//			}
//		}
//	}
//}
//void dfs2(int u,int fa) {
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa)continue;
//		int	v = to[e];
//		int w = weight[e];
//		if (k - people[v] > 0) {
//			if (people[v] == 0) {
//				outcost[v] = outcost[u] + incost[u] + w * 2;
//			}
//			else {
//				outcost[v] = outcost[u] + incost[u] - incost[v];
//			}
//			if (v != chose[u]) {
//				outer[v] = max(outer[u], inner1[u]) + w;
//			}
//			else {
//				outer[v] = max(outer[u], inner2[u]) + w;
//			}
//		}
//		dfs2(v, u);
//	}
//}
//signed main() {
//	cin >> n >> k;
//	for (int i = 1,u,v,w; i < n; i++) {
//		cin >> u >> v >> w;
//		addEdge(u, v, w);
//		addEdge(v, u, w);
//	}
//	for (int i = 1,u; i <= k; i++) {
//		cin >> u;
//		people[u]++;
//	}
//	dfs1(1, 0);
//	dfs2(1, 0);
//	for (int i = 1; i <= n; i++) {
//		cout << incost[i] + outcost[i] - max(inner1[i], outer[i])<<endl;
//	}
//}


//换根dp着重与子树与外部信息