//传教
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n, m;
//int lson[100000];
//int rson[100000];
//int ad[100000];
//int sum[100000];
//int cnt = 1;
//void lazy(int i,int v,int n) {
//	sum[i] += n * v;
//	ad[i] += v;
//}
//void up(int i) {
//	sum[i] = sum[lson[i]] + sum[rson[i]];
//}
//void down(int i,int ln,int rn) {
//	if (ad[i] != 0) {
//		if (lson[i] == 0)lson[i] = ++cnt;
//		lazy(lson[i], ad[i], ln);
//		if (rson[i] == 0) rson[i] = ++cnt;
//		lazy(rson[i], ad[i], rn);
//		ad[i] = 0;
//	}
//}
//void add(int jl, int jr, int v, int l, int r,int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v, r - l + 1);
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i, mid - l + 1, r - mid);
//		if (jl <= mid) {
//			if (lson[i] == 0)lson[i] = ++cnt;
//			add(jl, jr, v, l, mid, lson[i]);
//		}
//		if (jr > mid) {
//			if (rson[i] == 0)rson[i] = ++cnt;
//			add(jl, jr, v, mid + 1, r,rson[i]);
//		}
//		up(i);
//	}
//}
//int query(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int ans = 0;
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	if (jl <= mid) {
//		if(lson[i]!=0)ans += query(jl, jr, l, mid, lson[i]);
//	}
//	if (jr > mid) {
//		if (rson[i] != 0)ans += query(jl, jr, mid + 1, r, rson[i]);
//	}
//	return ans;
//}
//signed main() {
//	cin >> n >> m;
//	for (int i = 1,o; i <= m; i++) {
//		cin >> o;
//		if (o == 1) {
//			int l, r, k;
//			cin >> l >> r >> k;
//			add(l, r, k, 1, n,1);
//		}
//		else {
//			int l, r;
//			cin >> l >> r;
//			cout << query(l, r, 1, n,1)<<endl;
//		}
//	}
//}


//统计区间中的整数数目
//#include<bits/stdc++.h>
//using namespace std;
//class CountIntervals {
//public:
//    static const int n = 1000000000;
//
//    // 空间大小定成这个值是实验的结果
//    static const int LIMIT = 700001;
//    int sum[LIMIT];
//    int lson[LIMIT];
//    int rson[LIMIT];
//    int cnt = 1;
//    CountIntervals() {
//        memset(lson, 0, sizeof(lson));
//        memset(rson, 0, sizeof(rson));
//        memset(sum, 0, sizeof(sum));
//        cnt = 1;
//    }
//    void up(int i) {
//        sum[i] = sum[lson[i]] + sum[rson[i]];
//    }
//    void setOne(int jl, int jr, int l, int r, int i) {
//        if (sum[i] == r - l + 1) {
//            return;//因为只有一个操作，这样就不用传递懒信息了
//        }
//        if (jl <= l && jr >= r) {
//            sum[i] = r - l + 1;
//        }
//        else {
//            int mid = l + r >> 1;
//            if (jl <= mid) {
//                if (lson[i] == 0)lson[i] = ++cnt;
//                setOne(jl, jr, l, mid, lson[i]);
//            }
//            if (jr > mid) {
//                if (rson[i] == 0)rson[i] = ++cnt;
//                setOne(jl, jr, mid + 1, r, rson[i]);
//            }
//            up(i);
//        }
//    }
//    void add(int left, int right) {
//        setOne(left, right, 1, n, 1);
//    }
//
//    int count() {
//        return sum[1];
//    }
//};


//Gorgeous Sequence
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 1e6 + 10;
//int n, m;
//int a[MAXN];
//int Max[MAXN << 2];
//int Sem[MAXN << 2];
//int Sum[MAXN << 2];
//int Cnt[MAXN << 2];
//void lazy(int i, int v) {
//	if (v < Max[i]) {
//		Sum[i] += (v - Max[i]) * Cnt[i];
//		Max[i] = v;
//	}
//}
//void up(int i) {
//	int lson = i << 1;
//	int rson = i << 1 | 1;
//	Sum[i] = Sum[lson] + Sum[rson];
//	Max[i] = max(Max[lson], Max[rson]);
//	Cnt[i] = Max[lson] == Max[i] ? Cnt[lson] : 0 + Max[rson] == Max[i] ? Cnt[rson] : 0;
//	if (Max[lson] > Max[rson]) {
//		Cnt[i] = Cnt[lson];
//		Sem[i] = max(Sem[lson], Max[rson]);
//	}
//	else if (Max[lson] < Max[rson]) {
//		Cnt[i] = Cnt[rson];
//		Sem[i] = max(Max[lson], Sem[rson]);
//	}
//	else {
//		Cnt[i] = Cnt[lson] + Cnt[rson];
//		Sem[i] = max(Sem[lson], Sem[rson]);
//	}
//}
//void down(int i) {
//	lazy(i << 1, Max[i]);
//	lazy(i << 1 | 1, Max[i]);
//}
//void build(int l,int r,int i) {
//	if (l == r) {
//		Max[i] = a[l];
//		Sem[i] = -1;
//		Sum[i] = a[l];
//		Cnt[i] = 1;
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//}
//void setMin(int jl, int jr, int v, int l, int r, int i) {
//	if (v >= Max[i])return;
//	if (jl <= l && jr >= r&&Sem[i]<v) {
//		lazy(i, v);
//	}
//	else {
//		down(i);
//		int mid = l + r >> 1;
//		if (jl <= mid) {
//			setMin(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			setMin(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//int queryMax(int jl,int jr,int l,int r,int i) {
//	if (jl <= l && jr >= r) {
//		return Max[i];
//	}
//	int ans = INT_MIN;
//	int mid = l + r >> 1;
//	down(i);
//	if (jl <= mid) {
//		ans = max(ans, queryMax(jl, jr, l, mid, i << 1));
//	}
//	if (jr > mid) {
//		ans = max(ans, queryMax(jl, jr, mid + 1, r, i << 1 | 1));
//	}
//	return ans;
//}
//int querySum(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return Sum[i];
//	}
//	down(i);
//	int mid = l + r >> 1;
//	int ans = 0;
//	if (jl <= mid) {
//		ans += querySum(jl, jr, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		ans += querySum(jl, jr, mid + 1, r, i << 1 | 1);
//	}
//	return ans;
//}
//void solve() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	build(1, n, 1);
//	for (int i = 1,o; i <= m; i++) {
//		cin >> o;
//		if (o == 0) {
//			int x, y, t;
//			cin >> x >> y >> t;
//			setMin(x, y, t, 1, n, 1);
//		}
//		else if (o == 1) {
//			int x, y;
//			cin >> x >> y;
//			cout << queryMax(x, y, 1, n, 1) << endl;
//		}
//		else {
//			int x, y;
//			cin >> x >> y;
//			cout << querySum(x, y, 1, n, 1) << endl;
//		}
//	}
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}


//区间历史最大值的维护****
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 5 * 1e5 + 10;
//const int LOW = LLONG_MIN;
//int n, m;
//int a[MAXN];
//int Sum[MAXN << 2];
//int Max[MAXN << 2];
//int Sem[MAXN << 2];
//int Cnt[MAXN << 2];
//int MaxAdd[MAXN << 2];
//int OtherAdd[MAXN << 2];
//int MaxTop[MAXN << 2];
//int MaxAddTop[MAXN << 2];
//int OtherAddTop[MAXN << 2];
//void lazy(int i,int n,int maxAdd,int otherAdd,int maxAddTop,int otherAddTop) {
//	MaxTop[i] = max(MaxTop[i], Max[i] + maxAddTop);
//	MaxAddTop[i] = max(MaxAddTop[i], maxAddTop + MaxAdd[i]);
//	OtherAddTop[i] = max(OtherAddTop[i], otherAddTop + OtherAdd[i]);
//	OtherAdd[i] += otherAdd;
//	MaxAdd[i] += maxAdd;
//	Max[i] += maxAdd;
//	Sem[i] += Sem[i] == LOW ? 0 : otherAdd;
//	Sum[i]+= maxAdd * Cnt[i] + (n - Cnt[i]) * otherAdd;
//}
//void up(int i) {
//	int lson = i << 1;
//	int rson = i << 1 | 1;
//	MaxTop[i] = max(MaxTop[lson], MaxTop[rson]);
//	Sum[i] = Sum[lson] + Sum[rson];
//	Max[i] = max(Max[lson], Max[rson]);
//	if (Max[lson] > Max[rson]) {
//		Sem[i] = max(Sem[lson], Max[rson]);
//		Cnt[i] = Cnt[lson];
//	}
//	else if (Max[rson] > Max[lson]) {
//		Sem[i] = max(Sem[rson], Max[lson]);
//		Cnt[i] = Cnt[rson];
//	}
//	else {
//		Sem[i] = max(Sem[lson], Sem[rson]);
//		Cnt[i] = Cnt[lson] + Cnt[rson];
//	}
//}
//void down(int i,int ln,int rn) {
//	int lson = i << 1;
//	int rson = i << 1 | 1;
//	int maa = max(Max[lson], Max[rson]);
//	if (Max[lson] == maa) {
//		lazy(lson,ln, MaxAdd[i], OtherAdd[i], MaxAddTop[i], OtherAddTop[i]);
//	}
//	else {
//		lazy(lson, ln, OtherAdd[i], OtherAdd[i], OtherAddTop[i], OtherAddTop[i]);
//	}
//	if (Max[rson] == maa) {
//		lazy(rson, rn, MaxAdd[i], OtherAdd[i], MaxAddTop[i], OtherAddTop[i]);
//	}
//	else {
//		lazy(rson, rn, OtherAdd[i], OtherAdd[i], OtherAddTop[i], OtherAddTop[i]);
//	}
//	OtherAdd[i] = MaxAdd[i] = MaxAddTop[i] = OtherAddTop[i] = 0;
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		Sum[i] = Max[i] = MaxTop[i] = a[l];
//		Sem[i] = LOW;
//		Cnt[i] = 1;
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	MaxAdd[i] = OtherAdd[i] = MaxAddTop[i] = OtherAddTop[i] = 0;
//}
//void setMin(int jl, int jr, int v, int l, int r, int i) {
//	if (v >= Max[i])return;
//	if (jl <= l && jr >= r&&v>Sem[i]) {
//		lazy(i, r - l + 1, v - Max[i], 0, v - Max[i], 0);
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i, mid - l + 1, r - mid);
//		if (jl <= mid) {
//			setMin(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			setMin(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//void add(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, r -l+1 , v, v, v, v);
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
//int queryMax(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return Max[i];
//	}
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	int ans = LLONG_MIN;
//	if (jl <= mid) {
//		ans = max(ans, queryMax(jl, jr, l, mid, i << 1));
//	}
//	if (jr > mid) {
//		ans = max(ans, queryMax(jl, jr, mid + 1, r, i << 1 | 1));
//	}
//	return ans;
//}
//int querySum(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return Sum[i];
//	}
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	int ans = 0;
//	if (jl <= mid) {
//		ans+= querySum(jl, jr, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		ans += querySum(jl, jr, mid + 1, r, i << 1 | 1);
//	}
//	return ans;
//}
//int queryMaxTop(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return MaxTop[i];
//	}
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	int ans = LLONG_MIN;
//	if (jl <= mid) {
//		ans = max(ans, queryMaxTop(jl, jr, l, mid, i << 1));
//	}
//	if (jr > mid) {
//		ans = max(ans, queryMaxTop(jl, jr, mid + 1, r, i << 1 | 1));
//	}
//	return ans;
//}
//signed main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	build(1, n, 1);
//	for (int i = 1, o; i <= m; i++) {
//		cin >> o;
//		switch (o) {
//		case 1: {
//			int l, r, k;
//			cin >> l >> r >> k;
//			add(l, r, k, 1, n, 1);
//			break;
//		}
//		case 2: {
//			int l, r, k;
//			cin >> l >> r >> k;
//			setMin(l, r, k, 1, n, 1);
//			break;
//		}
//		case 3: {
//			int l, r;
//			cin >> l >> r;
//			cout << querySum(l, r, 1, n, 1)<<endl;
//			break;
//		}
//		case 4: {
//			int l, r;
//			cin >> l >> r;
//			cout << queryMax(l, r, 1, n, 1) << endl;
//			break;
//		}
//		case 5: {
//			int l, r;
//			cin >> l >> r;
//			cout << queryMaxTop(l, r, 1, n, 1) << endl;
//			break;
//		}
//		}
//	}
//}