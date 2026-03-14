//重链剖分
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 1e5 + 10;
//int n, m, r, mod;
//
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN];
//int cntg = 1;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//int weight[MAXN];//当前节点权值
//int fa[MAXN];//父节点是谁
//int dep[MAXN];//当前节点深度
//int siz[MAXN];//当前子树大小搭配dfn序使用
//int son[MAXN];//重儿子是谁,没有则为0
//int top[MAXN];//当前节点所在链的头部节点是谁
//int dfn[MAXN];//dfn序
//int seg[MAXN];//dfn序的反向索引
//int cntd = 0;
//
////线段树内容
//int sum[MAXN << 2];
//int ad[MAXN << 2];
//void lazy(int i,int v,int n) {
//	sum[i] = (sum[i] + (n * v)%mod) % mod;
//	ad[i] = (ad[i] + v)%mod;
//}
//void up(int i) {
//	sum[i] = (sum[i << 1] + sum[i << 1 | 1])%mod;
//}
//void down(int i, int ln, int rn) {
//	if (ad[i] != 0) {
//		lazy(i << 1, ad[i], ln);
//		lazy(i << 1 | 1, ad[i], rn);
//	}
//	ad[i] = 0;
//}
//void add(int jl,int jr,int v,int l,int r,int i){
//	if (jl <= l && jr >= r) {
//		lazy(i, v, r - l + 1);
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i, mid - l + 1, r - mid);
//		if (jl <= mid) {
//			add(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			add(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//int query(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int mid = l + r >> 1;
//	int ans = 0;
//	down(i, mid - l + 1, r - mid);
//	if (jl <= mid) {
//		ans = (ans + query(jl, jr, l, mid, i << 1))%mod;
//	}
//	if (jr > mid) {
//		ans = (ans+query(jl, jr, mid + 1, r, i << 1 | 1))%mod;
//	}
//	return ans;
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = weight[seg[l]];
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	ad[i] = 0;
//}
//void dfs1(int u, int pa) {
//	siz[u] = 1;
//	fa[u] = pa;
//	dep[u] = dep[pa] + 1;
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == pa)continue;
//		dfs1(to[e], u);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == pa)continue;
//		int v = to[e];
//		if (son[u] == 0 || siz[son[u]] < siz[v])
//			son[u] = v;
//		siz[u] += siz[v];
//	}
//}
//void add(int x, int y, int v) {
//	while (top[x] != top[y]) {//一次只能跳一个!!!
//		if (dep[top[x]] <= dep[top[y]]) {
//			add(dfn[top[y]], dfn[y], v, 1, n, 1);
//			y = fa[top[y]];
//		}
//		else {
//			add(dfn[top[x]], dfn[x], v, 1, n, 1);
//			x = fa[top[x]];
//		}
//	}
//	add(min(dfn[x],dfn[y]), max(dfn[x],dfn[y]), v, 1, n, 1);
//}
//void add(int x, int v) {
//	add(dfn[x], dfn[x] + siz[x] - 1, v, 1, n, 1);
//}
//int query(int x, int y) {
//	int sum = 0;
//	while (top[x] != top[y]) {//一次只能跳一个!!!
//		if (dep[top[x]] <= dep[top[y]]) {
//			sum = (sum + query(dfn[top[y]], dfn[y], 1, n, 1))%mod;
//			y = fa[top[y]];
//		}
//		else {
//			sum = (sum + query(dfn[top[x]], dfn[x], 1, n, 1))% mod;
//			x = fa[top[x]];
//		}
//	}
//	sum = (sum + query(min(dfn[x], dfn[y]), max(dfn[x], dfn[y]), 1, n, 1))%mod;
//	return sum;
//}
//int query(int x) {
//	return query(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1);
//}
//void dfs2(int u, int t) {
//	top[u] = t;
//	dfn[u] = ++cntd;
//	seg[cntd] = u;
//	if (son[u] == 0)return;
//	dfs2(son[u], t);
//	for (int e = head[u], v; e != 0; e = nex[e]) {
//		v = to[e];
//		if (v != fa[u] && v != son[u]) {
//			dfs2(v, v);
//		}
//	}
//}
//
//signed main() {
//	cin >> n >> m >> r >> mod;
//	for (int i = 1; i <= n; i++) {
//		cin >> weight[i];
//	}
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs1(r, 0);
//	dfs2(r, r);
//	build(1, n, 1);
//	for (int i = 1, o,x,y,z; i <= m; i++) {
//		cin >> o;
//		switch (o) {
//		case 1: {
//			cin >> x >> y >> z;
//			add(x, y, z);
//			break;
//		}
//		case 2: {
//			cin >> x >> y;
//			cout << query(x, y)%mod<<endl;
//			break;
//		}
//		case 3: {
//			cin >> x >> z;
//			add(x, z);
//			break;
//		}
//		case 4: {
//			cin >> x;
//			cout << query(x)%mod << endl;
//			break;
//		}
//		}
//	}
//}


//树链剖分解决LCA
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 5e5 + 10;
//int nex[MAXN<<1];
//int to[MAXN << 1];
//int head[MAXN];
//int cntg = 1;
//
//int fa[MAXN];
//int siz[MAXN];
//int dep[MAXN];
//int son[MAXN];
//int top[MAXN];
//int dfn[MAXN];
//int seg[MAXN];
//int cntd = 0;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//void dfs1(int u, int pa) {
//	siz[u] = 1;
//	fa[u] = pa;
//	dep[u] = dep[pa] + 1;
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == pa)continue;
//		dfs1(to[e], u);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == pa)continue;
//		siz[u] += siz[to[e]];
//		if (son[u] == 0 || siz[son[u]] < siz[to[e]]) {
//			son[u] = to[e];
//		}
//	}
//}
//void dfs2(int u, int t) {
//	top[u] = t;
//	dfn[u] = ++cntd;
//	seg[cntd] = u;
//	if (son[u] != 0) {
//		dfs2(son[u], t);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == son[u]||to[e]==fa[u])continue;
//		dfs2(to[e], to[e]);
//	}
//}
//int lca(int u, int v) {
//	while (top[u] != top[v]) {
//		if (dep[top[u]] <= dep[top[v]]) {
//			v = fa[top[v]];
//		}
//		else {
//			u = fa[top[u]];
//		}
//	}
//	return dep[u] < dep[v] ? u : v;
//}
//int main() {
//	int n, m, s;
//	cin >> n >> m >> s;
//	for (int i = 1,x,y; i < n; i++) {
//		cin >> x >> y;
//		addEdge(x, y);
//		addEdge(y, x);
//	}
//	dfs1(s, 0);
//	dfs2(s, s);
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		cout << lca(u, v) << endl;
//	}
//}


//树的统计
//注意线段树使用原数组值时一定要注意因为原数组值可能不会更新
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 3e4 + 10;
//int n, q;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN];
//int cntg = 1;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//
//int weight[MAXN];
//int fa[MAXN];
//int son[MAXN];
//int siz[MAXN];
//int dep[MAXN];
//int top[MAXN];
//int dfn[MAXN];
//int seg[MAXN];
//int cntd = 0;
//void dfs1(int u, int pa) {
//	fa[u] = pa;
//	siz[u] = 1;
//	dep[u] = dep[pa] + 1;
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == pa)continue;
//		dfs1(to[e], u);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == pa)continue;
//		if (son[u] == 0 || siz[son[u]] < siz[to[e]]) {
//			son[u] = to[e];
//		}
//		siz[u] += siz[to[e]];
//	}
//}
//void dfs2(int u, int t) {
//	top[u] = t;
//	dfn[u] = ++cntd;
//	seg[cntd] = u;
//	if (son[u] != 0) {
//		dfs2(son[u], t);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa[u] || to[e] == son[u])continue;
//		dfs2(to[e], to[e]);
//	}
//}
//
//int sum[MAXN << 2];
//int Max[MAXN << 2];
//int ad[MAXN << 2];
//void lazy(int i, int v, int n) {
//	sum[i] += v * n;
//	ad[i] += v;
//	Max[i] += v;
//}
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//	Max[i] = max(Max[i << 1], Max[i << 1 | 1]);
//}
//void down(int i, int ln, int rn) {
//	if (ad[i] != 0) {
//		lazy(i << 1, ad[i], ln);
//		lazy(i << 1 | 1, ad[i], rn);
//		ad[i] = 0;
//	}
//}
//void add(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v, r - l + 1);
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i, mid - l + 1, r - mid);
//		if (jl <= mid) {
//			add(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			add(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//int querySum(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	else {
//		int ans = 0;
//		int mid = l + r >> 1;
//		down(i, mid - l + 1, r - mid);
//		if (jl <= mid) {
//			ans += querySum(jl, jr, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			ans += querySum(jl, jr, mid + 1, r, i << 1 | 1);
//		}
//		return ans;
//	}
//}
//int queryMax(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return Max[i];
//	}
//	else {
//		int ans = INT_MIN;
//		int mid = l + r >> 1;
//		down(i, mid - l + 1, r - mid);
//		if (jl <= mid) {
//			ans = max(ans, queryMax(jl, jr, l, mid, i << 1));
//		}
//		if (jr > mid) {
//			ans = max(ans, queryMax(jl, jr, mid + 1, r, i << 1 | 1));
//		}
//		return ans;
//	}
//}
//int querySum(int u, int v) {
//	int ans = 0;
//	while (top[u] != top[v]) {
//		if (dep[top[u]] <= dep[top[v]]) {
//			ans += querySum(dfn[top[v]], dfn[v], 1, n, 1);
//			v = fa[top[v]];
//		}
//		else{
//			ans += querySum(dfn[top[u]], dfn[u], 1, n, 1);
//			u = fa[top[u]];
//		}
//	}
//	ans += querySum(min(dfn[u], dfn[v]), max(dfn[u], dfn[v]), 1, n, 1);
//	return ans;
//}
//int queryMax(int u, int v) {
//	int ans = INT_MIN;
//	while (top[u] != top[v]) {
//		if (dep[top[u]] <= dep[top[v]]) {
//			ans =max(ans,queryMax(dfn[top[v]], dfn[v], 1, n, 1));
//			v = fa[top[v]];
//		}
//		else {
//			ans = max(ans,queryMax(dfn[top[u]], dfn[u], 1, n, 1));
//			u = fa[top[u]];
//		}
//	}
//	ans = max(ans, queryMax(min(dfn[u], dfn[v]), max(dfn[u], dfn[v]), 1, n, 1));
//	return ans;
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i]=Max[i] = weight[seg[l]];
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	ad[i] = 0;
//}
//int main() {
//	cin >> n;
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs1(1, 0);
//	dfs2(1, 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> weight[i];
//	}
//	build(1, n, 1);
//	cin >> q;
//	for (int i = 1, a, b; i <= q; i++) {
//		string s;
//		cin >> s >> a >> b;
//		if (s == "CHANGE") {
//			add(dfn[a],dfn[a], b - querySum(dfn[a],dfn[a],1,n,1), 1, n, 1);
//		}
//		else if (s == "QMAX") {
//			cout << queryMax(a, b)<<endl;
//		}
//		else {
//			cout << querySum(a, b) << endl;
//		}
//	}
//}


//软件包管理器
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1e5 + 10;
//int n, q;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN];
//int cntg = 1;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//
//int weight[MAXN];
//int fa[MAXN];
//int son[MAXN];
//int siz[MAXN];
//int dep[MAXN];
//int top[MAXN];
//int dfn[MAXN];
//int seg[MAXN];
//int cntd = 0;
//void dfs1(int u, int pa) {
//	fa[u] = pa;
//	siz[u] = 1;
//	dep[u] = dep[pa] + 1;
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == pa)continue;
//		dfs1(to[e], u);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == pa)continue;
//		if (son[u] == 0 || siz[son[u]] < siz[to[e]]) {
//			son[u] = to[e];
//		}
//		siz[u] += siz[to[e]];
//	}
//}
//void dfs2(int u, int t) {
//	top[u] = t;
//	dfn[u] = ++cntd;
//	seg[cntd] = u;
//	if (son[u] != 0) {
//		dfs2(son[u], t);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa[u] || to[e] == son[u])continue;
//		dfs2(to[e], to[e]);
//	}
//}
//
//int sum[MAXN << 2];
//int upd[MAXN << 2];
//void lazy(int i, int v, int n) {
//	sum[i] = v * n;
//	upd[i] = v;
//}
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//void down(int i, int ln, int rn) {
//	if (upd[i] != -1) {
//		lazy(i << 1, upd[i], ln);
//		lazy(i << 1 | 1, upd[i], rn);
//		upd[i] = -1;
//	}
//}
//void update(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v, r - l + 1);
//	}
//	else {
//		int mid = l + r >> 1;
//		if (jl <= mid) {
//			update(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			update(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//int querySum(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	else {
//		int ans = 0;
//		int mid = l + r >> 1;
//		down(i, mid - l + 1, r - mid);
//		if (jl <= mid) {
//			ans += querySum(jl, jr, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			ans += querySum(jl, jr, mid + 1, r, i << 1 | 1);
//		}
//		return ans;
//	}
//}
//
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = 0;
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	upd[i] = -1;
//}
//int main() {
//	cin >> n;
//	for (int i = 2, u; i <= n; i++) {
//		cin >> u;
//		addEdge(u + 1, i);
//		addEdge(i, u + 1);
//	}
//	dfs1(1, 0);
//	dfs2(1, 1);
//	build(1, n, 1);
//	
//	//调试用
//	//for (int i = 1; i <= n; i++) {
//	//	cout << dep[i] << " ";
//	//}
//	//cout << endl;
//	
//	cin >> q;
//	for (int i = 1, x; i <= q; i++) {
//		string s;
//		cin >> s >> x;
//		x++;
//		if (s == "install") {
//			int ans = dep[x];
//			while (x!=0) {
//				ans -= querySum(dfn[top[x]], dfn[x],1,n,1);
//				update(dfn[top[x]], dfn[x], 1, 1, n, 1);
//				x = fa[top[x]];
//			}
//			cout << ans << endl;
//		}
//		else {
//			cout<<querySum(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1)<<endl;
//			update(dfn[x], dfn[x] + siz[x] - 1, 0, 1, n, 1);
//		}
//	}
//}


//染色
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1e5 + 10;
//int n, m;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN];
//int cntg = 1;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//
//int fa[MAXN];
//int son[MAXN];
//int siz[MAXN];
//int dep[MAXN];
//int top[MAXN];
//int dfn[MAXN];
//int seg[MAXN];
//int cntd = 0;
//void dfs1(int u, int pa) {
//	fa[u] = pa;
//	siz[u] = 1;
//	dep[u] = dep[pa] + 1;
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == pa)continue;
//		dfs1(to[e], u);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == pa)continue;
//		if (son[u] == 0 || siz[son[u]] < siz[to[e]]) {
//			son[u] = to[e];
//		}
//		siz[u] += siz[to[e]];
//	}
//}
//void dfs2(int u, int t) {
//	top[u] = t;
//	dfn[u] = ++cntd;
//	seg[cntd] = u;
//	if (son[u] != 0) {
//		dfs2(son[u], t);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa[u] || to[e] == son[u])continue;
//		dfs2(to[e], to[e]);
//	}
//}
//
//int color[MAXN];
//int kind[MAXN << 2];
//int upd[MAXN << 2];
//int lcolor[MAXN << 2];
//int rcolor[MAXN << 2];
//void lazy(int i, int v) {
//	kind[i] = 1;
//	lcolor[i] = rcolor[i] = v;
//	upd[i] = v;
//}
//void up(int i) {
//	kind[i] = kind[i << 1] + kind[i << 1 | 1];
//	if (rcolor[i << 1] == lcolor[i << 1 | 1])kind[i]--;
//	lcolor[i] = lcolor[i << 1];
//	rcolor[i] = rcolor[i << 1 | 1];
//}
//void down(int i) {
//	if (upd[i] != -1) {
//		lazy(i << 1, upd[i]);
//		lazy(i << 1 | 1, upd[i]);
//		upd[i] =-1;
//	}
//}
//void update(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v);
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i);
//		if (jl <= mid) {
//			update(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			update(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//void update(int u,int v,int c) {
//	while (top[u] != top[v]) {
//		if (dep[top[u]] <= dep[top[v]]) {
//			update(dfn[top[v]], dfn[v],c, 1, n, 1);
//			v = fa[top[v]];
//		}
//		else {
//			update(dfn[top[u]], dfn[u],c, 1, n, 1);
//			u = fa[top[u]];
//		}
//	}
//	update(min(dfn[u], dfn[v]), max(dfn[u], dfn[v]),c, 1, n, 1);
//}
//
//int queryColor(int x, int l, int r, int i) {
//	if (l == r) {
//		return lcolor[i];
//	}
//	int mid = l + r >> 1;
//	down(i);
//	if (x <= mid) {
//		return queryColor(x, l, mid, i << 1);
//	}
//	else {
//		return queryColor(x, mid + 1, r, i << 1 | 1);
//	}
//}
//int queryKinds(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return kind[i];
//	}
//	else {
//		int ans = 0;
//		int mid = l + r >> 1;
//		down(i);
//		if (jr <= mid) {
//			return queryKinds(jl, jr, l, mid, i << 1);
//		}
//		if (jl > mid) {
//			return queryKinds(jl, jr, mid + 1, r, i << 1 | 1);
//		}
//		ans+= queryKinds(jl, jr, l, mid, i << 1);
//		ans+= queryKinds(jl, jr, mid + 1, r, i << 1 | 1);
//		if (rcolor[i << 1] == lcolor[i << 1 | 1])ans--;
//		return ans;
//	}
//}
//int queryKinds(int u, int v) {
//	int ans = 0;
//	int lastcolorU=-1, lastcolorV=-1;
//	while (top[u] != top[v]) {
//		if (dep[top[u]] <= dep[top[v]]) {
//			ans += queryKinds(dfn[top[v]], dfn[v], 1, n, 1);
//			if (queryColor(dfn[v], 1, n, 1) == lastcolorV)ans--;
//			lastcolorV = queryColor(dfn[top[v]], 1, n, 1);
//			v = fa[top[v]];
//		}
//		else{
//			ans += queryKinds(dfn[top[u]], dfn[u], 1, n, 1);
//			if (queryColor(dfn[u], 1, n, 1) == lastcolorU)ans--;
//			lastcolorU = queryColor(dfn[top[u]], 1, n, 1);
//			u = fa[top[u]];
//		}
//	}
//	ans += queryKinds(min(dfn[u], dfn[v]), max(dfn[u], dfn[v]), 1, n, 1);
//	if (queryColor(dfn[v], 1, n, 1) == lastcolorV)ans--;
//	if (queryColor(dfn[u], 1, n, 1) == lastcolorU)ans--;
//	return ans;
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		kind[i]=1;
//		lcolor[i] =rcolor[i]=color[seg[l]];
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	upd[i] = -1;
//}
//void Debug(int l, int r, int i) {
//	cout << "当前区间[ " << l << " , " << r << " ] 对应下标:"<<i<< "[" << seg[l] << ", " << seg[r] << "]" << endl;
//	cout << "kind[i] : " << kind[i] << endl;
//	cout << "lcolor[i] : " << lcolor[i] << endl;
//	cout << "rcolor[i] : " << rcolor[i] << endl;
//	if (l < r) {
//		int mid = l + r >> 1;
//		Debug(l, mid, i << 1);
//		Debug(mid + 1, r, i << 1 | 1);
//	}
//}
//int main() {
//	cin >> n>>m;
//	for (int i = 1; i <= n; i++) {
//		cin >> color[i];
//	}
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs1(1, 0);
//	dfs2(1, 1);
//	build(1, n, 1);
//
//	//用于调试
//	//Debug(1, n, 1);
//	//for (int i = 1; i <= n; i++)cout << dfn[i] << " ";
//	//cout << endl;
//	//for (int i = 1; i <= n; i++)cout << queryColor(dfn[i],1,n,1)<<" ";
//	//cout << endl;
//
//	for (int i = 1, a, b,c; i <= m; i++) {
//		char op;
//		cin >> op;
//		if (op=='C') {
//			cin >> a >> b>>c;
//			update(a, b, c);
//		}
//		else {
//			cin >> a >> b;
//			cout << queryKinds(a, b)<<endl;
//		}
//		//for (int i = 1; i <= n; i++)cout << queryColor(dfn[i], 1, n, 1) << " ";
//		//cout << endl;
//	}
//}


//旅游
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 5e4 + 10;
//int n, q;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN];
//int cntg = 1;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//
//int price[MAXN];
//int fa[MAXN];
//int son[MAXN];
//int siz[MAXN];
//int dep[MAXN];
//int top[MAXN];
//int dfn[MAXN];
//int seg[MAXN];
//int cntd = 0;
//void dfs1(int u, int pa) {
//	fa[u] = pa;
//	siz[u] = 1;
//	dep[u] = dep[pa] + 1;
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == pa)continue;
//		dfs1(to[e], u);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == pa)continue;
//		if (son[u] == 0 || siz[son[u]] < siz[to[e]]) {
//			son[u] = to[e];
//		}
//		siz[u] += siz[to[e]];
//	}
//}
//void dfs2(int u, int t) {
//	top[u] = t;
//	dfn[u] = ++cntd;
//	seg[cntd] = u;
//	if (son[u] != 0) {
//		dfs2(son[u], t);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa[u] || to[e] == son[u])continue;
//		dfs2(to[e], to[e]);
//	}
//}
//
//int bestlr[MAXN << 2];
//int bestrl[MAXN << 2];
//int Max[MAXN << 2];
//int Min[MAXN << 2];
//int ad[MAXN << 2];
//void lazy(int i, int v) {
//	ad[i] += v;
//	Max[i] += v;
//	Min[i] += v;
//}
//void up(int i) {
//	Min[i] = min(Min[i << 1], Min[i << 1 | 1]);
//	Max[i] = max(Max[i << 1], Max[i << 1 | 1]);
//	bestlr[i] = max({ bestlr[i << 1], bestlr[i << 1 | 1], Max[i << 1 | 1] - Min[i << 1] });
//	bestrl[i] = max({ bestrl[i << 1], bestrl[i << 1 | 1], Max[i << 1] - Min[i << 1 | 1] });
//}
//void down(int i) {
//	if (ad[i] != 0) {
//		lazy(i << 1, ad[i]);
//		lazy(i << 1 | 1, ad[i]);
//		ad[i] = 0;
//	}
//}
//void add(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v);
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i);
//		if (jl <= mid) {
//			add(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			add(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//int queryMax(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return Max[i];
//	}
//	else {
//		int ans = INT_MIN;
//		int mid = l + r >> 1;
//		down(i);
//		if (jl <= mid) {
//			ans = max(ans, queryMax(jl, jr, l, mid, i << 1));
//		}
//		if (jr > mid) {
//			ans = max(ans, queryMax(jl, jr, mid + 1, r, i << 1 | 1));
//		}
//		return ans;
//	}
//}
//int queryMin(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return Min[i];
//	}
//	else {
//		int ans = INT_MAX;
//		int mid = l + r >> 1;
//		down(i);
//		if (jl <= mid) {
//			ans = min(ans, queryMin(jl, jr, l, mid, i << 1));
//		}
//		if (jr > mid) {
//			ans = min(ans, queryMin(jl, jr, mid + 1, r, i << 1 | 1));
//		}
//		return ans;
//	}
//}
//int queryBestlr(int jl, int jr, int l, int r, int i) {
//	//cout << jl << " " << jr << " " << l << " " << r<<" "<<i << endl;
//	if (jl <= l && jr >= r) {
//		return bestlr[i];
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i);
//		if (jl > mid) {
//			return queryBestlr(jl, jr, mid+1, r, i << 1|1);
//		}
//		if (jr <= mid) {
//			return queryBestlr(jl, jr, l, mid, i << 1);
//		}
//		
//		//cout << Max[i << 1 | 1] <<" "<< Min[i << 1] << " " << queryBestlr(jl, jr, mid + 1, r, i << 1 | 1) << " " << queryBestlr(jl, jr, l, mid, i << 1) << "***\n";
//		return max(queryMax(jl,jr,mid+1,r,i << 1 | 1) - queryMin(jl,jr,l,mid,i << 1), max(queryBestlr(jl, jr, mid + 1, r, i << 1 | 1), queryBestlr(jl, jr, l, mid, i << 1)));
//	}
//}
//int queryBestrl(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return bestrl[i];
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i);
//		if (jl > mid) {
//			return queryBestrl(jl, jr, mid + 1, r, i << 1 | 1);
//		}
//		if (jr <= mid) {
//			return queryBestrl(jl, jr, l, mid, i << 1);
//		}
//		return max(queryMax(jl,jr,l,mid,i << 1) - queryMin(jl,jr,mid+1,r,i << 1|1), max(queryBestrl(jl, jr, mid + 1, r, i << 1 | 1), queryBestrl(jl, jr, l, mid, i << 1)));
//	}
//}
//
//void build(int l, int r, int i) {
//	if (l == r) {
//		Min[i]=Max[i] = price[seg[l]];
//		bestlr[i] = 0;
//		bestrl[i] = 0;
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	ad[i] = 0;
//}
//int queryProfit(int u, int v) {
//	int VMAX=queryMax(dfn[v],dfn[v],1,n,1);
//	int UMIN=queryMin(dfn[u],dfn[u],1,n,1);
//	int VBEST=0;
//	int UBEST=0;
//	//cout << VMAX << " " << VBEST << " " << UMIN << " " << UBEST << endl;
//	while (top[u] != top[v]) {
//		//cout << u << " & " << v << endl;
//		//cout << "ok\n";
//		if (dep[top[u]] <= dep[top[v]]) {
//			VBEST = max(VBEST, max(queryBestlr(dfn[top[v]], dfn[v], 1, n, 1),VMAX-queryMin(dfn[top[v]],dfn[v],1,n,1)));
//			VMAX = max(VMAX, queryMax(dfn[top[v]], dfn[v], 1, n, 1));
//			v = fa[top[v]];
//		}
//		else {
//			UBEST = max(UBEST, max(queryBestrl(dfn[top[u]], dfn[u], 1, n, 1), queryMax(dfn[top[u]], dfn[u], 1, n, 1) - UMIN));
//			UMIN = min(UMIN, queryMin(dfn[top[u]], dfn[u], 1, n, 1));
//			u = fa[top[u]];
//		}
//	}
//	//cout << u << " & " << v << endl;
//	if (dep[u] <= dep[v]) {
//		//cout << "ok1\n";
//		//cout << VMAX << " " << VBEST << " " << UMIN << " " << UBEST << endl;
//		//cout << queryMin(dfn[u], dfn[v], 1, n, 1) << endl;
//		//cout << VMAX - queryMin(dfn[u], dfn[v], 1, n, 1) << endl;
//		//cout << queryBestlr(dfn[u], dfn[v], 1, n, 1) << endl;
//		VBEST = max(VBEST, max(queryBestlr(dfn[u], dfn[v], 1, n, 1), VMAX - queryMin(dfn[u], dfn[v], 1, n, 1)));
//		VMAX = max(VMAX, queryMax(dfn[u], dfn[v], 1, n, 1));
//	}
//	else {
//		//cout << "ok2\n";
//		UBEST = max(UBEST, max(queryBestrl(dfn[v], dfn[u], 1, n, 1), queryMax(dfn[v], dfn[u], 1, n, 1) - UMIN));
//		UMIN = min(UMIN, queryMin(dfn[v], dfn[u], 1, n, 1));
//	}
//	//cout << VMAX << " " << VBEST << " " << UMIN << " " << UBEST << endl;
//	return max(VMAX - UMIN, max(VBEST, UBEST));
//}
//void add(int u,int v,int c) {
//	while (top[u] != top[v]) {
//		if (dep[top[u]] <= dep[top[v]]) {
//			add(dfn[top[v]], dfn[v],c, 1, n, 1);
//			v = fa[top[v]];
//		}
//		else {
//			add(dfn[top[u]], dfn[u],c, 1, n, 1);
//			u = fa[top[u]];
//		}
//	}
//	add(min(dfn[u], dfn[v]), max(dfn[u], dfn[v]),c, 1, n, 1);
//}
//signed main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> price[i];
//	}
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs1(1, 0);
//	dfs2(1, 1);
//	build(1, n, 1);
//	//cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
//	//cout<<queryBestlr(dfn[2], dfn[4], 1, n, 1)<<endl;
//	//cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
//	//用于调试
//	//for (int i = 1; i <= n; i++)cout << top[i] << " "; cout << endl;
//	//for (int i = 1; i <= n; i++)cout << dfn[i] << " "; cout << endl;
//	//for (int i = 1; i <= n; i++)cout << queryMax(dfn[i],dfn[i],1,n,1) << " "; cout << endl;
//	//for (int i = 1; i <= n; i++)cout << queryMin(dfn[i], dfn[i], 1, n, 1) << " "; cout << endl;
//	//for (int i = 1; i <= n; i++)cout << queryBestlr(dfn[i], dfn[i], 1, n, 1) << " "; cout << endl;
//	//for (int i = 1; i <= n; i++)cout << queryBestrl(dfn[i], dfn[i], 1, n, 1) << " "; cout << endl;
//	cin >> q;
//	for (int i = 1, a, b, v; i <= q; i++) {
//		//cout << queryBestlr(dfn[2], dfn[4], 1, n, 1) <<"-------------------------------------------"<< endl;
//		//cout << queryBestrl(dfn[2], dfn[4], 1, n, 1) << "-------------------------------------------" << endl;
//		cin >> a >> b >> v;
//		cout << queryProfit(a, b)<<endl;
//		add(a,b,v);
//		//for (int i = 1; i <= n; i++)cout << queryMax(dfn[i], dfn[i], 1, n, 1) << " "; cout << endl;
//		//for (int i = 1; i <= n; i++)cout << queryMin(dfn[i], dfn[i], 1, n, 1) << " "; cout << endl;
//	}
//}


//遥远的国度
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1e5 + 10;
//int n, m,root;
//int nex[MAXN << 1];
//int to[MAXN << 1];
//int head[MAXN];
//int cntg = 1;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//
//int val[MAXN];
//int fa[MAXN];
//int son[MAXN];
//int siz[MAXN];
//int dep[MAXN];
//int top[MAXN];
//int dfn[MAXN];
//int seg[MAXN];
//int cntd = 0;
//void dfs1(int u, int pa) {
//	fa[u] = pa;
//	siz[u] = 1;
//	dep[u] = dep[pa] + 1;
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == pa)continue;
//		dfs1(to[e], u);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == pa)continue;
//		if (son[u] == 0 || siz[son[u]] < siz[to[e]]) {
//			son[u] = to[e];
//		}
//		siz[u] += siz[to[e]];
//	}
//}
//void dfs2(int u, int t) {
//	top[u] = t;
//	dfn[u] = ++cntd;
//	seg[cntd] = u;
//	if (son[u] != 0) {
//		dfs2(son[u], t);
//	}
//	for (int e = head[u]; e != 0; e = nex[e]) {
//		if (to[e] == fa[u] || to[e] == son[u])continue;
//		dfs2(to[e], to[e]);
//	}
//}
//
//int upd[MAXN << 2];
//int Min[MAXN << 2];
//void lazy(int i,int v) {
//	Min[i] = v;
//	upd[i] = v;
//}
//void up(int i) {
//	Min[i] = min(Min[i << 1], Min[i << 1 | 1]);
//}
//void down(int i) {
//	if (upd[i] != -1) {
//		lazy(i << 1, upd[i]);
//		lazy(i << 1 | 1, upd[i]);
//		upd[i] = -1;
//	}
//}
//void update(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v);
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i);
//		if (jl <= mid) {
//			update(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			update(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//int queryMin(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return Min[i];
//	}
//	else {
//		int ans = INT_MAX;
//		int mid = l + r >> 1;
//		down(i);
//		if (jl <= mid) {
//			ans = min(ans, queryMin(jl, jr, l, mid, i << 1));
//		}
//		if (jr > mid) {
//			ans = min(ans, queryMin(jl, jr, mid + 1, r, i << 1 | 1));
//		}
//		return ans;
//	}
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		Min[i] = val[seg[l]];
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	upd[i] = -1;
//}
//void update(int u, int v,int w) {
//	while (top[u] != top[v]) {
//		if (dep[top[u]] <= dep[top[v]]) {
//			update(dfn[top[v]], dfn[v], w, 1, n, 1);
//			v = fa[top[v]];
//		}
//		else {
//			update(dfn[top[u]], dfn[u], w, 1, n, 1);
//			u = fa[top[u]];
//		}
//	}
//	update(min(dfn[u], dfn[v]), max(dfn[u], dfn[v]),w,1,n,1);
//}
////int queryMin(int id) {
////	if (root == id) {
////		return queryMin(1, n, 1, n, 1);
////	}
////	if (dfn[root]<dfn[id] || dfn[root]>dfn[id] + siz[id] - 1) {
////		return queryMin(dfn[id], dfn[id] + siz[id] - 1, 1, n, 1);
////	}
////	int p=root;
////	if (top[p] == top[id])p = son[id];
////	else {
////		while (top[fa[top[p]]] != top[id]) {
////			p = fa[top[p]];
////		}
////		if (fa[top[p]] == id) {
////			p = top[p];
////		}
////		else {
////			p = son[id];
////		}
////	}
////	return min(queryMin(dfn[id], dfn[p] - 1, 1, n, 1), queryMin(dfn[p] + siz[p], dfn[id] + siz[id] - 1, 1, n, 1));
////}
//int queryMin(int id) {
//	if (root == id) {
//		return Min[1];
//	}
//	if (dfn[root] < dfn[id] || dfn[root] >= dfn[id] + siz[id]) {
//		return queryMin(dfn[id], dfn[id] + siz[id] - 1, 1, n, 1);
//	}
//	int p = root;
//	while (top[p] != top[id]) {
//		if (fa[top[p]] == id) {
//			p = top[p];
//			break;
//		}
//		p = fa[top[p]];
//	}
//	if (top[p] == top[id] && p != id) {
//		p = son[id];
//	}
//	int ans = INT_MAX;
//	if (1 <= dfn[p] - 1) {
//		ans = min(ans, queryMin(1, dfn[p] - 1, 1, n, 1));
//	}
//	if (dfn[p] + siz[p] <= n) {
//		ans = min(ans, queryMin(dfn[p] + siz[p], n, 1, n, 1));//注意右侧是n不是dfn[id]+siz[id]-1,因为要算整个树
//	}
//	return ans;
//}
//int main() {
//	cin >> n>>m;
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs1(1, 0);
//	dfs2(1, 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> val[i];
//	}
//	cin >> root;
//	build(1, n, 1);
//	for (int i = 1, opt; i <= m; i++) {
//		cin >> opt;
//		if (opt == 1) {
//			int id;
//			cin >> id;
//			root = id;
//		}
//		else if (opt == 2) {
//			int x, y, v;
//			cin >> x >> y >> v;
//			update(x, y, v);
//		}
//		else {
//			int id;
//			cin >> id;
//			cout << queryMin(id)<<endl;
//		}
//	}
//}