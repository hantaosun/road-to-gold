//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5+5;
//const int T = N * 37;
//int n, m;
//vector<int>a;
//int sum[N << 2];
//int root[N];
//int lson[T];
//int rson[T];
//int pos[N];
//int cnt = 0;
//int build(int l, int r) {
//	int rt = ++cnt;
//	sum[rt] = 0;
//	if (l < r) {
//		int mid = l + r >> 1;
//		lson[rt] = build(l, mid);
//		rson[rt] = build(mid + 1, r);
//	}
//	return rt;
//}
//int copy(int x) {
//	int rt = ++cnt;
//	lson[rt] = lson[x];
//	rson[rt] = rson[x];
//	sum[rt] = sum[x];
//	return rt;
//}
//int upd(int x, int v, int l, int r, int i) {
//	int rt = copy(i);
//	sum[rt] += v;//这题不用用up函数
//	if (l == r) {
//		return rt;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		lson[rt] = upd(x, v, l, mid, lson[i]);
//	}
//	else {
//		rson[rt] = upd(x, v, mid + 1, r, rson[i]);
//	}
//	return rt;
//}
//int qrySiz(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int ans = 0;
//	int mid = l + r >> 1;
//	if (jl <= mid) {
//		ans += qrySiz(jl, jr, l, mid, lson[i]);
//	}
//	if (jr > mid) {
//		ans += qrySiz(jl, jr, mid + 1, r, rson[i]);
//	}
//	return ans;
//
//}
//int qryKth(int k, int l, int r, int i) {
//	if (l == r) {
//		return l;
//	}
//	int mid = l + r >> 1;
//	int lsiz = sum[lson[i]];
//	if (lsiz >= k) {
//		return qryKth(k, l, mid, lson[i]);
//	}
//	else {
//		return qryKth(k - lsiz, mid + 1, r, rson[i]);
//	}
//}
//void prepare() {
//	cnt = 0;
//	memset(pos, 0, sizeof(pos));
//	root[n + 1] = build(1, n);
//	for (int i = n; i >= 1; i--) {
//		if (pos[a[i]] == 0) {
//			root[i] = upd(i, 1, 1, n, root[i + 1]);
//		}
//		else {
//			root[i] = upd(pos[a[i]], -1, 1, n, root[i + 1]);
//			root[i] = upd(i, 1, 1, n, root[i]);
//		}
//		pos[a[i]] = i;
//	}
//}
//void solve(int t) {
//	cin >> n >> m;
//	a.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	prepare();
//	cout << "Case #" << t << ":";
//	for (int i = 1, aa, bb, l, r, k, lastAns = 0; i <= m; i++) {
//		cin >> aa>>bb;
//		aa = (aa + lastAns) % n + 1;
//		bb = (bb + lastAns) % n + 1;
//		l = min(aa, bb);
//		r = max(aa, bb);
//		k = (qrySiz(l, r, 1, n, root[l]) + 1) / 2;
//		lastAns = qryKth(k, 1, n, root[l]);
//		cout << " " << lastAns;
//	}
//	cout << "\n";
//}
//int main() {
//	cin.tie(nullptr)->sync_with_stdio(false);
//	int t;
//	cin >> t;
//	for (int i = 1; i <= t; i++) {
//		solve(i);
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//const int T = N * 37;
//int n, m;
//int a[N];
////当前数字范围上每个数字在数组上出现的最晚位置中最左侧的位置,若有数字没有出现就为0
//int info[T];
//int lson[T];
//int rson[T];
//int rt[N];
//int cnt = 0;
//void up(int x) {
//	info[x] = min(info[lson[x]], info[rson[x]]);
//}
//int build(int l, int r) {
//	int rt = ++cnt;
//	if (l == r) {
//		info[rt] = 0;
//		return rt;
//	}
//	int mid = l + r >> 1;
//	lson[rt] = build(l, mid);
//	rson[rt] = build(mid + 1, r);
//	return rt;
//}
//int copy(int x) {
//	int rt = ++cnt;
//	lson[rt] = lson[x];
//	rson[rt] = rson[x];
//	info[rt] = info[x];
//	return rt;
//}
//int upd(int x, int v,int l, int r, int i) {
//	int rt = copy(i);
//	if (l == r) {
//		info[rt] = v;
//		return rt;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		lson[rt] = upd(x, v, l, mid, lson[i]);
//	}
//	else {
//		rson[rt] = upd(x, v, mid + 1, r, rson[i]);
//	}
//	up(rt);
//	return rt;
//}
//
//int query(int p,int l,int r,int i) {
//	if (l == r) {
//		return l;
//	}
//	int mid = l + r >> 1;
//	if (info[lson[i]] >= p) {
//		return query(p, mid + 1, r, rson[i]);
//	}
//	else {
//		return query(p, l, mid, lson[i]);
//	}
//}
//int main() {
//	cin >> n >> m;
//	int nn = 2e5;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	rt[0] = build(0, nn);
//	for (int i = 1; i <= n; i++) {
//		rt[i] = upd(a[i], i, 0, nn, rt[i - 1]);
//	}
//	for (int i = 1,l,r; i <= m; i++) {
//		cin >> l >> r;
//		cout << query(l,0,nn,rt[r]) << "\n";
//	}
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2e4 + 5;
//const int T = N * 20;
//vector<array<int,2>>a;
//int sum[T];
//int pre[T];
//int suf[T];
//int lson[T];
//int rson[T];
//int root[N];
//int cnt = 0;
//int n;
//int copy(int x) {
//	int rt = ++cnt;
//	lson[rt] = lson[x];
//	rson[rt] = rson[x];
//	sum[rt] = sum[x];
//	pre[rt] = pre[x];
//	suf[rt] = suf[x];
//	return rt;
//}
//void up(int x) {
//	sum[x] = sum[lson[x]] + sum[rson[x]];
//	pre[x] = max(pre[lson[x]], sum[lson[x]] + pre[rson[x]]);
//	suf[x] = max(suf[rson[x]], sum[rson[x]] + suf[lson[x]]);
//}
//int build(int l, int r) {
//	int rt = ++cnt;
//	if (l == r) {
//		pre[rt] = 1;
//		suf[rt] = 1;
//		sum[rt] = 1;
//		return rt;
//	}
//	int mid = l + r >> 1;
//	lson[rt] = build(l, mid);
//	rson[rt] = build(mid + 1, r);
//	up(rt);
//	return rt;
//}
//int upd(int x,int v,int l,int r,int i) {
//	int rt = copy(i);
//	if (l == r) {
//		sum[rt] =pre[rt]=suf[rt]=v;
//		return rt;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		lson[rt] = upd(x, v, l, mid, lson[rt]);
//	}
//	else {
//		rson[rt] = upd(x, v, mid + 1, r, rson[rt]);
//	}
//	up(rt);
//	return rt;
//}
//int querySum(int jl, int jr, int l, int r, int i) {
//	if (l > r)return 0;
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int ans = 0;
//	int mid = l + r >> 1;
//	if (jl <= mid) {
//		ans += querySum(jl, jr, l, mid, lson[i]);
//	}
//	if (jr > mid) {
//		ans += querySum(jl, jr, mid + 1, r, rson[i]);
//	}
//	return ans;
//}
//array<int, 3> queryInfo(int jl,int jr,int l,int r,int i) {
//	if (l > r) {
//		return { LLONG_MIN,LLONG_MIN,0 };
//	}
//	if (jl<=l&&jr>=r) {
//		return { pre[i],suf[i],sum[i] };
//	}
//	int mid = l + r >> 1;
//	if (jr <= mid) {
//		return queryInfo(jl, jr, l, mid, lson[i]);
//	}
//	else if (jl > mid) {
//		return queryInfo(jl, jr, mid + 1, r, rson[i]);
//	}
//	else {
//		array<int, 3>linfo = queryInfo(jl, jr, l, mid, lson[i]);
//		array<int, 3>rinfo = queryInfo(jl, jr, mid + 1, r, rson[i]);
//		return { max(linfo[0],linfo[2] + rinfo[0]),max(rinfo[1],rinfo[2] + linfo[1]),linfo[2] + rinfo[2] };
//	}
//}
//int bs(int l1,int r1,int l2,int r2) {
//	//cout << l1 << " " << r1 << " " << l2 << " " << r2 << "&\n";
//	int l = 1, r = n,mid,ans=-1;
//	while (l <= r) {
//		int mid = l + r >> 1;
//		//cout << mid << " " << querySum(r1 + 1, l2 - 1, 1, n, root[mid]) << " " << queryInfo(l1, r1, 1, n, root[mid])[1] << " " << queryInfo(l2, r2, 1, n, root[mid])[0] << "***\n";
//		if (querySum(r1 + 1, l2 - 1, 1, n, root[mid]) + queryInfo(l1,r1, 1, n, root[mid])[1] + queryInfo(l2,r2, 1, n, root[mid])[0] >= 0) {
//			ans = a[mid][0];
//			l = mid + 1;
//		}
//		else {
//			r = mid - 1;
//		}
//	}
//	return ans;
//}
//void debug1(int l, int r, int i) {
//	cout << "(" << l << "," << r << ","<<pre[i]<<","<<suf[i]<<","<<sum[i]<<")" << "*\n";
//	if (l == r) {
//		return;
//	}
//	int mid = l + r >> 1;
//	debug1(l, mid, lson[i]);
//	debug1(mid+1, r, rson[i]);
//}
//void debug(int l, int r, int i) {
//	if (l == r) {
//		cout << "(" << pre[i] << "," << suf[i] << "," << sum[i] << ")" << " ";
//		if (l == n)cout << "\n";
//		return;
//	}
//	int mid = l + r >> 1;
//	debug(l, mid, lson[i]);
//	debug(mid+1, r, rson[i]);
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n;
//	a.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i][0];
//		a[i][1] = i;
//	}
//	sort(a.begin(), a.end(), [&](auto x,auto y) {
//		return x[0] < y[0];
//		});
//	root[1] = build(1, n);
//	for (int i = 2; i <= n; i++) {
//		root[i] = upd(a[i-1][1], -1, 1, n, root[i - 1]);
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	debug(1, n, root[i]);
//	//	debug1(1, n, root[i]);
//	//}
//	//cout << "---------\n";
//	//cout << queryInfo(1, 2, 1, n, root[3])[0] << "%%%\n";
//	//debug1(1, n, root[3]);
//	array<int, 4>tmp;
//	int q;
//	cin >> q;
//	for (int i = 1,lastAns=0; i <= q; i++) {
//		cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
//		tmp[0] = (tmp[0] + lastAns) % n;
//		tmp[1] = (tmp[1] + lastAns) % n;
//		tmp[2] = (tmp[2] + lastAns) % n;
//		tmp[3] = (tmp[3] + lastAns) % n;
//		sort(tmp.begin(), tmp.end());
//		int a = tmp[0]+1, b = tmp[1]+1, c = tmp[2]+1, d = tmp[3]+1;
//		lastAns = bs(a,b,c,d);
//		cout << lastAns<<"\n";
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 5;
//const int T = N * 100;
//int w[N];
//int head[N];
//int to[N << 1];
//int nex[N << 1];
//int root[N];
//int cnt = 0;
//int cntg=1;
//int sum[T];
//int lson[T];
//int rson[T];
//int dep[N];
//int st[N][23];
//vector<int>vsort;
//int n, m;
//int nn;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//int copy(int x) {
//	int rt = ++cnt;
//	lson[rt] = lson[x];
//	rson[rt] = rson[x];
//	sum[rt] = sum[x];
//	return rt;
//}
//void up(int i) {
//	sum[i] = sum[lson[i]] + sum[rson[i]];
//}
//int build(int l, int r) {
//	int rt = ++cnt;
//	sum[rt] = 0;
//	if (l == r) {
//		return rt;
//	}
//	int mid = l + r >> 1;
//	lson[rt] = build(l, mid);
//	rson[rt] = build(mid + 1, r);
//	return rt;
//}
//int add(int x, int v, int l, int r, int i) {
//	int rt = copy(i);
//	if (l == r) {
//		sum[rt] += v;
//		return rt;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		lson[rt] = add(x, v, l, mid, lson[rt]);
//	}
//	else {
//		rson[rt] = add(x, v, mid + 1, r, rson[rt]);
//	}
//	up(rt);
//	return rt;
//}
//int lca(int u, int v){
//	if (dep[u] < dep[v])swap(u, v);
//	for (int p = 22; p >= 0; p--) {
//		if (dep[st[u][p]] >= dep[v]) {
//			u = st[u][p];
//		}
//	}
//	if (u == v)return u;
//	for (int p = 22; p >= 0; p--) {
//		if (st[u][p] != st[v][p])u=st[u][p],v=st[v][p];
//	}
//	u = st[u][0];
//	return u;
//}
//void dfs(int u, int fa) {
//	dep[u] = dep[fa] + 1;
//	st[u][0] = fa;
//	for (int p = 1; p < 23; p++) {
//		st[u][p] = st[st[u][p - 1]][p - 1];
//	}
//	root[u] = add(w[u], 1, 1, nn, root[fa]);
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		dfs(to[ui],u);
//	}
//}
//int kth(int k,int l, int r, int u, int v, int uv,int valuv) {
//	if (l == r) {
//		return l;
//	}
//	int lval = sum[lson[u]] + sum[lson[v]] - 2 * sum[lson[uv]];
//	int mid = l + r >> 1;
//	if (valuv <= mid&&valuv>=l)lval++;
//	if (lval >= k) {
//		return kth(k, l, mid, lson[u], lson[v], lson[uv],valuv);
//	}
//	else {
//		return kth(k - lval, mid + 1, r, rson[u], rson[v], rson[uv],valuv);
//	}
//}
//int work(int u, int v, int k) {
//	int uv = lca(u, v);
//	int tmp = kth(k, 1, nn, root[u], root[v], root[uv],w[uv]);
//	return vsort[tmp-1];
//}
//void debug(int l,int r,int i) {
//	if (l == r) {
//		cout << "("<< l << ',' << sum[i] << ')' << " ";
//		if (l == nn)cout << "\n";
//		return;
//	}
//	int mid = l + r >> 1;
//	debug(l, mid, lson[i]);
//	debug(mid + 1, r, rson[i]);
//}
//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> w[i];
//		vsort.push_back(w[i]);
//	}
//	sort(vsort.begin(), vsort.end());
//	vsort.erase(unique(vsort.begin(), vsort.end()), vsort.end());
//	for (int i = 1; i <= n; i++) {
//		w[i] = lower_bound(vsort.begin(), vsort.end(), w[i]) - vsort.begin() + 1;
//	}
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	nn = vsort.size();
//	root[0] = build(1, nn);
//	dep[0] = 0;
//	dfs(1, 0);
//	//for (int i = 1; i <= n; i++) {
//	//	cout << i << ":\n";
//	//	debug(1,nn,root[i]);
//	//}
//	for (int i = 1,u,v,k,lastAns=0; i <= m; i++) {
//		cin >> u >> v >> k;
//		u = u ^ lastAns;
//		lastAns = work(u, v, k);
//		cout << lastAns << "\n";
//	}
//}


//可持久化常用于时序关系，用dfn序可维护子树关系
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 3e5 + 5;
//const int T = N * 20;
//int head[N];
//int to[N<<1];
//int nex[N<<1];
//int cntg = 1;
//int dfn[N];
//int lson[T];
//int rson[T];
//int sum[T];
//int root[T];
//int dep[N];
//int siz[N];
//int mxdep = 0;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//int cntdfn = 0;
//
//int cnt = 0;
//void up(int x) {
//	sum[x] = sum[lson[x]] + sum[rson[x]];
//}
//int copy(int x) {
//	int rt = ++cnt;
//	lson[rt] = lson[x];
//	rson[rt] = rson[x];
//	sum[rt] = sum[x];
//	return rt;
//}
//int build(int l, int r) {
//	int rt = ++cnt;
//	sum[rt] = 0;
//	if (l == r) {
//		return rt;
//	}
//	int mid = l + r >> 1;
//	lson[rt] = build(l, mid);
//	rson[rt] = build(mid + 1, r);
//	return rt;
//}
//int add(int x, int val, int l, int r, int i) {
//	//cout << x << " " << l << " " << r << " " << i << "**\n";
//	int rt = copy(i);
//	if (l == r) {
//		sum[rt] += val;
//		return rt;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		lson[rt] = add(x, val, l, mid, lson[rt]);
//	}
//	else {
//		rson[rt] = add(x, val, mid + 1, r, rson[rt]);
//	}
//	up(rt);
//	return rt;
//}
//int query(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r)return sum[i];
//	int ans = 0;
//	int mid = l + r >> 1;
//	if (jl <= mid) {
//		ans += query(jl, jr, l, mid, lson[i]);
//	}
//	if (jr > mid) {
//		ans += query(jl, jr, mid + 1, r, rson[i]);
//	}
//	return ans;
//}
//void debug(int l, int r, int i);
//void dfs(int u, int fa) {
//	dfn[u] = ++cntdfn;
//	dep[u] = dep[fa] + 1;
//	//cout << dep[u] << "^^\n";
//	root[dfn[u]] = add(dep[u], siz[u] - 1, 1, mxdep, root[dfn[u] - 1]);
//	//cout << u << " "<<dep[u]<<"*\n";
//	//debug(1, mxdep, root[dfn[u]]);
//	for (int ui = head[u]; ui != 0; ui = nex[ui])if (to[ui] != fa) {
//		dfs(to[ui], u);
//	}
//}
//void getMaxDep(int u, int fa,int dep) {
//	siz[u] = 1;
//	mxdep = max(mxdep, dep);
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		getMaxDep(to[ui], u, dep + 1);
//		siz[u] += siz[to[ui]];
//	}
//}
//int querySum(int jl, int jr, int l,int r,int rt1, int rt2) {
//	//cout << l << " " << r << '\n';
//	if (jl <= l && jr >= r) {
//		return sum[rt2] - sum[rt1];
//	}
//	int ans = 0;
//	int mid = l + r >> 1;
//	if (jl <= mid) {
//		ans += querySum(jl, jr, l, mid, lson[rt1], lson[rt2]);
//	}
//	if (jr > mid) {
//		ans += querySum(jl, jr, mid + 1, r, rson[rt1], rson[rt2]);
//	}
//	return ans;
//}
//int work(int p, int k) {
//	int ans = min(dep[p] - 1, k) * (siz[p] - 1);
//	int rt1 = dfn[p] - 1;
//	int rt2 = dfn[p] + siz[p] - 1;
//	//debug(1, mxdep, root[rt1]);
//	//debug(1, mxdep, root[rt2]);
//	//cout << ans << "**\n";
//	//cout << dep[p] + 1 << "  " << min(dep[p] + k, mxdep) << "\n";
//	ans += querySum(dep[p]+1, min(dep[p] + k, mxdep), 1, mxdep, root[rt1], root[rt2]);
//	return ans;
//}
//
//void debug(int l, int r, int i) {
//	if (l == r) {
//		cout << "(" << l << "," << sum[i] << ")" << " ";
//		if(l==mxdep)cout<<'\n';
//		return;
//	}
//	int mid = l + r >> 1;
//	debug(l, mid, lson[i]);
//	debug(mid + 1, r, rson[i]);
//}
//int n, q;
//signed main() {
//	cin >> n >> q;
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	getMaxDep(1, 0,1);
//	root[0] = build(1,mxdep);
//	dfs(1, 0);
//	for (int i = 1,p,k; i <= q; i++) {
//		cin >> p >> k;
//		cout << work(p, k) << "\n";
//	}
//}