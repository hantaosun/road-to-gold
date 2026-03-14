//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int n, m;
//struct que {
//	int l,r,k;
//};
//vector<que>qry;
//vector<int>q;
//vector<array<int, 2>>a;
//vector<int>ans;
//int lowbit(int x) {
//	return x & (-x);
//}
//int sum[N];
//void add(int x, int v) {
//	while (x <= n) {
//		sum[x] += v;
//		x += lowbit(x);
//	}
//}
//int psum(int x) {
//	int an = 0;
//	while (x > 0) {
//		an += sum[x];
//		x -= lowbit(x);
//	}
//	return an;
//}
//int range(int l, int r) {
//	return psum(r) - psum(l - 1);
//}
//void compute(int ql, int qr, int jl, int jr) {
//	if (ql > qr)return;
//	if (jl == jr) {
//		for (int i = ql; i <=qr; i++) {
//			ans[q[i]] = a[jl][0];
//		}
//		return;
//	}
//	int mid = jl + jr >> 1;
//	for (int i = jl; i <= mid; i++) {
//		add(a[i][1], 1);
//	}
//	vector<int>lgrp;
//	vector<int>rgrp;
//	for (int i = ql; i <= qr; i++) {
//		int id = q[i];
//		int s = range(qry[id].l, qry[id].r);
//		if (s >= qry[id].k)lgrp.push_back(id);
//		else {
//			qry[id].k -= s;
//			rgrp.push_back(id);
//		}
//	}
//	for (int i = jl; i <= mid; i++) {
//		add(a[i][1], -1);
//	}
//	for (int i = 0; i < lgrp.size(); i++) {
//		q[ql + i] = lgrp[i];
//	}
//	for (int i = 0; i < rgrp.size(); i++) {
//		q[ql + lgrp.size() + i] = rgrp[i];
//	}
//	compute(ql, ql + lgrp.size()-1, jl, mid);
//	compute(ql + lgrp.size(), qr, mid + 1, jr);
//}
//int main() {
//	cin >> n >> m;
//	a.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i][0];
//		a[i][1] = i;
//	}
//	qry.resize(m + 1);
//	for (int i = 1; i <= m; i++) {
//		cin >> qry[i].l >> qry[i].r >> qry[i].k;
//	}
//	sort(a.begin() + 1, a.end(), [&](auto x, auto y) {
//		return x[0] < y[0];
//		});
//	ans.resize(m + 1);
//	q.resize(m + 1);
//	iota(q.begin(), q.end(), 0);
//	compute(1, m, 1, n);
//	for (int i = 1; i <= m; i++) {
//		cout << ans[i]<<"\n";
//	}
//}