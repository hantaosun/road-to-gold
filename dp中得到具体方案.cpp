//最长公共子序列
//爆栈版
//#include<bits/stdc++.h>
//#include<unordered_map>
//using namespace std;
//string a, b;
//vector<vector<string>> memo;
//string f(int i, int j) {
//	if (i == a.size() || j == b.size())return "";
//	if (memo[i][j] != "") return memo[i][j];
//	string ans = "";
//	if (a[i] == b[j]) {
//		ans = a[i] + f(i + 1, j + 1);
//	}
//	else {
//		string t1 = f(i + 1, j);
//		string t2 = f(j, i + 1);
//		if (t1.size() > t2.size())ans = t1;
//		else ans = t2;
//	}
//	memo[i][j] = ans;
//	return ans;
//}
//int main() {
//	cin >> a >> b;
//	memo.resize(a.size() + 5, vector<string>(b.size() + 5, ""));
//	cout << f(0, 0) << endl;
//}
//最长公共子序列
//位置依赖版
//正解并非如此，决策方案应通过逆推得到，而非在dp表中记录路径信息，在dp表中记录会导致内存占用过大
//#include<bits/stdc++.h>
//#include<unordered_map>
//using namespace std;
//string a, b;
//vector<vector<string>> dp;
//int main() {
//    cin >> a >> b;
//    dp.resize(a.size() + 5, vector<string>(b.size() + 5, ""));
//    for (int i = a.size()-1; i >= 0; i--) {
//        for (int j = b.size() - 1; j >= 0; j--) {
//            if (a[i] == b[j])dp[i][j] = a[i] + dp[i + 1][j + 1];
//            else {
//                if (dp[i + 1][j].size() > dp[i][j + 1].size()) {
//                    dp[i][j] = dp[i + 1][j];
//                }
//                else {
//                    dp[i][j] = dp[i][j + 1];
//                }
//            }
//        }
//    }
//    if (dp[0][0] == "")cout << -1<<endl;
//    else cout << dp[0][0] << endl;
//}


//最小的必要团队
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//class Solution {
//public:
//    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
//        map<string, int>index;
//        int n = req_skills.size();
//        for (int i = 0; i < n; i++) {
//            index[req_skills[i]] = i;
//        }
//        vector<ll>good(people.size(), 0);
//        for (int i = 0; i < people.size(); i++) {
//            for (int j = 0; j < people[i].size(); j++) {
//                good[i] |= 1 << index[people[i][j]];
//            }
//        }
//        vector<vector<ll>>dp(65, vector<ll>((1 << 16) + 5, INT_MAX));
//        for (int i = people.size(); i >= 0; i--) {
//            dp[i][0] = 0;
//        }
//        for (int i = people.size() - 1; i >= 0; i--) {
//            for (int j = 0; j <= (1 << n) - 1; j++) {
//                dp[i][j] = min(1 + dp[i + 1][j ^ (j & good[i])], dp[i + 1][j]);
//            }
//        }
//        vector<int>ans;
//        int x = 0, y = (1 << n) - 1;
//        while (y != 0) {
//            if (1 + dp[x + 1][y ^ (y & good[x])] < dp[x + 1][y]) {
//                ans.push_back(x);
//                y = (y ^ (y & good[x]));
//                x = x + 1;
//            }
//            else {
//                x = x + 1;
//            }
//        }
//        return ans;
//    }
//};


//最长递增子序列
//****
//#include<bits/stdc++.h>
//using namespace std;
//int bs(int t, int r, vector<int>& ends) {
//	int ans = -1;
//	int l = 0;
//	while (l <= r) {
//		int m = (l + r) / 2;
//		if (ends[m] <= t) {
//			ans = m;
//			r = m - 1;
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
//	vector<int>arr(n + 5);
//	vector<int>ends(n + 5);
//	int len = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	vector<int>rl(n);
//	for (int i = n - 1; i >= 0; i--) {
//		int pos = bs(arr[i], len - 1, ends);
//		if (pos == -1) {
//			ends[len++] = arr[i];
//			rl[i] = len;
//		}
//		else {
//			ends[pos] = arr[i];
//			rl[i] = pos + 1;
//		}
//	}
//	vector<int>ans(len);
//	for (int i = 0; i < n; i++) {
//		if (rl[i] == len) {
//			ans[0] = arr[i];
//		}
//		else if (arr[i] > ans[len - rl[i] - 1]) {
//			ans[len - rl[i]] = arr[i];
//		}
//	}
//	for (int i = 0; i < len; i++) {
//		cout << ans[i] << " ";
//	}
//	cout << endl;
//}


//通天之潜水
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int dp[105][205][205];
//vector<int>ans;
//int m, v, n;
//vector<int>w;
//vector<int>f;
//vector<int>t;
//void dfs(vector<int>& te, int nk, int ni, int nj) {
//	if (nk == 0) {
//		int s = 0;
//		for (int i = te.size() - 1, j = ans.size() - 1; i >= 0 && j >= 0; i--, j--) {
//			if (te[i] < ans[j]) {
//				s = 1;
//				break;
//			}
//			else if (ans[j] < te[i])break;
//		}
//		if (s)ans = te;
//		return;
//	}
//	if (ni < w[nk] || nj < f[nk]) {
//		dfs(te, nk - 1, ni, nj);
//	}
//	else {
//		if (dp[nk - 1][ni][nj] > t[nk] + dp[nk - 1][ni - w[nk]][nj - f[nk]]) {
//			dfs(te, nk - 1, ni, nj);
//		}
//		else if (dp[nk - 1][ni][nj] < t[nk] + dp[nk - 1][ni - w[nk]][nj - f[nk]]) {
//			te.push_back(nk);
//			dfs(te, nk - 1, ni - w[nk], nj - f[nk]);
//			te.pop_back();
//		}
//		else {
//			dfs(te, nk - 1, ni, nj);
//			te.push_back(nk);
//			dfs(te, nk - 1, ni - w[nk], nj - f[nk]);
//			te.pop_back();
//		}
//	}
//	return;
//}
//signed main() {
//	cin >> m >> v >> n;
//	w.resize(n + 2);
//	f.resize(n + 2);
//	t.resize(n + 2);
//	for (int i = 1; i <= n; i++) {
//		cin >> w[i] >> f[i] >> t[i];
//	}
//	for (int k = 1; k <= n; k++) {
//		for (int i = 0; i <= m; i++) {
//			for (int j = 0; j <= v; j++) {
//				dp[k][i][j] = dp[k - 1][i][j];
//				if (i >= w[k] && j >= f[k]) {
//					dp[k][i][j] = max(dp[k][i][j], t[k] + dp[k - 1][i - w[k]][j - f[k]]);
//				}
//			}
//		}
//	}
//	vector<int>t;
//	ans.resize(105, 999);//防止ans为空时无法被赋初值
//	dfs(t, n, m, v);
//	cout << dp[n][m][v] << endl;
//	for (int i = ans.size() - 1; i >= 0; i--)cout << ans[i] << " ";
//	cout << endl;
//}