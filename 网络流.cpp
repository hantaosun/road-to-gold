//#include<bits/stdc++.h>
//using namespace std;
//const int N = 205;
//const int M = 5e3 + 5;
//int n, m, s, t;
//int to[M<<1];
//int nex[M<<1];
//int head[N];
//long long cap[M << 1];
//int cnt = 2;
//void addEdge(int u, int v, int c) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	cap[cnt] = c;
//	head[u] = cnt++;
//}
//bool vis[N];
//int pre[N];
//long long incf[N];
//long long maxflow;
//bool bfs() {
//	memset(vis, 0, sizeof(vis));
//	queue<int>q;
//	q.push(s);
//	vis[s] = 1;
//	incf[s] = INT_MAX;
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//		for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//			if (cap[ui] != 0) {
//				int v = to[ui];
//				if (vis[v])continue;
//				incf[v] = min(incf[u], cap[ui]);
//				pre[v] = ui;
//				q.push(v);
//				vis[v] = 1;
//				if (v == t)return true;
//			}
//		}
//	}
//	return false;
//}
//void upd() {
//	int u = t;
//	while (u != s) {
//		int i = pre[u];
//		cap[i] -= incf[t];
//		cap[i ^ 1] += incf[t];
//		u = to[i^1];
//	}
//	maxflow += incf[t];
//}
//int main() {
//	maxflow = 0;
//	cin >> n >> m >> s >> t;
//	for (int i = 1,u,v,w; i <= m; i++) {
//		cin >> u >> v >> w;
//		addEdge(u, v, w);
//		addEdge(v, u, 0);
//	}
//	while (bfs())upd();
//	cout << maxflow << "\n";
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 205;
//const int M = 5e3 + 5;
//int n, m, s, t;
//int head[N];
//int to[M << 1];
//int nex[M << 1];
//long long cap[M << 1];
//int cnt=2;
//void addEdge(int u, int v, int c) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	cap[cnt] = c;
//	head[u] = cnt++;
//}
//int dep[N];
//int cur[N];
//bool bfs() {
//	memset(dep, -1, sizeof(dep));
//	queue<int>q;
//	q.push(s);
//	dep[s] = 0;
//	cur[s] = head[s];
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//		for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//			int v = to[ui];
//			if (dep[v] == -1 && cap[ui] != 0) {//忽略满流边和已经访问过的点
//				q.push(v);
//				dep[v] = dep[u] + 1;
//				cur[v] = head[v];
//				if (v == t) {
//					return true;
//				}
//			}
//		}
//	}
//	return false;
//}
//long long dfs(int u, long long limit) {
//	if (u == t) {
//		return limit;
//	}
//	long long flow = 0;
//	for (int ui = cur[u]; ui != 0 && flow < limit; ui = nex[ui]) {
//		cur[u] = ui;
//		int v = to[ui];
//		if (cap[ui] != 0 && dep[v] == dep[u] + 1) {
//			long long f=dfs(v, min(limit - flow, cap[ui]));
//			if (!f)dep[v] = -1;
//			cap[ui] -= f;
//			cap[ui ^ 1] += f;
//			flow += f;
//		}
//	}
//	return flow;
//}
//long long dinic() {
//	long long maxflow = 0,flow;
//	while (bfs()) {
//		while (flow = dfs(s, INT_MAX)) {
//			maxflow += flow;
//		}
//	}
//	return maxflow;
//}
//int main() {
//	cin >> n >> m >> s >> t;
//	for (int i = 1,u,v,w; i <= m; i++) {
//		cin >> u >> v >> w;
//		addEdge(u, v, w);
//		addEdge(v, u, 0);
//	}
//	cout << dinic() << "\n";
//}