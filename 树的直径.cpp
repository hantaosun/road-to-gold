//【模板】树的直径
//双dfs版
//仅可处理非负边权情况
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 5 * 1e5 + 10;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int weight[MAXN << 1];
//int head[MAXN];
//int cnt = 1;
//int far;
//int dis = INT_MIN;
//void dfs(int i, int fa,int length) {
//	if (length > dis) {
//		far = i;
//		dis = length;
//	}
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		dfs(to[ui], i, length + weight[ui]);
//	}
//}
//void addEdge(int u, int v, int w) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	weight[cnt] = w;
//	head[u] = cnt++;
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1,u,v,w; i < n; i++) {
//		cin >> u >> v >> w;
//		addEdge(u, v, w);
//		addEdge(v, u, w);
//	}
//	dfs(1, 1,0);
//	dis = INT_MIN;
//	dfs(far, far, 0);//可以在本次dfs中记录路径信息得到直径的路径
//	cout << dis << endl;
//}
//
//树形dp版
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 5*1e5 + 10;
//int head[MAXN];
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int weight[MAXN << 1];
//int cnt = 1;
//void addEdge(int u, int v, int w) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	weight[cnt] = w;
//	head[u] = cnt++;
//}
//int ans = 0;//全局最大直径
//int dis[MAXN];//从当前点开始必须包含当前点往下能扎到的最长长度
//void f(int i, int fa) {
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		f(to[ui], i);
//	}
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		ans = max(ans, dis[i] + dis[to[ui]] + weight[ui]);
//		dis[i] = max(dis[i], weight[ui] + dis[to[ui]]);
//	}
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1,u,v,w; i < n; i++) {
//		cin >> u >> v >> w;
//		addEdge(u, v, w);
//		addEdge(v, u, w);
//	}
//	f(1, 0);
//	cout << ans << endl;
//}


//所有直径都过的边的长度
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 2 * 1e5 + 10;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int weight[MAXN << 1];
//int head[MAXN << 1];
//int cnt = 1;
//int last[MAXN];
//int lastLen[MAXN];
//bool belongdia[MAXN];
//int far;
//int dialong = 0;
//int l,r;
//int dfs1(int i,int fa) {
//	int ans = 0;
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (belongdia[to[ui]] || to[ui] == fa)continue;
//		ans = max(ans, dfs1(to[ui], i)+weight[ui]);
//	}
//	return ans;
//}
//void dfs(int i, int fa,int length) {
//	last[i] = fa;
//	if (length > dialong) {
//		far = i;
//		dialong = length;
//	}
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		lastLen[to[ui]] = weight[ui];
//		dfs(to[ui], i, length + weight[ui]);
//	}
//}
//void addEdge(int u,int v,int w) {
//	nex[cnt] = head[u];
//	weight[cnt] = w;
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//signed main() {
//	int n;
//	cin >> n;
//	for(int i = 1,u,v,w; i < n; i++) {
//		cin >> u >> v >> w;
//		addEdge(u, v, w);
//		addEdge(v, u, w);
//	}
//	dfs(1, 1,0);
//	l = far;
//	dialong = 0;
//	dfs(far, far, 0);
//	r = far;
//	//cout << dialong << endl;
//	for (int a = r; a != l; a = last[a]) {
//		belongdia[a] = true;
//	}
//	belongdia[l] = true;
//	int rest=l, lest=r;
//	//cout << l << " " << r << endl;
//	for (int a = last[r],i=lastLen[r]; a != l; a = last[a],i+=lastLen[a]) {
//		//cout << a<<endl;
//		if (dfs1(a, a) == i) {
//			//cout << a << " " << i << " equal to r"<<endl;
//			lest = a;
//		}
//		if (rest == l && dfs1(a, a) == dialong - i) {
//			//cout << a << " " << dis-i << " equal to r" << endl;
//			rest = a;
//		}
//	}
//	int count = 0;
//	//cout << lest << " " << rest << endl;
//	for (int i = lest; i != rest; i = last[i], count++);
//	cout << dialong << endl;
//	cout << count << endl;
//}


//SHT造公园
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 3e5 + 10;
//int fa[MAXN];
//int dia[MAXN];//该集合直径长度
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN];
//int cnt = 1;
//int find(int x) {
//	if (fa[x] != x) {
//		fa[x] = find(fa[x]);
//	}
//	return fa[x];
//}
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//int dis[MAXN];
//int ans = 0;
//void dfs(int i, int pa) {
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == pa)continue;
//		dfs(to[ui], i);
//	}
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == pa)continue;
//		ans = max(ans, dis[i] + dis[to[ui]] + 1);
//		dis[i] = max(dis[i], dis[to[ui]] + 1);
//	}
//}
//int main() {
//	int n, m, q;
//	cin >> n >> m >> q;
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//	}
//	for (int i = 1, u, v; i <= m; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//		fa[find(u)] = fa[find(v)];
//	}
//	for (int i = 1; i <= n; i++) {
//		if (fa[i] == i) {
//			dfs(i, i);
//			dia[i] = ans;
//			ans = 0;
//		}
//	}
//	for (int i = 1, o; i <= q; i++) {
//		cin >> o;
//		if (o == 1) {
//			int x;
//			cin >> x;
//			cout << dia[find(x)] << endl;
//		}
//		else {
//			int x, y;
//			cin >> x >> y;
//			int fx = find(x);
//			int fy = find(y);
//			if (fx == fy)continue;//麻了戈壁
//			dia[fy] = max(max(dia[fx], dia[fy]), (dia[fx] + 1) / 2 + (dia[fy] + 1) / 2 + 1);
//			fa[fx] = fa[fy];
//		}
//	}
//}


//巡逻
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1e5 + 10;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN];
//int cnt = 1;
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//int dis[MAXN];
//int last[MAXN];
//void dfs(int i, int fa,int d) {
//	last[i] = fa;
//	dis[i] = d;
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		dfs(to[ui], i,d+1);
//	}
//}
//int main() {
//	int n,K;
//	cin >> n;
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs(1, 1, 0);
//	int st = 1;
//	for (int i = 1; i <= n; i++) {
//		if (dis[i] > dis[st]) {
//			st = i;
//		}
//	}
//	dfs(st, st, 0);
//	int en = 1;
//	int dia = 0;
//	for (int i = 1; i < n; i++) {
//		if (dis[i] > dis[en]) {
//			en = i;
//			dia = dis[i];
//		}
//	}
//	if (K == 1) {
//		cout << 2 * (n - 1) - dia + 1 << endl;
//	}
//	if (K == 2) {
//
//	}
//}