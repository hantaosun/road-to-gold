//#include<bits/stdc++.h>
//using namespace std;
//const int N=2e5;
//int head = 0;
//int cnt = 0;
//int key[N];
//int lson[N];
//int rson[N];
//int fa[N];
//int siz[N];
//void up(int i) {
//	siz[i] = siz[lson[i]] + siz[rson[i]] + 1;
//}
//int lr(int i) {
//	return rson[fa[i]] == i;
//}
//void rotate(int i) {
//	int f = fa[i], g = fa[f], soni = lr(i), sonf = lr(f);
//	if (soni == 1) {
//		rson[f] = lson[i];
//		if (rson[f] != 0) {
//			fa[rson[f]] = f;
//		}
//		lson[i] = f;
//	}
//	else {
//		lson[f] = rson[i];
//		if (lson[f] != 0) {
//			fa[lson[f]] = f;
//		}
//		rson[i] = f;
//	}
//	if (g != 0) {
//		if (sonf == 1) {
//			rson[g] = i;
//		}
//		else lson[g] = i;
//	}
//	fa[f] = i;
//	fa[i] = g;
//	up(f);
//	up(i);
//}
//void splay(int i,int goal) {
//	int f = fa[i], g = fa[f];
//	while (f != goal) {
//		if (g != goal) {
//			if (lr(i) == lr(f)) {
//				rotate(f);
//			}
//			else rotate(i);
//		}
//		rotate(i);
//		f = fa[i];
//		g = fa[f];
//	}
//	if (goal == 0) {
//		head = i;
//	}
//}
//void add(int num) {
//	key[++cnt] = num;
//	siz[cnt] = 1;
//	if (head == 0) {
//		head = cnt;
//	}
//	else {
//		int i = head, f = 0, son = 0;
//		while (i != 0) {
//			f = i;
//			if (key[i] <= num) {
//				son = 1;
//				i = rson[i];
//			}
//			else {
//				son = 0;
//				i = lson[i];
//			}
//		}
//		if (son == 1) {
//			rson[f] = cnt;
//		}
//		else lson[f] = cnt;
//		fa[cnt] = f;
//		splay(cnt, 0);
//	}
//}
//int find(int rank) {
//	int i = head;
//	while (i != 0) {
//		if (siz[lson[i]] + 1 == rank) {
//			return i;
//		}
//		else if (siz[lson[i]] + 1 < rank) {
//			rank -= siz[lson[i]] + 1;
//			i = rson[i];
//		}
//		else i = lson[i];
//	}
//	return 0;
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1,u; i <= n; i++) {
//		cin >> u;
//		add(u);
//	}
//	int m;
//	cin >> m;
//	string op;
//	for (int i = 1,u; i <= m; i++) {
//		cin >> op;
//		if (op[0] == 'a') {
//			cin >> u;
//			add(u);
//		}
//		else {
//			cout << key[find((siz[head] + 1) / 2)] << '\n';
//		}
//	}
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5;
//int head = 0;
//int cnt = 0;
//int key[N];
//int lson[N];
//int rson[N];
//int siz[N];
//double priority[N];
//void up(int i) {
//	siz[i] = siz[lson[i]] + siz[rson[i]]+1;
//}
//void split(int l, int r, int i, int num) {
//	if (i == 0) {
//		rson[l] = lson[r] = 0;
//	}
//	else {
//		if (key[i] <= num) {
//			rson[l] = i;
//			split(i, r, rson[i], num);
//		}
//		else {
//			lson[r] = i;
//			split(l, i, lson[i], num);
//		}
//		up(i);
//	}
//}
//int merge(int l, int r) {
//	if (l == 0 || r == 0) {
//		return l + r;
//	}
//	if (priority[l] >= priority[r]) {
//		rson[l] = merge(rson[l], r);
//		up(l);
//		return l;
//	}
//	else {
//		lson[r] = merge(l, lson[r]);
//		up(r);
//		return r;
//	}
//}
//void add(int num) {
//	split(0, 0, head, num);
//	key[++cnt] = num;
//	siz[cnt] = 1;
//	priority[cnt] = double(rand()) / RAND_MAX;
//	head=merge(merge(rson[0], cnt), lson[0]);
//}
//int find(int rank) {
//	int i = head;
//	while (i != 0) {
//		if (siz[lson[i]] + 1 == rank) {
//			return i;
//		}
//		else if (siz[lson[i]] + 1 < rank) {
//			rank -= siz[lson[i]] + 1;
//			i = rson[i];
//		}
//		else i = lson[i];
//	}
//	return i;
//}
//int main() {
//	srand(time(0));
//	int n;
//	cin >> n;
//	for (int i = 1, u; i <= n; i++) {
//		cin >> u;
//		add(u);
//	}
//	int m;
//	cin >> m;
//	string op;
//	for (int i = 1,x; i <= m; i++) {
//		cin >> op;
//		if (op[0] == 'a') {
//			cin >> x;
//			add(x);
//		}
//		else {
//			cout << key[find((siz[head] + 1) / 2)] << '\n';
//		}
//	}
//}
//



//#include<bits/stdc++.h>
//using namespace std;
//
//const int N = 5e5 + 5;
//int arr[N];
//int num[N];
//int	lson[N];
//int rson[N];
//int siz[N];
//int all[N];
//int suf[N];
//int pre[N];
//int sum[N];
//double priority[N];
//bool upd[N];
//int cha[N];
//bool rev[N];
//int space[N], si;
//int head = 0;
//
//void up(int i) {
//	int l = lson[i], r = rson[i];
//	siz[i] = siz[l] + siz[r] + 1;
//	sum[i] = sum[l] + sum[r] + num[i];
//	all[i] = max(max(all[l], all[r]), suf[l] + num[i] + pre[r]);
//	pre[i] = max(pre[l], sum[l] + num[i] + pre[r]);
//	suf[i] = max(suf[r], suf[l] + num[i] + sum[r]);
//}
//void setValue(int i, int val) {
//	if (i != 0) {
//		upd[i] = true;
//		cha[i] = val;
//		num[i] = val;
//		sum[i] = siz[i] * val;
//		all[i] = max(sum[i], val);
//		pre[i] = max(sum[i], 0);
//		suf[i] = max(sum[i], 0);
//	}
//}
//void setReverse(int i) {
//	if (i != 0) {
//		swap(pre[i], suf[i]);
//		rev[i] ^= 1;
//	}
//}
//void down(int i) {
//	if (upd[i]) {
//		setValue(lson[i], cha[i]);
//		setValue(rson[i], cha[i]);
//		upd[i] = false;
//	}
//	if (rev[i]) {
//		swap(lson[i], rson[i]);
//		setReverse(lson[i]);
//		setReverse(rson[i]);
//		rev[i] = false;
//	}
//}
//void split(int l, int r, int i, int rank) {
//	if (i == 0) {
//		rson[l] = lson[r] = 0;
//	}
//	else {
//		down(i);
//		if (siz[lson[i]] + 1 <= rank) {
//			rson[l] = i;
//			split(i, r, rson[i], rank - siz[lson[i]] - 1);
//		}
//		else {
//			lson[r] = i;
//			split(l, i, lson[i], rank);
//		}
//		up(i);
//	}
//}
//int merge(int l, int r) {
//	if (l == 0 || r == 0) {
//		return l + r;
//	}
//	if (priority[l] >= priority[r]) {
//		down(l);
//		rson[l] = merge(rson[l], r);
//		up(l);
//		return l;
//	}
//	else {
//		down(r);
//		lson[r] = merge(l, lson[r]);
//		up(r);
//		return r;
//	}
//}
//int init(int val) {
//	int cnt = space[si--];
//	siz[cnt] = 1;
//	num[cnt] = sum[cnt] = all[cnt] = val;
//	pre[cnt] = suf[cnt] = max(val, 0);
//	lson[cnt] = rson[cnt] = 0;
//	upd[cnt] = rev[cnt] = 0;
//	priority[cnt] = double(rand()) / RAND_MAX;
//	return cnt;
//}
//int build(int l, int r) {
//	if (l > r)return 0;
//	int mid = l + r >> 1;
//	int root = init(arr[mid]);
//	if (l < mid) {
//		lson[root] = build(l, mid - 1);
//	}
//	if (mid < r) {
//		rson[root] = build(mid + 1, r);
//	}
//	up(root);
//	return root;
//}
//void recycle(int i) {
//	if (i != 0) {
//		space[++si] = i;
//		recycle(lson[i]);
//		recycle(rson[i]);
//	}
//}
//int find(int rank) {
//	int i = head;
//	while (i != 0) {
//		down(i);
//		if (siz[lson[i]] + 1 == rank)return i;
//		else if (siz[lson[i]] + 1 < rank) {
//			rank -= siz[lson[i]] + 1;
//			i = rson[i];
//		}
//		else i = lson[i];
//	}
//	return i;
//}
//void insert(int rank, int n) {
//	split(0, 0, head, rank);
//	int rt = build(1, n);
//	head = merge(merge(rson[0], rt), lson[0]);
//
//}
//void del(int ls, int rs) {
//	split(0, 0, head, rs);
//	int lm = rson[0];
//	int r = lson[0];
//	split(0, 0, lm, ls - 1);
//	int l = rson[0];
//	recycle(lson[0]);
//	head = merge(l, r);
//}
//void reverse(int ls, int rs) {
//	split(0, 0, head, rs);
//	int lm = rson[0];
//	int r = lson[0];
//	split(0, 0, lm, ls - 1);
//	int l = rson[0];
//	int m = lson[0];
//	setReverse(m);
//	head = merge(merge(l, m), r);
//}
//void update(int ls, int rs, int val) {
//	split(0, 0, head, rs);
//	int lm = rson[0];
//	int r = lson[0];
//	split(0, 0, lm, ls - 1);
//	int l = rson[0];
//	int m = lson[0];
//	setValue(m, val);
//	head = merge(merge(l, m), r);
//}
//int querySum(int ls, int rs) {
//	split(0, 0, head, rs);
//	int lm = rson[0];
//	int r = lson[0];
//	split(0, 0, lm, ls - 1);
//	int l = rson[0];
//	int m = lson[0];
//	int ans = sum[m];
//	head = merge(merge(l, m), r);
//	return ans;
//}
//int queryMax() {
//	return all[head];
//}
//void inorder(int i) {
//	if (i == 0)return;
//	down(i);
//	inorder(lson[i]);
//	cout << num[i] << ' ';
//	inorder(rson[i]);
//}
//int main() {
//	all[0] = -2e9;  // 空节点的最大子段和设为负无穷
//	pre[0] = 0;     // 空节点的前缀最大和为0（不选任何元素）
//	suf[0] = 0;     // 空节点的后缀最大和为0
//	sum[0] = 0;     // 空节点的和为0
//	siz[0] = 0;     // 空节点的大小为0
//	int n, m;
//	cin >> n >> m;
//	si = N - 1;
//	for (int i = 1; i <= si; i++) {
//		space[i] = i;
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> arr[i];
//	}
//	insert(0, n);
//	string op;
//	for (int i = 1; i <= m; i++) {
//		cin >> op;
//		if (op[2] == 'X') {
//			cout << queryMax() << '\n';
//		}
//		else {
//			int pos, len, c;
//			cin >> pos >> len;
//			if (op[2] == 'S') {
//				for (int j = 1; j <= len; j++) {
//					cin >> arr[j];
//				}
//				insert(pos, len);
//			}
//			else if (op[2] == 'L') {
//				del(pos, pos + len - 1);
//			}
//			else if (op[2] == 'K') {
//				cin >> c;
//				update(pos, pos + len - 1, c);
//			}
//			else if (op[2] == 'V') {
//				reverse(pos, pos + len - 1);
//			}
//			else if (op[2] == 'T') {
//				cout << querySum(pos, pos + len - 1) << '\n';
//			}
//		}
//		//inorder(head); cout << '\n';
//	}
//}