//打怪兽
//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int N;
//	cin >> N;
//	vector<int>a(N+2);
//	vector<int>m(N+2);
//	for (int i = 1; i <= N; i++) {
//		cin >> a[i]>>m[i];
//	}
//	int sum = 0;
//	for (int i : m) {
//		sum += i;
//	}
//	vector<vector<int>>dp(N + 1, vector<int>(sum + 1));
//	for (int i = 1; i <= N; i++) {
//		for (int j = 0; j <= sum; j++) {
//			dp[i][j] = INT_MIN;
//			if (dp[i - 1][j] >= a[i]) {
//				dp[i][j] = dp[i - 1][j];
//			}
//			if (j - m[i] >= 0 && dp[i - 1][j - m[i]] != INT_MIN) {
//				dp[i][j] = max(dp[i][j], dp[i - 1][j - m[i]]+a[i]);
//			}
//		}
//	}
//	for (int i = 0; i <= sum; i++) {
//		if (dp[N][i] != INT_MIN) {
//			cout << i << endl;
//			break;
//		}
//	}
//}


//最长公共子序列***
//喵喵喵
//#include<bits/stdc++.h>
//using namespace std;
//int bs(int t, int r, vector<int>&ends) {
//	int l = 0,m;
//	int ans = -1;
//	while (l <= r) {
//		m = (l + r) / 2;
//		if (ends[m] >= t) {
//			ans = m;
//			r= m -1;
//		}
//		else {
//			l = m + 1;
//		}
//	}
//	return ans;
//}
//int main() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 2);
//	vector<int>posA(n + 2);
//	vector<int>b(n + 2);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		posA[a[i]] = i;
//	}
//	for (int i = 0; i < n; i++) {
//		cin >> b[i];
//		b[i] = posA[b[i]];
//	}
//	vector<int>ends(n + 2);
//	int len = 0;
//	for (int i = 0; i < n; i++) {
//		int pos = bs(b[i], len - 1, ends);
//		if (pos == -1) {
//			ends[len++] = b[i];
//		}
//		else {
//			ends[pos] = b[i];
//		}
//	}
//	cout << len << endl;
//}


//使数组严格递增 
//动态规划其实就是把不好枚举的问题用递归枚举
//#include<bits/stdc++.h>
//using namespace std;
//vector<int>a2;
//vector<int>a;
//int dp[2005][20005];
//int bs(int t) {
//    int r = a2.size() - 1, l = 0, m;
//    int ans = -1;
//    while (l <= r) {
//        m = (l + r) / 2;
//        if (a2[m] > t) {
//            ans = a2[m];
//            r = m - 1;
//        }
//        else {
//            l = m + 1;
//        }
//    }
//    return ans;
//}
//int f(int i, int pre) {//前面的数已经有序且结尾为pre，使后面的数有序的最小次数
//    if (i >= a.size())return 0;
//    if (pre != -1 && dp[i][pre] != -1)return dp[i][pre];
//    int num = bs(pre);
//    cout << i << " " << pre << " " << num << endl;
//    int ans = 0;
//    if (a[i] > pre) {
//        int d = f(i + 1, a[i]);
//        if (num == -1) {
//            ans = d;
//        }
//        else {
//            int d1 = f(i + 1, num);
//            if (d1 != -2 && d != -2) {
//                ans = min(1 + d1, d);
//            }
//            else {
//                ans = -2;
//                if (d1 != -2)ans = 1 + d1;
//                if (d != -2)ans = d;
//            }
//        }
//    }
//    else {
//        if (num == -1 && i != a.size())ans = -2;
//        else {
//            int d = f(i + 1, num);
//            if (d == -2)ans = -2;
//            else ans = 1 + d;
//        }
//    }
//    if (pre != -1)dp[i][pre] = ans;
//    //cout<<i<<" "<<pre<<" "<<ans<<"*"<<endl;
//    return ans;
//}
//class Solution {
//public:
//    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
//        sort(arr2.begin(), arr2.end());
//        memset(dp, -1, sizeof(dp));
//        a2.clear();
//        for (int i = 0, j = 0; i < arr2.size(); ) {
//            a2.push_back(arr2[i]);
//            while (j < arr2.size() && arr2[j] == arr2[i]) {
//                j++;
//            }
//            i = j;
//        }
//        for (int i : a2) {
//            cout << i << " *";
//        }
//        cout << endl;
//        a = arr1;
//        int ans = f(0, -1);
//        if (ans == -2)return -1;
//        else {
//            return ans;
//        }
//    }
//};
// 使数组严格递增
// 动态规划其实就是把不好枚举的问题用递归枚举
//#include <bits/stdc++.h>
//using namespace std;
//vector<int> a2;
//vector<int> a;
//int dp[2005][2010][2];
//int bs(int t) {
//    int r = a2.size() - 1, l = 0, m;
//    int ans = 2005;//单纯因为-1无法做下标
//    while (l <= r) {
//        m = (l + r) / 2;
//        if (a2[m] > t) {
//            ans = m;
//            r = m - 1;
//        }
//        else {
//            l = m + 1;
//        }
//    }
//    return ans;
//}
//int f(
//    int i, int pre,
//    bool
//    gai) { // 前面的数已经有序且结尾的数在a2中下一个为pre，使后面的数有序的最小次数
//    if (i >= a.size())
//        return 0;
//    int ans = 0;
//    if (dp[i][pre][gai] != -1)
//        return dp[i][pre][gai];
//    if (pre == 2005) {
//        if (gai) {
//            if (a[i] > a2.back()) {
//                int d = f(i + 1, 2005, 0);
//                if (d == -2)
//                    ans = -2;
//                else
//                    ans = d;
//            }
//            else {
//                ans = -2;
//            }
//        }
//        else {
//            if (a[i] > a[i - 1]) {
//                int d = f(i + 1, 2005, 0);
//                if (d == -2)
//                    ans = -2;
//                else
//                    ans = d;
//            }
//            else {
//                ans = -2;
//            }
//        }
//    }
//    else {
//        if (!gai) {
//            if (i == 0) {
//                int d1 = f(i + 1, bs(a[i]), 0);
//                int d2 = f(i + 1, bs(a2[pre]), 1);
//                if (d1 != -2 && d2 != -2) {
//                    ans = min(d1, 1 + d2);
//                }
//                else {
//                    ans = -2;
//                    if (d1 != -2)
//                        ans = d1;
//                    if (d2 != -2)
//                        ans = 1 + d2;
//                }
//            }
//            else {
//                if (a[i] > a[i - 1]) {
//                    int d1 = f(i + 1, bs(a[i]), 0);
//                    int d2 = f(i + 1, bs(a2[pre]), 1);
//                    if (d1 != -2 && d2 != -2) {
//                        ans = min(d1, 1 + d2);
//                    }
//                    else {
//                        ans = -2;
//                        if (d1 != -2)
//                            ans = d1;
//                        if (d2 != -2)
//                            ans = 1 + d2;
//                    }
//                }
//                else {
//                    int d = f(i + 1, bs(a2[pre]), 1);
//                    if (d == -2)
//                        ans = -2;
//                    else
//                        ans = 1 + d;
//                }
//            }
//        }
//        if (gai) {
//            if (a[i] > a2[pre - 1]) {
//                int d1 = f(i + 1, bs(a[i]), 0);
//                int d2 = f(i + 1, bs(a2[pre]), 1);
//                if (d1 != -2 && d2 != -2) {
//                    ans = min(d1, 1 + d2);
//                }
//                else {
//                    ans = -2;
//                    if (d1 != -2)
//                        ans = d1;
//                    if (d2 != -2)
//                        ans = 1 + d2;
//                }
//            }
//            else {
//                int d = f(i + 1, bs(a2[pre]), 1);
//                if (d == -2)
//                    ans = -2;
//                else
//                    ans = 1 + d;
//            }
//        }
//    }
//    dp[i][pre][gai] = ans;
//    return ans;
//}
//class Solution {
//public:
//    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
//        sort(arr2.begin(), arr2.end());
//        memset(dp, -1, sizeof(dp));
//        a2.clear();
//        for (int i = 0, j = 0; i < arr2.size();) {
//            a2.push_back(arr2[i]);
//            while (j < arr2.size() && arr2[j] == arr2[i]) {
//                j++;
//            }
//            i = j;
//        }
//        a = arr1;
//        int ans = f(0, 0, 0);
//        if (ans == -2)
//            return -1;
//        else {
//            return ans;
//        }
//    }
//};