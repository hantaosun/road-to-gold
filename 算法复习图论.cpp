//最短路
//连通性
//树
//重心 直径 差分 分治
//匹配 2-sat
//网络流
//二分图判定


//dijkstra
//出队时标记访问，距离变小才更新，状态可自定义
//#include<bits/stdc++.h>
//using namespace std;
//int n, m, k;
//int s, t;
//const int N = 1e4+5;
//const int M = 1e5 + 5;
//const int K = 12;
//bool vis[N][K];
//int dis[N][K];
//int head[N];
//int nex[M];
//int to[M];
//int we[M];
//int cntg = 1;
//void addEdge(int u,int v,int w) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	we[cntg] = w;
//	head[u] = cntg++;
//}
//struct Compare {
//	bool operator()(array<int, 3>& a, array<int, 3>& b) {
//		return a[2] > b[2];
//	}
//};
//int main() {
//	cin >> n >> m >> k;
//	cin >> s >> t;
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= k; j++) {
//			dis[i][j] = INT_MAX;
//		}
//	}
//	for (int i = 1,a,b,c; i <= m; i++) {
//		cin >> a >> b >> c;
//		addEdge(a, b, c);
//		addEdge(b, a, c);
//	}
//	priority_queue<array<int,3>,vector<array<int,3>>,Compare>pq;
//	dis[s][k] = 0;
//	pq.push({ s,k,0 });
//	while (!pq.empty()) {
//		auto arr = pq.top();
//		pq.pop();
//		int u = arr[0], c = arr[1], w = arr[2];
//		if (vis[u][c])continue;
//		vis[u][c] = true;
//		for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//			if (dis[u][c] + we[ui] < dis[to[ui]][c]) {
//				pq.push({to[ui],c,dis[u][c]+we[ui]});
//				dis[to[ui]][c] = dis[u][c] + we[ui];
//			}
//			if (c > 0 && dis[u][c] < dis[to[ui]][c - 1]) {
//				pq.push({to[ui],c-1,dis[u][c]});
//				dis[to[ui]][c - 1] = dis[u][c];
//			}
//		}
//	}
//	int ans = INT_MAX;
//	for (int i = 0; i <= k; i++) {
//		ans = min(ans, dis[t][i]);
//	}
//	cout << ans << "\n";
//}

//BellmanFord
//求k次中转,用上轮距离来更新该轮
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 100;
//int ldis[N];
//int cdis[N];
//class Solution {
//public:
//    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//        for (int i = 0; i <= n; i++) {
//            ldis[i] = cdis[i]=1e8;
//        }
//        ldis[src] = 0;
//        for (int i = 1; i <= k + 1;i++) {
//            for (int i = 0; i <= n; i++) {
//                cdis[i] = ldis[i];
//            }
//            for (auto v : flights) {
//                if (ldis[v[0]] + v[2] < cdis[v[1]]) {
//                    cdis[v[1]] = ldis[v[0]] + v[2];
//                }
//            }
//            for (int i = 0; i <= n; i++) {
//                ldis[i] = cdis[i];
//            }
//        }
//        return cdis[dst] == INT_MAX ? -1 : cdis[dst];
//    }
//};

//SPFA
//判断从1出发有无负环,若判断全局负环,需要连超级源点
//更新次数大于n-1就说明有负环,出发点刚上来更新为0也算
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2e3 + 5;
//const int M = 8e3 + 5;
//int head[N];
//int nex[M];
//int to[M];
//int W[M];
//int dis[N];
//int cnt = 1;
//int inq[N];
//int updcnt[N];
//int n=0, m=0;
//void addEdge(int u, int v,int w) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	W[cnt] = w;
//	head[u] = cnt++;
//}
//bool spfa() {
//	queue<int>q;
//	dis[1] = 0;
//	updcnt[1]++;
//	inq[1] = true;
//	q.push(1);
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//		inq[u] = false;
//		for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//			int v = to[ui];
//			if (dis[u] + W[ui] < dis[v]) {
//				dis[v] = dis[u] + W[ui];
//				if (!inq[v]) {
//					if (++updcnt[v] >= n) {
//						return true;
//					}
//					q.push(v);
//					inq[v] = true;
//				}
//			}
//		}
//	}
//	return false;
//}
//void build() {
//	for (int i = 1; i <= n; i++) {
//		dis[i] = LLONG_MAX;
//		updcnt[i] = 0;
//		inq[i] = false;
//	}
//}
//void solve() {
//	for (int i = 1; i <= n; i++) {
//		head[i] = 0;
//	}
//	cnt = 1;
//	cin >> n >> m;	
//	build();
//	for (int i = 1; i <= n; i++) {
//		dis[i] = LLONG_MAX;
//	}
//	for (int i = 1,u,v,w; i <= m; i++) {
//		cin >> u >> v >> w;
//		if (w >= 0) {
//			addEdge(u, v, w);
//			addEdge(v, u, w);
//		}
//		else {
//			addEdge(u, v, w);
//		}
//	}
//	cout << (spfa() ? "YES":"NO") << "\n";
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


//割点
//dfs树中在该节点子树中存在节点low[v]>=dfn[u]则u是割点,根节点与其它节点判定需分开
//求桥将>=改为大于即可
//#include<bits/stdc++.h>
//using namespace std;
//int n, m;
//const int N = 2e4 + 5;
//const int M = 1e5 + 5;
//int dfn[N];
//int low[N];
//int head[N];
//int nex[M << 1];
//int to[M << 1];
//bool ap[N];
//int cntg = 1;
//int cnt = 0;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//void tarjan(int u,bool root) {
//	dfn[u] = low[u] = ++cnt;
//	int son = 0;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		int v = to[ui];
//		if (!dfn[v]) {
//			son++;
//			tarjan(v, false);
//			low[u] = min(low[u], low[v]);
//			if (!root&&low[v] >= dfn[u]) {//一定要判断是不是根
//				ap[u] = true;
//			}
//		}
//		else {
//			low[u] = min(low[u], dfn[v]);
//		}
//	}
//	if (root && son >= 2) {
//		ap[u] = true;
//	}
//}
//int main() {
//	cin >> n >> m;
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!dfn[i])tarjan(i, true);
//	}
//	int cn=0;
//	for (int i = 1; i <= n; i++) {
//		if (ap[i]) {
//			cn++;
//		}
//	}
//	cout << cn << "\n";
//	for (int i = 1; i <= n; i++) {
//		if (ap[i])cout << i << " ";
//	}cout << '\n';
//}
// 
// 
//强连通分量
//相当于无向图求边双(遍历边时只需要跳过入边的反向边即可)
//求点双需要在知道该点是割点后立刻
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e4 + 5;
//const int M = 1e5 + 5;
//int n, m;
//int head[N];
//int to[M];
//int nex[M];
//int cntg = 1;
//stack<int>sta;
//int insta[N];
//int dfn[N];
//int low[N];
//int cnt = 0;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//vector<vector<int>>scc;
//void tarjan(int u) {
//	dfn[u] = low[u] = ++cnt;
//	sta.push(u);
//	insta[u] = true;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		int v = to[ui];
//		if (!dfn[v]) {
//			tarjan(v);
//			low[u] = min(low[u], low[v]);
//		}
//		else if(insta[v]) {//其它情况说明已被处理过在别的连通分量,不用处理
//			low[u] = min(low[u], dfn[v]);
//		}
//	}
//	if (dfn[u] == low[u]) {
//		vector<int>tmp;
//		while (insta[u]) {
//			int v = sta.top();
//			sta.pop();
//			insta[v] = false;
//			tmp.push_back(v);
//		}
//		scc.push_back(tmp);
//	}
//}
//int id[N];
//int vis[N];
//int main() {
//	cin >> n >> m;
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!dfn[i]) {
//			tarjan(i);
//		}
//	}
//	for (int i = 0; i < scc.size(); i++) {
//		sort(scc[i].begin(), scc[i].end());
//		for (auto v : scc[i]) {
//			id[v] = i;
//		}
//	}
//	cout << scc.size() << "\n";
//	for (int i = 1; i <= n; i++) {
//		if (!vis[id[i]]) {
//			for (int j = 0; j < scc[id[i]].size(); j++) {
//				cout << scc[id[i]][j] << " ";
//			}
//			cout << "\n";
//			vis[id[i]] = true;
//		}
//	}
//}
//点双连通分量
//是割点就收集,但注意割点不弹出,因为割点可能是在多个点双连通分量中
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 5e5 + 5;
//const int M = 2e6 + 5;
//int head[N];
//int nex[M << 1];
//int to[M << 1];
//int cntg = 1;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//int dfn[N];
//int low[N];
//int cnt = 0;
//int sta[N];
//int r = 0;
//vector<vector<int>>ans;
//vector<int>tmp;
//void tarjan(int u, bool root) {
//	sta[++r] = u;
//	dfn[u] = low[u] = ++cnt;
//	int son = 0;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		int v = to[ui];
//		if (!dfn[v]) {
//			tarjan(v, 0);
//			low[u] = min(low[u], low[v]);
//			son++;
//			if (low[v] >= dfn[u]) {
//				tmp.clear();
//				int t;
//				do {
//					t = sta[r--];
//					tmp.push_back(t);
//				} while (t != v);
//				tmp.push_back(u);
//				ans.push_back(tmp);
//			}
//		}
//		else {
//			low[u] = min(low[u], dfn[v]);
//		}
//	}
//	if (root && son == 0) {
//		tmp.clear();
//		tmp.push_back(u);
//		ans.push_back(tmp);
//	}
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1, u, v; i <= m; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!dfn[i]) {
//			tarjan(i, true);
//		}
//	}
//	cout << ans.size() << '\n';
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i].size() << ' ';
//		for (auto v : ans[i]) {
//			cout << v << ' ';
//		}cout << '\n';
//	}
//}


//树上
//重心
//1.一颗树最多两个重心,若有两个一定相邻
//2.增删一个叶节点,重心最多动1条边
//3.两数相连新重心一定在原重心路径上
//4.若边权都为正数,所有节点走向重心总距离最小
//判定,最大子树节点树最少,每颗节点树不超过总节点树一半,所有节点走向该节点边数最少
//
//直径
//树上边权为正则,多条直径必有共同中间部分,树上任意一点,相隔最远的点的集合,直径的两端点至少有一个在其中
//两次dfs
//树形dp
//
//差分


//点分治
//#include<bits/stdc++.h>
//using namespace std;
//const int N=1e5+5;
//int del[N];
//int siz[N];
//int rt;//当前来到的树的根
//void dfs() {//收集信息
//
//}
//void dfs1() {//计算答案
//
//}
//void cal() {//计算当前答案
//
//}
//void divide() {//分治流程
//	del[u] = 1;
//	cal();
//	//遍历子树
//	//逐个子树分治
//}
//void getRt() {
//
//}
//int main() {
//
//}