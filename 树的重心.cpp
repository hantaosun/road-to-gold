//利用性质:以树的重心为根,树的最大子树最小 求重心
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 5 * 1e5 + 10;
//int n;
//int head[MAXN];
//int nex[MAXN<<1];
//int to[MAXN << 1];
//int cnt = 1;
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//int heart=1,siz=INT_MAX;
//int dfs(int i, int fa) {
//	int sum=0,maxSize=INT_MIN;
//	for (int ui = head[i]; ui != 0; ui=nex[ui]) {
//		if (to[ui] == fa)continue;
//		int t = dfs(to[ui], i);
//		sum += t;
//		maxSize = max(t, maxSize);
//	}
//	maxSize = max(n - 1 - sum, maxSize);
//	if (maxSize < siz) {
//		heart = i;
//		siz = maxSize;
//	}
//	return sum + 1;
//}
//int main() {
//	cin >> n;
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs(1, 1);
//	cout << heart << endl;
//}


//利用性质 以重心做根最大子树大小不超过总节点一半求所有重心
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 5 * 1e5 + 10;
//int n;
//int maxSize[MAXN];
//int head[MAXN];
//int nex[MAXN<<1];
//int to[MAXN << 1];
//int cnt = 1;
//int heart[2];
//int hh = 0;
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//int dfs(int i, int fa) {
//	int sum=0,mSize=INT_MIN;
//	for (int ui = head[i]; ui != 0; ui=nex[ui]) {
//		if (to[ui] == fa)continue;
//		int t = dfs(to[ui], i);
//		sum += t;
//		mSize = max(t, mSize);
//	}
//	mSize = max(n - 1 - sum, mSize);
//	maxSize[i] = mSize;
//	return sum + 1;
//}
//int main() {
//	cin >> n;
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	if (n == 1) {
//		cout << 1 << endl;
//		return;
//	}
//	dfs(1, 1);
//	for (int i = 1; i <= n; i++) {
//		if (maxSize[i] <= n / 2) {
//			heart[hh++] = i;
//		}
//	}
//	for (int i = 0; i < hh; i++)cout << heart[i] << " ";
//	cout << endl;
//}


//Great Cow Gathering G
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int N;
//int cows=0;
//const int MAXN = 1e5 + 10;
//int weight[MAXN];
//int plong[MAXN << 2];
//int head[MAXN];
//int to[MAXN<<1];
//int nex[MAXN << 1];
//int cnt = 1;
//int heart,  maxSize=INT_MAX;
//int dfs(int i, int fa) {
//	int sum = 0,mSize=INT_MIN;
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		int t=dfs(to[ui], i);
//		mSize = max(mSize, t);
//		sum += t;
//	}
//	mSize = max(mSize, cows - weight[i] - sum);
//	if (mSize < maxSize) {
//		heart = i;
//		maxSize = mSize;
//	}
//	return sum + weight[i];
//}
//int path[MAXN];
//void dfs1(int i,int fa,int length) {
//	path[i] = length;
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		dfs1(to[ui], i, length + plong[ui]);
//	}
//}
//void addEdge(int u, int v, int w) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	plong[cnt] = w;
//	head[u] = cnt++;
//}
//signed main() {
//	cin >> N;
//	for (int i = 1; i <= N; i++) {
//		cin >> weight[i];
//		cows += weight[i];
//	}
//	for (int i = 1,a,b,l; i < N; i++) {
//		cin >> a >> b >> l;
//		addEdge(a, b, l);
//		addEdge(b, a, l);
//	}
//	dfs(1, 1);
//	dfs1(heart, heart,0);
//	int ans = 0;
//	for (int i = 1; i <= N; i++) {
//		ans += path[i]*weight[i];
//	}
//	cout << ans << endl;
//}


//Link Cut Centroids
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1e5 + 10;
//int n;
//int cnt = 1;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN];
//int maxSize[MAXN];
//int heart[2];
//int hh = 0;
//int leaf = -1;
//void f(int i,int fa) {
//	if (leaf != -1)return;
//	bool hasson = 0;
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		hasson = 1;
//		f(to[ui], i);
//	}
//	if (!hasson)leaf = i;
//}
//int dfs(int i, int fa) {
//	int sum = 0, mSize = INT_MIN;
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		int t = dfs(to[ui], i);
//		sum += t;
//		mSize = max(mSize, t);
//	}
//	mSize = max(mSize, n - sum - 1);
//	maxSize[i] = mSize;
//	return sum + 1;
//}
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//void solve() {
//	cin >> n;
//	cnt = 1;
//	leaf = -1;
//	hh = 0;
//	memset(head, 0, sizeof(head));
//	memset(nex, 0, sizeof(nex));
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs(1, 1);
//	for (int i = 1; i <= n; i++) {
//		if (maxSize[i] <= n / 2) {
//			heart[hh++] = i;
//		}
//	}
//	if (hh == 1) {
//		cout << heart[0] << " " << to[head[heart[0]]] << endl;
//		cout << heart[0] << " " << to[head[heart[0]]] << endl;
//		return;
//	}
//	f(heart[1],heart[0]);
//	cout << to[head[leaf]] << " " << leaf << endl;
//	cout << heart[0] << " " << leaf << endl;
//}
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}