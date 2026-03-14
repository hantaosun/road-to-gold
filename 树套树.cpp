//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1005;
//int a[N << 2][N << 2];
//int n = 1000;
//int nl = 100, nr = 200;
//void up(int rt, int i) {
//	a[rt][i] = max(a[rt][i << 1], a[rt][i << 1 | 1]);
//}
//void ininsert(int x, int v, int l, int r, int rt, int i) {
//	if (l == r) {
//		a[rt][i] = max(v, a[rt][i]);
//		return;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		ininsert(x, v, l, mid, rt, i << 1);
//	}
//	else {
//		ininsert(x, v, mid + 1, r, rt, i << 1 | 1);
//	}
//	up(rt, i);
//}
//void ouinsert(int x, int y, int v, int l, int r, int i) {
//	ininsert(y, v, 0, n, i, 1);
//	if (l == r)return;
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		ouinsert(x, y, v, l, mid, i << 1);
//	}
//	else {
//		ouinsert(x, y, v, mid + 1, r, i << 1 | 1);
//	}
//}
//int inquery(int jl, int jr, int l, int r, int rt, int i) {
//	if (jl <= l && jr >= r) {
//		return a[rt][i];
//	}
//	int ans = -1;
//	int mid = l + r >> 1;
//	if (jl <= mid) {
//		ans = max(ans, inquery(jl, jr, l, mid, rt, i << 1));
//	}
//	if (jr > mid) {
//		ans = max(ans, inquery(jl, jr, mid + 1, r, rt, i << 1 | 1));
//	}
//	return ans;
//}
//int ouquery(int jl, int jr, int jl1, int jr1, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return inquery(jl1, jr1, 0, n, i, 1);
//	}
//	int mid = l + r >> 1;
//	int ans = -1;
//	if (jl <= mid) {
//		ans = max(ans, ouquery(jl, jr, jl1, jr1, l, mid, i << 1));
//	}
//	if (jr > mid) {
//		ans = max(ans, ouquery(jl, jr, jl1, jr1, mid + 1, r, i << 1 | 1));
//	}
//	return ans;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int m;
//	cin >> m;
//	char op;
//	double h, aa, l, h1, h2, a1, a2;
//	cout << fixed << setprecision(1);
//	for (int i = 1; i <= m; i++) {
//		cin >> op;
//		if (op == 'I') {
//			cin >> h >> aa >> l;
//			ouinsert(h, aa * 10, l * 10, nl, nr, 1);
//		}
//		else {
//			cin >> h1 >> h2 >> a1 >> a2;
//			cout << ouquery(h1, h2, a1 * 10, a2 * 10, nl, nr, 1) / 10.0 << "\n";
//		}
//	}
//	cin >> m;
//	return 0;
//}


//喵喵喵
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 5e4 + 5;
//const int T = N * 230;
//int n, m,s;
//int rt[N << 2];
//int cnt = 0;
//int sum[T];
//int lson[T];
//int rson[T];
//int lzt[T];
//void up(int i) {
//	sum[i] = sum[lson[i]] + sum[rson[i]];
//}
//void lazy(int i, int v, int n) {
//	lzt[i] += v;
//	sum[i] += v * n;
//}
//void down(int i, int ln, int rn) {
//	if (lzt[i] == 0)return;
//	if (lson[i] == 0)lson[i] = ++cnt;
//	if (rson[i] == 0)rson[i] = ++cnt;
//	lazy(lson[i], lzt[i], ln);
//	lazy(rson[i], lzt[i], rn);
//	lzt[i] = 0;
//}
//vector<array<int, 4>>op;
//void ininsert(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, 1, r - l + 1);
//		return;
//	}
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	if (jl <= mid) {
//		if (lson[i] == 0)lson[i] = ++cnt;
//		ininsert(jl, jr, v, l, mid, lson[i]);
//	}
//	if (jr > mid) {
//		if (rson[i] == 0)rson[i] = ++cnt;
//		ininsert(jl, jr, v, mid + 1, r, rson[i]);
//	}
//	up(i);
//}
//void ouinsert(int x, int jl, int jr, int l, int r, int i) {
//	if (rt[i] == 0)rt[i] = ++cnt;
//	ininsert(jl, jr,1, 1, n, rt[i]);
//	if (l == r)return;
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		ouinsert(x, jl, jr, l, mid, i << 1);
//	}
//	else{
//		ouinsert(x, jl, jr, mid + 1, r, i << 1 | 1);
//	}
//}
//
//int inquery(int jl, int jr, int l, int r, int i) {
//	if (i == 0)return 0;
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	int ans = 0;
//	if (jl <= mid&&lson[i]!=0) {
//		ans += inquery(jl, jr, l, mid, lson[i]);
//	}
//	if (jr > mid&&rson[i]!=0) {
//		ans += inquery(jl, jr, mid + 1,r, rson[i]);
//	}
//	return ans;
//}
//int ouquery(int k, int jl, int jr, int l, int r, int i) {
//	if (l == r) {
//		return l;
//	}
//	int mid = l + r >> 1;
//	int rr = inquery(jl, jr, 1, n, rt[i << 1|1]);
//	if (rr < k) {
//		return ouquery(k - rr, jl, jr, l, mid, i << 1);
//	}
//	else {
//		return ouquery(k, jl, jr, mid + 1, r, i << 1 | 1);
//	}
//}
//signed main() {
//	cin >> n >> m;
//	op.resize(m + 1);
//	vector<int>vsort;
//	for (int i = 1; i <= m; i++) {
//		cin >> op[i][0] >> op[i][1] >> op[i][2] >> op[i][3];
//		if (op[i][0] == 1)vsort.push_back(op[i][3]);
//	}
//	sort(vsort.begin(), vsort.end());
//	vsort.erase(unique(vsort.begin(), vsort.end()), vsort.end());
//	s = vsort.size();
//	for (int i = 1; i <= m; i++) {
//		if (op[i][0] == 1) {
//			op[i][3] = lower_bound(vsort.begin(), vsort.end(),op[i][3]) - vsort.begin();
//			ouinsert(op[i][3], op[i][1], op[i][2], 0, s, 1);
//		}
//		else {
//			cout << vsort[ouquery(op[i][3], op[i][1], op[i][2], 0, s, 1)] << "\n";
//		}
//	}
//}



//线段树套平衡树
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 5e4 + 5;
//const int T = N * 230;
//const double ALPHA = 0.7;
//const int INF = INT_MAX;
//int n, m;
//int nn;
//int rt[N << 2];
//int lson[T];
//int rson[T];
//int cont[T];
//int key[T];
//int siz[T];
//int diff[T];
//int collect[T];
//int ci;
//int cnt = 0;
//int top, father, side;	
//vector<int>arr;
//int init(int num) {
//	int i = ++cnt;
//	key[i] = num;
//	lson[i] = rson[i] = 0;
//	cont[i] = siz[i] = diff[i] = 1;
//	return i;
//}
//bool balance(int i) {
//	return i == 0 || diff[i] * ALPHA >= max(diff[lson[i]], diff[rson[i]]);
//}
//void up(int i) {
//	siz[i] = siz[lson[i]] + siz[rson[i]] + cont[i];
//	diff[i] = diff[lson[i]] + diff[rson[i]] + (cont[i] > 0 ? 1 : 0);
//}
//int inInsert(int num, int f, int s,int i) {
//	if (i == 0) {
//		i = init(num);
//	}
//	else {
//		if (key[i] == num) {
//			cont[i]++;
//		}
//		else if(key[i]>num) {
//			lson[i]=inInsert(num, i, 0, lson[i]);
//		}
//		else {
//			rson[i] = inInsert(num, i, 1, rson[i]);
//		}
//		up(i);
//		if (!balance(i)) {
//			top = i, father = f, side = s;
//		}
//	}
//	return i;
//}
//void inorder(int i) {
//	if (!i)return;
//	inorder(lson[i]);
//	if (cont[i] > 0) {
//		collect[++ci] = i;
//	}
//	inorder(rson[i]);
//}
//int inBuild(int l, int r) {
//	if (l > r)return 0;
//	int mid = l + r >> 1;
//	int h = collect[mid];
//	lson[h] = inBuild(l, mid - 1);
//	rson[h] = inBuild(mid+1, r);
//	up(h);
//	return h;
//}
//int inRebuild(int i) {
//	if (top) {
//		ci = 0;
//		inorder(top);
//		if (ci > 0) {
//			if (father == 0) {
//				i = inBuild(1, ci);
//			}
//			else if(side==0){
//				lson[father] = inBuild(1, ci);
//			}
//			else {
//				rson[father] = inBuild(1, ci);
//			}
//		}
//	}
//	return i;
//}
//int inInsert(int num,int h) {
//	top = father = side = 0;
//	h = inInsert(num, 0, 0, h);
//	h = inRebuild(h);
//	return h;
//}
//int inSmall(int num, int i) {
//	if (!i)return 0;
//	if (key[i] >= num)return inSmall(num, lson[i]);
//	else return siz[lson[i]] + cont[i] + inSmall(num, rson[i]);
//}
//int inIndex(int k,int i){//查找排名为k的数字
//	if (siz[lson[i]] >= k) {
//		return inIndex(k, lson[i]);
//	}
//	else if (siz[lson[i]] + cont[i] < k) {
//		return inIndex(k - siz[lson[i]] - cont[i], rson[i]);
//	}
//	return key[i];
//}
//int inPre(int num, int i) {
//	int kth = inSmall(num, i) + 1;//num的排名
//	if (kth == 1)return -INF;
//	return inIndex(kth - 1, i);
//}
//int inPost(int num, int i) {
//	int kth = inSmall(num+1, i);
//	if (kth == siz[i])return INF;
//	return inIndex(kth +1, i);
//}
//void inRemove(int num, int f,int s,int i) {
//	if (key[i] == num) {
//		cont[i]--;
//	}
//	else if (key[i] > num) {
//		inRemove(num, i, 0, lson[i]);
//	}
//	else inRemove(num, i, 1, rson[i]);
//	up(i);
//	if (!balance(i)) {
//		top = i;
//		father = f;
//		side = s;
//	}
//}
//int inRemove(int num, int i) {
//	if (inSmall(num,i) != inSmall(num + 1,i)) {
//		top = father = side = 0;
//		inRemove(num, 0, 0, i);
//		i = inRebuild(i);
//	}
//	return i;
//}
//void ouInsert(int x,int v, int l, int r, int i) {
//	rt[i]=inInsert(v, rt[i]);
//	if (l >= r)return;
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		ouInsert(x, v, l, mid, i << 1);
//	}
//	else {
//		ouInsert(x, v, mid + 1, r, i << 1 | 1);
//	}
//}
//void upd(int x, int v, int l, int r, int i) {
//	rt[i] = inRemove(arr[x], rt[i]);
//	rt[i] = inInsert(v, rt[i]);
//	if (l == r)return;
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		upd(x, v, l, mid, i << 1);
//	}
//	else{
//		upd(x, v, mid + 1, r, i << 1 | 1);
//	}
//}
//int small(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r)return inSmall(v, rt[i]);
//	int mid = l + r >> 1;
//	int ans = 0;
//	if (jl <= mid) {
//		ans += small(jl, jr, v, l, mid, i << 1);
//	}
//	if(jr>mid){
//		ans += small(jl, jr, v, mid + 1, r, i << 1 | 1);
//	}
//	return ans;
//}
//int number(int jl, int jr, int k) {
//	int l = 0, r = 100000000, mid, ans = 0;
//	while (l <= r) {
//		mid = l + r >> 1;
//		if (small(jl, jr, mid + 1, 1, n, 1) + 1 > k) {
//			ans = mid;
//			r = mid-1;
//		}
//		else {
//			l = mid + 1;
//		}
//	}
//	return ans;
//}
//int pre(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r)return inPre(v, rt[i]);
//	int mid = l + r >> 1;
//	int ans = -INF;
//	if (jl <= mid) {
//		ans = max(ans, pre(jl, jr, v, l, mid, i << 1));
//	}
//	if (jr > mid) {
//		ans = max(ans, pre(jl, jr, v, mid + 1, r, i << 1 | 1));
//	}
//	return ans;
//}
//int post(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r)return inPost(v, rt[i]);
//	int mid = l + r >> 1;
//	int ans = INF;
//	if (jl <= mid) {
//		ans = min(ans, post(jl, jr, v, l, mid, i << 1));
//	}
//	if (jr > mid) {
//		ans = min(ans, post(jl, jr, v, mid + 1, r, i << 1 | 1));
//	}
//	return ans;
//}
//vector<vector<int>>opt;
//int main() {
//	cin >> n >> m;
//	arr.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> arr[i];
//		ouInsert(i, arr[i], 1, n, 1);
//	}
//	for (int i = 1,op,l,r,k,p; i <= m; i++) {
//		cin >> op;
//		if (op == 1) {
//			cin >> l >> r >> k;
//			cout << small(l, r, k, 1, n, 1)+1<<"\n";
//		}
//		else if (op == 2) {
//			cin >> l >> r >> k;
//			cout << number(l, r, k) << "\n";
//		}
//		else if (op == 3) {
//			cin >> p >> k;
//			upd(p, k, 1, n, 1);
//			arr[p] = k;
//		}
//		else if (op == 4) {
//			cin >> l >> r >> k;
//			cout << pre(l, r, k, 1, n, 1) << "\n";
//		}
//		else if (op == 5) {
//			cin >> l >> r >> k;
//			cout << post(l, r, k, 1, n, 1) << "\n";
//		}
//	}
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 5e4 + 5;
//const int T = N * 160;
//const int INF = 2147483647;
//int n, m, s;
//int rt[N];
//int que[N][4];
//int a[N];
//int lson[T];
//int rson[T];
//int sum[T];
//int cnt = 0;
//
//int lowbit(int x) {
//    return x & (-x);
//}
//
//void up(int i) {
//    sum[i] = sum[lson[i]] + sum[rson[i]];
//}
//
//int inAdd(int x, int v, int l, int r, int i) {
//    if (i == 0) i = ++cnt;
//    if (l == r) {
//        sum[i] += v;
//        return i;
//    }
//    int mid = l + r >> 1;
//    if (x <= mid) {
//        lson[i] = inAdd(x, v, l, mid, lson[i]);
//    }
//    else {
//        rson[i] = inAdd(x, v, mid + 1, r, rson[i]);
//    }
//    up(i);
//    return i;
//}
//
//void add(int x, int v) {
//    for (int i = x; i <= n; i += lowbit(i)) {
//        rt[i] = inAdd(a[x], v, 1, s, rt[i]);
//    }
//}
//
//void upd(int x, int v) {
//    add(x, -1);
//    a[x] = v;
//    add(x, 1);
//}
//
//int adT[N], sbT[N]; // 改为固定大小数组
//
//int querySmall(int x, int l, int r, int ra, int rb) {
//    if (l == r) return 0;
//    int mid = l + r >> 1;
//    if (x <= mid) {
//        for (int i = 1; i <= ra; i++) adT[i] = lson[adT[i]];
//        for (int i = 1; i <= rb; i++) sbT[i] = lson[sbT[i]];
//        return querySmall(x, l, mid, ra, rb);
//    }
//    else {
//        int lsum = 0;
//        for (int i = 1; i <= ra; i++) lsum += sum[lson[adT[i]]];
//        for (int i = 1; i <= rb; i++) lsum -= sum[lson[sbT[i]]];
//        for (int i = 1; i <= ra; i++) adT[i] = rson[adT[i]];
//        for (int i = 1; i <= rb; i++) sbT[i] = rson[sbT[i]];
//        return lsum + querySmall(x, mid + 1, r, ra, rb);
//    }
//}
//
//int small(int l, int r, int x) {
//    int ra = 0, rb = 0;
//    for (int i = r; i > 0; i -= lowbit(i)) adT[++ra] = rt[i];
//    for (int i = l - 1; i > 0; i -= lowbit(i)) sbT[++rb] = rt[i];
//    return querySmall(x, 1, s, ra, rb);
//}
//
//int queryIndex(int k, int l, int r, int ra, int rb) {
//    if (l == r) return l;
//    int mid = l + r >> 1;
//    int lsum = 0;
//    for (int i = 1; i <= ra; i++) lsum += sum[lson[adT[i]]];
//    for (int i = 1; i <= rb; i++) lsum -= sum[lson[sbT[i]]];
//    if (k <= lsum) {
//        for (int i = 1; i <= ra; i++) adT[i] = lson[adT[i]];
//        for (int i = 1; i <= rb; i++) sbT[i] = lson[sbT[i]];
//        return queryIndex(k, l, mid, ra, rb);
//    }
//    else {
//        for (int i = 1; i <= ra; i++) adT[i] = rson[adT[i]];
//        for (int i = 1; i <= rb; i++) sbT[i] = rson[sbT[i]];
//        return queryIndex(k - lsum, mid + 1, r, ra, rb);
//    }
//}
//
//int getIndex(int l, int r, int k) {
//    int ra = 0, rb = 0;
//    for (int i = r; i > 0; i -= lowbit(i)) adT[++ra] = rt[i];
//    for (int i = l - 1; i > 0; i -= lowbit(i)) sbT[++rb] = rt[i];
//    return queryIndex(k, 1, s, ra, rb);
//}
//
//int pre(int l, int r, int v) {
//    int rank = small(l, r, v);
//    if (rank == 0) return -INF;
//    return getIndex(l, r, rank);
//}
//
//int post(int l, int r, int v) {
//    int rank = small(l, r, v + 1);
//    if (rank == r - l + 1) return INF; // 修正：应该是 ==
//    return getIndex(l, r, rank + 1);
//}
//
//int main() {
//    cin >> n >> m;
//    vector<int> vsort;
//    for (int i = 1; i <= n; i++) {
//        cin >> a[i];
//        vsort.push_back(a[i]);
//    }
//    for (int i = 1; i <= m; i++) {
//        cin >> que[i][0] >> que[i][1] >> que[i][2];
//        if (que[i][0] != 3) cin >> que[i][3];
//        else vsort.push_back(que[i][2]); // 修改操作的值也要加入离散化
//    }
//
//    // 将所有可能的值加入离散化
//    for (int i = 1; i <= m; i++) {
//        if (que[i][0] == 4 || que[i][0] == 5) {
//            vsort.push_back(que[i][3]);
//        }
//    }
//
//    sort(vsort.begin(), vsort.end());
//    vsort.erase(unique(vsort.begin(), vsort.end()), vsort.end());
//    s = vsort.size();
//
//    // 离散化初始数组
//    for (int i = 1; i <= n; i++) {
//        a[i] = lower_bound(vsort.begin(), vsort.end(), a[i]) - vsort.begin() + 1;
//    }
//
//    // 离散化查询中的值
//    for (int i = 1; i <= m; i++) {
//        if (que[i][0] == 3) {
//            que[i][2] = lower_bound(vsort.begin(), vsort.end(), que[i][2]) - vsort.begin() + 1;
//        }
//        else if (que[i][0] != 2) {
//            que[i][3] = lower_bound(vsort.begin(), vsort.end(), que[i][3]) - vsort.begin() + 1;
//        }
//    }
//
//    // 初始化树状数组套线段树
//    for (int i = 1; i <= n; i++) {
//        add(i, 1);
//    }
//
//    for (int i = 1; i <= m; i++) {
//        int op = que[i][0], x = que[i][1], y = que[i][2], z = que[i][3];
//        if (op == 1) {
//            cout << small(x, y, z) + 1 << "\n";
//        }
//        else if (op == 2) {
//            cout << vsort[getIndex(x, y, z) - 1] << "\n";
//        }
//        else if (op == 3) {
//            upd(x, y);
//        }
//        else if (op == 4) {
//            int ans = pre(x, y, z);
//            if (ans == -INF) cout << -2147483647 << "\n";
//            else cout << vsort[ans - 1] << "\n";
//        }
//        else if (op == 5) {
//            int ans = post(x, y, z);
//            if (ans == INF) cout << 2147483647 << "\n";
//            else cout << vsort[ans - 1] << "\n";
//        }
//    }
//    return 0;
//}