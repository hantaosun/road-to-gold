//左偏树模板
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 1;
//int n, m;
//int num[N];
//int lson[N];
//int rson[N];
//int dist[N];//当前节点到空节点的步数-1
//int fa[N];//这是并查集的父节点,不是左偏树的父节点
//void prepare() {
//	dist[0] = -1;
//	for (int i = 1; i <= n; i++) {
//		lson[i] = rson[i] = dist[i] = 0;
//		fa[i] = i;
//	}
//}
//int find(int i) {
//	while (fa[i] != i) {
//		i = fa[i] = fa[fa[i]];
//	}
//	return i;
//}
//int merge(int i, int j) {//合并以i为根和以j为根的堆,操作永远在右树上进行
//	if (i == 0 || j == 0) {
//		return i + j;
//	}
//	if (num[i] > num[j] || num[i] == num[j] && i > j) {//谁小谁做新根
//		swap(i, j);
//	}
//	//通过上面的判断这里i一定是值较小的根
//	rson[i] = merge(rson[i], j);
//	if (dist[lson[i]] < dist[rson[i]]) {
//		swap(lson[i], rson[i]);
//	}
//	dist[i] = dist[rson[i]] + 1;
//	//新左右孩子的父亲信息未设置
//	fa[lson[i]] = fa[rson[i]] = i;
//	return i;
//}
//int pop(int i) {
//	fa[lson[i]] = lson[i];
//	fa[rson[i]] = rson[i];
//	//lson[i]和rson[i]谁做头部在merge里会设置
//	fa[i] = merge(lson[i], rson[i]);
//	lson[i] = rson[i] = dist[i] = 0;
//	return fa[i];
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n;
//	prepare();
//	for (int i = 1; i <= n; i++) {
//		cin >> num[i];
//	}
//	cin >> m;
//	char op;
//	for (int i = 1,x,y; i <= m; i++) {
//		cin >> op;
//		if (op == 'M') {
//			cin >> x >> y;
//			if (num[x] != -1 && num[y] != -1) {
//				int l = find(x);
//				int r = find(y);
//				if (l != r) {
//					merge(l, r);
//				}
//			}
//		}
//		else {
//			cin >> x;
//			if (num[x] == -1) {
//				cout << 0 << '\n';
//			}
//			else {
//				int ans = find(x);
//				cout << num[ans] << '\n';
//				pop(ans);
//				num[ans] = -1;
//			}
//		}
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2e6 + 5;
//int num[N];
//int dist[N];
//int up[N];//左偏树的上级节点,移除节点需要该结构
//int lson[N];
//int rson[N];
//int fa[N];//并查集的父亲
//int n, m;
//int t, w, k;
//void prepare() {
//	dist[0] = -1;
//	for (int i = 1; i <= n; i++) {
//		up[i] = lson[i] = rson[i] = dist[i] = 0;
//		fa[i] = i;
//	}
//}
//int find(int x) {
//	while (x != fa[x]) {
//		x = fa[x] = fa[fa[x]];
//	}
//	return x;
//}
//int merge(int i, int j) {
//	if (i == 0 || j == 0)return i + j;
//	if (num[i]<num[j] || num[i] == num[j] && i>j) {
//		swap(i, j);
//	}
//	rson[i] = merge(rson[i], j);
//	up[rson[i]] = i;
//	if (dist[lson[i]] < dist[rson[i]]) {
//		swap(lson[i], rson[i]);
//	}
//	dist[i] = dist[rson[i]] + 1;
//	fa[lson[i]] = fa[rson[i]] = i;
//	return i;
//}
//int remove(int i) {
//	int h = find(i);
//	fa[lson[i]] = lson[i];
//	fa[rson[i]] = rson[i];
//	int s = merge(lson[i], rson[i]);
//	int f = up[i];
//	fa[i] = s;
//	up[s] = f;
//	if (h != i) {
//		fa[s] = h;
//		if (lson[f] == i) {
//			lson[f] = s;
//		}
//		else {
//			rson[f] = s;
//		}
//		for (int d = dist[s]; dist[f] > d + 1; f = up[f], d++) {
//			dist[f] = d + 1;
//			if (dist[lson[f]] < dist[rson[f]]) {
//				swap(lson[f], rson[f]);
//			}
//		}
//	}
//	up[i] = lson[i] = rson[i] = dist[i] = 0;
//	return fa[s];
//}
//void reduce(int i, int v) {
//	int h = remove(i);
//	num[i] = max(num[i] - v, 0ll);
//	fa[h] = fa[i] = merge(h, i);
//}
//int compute() {
//	int ans = 0;
//	int mx = 0;
//	for (int i = 1; i <=n; i++) {
//		if (fa[i] == i) {
//			ans += num[i];
//			if (num[i] > mx)mx = num[i];
//		}
//	}
//	if (w == 2) {
//		ans -= mx;
//	}
//	else if (w == 3) {
//		ans += mx;
//	}
//	return ans;
//}
//void solve() {
//	cin >> n >> m;
//	prepare();
//	for (int i = 1; i <= n; i++) {
//		cin >> num[i];
//	}
//	for (int i = 1,op,x,y; i <= m; i++) {
//		cin >> op;
//		if (op == 2) {
//			cin >> x;
//			reduce(x, num[x]);
//		}
//		else if (op == 3) {
//			cin >> x >> y;
//			reduce(find(x), y);
//		}
//		else {
//			cin >> x >> y;
//			int l = find(x);
//			int r = find(y);
//			if (l != r) {
//				merge(l, r);
//			}
//		}
//	}
//	int ans = compute();
//	if (ans == 0) {
//		cout << "Gensokyo " << ans << endl;
//	}
//	else if (ans > k) {
//		cout << "Hell " << ans << endl;
//	}
//	else {
//		cout << "Heaven " << ans << endl;
//	}
//}
//signed main() {
//	cin >> t>>w>>k;
//	while (t--) {
//		solve();
//	}
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 5;
//int num[N];
//int fa[N];
//int up[N];
//int lson[N];
//int rson[N];
//int dist[N];
//int find(int x) {
//	while (x != fa[x]) {
//		x = fa[x] = fa[fa[x]];
//	}
//	return x;
//}
//int merge(int i, int j) {
//	if (i == 0 || j == 0) {
//		return i + j;
//	}
//	if (num[i] < num[j]) {
//		swap(i, j);
//	}
//	rson[i] = merge(rson[i], j);
//	if (dist[lson[i]] < dist[rson[i]]) {
//		swap(lson[i], rson[i]);
//	}
//	dist[i] = dist[rson[i]] + 1;
//	fa[lson[i]] = fa[rson[i]] = i;
//	return i;
//}
//int pop(int i) {//移除i号节点并返回新头
//	fa[lson[i]] = lson[i];
//	fa[rson[i]] = rson[i];
//	fa[i] = merge(lson[i], rson[i]);
//	lson[i] = rson[i] = dist[i] = 0;
//	return fa[i];
//}
//int fight(int x, int y) {
//	int fx = find(x);
//	int fy = find(y);
//	if (fx == fy)return -1;
//	int l = pop(fx);
//	int r = pop(fy);
//	num[fx] /= 2;
//	num[fy] /= 2;
//	fa[fx]=fa[fy]=fa[l]=fa[r]=merge(merge(l, fx),merge(r, fy));
//	return num[fa[fx]];
//}
//void prepare() {
//	dist[0] = -1;
//	for (int i = 1; i < N; i++) {
//		fa[i] = i;
//		lson[i] = rson[i]=dist[i]=0;
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n;
//	while (cin >> n) {
//		prepare();
//		for (int i = 1; i <= n; i++) {
//			cin >> num[i];
//		}
//		int m;
//		cin >> m;
//		for (int i = 1, x, y; i <= m; i++) {
//			cin >> x >> y;
//			cout << fight(x, y) << '\n';
//		}
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//int n, m;
//const int N = 1e5 + 5;
//int leader[N];
//long long cost[N];
//long long ability[N];
//int lson[N];
//int rson[N];
//int dist[N];
//int fa[N];
//int siz[N];
//long long sum[N];
//int find(int x) {
//	while(x != fa[x]) {
//		x = fa[x] = fa[fa[x]];
//	}
//	return x;
//
//}
//int merge(int i, int j) {
//	if (i == 0 || j == 0) {
//		return i + j;
//	}
//	if (cost[i] < cost[j]) {
//		swap(i, j);
//	}
//	rson[i] = merge(rson[i], j);
//	if (dist[lson[i]] < dist[rson[i]]) {
//		swap(lson[i], rson[i]);
//	}
//	dist[i] = dist[rson[i]] + 1;
//	fa[lson[i]] = fa[rson[i]] = i;
//	return i;
//}
//int pop(int i) {
//	fa[lson[i]] = lson[i];
//	fa[rson[i]] = rson[i];
//	fa[i] = merge(lson[i], rson[i]);
//	lson[i] = rson[i] = dist[i] = 0;
//	return fa[i];
//}
//long long compute() {
//	long long ans = 0;
//	int p, psize, h, hsize;
//	long long hsum, psum;
//	for (int i = n; i >= 1; i--) {
//		h = find(i);
//		hsize = siz[h];
//		hsum = sum[h];
//		while (hsum > m) {
//			pop(h);
//			hsize--;
//			hsum -= cost[h];
//			h = find(i);
//		}
//		ans = max(ans, (long long)hsize * ability[i]);
//		if (i > 1) {
//			p = find(leader[i]);
//			psize = siz[p];
//			psum = sum[p];
//			fa[p] = fa[h] = merge(h, p);
//			siz[fa[p]] = psize + hsize;
//			sum[fa[p]] = psum + hsum;
//		}
//	}
//	return ans;
//}
//void prepare() {
//	dist[0] = -1;
//	for (int i = 1; i <= n; i++) {
//		lson[i]=rson[i]=dist[i] = 0;
//		siz[i] = 1;
//		sum[i] = cost[i];
//		fa[i] = i;
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> leader[i] >> cost[i] >> ability[i];
//	}
//	prepare();
//	cout << compute() << '\n';
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//int n;
//int a[N];
//int ans[N];
//int fa[N];
//int lson[N];
//int rson[N];
//int dist[N];
//int siz[N];
//int from[N];
//int to[N];
//void prepare() {
//	dist[0] = -1;
//	for (int i = 1; i <= n; i++) {
//		fa[i] = from[i]=to[i]=i;
//		dist[i] = 0;
//		siz[i] = 1;
//	}
//}
//int merge(int i, int j) {
//	if (i == 0 || j == 0) {
//		return i + j;
//	}
//	if (a[i] < a[j]) {
//		swap(i, j);
//	}
//	rson[i] = merge(rson[i], j);
//	if (dist[rson[i]] > dist[lson[i]]) {
//		swap(lson[i], rson[i]);
//	}
//	dist[i] = dist[rson[i]] + 1;
//	fa[lson[i]] = fa[rson[i]] = i;
//	return i;
//}
//int pop(int i) {
//	fa[lson[i]] = lson[i];
//	fa[rson[i]] = rson[i];
//	fa[i] = merge(lson[i], rson[i]);
//	lson[i] = rson[i] = dist[i] = 0;
//	return fa[i];
//}
//int find(int x) {
//	while (x != fa[x]) {
//		x = fa[x] = fa[fa[x]];
//	}
//	return x;
//}
//int sta[N];
//long long compute() {
//	int stackSiz = 0;
//	for (int i = 1, pre, cur, s; i <= n; i++) {
//		while (stackSiz > 0) {
//			pre = find(sta[stackSiz]);
//			cur = find(i);
//			if (a[pre] <= a[cur]) {//因为堆中只留了一半的元素,所以此时的堆顶就是中位数
//				break;
//			}
//			s = siz[pre] + siz[cur];
//			cur = merge(pre,cur);
//			while (s > ((i - from[pre] + 1 + 1) / 2)) {
//				cur = pop(cur);
//				s--;
//			}
//			from[cur] = from[pre];
//			to[cur] = i;
//			siz[cur] = s;
//			stackSiz--;
//		}
//		sta[++stackSiz] = i;
//	}
//	long long sum = 0;
//	for (int i = 1, cur; i <= stackSiz; i++) {
//		cur = find(sta[i]);
//		for (int j = from[cur]; j <= to[cur]; j++) {
//			ans[j] = a[cur];
//			sum += llabs(ans[j] - a[j]);
//		}
//	}
//	return sum;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n;
//	prepare();
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		a[i] -= i;
//	}
//	long long res = compute();
//	cout << res << '\n';
//	for (int i = 1; i <= n; i++) {
//		cout << ans[i] + i << ' ';
//	}
//	cout << '\n';
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 3e5 + 5;
//int dui[N];//当前城市堆中的一个元素的编号
//int h[N];
//int f[N];
//int a[N];
//int v[N];
//int att[N];
//int fst[N];
//int dep[N];
//int lson[N];
//int rson[N];
//int dist[N];
//int ad[N];
//int mul[N];
//int head[N];
//int nex[N];
//int to[N];
//int die[N];
//int dieAt[N];
//int cnt = 1;
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//void prepare() {
//	dist[0] = -1;
//	for (int i = 1; i < N; i++) {
//		dist[i] = 0;
//		ad[i] = 0;
//		mul[i] = 1;
//	}
//}
//void down(int i) {
//	int l = lson[i], r = rson[i];
//	if (mul[i] != 1) {
//		if (l != 0) {
//			att[l] *= mul[i];
//			mul[l] *= mul[i];
//			ad[l] *= mul[i];
//		}
//		if (r != 0) {
//			att[r] *= mul[i];
//			mul[r] *= mul[i];
//			ad[r] *= mul[i];
//		}
//		mul[i] = 1;
//	}
//	if (ad[i] != 0) {
//		if (l != 0) {
//			att[l] += ad[i];
//			ad[l] += ad[i];
//		}
//		if (r != 0) {
//			att[r] += ad[i];
//			ad[r] += ad[i];
//
//		}
//		ad[i] = 0;
//	}
//}
//void dfs(int i, int pa) {
//	dep[i] = dep[pa] + 1;
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		dfs(to[ui], i);
//	}
//}
//int merge(int i, int j) {
//	if (i == 0 || j == 0) {
//		return i + j;
//	}
//	if (att[i] > att[j]) {
//		swap(i, j);
//	}
//	down(i);
//	rson[i] = merge(rson[i], j);
//	if (dist[rson[i]] > dist[lson[i]]) {
//		swap(lson[i], rson[i]);
//	}
//	dist[i] = dist[rson[i]] + 1;
//	return i;
//}
//int pop(int i) {
//	down(i);
//	int ans = merge(lson[i], rson[i]);
//	lson[i] = rson[i] = dist[i] = 0;
//	return ans;
//}
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	prepare();
//	for (int i = 1; i <= n; i++) {
//		cin >> h[i];
//	}
//	a[1] = v[1] = 1;
//	for (int i = 2; i <= n; i++) {
//		cin >> f[i] >> a[i] >> v[i];
//		addEdge(f[i], i);
//	}
//	dfs(1, 0);
//	for (int i = 1; i <= m; i++) {
//		cin >> att[i] >> fst[i];
//		dieAt[i] = dep[fst[i]];
//		if (dui[fst[i]] == 0) {
//			dui[fst[i]] = i;
//		}
//		else {
//			dui[fst[i]] = merge(dui[fst[i]], i);
//		}
//	}
//	for (int i = n; i >= 1; i--) {
//		while (dui[i] != 0 && att[dui[i]] < h[i]) {
//			die[i]++;
//			dieAt[dui[i]] = dep[fst[dui[i]]] - dep[i];
//			dui[i] = pop(dui[i]);
//		}
//		if (dui[i] != 0) {
//			if (a[i] == 0) {
//				att[dui[i]] += v[i];
//				ad[dui[i]] += v[i];
//			}
//			else {
//				att[dui[i]] *= v[i];
//				ad[dui[i]] *= v[i];
//				mul[dui[i]] *= v[i];
//			}
//			if (f[i] != 0) {
//				dui[f[i]]=merge(dui[f[i]], dui[i]);
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << die[i] << '\n';
//	}
//	for (int i = 1; i <= m; i++) {
//		cout << dieAt[i] << '\n';
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 3e5 + 5;
//int a[N];
//int dist[N];
//int lson[N];
//int rson[N];
//int fa[N];
//int up[N];
//int siz[N];
//int ad[N];
//int allAd = 0;
//map<int, int>mx;
//int n;
//void rhead(int i) {
//	if (i == 0)return;
//	if (mx.count(a[i] + ad[i])) {
//		if (--mx[a[i] + ad[i]] <= 0) {
//			mx.erase(a[i] + ad[i]);
//		}
//	}
//}
//void ahead(int i) {
//	if(i!=0)mx[a[i] + ad[i]]++;
//}
//int find(int x) {
//	while (x != fa[x]) {
//		x = fa[x] = fa[fa[x]];
//	}
//	return x;
//}
//void prepare() {
//	dist[0] = -1;
//	mx.clear();
//	for (int i = 1; i <= n; i++) {
//		up[i]=dist[i] = lson[i] = rson[i] = 0;
//		fa[i] = i;
//		siz[i] = 1;
//		ahead(i);
//	}
//}
//int merge(int i, int j) {
//	if (i == 0 || j == 0) {
//		return i + j;
//	}
//	if (a[i] < a[j]) {
//		swap(i, j);
//	}
//	rson[i] = merge(rson[i], j);
//	up[rson[i]] = i;
//	if (dist[rson[i]] > dist[lson[i]]) {
//		swap(lson[i], rson[i]);
//	}
//	dist[i] = dist[rson[i]] + 1;
//	fa[lson[i]] = fa[rson[i]] = i;
//	return i;
//}
//int remove(int i) {
//	//简单的更新父子信息的操作
//	int h = find(i);
//	fa[lson[i]] = lson[i];
//	fa[rson[i]] = rson[i];
//	int s = merge(lson[i], rson[i]);
//	int f = up[i];
//	fa[i] = s;
//	up[s] = f;
//	if (h != i) {//i不是根节点
//		//简单的更新孩子信息的操作
//		fa[s] = h;
//		if (lson[f] == i) {
//			lson[f] = s;
//		}
//		else {
//			rson[f] = s;
//		}
//		for (int d = dist[s]; dist[f] > d + 1; f = up[f], d++) {
//			dist[f] = d + 1;
//			if (dist[lson[f]] < dist[rson[f]]) {
//				swap(lson[f], rson[f]);
//			}
//		}
//	}
//	up[i] = lson[i] = rson[i] = dist[i] = 0;
//	return fa[s];//返回的是合并后的根节点
//}
//
//void down(int i,int v) {
//	if (i == 0)return;
//	a[i] += v;
//	down(lson[i], v);
//	down(rson[i], v);
//}
//void Union(int i, int j) {//把i和j所在堆合并
//	int l = find(i);
//	int r = find(j);
//	if (l == r)return;	
//	int lsiz = siz[l];
//	int rsiz = siz[r];	
//	rhead(l);
//	rhead(r);
//	int adtag;
//	if (lsiz <= rsiz) {
//		down(l, ad[l] - ad[r]);
//		adtag = ad[r];
//	}
//	else {
//		down(r, ad[r] - ad[l]);
//		adtag = ad[l];
//	}
//	int h = merge(l, r);
//	siz[h] = lsiz + rsiz;
//	ad[h] = adtag;
//	ahead(h);
//}
//void a1(int i, int v) {
//	int h = find(i);
//	rhead(h);
//	int l=remove(i);
//	if (l != 0) {
//		siz[l] = siz[h] - 1;
//		ad[l] = ad[h];
//		ahead(l);
//	}
//	a[i] = a[i] + ad[h] + v;
//	lson[i] = rson[i] = 0;
//	ad[i] = 0;
//	fa[i] = i;
//	siz[i] = 1;
//	ahead(i);
//	Union(i, l);
//}
//void a2(int i, int v) {
//	int h = find(i);
//	rhead(h);
//	ad[h] += v;
//	ahead(h);
//}
//void a3(int v) {
//	allAd += v;
//}
//int f1(int i) {
//	return a[i] + ad[find(i)] + allAd;
//}
//int f2(int i) {
//	int h = find(i);
//	return a[h] + ad[h] + allAd;
//}
//int f3() {
//	return ((*prev(mx.end())).first)+allAd;
//}
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	prepare();
//	int q;
//	cin >> q;
//	string op;
//	for (int i = 1,x,v; i <= q; i++) {
//		cin >> op;
//		if (op == "U") {
//			cin >> x >> v;
//			Union(x, v); 
//		}
//		else if (op == "A1") {
//			cin >> x >> v;
//			a1(x, v);
//		}
//		else if (op == "A2") {
//			cin >> x >> v;
//			a2(x, v);
//		}
//		else if (op == "A3") {
//			cin >> x;
//			a3(x);
//		}
//		else if (op == "F1") {
//			cin >> x;
//			cout << f1(x) << '\n';
//		}
//		else if (op == "F2") {
//			cin >> x;
//			cout << f2(x) << '\n';
//		}
//		else {
//			cout << f3() << '\n';
//		}
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 101;
//const int M = 10001;
//const int T = 1000001;
//int n, k;
//int arr[M];
//int start[N];
//int boundary[N];
//
////最优行动来自哪个数组
//int idx[T];
////最优行动要替换掉对应idx数组中什么位置的数
//int jdx[T];
//int cost[T];
//int lson[T];
//int rson[T];
//int dist[T];
////基于之前的某个方案这个方案的累加和
//int pre[T];
//int cnt = 0;
//
//int ans[M];
//int init(int i, int j) {
//	idx[++cnt] = i;
//	jdx[cnt] = j;
//	cost[cnt] = (j + 1 < boundary[i]) ? (arr[j + 1] - arr[j]) : INT_MAX;
//	lson[cnt] = rson[cnt] = dist[cnt] = 0;
//	return cnt;
//}
//int clone(int i) {
//	idx[++cnt] = idx[i];
//	jdx[cnt] = jdx[i];
//	cost[cnt] = cost[i];
//	lson[cnt] = lson[i];
//	rson[cnt] = rson[i];
//	dist[cnt] = dist[i];
//	return cnt;
//}
//int merge(int i, int j) {
//	if (i == 0 || j == 0) {
//		return i + j;
//	}
//	if (cost[i] > cost[j]) {
//		swap(i, j);
//	}
//	int h = clone(i);
//	rson[h] = merge(rson[h], j);
//	if (dist[lson[h]] < dist[rson[h]]) {
//		swap(lson[h], rson[h]);
//	}
//	dist[h] = dist[rson[h]] + 1;
//	return h;
//}
//
//int pop(int i) {
//	if (lson[i] == 0 && rson[i] == 0)return 0;
//	if (lson[i] == 0 || rson[i] == 0) {
//		return clone(lson[i] + rson[i]);
//	}
//	return merge(lson[i], rson[i]);
//}
//struct Compare {
//	bool operator()(int x, int y) {
//		return pre[x] + cost[x] > pre[y] + cost[y];
//	}
//};
//priority_queue<int, vector<int>,Compare>pq;
//void compute() {
//	int first = 0;
//	for (int i = 1; i <= n; i++) {
//		sort(arr + start[i], arr + boundary[i]);
//		first += arr[start[i]];
//	}
//	dist[0] = -1;
//	int head = 0 ;
//	for (int i = 1; i <= n; i++) {
//		head = merge(head, init(i, start[i]));
//	}
//	pre[head] = first;
//	ans[1] = first;
//	pq.push(head);
//	for (int ansi = 2, h1, h2; ansi <= k; ansi++) {
//		head = pq.top();
//		pq.pop();
//		ans[ansi] = pre[head] + cost[head];
//		h1 = pop(head);
//		if (h1 != 0) {
//			pre[h1] = pre[head];
//			pq.push(h1);
//		}
//		if (jdx[head] + 1 < boundary[idx[head]]) {
//			h2 = merge(h1, init(idx[head], jdx[head] + 1));
//			pre[h2] = ans[ansi];
//			pq.push(h2);
//		}
//	}
//}
//int main() {
//	cin >> n >> k;
//	int ai = 0;
//	for (int i = 1; i <= n; i++) {
//		int m;
//		cin >> m;
//		start[i] = ai + 1;
//		for (int j = 1; j <= m; j++) {
//			cin >> arr[++ai];
//		}
//		boundary[i] = start[i] + m;
//	}
//	compute();
//	for (int i = 1; i <= k; i++) {
//		cout << ans[i] << ' ';
//	}
//	cout << '\n';
//}



//k短路问题
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 5e4 + 1;
//const int M = 2e5 + 1;
//const int T = 1000001;
//const double INF = 1e18;
//int n, m;
//double money;
//
////正图
//int headg[N];
//int tog[M];
//int nexg[M];
//double weightg[M];
//int cntg = 0;
//
//
////反图
//int headr[N];
//int tor[M];
//int nexr[M];
//double weightr[M];
//int cntr = 0;
//
//int to[T];
//double cost[T];
//int lson[T];
//int rson[T];
//int dist[T];
//int cntt = 0;
//
//int rt[N];
//
//
//bool vis[N];
//int path[N];
//double dis[N];
//void addEdgeG(int u, int v, double w) {
//	nexg[++cntg] = headg[u];
//	tog[cntg] = v;
//	weightg[cntg] = w;
//	headg[u] = cntg;
//}
//void addEdgeR(int u, int v, double w) {
//	nexr[++cntr] = headr[u];
//	tor[cntr] = v;
//	weightr[cntr] = w;
//	headr[u] = cntr;
//}
//int init(int t, double v) {
//	to[++cntt] = t;
//	cost[cntt] = v;
//	lson[cntt] = rson[cntt] = dist[cntt] = 0;
//	return cntt;
//}
//int clone(int i) {
//	to[++cntt] = to[i];
//	cost[cntt] = cost[i];
//	lson[cntt] = lson[i];
//	rson[cntt] = rson[i];
//	dist[cntt] = dist[i];
//	return cntt;
//}
//int merge(int i, int j) {
//	if (i == 0 || j == 0) {
//		return i + j;
//	}
//	if (cost[i] > cost[j]) {
//		swap(i, j);
//	}
//	int h = clone(i);
//	rson[h] = merge(rson[h], j);
//	if (dist[lson[h]] < dist[rson[h]]) {
//		swap(lson[h], rson[h]);
//	}
//	dist[h] = dist[rson[h]] + 1;
//	return h;
//}
//struct Compare {
//	bool operator()(pair<int, double>& x, pair<int, double>& y) {
//		return x.second > y.second;
//	}
//};
//priority_queue<pair<int, double>, vector<pair<int, double>>, Compare>pq;
//void dijkstra() {
//	while (!pq.empty())pq.pop();
//	for (int i = 0; i < N; i++) {
//		dis[i] = INF;
//	}
//	dis[n] = 0;
//	pq.push({ n, 0 });
//	while (!pq.empty()) {
//		auto x = pq.top();
//		pq.pop();
//		int u = x.first;
//		double w = x.second;
//		if (!vis[u]) {
//			vis[u] = true;
//			for (int e = headr[u]; e != 0; e = nexr[e]) {
//				int v = tor[e];
//				if (dis[v] > w + weightr[e]) {
//					dis[v] = w + weightr[e];
//					path[v] = e;
//					pq.push({ v,dis[v] });
//				}
//			}
//		}
//	}
//}
//void mergeRoad() {
//	while (!pq.empty())pq.pop();
//	for (int i = 1; i <= n; i++) {
//		pq.push({ i,dis[i] });
//	}
//	dist[0] = -1;
//	while (!pq.empty()) {//这里堆的作用其实就是从近到远处理节点确保等级关系正确
//		auto t = pq.top();
//		pq.pop();
//		int u = t.first;
//		for (int e = headg[u]; e != 0; e = nexg[e]) {
//			int v = tog[e];
//			if (e != path[u]) {
//				rt[u] = merge(rt[u], init(v, weightg[e] + dis[v] - dis[u]));
//			}
//		}//合并自己的其它出边
//		if (path[u] != 0) {//合并自己的父节点
//			rt[u] = merge(rt[u], rt[tog[path[u]]]);
//		}
//	}
//}
//int expand() {
//	int ans = 0;
//	money -= dis[1];
//	if (money >= 0) {
//		ans++;
//		while (!pq.empty()) {
//			pq.pop();
//		}
//		if (rt[1] != 0) {
//			pq.push({ rt[1], dis[1] + cost[rt[1]] });
//		}
//		while (!pq.empty()) {
//			auto top = pq.top();
//			pq.pop();
//			int h = top.first;
//			double w = top.second;
//			money -= w;
//			if (money < 0)break;
//			ans++;
//			if (lson[h] != 0) {
//				pq.push({ lson[h], w - cost[h] + cost[lson[h]] });
//			}
//			if (rson[h] != 0) {
//				pq.push({ rson[h],w - cost[h] + cost[rson[h]] });
//			}
//			if (to[h] != 0 && rt[to[h]] != 0) {
//				pq.push({ rt[to[h]], w + cost[rt[to[h]]] });
//			}
//		}
//	}
//	return ans;
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> n >> m >> money;
//	int u, v;
//	double w;
//	for (int i = 1; i <= m; i++) {
//		cin >> u >> v >> w;
//		if (u != n) {
//			addEdgeG(u, v, w);
//			addEdgeR(v, u, w);
//		}
//	}
//	dijkstra();
//	mergeRoad();
//	int ans = expand();
//	cout << ans << '\n';
//	return 0;
//}