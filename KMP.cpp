//kmp模板
//#include<bits/stdc++.h>
//using namespace std;
//int nex[10010];
//void getNex(string t) {
//    nex[0] = -1;
//    if (t.size() == 1)return;
//    nex[1] = 0;
//    int i = 2,cn=0;
//    while (i < t.size()) {
//        if (t[i - 1] == t[cn]) {
//            nex[i++] = ++cn;
//        }
//        else if (cn > 0) {
//            cn = nex[cn];
//        }
//        else {
//            nex[i++] = 0;
//        }
//    }
//}
//int kmp(string a, string t) {
//    getNex(t);
//    int x = 0,y=0;
//    while (x < a.size() && y < t.size()) {
//        if (a[x] == t[y]) {
//            x++;
//            y++;
//        }
//        else if (y == 0) {
//            x++;
//        }
//        else {
//            y = nex[y];
//        }
//    }
//    return y == t.size() ? x-y : -1;
//}
//class Solution {
//public:
//    int strStr(string haystack, string needle) {
//        return kmp(haystack, needle);
//    }
//};


//另一颗树的子树
//#include<bits/stdc++.h>
//using namespace std;
//int a[2010];
//int t[2010];
//int cnt, cna;
//void f(int* a, TreeNode* root, int& cnt) {//序列化函数
//    a[cnt++] = root->val;
//    if (root->left != NULL) {
//        f(a, root->left, cnt);
//    }
//    else {
//        a[cnt++] = INT_MIN;
//    }
//    if (root->right != NULL) {
//        f(a, root->right, cnt);
//    }
//    else {
//        a[cnt++] = INT_MIN;
//    }
//}
//int nex[2010];
//void getNex() {
//    nex[0] = -1;
//    if (cnt == 1)return;
//    nex[1] = 0;
//    int i = 2, cn = 0;
//    while (i < cnt) {
//        if (t[i - 1] == t[cn]) {
//            nex[i++] = ++cn;
//        }
//        else if (cn > 0) {
//            cn = nex[cn];
//        }
//        else {
//            nex[i++] = 0;
//        }
//    }
//}
//bool kmp() {
//    getNex();
//    int x = 0, y = 0;
//    while (x < cna && y < cnt) {
//        if (a[x] == t[y]) {
//            x++;
//            y++;
//        }
//        else if (y == 0) {
//            x++;
//        }
//        else {
//            y = nex[y];
//        }
//    }
//    return y == cnt;
//}
//class Solution {
//public:
//    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//        cnt = 0, cna = 0;
//        f(a, root, cna);
//        f(t, subRoot, cnt);
//        return kmp();
//    }
//};


//Radio Transmission
//#include<bits/stdc++.h>
//using namespace std;
//int nex[1000010];
//string s;
//int len;
//int main() {
//	cin >> len >> s;
//	if (len == 1) {
//		cout << 1 << endl;
//		return 0;
//	}
//	nex[0] = -1;
//	nex[1] = 0;
//	int i = 2;
//	int cn = 0;
//	while (i <= len) {
//		if (s[i - 1] == s[cn]) {
//			nex[i++] = ++cn;
//		}
//		else if (cn > 0) {
//			cn = nex[cn];
//		}
//		else {
//			nex[i++] = 0;
//		}
//	}
//	cout << len - nex[len] << endl;
//}


//Censoring S
//#include<bits/stdc++.h>
//using namespace std;
//string s, t;
//char ch[1000010];
//int sty[1000010];
//int nex[1000010];
//int r = 0;
//void getNex() {
//	nex[0] = -1;
//	if (t.size() == 1)return;
//	nex[1] = 0;
//	int i = 2, cn = 0;
//	while (i < t.size()) {
//		if (t[i - 1] == t[cn]) {
//			nex[i++] = ++cn;
//		}
//		else if (cn > 0) {
//			cn = nex[cn];
//		}
//		else {
//			nex[i++] = 0;
//		}
//	}
//}
//void kmp() {
//	getNex();
//	int x = 0, y = 0;
//	while (x < s.size()) {
//		if (y == t.size()) {
//			r -= t.size();
//			if (r == 0) {
//				y = 0;
//			}
//			else {
//				y = sty[r - 1];
//			}
//		}
//		else if (s[x] == t[y]) {
//			ch[r] = s[x];
//			sty[r++] = y+1;
//			//cout << s[x] << " " << y << endl;
//			x++;
//			y++;
//		}
//		else if (y == 0) {
//			ch[r] = s[x];
//			//cout << s[x] << endl;
//			sty[r++] = 0;
//			x++;
//		}
//		else {
//			y = nex[y];
//		}
//	}
//	if (y == t.size()) {
//		r -= t.size();
//	}
//}
//int main() {
//	cin >> s >> t;
//	r = 0;
//	kmp();
//	//cout << r << endl;
//	for (int i = 0; i < r; i++) {
//		cout << ch[i] ;
//	}
//	cout << endl;
//}


//二叉树中的链表
//#include<bits/stdc++.h>
//using namespace std;
//vector<int>sub;
//vector<int>nex(120);
//void getNex() {
//	nex[0] = -1;
//	if (sub.size() == 1)return;
//	nex[1] = 0;
//	int i = 2;
//	int cn = 0;
//	while (i < sub.size()) {
//		if (sub[i - 1] == sub[cn]) {
//			nex[i++] = ++cn;
//		}
//		else if (cn > 0) {
//			cn = nex[cn];
//		}
//		else {
//			nex[i++] = 0;
//		}
//	}
//}
//bool kmp(int y, TreeNode* cur) {
//	if (y == sub.size())return true;
//	if (cur == nullptr)return false;
//	bool ans = 0;
//	while (y != -1 && sub[y] != cur->val) {
//		y = nex[y];
//	}
//	if (y != -1) {
//		if (kmp(y + 1, cur->left))return true;
//		if (kmp(y + 1, cur->right))return true;
//	}
//	else {
//		if (kmp(0, cur->left))return true;
//		if (kmp(0, cur->right))return true;
//	}
//	return ans;
//}
//class Solution {
//public:
//	bool isSubPath(ListNode* head, TreeNode* root) {
//		sub.clear();
//		for (auto i = head; i != nullptr; i = i->next) {
//			sub.push_back(i->val);
//		}
//		getNex();
//		return kmp(0, root);
//	}
//};


//找到所有好字符串
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int mod = 1e9 + 7;
//string bad, s;
//int len;
//int nex[55];
//ll dp[505][2][55];
//int pos[55][30];
//void getNex() {
//	nex[0] = -1;
//	if (bad.size() == 1)return;
//	nex[1] = 0;
//	int i = 2, cn = 0;
//	while (i < bad.size()) {
//		if (bad[i - 1] == bad[cn]) {
//			nex[i++] = ++cn;
//		}
//		else if (cn > 0) {
//			cn = nex[cn];
//		}
//		else {
//			nex[i++] = 0;
//		}
//	}
//}
//ll f(int cur, int free, int k) {
//	if (k == bad.size())return 0;
//	if (cur == len)return 1;
//	if (dp[cur][free][k] != -1)return dp[cur][free][k];
//	ll ans = 0;
//	if (free) {
//		for (int i = 0; i < 26; i++) {
//			//这里也可以记忆化
//			if (pos[k][i] != -2) {
//				ans = (ans + f(cur + 1, 1, pos[k][i] + 1)) % mod;
//			}
//			else {
//				int t = k;
//				while (t != -1 && bad[t] - 'a' != i) {
//					t = nex[t];
//				}
//				if (t != -1) {
//					ans = (ans + f(cur + 1, 1, t + 1)) % mod;
//					pos[k][i] = t;
//				}
//				else {
//					ans = (ans + f(cur + 1, 1, 0)) % mod;
//					pos[k][i] = -1;
//				}
//			}
//		}
//	}
//	else {
//		for (int i = 0; i < s[cur] - 'a'; i++) {
//			if (pos[k][i] != -2) {
//				ans = (ans + f(cur + 1, 1, pos[k][i] + 1)) % mod;
//			}
//			else {
//				int t = k;
//				while (t != -1 && bad[t] - 'a' != i) {
//					t = nex[t];
//				}
//				if (t != -1) {
//					ans = (ans + f(cur + 1, 1, t + 1)) % mod;
//					pos[k][i] = t;
//				}
//				else {
//					ans = (ans + f(cur + 1, 1, 0)) % mod;
//					pos[k][i] = -1;
//				}
//			}
//		}
//		if (pos[k][s[cur] - 'a'] != -2) {
//			ans = (ans + f(cur + 1, 0, pos[k][s[cur] - 'a'] + 1)) % mod;
//		}
//		else {
//			int t = k;
//			while (t != -1 && bad[t] - 'a' != s[cur] - 'a') {
//				t = nex[t];
//			}
//			if (t != -1) {
//				ans = (ans + f(cur + 1, 0, t + 1)) % mod;
//				pos[k][s[cur] - 'a'] = t;
//			}
//			else {
//				ans = (ans + f(cur + 1, 0, 0)) % mod;
//				pos[k][s[cur] - 'a'] = -1;
//			}
//		}
//	}
//	dp[cur][free][k] = ans;
//	return ans;
//}
//bool kmp(string s) {
//	int x = 0, y = 0;
//	while (x < s.size() && y < bad.size()) {
//		if (s[x] == bad[y]) {
//			x++;
//			y++;
//		}
//		else if (y == 0) {
//			x++;
//		}
//		else {
//			y = nex[y];
//		}
//	}
//	return y == bad.size();
//}
//class Solution {
//public:
//	int findGoodStrings(int n, string s1, string s2, string evil) {
//		memset(dp, -1, sizeof(dp));
//		for (int i = 0; i < 55; i++) {
//			for (int j = 0; j < 30; j++) {
//				pos[i][j] = -2;
//			}
//		}
//		bad = evil;
//		len = n;
//		s = s2;
//		getNex();
//		ll a1 = f(0, 0, 0);
//		s = s1;
//		memset(dp, -1, sizeof(dp));
//		ll a2 = f(0, 0, 0);
//		ll ans = (a1 + mod - a2) % mod;
//		if (!kmp(s1)) {
//			ans = (ans + 1) % mod;
//		}
//		return ans;
//	}
//};