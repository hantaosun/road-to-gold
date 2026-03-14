//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e4 + 5;
//vector<array<int,2>>query;
//int head[N];
//int to[N << 1];
//int nex[N << 1];
//int len[N << 1];
//bool del[N];
//int siz[N];
//int dis[N];
//int cnt = 1;
//int tsiz;//当前找重心的连通块的总点数
//int rt;//一个当前在分治的根，设为全局变量较方便
//set<int>st;
//void addEdge(int u, int v,int w) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	len[cnt] = w;
//	head[u] = cnt++;
//}
//void dfs(int u, int fa) {
//	siz[u] = 1;
//	for (auto&v : query) {
//		if (st.count(v[0] - dis[u]))v[1] = true;
//	}
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) if (!del[to[ui]] && to[ui] != fa) {
//		dis[to[ui]] = dis[u] + len[ui];
//		dfs(to[ui], u);
//		siz[u] += siz[to[ui]];
//	}
//}
//void dfs1(int u, int fa) {
//	st.insert(dis[u]);
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) if (!del[to[ui]] && to[ui] != fa) {
//		dfs1(to[ui], u);
//	}
//}
//void getRt(int u,int fa) {
//	int mxsiz=0;
//	siz[u] = 1;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) if(!del[to[ui]]&&to[ui]!=fa) {
//		getRt(to[ui], u);
//		mxsiz = max(mxsiz, siz[to[ui]]);
//		siz[u] += siz[to[ui]];
//	}
//	mxsiz = max(tsiz - siz[u],mxsiz);
//	if (mxsiz * 2 <= tsiz)rt = u;
//}
//void cal(int u) {//计算过点u路径的
//	st.clear();
//	st.insert(0);
//	dis[u] = 0;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (del[to[ui]])continue;
//		dis[to[ui]] = len[ui];
//		dfs(to[ui], u);
//		dfs1(to[ui], u);
//	}
//}
//void divide(int u) {
//	del[u] = true;
//	cal(u);
//	for (int ui = head[u]; ui != 0; ui = nex[ui])if(!del[to[ui]]) {
//		rt = -1;
//		tsiz = siz[to[ui]];
//		getRt(to[ui],u);
//		divide(rt);
//	}
//}
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1,u,v,w; i < n; i++){
//		cin >> u >> v >> w;
//		addEdge(u, v, w);
//		addEdge(v, u, w);
//	}
//	for (int i = 1,k; i <= m; i++) {
//		cin >> k;
//		query.push_back({ k,0 });
//	}
//	rt = -1;
//	tsiz = n;
//	getRt(1,0);
//	divide(rt);
//	for (auto v : query) {
//		if (v[1]) {
//			cout << "AYE\n";
//		}
//		else {
//			cout << "NAY\n";
//		}
//	}
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 5;
//int head[N];
//int nex[N<<1];
//int to[N<<1];
//int cntg = 1;
//int ans[N];
//int cnt[N];
//bool del[N];
//int siz[N];
//int c[N];
//int ap[N];
//int sum = 0;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//int rt;
//int mnsiz;
//int n,mxc,tsiz;
//void getRt(int u,int fa) {
//	int mxsiz = 0;
//	siz[u] = 1;
//	for (int ui = head[u]; ui != 0; ui = nex[ui])if(!del[to[ui]]&&to[ui]!=fa) {
//		getRt(to[ui], u);
//		siz[u] += siz[to[ui]];
//		mxsiz = max(mxsiz, siz[to[ui]]);
//	}
//	mxsiz = max(mxsiz, tsiz - siz[u]);
//	if (mxsiz < mnsiz) {
//		rt = u;
//		mnsiz = mxsiz;
//	}
//}
//void dfs(int u,int fa,int kinds) {//计算  sum是其它子树上不包含当前rt到该节点路径上颜色的其它颜色的路径条数
//	if (!ap[c[u]]) {
//		sum -= cnt[c[u]];//防止算重
//		kinds++;
//	}
//	ap[c[u]]++;
//	siz[u] = 1;
//	ans[u] += sum + kinds * siz[rt];//siz[rt]是之前的子树的大小及根节点总和
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa || del[to[ui]])continue;
//		dfs(to[ui], u, kinds);
//		siz[u] += siz[to[ui]];
//	}
//	if (--ap[c[u]] == 0) {
//		sum += cnt[c[u]];
//	}
//}
//void dfs1(int u,int fa) {//收集
//	if (!ap[c[u]]) {
//		cnt[c[u]] += siz[u];
//		sum += siz[u];
//	}
//	ap[c[u]]++;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa || del[to[ui]])continue;
//		dfs1(to[ui], u);
//	}
//	ap[c[u]]--;
//}
//void clear(int u,int fa) {
//	cnt[c[u]] = 0;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (del[to[ui]] || to[ui] == fa)continue;
//		clear(to[ui], u);
//	}
//}
//void clear1(int u, int fa,int now) {//更新好根节点的答案并清空
//	if (!ap[c[u]])now++;
//	ap[c[u]]++;
//	ans[u] -= now;//因为正序和逆序时rt的颜色会被重复计数
//	ans[rt] += now;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (del[to[ui]] || to[ui] == fa)continue;
//		clear1(to[ui], u, now);
//	}
//	ap[c[u]]--;
//	cnt[c[u]] = 0;
//}
//void cal(int u) {
//	ans[u]++;//自己到自己
//	ap[c[u]]++;
//	cnt[c[u]]=1;
//	siz[u] = 1;
//	sum = 1;
//	vector<int>tmp;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (del[to[ui]])continue;
//		tmp.push_back(to[ui]);
//	}
//	for (int i = 0; i < tmp.size();i++) {
//		dfs(tmp[i], u, 0);
//		dfs1(tmp[i], u);
//		siz[u] += siz[tmp[i]];
//		cnt[c[u]] += siz[tmp[i]];
//		sum += siz[tmp[i]];
//	}
//	clear(u,0);
//	sum = 1;
//	siz[u] = 1;
//	cnt[c[u]] = 1;
//	for (int i = tmp.size() - 1; i >= 0; i--) {
//		dfs(tmp[i], u, 0);
//		dfs1(tmp[i], u);
//		siz[u] += siz[tmp[i]];
//		cnt[c[u]] += siz[tmp[i]];
//		sum += siz[tmp[i]];
//	}
//	ap[c[u]]--;
//	clear1(u, 0, 0);
//}
//void divide(int u) {
//	del[u] = true;
//	cal(u);
//	for (int ui = head[u]; ui != 0; ui = nex[ui])if(!del[to[ui]]) {
//		rt = -1;
//		mnsiz = INT_MAX;
//		tsiz = siz[to[ui]];
//		getRt(to[ui], u);
//		divide(rt);
//	}
//}
//signed main() {
//	mxc = -1;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> c[i];
//		mxc = max(mxc, c[i]);
//	}
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	mnsiz = INT_MAX;
//	rt = -1;
//	tsiz = n;
//	getRt(1, 0);
//	divide(rt);
//	for (int i = 1; i <= n; i++) {
//		cout << ans[i] << "\n";
//	}
//}