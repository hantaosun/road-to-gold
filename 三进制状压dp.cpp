//#include<bits/stdc++.h>
//using namespace std;
//int n, m;
//int dp[6][6][730][7][7];
//int get(int s, int bit) {
//	if (bit == 0)return 0;
//	return s / bit % 3;
//}
//int setv(int s, int bit, int v) {
//	return s - get(s, bit) * bit + v * bit;
//}
//int f(int i, int j, int s, int inn, int out, int bit) {
//	if (i == n)return 0;
//	if (j == m)return f(i + 1, 0, s, inn, out, 1);
//	if (dp[i][j][s][inn][out] != -1)return dp[i][j][s][inn][out];
//	int ans = f(i, j + 1, setv(s, bit, 0), inn, out, bit * 3);
//	if (inn > 0 || out > 0) {
//		int up = get(s, bit);
//		int lef = get(s, bit / 3);
//		int neighbour = 0;
//		int cn = 0;
//		if (up == 2) {
//			neighbour += 20;
//			cn++;
//		}
//		else if (up == 1) {
//			neighbour -= 30;
//			cn++;
//		}
//		if (lef == 2) {
//			neighbour += 20;
//			cn++;
//		}
//		else if (lef == 1) {
//			neighbour -= 30;
//			cn++;
//		}
//		if (inn > 0) {
//			ans = max(ans, neighbour + 120-cn*30 + f(i, j + 1, setv(s, bit, 1), inn - 1, out, bit * 3));
//		}
//		if (out > 0) {
//			ans = max(ans, neighbour + 40 +cn*20+ f(i, j + 1, setv(s, bit, 2), inn, out - 1, bit * 3));
//		}
//	}
//	dp[i][j][s][inn][out] = ans;
//	return ans;
//}
//class Solution {
//public:
//	int getMaxGridHappiness(int mm, int nn, int introvertsCount, int extrovertsCount) {
//		memset(dp, -1, sizeof(dp));
//		n = mm;
//		m = nn;
//		return f(0, 0, 0, introvertsCount, extrovertsCount, 1);
//	}
//};



//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int mod = 1e9 + 7;
//int n, m;
//int dp[1005][6][730];
//int get(int s, int bit, int i) {
//    if (i == 0 || bit == 0)return -1;
//    return s / bit % 3;
//}
//int setv(int s, int bit, int v) {
//    return s - get(s, bit, 1) * bit + v * bit;
//}
//ll f(int i, int j, int s, int bit) {
//    if (i == n)return 1;
//    if (j == m)return f(i + 1, 0, s, 1);
//    if (dp[i][j][s] != -1)return dp[i][j][s];
//    ll ans = 0;
//    int u = get(s, bit, i);
//    int l = get(s, bit / 3, 1);
//    for (int k = 0; k <= 2; k++) {
//        if (u != k && l != k) {
//            ans = (ans + f(i, j + 1, setv(s, bit, k), bit * 3)) % mod;
//        }
//    }
//    dp[i][j][s] = ans;
//    return ans;
//}
//class Solution {
//public:
//    int colorTheGrid(int mm, int nn) {
//        memset(dp, -1, sizeof(dp));
//        n = nn;
//        m = mm;
//        return f(0, 0, 0, 1);
//    }
//};


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n, m;
//int bit[] = { 1,3,9,27,81,243,729,2187,6561,19683,59049 };
//int get(int s, int bit) {
//	return (s / bit) % 3;
//}
//int setv(int s, int bit, int v) {
//	return s - get(s, bit) * bit + v * bit;
//}
//int setv1(int s, int i,int v) {
//	if (v == 1) { 
//		return s | (1 << i);
//	}
//	return s & (~(1 << i));
//}
//int g[11][11];
//int dp[11][59050];
//int f(int cur,int s,int t) {
//	if (dp[cur][s]!=-1)return dp[cur][s];
//	bool all_visited = true;
//	for (int i = 0; i < n; i++) {
//		if (get(s, bit[i]) == 0) {
//			all_visited = false;
//			break;
//		}
//	}
//	if (all_visited) {
//		return dp[cur][s] = 0;
//	}
//	int ans = LLONG_MAX;
//	for (int i = 0; i < n; i++) {
//		if (g[cur][i] == -1) continue;
//		int cnt = get(s, bit[i]);
//		if (cnt == 2) continue;
//
//		int ns = setv(s, bit[i], cnt + 1); // 更新i的访问次数
//		int temp = f(i, ns,setv1(t,i,1));
//		if (temp != LLONG_MAX) {
//			if (temp <= LLONG_MAX - g[cur][i]) // 防溢出
//				ans = min(ans, g[cur][i] + temp);
//		}
//	}
//	dp[cur][s] = ans;
//	return ans;
//}
//void solve() {
//	for (int i = 0; i < n; i++) {
//		g[i][i] = 0;
//	}
//	for (int i = 0,u,v,w; i < m; i++) {
//		cin >> u >> v >> w;
//		u--;
//		v--;
//		g[u][v] = w;
//		g[v][u] = w;
//	}
//	int an = LLONG_MAX;
//	for (int i = 0; i < n; i++) {
//		an = min(an,f(i, setv(0, bit[i], 1), setv1(0, i, 1)));
//	}
//	cout << (an == LLONG_MAX ? -1 : an) << '\n';
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	while (cin >> n >> m) {
//		memset(g, -1, sizeof g);
//		memset(dp, -1, sizeof dp);
//		solve();
//	}
//	return 0;
//}