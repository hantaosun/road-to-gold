//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//struct Compare {
//	bool operator()(array<int,2>&a,array<int,2>&b) {
//		return a[1] > b[1];
//	}
//};
//signed main() {
//	int n, m, s;
//	cin >> n >> m >> s;
//	vector<vector<array<int,2>>>adj(n+1);
//	for (int i = 1,u,v,w; i <= m; i++) {
//		cin >> u >> v >> w;
//		adj[u].push_back({ v,w });
//		adj[v].push_back({ u,w });
//	}
//	priority_queue<array<int, 2>, vector<array<int, 2>>, Compare>pq;
//	vector<int>dis(n + 1, LLONG_MAX);
//	vector<bool>vis(n + 1, false);
//	pq.push({ s,0 });
//	dis[s] = 0;
//	while (!pq.empty()) {
//		auto e = pq.top();
//		pq.pop();
//		if (vis[e[0]])continue;
//		vis[e[0]] = true;
//		for (auto to : adj[e[0]]) {
//			int w = to[1];
//			int v = to[0];
//			if (!vis[v] && dis[v] > dis[e[0]] + w) {
//				dis[v] = dis[e[0]] + w;
//				pq.push({ v,dis[v] });
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << dis[i] << " ";
//	}cout << '\n';
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 100;
//int nn;
//int ldis[N];
//int cdis[N];
//int start;
//void run(vector<vector<int>>& e) {
//    for (int i = 0; i < nn; i++) {
//        cdis[i] = ldis[i];
//    }
//    for (vector<int>& edge : e) {
//        int u = edge[0], v = edge[1], w = edge[2];
//        if (ldis[u] + w < cdis[v]) {//注意这里是核心
//            cdis[v] = ldis[u] + w;
//        }
//    }
//    for (int i = 0; i < nn; i++) {
//        ldis[i] = cdis[i];
//    }
//}
//class Solution {
//public:
//    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//        for (int i = 0; i < n; i++) {
//            ldis[i] = 1e8;
//        }
//        start = src;
//        nn = n;
//        ldis[src] = 0;
//        for (int i = 1; i <= k + 1; i++) {
//            run(flights);
//        }
//        return (ldis[dst] == 1e8 ? -1 : ldis[dst]);
//    }
//};



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