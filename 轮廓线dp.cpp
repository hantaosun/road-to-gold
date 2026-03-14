//Corn Fields G
//普通状压版
//#include<bits/stdc++.h>
//#define int long long
//const int mod = 1e8;
//using namespace std;
//int g[13][13];
//int dp[13][(1 << 13) + 1];
//int m, n;
//int get(int s,int i) {
//	if (i < 0) {
//		return 0;
//	}
//	return (s >> i) & 1;
//}
//int setv(int s, int i, int v) {
//	if (v == 0) {
//		return s & (~(1 << i));
//	}
//	else {
//		return s | (1 << i);
//	}
//}
//int f(int i, int s);
//int dfs(int i,int j,int s,int ss) {
//	if (j == n) {
//		return f(i + 1, ss);
//	}
//	int ans = 0;
//	ans = (ans + dfs(i, j + 1, s, ss))%mod;
//	if ( get(ss, j - 1) == 0 && get(s, j) == 0 && g[i][j] == 1) {
//		ans = (ans + dfs(i, j + 1, s, setv(ss, j, 1)))%mod;
//	}
//	return ans;
//}
//int f(int i, int s) {//当前来到第几行,上一行种草状况为s,返回整个网格种草方案数
//	if (dp[i][s] != -1)return dp[i][s];
//	int ans;
//	if (i == m)ans=1;
//	else { 
//		ans=dfs(i, 0, s, 0);
//	}
//	dp[i][s] = ans;
//	return ans;
//}
//signed main() {
//	memset(dp, -1, sizeof(dp));
//	cin >> m >> n;
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> g[i][j];
//		}
//	}
//	cout << f(0, 0) << '\n';
//}

//轮廓线dp版
//#include<bits/stdc++.h>
//using namespace std;
//const int mod = 1e8;
//int n, m;
//int g[13][13];
//int dp[13][13][(1 << 13) + 1];
//int get(int s, int i) {
//	if (i < 0)return 0;
//	return (s >> i) & 1;
//}
//int setv(int s, int i, int v) {
//	if (v == 0) {
//		return s & (~(1 << i));
//	}
//	else {
//		return s | (1 << i);
//	}
//}
//int f(int i, int j, int s) {//当前来到(i,j)位置,其左侧和上侧种植情况为s返回方案数
//	if (i == n)return 1;
//	if (dp[i][j][s] != -1)return dp[i][j][s];
//	if (j == m) {
//		return f(i + 1, 0, s);
//	}
//	int ans = 0;
//	ans = f(i, j + 1, setv(s,j,0));
//	if (get(s, j - 1) == 0 && get(s, j) == 0 && g[i][j] == 1) {
//		ans = (ans + f(i, j + 1, setv(s, j, 1))) % mod;
//	}
//	dp[i][j][s] = ans;
//	return ans;
//}
//int main() {
//	memset(dp, -1, sizeof dp);
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> g[i][j];
//		}
//	}
//	cout << f(0, 0, 0) << '\n';
//}
//
//空间压缩版
//#include<bits/stdc++.h>
//using namespace std;
//const int mod = 1e8;
//int n, m;
//int setv(int s, int i,int v) {
//	if (v == 0) {
//		return s & (~(1 << i));
//	}
//	else {
//		return s | (1 << i);
//	}
//}
//int get(int s, int i) {
//	if (i < 0)return 0;
//	return (s >> i) & 1;
//}
//int g[13][13];
//int backup[(1 << 13) + 1];
//int dp[14][(1 << 13) + 1];
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> g[i][j];
//		}
//	}
//	for (int s = 0; s < (1 << m); s++) {
//		backup[s] = 1;
//	}
//	for (int i = n - 1; i >= 0; i--) {
//		for (int s = 0; s < (1 << m); s++) {
//			dp[m][s] = backup[s];
//		}
//		for (int j = m-1; j >= 0; j--) {
//			for (int s = 0; s < (1 << m); s++) {
//				dp[j][s] = dp[j + 1][setv(s, j, 0)];
//				if (get(s, j - 1) == 0 && get(s, j) == 0 && g[i][j] == 1) {
//					dp[j][s] = (dp[j][s] + dp[j + 1][setv(s, j, 1)]) % mod;
//				}
//			}
//		}
//		for (int s = 0; s < (1 << m); s++) {
//			backup[s] = dp[0][s];
//		}
//	}
//	cout << dp[0][0] << '\n';
//}

//贴瓷砖
//#include<bits/stdc++.h>
//using namespace std;
//int n, m;
//int dp[12][12][1 << 12];
//int get(int s, int i) {
//	if (i >= m)return 1;
//	return (s >> i) & 1;
//}
//int setv(int s, int i, int v) {
//	if (v == 0) {
//		return s & (~(1 << i));
//	}
//	else {
//		return s | (1 << i);
//	}
//}
//int f(int i, int j, int s) {//当前来到i行j列,s中0-j表示左侧贴的瓷砖有没有占到下一行，右侧表示当前行有没有贴上瓷砖
//	if (i == n)return 1;
//	if (j >= m) {
//		return f(i + 1, 0, s);
//	}
//	if (dp[i][j][s] != -1)return dp[i][j][s];
//	int ans = 0;
//	if (get(s, j) == 1) {
//		ans = f(i, j + 1, setv(s, j, 0));
//	}
//	else {
//		if (i != n - 1)ans += f(i, j + 1, setv(s, j, 1));
//		if (get(s, j) != 1 && get(s, j + 1) != 1) {
//			ans += f(i, j + 2, setv(setv(s, j, 0), j + 1, 0));
//		}
//		dp[i][j][s] = ans;
//	}
//	return ans;
//}
//int main() {
//	cin >> n >> m;
//	while (n != 0 || m != 0) {
//		memset(dp, -1, sizeof(dp));
//		cout << f(0, 0, 0) << '\n';
//		cin >> n >> m;
//	}
//	return 0;
//}
//贴瓷砖
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n, m;
//int backup[1 << 12];
//int dp[12][1 << 12];
//int get(int s, int i) {
//	if (i >= m)return 1;
//	return (s >> i) & 1;
//}
//int setv(int s, int i, int v) {
//	if (v == 0) {
//		return s & (~(1 << i));
//	}
//	else {
//		return s | (1 << i);
//	}
//}
//signed main() {
//	while (cin >> n >> m && (n != 0 || m != 0)) {
//		memset(dp, 0, sizeof(dp));
//		for (int s = 0; s < (1 << m); s++) {
//			backup[s] = 1;
//		}
//		for (int i = n - 1; i >= 0; i--) {
//			for (int s = 0; s < (1 << m); s++) {
//				dp[m][s] = backup[s];
//			}
//			for (int j = m - 1; j >= 0; j--) {
//				for (int s = 0; s < (1 << m); s++) {
//					int ans = 0;
//					if (get(s, j) == 1) {
//						ans = dp[j + 1][setv(s, j, 0)];
//					}
//					else {
//						if (i+1< n)ans += dp[j + 1][setv(s, j, 1)];
//						if (get(s, j + 1) == 0) {
//							ans += dp[j + 2][s];
//						}
//					}
//					dp[j][s] = ans;
//				}
//			}
//			for (int s = 0; s < (1 << m); s++) {
//				backup[s] = dp[0][s];
//			}
//		}
//		cout << dp[0][0] << '\n';
//	}
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//vector<int>up;
//vector<int>down;
//int n, m, k;
//const int mod = 376544743;
//int dp[101][9][257][257];
//int setv(int s, int i, int v) {
//	if (v == 0) {
//		return s & (~(1 << i));
//	}
//	else {
//		return s | (1 << i);
//	}
//}
//int get(int s1, int s2, int i) {
//	if (i < 0) {
//		return -1;
//	}
//	return ((s1 >> i) & 1) + ((s2 >> i) & 1) * 2;
//}
//int f(int i, int j, int s1, int s2) {
//	if (dp[i][j][s1][s2] != -1)return dp[i][j][s1][s2];
//	if (i == n-1) {
//		return 1;
//	}
//	if (j == m) {
//		return f(i + 1, 0, s1, s2);
//	}
//	int ans = 0;
//	int d = (i == n - 2 ? down[j] : -1);
//	int u = get(s1, s2, j), l = get(s1, s2, j - 1);
//	for (int c = 0; c <= k-1; c++) {
//		if (c != u && c != l&&c!=d) {
//			ans = (ans + f(i, j + 1, setv(s1, j, c & 1), setv(s2, j, c>> 1))) % mod;
//		}
//	}
//	dp[i][j][s1][s2] = ans;
//	return ans;
//}
//int main() {
//	memset(dp, -1, sizeof(dp));
//	cin >> n >> m >> k;
//	up.resize(m + 1);
//	down.resize(m + 1);
//	for (int i = 0; i < m; i++) {
//		cin >> up[i];
//	}
//	for (int i = 0; i < m; i++) {
//		cin >> down[i];
//	}
//	//-----------------
//	{
//		if (k == 2) {
//			if (n % 2 == 0) {
//				if (up[0] == down[0]) {
//					cout << 0 << '\n';
//					return 0;
//				}
//				for (int i = 1; i < m; i++) {
//					if (up[i] == up[i - 1] || down[i] == down[i - 1]) {
//						cout << 0 << '\n';
//						return 0;
//					}
//				}
//			}
//			else {
//				if (up[0] != down[0]) {
//					cout << 0 << '\n';
//					return 0;
//				}
//				for (int i = 1; i < m; i++) {
//					if (up[i] == up[i - 1] || down[i] == down[i - 1]) {
//						cout << 0 << '\n';
//						return 0;
//					}
//				}
//			}
//			cout << 1 << '\n';
//			return 0;
//		}
//	}
//	//--------------
//	int s1 = 0,s2=0;
//	for (int i = 0; i < m; i++) {
//		s1 |= (up[i] & 1) << i;
//		s2 |= (up[i] >> 1) << i;
//	}
//	cout << f(1, 0,s1,s2 )<<'\n';
//}



//#include<bits/stdc++.h>
//using namespace std;
//vector<int>up;
//vector<int>down;
//int n, m, k;
//const int mod = 376544743;
//int dp[9][257][257];
//int setv(int s, int i, int v) {
//	if (v == 0) {
//		return s & (~(1 << i));
//	}
//	else {
//		return s | (1 << i);
//	}
//}
//int get(int s1, int s2, int i) {
//	if (i < 0) {
//		return -1;
//	}
//	return ((s1 >> i) & 1) + ((s2 >> i) & 1) * 2;
//}
//int main() {
//	memset(dp, -1, sizeof(dp));
//	cin >> n >> m >> k;
//	up.resize(m + 1);
//	down.resize(m + 1);
//	for (int i = 0; i < m; i++) {
//		cin >> up[i];
//	}
//	for (int i = 0; i < m; i++) {
//		cin >> down[i];
//	}
//	//-----------------
//	{
//		if (k == 2) {
//			if (n % 2 == 0) {
//				if (up[0] == down[0]) {
//					cout << 0 << '\n';
//					return 0;
//				}
//				for (int i = 1; i < m; i++) {
//					if (up[i] == up[i - 1] || down[i] == down[i - 1]) {
//						cout << 0 << '\n';
//						return 0;
//					}
//				}
//			}
//			else {
//				if (up[0] != down[0]) {
//					cout << 0 << '\n';
//					return 0;
//				}
//				for (int i = 1; i < m; i++) {
//					if (up[i] == up[i - 1] || down[i] == down[i - 1]) {
//						cout << 0 << '\n';
//						return 0;
//					}
//				}
//			}
//			cout << 1 << '\n';
//			return 0;
//		}
//	}
//	//--------------
//	vector<vector<int>>backup(1 << m,vector<int>(1<<m,1));
//	for (int i = n - 2; i >= 1; i--) {
//		for (int s1 = 0; s1 < (1 << m); s1++) {
//			for (int s2 = 0; s2 < (1 << m); s2++) {
//				dp[m][s1][s2] = backup[s1][s2];
//			}
//		}
//		for (int j = m-1; j >= 0; j--) {
//			for (int s1 = 0; s1 < (1 << m); s1++) {
//				for (int s2 = 0; s2 < (1 << m); s2++) {
//					int ans = 0;
//					int d = (i == n - 2 ? down[j] : -1);
//					int u = get(s1, s2, j), l = get(s1, s2, j - 1);
//					for (int c = 0; c <= k - 1; c++) {
//						if (c != u && c != l && c != d) {
//							ans = (ans + dp[j + 1][setv(s1, j, c & 1)][setv(s2, j, c >> 1)]) % mod;
//						}
//					}
//					dp[j][s1][s2] = ans;
//				}
//			}
//		}
//		for (int s1 = 0; s1 < (1 << m); s1++) {
//			for (int s2 = 0; s2 < (1 << m); s2++) {
//				backup[s1][s2] = dp[0][s1][s2];
//			}
//		}
//	}
//	int ts1 = 0,ts2=0;
//	for (int i = 0; i < m; i++) {
//		ts1 |= (up[i] & 1) << i;
//		ts2 |= (up[i] >> 1) << i;
//	}
//	cout << dp[0][ts1][ts2] << '\n';
//}



//互不侵犯
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n, k;
//int get(int s, int i) {
//	return (s >> i) & 1;
//}
//int setv(int s, int i, int v) {
//	if (i < 0)return s;
//	if (i >= n)return s;
//	if (v == 0) {
//		return s & (~(1 << i));
//	}
//	else {
//		return s | (1 << i);
//	}
//}
//int dp[10][10][1 << 10][82];
//int f(int i, int j, int s, int k) {
//	if (k == 0) { 
//		return 1;
//	}
//	if (i == n) {
//		return 0;
//	}
//	if (j >= n) {
//		return f(i + 1, 0, s, k);
//	}
//	if (dp[i][j][s][k] != -1)return dp[i][j][s][k];
//	int ans = f(i,j+1,setv(s,j,0), k);//这样写如果上一行有1不会清除
//	if (get(s, j) == 0) {
//		ans = ans + f(i, j + 2, setv(setv(setv(s,j,1),j-1,1),j+1,1), k - 1);
//	}
//	dp[i][j][s][k] = ans;
//	return ans;
//}
//signed main() {
//	memset(dp, -1, sizeof(dp));
//	cin >> n >> k;
//	cout << f(0, 0, 0, k) << '\n';
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n, k;
//int get(int s, int i) {
//	return (s >> i) & 1;
//}
//int setv(int s, int i, int v) {
//	if (i < 0)return s;
//	if (i >= n)return s;
//	if (v == 0) {
//		return s & (~(1 << i));
//	}
//	else {
//		return s | (1 << i);
//	}
//}
//int dp[11][1 << 11][101];
//signed main() {
//	cin >> n >> k;
//	for (int s = 0; s < (1 << n); s++) {
//		dp[0][s][0] = 1;
//	}
//	for (int i = n - 1; i >= 0; i--) {
//		for (int s = 0; s < (1 << n); s++) {
//			for (int m = 0; m <= k; m++) {
//				dp[n][s][m] = dp[0][s][m];
//				dp[n + 1][s][m] = dp[0][s][m];
//			}
//		}
//		for (int j = n - 1; j >= 0; j--) {
//			for (int s = 0; s < (1ll << n); s++) {
//				for (int m = 0; m <= k; m++) {
//					if (m == 0) {
//						dp[j][s][m] = 1;
//					}
//					else {
//						int ans = dp[j + 1][setv(s, j, 0)][m];
//						if (get(s, j) == 0) {
//							ans = ans + dp[j + 2][setv(setv(setv(s, j, 1), j - 1, 1), j + 1, 1)][m - 1];
//						}
//						dp[j][s][m] = ans;
//					}
//				}
//			}
//		}
//	}
//	cout << dp[0][0][k] << '\n';
//}