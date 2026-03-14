//can i win?
//#include<bits/stdc++.h>
//using namespace std;
//int dp[(1 << 20)];
//class Solution {
//public:
//    bool f(int n, int s, int rest) {//在累加和还剩rest的情况下，当前的先手能不能赢
//        if (rest <= 0)return false;
//        if (dp[s] != 0)return dp[s] == 1;
//        bool ans = 0;
//        for (int i = 1; i <= n; i++) {
//            if ((s & (1 << i - 1)) != 0 && !f(n, s ^ (1 << i - 1), rest - i)) {
//                ans = true;
//                break;
//            }
//        }
//        dp[s] = ans ? 1 : -1;
//        return ans;
//    }
//    bool canIWin(int n, int m) {
//        if (m == 0)return true;
//        if ((1 + n) * n / 2 < m)return false;
//        memset(dp, 0, sizeof(dp));
//        return f(n, (1 << n) - 1, m);
//    }
//};

//火柴拼正方形
//#include<bits/stdc++.h>
//using namespace std;
//int dp[65000];
//class Solution {
//public:
//    bool f(int s, int cur, int c,int t, vector<int>& match) {//当前哪些火柴能用,拼到第几条边了,当前边拼了cur长度的情况下，能否拼出正方形
//        if (c == 5)return true;
//        if (cur == t)return f(s, 0, c + 1, t, match);
//        if (cur > t)return false;
//        if (dp[s] != -1)return dp[s];
//        bool ans = 0;
//        for (int i = 0; i < match.size(); i++) {
//            if ((s & (1 << i)) != 0&&f(s^(1<<i),cur+match[i],c,t,match)) {
//                ans = true;
//                break;
//            }
//        }
//        dp[s] = ans;
//        return ans;
//    }
//    bool makesquare(vector<int>& matchsticks) {
//        int sum = 0;
//        for (int i : matchsticks) {
//            sum += i;
//        }
//        if (sum % 4 != 0)return false;
//        memset(dp, -1, sizeof(dp));
//        return f((1 << matchsticks.size()) - 1, 0, 1, sum / 4, matchsticks);
//    }
//};

//划分为k个非空子集
//#include<bits/stdc++.h>
//using namespace std;
//int dp[165000];
//class Solution {
//public:
//    bool f(int s, int cur, int c, int t, vector<int>& match, int k) {//当前哪些火柴能用,拼到第几条边了,当前边拼了cur长度的情况下，能否拼出正方形
//        if (c == k + 1)return true;
//        if (cur == t)return f(s, 0, c + 1, t, match, k);
//        if (cur > t)return false;
//        if (dp[s] != -1)return dp[s];
//        bool ans = 0;
//        for (int i = 0; i < match.size(); i++) {
//            if ((s & (1 << i)) != 0 && f(s ^ (1 << i), cur + match[i], c, t, match, k)) {
//                ans = true;
//                break;
//            }
//        }
//        dp[s] = ans;
//        return ans;
//    }
//    bool canPartitionKSubsets(vector<int>& nums, int k) {
//        int sum = 0;
//        for (int i : nums) {
//            sum += i;
//        }
//        if (sum % k != 0)return false;
//        memset(dp, -1, sizeof(dp));
//        return f((1 << nums.size()) - 1, 0, 1, sum / k, nums, k);
//    }
//};

//剪枝加回溯做法
//#include<bits/stdc++.h>	
//using namespace std;
//class Solution {
//public:
//    bool f(int index,vector<int>&arr,vector<int>& nums, int tar,int k) {
//        if (index < 0)return true;
//        int num = nums[index];
//        for (int i = 0; i<k; i++) {
//            if (arr[i] + num <= tar) {
//                arr[i] += num;
//                if (f(index - 1, arr, nums, tar, k))
//                    return true;
//                arr[i] -= num;
//                while (i + 1 < k && arr[i] == arr[i + 1]) {
//                    i++;
//                }
//            }
//        }
//        return false;
//    }
//    bool canPartitionKSubsets(vector<int>& nums, int k) {
//        sort(nums.begin(), nums.end());
//        int sum = 0;
//        for (int i : nums) {
//            sum += i;
//        }
//        if (sum % k != 0)return false;
//        vector<int>arr(k);
//        return f(nums.size() - 1, arr, nums, sum / k, k);
//    }
//};


//TSP问题
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//int dp[2000000][22];
//int f(int s, int cur,vector<vector<int>>&g) {//哪些村庄走过了，当前停在哪
//	if (s == ((1 << n) - 1))return g[cur][0];
//	if (dp[s][cur] != -1)return dp[s][cur];
//	int ans = INT_MAX;
//	for (int i = 0; i < n; i++) {
//		if (!(s & (1 << i))) {
//			ans = min(ans,g[cur][i] + f(s^(1<<i), i,g));
//		}
//	}
//	dp[s][cur] = ans;
//	return ans;
//}
//
//int main() {
//	cin >> n;
//	vector<vector<int>>g(n + 1, vector<int>(n + 1));
//	for (int i = 0; i <n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> g[i][j];
//		}
//	}
//	memset(dp, -1, sizeof(dp));
//	cout<<f(1, 0,g)<<endl;
//}


//每个人戴不同帽子的方案数
//帽子匹配人不行
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int mod = 1e9 + 7;
//class Solution {
//public:
//    ll f(ll s,int cur,vector<vector<int>>&hats){//当前哪些帽子使用了，安排到数组中下标哪一位了
//        if (cur == hats.size())return 1;
//        ll ans = 0;
//        for (int i = 0; i < hats[cur].size(); i++) {
//            if ((s & (1 << hats[cur][i])) == 0)
//                ans = (ans + f(s ^ (1 << hats[cur][i]), cur + 1, hats))%mod;
//        }
//        return ans;
//    }
//    int numberWays(vector<vector<int>>& hats) {
//        return f(0, 0, hats);
//    }
//};
//人匹配帽子
//#include<bits/stdc++.h>
//#include<unordered_set>
//#include<unordered_map>
//#define ll long long
//using namespace std;
//const int mod = 1e9 + 7;
//int offset;
//ll dp[1 << 11][42];
//class Solution {
//public:
//    ll f(int s, int cur, vector<vector<int>>& mans) {
//        if (dp[s][cur] != -1)return dp[s][cur];
//        if (cur == mans.size()) {
//            if (s == offset)return 1;
//            return 0;
//        }
//        ll ans = 0;
//        ans += f(s, cur + 1, mans);
//        for (int i = 0; i < mans[cur].size(); i++) {
//            if ((s & (1 << mans[cur][i])) == 0) {
//                ans = (ans + f(s ^ (1 << mans[cur][i]), cur + 1, mans)) % mod;
//            }
//        }
//        dp[s][cur] = ans;
//        return ans;
//    }
//    int numberWays(vector<vector<int>>& hats) {
//        memset(dp, -1, sizeof(dp));
//        unordered_set<int>t;
//        for (int i = 0; i < hats.size(); i++) {
//            for (int j = 0; j < hats[i].size(); j++) {
//                t.insert(hats[i][j]);
//            }
//        }
//        vector<int>a;
//        for (int x : t) {
//            a.push_back(x);
//        }
//        sort(a.begin(), a.end());
//        unordered_map<int, int>index;
//        for (int i = 0; i < a.size(); i++) {
//            index[a[i]] = i;
//        }
//        vector<vector<int>>mans(a.size());
//        for (int i = 0; i < hats.size(); i++) {
//            for (int j = 0; j < hats[i].size(); j++) {
//                mans[index[hats[i][j]]].push_back(i);
//            }
//        }
//        offset = (1 << hats.size()) - 1;
//        return f(0, 0, mans);
//    }
//};


//好子集的数目***
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int mod = 1e9 + 7;
//int own[] = { 0b0000000000, // 0
//        0b0000000000, // 1
//        0b0000000001, // 2
//        0b0000000010, // 3
//        0b0000000000, // 4
//        0b0000000100, // 5
//        0b0000000011, // 6
//        0b0000001000, // 7
//        0b0000000000, // 8
//        0b0000000000, // 9
//        0b0000000101, // 10
//        0b0000010000, // 11
//        0b0000000000, // 12
//        0b0000100000, // 13
//        0b0000001001, // 14
//        0b0000000110, // 15
//        0b0000000000, // 16
//        0b0001000000, // 17
//        0b0000000000, // 18
//        0b0010000000, // 19
//        0b0000000000, // 20
//        0b0000001010, // 21
//        0b0000010001, // 22
//        0b0100000000, // 23
//        0b0000000000, // 24
//        0b0000000000, // 25
//        0b0000100001, // 26
//        0b0000000000, // 27
//        0b0000000000, // 28
//        0b1000000000, // 29
//        0b0000000111 // 30
//};
//ll dp[1 << 11][35];
//class Solution {
//public:
//    ll f(int s, int cur, vector<int>& a) {
//        if (dp[s][cur] != -1)return dp[s][cur];
//        ll ans = 0;
//        if (cur == 1) {
//            if (s == 0) {
//                ans = 1;
//                for (int i = 0; i < a[cur]; i++) {
//                    ans = (ans * 2) % mod;
//                }
//            }
//        }
//        else {
//            ans = (ans + f(s, cur - 1, a)) % mod;
//            if (own[cur] != 0 && ((s & own[cur]) == own[cur])) {
//                ans = (ans + f(s ^ own[cur], cur - 1, a) * a[cur]) % mod;
//            }
//        }
//        dp[s][cur] = ans;
//        return ans;
//    }
//    int numberOfGoodSubsets(vector<int>& nums) {
//        memset(dp, -1, sizeof(dp));
//        vector<int>a(31);
//        for (int i = 0; i < nums.size(); i++) {
//            a[nums[i]]++;
//        }
//        ll ans = 0;
//        for (int i = 1; i < (1 << 10); i++) {
//            ans = (ans + f(i, a.size() - 1, a)) % mod;
//        }
//        return ans;
//    }
//};


//分配重复整数
//#include<bits/stdc++.h>
//using namespace std;
//int dp[1 << 10 + 5][1005];
//class Solution {
//public:
//    bool f(int s, int cur, vector<int>& a, vector<int>& b) {
//        if (dp[s][cur] != -1)return dp[s][cur];
//        if (s == 0)return true;
//        if (cur == a.size())return false;
//        bool ans = false;
//        for (int j = s; j > 0; j = (j - 1) & s) {
//            if (a[cur] >= b[j]) {
//                if (f(s ^ j, cur + 1, a, b)) {
//                    ans = true;
//                    break;
//                }
//            }
//        }
//        if (!ans)ans = f(s, cur + 1, a, b);
//        dp[s][cur] = ans;
//        return ans;
//    }
//    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
//        memset(dp, -1, sizeof(dp));
//        sort(nums.begin(), nums.end());
//        vector<int>a;
//        for (int i = 0, j = 0; i < nums.size();) {
//            while (j < nums.size() && nums[j] == nums[i])j++;
//            a.push_back(j - i);
//            i = j;
//        }
//        vector<int>b(1 << 10);
//        b[0] = 0;
//        for (int i = 0; i < quantity.size(); i++) {
//            int a = 1 << i;
//            for (int j = 0; j < a; j++) {
//                b[j | a] = b[j] + quantity[i];
//            }
//        }
//        return f((1 << quantity.size()) - 1, 0, a, b);
//    }
//};