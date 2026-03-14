//FHQ Treap计数版
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 5;
//int head = 0;
//int cnt = 0;
//int key[N];
//int cont[N];
//int lson[N];
//int rson[N];
//int siz[N];
//double priority[N];
//void up(int i) {
//	siz[i] = siz[lson[i]] + siz[rson[i]] + cont[i];
//}
//
////按值分裂
////l是目前左树上来到的节点编号,r是目前右数上来到的节点编号
////i是当前来到哪个节点(分裂的是哪颗树),num是划分值
//void split(int l, int r, int i, int num) {
//	if (i == 0) {
//		rson[l] = lson[r] = 0;
//	}
//	else {
//		if (key[i] <= num) {//划分给左数
//			rson[l] = i;
//			split(i, r, rson[i], num);
//		}
//		else {//划分给右树
//			lson[r] = i;
//			split(l, i, lson[i], num);
//		}
//		//在后续的split过程i的子节点可能发生变化,需要更新信息
//		up(i);
//	}
//}
//int merge(int l, int r) {
//	if (l == 0 || r == 0) {
//		return l + r;//有空的则返回非空节点或空节点
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
//int find(int i, int num) {
//	if (i == 0) {
//		return 0;
//	}
//	if (key[i] == num) {
//		return i;
//	}
//	else if (key[i] > num) {
//		return find(lson[i], num);
//	}
//	else {
//		return find(rson[i], num);
//	}
//}
//void changeCount(int i, int num, int change) {
//	if (key[i] == num) {
//		cont[i] += change;
//	}
//	else if (key[i] > num) {
//		changeCount(lson[i], num, change);
//	}
//	else {
//		changeCount(rson[i], num, change);
//	}
//	up(i);
//}
//void add(int num) {
//	if (find(head, num) != 0) {
//		changeCount(head, num, 1);
//	}
//	else {
//		split(0, 0, head, num);//先按num划分
//		key[++cnt] = num;
//		cont[cnt] = siz[cnt] = 1;
//		priority[cnt] = (double)rand() / RAND_MAX;
//		head = merge(merge(rson[0], cnt), lson[0]);//通过先分裂再合并加入节点
//	}
//}
//void remove(int num) {
//	int i = find(head, num);
//	if (i != 0) {
//		if (cont[i] > 1) {
//			changeCount(head, num, -1);
//		}
//		else {
//			split(0, 0, head, num);
//			int lm = rson[0];
//			int r = lson[0];
//			split(0, 0, lm, num - 1);
//			int l = rson[0];
//			head = merge(l, r);
//		}
//	}
//}
//int small(int i, int num) {
//	if (i == 0) {
//		return 0;
//	}
//	if (key[i] >= num) {
//		return small(lson[i], num);
//	}
//	else {
//		return siz[lson[i]] + cont[i] + small(rson[i], num);
//	}
//}
//int getRank(int num) {
//	return small(head, num) + 1;
//}
//int index(int i, int x) {
//	if (siz[lson[i]] >= x) {
//		return index(lson[i], x);
//	}
//	else if (siz[lson[i]] + cont[i] < x) {
//		return index(rson[i], x - siz[lson[i]] - cont[i]);
//	}
//	return key[i];
//}
//int index(int x) {
//	return index(head, x);
//}
////返回当前树上小于num中最大的值
//int pre(int i, int num) {
//	if (i == 0) {//没找到前驱
//		return INT_MIN;
//	}
//	if (key[i] >= num) {
//		return pre(lson[i], num);
//	}
//	else {
//		return max(key[i], pre(rson[i], num));
//	}
//}
//int pre(int num) {
//	return pre(head, num);
//}
//int post(int i, int num) {
//	if (i == 0) {
//		return INT_MAX;
//	}
//	if (key[i] <= num) {
//		return post(rson[i], num);
//	}
//	else {
//		return min(key[i], post(lson[i], num));
//	}
//}
//int post(int num) {
//	return post(head, num);
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1, op, x; i <= n; i++) {
//		cin >> op >> x;
//		switch (op) {
//		case 1:add(x); break;
//		case 2:remove(x); break;
//		case 3:cout << getRank(x) << '\n'; break;
//		case 4:cout << index(x) << '\n'; break;
//		case 5:cout << pre(x) << '\n'; break;
//		case 6:cout << post(x) << '\n'; break;
//		}
//	}
//}



//FHQ Treap不计数版
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 5;
//int head = 0;
//int cnt = 0;
//int key[N];
//int lson[N];
//int rson[N];
//int siz[N];
//double priority[N];
//void up(int i) {
//	siz[i] = siz[lson[i]] + siz[rson[i]] + 1;
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
//	head = merge(merge(rson[0], cnt), lson[0]);
//}
//void remove(int num) {
//	split(0, 0, head, num);
//	int lm = rson[0];
//	int r = lson[0];
//	split(0, 0, lm, num - 1);
//	int l = rson[0];
//	int m = lson[0];
//	//合并头结点左右正好去掉头结点的num
//	head = merge(merge(l, merge(lson[m], rson[m])), r);
//}
//int getRank(int num) {
//	split(0, 0, head, num - 1);
//	int ans = siz[rson[0]] + 1;
//	head = merge(rson[0], lson[0]);
//	return ans;
//}
//int index(int i, int x) {
//	if (siz[lson[i]] >= x) {
//		return index(lson[i], x);
//	}
//	else if (siz[lson[i]] + 1 < x) {
//		return index(rson[i], x-siz[lson[i]]-1);
//	}
//	else return key[i];
//}
//int index(int x) {
//	return index(head, x);
//}
//int pre(int i, int num) {
//	if (i == 0) {
//		return INT_MIN;
//	}
//	if (key[i] >= num) {
//		return pre(lson[i], num);
//	}
//	else {
//		return max(key[i], pre(rson[i], num));
//	}
//}
//int pre(int num) {
//	return pre(head, num);
//}
//int post(int i, int num) {
//	if (i == 0) {
//		return INT_MAX;
//	}
//	if (key[i] <= num) {
//		return post(rson[i], num);
//	}
//	else {
//		return min(key[i], post(lson[i], num));
//	}
//}
//int post(int num) {
//	return post(head, num);
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	srand(time(0));
//	int n;
//	cin >> n;
//	for (int i = 1, op, x; i <= n; i++) {
//		cin >> op >> x;
//		switch (op) {
//		case 1:add(x); break;
//		case 2:remove(x); break;
//		case 3:cout<<getRank(x)<<'\n'; break;
//		case 4:cout<<index(x)<<'\n'; break;
//		case 5:cout<<pre(x)<<'\n'; break;
//		case 6:cout<<post(x)<<'\n'; break;
//		}
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e6 + 5;
//int siz[N];
//int lson[N];
//int rson[N];
//char key[N];
//double priority[N];
//int head = 0;
//int cnt = 0;
//void up(int i) {
//	siz[i] = siz[lson[i]] + siz[rson[i]] + 1;
//}
//void split(int l, int r, int i, int rank) {
//	if (i == 0) {
//		rson[l] = lson[r] = 0;
//	}
//	else {
//		if (siz[lson[i]] + 1 <= rank) {
//			rson[l] = i;
//			split(i, r, rson[i], rank - siz[lson[i]] - 1);
//		}
//		else {
//			lson[r] = i;
//			split(l, i, lson[i], rank);
//		}
//		up(i);//不能写在外面,否则会错误更新siz[0]为1,导致叶子节点up时也错误
//	}
//}
//int merge(int l,int r) {
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
//void inorder(int i) {
//	if (i == 0)return;
//	inorder(lson[i]);
//	cout << key[i];
//	inorder(rson[i]);
//}
//int main() {
//	int t;
//	cin >> t;
//	string op;
//	string s;
//	int pos = 0;
//	for (int i = 1,len; i <= t; i++) {
//		cin >> op;
//		if (op[0] == 'M') {
//			cin >> pos;
//		}
//		else if (op[0] == 'I') {
//			cin >> len;
//			split(0, 0, head, pos);
//			int l = rson[0];
//			int r = lson[0];
//			for (int j = 1; j <= len;j++ ) {
//				char ch = getchar();
//				while (ch < 32 || ch>126) {
//					ch = getchar();
//				}
//				key[++cnt] = ch;
//				siz[cnt] = 1;			
//				priority[cnt] = double(rand()) / RAND_MAX;
//				l = merge(l, cnt);
//			}
//			head = merge(l, r);
//		}
//		else if (op[0] == 'D') {
//			cin >> len;
//			split(0, 0, head, pos+len);
//			int lm = rson[0];
//			int r = lson[0];
//			split(0, 0, lm, pos);
//			int l = rson[0];
//			head = merge(l, r);
//		}
//		else if (op[0] == 'G') {
//			cin >> len;
//			split(0, 0, head, pos+len);
//			int lm = rson[0];
//			int r = lson[0];
//			split(0, 0, lm, pos);
//			int l = rson[0];
//			int m = lson[0];
//			inorder(m);
//			cout << '\n';
//			head = merge(merge(l, m), r);
//		}
//		else if (op[0] == 'P') {
//			pos--;
//		}
//		else if (op[0] == 'N') {
//			pos++;
//		}
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 10;
//int siz[N];
//int key[N];
//int lson[N];
//int rson[N];
//double priority[N];
//int lzt[N];
//int head = 0;
//int cnt = 0;
//void up(int i) {
//	siz[i] = siz[lson[i]] + siz[rson[i]] + 1;
//}
//void lazy(int i) {
//	if (i == 0)return;
//	lzt[i] ^=1;
//}
//void down(int i) {//这里down与线段树不一样,要在down时再反转下发,如果直接反转如果后续有分裂操作会导致错误
//	if (lzt[i] != 0&&i!=0) {
//		lazy(lson[i]);
//		lazy(rson[i]);
//		swap(lson[i], rson[i]);
//		lzt[i] = 0;
//	}
//}
//void split(int l, int r, int i, int rank) {
//	if (i == 0) {
//		rson[l] = lson[r] = 0;
//	}
//	else {
//		down(i);//下发懒信息！！
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
//	if (l == 0 || r == 0)return l + r;
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
//void inorder(int i) {
//	if (i == 0)return;
//	down(i);
//	inorder(lson[i]);
//	cout << key[i] << " ";
//	inorder(rson[i]);
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	srand(0);
//	for (int i = 1; i <= n; i++) {
//		key[++cnt] = i;
//		siz[cnt] = 1;
//		priority[cnt] = double(rand()) / RAND_MAX;
//		head = merge(head, cnt);
//	}
//	for (int i = 1,l,r; i <= m; i++) {
//		cin >> l >> r;
//		split(0, 0, head, r);
//		int lm = rson[0];
//		int r1 = lson[0];
//		split(0, 0, lm, l-1);
//		int l1 = rson[0];
//		int mid = lson[0];
//		lazy(mid);
//		head = merge(merge(l1, mid), r1);
//	}
//	inorder(head);
//	cout << '\n';
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 500005;
//const int M = N * 50;
//int cnt = 0;
//int head[N];
//int key[M];
//int lson[M];
//int rson[M];
//int siz[M];
//double priority[M];
//int copy(int i) {//复制i号节点,返回新节点编号
//	key[++cnt] = key[i];
//	siz[cnt] = siz[i];
//	lson[cnt] = lson[i];
//	rson[cnt] = rson[i];
//	priority[cnt] = priority[i];
//	return cnt;
//}
//void up(int i) {
//	siz[i] = siz[lson[i]] + siz[rson[i]]+1;
//}
//void split(int l, int r, int i, int num) {
//	if (i == 0) {
//		rson[l] = lson[r] = 0;
//	}
//	else {
//		i = copy(i);
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
//		l = copy(l);
//		rson[l] = merge(rson[l], r);
//		up(l);
//		return l;
//	}
//	else {
//		r = copy(r);
//		lson[r] = merge(l, lson[r]);
//		up(r);
//		return r;
//	}
//}
//void add(int v, int i, int num) {//在v版本的树上加入新版本
//	split(0, 0, i, num);
//	int r = lson[0];
//	int l = rson[0];
//	lson[0] = rson[0] = 0;
//	++cnt;
//	key[cnt] = num;
//	siz[cnt] = 1;
//	priority[cnt] = double(rand()) / RAND_MAX;
//	head[v] = merge(merge(l, cnt), r);
//}
//void remove(int v, int i, int num) {
//	split(0, 0, i, num);
//	int lm = rson[0];
//	int r = lson[0];
//	split(0, 0, lm, num-1);
//	int l = rson[0];
//	int m = lson[0];
//	lson[0] = rson[0] = 0;
//	head[v] = merge(merge(l, merge(lson[m], rson[m])),r);
//}
//int small(int i, int num) {
//	if (i == 0) {
//		return 0;
//	}
//	if (key[i] >= num) {
//		return small(lson[i], num);
//	}
//	else {
//		return siz[lson[i]] + 1 + small(rson[i], num);
//	}
//}
//int index(int i, int x) {
//	if (siz[lson[i]] >= x) {
//		return index(lson[i], x);
//	}
//	else if (siz[lson[i]] + 1 < x) {
//		return index(rson[i], x - siz[lson[i]] - 1);
//	}
//	else {
//		return key[i];
//	}
//}
//int pre(int i, int num) {
//	if (i == 0) {
//		return INT_MIN;
//	}
//	if (key[i] >= num) {
//		return pre(lson[i], num);
//	}
//	else {
//		return max(key[i], pre(rson[i], num));
//	}
//}
//int post(int i, int num) {
//	if (i == 0) {
//		return INT_MAX;
//	}
//	if (key[i] <= num) {
//		return post(rson[i], num);
//	}
//	else {
//		return min(key[i], post(lson[i], num));
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n;
//	cin >> n;
//	for (int i = 1, v, op, x; i <= n; i++) {
//		cin >> v >> op >> x;
//		if (op == 1) {
//			add(i, head[v], x);
//		}
//		else if (op == 2) {
//			remove(i, head[v], x);
//		}
//		else {
//			head[i] = head[v];
//			if (op == 3) {
//				cout << small(head[i], x) + 1 << '\n';
//			}
//			else if (op == 4) {
//				cout << index(head[i], x) << '\n';
//			}
//			else if (op == 5) {
//				cout << pre(head[i], x)<<'\n';
//			}
//			else {
//				cout << post(head[i], x)<<"\n";
//			}
//		}
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//const int M = N * 100;
//
//int cnt = 0;
//int head[N];
//int key[M];
//int lson[M];
//int rson[M];
//int siz[M];
//int rev[M];
//long long sum[M];
//double priority[M];
//int copy(int i) {
//	key[++cnt] = key[i];
//	lson[cnt] = lson[i];
//	rson[cnt] = rson[i];
//	siz[cnt] = siz[i];
//	rev[cnt] = rev[i];
//	sum[cnt] = sum[i];
//	priority[cnt] = priority[i];
//	return cnt;
//}
//void up(int i) {
//	siz[i] = siz[lson[i]] + siz[rson[i]]+1;
//	sum[i] = sum[lson[i]] + sum[rson[i]] + key[i];
//}
//void down(int i) {
//	if (rev[i]) {
//		if (lson[i] != 0) {
//			lson[i] = copy(lson[i]);
//			rev[lson[i]] ^= 1;
//		}
//		if (rson[i] != 0) {
//			rson[i] = copy(rson[i]);
//			rev[rson[i]] ^= 1;
//		}
//		swap(lson[i], rson[i]);
//		rev[i] = false;
//	}
//}
//void split(int l, int r, int i, int rank) {
//	if (i == 0) {
//		rson[l] = lson[r] = 0;
//	}
//	else {
//		i = copy(i);
//		down(i);
//		if (siz[lson[i]] + 1 <= rank) {
//			rson[l] = i;
//			split(i, r, rson[i], rank-siz[lson[i]]-1);
//		}
//		else {
//			lson[r] = i;
//			split(l, i, lson[i], rank);
//		}
//		up(i);
//	}
//}
//int merge(int l, int r) {
//	if (l == 0 || r == 0)return l + r;
//	if (priority[l] >= priority[r]) {
//		l = copy(l);
//		down(l);
//		rson[l] = merge(rson[l], r);
//		up(l);
//		return l;
//	}
//	else {
//		r = copy(r);
//		down(r);
//		lson[r] = merge(l, lson[r]);
//		up(r);
//		return r;
//	}
//}
//int main() {
//	int n;
//	cin >> n;
//	long long lastAns = 0;
//	for (int i = 1; i <= n; i++) {
//		int v, op;
//		long long x, y=0;
//		cin >> v >> op >> x;
//		x ^= lastAns;
//		if (op != 2) {
//			cin >> y;
//			y ^= lastAns;
//		}
//		int l, m, lm, r;
//		if (op == 1) {
//			split(0, 0, head[v], x);
//			l = rson[0];
//			r = lson[0];
//			lson[0] = rson[0] = 0;
//			key[++cnt] = y;
//			siz[cnt] = 1;
//			sum[cnt] = y;
//			priority[cnt] = double(rand()) / RAND_MAX;
//			head[i] = merge(merge(l, cnt), r);
//		}
//		else if (op == 2) {
//			split(0, 0, head[v], x);
//			lm = rson[0];
//			r = lson[0];
//			split(0, 0, lm, x - 1);
//			l = rson[0];
//			m = lson[0];
//			lson[0] = rson[0] = 0;
//			head[i] = merge(l, r);
//		}
//		else if(op==3){
//			split(0, 0, head[v], y);
//			lm = rson[0];
//			r = lson[0];
//			split(0, 0, lm, x - 1);
//			l = rson[0];
//			m = lson[0];
//			lson[0] = rson[0] = 0;
//			rev[m] ^= 1;
//			head[i] = merge(merge(l, m), r);
//		}
//		else {
//			split(0, 0, head[v], y);
//			lm = rson[0];
//			r = lson[0];
//			split(0, 0, lm, x - 1);
//			l = rson[0];
//			m = lson[0];
//			lson[0] = rson[0] = 0;
//			lastAns = sum[m];
//			cout << lastAns << '\n';
//			head[i] = merge(merge(l, m), r);
//		}
//	}
//}


