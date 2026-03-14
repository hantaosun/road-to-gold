//#include<bits/stdc++.h>
//using namespace std;
//const int N = 6e5 + 10;
//const int BIT = 25;
//int n, m;
//int a[N];
//int pass[N*22];
//int tree[N * 22][2];
//int root[N];
//int cnt = 0;
//int insert(int num, int i) {//插入num并返回新头部
//	int rt = ++cnt;
//	tree[rt][0] = tree[i][0];
//	tree[rt][1] = tree[i][1];
//	pass[rt] = pass[i] + 1;
//	for (int b = BIT, path, pre = rt, cur; b >= 0; b--, pre = cur) {
//		path= (num>> b) & 1;
//		i = tree[i][path];
//		cur = ++cnt;
//		tree[cur][0] = tree[i][0];
//		tree[cur][1] = tree[i][1];
//		pass[cur] = pass[i] + 1;
//		tree[pre][path] = cur;
//	}
//	return rt;
//}
//int query(int num, int u, int v) {
//	int ans = 0;
//	for (int b = BIT, path, best; b >= 0; b--) {
//		path = (num >> b) & 1;
//		best = path ^ 1;
//		if (pass[tree[v][best]] > pass[tree[u][best]]) {
//			ans += 1 << b;
//			u = tree[u][best];
//			v = tree[v][best];
//		}
//		else {
//			u = tree[u][path];
//			v = tree[v][path];
//		}
//	}
//	return ans;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n >> m;
//	int eor = 0;
//	root[0] = insert(eor, 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		eor ^= a[i];
//		root[i] = insert(eor, root[i - 1]);
//	}
//	char op;
//	for (int i = 1,l,r,x; i <= m; i++) {
//		cin >> op;
//		if (op == 'A') {
//			cin >> x;
//			a[++n] = x;
//			eor ^= x;
//			root[n] = insert(eor, root[n - 1]);
//		}
//		else {
//			cin >> l >> r >> x;
//			if (l == 1) {
//				cout << query(eor ^ x, 0, root[r - 1])<<"\n";
//			}
//			else {
//				cout << query(eor ^ x, root[l - 2], root[r - 1])<<"\n";
//			}
//		}
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 5;
//const int T = N * 22;
//int tree[T][26];
//int pass[T];
//int root[N];
//int head[N];
//int to[N << 2];
//int nex[N << 2];
//string ss[N << 2];
//int st[N][23];
//int dep[N];
//int cntg = 1;
//int cnt = 0;
//void addEdge(int u, int v, string t) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	ss[cntg] = t;
//	head[u] = cntg++;
//}
//int copy(int x) {
//	int rt = ++cnt;
//	for (int i = 0; i < 26; i++) {
//		tree[rt][i] = tree[x][i];
//	}
//	pass[rt] = pass[x];
//	return rt;
//}
//int insert(string s,int i) {
//	int rt = copy(i);
//	pass[rt]++;
//	for (int j = 0,pre=rt,cur; j < s.size(); j++,pre=cur) {
//		int path = s[j] - 'a';
//		i = tree[i][path];
//		cur = copy(i);
//		pass[cur]++;
//		tree[pre][path] = cur;
//	}
//	return rt;
//}
//void dfs(int u, int fa) {
//	st[u][0] = fa;
//	dep[u] = dep[fa] + 1;
//	for (int p = 1; p <= 22; p++) {
//		st[u][p] = st[st[u][p - 1]][p - 1];
//	}
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		root[to[ui]] = insert(ss[ui], root[u]);
//		dfs(to[ui], u);
//	}
//}
//int lca(int u, int v) {
//	if (dep[u] < dep[v])swap(u, v);
//	for (int p = 22; p >= 0; p--) {
//		if (dep[st[u][p]] >= dep[v]) {
//			u = st[u][p];
//		}
//	}
//	if (u == v)return u;
//	for (int p = 22; p >= 0; p--) {
//		if (st[u][p] != st[v][p]) {
//			u = st[u][p];
//			v = st[v][p];
//		}
//	}
//	return st[u][0];
//}
//int query(string t, int i) {
//	for (int j = 0; j < t.size(); j++) {
//		int path = t[j] - 'a';
//		if (tree[i][path] == 0) {
//			return 0;
//			break;
//		}
//		i = tree[i][path];
//	}
//	return pass[i];
//}
//int work(int u, int v, string t) {
//	return query(t, root[u]) + query(t, root[v]) - 2*query(t, root[lca(u, v)]);
//}
//int n;
//int main() {
//	cin >> n;
//	string t;
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v >> t;
//		addEdge(u, v, t);
//		addEdge(v, u, t);
//	}
//	root[0] = 0;
//	dep[0] = 0;
//	dfs(1, 0);
//	int q;
//	cin >> q;
//	for (int i = 1,u,v; i <= q; i++) {
//		cin >> u >> v>>t;
//		cout << work(u, v,t)<<"\n";
//	}
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 5;
//const int T = N * 100;
//const int BIT = 32;
//int w[N];
//int rtdfn[N];
//int rtf[N];
//int head[N];
//int nex[N << 1];
//int to[N << 1];
//int cntg = 1;
//int cntdfn = 0;
//int dfn[N];
//int st[N][23];
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//int cnt = 0;
//int tree[T][2];
//int pass[T];
//int dep[N];
//int siz[N];
//int copy(int i) {
//	int rt = ++cnt;
//	tree[rt][0] = tree[i][0];
//	tree[rt][1] = tree[i][1];
//	pass[rt] = pass[i];
//	return rt;
//}
//int insert(int num, int i) {
//	int rt = copy(i);
//	pass[rt]++;
//	for (int b = BIT,pre=rt,cur; b >= 0; b--,pre=cur) {
//		int path = (num >> b) & 1;
//		i = tree[i][path];
//		cur = copy(i);
//		pass[cur]++;
//		tree[pre][path] = cur;
//	}
//	return rt;
//}
//void dfs(int u, int fa) {
//	dfn[u] = ++cntdfn;
//	st[u][0] = fa;
//	dep[u] = dep[fa] + 1;
//	siz[u] = 1;
//	for (int p = 1; p <= 22; p++) {
//		st[u][p] = st[st[u][p - 1]][p - 1];
//	}
//	rtdfn[dfn[u]] = insert(w[u], rtdfn[dfn[u] - 1]);
//	rtf[u] = insert(w[u], rtf[fa]);
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		dfs(to[ui], u);
//		siz[u] += siz[to[ui]];
//	}
//}
//int lca(int u, int v) {
//	if (dep[u] < dep[v])swap(u, v);
//	for (int p = 22; p >= 0; p--) {
//		if (dep[st[u][p]] >= dep[v]) {
//			u = st[u][p];
//		}
//	}
//	if (u == v)return u;
//	for (int p = 22; p >= 0; p--) {
//		if (st[u][p] != st[v][p]) {
//			u = st[u][p];
//			v = st[v][p];
//		}
//	}
//	return st[u][0];
//}
//int query(int x, int num) {
//	int ans = 0;
//	int rt = rtdfn[dfn[x]-1], rt1 = rtdfn[dfn[x] + siz[x] - 1];
//	for (int b = BIT; b >= 0; b--) {
//		int path = (num >> b) & 1;
//		int best = path ^ 1;
//		if (pass[tree[rt1][best]] > pass[tree[rt][best]]) {
//			ans += 1ll << b;
//			rt = tree[rt][best];
//			rt1 = tree[rt1][best];
//		}
//		else {
//			rt = tree[rt][path];
//			rt1 = tree[rt1][path];
//		}
//	}
//	return ans;
//}
//int query(int u, int v, int num) {
//	int uv = lca(u,v);
//	int fuv = rtf[st[uv][0]];
//	uv = rtf[uv];
//	int ans = 0;
//	u = rtf[u];
//	v = rtf[v];
//	for (int b = BIT; b >= 0; b--) {
//		int path = (num >> b) & 1;
//		int best = path ^ 1;
//		if (pass[tree[u][best]] + pass[tree[v][best]] - pass[tree[fuv][best]]-pass[tree[uv][best]] > 0) {
//			ans+=1ll << b;
//			uv = tree[uv][best];
//			u = tree[u][best];
//			v = tree[v][best];
//			fuv = tree[fuv][best];
//		}
//		else {
//			uv = tree[uv][path];
//			u = tree[u][path];
//			v = tree[v][path];
//			fuv = tree[fuv][path];
//		}
//	}
//	return ans;
//}
//int n, q;
//signed main() {
//	cin >> n >> q;
//	for (int i = 1; i <= n; i++) {
//		cin >> w[i];
//	}
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dep[0] = 0;
//	pass[0] = tree[0][0] = tree[0][1] = 0;
//	rtdfn[0]=rtf[0] = 0;
//	dfs(1, 0);
//	for (int i = 1,op,x,y,z; i <= q; i++) {
//		cin >> op;
//		if (op == 1) {
//			cin >> x >> z;
//			cout << query(x, z) << "\n";
//		}
//		else {
//			cin >> x >> y >> z;
//			cout << query(x, y, z)<<"\n";
//		}
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//const int T = N * 37;
//const int BIT = 25;
//int n, m;
//int nn = -1;
//vector<int>a;
//int sum[T];
//int lson[T];
//int rson[T];
//int root[N];
//void up(int i) {
//	sum[i] = sum[lson[i]] + sum[rson[i]];
//}
//int cnt = 0;
//int copy(int i) {
//	int rt = ++cnt;
//	lson[rt] = lson[i];
//	rson[rt] = rson[i];
//	sum[rt] = sum[i];
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
//int querySum(int jl, int jr, int l, int r, int rt1,int rt2) {
//	if (l > r)return 0;
//	if (jl <= l && jr >= r) {
//		return sum[rt2]-sum[rt1];
//	}
//	int mid = l + r >> 1;
//	int ans = 0;
//	if (jl <= mid) {
//		ans += querySum(jl, jr, l, mid, lson[rt1],lson[rt2]);
//	}
//	if (jr > mid) {
//		ans += querySum(jl, jr, mid + 1, r, rson[rt1],rson[rt2]);
//	}
//	return ans;
//}
//void debug(int l, int r, int i) {
//	if (l == r) {
//		cout << '(' << l << ',' << sum[i] << ')' << " ";
//		if (l == nn)cout << "\n";
//		return;
//	}
//	int mid = l + r >> 1;
//	debug(l, mid,lson[i]);
//	debug(mid + 1, r,rson[i]);
//}
//int work(int b, int x, int l, int r) {
//	//debug(0,nn,root[l-1]);
//	//debug(0, nn, root[r]);
//	int rt1 = root[l - 1];
//	int rt2 = root[r];
//	int ans = 0;
//	int cur = 0;//前面做的选择
//	for (int B = BIT; B >= 0; B--) {
//		//cout << B<<":"<<bitset<10>(cur) << "**\n";
//		int best = ((b >> B) & 1) ^ 1;
//		int ql = max(0,cur-x), qr = min(nn,max(0,cur + (1 << (B + 1))-1-x)), qmid=min(nn,max(0,cur+(1<<B)-1-x));
//		//cout << bitset<10>(ql) << "^^\n" << bitset<10>(qmid) << "^^\n" << bitset<10>(qr) << "^^\n";
//		if (best == 1) {
//			//cout << best << " " << querySum(qmid + 1, qr, 0, nn, rt1, rt2) << "&&&\n";
//			if (querySum(qmid + 1, qr, 0, nn, rt1, rt2) > 0) {
//				cur += 1 << B;
//				ans += 1 << B;
//			}
//		}
//		else {
//			//cout << best << " " << querySum(ql, qmid, 0, nn, rt1, rt2) << "&&&\n";
//			if (querySum(ql, qmid, 0, nn, rt1, rt2) > 0) {
//				ans += 1 << B;
//			}
//			else {
//				cur += 1 << B;
//			}
//		}
//	}
//	return ans;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n >> m;
//	a.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		nn = max(nn, a[i]);
//	}
//	root[0] = build(0, nn);
//	for (int i = 1; i <= n; i++) {
//		root[i] = add(a[i], 1, 0, nn, root[i-1]);
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	debug(0, nn, root[i]);
//	//}
//	for (int i = 1, b, x, l, r; i <= m; i++) {
//		cin >> b >> x >> l >> r;
//		cout << work(b, x, l, r) << "\n";
//	}
//}



//又是这个技巧,找每一位置数字左侧第k个比x大的数
//#include<bits/stdc++.h>
//using namespace std;
//const int BIT = 30;
//const int N = 5e4 + 5;
//const int T = N * 100;
//int cnt = 0;
//int tree[T][2];
//int root[N];
//int pass[T];
//int copy(int i) {
//	int rt = ++cnt;
//	tree[rt][0] = tree[i][0];
//	tree[rt][1] = tree[i][1];
//	pass[rt] = pass[i];
//	return rt;
//}
//int insert(int num, int i) {
//	int rt = copy(i);
//	pass[rt]++;
//	for (int b = BIT,pre=rt,cur; b >= 0; b--,pre=cur) {
//		int path = (num >> b) & 1;
//		i = tree[i][path];
//		cur = copy(i);
//		pass[cur]++;
//		tree[pre][path] = cur;
//	}
//	return rt;
//}
//int query(int l, int r, int num) {
//	//cout << l << " " << r << "**\n";
//	int rt1 = root[l-1];
//	int rt2 = root[r];
//	int ans = 0;
//	for (int b = BIT; b >= 0; b--) {
//		int path = (num >> b) & 1;
//		int best = path ^ 1;
//		if (pass[tree[rt2][best]] > pass[tree[rt1][best]]) {
//			ans += 1 << b;
//			rt1 = tree[rt1][best];
//			rt2 = tree[rt2][best];
//		}
//		else {
//			rt1 = tree[rt1][path];
//			rt2 = tree[rt2][path];
//		}
//	}
//	//cout << ans << "$$\n";
//	return ans;
//}
//int main() {
//	int n;
//	cin >> n;
//	vector<array<int, 2>>a(n+2);
//	root[0] = 0;
//	int mx = -1;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i][0];
//		root[i] = insert(a[i][0], root[i - 1]);
//		a[i][1] = i;
//		mx = max(mx, a[i][0]);
//	}
//	vector<int>l(n + 2);
//	vector<int>r(n + 2);
//	for (int i = 1; i <= n; i++) {
//		l[i] = i - 1;
//		r[i] = i + 1;
//	}
//	r[n + 1]=n + 1;
//	sort(a.begin(), prev(a.end()), [&](auto x,auto y) {
//		return x[0] < y[0];
//		});
//	vector<int>l1(n + 2);
//	vector<int>l2(n + 2);
//	vector<int>r1(n + 2);
//	vector<int>r2(n + 2);
//	for (int i = 1; i <= n; i++) {
//		int id = a[i][1];
//		l1[id] = l[id];
//		l2[id] = l[l[id]];
//		r1[id] = r[id];
//		r2[id] = r[r[id]];
//		r[l[id]] = r[id];
//		l[r[id]] = l[id];
//	}
//	int ans = INT_MIN;
//	for (int i = 1; i <= n; i++) {
//		if (a[i][0] == mx)continue;
//		int ll = l2[a[i][1]]+1;
//		int rr = r2[a[i][1]]-1;
//		//cout << a[i][1] << "*\n";
//		ans = max(ans, query(ll, rr, a[i][0]));
//		//cout << ans << "&&\n";
//	}
//	cout << ans << "\n";
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int M = 3e5 + 5;
//const int N = 1e3 + 5;
//const int T = M * 60;
//const int BIT = 31;
//int xroad[N][2];
//int root[M];
//int tree[T][2];
//int pass[T];
//int cnt = 0;
//vector<int>x;
//vector<int>y;
//int copy(int i) {
//	int rt = ++cnt;
//	tree[rt][0] = tree[i][0];
//	tree[rt][1] = tree[i][1];
//	pass[rt] = pass[i];
//	return rt;
//}
//int insert(int num, int i) {
//	int rt = copy(i);
//	pass[rt]++;
//	for (int b = BIT,pre=rt,cur; b >= 0; b--,pre=cur) {
//		int path = (num >> b) & 1;
//		i = tree[i][path];
//		cur = copy(i);
//		pass[cur]++;
//		tree[pre][path] = cur;
//	}
//	return rt;
//}
//int query(int u, int d, int l, int r, int k) {
//	for (int i = u; i <= d; i++) {
//		xroad[i][0] = root[l-1];
//		xroad[i][1] = root[r];
//	}
//	int ans = 0;
//	for (int b = BIT; b >= 0; b--) {
//		int sum = 0;
//		for (int i = u; i <= d; i++) {
//			int path = (x[i] >> b) & 1;
//			int best = path ^ 1;
//			sum += pass[tree[xroad[i][1]][best]] - pass[tree[xroad[i][0]][best]];
//		}
//		for (int i = u; i <= d; i++) {
//			int path = (x[i] >> b) & 1;
//			int best = path ^ 1;
//			if (sum>=k) {
//				xroad[i][1] = tree[xroad[i][1]][best];
//				xroad[i][0] = tree[xroad[i][0]][best];
//			}
//			else {
//				xroad[i][1] = tree[xroad[i][1]][path];
//				xroad[i][0] = tree[xroad[i][0]][path];
//			}
//		}
//		if (sum >= k) {
//			ans += 1ll << b;
//		}
//		else {
//			k -= sum;
//		}
//	}
//	return ans;
//}
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	x.resize(n + 1);
//	y.resize(m + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> x[i];
//	}
//	for (int i = 1; i <= m; i++) {
//		cin >> y[i];
//		root[i] = insert(y[i], root[i - 1]);
//	}
//	int p;
//	cin >> p;
//	for (int i = 1,u,d,l,r,k; i <= p; i++) {
//		cin >> u >> d >> l >> r >> k;
//		cout << query(u, d, l, r, k) << "\n";
//	}
//}