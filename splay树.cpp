//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 5;
//int head = 0;
//int cnt = 0;
//int key[N];
//int fa[N];
//int lson[N];
//int rson[N];
//int siz[N];
//void up(int i) {
//	siz[i] = siz[lson[i]] + siz[rson[i]] + 1;
//}
//int lr(int i) {//判断i节点是不是其父亲节点的右孩子
//	return rson[fa[i]] == i ? 1 : 0;
//}
//void rotate(int i) {//将i节点往上旋转
//	int f = fa[i], g = fa[f], soni = lr(i), sonf = lr(f);
//	if (soni == 1) {//是父节点的右孩子进行左旋操作
//		rson[f] = lson[i];
//		if (rson[f] != 0) {
//			fa[rson[f]] = f;//注意还要额外更新fa数组的信息
//		}
//		lson[i] = f;
//	}
//	else {//进行右旋操作
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
//		else {
//			lson[g] = i;
//		}
//	}
//	fa[f] = i;
//	fa[i] = g;
//	up(f);
//	up(i);
//}
//
////提根操作,将i节点提为goal的孩子,若goal为0则提为整棵树的根
//void splay(int i, int goal) {
//	int f = fa[i], g = fa[f];
//	while (f != goal) {
//		if (g != goal) {//至少要提两次
//			if (lr(i) == lr(f)) {//一字型调整
//				rotate(f);
//			}
//			else {//z字型调整
//				rotate(i);
//			}
//		}
//		rotate(i);
//		f = fa[i];
//		g = fa[f];
//	}
//	if (goal == 0) {
//		head = i;
//	}
//}
//
//int find(int rank) {//查找排名rank的数字的节点编号
//	int i = head;
//	while (i != 0) {
//		if (siz[lson[i]] + 1 == rank) {
//			return i;
//		}
//		else if (siz[lson[i]] >= rank) {
//			i = lson[i];
//		}
//		else {
//			rank -= siz[lson[i]] + 1;
//			i = rson[i];
//		}
//	}
//	return 0;//没找到
//}
//
//void add(int num) {//加入数字
//	key[++cnt] = num;
//	siz[cnt] = 1;//先建出节点
//	if (head == 0) {
//		head = cnt;//空树,直接成为头节点即可
//	}
//	else {
//		int f = 0, i = head, son = 0;//跟踪父节点及是左孩子还是右孩子,为了最后插入做准备
//		while (i != 0) {//找插入位置
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
//		else {
//			lson[f] = cnt;
//		}
//		fa[cnt] = f;
//		splay(cnt, 0);//将新插入的节点提到头结点
//	}
//}
//int getRank(int num) {//查找数字num的排名
//	int i = head, last = head;
//	int ans = 0;
//	while (i != 0) {
//		last = i;
//		if (key[i] >= num) {
//			i = lson[i];
//		}
//		else {
//			ans += siz[lson[i]] + 1;
//			i = rson[i];
//		}
//	}
//	splay(last, 0);
//	return ans + 1;
//}
//int index(int x) {
//	int i = find(x);
//	splay(i, 0);
//	return key[i];
//}
//int pre(int num) {//这里的查询在其它树上都是可以写成递归的,但splay树要防止极端情况导致的爆栈,所以都写成了非递归形式
//	int i = head, last = head;
//	int ans = INT_MIN;
//	while (i != 0) {
//		last = i;
//		if (key[i] >= num) {
//			i = lson[i];
//		}
//		else {
//			ans = max(ans, key[i]);
//			i = rson[i];
//		}
//	}
//	splay(last, 0);
//	return ans;
//}
//int post(int num) {
//	int i = head, last = head;
//	int ans = INT_MAX;
//	while (i != 0) {
//		last = i;
//		if (key[i] <= num) {
//			i = rson[i];
//		}
//		else {
//			ans = min(ans, key[i]);
//			i = lson[i];
//		}
//	}
//	splay(last, 0);
//	return ans;
//}
//void remove(int num) {
//	int kth = getRank(num);
//	if (kth != getRank(num + 1)) {
//		int i = find(kth);
//		splay(i, 0);
//		if (lson[i] == 0) {
//			head = rson[i];
//		}
//		else if (rson[i] == 0) {
//			head = lson[i];
//		}
//		else {//此时j一定在i的右树上,因为i提到根,排名小于i的都在i的左子树,大于的都在i的右子树
//			int j = find(kth + 1);
//			splay(j, i);//j的左子树一定空
//			lson[j] = lson[i];
//			fa[lson[j]] = j;
//			up(j);
//			head = j;
//		}
//		if (head != 0) {
//			fa[head] = 0;
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n;
//	cin >> n;
//	for (int i = 1, op, x; i <= n; i++) {
//		cin >> op >> x;
//		if (op == 1) {
//			add(x);
//		}
//		else if (op == 2) {
//			remove(x);
//		}
//		else if (op == 3) {
//			cout << getRank(x)<<'\n';
//		}
//		else if (op == 4) {
//			cout << index(x) << '\n';
//		}
//		else if (op == 5) {
//			cout << pre(x) << '\n';
//		}
//		else {
//			cout << post(x) << '\n';
//		}
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 3e5 + 5;
//int head = 0;
//int cnt = 0;
//int key[N];
//int fa[N];
//int lson[N];
//int rson[N];
//int siz[N];
//int limit;
//int change = 0;
//int enter = 0;
//void up(int i) {
//	siz[i] = siz[lson[i]] + siz[rson[i]] + 1;
//}
//int lr(int i) {
//	return rson[fa[i]] == i ? 1 : 0;
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
//		else {
//			lson[g] = i;
//		}
//	}
//	fa[f] = i;
//	fa[i] = g;
//	up(f);
//	up(i);//g的尺寸信息并未变化
//}
//void splay(int i, int goal) {
//	int f = fa[i], g = fa[f];
//	while (f != goal) {
//		if (g != goal) {
//			if (lr(i) == lr(f)) {
//				rotate(f);
//			}
//			else {
//				rotate(i);
//			}
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
//		else {
//			lson[f] = cnt;
//		}
//		fa[cnt] = f;
//		splay(cnt, 0);
//	}
//}
//int index(int x) {//查找排名x的值
//	int i = head, last = head;
//	while (i != 0) {
//		last = i;
//		if (siz[lson[i]] >= x) {
//			i = lson[i];
//		}
//		else if(siz[lson[i]]+1<x) {
//			x -= siz[lson[i]] + 1;
//			i = rson[i];
//		}
//		else {
//			i = 0;
//		}
//	}
//	splay(last, 0);
//	return key[last];
//}
//void departure() {
//	int num = limit - change - 1;
//	int i = head, ans = 0;
//	//ans是大于num的最小值的下标
//	while (i != 0) {
//		if (key[i] > num) {
//			ans = i;
//			i = lson[i];
//		}
//		else {
//			i = rson[i];
//		}
//	}
//	if (ans == 0) {
//		head = 0;
//	}
//	else {
//		splay(ans, 0);//左侧的全离职了
//		lson[head] = 0;
//		up(head);
//	}
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n, x;
//	char op;
//	cin >> n >> limit;
//	for (int i = 1; i <= n; i++) {
//		cin >> op >> x;
//		if (op == 'I') {
//			if (x >= limit) {
//				enter++;
//				add(x - change);
//			}
//		}
//		else if (op == 'A') {
//			change += x;
//		}
//		else if (op == 'S') {
//			change -= x;
//			departure();
//		}
//		else if (op == 'F') {
//			if (x > siz[head]) {
//				cout << -1 << '\n';
//			}
//			else cout << index(siz[head] - x + 1) + change << '\n';
//		}
//	}
//	cout << enter - siz[head] << '\n';
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5+5;
//int head = 0;
//int cnt = 0;
//int key[N];
//int rev[N];
//int lson[N];
//int rson[N];
//int siz[N];
//int fa[N];
//void up(int i) {
//	siz[i] = siz[lson[i]] + siz[rson[i]] + 1;
//}
//void down(int i) {
//	if (rev[i]) {
//		rev[lson[i]] ^= 1;
//		rev[rson[i]] ^= 1;
//		swap(lson[i], rson[i]);
//		rev[i] = 0;
//	}
//}
//int lr(int i) {
//	return rson[fa[i]] == i ? 1 : 0;
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
//		else {
//			lson[g] = i;
//		}
//	}
//	fa[f] = i;
//	fa[i] = g;
//	up(f);//注意先后顺序
//	up(i);
//}
//void splay(int i, int goal) {
//	int f = fa[i],  g = fa[f];
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
//	fa[cnt] = head;
//	rson[head] = cnt;
//	splay(cnt, 0);
//}
//int find(int rank) {
//	int i = head;
//	while (i != 0) {
//		down(i);
//		if (siz[lson[i]] + 1 == rank) {
//			return i;
//		}
//		else if (siz[lson[i]] >= rank) {
//			i = lson[i];
//		}
//		else {
//			rank -= siz[lson[i]] + 1;
//			i = rson[i];
//		}
//	}
//	return 0;
//}
//void reverse(int l, int r) {
//	int i = find(l-1);
//	int j = find(r + 1);
//	splay(i, 0);
//	splay(j, i);
//	rev[lson[rson[head]]] ^= 1;
//}
//int sta[N];
//int si = 0;
//int ans[N];
//int ai = 0;
//void inorder() {
//	si = 0;
//	int i = head;
//	while (si != 0 || i != 0) {
//		if (i != 0) {
//			down(i);
//			sta[++si] = i;
//			i = lson[i];
//		}
//		else {
//			i = sta[si--];
//			ans[++ai] = key[i];
//			i = rson[i];
//		}
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i <= n ;i++) {
//		add(i);
//	}
//	add(0);
//	for (int i = 1,l,r; i <= m; i++) {
//		cin >> l >> r;
//		reverse(l + 1, r + 1);
//	}
//	ai = 0;
//	inorder();
//	for (int i = 2; i < ai; i++) {
//		cout << ans[i] << " ";
//	}cout << '\n';
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 80005;
//int head = 0;
//int cnt = 0;
//int num[N];
//int fa[N];
//int lson[N];
//int rson[N];
//int siz[N];
//int pos[N];
//void up(int i) {
//	siz[i] = siz[lson[i]] + siz[rson[i]] + 1;
//}
//int lr(int i) {
//	return rson[fa[i]] == i ? 1 : 0;
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
//void splay(int i, int goal) {
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
//
//}
//void add(int s) {
//	num[++cnt] = s;
//	pos[s] = cnt;
//	siz[cnt] = 1;
//	fa[cnt] = head;
//	rson[head] = cnt;
//	splay(cnt, 0);
//}
//int find(int rank) {//找到第rank名的书的索引
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
//
//int ask(int s) {//询问大于s的有几本书
//	int i = pos[s];//通过反向索引找到s,因为本题无删除操作,所以可以加上反向索引
//	splay(i, 0);//提到根节点后中序序小于s的就都在左孩子啦
//	return siz[lson[i]];
//}
//void move(int a, int b) {//其实就是通过提根操作设法改变中序遍历次序
//	int l = find(a - 1);
//	int r = find(a + 1);//找左右两边方便独立出需要的部分
//	splay(l, 0);
//	splay(r, l);
//	int i = lson[r];
//	lson[r] = 0;
//	up(r);
//	up(l);
//	l = find(b - 1);
//	r = find(b);
//	splay(l, 0);
//	splay(r, l);
//	lson[r] = i;
//	fa[i] = r;
//	up(r);
//	up(l);
//}
//int query(int s) {
//	int i = find(s);
//	splay(i, 0);
//	return num[i];
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n, m;
//	cin >> n >> m;
//	string op;
//	int s,t;
//	add(0);
//	for (int i = 1,x; i <= n; i++) {
//		cin >> x;
//		add(x);
//	}
//	add(n + 1);
//	n = n + 2;
//	for (int i = 1; i <= m; i++) {
//		cin >> op>>s;
//		int rank = ask(s) + 1;
//		if (op[0] == 'T') {
//			move(rank, 2);
//		}
//		else if (op[0] == 'B') {
//			move(rank, n - 1);
//		}
//		else if (op[0] == 'A') {
//			cout << rank - 2 << '\n';
//		}
//		else if (op[0] == 'I') {
//			cin >> t;
//			move(rank, rank + t);
//		}
//		else {
//			cout << query(s + 1)<<'\n';
//		}
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int INF = 1e9 + 1;
//const int N = 5e5 + 5;
//int head = 0;
//int arr[N];
//int num[N];
//int fa[N];
//int lson[N];
//int rson[N];
//int siz[N];
//int space[N], si;
//int sum[N];
//int all[N];
//int pre[N];
//int suf[N];
//bool upd[N];
//int cha[N];
//bool rev[N];
//void up(int i) {
//	int l = lson[i], r = rson[i];
//	siz[i] = siz[l] + siz[r] + 1;
//	sum[i] = sum[l] + sum[r] + num[i];
//	all[i] = max(max(all[l], all[r]), suf[l] + num[i] + pre[r]);
//	pre[i] = max(pre[l], sum[l] + num[i] + pre[r]);
//	suf[i] = max(suf[r], suf[l] + num[i] + sum[r]);
//}
//int lr(int i) {
//	return rson[fa[i]] == i ? 1 : 0;
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
//void splay(int i, int goal) {
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
//
//void setValue(int i, int val) {//这里默认修改的就是i的整颗子树,范围的调整是由提根操作实现的
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
//int init(int val) {
//	int i = space[si--];
//	siz[i] = 1;
//	num[i] =sum[i]=all[i]=val;
//	pre[i] = suf[i] = max(val, 0);
//	fa[i] = lson[i] = rson[i] = 0;
//	upd[i] = rev[i] = false;
//	return i;
//}
//int build(int l, int r) {//因为insert操作是插入一系列数,直接建树会比逐个插入时间更好
//	int mid = l + r >> 1;
//	int root = init(arr[mid]);
//	if (l < mid) {
//		lson[root] = build(l, mid-1);
//		fa[lson[root]] = root;
//	}
//	if (mid < r) {
//		rson[root] = build(mid + 1, r);
//		fa[rson[root]] = root;
//	}
//	up(root);
//	return root;
//}
//int find(int rank) {
//	int i = head;
//	while (i != 0) {
//		down(i);
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
//void insert(int rank, int n) {
//	if (rank == 0) {
//		head = build(1, n);
//	}
//	else {
//		int l = find(rank);
//		int r = find(rank + 1);
//		splay(l, 0);
//		splay(r, l);
//		lson[r] = build(1, n);
//		fa[lson[r]] = r;
//		up(r);
//		up(l);
//	}
//}
//
//void recycle(int i) {//回收i号空间
//	if (i != 0) {
//		space[++si] = i;
//		recycle(lson[i]);
//		recycle(rson[i]);
//	}
//}
//
//void remove(int rank, int n) {
//	int l = find(rank - 1);
//	int r = find(rank + n);
//	splay(l, 0);
//	splay(r, l);
//	recycle(lson[r]);
//	lson[r] = 0;
//	up(r);
//	up(l);
//}
//
//void reset(int rank, int n, int val) {
//	int l = find(rank - 1);
//	int r = find(rank + n);
//	splay(l, 0);
//	splay(r, l);
//	setValue(lson[r], val);
//	up(r);
//	up(l);
//}
//
//void reverse(int rank, int n) {
//	int l = find(rank - 1);
//	int r = find(rank + n);
//	splay(l, 0);
//	splay(r, l);
//	setReverse(lson[r]);
//	up(r);
//	up(l);
//}
//
//int querySum(int rank, int n) {
//	int l = find(rank - 1);
//	int r = find(rank + n);
//	splay(l, 0);
//	splay(r, l);
//	return sum[lson[r]];
//}
//int queryMax() {
//	return all[head];
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n, m;
//	cin >> n >> m;
//	si = N - 1;
//	for (int i = 1; i <= si; i++) {
//		space[i] = i;
//	}
//	for (int i = 1,j=2; i <= n; i++,j++) {
//		cin >> arr[j];
//	}
//	arr[1] = arr[n + 2] = all[0] = -INF;
//	insert(0, n + 2);
//	string op;
//	for (int i = 1,pos,len,c; i <= m; i++) {
//		cin >> op;
//		if (op[2] == 'X') {
//			cout << queryMax() << '\n';
//		}
//		else {
//			int pos, len, c;
//			cin >> pos >> len;
//			pos++;//修正索引,因为开头补了一个值
//			if (op[2] == 'S') {
//				for (int j = 1; j <= len; j++) {
//					cin >> arr[j];
//				}
//				insert(pos, len);
//			}
//			else if (op[2] == 'L') {
//				remove(pos, len);
//			}
//			else if (op[2] == 'K') {
//				cin >> c;
//				reset(pos, len, c);
//			}
//			else if (op[2] == 'V') {
//				reverse(pos, len);
//			}
//			else if (op[2] == 'T') {
//				cout << querySum(pos, len) << '\n';
//			}
//		}
//	}
//}