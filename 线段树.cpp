//#include<bits/stdc++.h>
//#define int long long
//const int inf = 1e17;
//using namespace std;
//struct SegmentTree {
//	vector<int>mx;
//	vector<int>mxp;
//	void up(int i) {
//		if (mx[i << 1] > mx[i << 1 | 1]) {
//			mx[i] = mx[i << 1];
//			mxp[i] = mxp[i << 1];
//		}
//		else {
//			mx[i] = mx[i << 1 | 1];
//			mxp[i] = mxp[i << 1 | 1];
//		}
//	}
//	void build(int l, int r, int i, vector<int>& a) {
//		if (l == r) {
//			mx[i] = a[l];
//			mxp[i] = l;
//			return;
//		}
//		int mid = l + r >> 1;
//		build(l, mid, i << 1, a);
//		build(mid + 1, r, i << 1 | 1, a);
//		up(i);
//	}
//	void build(int l, int r, int i, vector<int>& a,vector<int>&s) {
//		if (l == r) {
//			mx[i] = a[l]+2*s[l];
//			mxp[i] = l;
//			return;
//		}
//		int mid = l + r >> 1;
//		build(l, mid, i << 1, a,s);
//		build(mid + 1, r, i << 1 | 1, a,s);
//		up(i);
//	}
//	void upd(int x, int v, int l, int r, int i) {
//		if (l == r) {
//			mx[i] = v;
//			return;
//		}
//		int mid = l + r >> 1;
//		if (x <= mid) {
//			upd(x, v, l, mid, i << 1);
//		}
//		if (x > mid) {
//			upd(x, v, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//	array<int, 2> query(int jl, int jr, int l, int r, int i) {
//		if (jl > jr)return { INT_MIN,-1 };
//		if (jl <= l && jr >= r) {
//			return { mx[i],mxp[i] };
//		}
//		int mid = l + r >> 1;
//		array<int, 2>ans = { INT_MIN,-1 };
//		if (jl <= mid) {
//			auto t = query(jl, jr, l, mid, i << 1);
//			if (ans[0] < t[0]) {
//				ans = t;
//			}
//		}
//		if (jr > mid) {
//			auto t = query(jl, jr, mid + 1, r, i << 1 | 1);
//			if (ans[0] < t[0]) {
//				ans = t;
//			}
//		}
//		return ans;
//	}
//	SegmentTree(int n,vector<int>&a) {
//		mx.resize((n << 2) + 5);
//		mxp.resize((n << 2) + 5);
//		build(1, n, 1, a);
//	}
//	SegmentTree(int n,vector<int>&a,vector<int>&s) {
//		mx.resize((n << 2) + 5);
//		mxp.resize((n << 2) + 5);
//		build(1, n, 1, a,s);
//	}
//};
//signed main() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	vector<int>s(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> s[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	SegmentTree tr1(n,a), tr2(n,a,s);
//	int r=0;//当前选择的最右侧住家序号
//	int ans = 0;//当前答案
//	for (int i = 1; i <= n; i++) {
//		//cout << r << "**\n";
//		auto t1 = tr1.query(1, r-1,1,n,1);
//		auto t2 = tr2.query(r+1, n, 1, n, 1);
//		if (t1[0] >= t2[0] - 2*s[r]) {
//			//cout << t1[0] << " " << t1[1] << "***\n";
//			ans += t1[0];
//			tr1.upd(t1[1], -inf, 1, n, 1);
//			tr2.upd(t1[1], -inf, 1, n, 1);
//			cout << ans << '\n';
//		}
//		else {
//			//cout << t2[0] << " " << t2[1] << "**\n";
//			//cout << s[r] << "^^^\n";
//			ans += t2[0] - 2*s[r];
//			r = t2[1];
//			tr2.upd(t2[1], -inf, 1, n, 1);
//			tr1.upd(t2[1], -inf, 1, n, 1);
//			cout << ans << '\n';
//		}
//	}
//}