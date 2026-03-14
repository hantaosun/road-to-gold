//括号区间匹配***
//#include<iostream>
//#include<cstring>
//#include<climits>
//using namespace std;
//int memo[105][105];
//int f(int l, int r, string s) {
//	if (memo[l][r] != -1)return memo[l][r];
//	if (l == r) {
//		return 1;
//	}
//	else if (l > r) {
//		return 0;
//	}
//	else if (l + 1 == r) {
//		if ((s[l] == '(' && s[r] == ')') || (s[l] == '[' && s[r] == ']')) {
//			return 0;
//		}
//		else {
//			return 2;
//		}
//	}
//	int ans = INT_MAX;
//	if ((s[l] == '(' && s[r] == ')') || (s[l] == '[' && s[r] == ']')) {
//		ans = f(l + 1, r - 1, s);
//	}
//	for (int j = l; j < r; j++) {
//		ans = min(ans, f(l, j, s) + f(j + 1, r, s));
//	}
//	memo[l][r] = ans;
//	return ans;
//}
//int main() {
//	string s;
//	cin >> s;
//	memset(memo, -1, sizeof(memo));
//	cout << f(0, s.size() - 1, s) << endl;
//	return 0;
//}

//涂色***
//#include<iostream>
//#include<cstring>
//#include<climits>
//using namespace std;
//int dp[105][105];
//int main(){
//	string s;
//	cin >> s;
//	for (int i = 0; i < s.size(); i++) {
//		for (int j = i; j < s.size(); j++) {
//			dp[i][j] = INT_MAX;
//		}
//	}
//	for (int i = 0; i < s.size(); i++) {
//		dp[i][i] = 1;
//		if (s[i] == s[i + 1]) {
//			dp[i][i + 1] = 1;
//		}
//		else {
//			dp[i][i + 1] = 2;
//		}
//	}
//	for (int i = s.size()-1; i >=0;i-- ) {
//		for (int j = i + 2; j < s.size();j++) {
//			if (s[i] == s[j]) {
//				dp[i][j] = dp[i + 1][j];
//			}
//			else {
//				for (int k = i; k < j; k++) {
//					dp[i][j] = min(dp[i][j],dp[i][k]+ dp[k + 1][j]);
//				}
//			}
//		}
//	}
//	cout<<dp[0][s.size() - 1] << endl;
//}

//合唱队
//#include<iostream>
//#include<vector>
//using namespace std;
//const int mod = 19650827;
//int dp[1005][1005][2];
//int f(int l,int r,int cur,int whe,vector<int>&idea) {//当前身高cur,是从whe端(0左1右)拿的
//	if (dp[l][r][whe] != -1)return dp[l][r][whe];
//	if (l > r)return 0;
//	else if (l == r) {
//		if (whe) {
//			if (cur > idea[l])return 1;
//			else {
//				return 0;
//			}
//		}
//		else {
//			if (cur < idea[l])return 1;
//			return 0;
//		}
//	}
//	int ans = 0;
//	if (whe) {
//		if (cur > idea[l]) {
//			ans = (ans + f(l + 1, r, idea[l],0, idea))%mod;
//		}
//		if (cur > idea[r]) {
//			ans = (ans + f(l, r - 1, idea[r], 1, idea))%mod;
//		}
//	}
//	else {
//		if (cur < idea[l]) {
//			ans = (ans + f(l + 1, r, idea[l], 0, idea)) % mod;
//		}
//		if (cur < idea[r]) {
//			ans = (ans + f(l, r - 1, idea[r], 1, idea)) % mod;
//		}
//	}
//	dp[l][r][whe] = ans;
//	return ans;
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < 1005; i++) {
//		for (int j = 0; j < 1005; j++) {
//			dp[i][j][0] = -1;
//			dp[i][j][1] = -1;
//		}
//	}
//	vector<int>idea(n + 5);
//	for (int i = 1; i <= n; i++) {
//		cin >> idea[i];
//	}
//	cout << (f(2, n, idea[1], 0, idea) + f(1, n - 1, idea[n], 1, idea))%mod << endl;
//}

//移除盒子***
//#include<iostream>
//#include<vector>
//using namespace std;
//int dp[105][105][105];
//int f(int l, int r, int k, vector<int>& box) {//带着k个与l位置相同的盒子在l到r上最大能得多少分
//    if (l > r)return 0;
//    if (dp[l][r][k] != -1) {
//        return dp[l][r][k];
//    }
//    int ans = -1;
//    int s = l;
//    while (s <= r && box[s] == box[l]) {
//        s++;
//    }
//    int cnt = k + s - l;
//    ans = max(ans, cnt * cnt + f(s, r, 0, box));
//    for (int i = r; i > s; i--) {
//        if (box[i] == box[l] && box[i - 1] != box[l]) {
//            ans = max(ans, f(s, i - 1, 0, box) + f(i, r, cnt, box));
//        }
//    }
//    dp[l][r][k] = ans;
//    return ans;
//}
//class Solution {
//public:
//    int removeBoxes(vector<int>& boxes) {
//        memset(dp, -1, sizeof(dp));
//        return f(0, boxes.size() - 1, 0, boxes);
//    }
//};

//合并石头
//#include<iostream>
//#include<vector>
//using namespace std;
//int dp[105][105];
//int f(int l, int r, int k, vector<int>& stones, vector<int>& presum) {
//    if (r - l == k - 1) {
//        return presum[r + 1] - presum[l];
//    }
//    else {
//        if (r - l < k - 1) {
//            return 0;
//        }
//    }
//    if (dp[l][r] != -1)return dp[l][r];
//    int ans = INT_MAX;
//    for (int i = l; i < r; i += k - 1) {
//        ans = min(ans, f(l, i, k, stones, presum) + f(i + 1, r, k, stones, presum));
//    }
//    if ((r - l) % (k - 1) == 0)ans += presum[r + 1] - presum[l];
//    dp[l][r] = ans;
//    return ans;
//}
//class Solution {
//public:
//    int mergeStones(vector<int>& stones, int k) {
//        if ((stones.size() - 1) % (k - 1) != 0)return -1;
//        memset(dp, -1, sizeof(dp));
//        vector<int>presum(stones.size() + 2);
//        presum[0] = 0;
//        for (int i = 1; i <= stones.size(); i++) {
//            presum[i] = presum[i - 1] + stones[i - 1];
//        }
//        return f(0, stones.size() - 1, k, stones, presum);
//    }
//};
//

//统计回文子序列
//#include<bits/stdc++.h>
//using namespace std;
//const int mod = 1e9 + 7;
//long long dp[1005][1005];
//class Solution {
//public:
//    int countPalindromicSubsequences(string s) {
//        memset(dp, 0, sizeof(dp));
//        int a = -1, b = -1, c = -1, d = -1;
//        vector<pair<int, int>>ar(s.size() + 5);
//        for (int i = 0; i < s.size(); i++) {
//            switch (s[i]) {
//            case 'a': { ar[i].first = a; a = i; break; }
//            case 'b': { ar[i].first = b; b = i; break; }
//            case 'c': { ar[i].first = c; c = i; break; }
//            case 'd': { ar[i].first = d; d = i; break; }
//            }
//        }
//        a = s.size(); b = s.size(); c = s.size(); d = s.size();
//        for (int i = s.size() - 1; i >= 0; i--) {
//            switch (s[i]) {
//            case 'a': { ar[i].second = a; a = i; break; }
//            case 'b': { ar[i].second = b; b = i; break; }
//            case 'c': { ar[i].second = c; c = i; break; }
//            case 'd': { ar[i].second = d; d = i; break; }
//            }
//        }
//        for (int i = 0; i < s.size(); i++) {
//            dp[i][i] = 1;
//        }
//        for (int i = s.size() - 1; i >= 0; i--) {
//            for (int j = i + 1; j < s.size(); j++) {
//                if (s[i] != s[j]) {
//                    dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + mod) % mod;
//                }
//                else {
//                    int z = ar[i].second;
//                    int y = ar[j].first;
//                    dp[i][j] = 2 * dp[i + 1][j - 1];
//                    if (z > y)dp[i][j] += 2;
//                    else if (z == y)dp[i][j] += 1;
//                    else {
//                        dp[i][j] = (dp[i][j] - dp[z + 1][y - 1] + mod) % mod;
//                    }
//                }
//            }
//        }
//        return dp[0][s.size() - 1] % mod;
//    }
//};
