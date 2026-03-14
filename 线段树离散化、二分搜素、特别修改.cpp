//掉落的方块
//注意边界处理
//#include<bits/stdc++.h>
//using namespace std;
//int rankk(int t, int l, int r, vector<int>& a) {
//    int ans = -1, m;
//    while (l <= r) {
//        m = l + r >> 1;
//        if (a[m] >= t) {
//            ans = m;
//            r = m - 1;
//        }
//        else {
//            l = m + 1;
//        }
//    }
//    return ans + 1;
//}
//int Max[5000];
//int Set[5000];
//void lazy(int i, int v) {
//    Set[i] = v;
//    Max[i] = v;
//}
//void up(int i) {
//    Max[i] = max(Max[i << 1], Max[i << 1 | 1]);
//}
//void down(int i) {
//    if (Set[i] != -1) {
//        lazy(i << 1, Set[i]);
//        lazy(i << 1 | 1, Set[i]);
//        Set[i] = -1;
//    }
//}
//int query(int jl, int jr, int l, int r, int i) {//查询jl-jr上最大值
//    if (jl <= l && jr >= r) {
//        return Max[i];
//    }
//    int ans = -1;
//    int mid = (l + r) >> 1;
//    down(i);
//    if (jl <= mid) {
//        ans = max(ans, query(jl, jr, l, mid, i << 1));
//    }
//    if (jr > mid) {
//        ans = max(ans, query(jl, jr, mid + 1, r, i << 1 | 1));
//    }
//    return ans;
//}
//void reset(int jl, int jr, int v, int l, int r, int i) {
//    if (jl <= l && jr >= r) {
//        lazy(i, v);
//    }
//    else {
//        int mid = (l + r) >> 1;
//        down(i);
//        if (jl <= mid) {
//            reset(jl, jr, v, l, mid, i << 1);
//        }
//        if (jr > mid) {
//            reset(jl, jr, v, mid + 1, r, i << 1 | 1);
//        }
//        up(i);
//    }
//}
//class Solution {
//public:
//    vector<int> fallingSquares(vector<vector<int>>& pos) {
//        vector<int>bi(pos.size() * 2);
//        for (int i = 0; i < pos.size(); i++) {
//            bi[2 * i] = pos[i][0];
//            bi[2 * i + 1] = pos[i][0] + pos[i][1];
//        }
//        sort(bi.begin(), bi.end());
//        int len = 0;
//        for (int i = 1; i < bi.size(); i++) {
//            if (bi[i] != bi[len]) {
//                bi[++len] = bi[i];
//            }
//        }
//        memset(Max, 0, sizeof(Max));
//        memset(Set, -1, sizeof(Set));
//        vector<int>ans(pos.size());
//        for (int i = 0; i < pos.size(); i++) {
//            int l = rankk(pos[i][0], 0, len, bi), r = rankk(pos[i][0] + pos[i][1], 0, len, bi) - 1, h = pos[i][1];
//            int t = query(l, r, 1, len, 1);
//            reset(l, r, h + t, 1, len, 1);
//            ans[i] = query(1, len, 1, len, 1);
//        }
//        return ans;
//    }
//};


//Vases and Flowers
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = (5 * 1e5) + 10;
//int n, m;
//int sum[MAXN << 2];//记录非花瓶数量
//int dis[MAXN << 2];
//int ins[MAXN << 2];
//void lazy(int i,int di,int in,int n) {
//	if (di) {
//		sum[i] = 0;
//		ins[i] = 0;
//		dis[i] = 1;
//	}
//	if (in) {
//		sum[i] = n;
//		dis[i] = 0;
//		ins[i] = 1;
//	}
//}
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//void down(int i,int ln,int rn) {
//	lazy(i << 1,dis[i],ins[i],ln);
//	lazy(i << 1 | 1,dis[i],ins[i],rn);
//	dis[i] = 0;
//	ins[i] = 0;
//}
//int query(int jl, int jr, int l, int r, int i) {
//	if (jr < jl)return 0;
//	if (jl <= l&&jr>=r) {
//		return sum[i];
//	}
//	int ans = 0;
//	int mid = l + r >> 1;
//	down(i,mid-l+1,r-mid);
//	if (jl <= mid) {
//		ans += query(jl, jr, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		ans += query(jl, jr, mid + 1, r, i << 1 | 1);
//	}
//	return ans;
//}
//void insert(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i,0,1,r-l+1);
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i, mid - l + 1, r - mid);
//		if (jl <= mid) {
//			insert(jl, jr, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			insert(jl, jr, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//void discard(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i,1,0,r-l+1);
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i, mid - l + 1, r - mid);
//		if (jl <= mid) {
//			discard(jl, jr, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			discard(jl, jr, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//int bs(int t, int l, int r) {//查询l-r上距离l最近且满足l-p之间空花瓶数量为t的位置,不存在返回最右侧空花瓶位置;
//	int begin = l;
//	int end = r;
//	int pre = query(1, l - 1, 1, n, 1);
//	int m,ans=-1;
//	while (l <= r) {
//		m = (l + r) >> 1;
//		int qm = query(1, m, 1, n, 1);
//		if (m - begin + 1 - (qm - pre) >= t) {
//			ans = m;
//			r = m - 1;
//		}
//		else {
//			l = m + 1;
//		}
//	}
//	if (ans == -1) {
//		//cout << "out bound\n";
//		ans = bs(end - begin + 1 - (query(1, end, 1, n, 1) - pre), begin, end);
//	}
//	return ans;
//}
//void solve() {
//	cin >> n >> m;
//	memset(sum, 0, sizeof(sum));
//	memset(dis, 0, sizeof(dis));
//	memset(ins, 0, sizeof(ins));
//	for (int i = 1,k,a,b; i <= m; i++) {
//		cin >> k>>a>>b;
//		a++;
//		b;
//		if (k == 1) {
//			if (query(1, n, 1, n, 1) - query(1, a - 1, 1, n, 1) == n-a+1) {
//				cout << "Can not put any one.\n";
//			}
//			else {
//				int a1 = bs(1, a, n), a2 = bs(b, a, n);
//				cout <<a1-1<<" "<<a2-1<< endl;
//				insert(a1, a2, 1, n, 1);
//			}
//		}
//		else {
//			b++;
//			cout << query(1, b, 1, n, 1) - query(1, a - 1, 1, n, 1) << endl;
//			discard(a, b, 1, n, 1);
//		}
//		//for (int i = 1; i <= n; i++) {
//		//	cout << query(i, i, 1, n, 1) << " ";
//		//}
//		//cout << endl;
//	}
//	cout << endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//开平方操作的线段树
//着重理解剪枝及为什么没有懒更新机制
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 1e5 + 10;
//int n, m;
//int a[MAXN];
//int sum[MAXN << 2];
//int Max[MAXN << 2];
//int isSqrt[MAXN << 2];
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//	Max[i] = max(Max[i << 1], Max[i << 1 | 1]);
//}
//int query(int jl,int jr,int l,int r,int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int ans = 0;
//	int mid = l + r >> 1;
//	if (jl <= mid) {
//		ans += query(jl, jr, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		ans += query(jl, jr, mid + 1, r, i << 1 | 1);
//	}
//	return ans;
//}
//void sqrt(int jl, int jr, int l, int r, int i) {
//	if (l == r) {
//		sum[i] = sqrt(sum[i]);
//		Max[i] = sum[i];
//	}
//	else {
//		if (Max[i] == 1)return;
//		int mid = l + r >> 1;
//		if (jl <= mid) {
//			sqrt(jl, jr, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			sqrt(jl, jr, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = a[l];
//		Max[i] = a[l];
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	isSqrt[i] = 0;
//}
//signed main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) { 
//		cin >> a[i];
//	}
//	build(1, n, 1);
//	cin >> m;
//	for (int i = 1,k,a,b; i <= m; i++) {
//		cin >> k>>a>>b;
//		if (a > b) {
//			a = a ^ b;
//			b = b ^ a;
//			a = a ^ b;
//		}
//		if (k == 0) {
//			sqrt(a, b, 1, n, 1);
//		}
//		else {
//			cout << query(a, b, 1, n, 1)<<endl;
//		}
//	}
//}


//The Child and Sequence
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 1e5 + 10;
//int n, m;
//int a[MAXN];
//int sum[MAXN << 2];
//int Max[MAXN << 2];
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//	Max[i] = max(Max[i << 1], Max[i << 1 | 1]);
//}
//void Mod(int jl, int jr, int x, int l, int r, int i) {
//	if (l == r) {
//		sum[i] %= x;
//		Max[i] %= x;
//	}
//	else {
//		if (Max[i] < x) return;
//		int mid = l + r >> 1;
//		if (jl <= mid) {
//			Mod(jl, jr, x, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			Mod(jl, jr, x, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//void change(int k,int x, int l, int r, int i) {
//	if (k == l && k == r) {
//		sum[i] = x;
//		Max[i] = x;
//	}
//	else {
//		int mid = l + r >> 1;
//		if (k <= mid) {
//			change(k, x, l, mid, i << 1);
//		}
//		else {
//			change(k, x, mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//}
//int query(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	else {
//		int ans = 0;
//		int mid = l + r >> 1;
//		if (jl <= mid) {
//			ans += query(jl, jr, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			ans += query(jl, jr, mid + 1, r, i << 1 | 1);
//		}
//		return ans;
//	}
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = a[l];
//		Max[i] = a[l];
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//}
//signed main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	build(1,n,1);
//	for (int i = 1,o; i <= m; i++) {
//		cin >> o;
//		if (o == 1) {
//			int l, r;
//			cin >> l >> r;
//			cout << query(l, r, 1, n, 1)<<endl;
//		}
//		else if (o == 2) {
//			int l, r, x;
//			cin >> l >> r >> x;
//			Mod(l, r, x, 1, n, 1);
//		}
//		else {
//			int k, x;
//			cin >> k >> x;
//			change(k, x, 1, n, 1);
//		}
//	}
//}


//贴海报***着重理解为什么可以没有up函数
//#include<bits/stdc++.h>
//using namespace std;
//int n, m;
//int len;
//int l[10005];
//int r[10005];
//int rankk(int t, int l, int r, vector<int>& a) {
//	int m, ans = -1;
//	while (l <= r) {
//		m = l + r >> 1;
//		if (a[m] >= t) {
//			ans = m;
//			r = m - 1;
//		}
//		else {
//			l = m + 1;
//		}
//	}
//	return ans + 1;
//}
//int id[200000];
//void down(int i) {
//	if (id[i] != 0) {
//		id[i << 1] = id[i];
//		id[i << 1 | 1] = id[i];
//		id[i] = 0;
//	}
//}
//void change(int jl, int jr,int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		id[i] = v;
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
//	}
//}
//bool visi[200000];
//int query(int jl, int jr, int l, int r, int i) {
//	if (l == r) {
//		if (id[i] != 0 && !visi[id[i]]) {
//			visi[id[i]] = 1;
//			return 1;
//		}
//		else {
//			return 0;
//		}
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i);
//		int ans = 0;
//		if (jl <= mid) {
//			ans += query(jl, jr, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			ans += query(jl, jr, mid + 1, r, i<< 1 | 1);
//		}
//		return ans;
//	}
//}
//int main() {
//	cin >> n >> m;
//	vector<int>a;
//	a.emplace_back(n);
//	for (int i = 1; i <= m; i++) {
//		cin >> l[i] >> r[i];
//		a.emplace_back(l[i]);
//		a.emplace_back(r[i]);
//	}
//	sort(a.begin(), a.end());
//	int temp = a.size();
//	for (int i = 1; i < temp; i++) {
//		if (a[i] - a[i - 1] >= 2) {
//			a.emplace_back(a[i - 1] + 1);
//		}
//	}
//	sort(a.begin(), a.end());
//	len = 0;
//	for (int i = 1; i < a.size(); i++) {
//		if (a[len] != a[i]) {
//			a[++len] = a[i];
//		}
//	}
//	for (int i = 1; i <= m; i++) {
//		l[i] = rankk(l[i], 0, len, a);
//		r[i] = rankk(r[i], 0, len, a);
//	}
//	memset(id,0,sizeof(id));
//	memset(visi, 0, sizeof(visi));
//	for (int i = 1; i <= m; i++) {
//		change(l[i],r[i], i, 1, len, 1);
//	}
//	cout<<query(1, rankk(n,0,len,a), 1, len, 1)<<endl;
//}