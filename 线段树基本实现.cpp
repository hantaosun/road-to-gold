//Ïß¶ÎÊ÷Ä£°å
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 1e5 + 10;
//int a[MAXN];
//int sum[MAXN << 2];
//int ad[MAXN << 2];
//void lazy(int i, int v, int n) {
//	sum[i] += v * n;
//	ad[i] += v;
//}
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//void down(int i,int ln,int rn) {
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
//		int mid = (l + r) / 2;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	ad[i] = 0;
//}
//int query(int jl,int jr,int l,int r,int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int ans = 0;
//	int mid = (l + r) >> 1;
//	down(i, mid - l + 1, r - mid);
//	if (jl <= mid) {
//		ans += query(jl, jr, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		ans += query(jl, jr, mid + 1, r, i << 1 | 1);
//	}
//	return ans;
//}
//void add(int jl, int jr, int v, int l, int r,int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v, r - l + 1);
//	}
//	else {
//		int mid = (l + r) >> 1;
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
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	build(1, n, 1);
//	for (int i = 1,o; i <= m; i++) {
//		cin >> o;
//		if (o == 1) {
//			int x, y, k;
//			cin >> x >> y >> k;
//			add(x, y, k,1,n,1);
//		}
//		else {
//			int x, y;
//			cin >> x >> y;
//			cout << query(x, y, 1, n, 1)<<endl;
//		}
//	}
//}

//Ä£°å2
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 1e5 + 10;
//int n, q, mod;
//int a[MAXN];
//int sum[MAXN << 2];
//int ad[MAXN << 2];
//int mu[MAXN << 2];
//void lazy(int i, int a, int m, int n) {
//	if (m != 1) {
//		sum[i] = (sum[i] * m) % mod;
//		ad[i] = (ad[i] * m) % mod;
//		mu[i] = (mu[i] * m) % mod;
//	}
//	if (a != 0) {
//		sum[i] = (sum[i] + a * n) % mod;
//		ad[i] = (ad[i] + a) % mod;
//	}
//
//}
//void up(int i) {
//	sum[i] = (sum[i << 1] + sum[i << 1 | 1])%mod;
//}
//void down(int i,int ln,int rn) {
//	lazy(i << 1, ad[i], mu[i], ln);
//	lazy(i << 1 | 1, ad[i], mu[i], rn);
//	ad[i] = 0;
//	mu[i] = 1;
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
//	mu[i] = 1;
//}
//int query(int jl,int jr,int l,int r,int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int mid = (l + r) >> 1;
//	int ans = 0;
//	down(i, mid - l + 1, r - mid);
//	if (jl <= mid) {
//		ans = (ans + query(jl, jr, l, mid, i << 1))%mod;
//	}
//	if (jr > mid) {
//		ans = (ans + query(jl, jr, mid + 1, r, i << 1 | 1))%mod;
//	}
//	return ans;
//}
//void add(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v, 1, r - l + 1);
//	}
//	else {
//		int mid = (l + r) >> 1;
//		down(i, mid - l + 1, r - mid);
//		if (jl <= mid) {
//			add(jl, jr, v,l, mid, i << 1);
//		}
//		if (jr > mid) {
//			add(jl, jr,v, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//void mul(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, 0, v, l - r + 1);
//	}
//	else {
//		int mid = (l + r) >> 1;
//		down(i, mid - l + 1, r - mid);
//		if (jl <= mid) {
//			mul(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			mul(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//signed main() {
//	cin >> n >> q >> mod;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	build(1, n, 1);
//	for (int i = 1,o; i <= q; i++) {
//		cin >> o;
//		if (o == 1) {
//			int x, y, k;
//			cin >> x >> y >> k;
//			mul(x, y, k,1,n,1);
//		}
//		if (o == 2) {
//			int x, y, k;
//			cin >> x >> y >> k;
//			add(x, y, k, 1, n, 1);
//		}
//		if (o == 3) {
//			int x, y;
//			cin >> x >> y;
//			cout << query(x, y, 1, n, 1)<<endl;
//		}
//	}
//}