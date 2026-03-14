//开关
//还是没有深度理解
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1e5 + 10;
//int sum[MAXN << 2];//记录区间内开灯数量
//int r[MAXN << 2];
//void lazy(int i, int n) {
//	sum[i] = n - sum[i];
//	r[i] = ~r[i];
//}//注意推下去后对子节点状态的影响
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//void down(int i,int ln,int rn) {
//	if (r[i]) {
//		lazy(i << 1, ln);
//		lazy(i << 1 | 1, rn);
//		r[i] = 0;
//	}
//}
//int query(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int ans = 0;
//	int mid = (l + r)>>1;
//	down(i, mid - l + 1, r - mid);
//	if (jl <= mid) {
//		ans += query(jl, jr, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		ans += query(jl, jr, mid + 1, r, i << 1 | 1);
//	}
//	return ans;
//}
//void op(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, r - l + 1);
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i, mid - l + 1, r - mid);
//		if (jl <= mid) {
//			op(jl, jr, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			op(jl, jr, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1,c,a,b; i <= m; i++) {
//		cin >> c >> a >> b;
//		if (c == 1) {
//			cout << query(a, b, 1, n, 1)<<endl;
//		}
//		else {
//			op(a, b, 1, n, 1);
//		}
//	}
//}


//贪婪大陆***
//奇思妙想
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1e5 + 10;
//int n, m;
//int start[MAXN << 2];
//int en[MAXN << 2];
//void up(int i) {
//	start[i] = start[i << 1] + start[i << 1 | 1];
//	en[i] = en[i << 1] + en[i << 1 | 1];
//}
//void add(int x,int a,int b, int l, int r, int i) {
//	if (x==l&&x== r) {
//		start[i]+=a;
//		en[i] += b;
//	}
//	else {
//		int mid = (l + r) >> 1;
//		if (x <=mid) {
//			add(x, a, b, l, mid, i << 1);
//		}
//		else {
//			add(x, a, b, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//int queryS(int jl, int jr, int l, int r, int i) {
//	if (jr < jl)return 0;
//	if (jl <= l && jr >= r) {
//		return start[i];
//	}
//	else {
//		int mid = l + r >> 1;
//		int ans = 0;
//		if (jl <= mid) {
//			ans += queryS(jl, jr, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			ans += queryS(jl, jr, mid + 1, r, i << 1 | 1);
//		}
//		return ans;
//	}
//}
//int queryE(int jl, int jr, int l, int r, int i) {
//	if (jr < jl)return 0;
//	if (jl <= l && jr >= r) {
//		return en[i];
//	}
//	else {
//		int mid = l + r >> 1;
//		int ans = 0;
//		if (jl <= mid) {
//			ans += queryE(jl, jr, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			ans += queryE(jl, jr, mid + 1, r, i << 1 | 1);
//		}
//		return ans;
//	}
//}
//int main() {
//	cin >> n >> m;
//	for (int i = 1,q,r,l; i <= m; i++) {
//		cin >> q >> l>> r;
//		if (q == 1) {
//			add(l, 1, 0, 1, n, 1);
//			add(r, 0, 1, 1, n, 1);
//		}
//		else {
//			cout << queryS(1, r, 1, n, 1) - queryE(1, l - 1, 1, n, 1)<<endl;
//		}
//	}
//}


//无聊的数列
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 1e5 + 10;
//int n, m;
//int a[MAXN];
//int sum[MAXN << 2];
//int ad[MAXN << 2];
//void lazy(int i, int v,int n) {
//	sum[i] += v * n;
//	ad[i] += v;
//}
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//void down(int i, int ln, int rn) {
//	if (ad[i] != 0) {
//		lazy(i << 1, ad[i], ln);
//		lazy(i << 1 | 1, ad[i], rn);
//		ad[i] = 0;
//	}
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = a[l];
//	}
//	else {
//		int mid = (l + r) >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	ad[i] = 0;
//}
//void add(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v, r - l + 1);
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i,mid-l+1,r-mid);
//		if (jl <= mid) {
//			add(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			add(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//int query(int jl, int jr,int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int ans = 0;
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	if (jl <= mid) {
//		ans += query(jl, jr, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		ans += query(jl, jr, mid + 1, r, i << 1 | 1);
//	}
//	return ans;
//}
//signed main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = n; i >=2; i--) {
//		a[i] -= a[i - 1];
//	}
//	build(1,n,1);
//	for (int i = 1,opt; i <= m; i++) {
//		cin >> opt;
//		if (opt == 1) {
//			int l, r, K, D;
//			cin >> l >> r >> K >> D;
//			add(l, l, K, 1, n, 1);
//			if(l+1<=n)add(l + 1, r, D, 1, n, 1);
//			if (r + 1 <= n)add(r + 1, r + 1, -K - (r - l) * D, 1, n, 1);
//		}
//		else {
//			int p;
//			cin >> p;
//			cout << query(1, p, 1, n, 1)<<endl;
//		}
//	}
//}


//方差
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1e5 + 10;
//int n, m;
//double a[MAXN];
//double sum[MAXN << 2];
//double qsum[MAXN << 2];
//double ad[MAXN << 2];
//void lazy(int i, double v, int n) {
//	qsum[i] += 2 * sum[i] * v + v * v * n;
//	sum[i] += v * n;
//	ad[i] += v;
//}
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//	qsum[i] = qsum[i << 1] + qsum[i << 1 | 1];
//}
//void down(int i, int ln, int rn) {
//	if (ad[i] != 0) {
//		lazy(i << 1, ad[i], ln);
//		lazy(i << 1 | 1, ad[i], rn);
//		ad[i] = 0;
//	}
//}
//void add(int jl, int jr, double v, int l, int r, int i) {
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
//double queryS(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	double ans = 0;
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	if (jl <= mid) {
//		ans += queryS(jl, jr, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		ans += queryS(jl, jr, mid + 1, r, i << 1 | 1);
//	}
//	return ans;
//}
//double queryQS(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return qsum[i];
//	}
//	double ans = 0;
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	if (jl <= mid) {
//		ans += queryQS(jl, jr, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		ans += queryQS(jl, jr, mid + 1, r, i << 1 | 1);
//	}
//	return ans;
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = a[l];
//		qsum[i] = a[l] * a[l];
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i<<1);
//		build(mid + 1, r, i<< 1|1);
//		up(i);
//	}
//	ad[i] = 0;
//}
//int main() {
//	cout << fixed<<setprecision(4);
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	build(1, n, 1);
//	for (int i = 1; i <= m; i++) {
//		double k;
//		int x, y, o;
//		cin >> o;
//		if (o== 1) {
//			cin >> x>>y>>k;
//			add(x, y, k, 1, n, 1);
//		}
//		else if (o == 2) {
//			cin >> x >> y;
//			cout << queryS(x, y, 1, n, 1)/(y-x+1) << endl;
//		}
//		else {
//			cin >> x >> y;
//			double t = queryS(x, y, 1, n, 1)/double(y-x+1);
//			cout << queryQS(x, y, 1, n, 1)/double(y-x+1)-double(t*t) << endl;
//		}
//	}
//}


//色版游戏
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 1e5 + 10;
//int n, t, o;
//int color[MAXN << 2];
//int update[MAXN << 2];
//void lazy(int i, int v) {
//	color[i] = 1<<v;
//	update[i] = v;
//}
//void up(int i) {
//	color[i] = color[i << 1] | color[i << 1 | 1];
//}
//void down(int i) {
//	if (update[i] != 0) {
//		lazy(i << 1, update[i]);
//		lazy(i << 1 | 1, update[i]);
//		update[i] = 0;
//	}
//}
//void change(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v);
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i);
//		if (jl <= mid) {
//			change(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			change(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//int query(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return color[i];
//	}
//	int ans = 0;
//	int mid = l + r >> 1;
//	down(i);
//	if (jl <= mid) {
//		ans |= query(jl, jr, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		ans |= query(jl, jr, mid + 1, r, i << 1 | 1);
//	}
//	return ans;
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		color[i] = 2;
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	update[i] = 0;
//}
//signed main() {
//	cin >> n >> t >> o;
//	build(1, n, 1);
//	while (o--) {
//		char op;
//		cin >> op;
//		if (op == 'C') {
//			int a, b, c;
//			cin >> a >> b >> c;
//			if (a > b) {
//				a = a ^ b;
//				b = b ^ a;
//				a = a ^ b;
//			}
//			change(a, b, c, 1, n, 1);
//		}
//		else {
//			int a, b;
//			cin >> a >> b;
//			if (a > b) {
//				a = a ^ b;
//				b = b ^ a;
//				a = a ^ b;
//			}
//			int t = query(a, b, 1, n, 1);
//			int ans = 0;
//			while (t != 0) {
//				if (t & 1) {
//					ans++;
//				}
//				t >>= 1;
//			}
//			cout << ans << endl;
//		}
//	}
//}