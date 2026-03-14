//Dropping Test
//#include<bits/stdc++.h>
//using namespace std;
//int n, k;
//const double sml = 1e-8;
//bool check(double x, vector<array<double, 3>>& a) {
//	for (int i = 0; i < a.size(); i++) {
//		a[i][2] = a[i][0] - x * a[i][1];
//	}
//	nth_element(a.begin(), a.begin() + n - k, a.end(), [&](auto x, auto y) {
//		return x[2] > y[2];
//		});
//	double sum = 0;
//	for (int i = 0; i < n - k; i++) {
//		sum += a[i][2];
//	}
//	return sum >= 0;
//}
//bool solve() {
//	cin >> n >> k;
//	if (n == 0 && k == 0)return false;
//	vector<array<double, 3>>a(n);//预留一个位置便于二分 别开大，sort时会把0放到前面
//	double l = 0, r = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i][0];
//		r += a[i][0];
//	}
//	for (int i = 0; i < n; i++) {
//		cin >> a[i][1];
//	}
//	if (n - k == 0) {
//		cout << 0 << '\n';
//		return true;
//	}
//	double ans = 0;
//	while (l < r && r - l>sml) {
//		double x = (l + r) / 2;
//		if (check(x, a)) {
//			ans = x;
//			l = x + sml;
//		}
//		else {
//			r = x - sml;
//		}
//	}
//	cout << int(100 * (ans + 0.005)) << endl;
//	return true;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	while (true) {
//		if (!solve()) {
//			break;
//		}
//	}
//}


//Talent Show G
//#include<bits/stdc++.h>
//using namespace std;
//const double sml = 1e-8;
//int n, w;
//bool check(double x, vector<array<double, 3>>& cow) {
//	for (int i = 1; i <= n; i++) {
//		cow[i][2] = cow[i][0] - x * cow[i][1];
//	}
//	vector<vector<double>>dp(n + 2, vector<double>(w + 2, -1e10));
//	dp[0][0] = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= w; j++)dp[i][j] = dp[i - 1][j];
//		for (int j = 0; j <= w; j++) {
//			if (dp[i - 1][j] == -1e10)continue;
//			int nj = j + cow[i][1];
//			if (nj >= w) {
//				dp[i][w] = max(dp[i][w], dp[i - 1][j] + cow[i][2]);
//			}
//			else {
//				dp[i][nj] = max(dp[i][nj], dp[i - 1][j] + cow[i][2]);//注意行内会多次更新dp[i][nj]不能利用dp[i-1][nj];
//			}
//		}
//	}
//	return dp[n][w] >= 0;
//	// vector<double> dp(w + 1, -1e10);
//	// dp[0] = 0;
//	// for (int i = 1; i <= n; i++) {
//	// 	double value = cow[i][2];
//	// 	for (int j = w; j >= 0; j--) {
//	// 		if (dp[j] == -1e10) continue;
//	// 		int j_next = j + cow[i][1];
//	// 		if (j_next > w) j_next = w;
//	// 		if (dp[j_next] < dp[j] + value) {
//	// 			dp[j_next] = dp[j] + value;
//	// 		}
//	// 	}
//	// }
//	// return dp[w] >= 0;
//}
//int main() {
//
//	cin >> n >> w;
//	vector<array<double, 3>>cow(n + 1);
//	double l = 0, r = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> cow[i][1] >> cow[i][0];
//		r += cow[i][0];
//	}
//	double ans = 0;
//	while (l < r && r - l >= sml) {
//		double x = (l + r) / 2;
//		if (check(x, cow)) {
//			ans = x;
//			l = x + sml;
//		}
//		else {
//			r = x - sml;
//		}
//	}
//	cout << int(1000 * ans + 0.00001) << '\n';
//}


//DesertKing
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1005;
//const double sml = 1e-6;
//int n;
//double x[N];
//double y[N];
//double z[N];
//double dist[N][N];
//double cost[N][N];
//bool vis[N];
//double val[N];
//double prim(double x) {
//	for (int i = 1; i <= n; i++) {
//		vis[i] = false;
//		val[i] = cost[1][i] - x * dist[1][i];
//	}
//	vis[1] = true;
//	double sum = 0;
//	for (int i = 1; i <= n - 1; i++) {
//		double minDist = 1e15;
//		int next = 0;
//		for (int j = 1; j <= n; j++) {
//			if (!vis[j] && val[j] < minDist) {
//				minDist = val[j];
//				next = j;
//			}
//		}
//		sum += minDist;
//		vis[next] = true;
//		for (int j = 1; j <= n; j++) {
//			if (!vis[j] && val[j] > cost[next][j] - x * dist[next][j]) {
//				val[j] = cost[next][j] - x * dist[next][j];
//			}
//		}
//	}
//	return sum;
//}
//void solve() {
//	for (int i = 1; i <= n; i++) {
//		cin >> x[i];
//		cin >> y[i];
//		cin >> z[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (i != j) {
//				dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
//				cost[i][j] = abs(z[i] - z[j]);
//			}
//		}
//	}
//	double l = 0, r = 100, x, ans = 0;
//	while (l < r && r - l >= sml) {
//		x = (l + r) / 2;
//		if (prim(x) <= 0) {
//			ans = x;
//			r = x - sml;
//		}
//		else {
//			l = x + sml;
//		}
//	}
//	cout << fixed << setprecision(3) << ans << endl;
//}
//int main() {
//	cin >> n;
//	while (n) {
//		solve();
//		cin >> n;
//	}
//}


