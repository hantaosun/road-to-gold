//序列操作********************************************
//不用担心优先级，下发任务时其他已有任务一定已经处理过了,
//优先级是指后来的任务可以取消前面的任务或者改变从前的任务从而影响后续下发***
//lazy中务必要修改任务信息
//#include<bits/stdc++.h>
//using namespace std;
//int n, m;
//const int MAXN = 1e5 + 10;
//int a[MAXN];
//
//int pre1[MAXN << 2];
//int suf1[MAXN << 2];
//int len1[MAXN << 2];
//
//int pre0[MAXN << 2];
//int suf0[MAXN << 2];
//int len0[MAXN << 2];
//
//int sum[MAXN << 2];
//int cha[MAXN << 2];
//int rev[MAXN << 2];
//struct info {
//	int len1,pre1,suf1;
//	info(int a, int b, int c) {
//		len1 = a;
//		pre1 = b;
//		suf1 = c;
//	}
//};
//void swap(int& a, int& b) {
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//}
//void lazy(int i, int re, int ch, int n) {
//	if (ch != -1) {
//		pre1[i] = suf1[i] = len1[i] = ch == 1 ? n : 0;
//		pre0[i] = suf0[i] = len0[i] = ch == 1 ? 0 : n;
//		sum[i] = ch * n;
//		rev[i] = 0;
//		cha[i] = ch;
//	}
//	if (re) {
//		swap(pre0[i], pre1[i]);
//		swap(suf0[i], suf1[i]);
//		swap(len0[i], len1[i]);
//		sum[i] = n - sum[i];
//		rev[i] ^= 1;
//	}
//}
//void up(int i, int ln, int rn) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//	pre1[i] = pre1[i << 1] == ln ? pre1[i << 1] + pre1[i << 1 | 1] : pre1[i << 1];
//	suf1[i] = suf1[i << 1 | 1] == rn ? suf1[i << 1] + suf1[i << 1 | 1] : suf1[i << 1 | 1];
//	len1[i] = max(suf1[i<<1]+pre1[i<<1|1],max(len1[i << 1], len1[i << 1 | 1]));
//	pre0[i] = pre0[i << 1] == ln ? pre0[i << 1] + pre0[i << 1 | 1] : pre0[i << 1];
//	suf0[i] = suf0[i << 1 | 1] == rn ? suf0[i << 1] + suf0[i << 1 | 1] : suf0[i << 1 | 1];
//	len0[i] = max(suf0[i << 1] + pre0[i << 1 | 1], max(len0[i << 1], len0[i << 1 | 1]));
//}
//void down(int i, int ln, int rn) {
//	lazy(i << 1, rev[i], cha[i], ln);
//	lazy(i << 1 | 1, rev[i], cha[i], rn);
//	rev[i] = 0;
//	cha[i] = -1;
//}
//void reverse(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, 1, -1, r - l + 1);
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i, mid - l + 1, r - mid);
//		if (jl <= mid) {
//			reverse(jl, jr, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			reverse(jl, jr, mid + 1, r, i << 1 | 1);
//		}
//		up(i, mid -l+1,r-mid);
//	}
//}
//void change(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, 0, v, r - l + 1);
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i, mid - l + 1, r - mid);
//		if (jl <= mid) {
//			change(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			change(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//		up(i, mid - l + 1, r - mid);
//	}
//}
//int queryS(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int ans = 0;
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
//info queryL(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		info in(len1[i], pre1[i], suf1[i]);
//		return in;
//	}
//	int len=0,pre=0,suf=0;
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	if (jl > mid) {
//		return queryL(jl, jr, mid+1, r, i << 1|1);
//	}
//	if (jr <=mid) {
//		return queryL(jl, jr, l, mid, i << 1);
//	}
//	info in1 = queryL(jl, jr, l, mid, i << 1);
//	info in2 = queryL(jl, jr, mid + 1, r, i << 1 | 1);
//	pre = in1.pre1==mid-max(jl,l) + 1 ? in1.pre1 + in2.pre1 : in1.pre1;
//	suf = in2.suf1==min(jr,r)-mid ? in2.suf1 + in1.suf1: in2.suf1;
//	len = max(max(in1.len1, in2.len1), in1.suf1 + in2.pre1);
//	info ans(len, pre, suf);
//	return ans;
//}
//
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = a[l];
//		pre1[i] = a[l];
//		suf1[i] = a[l];
//		len1[i] = a[l];
//		pre0[i] = 1 - a[l];
//		suf0[i] = 1 - a[l];
//		len0[i] = 1 - a[l];
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i, mid - l + 1, r - mid);
//	}
//	cha[i] = -1;
//	rev[i] = 0;
//}
//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	build(1, n, 1);
//	for (int i = 1, o, l, r; i <= m; i++) {
//		cin >> o >> l >> r;
//		l++, r++;
//		switch (o) {
//		case 0:change(l, r, 0, 1, n, 1); break;
//		case 1:change(l, r, 1, 1, n, 1); break;
//		case 2:reverse(l, r, 1, n, 1); break;
//		case 3:cout << queryS(l, r, 1, n, 1)<<endl; break;
//		case 4:cout << queryL(l, r, 1, n, 1).len1 << endl; break;
//		}
//	}
//}


//STEP
//#include<bits/stdc++.h>
//using namespace std;
//int n, q;
//const int MAXN = 2 * 1e5 + 10;
//int a[MAXN];//0为l,1为r
//int len[MAXN << 2];
//int pre[MAXN << 2];
//int suf[MAXN << 2];
//void up(int i,int l,int r) {
//	int mid = (l + r) >> 1;
//	len[i] = max(len[i << 1], len[i << 1 | 1]);
//	pre[i] = pre[i << 1];
//	suf[i] = suf[i << 1 | 1];
//	if (a[mid] != a[mid + 1]) {
//		len[i] = max(suf[i << 1] + pre[i << 1 | 1],len[i]);
//		if (pre[i<<1]==mid - l + 1) {
//			pre[i] = mid - l + 1 + pre[i << 1 | 1];
//		}
//		if (suf[i<<1|1] == r - mid) {
//			suf[i] = r - mid + suf[i << 1];
//		}
//	}
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		len[i] = 1;
//		pre[i] = 1;
//		suf[i] = 1;
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i,l,r);
//	}
//}
//void change(int x, int l, int r, int i) {
//	if (l == r) {
//		a[x] ^=1;
//		return;
//	}
//	int mid = l + r >>1;
//	if (x <=mid) {
//		change(x, l, mid, i << 1);
//	}
//	if (x > mid) {
//		change(x, mid + 1, r, i << 1|1);
//	}
//	up(i, l, r);
//}
//int main() {
//	cin >> n >> q;
//	build(1, n, 1);
//	for (int i = 1,p; i <= q; i++) {
//		cin >> p;
//		change(p, 1, n, 1);
//		cout << len[1]<< endl;
//	}
//}


//鬼子进村
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 5 * 1e4 + 10;
//int n, m;
//int pre[MAXN<<2];
//int suf[MAXN<<2];
//void up(int i,int ln,int rn) {
//	pre[i] = pre[i << 1];
//	suf[i] = suf[i << 1 | 1];
//	if (pre[i << 1] == ln) {
//		pre[i] = ln + pre[i << 1 | 1];
//	}
//	if (suf[i<<1|1] == rn) {
//		suf[i] = rn + suf[i << 1];
//	}
//}
//void change(int x,int v, int l, int r, int i) {
//	if (l == r) {
//		pre[i] = v;
//		suf[i] = v;
//	}
//	else {
//		int mid = l + r >> 1;
//		if (x > mid) {
//			change(x,v, mid + 1, r, i << 1 | 1);
//		}
//		if (x <= mid) {
//			change(x,v, l, mid, i << 1);
//		}
//		up(i, mid - l + 1, r - mid);
//	}
//}
//int query(int x,int l,int r,int i) {
//	if (l == r) {
//		return pre[i];
//	}
//	else {
//		int mid = l + r >> 1;
//		if (x > mid) {
//			if(pre[i << 1 | 1] >= x - mid)
//				return pre[i << 1 | 1] + suf[i << 1];
//			else {
//				return query(x, mid + 1, r, i << 1 | 1);
//			}
//		}
//		if (x <= mid) {
//			if(suf[i << 1] >= mid - x + 1)
//				return suf[i << 1] + pre[i << 1 | 1];
//			else {
//				return query(x, l, mid, i << 1);
//			}
//		}
//	}
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		suf[i] = 1;
//		pre[i] = 1;
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i, mid - l+1,r-mid);
//	}
//}
//int s[MAXN];
//int r = 0;
//int main() {
//	cin >> n >> m;
//	build(1,n,1);
//	for (int i = 1; i <= m; i++) {
//		char o;
//		cin >> o;
//		if (o == 'D') {
//			int x;
//			cin >> x;
//			change(x, 0, 1, n, 1);
//			s[r++] = x;
//		}
//		if (o == 'R') {
//			if (r != 0) {
//				change(s[--r], 1, 1, n, 1);
//			}
//		}
//		if (o == 'Q') {
//			int x;
//			cin >> x;
//			cout << query(x, 1, n, 1) << endl;
//		}
//	}
//}


//Hotel G
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 50010;
//int n, m;
////空房记为1 占据即为0
//int len[MAXN << 2];//空房间最长连续数
//int pre[MAXN << 2];
//int suf[MAXN << 2];
//int cha[MAXN << 2];//-1为无重置信息
//void lazy(int i, int v,int n) {
//	cha[i] = v;
//	len[i] = pre[i] = suf[i] = n * v;
//}
//void up(int i,int ln,int rn) {
//	int lson = i << 1;
//	int rson = i << 1 | 1;
//	pre[i] = pre[lson];
//	if (pre[lson] == ln) {
//		pre[i] += pre[rson];
//	}
//	suf[i] = suf[rson];
//	if (suf[rson] == rn) {
//		suf[i] += suf[lson];
//	}
//	len[i] = max(suf[lson] + pre[rson], max(len[lson], len[rson]));
//
//}
//void down(int i,int ln,int rn) {
//	if (cha[i] != -1) {
//		lazy(i << 1, cha[i], ln);
//		lazy(i << 1 | 1, cha[i], rn);
//		cha[i] = -1;
//	}
//}
//void build(int l,int r,int i) {
//	if (l == r) {
//		len[i] = suf[i] = pre[i] = 1;
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i<<1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i, mid - l + 1, r - mid);
//	}
//	cha[i] = -1;
//}
//void update(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v, r - l + 1);
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i, mid - l + 1, r - mid);
//		if (jl <= mid) {
//			update(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			update(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//		up(i, mid - l + 1, r - mid);
//	}
//}
//int query(int x,int l,int r,int i) {
//	if (l == r)return l;
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	if (len[i << 1] >= x) {
//		return query(x, l, mid, i << 1);
//	}
//	if (suf[i << 1] + pre[i << 1 | 1] >= x) {
//		return mid - suf[i << 1] + 1;
//	}
//	return query(x, mid + 1, r, i << 1 | 1);
//}
//int main() {
//	cin >> n >> m;
//	build(1, n, 1);
//	for (int i = 1,o; i <= m; i++) {
//		cin >> o;
//		if (o == 1) {
//			int x;
//			cin >> x;
//			if (len[1] < x) {
//				cout << 0 << endl;
//			}
//			else {
//				int l = query(x, 1, n, 1);
//				update(l, l + x-1, 0, 1, n, 1);
//				cout << l << endl;
//			}
//		}
//		else {
//			int x, y;
//			cin >> x >> y;
//			update(x, min(x + y - 1,n), 1, 1, n, 1);
//		}
//	}
//}