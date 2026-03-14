//逆序对
//归并分治做法
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int help[500050];
//int merge(int l, int r, vector<int>& a) {
//	int m = (l + r) / 2;
//	int cur = 0;
//	int p1 = l;
//	int p2 = m + 1;
//	int ans = 0;
//	while (p1 <= m && p2 <= r) {
//		if (a[p1] <= a[p2]) {
//			help[cur++] = a[p1];
//			ans += p2 - m-1;
//			p1++;
//		}
//		else {
//			help[cur++] = a[p2];
//			p2++;
//		}
//	}
//	while (p1 <= m) {
//		help[cur++] = a[p1];
//		ans += p2 - m - 1;
//		p1++;
//	}
//	while (p2 <= r) {
//		help[cur++] = a[p2];
//		p2++;
//	}
//	for (int i = 0; i < cur; i++) {
//		a[l + i] = help[i];
//	}
//	return ans;
//}
//int f(int l, int r, vector<int>& a) {//返回l-r上逆序对数量并使l-r上有序
//	if (l >= r)return 0;
//	int m = (l + r) / 2;
//	int ans = 0;
//	ans+=f(l, m,a);
//	ans+= f(m + 1, r, a);
//	ans+= merge(l, r, a);
//	return ans;
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n;
//	cin >> n;
//	vector<int>a(n+2);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	cout << f(1, n, a) << endl;
//}
//树状数组做法
//需要搭配离散化
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n;
//vector<int>a;
//vector<int>cnt;
//int siz;
//int lowbit(int i) {
//	return i & (-i);
//}
//void add(int i, int num) {
//	while (i <= siz) {
//		cnt[i] += num;
//		i += lowbit(i);
//	}
//}
//int sum(int i) {
//	int ans = 0;
//	while (i > 0) {
//		ans += cnt[i];
//		i -= lowbit(i);
//	}
//	return ans;
//}
//int rankk(vector<int>& lisan, int l, int r, int t) {
//	int m;
//	int ans = -1;
//	while (l <= r) {
//		m = (l + r) / 2;
//		if (lisan[m] >= t) {
//			ans = m;
//			r = m - 1;
//		}
//		else {
//			l = m + 1;
//		}
//	}
//	return ans;
//}
//signed main() {
//	cin >> n;
//	a.resize(n + 1, 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	vector<int>lisan(a.begin()+1,a.end());
//	sort(lisan.begin(), lisan.end());
//	int len = 0;
//	for (int i = 1;i<lisan.size();i++) {
//		if (lisan[len] != lisan[i])lisan[++len] = lisan[i];
//	}
//	for (int i = 1; i<=n; i++) {
//		a[i] = rankk(lisan, 0, len, a[i])+1;
//	}
//	cnt.resize(len + 2, 0);
//	siz = len + 1;
//	//cout << len << endl;
//	//for (int i : lisan)cout << i << " ";
//	//cout << endl;
//	//for (int i : a)cout << i << " ";
//	//cout << endl;
//	int ans = 0;
//	for (int i = n; i >= 1; i--) {
//		ans += sum(a[i] - 1);
//		add(a[i], 1);
//	}
//	cout << ans << endl;
//}


//三元上升子序列
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int ls[30005];//当前位置左边有几个数比该数小
//int rs[30005];//当前位置右边有几个数比该数大
//int siz;
//int lowbit(int i) {
//	return i & (-i);
//}
//void add(int i, int num,vector<int>&a) {
//	while (i <= siz) {
//		a[i] += num;
//		i += lowbit(i);
//	}
//}
//int sum(int i,vector<int>&a) {
//	int ans = 0;
//	while (i > 0) {
//		ans += a[i];
//		i -= lowbit(i);
//	}
//	return ans;
//}
//signed main() {
//	int n;
//	cin >> n;
//	vector<int>a(n+1);
//	int MAX = INT_MIN;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		MAX = max(MAX, a[i]);
//	}
//	siz = MAX;
//	vector<int>lcnt(MAX + 2,0);
//	vector<int>rcnt(MAX + 2,0);
//	for (int i = 1; i <= n; i++) {
//		ls[i] = sum(a[i] - 1,lcnt);
//		add(a[i], 1, lcnt);
//	}
//	for (int i = n; i >= 1; i--) {
//		rs[i] = n-i-sum(a[i],rcnt);
//		add(a[i], 1, rcnt);
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		ans +=ls[i]*rs[i];
//	}
//	cout << ans << endl;
//}


//最长递增子序列的个数
//#include<bits/stdc++.h>
//using namespace std;
//class Solution {
//public:
//    int findNumberOfLIS(vector<int>& nums) {
//        vector<int>ril(nums.size() + 1, 1);
//        vector<int>cnt(nums.size() + 1, 1);
//        int MAX = INT_MIN;
//        for (int i = nums.size() - 1; i >= 0; i--) {
//            for (int j = i + 1; j < nums.size(); j++) {
//                if (nums[j] > nums[i]) {
//                    if (ril[j] + 1 > ril[i]) {
//                        ril[i] = ril[j] + 1;
//                        cnt[i] = cnt[j];
//                    }
//                    else if (ril[j] + 1 == ril[i]) {
//                        cnt[i] += cnt[j];
//                    }
//                }
//            }
//            MAX = max(MAX, ril[i]);
//        }
//        int ans = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            if (ril[i] == MAX) {
//                ans += cnt[i];
//            }
//        }
//        return ans;
//    }
//};
//树状数组版
//#include<bits/stdc++.h>
//using namespace std;
//int alen[2005];
//int acnt[2005];
//int M = 0;
//int lowbit(int i) {
//    return i & (-i);
//}
//void add(int i, int len, int cnt) {
//    while (i <= M) {
//        if (alen[i] == len) {
//            acnt[i] += cnt;
//        }
//        else if (alen[i] < len) {
//            alen[i] = len;
//            acnt[i] = cnt;
//        }
//        i += lowbit(i);
//    }
//}
//int maxLen, maxCnt;
//void query(int i) {
//    maxLen = 0;
//    maxCnt = 0;
//    while (i > 0) {
//        if (alen[i] > maxLen) {
//            maxLen = alen[i];
//            maxCnt = acnt[i];
//        }
//        else if (alen[i] == maxLen) {
//            maxCnt += acnt[i];
//        }
//        i -= lowbit(i);
//    }
//}
//int rankk(int t, vector<int>& a, int r) {
//    int l = 1;
//    int ans = -1;
//    while (l <= r) {
//        int m = (l + r) / 2;
//        if (a[m] >= t) {
//            ans = m;
//            r = m - 1;
//        }
//        else {
//            l = m + 1;
//        }
//    }
//    return ans;
//}


//class Solution {
//public:
//    int findNumberOfLIS(vector<int>& nums) {
//        M = 1;
//        memset(alen, 0, sizeof(alen));
//        memset(acnt, 0, sizeof(acnt));
//        vector<int>t(nums.size() + 1);
//        for (int i = 1; i <= nums.size(); i++) {
//            t[i] = nums[i - 1];
//        }
//        sort(t.begin() + 1, t.end());
//        for (int i = 1; i < t.size(); i++) {
//            if (t[i] != t[M]) {
//                t[++M] = t[i];
//            }
//        }
//        for (int i = 0; i < nums.size(); i++) {
//            nums[i] = rankk(nums[i], t, M);
//        }
//        for (int i : nums) {
//            query(i - 1);
//            add(i, maxLen + 1, max(maxCnt, 1));
//        }
//        query(M);
//        return maxCnt;
//    }
//};


//种类询问  离线处理****
//#include<bits/stdc++.h>
//using namespace std;
//int n, m;
//int tree[1000005];
//int pos[1000005];
//bool f(vector<int>& a, vector<int>& b) { return a[1] < b[1]; };
//int lowbit(int i) {
//	return i & (-i);
//}
//void add(int i, int num) {
//	while (i <= n) {
//		tree[i] += num;
//		i += lowbit(i);
//	}
//}
//int sum(int i) {
//	int ans = 0;
//	while (i > 0) {
//		ans += tree[i];
//		i -= lowbit(i);
//	}
//	return ans;
//}
//int range(int l, int r) {
//	return sum(r) - sum(l - 1);
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	cin >> m;
//	vector<vector<int>>q(m + 1,vector<int>(3));
//	vector<int>ans(m + 1);
//	for (int i = 1; i <= m; i++) {
//		cin >> q[i][0] >> q[i][1];
//		q[i][2] = i;
//	}
//	sort(q.begin() + 1, q.end(),f);
//	for (int s=1,i = 1; i <= m; i++) {
//		int r = q[i][1];
//		for (; s <= r; s++) {
//			int color = a[s];
//			if (pos[color] != 0) {
//				add(pos[color], -1);
//			}
//			add(s, 1);
//			pos[color] = s;
//		}
//		ans[q[i][2]] = range(q[i][0], q[i][1]);
//	}
//	for (int i = 1; i <= m; i++) {
//		cout << ans[i] << endl;
//	}
//}