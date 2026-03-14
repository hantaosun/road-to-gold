//#include<bits/stdc++.h>
//using namespace std;
//int popcount(int x) {
//	int ans = 0;
//	while (x != 0) {
//		if (x & 1) {
//			ans++;
//		}
//		x >>= 1;
//	}
//	return ans;
//}
//vector<int>status;
//int n, m;
//void dfs(int i, int s) {
//	if (i >= m) { status.push_back(s); return; }
//	dfs(i + 3, s | (1 << i));
//	dfs(i + 1, s);
//}
//int dp[105][100][100];
//int main() {
//
//	cin >> n >> m;
//	vector<int>a(n + 1, 0);
//	for (int i = 1; i <= n; i++) {
//		char c;
//		for (int j = 1; j <= m; j++) {
//			cin >> c;
//			if (c == 'P') {
//				a[i] |= 1 << (j - 1);
//			}
//		}
//	}
//	dfs(0, 0);
//	for (int i = 0; i < status.size(); i++) {
//		int s=status[i]& a[1];
//		for (int j = 0; j < status.size();j++) {
//			int s1 = status[j];
//			if ((s & s1) != 0)continue;
//			dp[1][i][j] = popcount(s);
//		}
//	}
//	for (int i = 2; i <= n; i++) {
//		for (int j = 0; j < status.size();j++) {
//			int s = status[j] & (a[i]);
//			for (int k = 0; k < status.size();k++) {
//				int s1 = status[k];
//				if ((s1 & s) != 0)continue;
//				for (int l = 0; l < status.size();l++) {
//					int s2 = status[l];
//					if ((s2 & s1) != 0 || (s2 & s) != 0)continue;
//					dp[i][j][k] = max(dp[i][j][k],popcount(s)+dp[i - 1][k][l]);
//				}
//			}
//		}
//	}
//
//	int ans = 0;
//	for (int i = 0; i < status.size(); i++) {
//		for (int j = 0; j < status.size();j++) {
//			ans = max(ans, dp[n][i][j]);
//		}
//	}
//	cout << ans << '\n';
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e4 + 5;
//int a[N];
//const int mod = 998244353;
//int dp[N][201][2];
//int pre[202];
//int suf[202];
//void prepare(int i) {
//	for (int v = 1; v <= 200; v++) {
//		pre[v] = (pre[v - 1] + dp[i][v][1])%mod;
//	}
//	for (int v = 200; v >= 1; v--) {
//		suf[v] = (suf[v + 1] + dp[i][v][0])%mod;
//	}
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int v = 1; v <= 200; v++) {
//		dp[0][v][1] = 1;
//	}
//	for (int i = 1; i <= n; i++) {
//		prepare(i - 1);
//		for (int v = 0; v <= 200; v++) {
//			for (int s = 0; s <= 1; s++) {
//				if (a[i]!= 0) {
//					if (a[i] >= v || s == 1) {
//						dp[i][v][s] = dp[i - 1][a[i]][a[i] <= v];
//					}
//				}
//				else {
//					int ans = 0;
//					ans = (ans + suf[v + 1])%mod;
//					/*for (int cur = v + 1; cur <= 200; cur++) {
//						ans = (ans + dp[i - 1][cur][0]) % mod;
//					}*/
//					if (v != 0) {
//						ans = (ans + dp[i - 1][v][1]) % mod;
//					}
//					
//					if (s == 1&&v>0) {
//						ans = (ans + pre[v - 1])%mod;
//						/*for (int cur = 1; cur < v; cur++) {
//							ans = (ans + dp[i - 1][cur][1]) % mod;
//						}*/
//					}
//					dp[i][v][s] = ans;
//				}
//			}
//		}
//	}
//	cout << dp[n][0][1] << '\n';
//}




//粉刷房子
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//int n, m, tar;
////i后面的房子已经刷完了共用了k种颜色,第i+1个房子颜色为c,左侧后续方案最小花费
//ll dp[105][105][25];
//ll lmin[105][25];
//ll rmin[105][25];
//class Solution {
//public:
//	int minCost(vector<int>& h, vector<vector<int>>& cost, int m, int n, int tar) {
//		h.insert(h.begin(), 0);
//		cost.insert(cost.begin(), { 0,0 });
//		for (int j = 0; j <= tar; j++) {
//			for (int k = 0; k <= n; k++) {
//				if (j == tar) {
//					dp[0][j][k] = 0;
//				}
//				else {
//					dp[0][j][k] = INT_MAX;
//				}
//			}
//		}
//
//		//妈了个臭逼,必须要设置,因为dp里面还用了越界位置的值
//		for (int j = 0; j <= tar; j++) {
//			for (int k = 0; k <= n + 1; k++) {
//				lmin[j][k] = rmin[j][k] = INT_MAX;
//			}
//		}
//		auto prepare = [&](int i)->void {
//
//			for (int j = 0; j <= tar; j++) {
//				for (int k = 1; k <= n; k++) {
//					lmin[j][k] = min(cost[i + 1][k - 1] + dp[i][j][k], lmin[j][k - 1]);
//				}
//			}
//			for (int j = 0; j <= tar; j++) {
//				for (int k = n; k >= 1; k--) {
//					rmin[j][k] = min(cost[i + 1][k - 1] + dp[i][j][k], rmin[j][k + 1]);
//				}
//			}
//			};
//		for (int i = 1; i <= m; i++) {//当前来到位置
//			prepare(i - 1);
//			for (int j = 0; j <= tar; j++) {//当前右侧已用颜色个数
//				for (int k = 0; k <= n; k++) {//当前右侧使用的颜色
//					if (h[i] != 0) {
//						if (j < tar || h[i] == k) {
//							dp[i][j][k] = dp[i - 1][j + (h[i] != k)][h[i]];
//						}
//						else dp[i][j][k] = INT_MAX;
//					}
//					else {
//						if (j == tar && k > 0) {
//							dp[i][j][k] = cost[i][k - 1] + dp[i - 1][j][k];
//						}
//						else {
//							ll ans = INT_MAX;
//							if (k == 0) {
//								ans = min(ans, rmin[j + 1][1]);
//							}
//							else {
//								ans = min(ans, cost[i][k - 1] + dp[i - 1][j][k]);
//								ans = min(ans, lmin[j + 1][k - 1]);
//								ans = min(ans, rmin[j + 1][k + 1]);
//							}// for (int d = 1; d <= n; d++) {
//							// 	ans = min(ans, cost[i][d - 1] + dp[i - 1][j + (d != k)][d]);
//							// }
//							dp[i][j][k] = ans;
//						}
//					}
//				}
//			}
//		}
//		ll ans = dp[m][0][0];
//		if (ans >= INT_MAX) {
//			return -1;
//		}
//		return ans;
//	}
//};


//#include<bits/stdc++.h>
//using namespace std;
//int dp[55][55][1300];
//int g[55][55];
//int help[55][1300];
//int n, m;
//void prepare(int i) {
//	for (int j = 0; j <= m; j++) {
//		for (int k = i; k >= 0; k--) {
//			help[k][j] = max(dp[i][k][j], help[k + 1][j]);
//		}
//	}
//}
//int main() {
//	cin >> n >> m;
//	for (int j = 1; j <= n; j++) {
//		for (int i = n; i >= j;i--) {
//			cin >> g[i][j];
//		}
//	}
//	int sum;
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		sum = 0;
//		prepare(i - 1);
//		for (int j = 0; j <= i; j++) {
//			sum += g[i][j];
//			for (int k = j * (j + 1) / 2; k <= m; k++) {
//				/*int mx = 0;
//				for (int p = max(j - 1, 0); p <= i - 1; p++) {
//					mx = max(mx, dp[i - 1][p][k - j]);
//				}
//				dp[i][j][k] = mx + sum;*/
//				dp[i][j][k] = sum + help[max(j - 1, 0)][k - j];
//				ans = max(ans, dp[i][j][k]);
//			}
//		}
//	}
//	cout << ans << '\n';
//}