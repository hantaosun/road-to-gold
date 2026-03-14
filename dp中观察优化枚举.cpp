//股票1
//#include<bits/stdc++.h>
//using namespace std;
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int mi=INT_MAX, ans=INT_MIN;
//        for (int i = 0; i < prices.size(); i++) {
//            mi = min(mi, prices[i]);
//            ans = max(prices[i] - mi, ans);
//        }
//        return ans;
//    }
//};


//股票2
//#include<bits/stdc++.h>
//using namespace std;
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int ans = 0;
//        for (int i = 1; i < prices.size(); i++) {
//            if (prices[i] - prices[i - 1] > 0) {
//                ans += prices[i] - prices[i - 1];
//            }
//        }
//        return ans;
//    }
//};


//股票3
//#include<bits/stdc++.h>
//using namespace std;
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        vector<int>dp1(prices.size() + 5);
//        vector<int>dp2(prices.size() + 5);
//        int mi = prices[0];
//        dp1[0] = 0;
//        for (int i = 1; i < prices.size(); i++) {
//            mi = min(mi, prices[i]);
//            dp1[i] = max(dp1[i - 1], prices[i] - mi);
//        }
//        dp2[0] = 0;
//        int ans = 0;
//        vector<int>best(prices.size() + 5);
//        best[0] = dp1[0] - prices[0];
//        for (int i = 1; i < prices.size(); i++) {
//            best[i] = max(best[i - 1], dp1[i] - prices[i]);
//        }
//        for (int i = 1; i < prices.size(); i++) {
//            ans = max(ans, prices[i] + best[i]);
//        }
//        return ans;
//    }
//};


//股票4
//未优化版
//#include<bits/stdc++.h>
//using namespace std;
//int dp[105][1005];
//class Solution {
//public:
//    int maxProfit(int k, vector<int>& prices) {
//        int ans = 0;
//        for (int i = 0; i <= k; i++) {
//            dp[i][0] = 0;
//        }
//        for (int i = 0; i < prices.size(); i++) {
//            dp[0][i] = 0;
//        }
//        for (int i = 1; i <= k; i++) {
//            for (int j = 1; j < prices.size(); j++) {
//                dp[i][j] = dp[i][j - 1];
//                for (int k = 0; k <= j; k++) {
//                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + prices[j] - prices[k]);
//                }
//            }
//        }
//        return dp[k][prices.size() - 1];
//    }
//};
//
//优化版   注意优化所用数组,实际可以用一个变量实现相同功能
//#include<bits/stdc++.h>
//using namespace std;
//int dp[105][1005];
//class Solution {
//public:
//    int maxProfit(int k, vector<int>& prices) {
//        int ans = 0;
//        for (int i = 0; i <= k; i++) {
//            dp[i][0] = 0;
//        }
//        for (int i = 0; i < prices.size(); i++) {
//            dp[0][i] = 0;
//        }
//        vector<int>t(prices.size() + 5);//第i层从0-当前下标dp[i][k]-price[k]的最大值
//        t[0] = -prices[0];
//        for (int i = 1; i < prices.size(); i++) {
//            t[i] = max(t[i - 1], dp[0][i] - prices[i]);
//        }
//        for (int i = 1; i <= k; i++) {
//            for (int j = 1; j < prices.size(); j++) {
//                dp[i][j] = max(dp[i][j - 1], prices[j] + t[j]);
//                t[j] = max(t[j - 1], dp[i][j] - prices[j]);
//            }
//        }
//        return dp[k][prices.size() - 1];
//    }
//};


//股票5***
//建议看题解思考方式
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
//#include<bits/stdc++.h>
//using namespace std;
//class Solution {
//public:
//    int maxProfit(vector<int>& prices, int fee) {
//        int n = prices.size();
//        vector<int>dp(n);
//        int best = -prices[0];
//        for (int i = 1; i < n; i++) {
//            dp[i] = max(dp[i - 1], prices[i] + best - fee);
//            best = max(best, dp[i] - prices[i]);
//        }
//        return dp[n - 1];
//    }
//};


//股票6
//未优化版
//#include<bits/stdc++.h>
//using namespace std;
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        vector<int>dp(prices.size() + 5);
//        for (int i = 1; i < prices.size(); i++) {
//            dp[i] = dp[i - 1];
//            for (int j = 0; j <= i; j++) {
//                dp[i] = max(dp[i], prices[i] - prices[j] + (j - 2 >= 0 ? dp[j - 2] : 0));
//            }
//        }
//        return dp[prices.size() - 1];
//    }
//};
//优化版  仅基于对转移方程的观察  可以直接从2开始,0,1自己讨论
//#include<bits/stdc++.h>
//using namespace std;
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        vector<int>dp(prices.size() + 5);
//        if (prices.size() == 1)return 0;
//        int best = -prices[0];
//        for (int i = 1; i < prices.size(); i++) {
//            dp[i] = max(dp[i - 1], best + prices[i]);
//            if (i >= 2) {
//                best = max(best, dp[i - 2] - prices[i]);
//            }
//            else {
//                best = max(best, -prices[i]);
//            }
//        }
//        return dp[prices.size() - 1];
//    }
//};


//DI序列的有效排列
//暴力版
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int mod = 1e9 + 7;
//class Solution {
//public:
//    ll f(set<int>& used, int cur, int end, string& t) {//哪些数字使用了，哪个数字结尾
//        if (cur == t.size())return 1;
//        int ans = 0;
//        if (t[cur] == 'D') {
//            for (int i = 0; i < end; i++) {
//                if (used.count(i))continue;
//                used.insert(i);
//                ans += f(used, cur + 1, i, t);
//                used.erase(i);
//            }
//        }
//        else {
//            for (int i = end + 1; i <= t.size(); i++) {
//                if (used.count(i))continue;
//                used.insert(i);
//                ans += f(used, cur + 1, i, t);
//                used.erase(i);
//            }
//        }
//        return ans;
//    }
//    int numPermsDISequence(string s) {
//        int ans = 0;
//        for (int i = 0; i <= s.size(); i++) {
//            set<int>used;
//            used.insert(i);
//            ans += f(used, 0, i, s);
//        }
//        return ans;
//    }
//};
//
//初步优化版 未优化枚举行为
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int mod = 1e9 + 7;
//int dp[205][205];
//class Solution {
//public:
//    ll f(int cur, int less, string s) {//到了哪一个位置，比上一个数字小的数有几个
//        if (cur == s.size())return 1;
//        if (dp[cur][less] != -1)return dp[cur][less];
//        ll ans = 0;
//        if (s[cur] == 'D') {
//            if (less == 0)return 0;
//            for (int i = 0; i < less; i++)
//                ans = (ans + f(cur + 1, i, s)) % mod;
//        }
//        else {
//            if (s.size() - less - cur == 0)return 0;
//            for (int i = less; i < s.size() - cur; i++) {
//                ans = (ans + f(cur + 1, i, s)) % mod;
//            }
//        }
//        dp[cur][less] = ans;
//        return ans;
//    }
//    int numPermsDISequence(string s) {
//        memset(dp, -1, sizeof(dp));
//        int ans = 0;
//        for (int i = 0; i <= s.size(); i++) {
//            ans = (ans + f(0, i, s)) % mod;
//        }
//        return ans;
//    }
//};
//位置依赖版
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int mod = 1e9 + 7;
//ll dp[205][205];
//class Solution {
//public:
//    int numPermsDISequence(string s) {
//        memset(dp, 0, sizeof(dp));//一定要设为0否则会多出额外情况
//        for (int i = s.size(); i >= 0; i--) {
//            dp[s.size()][i] = 1;
//        }
//        for (int i = s.size() - 1; i >= 0; i--) {
//            for (int j = s.size(); j >= 0; j--) {
//                if (s[i] == 'D') {
//                    for (int k = 0; k < j; k++)
//                        dp[i][j] = (dp[i][j] + dp[i + 1][k]) % mod;
//                }
//                else {
//                    for (int k = j; k < s.size() - i; k++) {
//                        dp[i][j] = (dp[i][j] + dp[i + 1][k]) % mod;
//                    }
//                }
//            }
//        }
//        int ans = 0;
//        for (int i = 0; i <= s.size(); i++) {
//            ans = (ans + dp[0][i]) % mod;
//        }
//        return ans;
//    }
//};
// 最终优化版
//#include <bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int mod = 1e9 + 7;
//ll dp[205][205];
//class Solution {
//public:
//    int numPermsDISequence(string s) {
//        memset(dp, 0, sizeof(dp)); // 一定要设为0否则会多出额外情况
//        for (int i = s.size(); i >= 0; i--) {
//            dp[s.size()][i] = 1;
//        }
//        for (int i = s.size() - 1; i >= 0; i--) {
//            if (s[i] == 'D') {
//                dp[i][1] = dp[i + 1][0];
//                for (int j = 2; j <= s.size(); j++) {
//                    dp[i][j] = (dp[i][j - 1] + dp[i + 1][j - 1]) % mod;
//                }
//            }
//            else {
//                dp[i][s.size() - i - 1] = dp[i + 1][s.size() - i - 1];
//                for (int j = s.size() - i - 2; j >= 0; j--) {
//                    dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % mod;
//                }
//            }
//        }
//        int ans = 0;
//        for (int i = 0; i <= s.size(); i++) {
//            ans = (ans + dp[0][i]) % mod;
//        }
//        return ans;
//    }
//};


//规划兼职工作***注意状态设计
//#include<bits/stdc++.h>
//using namespace std;
//int dp[50005];
//int nex[50005];
//class Solution {
//public:
//    int bs(vector<vector<int>>& a, int s) {
//        int l = 0, r = a.size() - 1;
//        int ans = -1;
//        while (l <= r) {
//            int m = (l + r) / 2;
//            if (a[m][0] >= s) {
//                ans = m;
//                r = m - 1;
//            }
//            else {
//                l = m + 1;
//            }
//        }
//        return ans;
//    }
//    int  f(int i, vector<vector<int>>& a) {//从i个工作往后选择可以获得的最大利润
//        if (i >= a.size())return 0;
//        if (dp[i] != -1)return dp[i];
//        int ans = a[i][2];
//        int next = -1;
//        if (nex[i] != 0)next = nex[i];
//        else next = bs(a, a[i][1]);
//        if (next != -1)ans += f(next, a);
//        ans = max(ans, f(i + 1, a));
//        dp[i] = ans;
//        return ans;
//    }
//    static bool g(vector<int>& a, vector<int>& b) {
//        return a[0] < b[0];
//    }
//    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//        vector<vector<int>>a(startTime.size(), vector<int>(3));
//        memset(dp, -1, sizeof(dp));
//        memset(nex, 0, sizeof(nex));
//        for (int i = 0; i < a.size(); i++) {
//            a[i][0] = startTime[i];
//            a[i][1] = endTime[i];
//            a[i][2] = profit[i];
//        }
//        sort(a.begin(), a.end(), g);
//        int ans = -1;
//        for (int i = 0; i < a.size(); i++) {
//            if (a[i][0] < a[0][1]) {
//                ans = max(ans, f(i, a));
//            }
//            else break;
//        }
//        return ans;
//    }
//};


//k个逆序对数组
//未优化版
//#include<bits/stdc++.h>
//using namespace std;
//int dp[1005][1005];
//const int mod = 1e9 + 7;
//class Solution {
//public:
//    int kInversePairs(int n, int k) {
//        for (int i = 1; i <= n; i++) {
//            dp[i][0] = 1;
//        }
//        for (int i = 2; i <= n; i++) {
//            for (int j = 1; j <= k; j++) {
//                if (i > j) {
//                    dp[i][j] = 0;
//                    for (int k = 0; k <= j; k++) {
//                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
//                    }
//                }
//                else {
//                    dp[i][j] = 0;
//                    for (int k = j - i + 1; k <= j; k++) {
//                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
//                    }
//                }
//            }
//        }
//        return dp[n][k];
//    }
//};
//优化版
//#include <bits/stdc++.h>
//using namespace std;
//int dp[1005][1005];
//const int mod = 1e9 + 7;
//class Solution {
//public:
//    int kInversePairs(int n, int k) {
//        for (int i = 1; i <= n; i++) {
//            dp[i][0] = 1;
//        }
//        for (int i = 2; i <= n; i++) {
//            int l = 0, r = 0, sum = dp[i - 1][0];
//            for (int j = 1; j <= k; j++) {
//                sum = (sum + dp[i - 1][++r]) % mod;
//                if (r - l + 1 > i) {
//                    sum = (sum - dp[i - 1][l++] + mod) % mod;
//                }
//                dp[i][j] = sum;
//            }
//        }
//        return dp[n][k];
//    }
//};


//自由之路***
//#include<bits/stdc++.h>
//using namespace std;
//int dp[105][105];
//class Solution {
//public:
//    int lbs(int cur, vector<int>& pos) {
//        int ans = -1, l = 0, r = pos.size() - 1;
//        while (l <= r) {
//            int m = (l + r) / 2;
//            if (pos[m] <= cur) {
//                ans = pos[m];
//                l = m + 1;
//            }
//            else {
//                r = m - 1;
//            }
//        }
//        if (ans == -1)return pos.back();
//        return ans;
//    }
//    int rbs(int cur, vector<int>& pos) {
//        int ans = -1, l = 0, r = pos.size() - 1;
//        while (l <= r) {
//            int m = (l + r) / 2;
//            if (pos[m] >= cur) {
//                ans = pos[m];
//                r = m - 1;
//            }
//            else {
//                l = m + 1;
//            }
//        }
//        if (ans == -1)return pos[0];
//        return ans;
//    }
//    int f(int i, int j, string ring, string key, vector<vector<int>>& pos) {//当前指向ring的i位置，要解决key的j位置及以后的位置所需的最小代价
//        if (j == key.size())return 0;
//        if (dp[i][j] != -1)return dp[i][j];
//        int ans = 0;
//        if (ring[i] == key[j]) {
//            ans = 1 + f(i, j + 1, ring, key, pos);
//        }
//        else {
//            int rp = rbs(i, pos[key[j] - 'a']);
//            int lp = lbs(i, pos[key[j] - 'a']);
//            ans = min((rp + ring.size() - i) % ring.size() + 1 + f(rp, j + 1, ring, key, pos),
//                (i + ring.size() - lp) % ring.size() + 1 + f(lp, j + 1, ring, key, pos));
//        }
//        dp[i][j] = ans;
//        return ans;
//    }
//    int findRotateSteps(string ring, string key) {
//        memset(dp, -1, sizeof(dp));
//        vector<vector<int>>pos(26);
//        for (int i = 0; i < ring.size(); i++) {
//            pos[ring[i] - 'a'].push_back(i);
//        }
//        return f(0, 0, ring, key, pos);
//    }
//};


//未排序数组中累加和小于或等于给定值的最长子数组长度***
//正常复杂度O(nlog(n))通过前缀信息配二分即可实现
//O(n)复杂度的解法
//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int N, k;
//	cin >> N >> k;
//	vector<int>a(N);
//	for (int i = 0; i < N; i++) {
//		cin >> a[i];
//	}
//	vector<int>minSum(N);//从i位置出发往右扩能得到的数组累加和最小是多少
//	vector<int>minEnd(N);//该累加和扩到了右侧什么位置
//	minSum[N - 1] = a[N - 1];
//	minEnd[N - 1] = N - 1;
//	for (int i = N-2; i>=0; i--) {
//		if (minSum[i + 1] < 0) {
//			minSum[i] = a[i]+minSum[i+1];
//			minEnd[i] = minEnd[i + 1];
//		}
//		else {
//			minSum[i] = a[i];
//			minEnd[i] = i;
//		}
//	}
//	int ans = 0;
//	for (int i = 0, sum = 0, end = 0; i < N; i++) {
//		while (end < N&&sum+minSum[end]<=k) {
//			sum += minSum[end];
//			end = minEnd[end] + 1;
//		}
//		if (end > i) {
//			ans = max(ans, end - i);
//			sum -= a[i];
//		}
//		else {
//			end++;
//		}
//	}
//	cout << ans << endl;
//}