//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//const int T = N * 25;
//int head[N];
//int lson[T];
//int rson[T];
//int val[T];
//int cnt = 0;
//int a[N];
//void build(int l, int r, int i) {
//	if (l == r) {
//		val[i] = a[l];
//		return;
//	}
//	lson[i] = ++cnt;
//	rson[i] = ++cnt;
//	int mid = l + r >> 1;
//	build(l, mid, lson[i]);
//	build(mid + 1, r, rson[i]);
//}
//int add(int x,int v, int l, int r, int i) {
//	int rt = ++cnt;
//	lson[rt] = lson[i];
//	rson[rt] = rson[i];
//	val[rt] = val[i];
//	if (l == r) {
//		val[rt] = v;
//		return rt;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		lson[rt] = add(x,v, l, mid, lson[rt]);
//	}
//	else {
//		rson[rt] = add(x,v, mid + 1, r, rson[rt]);
//	}
//	return rt;
//}
//int query(int x, int l, int r, int i) {
//	if (l == r) {
//		return val[i];
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		return query(x, l, mid, lson[i]);
//	}
//	else return query(x, mid + 1, r, rson[i]);
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	head[0] = ++cnt;
//	build(1, n, head[0]);
//	for (int i = 1,v,op,p,c; i <= m; i++) {
//		cin >> v >> op;
//		if (op == 1) {
//			cin >> p >> c;
//			head[i] = add(p,c, 1, n, head[v]);
//		}
//		else {
//			cin >> p;
//			head[i] = head[v];
//			cout<<query(p,1,n,head[v])<<'\n';
//		}
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//const int T = N * 25;
//int a[N];
//int head[N];
//int lson[T];
//int rson[T];
//int siz[T];
//int cnt = 0;
//int build(int l, int r) {
//	int rt = ++cnt;
//	siz[rt] = 0;
//	if (l != r) {
//		int mid = l + r >> 1;
//		lson[rt] = build(l, mid);
//		rson[rt] = build(mid + 1, r);
//	}
//	return rt;
//}
//int add(int x, int l, int r, int i) {
//	int rt = ++cnt;
//	lson[rt] = lson[i];
//	rson[rt] = rson[i];
//	siz[rt] = siz[i] + 1;
//	if (l<r) {
//		int mid = l + r >> 1;
//		if (x <= mid) {
//			lson[rt] = add(x, l, mid, lson[rt]);
//		}
//		else {
//			rson[rt] = add(x, mid + 1, r, rson[rt]);
//		}
//	}
//	return rt;
//}
//int query(int l, int r, int k, int h1, int h2) {
//	if (l == r) {
//		return l;
//	}
//	int sizl = siz[lson[h2]] - siz[lson[h1]];
//	int mid = l + r >> 1;
//	if (k <= sizl) {
//		return query(l, mid, k, lson[h1], lson[h2]);
//	}
//	else {
//		return query(mid + 1, r, k - sizl, rson[h1], rson[h2]);
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n, m;
//	cin >> n >> m;
//	vector<int>vsort;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		vsort.push_back(a[i]);
//	}
//	
//	sort(vsort.begin(), vsort.end());
//	vsort.erase(unique(vsort.begin(), vsort.end()), vsort.end());
//	int s = vsort.size();
//	vsort.insert(vsort.begin(), 0);
//	head[0] = build(1, s);
//	for (int i = 1; i <= n; i++) {
//		int v = lower_bound(vsort.begin() + 1, vsort.end(), a[i]) - vsort.begin();
//		head[i] = add(v, 1, s, head[i - 1]);
//	}
//	for (int i = 1, l, r, k; i <= m; i++) {
//		cin >> l >> r >> k;
//		cout << vsort[query(1, s, k, head[l - 1], head[r])] << '\n';
//	}
//}

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 5;
//const int T = N * 70;
//int a[N];
//int sum[T];
//int lzt[T];
//int lson[T];
//int rson[T];
//int head[N];
//int cnt = 0;
//int clone(int i) {
//	int rt = ++cnt;
//	lson[rt] = lson[i];
//	rson[rt] = rson[i];
//	sum[rt] = sum[i];
//	lzt[rt] = lzt[i];
//	return rt;
//}
//void lazy(int i, int v, int n) {
//	sum[i]+=v * n;
//	lzt[i] += v;
//}
//void up(int i) {
//	sum[i] = sum[lson[i]] + sum[rson[i]];
//}
//void down(int i, int ln, int rn){
//	if (lzt[i] != 0) {
//		lson[i] = clone(lson[i]);
//		rson[i] = clone(rson[i]);
//		lazy(lson[i], lzt[i], ln);
//		lazy(rson[i], lzt[i], rn);
//		lzt[i] = 0;
//	}
//}
//int build(int l, int r) {
//	int rt = ++cnt;
//	lzt[rt] = 0;
//	if (l == r) {
//		sum[rt] = a[l];
//		return rt;
//	}
//	int mid = l + r >> 1;
//	lson[rt] = build(l, mid);
//	rson[rt] = build(mid + 1, r);
//	up(rt);
//	return rt;
//}
//int query(int jl,int jr,int l,int r,int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int ans = 0;
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	if (jl <= mid) {
//		ans += query(jl, jr, l, mid, lson[i]);
//	}
//	if (jr > mid) {
//		ans += query(jl, jr, mid + 1, r, rson[i]);
//	}
//	return ans;
//}
//int add(int jl, int jr,int v, int l, int r, int i) {
//	int rt = clone(i);
//	if (jl <= l && jr >= r) {
//		lazy(rt, v, r - l + 1);
//		return rt;
//	}
//	int mid = l + r >> 1;
//	down(rt, mid - l + r, r - mid);
//	int ans = 0;
//	if (jl <= mid) {
//		lson[rt] = add(jl, jr,v, l, mid, lson[rt]);
//	}
//	if (jr > mid) {
//		rson[rt] = add(jl, jr,v, mid + 1, r, rson[rt]);
//	}
//	up(rt);
//	return rt;
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	char op;
//	int v = 0;
//	head[0] = build(1,n);
//	for (int i = 1,l,r,t; i <= m; i++) {
//		cin >> op;
//		if (op == 'Q') {
//			cin >> l >> r;
//			cout << query(l, r, 1, n, head[v])<<'\n';
//		}
//		else if (op == 'C') {
//			cin >> l >> r >> t;
//			head[v + 1] = add(l, r, t, 1, n, head[v]);
//			v++;
//		}
//		else if (op == 'H') {
//			cin >> l >> r >> t;
//			cout << query(l, r, 1, n, head[t]) << "\n";
//		}
//		else {
//			cin >> t;
//			v = t;
//		}
//	}
//}




//标记永久化实现线段树
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 5;
//int a[N];
//int sum[N << 2];
//int tag[N << 2];
//int lson[N << 2];
//int rson[N << 2];
//int cnt = 0;
//void up(int i) {
//	sum[i] = sum[lson[i]] + sum[rson[i]];
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = a[l];
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		sum[i] = sum[i << 1] + sum[i << 1 | 1];
//	}
//	tag[i] = 0;
//}
//void add(int jl, int jr, int v, int l, int r, int i) {
//	int a = max(jl, l), b = min(jr, r);//任务真正影响到的左右边界
//	sum[i] += v * (b - a + 1);
//	if (jl <= l && jr >= r) {
//		tag[i] += v;//全覆盖就更新tag不再下传//tag只影响该节点的子节点,不影响该节点
//	}
//	else {
//		int mid = l + r >> 1;
//		if (jl <= mid) {
//			add(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			add(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//	}
//}
//int query(int jl, int jr, int ad, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i] + (r - l + 1) * ad;
//	}
//	int mid = l + r >> 1;
//	int ans = 0;
//	if (jl <= mid) {
//		ans += query(jl, jr, ad + tag[i], l, mid, i << 1);
//	}
//	if (jr > mid){
//		ans += query(jl, jr, ad + tag[i], mid + 1, r, i << 1 | 1);
//	}
//	return ans;
//}
//signed main() {
//	int n, m;
//	cin >> n>>m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	build(1, n, 1);
//	for (int i = 1,op,x,y,k; i <= m; i++) {
//		cin >> op>>x>>y;
//		if (op == 1) {
//			cin >> k;
//			add(x, y, k, 1, n, 1);
//		}
//		else {
//			cout << query(x, y, 0, 1, n, 1) << '\n';
//		}
//	}
//}



//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int N = 1e5 + 5;
//const int T = N * 25;
//int a[N];
//int head[N];
//int lson[T];
//int rson[T];
//ll tag[T];
//ll sum[T];
//int cnt = 0;
//int build(int l, int r) {
//	int rt = ++cnt;
//	tag[rt] = 0;
//	if (l == r) {
//		sum[rt] = a[l];
//		return rt;
//	}
//	int mid = l + r >> 1;
//	lson[rt] = build(l, mid);
//	rson[rt] = build(mid + 1, r);
//	sum[rt] = sum[lson[rt]] + sum[rson[rt]];//up方法仅在这里需要所以就没写up了
//	return rt;
//}
//int clone(int i) {
//	sum[++cnt] = sum[i];
//	lson[cnt] = lson[i];
//	rson[cnt] = rson[i];
//	tag[cnt] = tag[i];
//	return cnt;
//}
//int add(int jl, int jr, int v,int l, int r, int i) {
//	int rt = clone(i);
//	int a = max(jl, l), b = min(jr, r);
//	sum[rt] += (b - a + 1) * v;
//	if (jl <= l && jr >= r) {
//		tag[rt] += v;
//		return rt;
//	}
//	int mid = l + r >> 1;
//	if (jl <= mid) {
//		lson[rt] = add(jl, jr, v, l, mid, lson[rt]);
//	}
//	if (jr > mid) {
//		rson[rt] = add(jl, jr, v, mid + 1, r, rson[rt]);
//	}
//	return rt;
//}
//
//ll query(int jl, int jr,int ad, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i] + (r - l + 1) * ad;
//	}
//	int mid = l + r >> 1;
//	ll ans = 0;
//	if (jl <= mid) {
//		ans += query(jl, jr, ad + tag[i], l, mid, lson[i]);
//	}
//	if(jr>mid){
//		ans += query(jl, jr, ad + tag[i], mid + 1, r, rson[i]);
//	}
//	return ans;
//}
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	head[0] = build(1, n);
//	int t = 0;
//	char op;
//	for (int i = 1,l,r,v; i<= m; i++) {
//		cin >> op;
//		if (op == 'C') {
//			cin >> l >> r >> v;
//			head[t+1]=add(l, r, v, 1, n, head[t]);
//			t++;
//		}
//		else if(op=='Q') {
//			cin >> l >> r;
//			cout << query(l, r, 0, 1, n, head[t])<<'\n';
//		}
//		else if (op == 'H') {
//			cin >> l >> r >> v;
//			cout << query(l, r, 0, 1, n, head[v])<<'\n';
//		}
//		else {
//			cin >> v;
//			t = v;
//		}
//	}
//}