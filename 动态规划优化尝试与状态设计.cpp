//ÕªÓ£ÌÒ
//#include<bits/stdc++.h>
//using namespace std;
//int dp[51][51][51];
//int n;
//int f(int a, int b, int c, vector<vector<int>>& g) {
//    int d = a + b - c;
//    if (dp[a][b][c] != -2) {
//        return dp[a][b][c];
//    }
//    if (a == n || b == n || c == n || d == n || g[a][b] == -1 || g[c][d] == -1) {
//        return dp[a][b][c] = -1;
//    }
//    if (a == n - 1 && b == n - 1)return g[a][b];
//    int get = (a == c && b == d ? g[a][b] : (g[a][b] + g[c][d]));
//    int ans = -1;
//    int next = f(a + 1, b, c + 1, g);
//    next = max(next, f(a, b + 1, c + 1, g));
//    next = max(next, f(a + 1, b, c, g));
//    next = max(next, f(a, b + 1, c, g));
//    if (next != -1) {
//        ans = get + next;
//    }
//    dp[a][b][c] = ans;
//    return ans;
//}
//class Solution {
//public:
//    int cherryPickup(vector<vector<int>>& grid) {
//        for (int i = 0; i <= 50; i++) {
//            for (int j = 0; j <= 50; j++) {
//                for (int k = 0; k <= 50; k++) {
//                    dp[i][j][k] = -2;
//                }
//            }
//        }
//        n = grid.size();
//        int ans = f(0, 0, 0, grid);
//        return ans == -1 ? 0 : ans;
//    }
//};


//ÇàÍÜ¹ýºÓ
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//signed main() {
//	int n, x;
//	cin >> n >> x;
//	vector<int>h(n+2);
//	for (int i = 1; i <= n - 1; i++) {
//		cin >> h[i];
//	}
//	h[n] = 2 * x + 1;
//	int ans = 0;
//	int sum = h[1];
//	for (int l = 1, r = 2; l <= n; l++) {
//		while (sum < x * 2) {
//			sum += h[r++];
//		}
//		ans = max(ans, r - l);
//		sum -= h[l];
//	}
//	cout << ans << '\n';
//}



