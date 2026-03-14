//#include<bits/stdc++.h>
//using namespace std;
//const double alpha = 0.7;
//const int MAXN = 100001;
//int head = 0;
//int cnt = 0;
//int key[MAXN];
//int cont[MAXN];
//int lson[MAXN];
//int rson[MAXN];
//int siz[MAXN];//树大小(计重)
//int diff[MAXN];//树大小(不计重)
//int collect[MAXN];
//int ci;
//int top;
//int father;
//int side;
//int init(int num) {//初始化节点
//	key[++cnt] = num;
//	lson[cnt] = rson[cnt] = 0;
//	cont[cnt] = siz[cnt] = diff[cnt] = 1;
//	return cnt;
//}
//void up(int i) {
//	siz[i] = siz[lson[i]] + siz[rson[i]] + cont[i];
//	//因为删除的节点不会立马删除,而是在重构时删除所以要判断cont[i]>0
//	diff[i] = diff[lson[i]] + diff[rson[i]] + (cont[i] > 0 ? 1 : 0);
//}
//void inorder(int i) {//中序遍历收集当前子树上节点(确保有序)
//	if (i != 0) {
//		inorder(lson[i]);
//		if (cont[i] > 0) {
//			collect[++ci] = i;
//		}
//		inorder(rson[i]);
//	}
//}
//int build(int l, int r) {//重建当前子树并返回新头部
//	if (l > r) {
//		return 0;
//	}
//	int m = l + r >> 1;
//	int h = collect[m];
//	lson[h] = build(l, m - 1);
//	rson[h] = build(m + 1, r);
//	up(h);
//	return h;
//}
//void rebuild() {
//	if (top != 0) {//top记录最上方不平衡节点 father为该节点父亲编号 side为该节点是左孩子还是右孩子
//		ci = 0;//ci记录收集的最右端
//		inorder(top);
//		if (ci > 0) {
//			if (father == 0) {//top是根节点
//				head = build(1, ci);
//			}
//			else if (side == 1) {
//				lson[father] = build(1, ci);
//			}
//			else {
//				rson[father] = build(1, ci);
//			}
//		}
//	}
//}
//bool balance(int i) {
//	return alpha * (diff[i]) >= max(diff[lson[i]], diff[rson[i]]);
//}
//void add(int i, int f, int s, int num) {
//	if (i == 0) {//找到了要加入的位置
//		if (f == 0) {//当前是空树
//			head = init(num);
//		}
//		else if(s==1){
//			lson[f] = init(num);
//		}
//		else {
//			rson[f] = init(num);
//		}
//	}
//	else {
//		if (key[i] == num) {
//			cont[i]++;
//		}
//		else if (key[i] > num) {
//			add(lson[i], i, 1, num);
//		}
//		else {
//			add(rson[i], i, 2, num);
//		}
//		up(i);
//		if (!balance(i)) {//更新最上方不平衡节点
//			top = i;
//			father = f;
//			side = s;
//		}
//	}
//}
//void add(int num) {
//	top = father = side = 0;
//	add(head, 0, 0, num);
//	rebuild();
//}
//
////小于num的有几个
//int small(int i, int num) {
//	if (i == 0)return 0;
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
//
////返回排名第x的数
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
//int pre(int num) {
//	int kth = getRank(num);
//	if (kth == 1) {
//		return INT_MIN;
//	}
//	else {
//		return index(kth-1);
//	}
//}
//int post(int num) {
//	int kth = getRank(num + 1);
//	if (kth == siz[head] + 1) {
//		return INT_MAX;
//	}
//	else {
//		return index(kth);
//	}
//}
//void remove(int i, int f, int s, int num) {
//	if (key[i] == num) {
//		cont[i]--;
//	}
//	else if (key[i] > num) {
//		remove(lson[i], i, 1, num);
//	}
//	else {
//		remove(rson[i], i, 2, num);
//	}
//	up(i);
//	if (!balance(i)) {
//		top = i;
//		father = f;
//		side = s;
//	}
//}
//void remove(int num) {
//	if (getRank(num) != getRank(num + 1)) {
//		top = father = side = 0;//防止全平衡但是由于上次数据又重建了
//		remove(head, 0, 0, num);
//		rebuild();
//	}
//}
//void clear() {
//	memset(key, 0, sizeof(key));
//	memset(cont, 0, sizeof(cont));
//	memset(lson, 0, sizeof(lson));
//	memset(rson, 0, sizeof(rson));
//	memset(siz, 0, sizeof(siz));
//	memset(diff, 0, sizeof(diff));
//	cnt = head = 0;
//	
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1,op,x; i <= n; i++) {
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