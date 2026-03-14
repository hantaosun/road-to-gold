//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6;
//int lson[N];
//int rson[N];
//int height[N];
//int siz[N];
//int cont[N];
//int key[N];
//int head = 0, cnt = 0;
////���µ�ǰ�ڵ���Ϣ
//void up(int i) {
//	siz[i] = siz[lson[i]] + siz[rson[i]] + cont[i];
//	height[i] = max(height[lson[i]], height[rson[i]]) + 1;
//}
//
////����i���Ϊͷ����������,������ͷ��
//int leftRotate(int i) {
//	int r = rson[i];
//	rson[i] = lson[r];
//	lson[r] = i;
//	up(i);
//	up(r);//��ؼǵø���
//	return r;
//}
//
////����i���Ϊͷ����������,������ͷ��
//int rightRotate(int i) {
//	int l = lson[i];
//	lson[i] = rson[l];
//	rson[l] = i;
//	up(i);
//	up(l);
//	return l;
//}
//
////ά����ǰ�ڵ㼰������ƽ����,������ͷ��
//int maintain(int i) {
//	int lh = height[lson[i]];
//	int rh = height[rson[i]];
//	if (lh - rh > 1) {
//		if (height[lson[lson[i]]] >= height[rson[lson[i]]]) {
//			lson[i] = rightRotate(lson[i]);
//		}
//		else {
//			lson[i] = leftRotate(lson[i]);
//			i = rightRotate(i);
//		}
//	}
//	else if (rh - lh > 1) {
//		if (height[rson[rson[i]]] >= height[lson[rson[i]]]) {
//			rson[i] = leftRotate(rson[i]);
//		}
//		else {
//			rson[i] = rightRotate(rson[i]);
//			i = leftRotate(i);
//		}
//	}
//	return i;
//}
//
////��i�ڵ㼰�������ϼ���num��������ͷ��
//int add(int i, int num) {
//	if (i == 0) {
//		key[++cnt] = num;
//		height[cnt] = siz[cnt] = cont[cnt] = 1;
//		return cnt;
//	}
//	if (key[i] == num) {
//		cont[i]++;//siz����upʱ����
//	}
//	else if (key[i] >= num) {
//		lson[i] = add(lson[i], num);
//	}
//	else {
//		rson[i] = add(rson[i], num);
//	}
//	up(i);
//	return maintain(i);//һ��Ҫ����ά��ƽ����ͷ�ڵ�
//}
//void add(int num) {
//	head = add(head, num);
//}
//
//
////����С��num�����ĸ���
//int getRank(int i, int num) {
//	if (i == 0)return 0;
//	if (key[i] >= num) {
//		return getRank(lson[i], num);
//	}
//	else {
//		return siz[lson[i]] + cont[i] + getRank(rson[i], num);
//	}
//}
////����С��num�ĸ�����1
//int getRank(int num) {
//	return getRank(head, num) + 1;
//}
//
//int removeMostleft(int i, int mostleft) {
//	if (i == mostleft) {
//		return rson[i];
//	}
//	else {
//		lson[i] = removeMostleft(lson[i], mostleft);
//		up(i);
//		return maintain(i);
//	}
//}
//
//int remove(int i, int num) {
//	if (key[i] < num) {
//		rson[i] = remove(rson[i], num);
//	}
//	else if (key[i] > num) {
//		lson[i] = remove(lson[i], num);
//	}
//	else {
//		if (cont[i] != 1) {
//			cont[i]--;
//		}
//		else {
//			if (lson[i] == 0 && rson[i] == 0) {
//				return 0;
//			}
//			else if (lson[i] != 0 && rson[i] == 0) {
//				i = lson[i];
//			}
//			else if (lson[i] == 0 && rson[i] != 0) {
//				i = rson[i];
//			}
//			else {
//				int mostleft = rson[i];
//				while (lson[mostleft] != 0) {
//					mostleft = lson[mostleft];
//				}
//				rson[i] = removeMostleft(rson[i], mostleft);
//				lson[mostleft] = lson[i];
//				rson[mostleft] = rson[i];
//				i = mostleft;
//			}
//		}
//	}
//	up(i);
//	return maintain(i);
//}
//void remove(int num) {
//	if (getRank(num) != getRank(num + 1)) {//�ж�num�Ƿ����
//		head = remove(head, num);
//	}
//}
//
//
//int index(int i, int x) {
//	if (siz[lson[i]] >= x) {
//		return index(lson[i], x);
//	}
//	else if (siz[lson[i]] + cont[i] < x) {
//		return index(rson[i], x - siz[lson[i]] - cont[i]);
//	}
//	return key[i];
//}
////���ش�С��������Ϊx����
//int index(int x) {
//	return index(head, x);
//}
//
//int pre(int i, int num) {
//	if (i == 0) {
//		return INT_MIN;
//
//	}
//	if (key[i] >= num) {
//		return pre(lson[i], num);
//	}
//	else {
//		return max(key[i], pre(rson[i], num));
//	}
//}
////����С��num����keyֵ
//int pre(int num) {
//	return pre(head, num);
//}
//
//
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
//	for (int i = 1, opt, x; i <= n; i++) {
//		cin >> opt >> x;
//		switch (opt) {
//		case 1:add(x); break;
//		case 2:remove(x); break;
//		case 3:cout << getRank(x) << '\n'; break;
//		case 4:cout << index(x) << '\n'; break;
//		case 5:cout << pre(x) << '\n'; break;
//		case 6:cout << post(x) << '\n'; break;
//		}
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2500;
//int lson[N];
//int rson[N];
//int height[N];
//int siz[N];
//int key[N];
//int value[N];
//int cnt = 0;
//int head = 0;
//void up(int i) {
//    siz[i] = siz[lson[i]] + siz[rson[i]] + 1;
//    height[i] = max(height[lson[i]], height[rson[i]]) + 1;
//}
//int leftRotate(int i) {
//    int r = rson[i];
//    rson[i] = lson[r];
//    lson[r] = i;
//    up(i);
//    up(r);
//    return r;
//}
//int rightRotate(int i) {
//    int l = lson[i];
//    lson[i] = rson[l];
//    rson[l] = i;
//    up(i);
//    up(l);
//    return l;
//}
//int maintain(int i) {
//    int lh = height[lson[i]];
//    int rh = height[rson[i]];
//    if (lh - rh > 1) {
//        if (height[lson[lson[i]]] >= height[rson[lson[i]]]) {
//            i = rightRotate(i);
//        }
//        else {
//            lson[i] = leftRotate(lson[i]);
//            i = rightRotate(i);
//        }
//    }
//    else if (rh - lh > 1) {
//        if (height[rson[rson[i]]] >= height[lson[rson[i]]]) {
//            i = leftRotate(i);
//        }
//        else {
//            rson[i] = rightRotate(rson[i]);
//            i = leftRotate(i);
//        }
//    }
//    return i;
//}
//int add(int i, int rank, int num, int index) {
//    if (i == 0) {
//        key[++cnt] = num;
//        value[cnt] = index;
//        siz[cnt] = height[cnt] = 1;
//        return cnt;
//    }
//    if (siz[lson[i]] >= rank) {
//        lson[i] = add(lson[i], rank, num, index);
//    }
//    else {
//        rson[i] = add(rson[i], rank - siz[lson[i]] - 1, num, index);
//    }
//    up(i);
//    return maintain(i);
//}
//void add(int num, int index) {
//    head = add(head, index, num, index);
//}
//void clear() {
//    memset(key, 0, sizeof(key));
//    memset(height, 0, sizeof(height));
//    memset(lson, 0, sizeof(lson));
//    memset(rson, 0, sizeof(rson));
//    memset(siz, 0, sizeof(siz));
//    memset(value, 0, sizeof(value));
//    cnt = head = 0;
//}
//vector<vector<int>>ans;
//int cn;
//void inorder(int i) {
//    if (i == 0) {
//        return;
//    }
//    inorder(lson[i]);
//    ans[cn] = { key[i],value[i] };
//    cn++;
//    inorder(rson[i]);
//}
//class Solution {
//public:
//    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//        clear();
//        sort(people.begin(), people.end(), [&](auto x, auto y) {
//            if (x[0] == y[0])return x[1] < y[1];
//            return x[0] > y[0];
//            });
//        for (int i = 0; i < people.size(); i++) {
//            add(people[i][0], people[i][1]);
//        }
//        ans.assign(people.size(), {});
//        cn = 0;
//        inorder(head);
//        return ans;
//    }
//};

#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"hello world"<<endl;
}