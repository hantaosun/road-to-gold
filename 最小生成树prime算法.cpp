//#include<bits/stdc++.h>
//using namespace std;
//struct Compare {
//	bool operator()(array<int, 2>& a, array<int, 2>& b) {
//		return a[1] > b[1];
//	}
//};
//using namespace std;
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<array<int, 2>>>adj(n + 1);
//	for (int i = 1, u, v, w; i <= m; i++) {
//		cin >> u >> v >> w;
//		adj[u].push_back({ v,w });
//		adj[v].push_back({ u,w });
//	}
//	priority_queue<array<int, 2>, vector<array<int, 2>>, Compare> pq;
//	int ans = 0;
//	vector<bool>set(n + 1);
//	set[1] = true;
//	int vcnt = 1;
//	for (auto v : adj[1]) {
//		pq.push(v);
//	}
//	while (!pq.empty()) {
//		auto e = pq.top();
//		pq.pop();
//		if (!set[e[0]]) {
//			vcnt++;
//			ans += e[1];
//			set[e[0]] = true;
//			for (auto v : adj[e[0]]) {
//				pq.push(v);
//			}
//		}
//	}
//	if (vcnt == n)cout << ans << '\n';
//	else {
//		cout << "orz\n";
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 5005;
//const int M = 400001;
//int head[N];
//int nex[M];
//int to[M];
//int weight[M];
//int cnt;
//int nodeCnt;
//void addEdge(int u, int v, int w) {
//	nex[cnt] = head[u];
//	weight[cnt] = w;
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
//int heapSize;
//array<int, 2> heap[N];
//int where[N];//反向索引表 -1未访问 -2访问且已弹出 其余在堆中
//void swap(int i, int j) {
//	where[heap[i][0]] = j;
//	where[heap[j][0]] = i;
//	swap(heap[i], heap[j]);
//}
//void up(int i) {//向上调整i位置
//	while (heap[i][1] < heap[(i - 1) / 2][1]) {
//		swap(i, (i - 1) / 2);
//		i = (i - 1) / 2;
//	}
//}
//void down(int i) {
//	int l = i * 2 + 1;//0位置使用左孩子就是2*i+1
//	while (l < heapSize) {
//		int best = l + 1 < heapSize && heap[l + 1][1] < heap[l][1] ? l + 1 : l;
//		best = heap[best][1] < heap[i][1] ? best : i;
//		if (best == i) {
//			break;
//		}
//		swap(best, i);
//		i = best;
//		l = 2 * i + 1;
//	}
//}
//void addOrUpdateOrIgnore(int e) {
//	int v = to[e];
//	int w = weight[e];
//	if (where[v] == -1) {//没访问过,加入堆
//		heap[heapSize][0] = v;
//		heap[heapSize][1] = w;
//		where[v] = heapSize++;
//		up(where[v]);//加入后向上调整
//	}
//	else if (where[v] >= 0) {
//		heap[where[v]][1] = min(w, heap[where[v]][1]);
//		up(where[v]);//因为是调小,所以只可能向上调整
//	}
//}
//void prepare() {
//	cnt = 1;
//	heapSize = 0;
//	nodeCnt = 0;
//	memset(head, 0, sizeof(head));
//	memset(where, -1, sizeof(where));
//}
//int u, w;
//void pop() {//弹出堆顶节点,拿最后一个节点顶上来,并且向下调整
//	u = heap[0][0];
//	w = heap[0][1];
//	swap(0, --heapSize);
//	down(0);
//	where[u] = -2;
//	nodeCnt++;
//}
//int main() {
//	prepare();
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1, u, v, w; i <= m; i++) {
//		cin >> u >> v >> w;
//		addEdge(u, v, w);
//		addEdge(v, u, w);
//	}
//	where[1] = -2;
//	nodeCnt = 1;
//	for (int ui = head[1]; ui != 0; ui = nex[ui]) {
//		addOrUpdateOrIgnore(ui);
//	}
//	int ans = 0;
//	while (heapSize != 0) {
//		pop();
//		ans += w;
//		for (int ei = head[u]; ei != 0; ei = nex[ei]) {
//			addOrUpdateOrIgnore(ei);
//		}
//	}
//	if (nodeCnt != n)cout << "orz\n";
//	else cout << ans << '\n';
//}