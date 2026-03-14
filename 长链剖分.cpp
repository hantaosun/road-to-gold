//#include<bits/stdc++.h>
//#define uii unsigned int
//using namespace std;
//const int N = 5e5 + 5;
//int n, q;
//uii s;
//int head[N];
//int nex[N];
//int to[N];
//int cnt = 1;
//int rt = 0;
//int high[N];
////³¤Á´ÆÊ·Ö
//int son[N];
//int top[N];
//int up[N];
//int down[N];
//int dfn[N];
//int dep[N];
//int len[N];
//int st[N][23];
//int cntdfn = 0;
//void dfs1(int u, int fa) {
//	dep[u] = dep[fa] + 1;
//	st[u][0] = fa;
//	for (int p = 1; p < 23; p++) {
//		st[u][p] = st[st[u][p - 1]][p - 1];
//	}
//	for (int ui = head[u]; ui != 0; ui = nex[ui]){
//		dfs1(to[ui], u);
//		if (son[u]==0||len[to[ui]] > len[son[u]]) {
//			son[u] = to[ui];
//		}
//	}
//	len[u] = len[son[u]] + 1;
//}
//void dfs2(int u, int tp) {
//	top[u] = tp;
//	dfn[u] = ++cntdfn;
//	if (son[u] == 0)return;
//	dfs2(son[u], tp);
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] != son[u])dfs2(to[ui], to[ui]);
//	}
//}
//void setup(int u, int i, int v) {
//	up[dfn[u] + i] = v;
//}
//void setdown(int u, int i, int v) {
//	down[dfn[u] + i] = v;
//}
//void prepare() {
//	dfs1(rt, 0);
//	dfs2(rt, rt);
//	high[0] = -1;
//	for (int i = 1; i <= n; i++) {
//		high[i] = high[i >> 1] + 1;
//	}
//	for (int u = 1; u <= n; u++) {
//		if (top[u] == u) {
//			for (int i = 0, a = u, b = u; i < len[u]; i++, a = st[a][0], b = son[b]) {
//				setup(u, i, a);
//				setdown(u, i, b);
//			}
//		}
//	}
//}
//inline uii get(uii x) {
//	x ^= x << 13;
//	x ^= x >> 17;
//	x ^= x << 5;
//	return s = x;
//}
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
//int getUp(int x, int i) {
//	return up[dfn[x] + i];
//}
//int getDown(int u, int i) {
//	return down[dfn[u] + i];
//}
//int query(int x, int k) {
//	if (k == 0) {
//		return x;
//	}
//	if (k == (1 << high[k])) {
//		return st[x][high[k]];
//	}
//	x = st[x][high[k]];
//	k -= (1 << high[k]);
//	k -= dep[x] - dep[top[x]];
//	x = top[x];
//	return (k >= 0) ? getUp(x, k) : getDown(x, -k);
//}
//int main() {
//	cin >> n >> q >> s;
//	for (int i = 1,father; i <= n; i++) {
//		cin >> father;
//		if (father == 0) {
//			rt = i;
//		}
//		else {
//			addEdge(father, i);
//		}
//	}
//	prepare();
//	long long ans = 0;
//	for (int i = 1, x, k, lastAns = 0; i <= q; i++) {
//		x = ((get(s) ^ lastAns) % n) + 1;
//		k = (get(s) ^ lastAns) % dep[x];
//		lastAns = query(x, k);
//		ans ^= (long long)i * lastAns;
//	}
//	cout << ans << '\n';
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//int head[N], to[N<<1], nex[N<<1], cnt = 1;
//void addEdge(int u, int v) { nex[cnt] = head[u]; to[cnt] = v; head[u] = cnt++; }
//int dp[N];
//int dfn[N];
//int dep[N];
//int len[N];
//int son[N];
//int ans[N];
//int cntdfn = 0;
//int getdp(int u, int i) {
//	return dp[dfn[u] + i];
//}
//void setdp(int u, int i, int v) {
//	dp[dfn[u] + i] = v;
//}
//void dfs1(int u, int fa) {
//	dep[u] = dep[fa] + 1;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		dfs1(to[ui], u);
//		if (son[u] == 0 || len[to[ui]] > len[son[u]]) {
//			son[u] = to[ui];
//		}
//	}
//	len[u] = len[son[u]] + 1;
//}
//void dfs2(int u, int fa) {
//	dfn[u] = ++cntdfn;
//	setdp(u, 0, 1);
//	ans[u] = 0;
//	if (son[u] == 0) {
//		return;
//	}
//	dfs2(son[u], u);
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == son[u] || to[ui] == fa)continue;
//		dfs2(to[ui], u);
//	}
//	ans[u] = ans[son[u]] + 1;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa || to[ui] == son[u])continue;
//		for (int i = 1; i <= len[to[ui]]; i++) {
//			setdp(u, i, getdp(u, i) + getdp(to[ui], i - 1));
//			if (getdp(u, i) > getdp(u, ans[u])|| getdp(u, i) == getdp(u, ans[u])&&i<ans[u]) {
//				ans[u] = i;
//			}
//		}
//	}
//	if (getdp(u, ans[u]) == 1)ans[u] = 0;
//}
//int n;
//int main() {
//	cin >> n;
//	for (int i = 1,u,v; i <n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs1(1, 0);
//	dfs2(1, 0);
//	for (int i = 1; i <= n; i++) {
//		cout << ans[i] << "\n";
//	}
//}


