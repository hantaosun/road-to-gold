//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void donkey() {
//	int n, w;
//	cin >> n >> w;
//	cout << n / w * (w - 1) + n % w << endl;
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		donkey();
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void donkey() {
//	int n, x,y;
//	cin >> n >> x>>y;
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		b[i] = a[i] / x * y;
//		sum += b[i];
//	}
//	int ans = -1;
//	for (int i = 1; i <= n; i++) {
//		ans = max(ans, sum - b[i] + a[i]);
//	}
//	cout << ans << endl;
//	
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		donkey();
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n, k;
//vector<int>g;
//vector<int>tmp;
//bool check(int m) {
//	tmp.clear();
//	//cout << m << "m\n";
//	for (int i = 0; i <m; i++) {
//		int cur = g[i];
//		int j = i;
//		while (j < n) {
//			cur &= g[j];
//			j += m;
//		}
//		if (cur != 0) {
//			tmp.push_back(cur);
//		}
//		else {
//			return false;
//		}
//	}
//	return true;
//}
//void donkey() {
//	cin >> n >> k;
//	string s;
//	g.assign(n + 1, 0);
//	for (int i = 1; i <= k; i++) {
//		cin >> s;
//		for (int j = 0; j < n; j++) {
//			g[j] |= 1 << (s[j] - 'a');
//		}
//	}
//	for (int i = 1; i<= n; i++) {
//		if (n % i == 0) {
//			if (check(i)) {
//				string ans = "";
//				for (auto v : tmp) {	
//					for (int j = 0; j < 26; j++) {
//						if ((v >> j) & 1) {
//							ans += char('a' + j);
//							break;
//						}
//					}
//				}
//				//cout << ans << "ans\n";
//				for (int j = 1; j <= n / i; j++) {
//					cout << ans;
//				}cout << endl;
//				return;
//			}
//		}
//	}
//	cout << -1 << endl;
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		donkey();
//	}
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n, m;
//vector<vector<int>>g;
//vector<int>sum;
//void donkey() {
//	cin >> n >> m;
//	g.assign(n + 1, vector<int>(m + 1));
//	sum.assign(n + 1,0);
//	int tot = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> g[i][j];
//			if (g[i][j] == 1) {
//				tot++; sum[i]++;
//			}
//		}
//	}
//	int cur = 0;
//	int dn = 0;
//	
//	for (int i = 1; i <= n; i++) {
//		if (cur + sum[i] > tot / 2) {
//			dn = i - 1;
//			break;
//		}
//		else {
//			cur += sum[i];
//		}
//	}
//	int rr = 0;
//	for (int j = m; j >= 1; j--) {
//		if (cur >= tot / 2) {
//			rr = j;
//			break;
//		}
//		if (g[dn + 1][j] == 1) {
//			cur ++;
//		}
//	}
//	cout << cur * (tot - cur) << endl;
//	for (int i = 1; i <= dn; i++) {
//		cout << 'D';
//	}
//	for (int i = 1; i <= rr; i++) {
//		cout << 'R';
//	}
//	cout << 'D';
//	for (int i = rr + 1; i <= m; i++) {
//		cout << 'R';
//	}
//	for (int i = dn + 2; i <= n; i++) {
//		cout << 'D';
//	}cout << endl;
//
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		donkey();
//	}
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n, m;
//void donkey() {
//	cin >> n >> m;
//	vector<vector<int>>a(n + 1, vector<int>(m + 1));
//	vector<vector<int>>from(n + 1, vector<int>(m + 1));
//	vector<vector<int>>dp(n + 1, vector<int>(m + 1, LLONG_MIN));
//	vector<vector<int>>dpc(n + 1, vector<int>(m + 1, 0));
//	vector<vector<int>>dpc1(n + 1, vector<int>(m + 1, 0));
//	vector<vector<bool>>inq(n + 1, vector<bool>(m + 1, 0));
//	dp[0][1] = 0;
//	dp[1][0] = 0;
//	dpc[0][1] = 1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> a[i][j];
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			if (dp[i][j - 1] > dp[i - 1][j]) {
//				from[i][j] = 1;
//				dpc[i][j] += dpc[i][j - 1];
//			}
//			else if (dp[i - 1][j] > dp[i][j - 1]) {
//				from[i][j] = 2;
//				dpc[i][j] += dpc[i - 1][j];
//			}
//			else {
//				from[i][j] = 3;
//				dpc[i][j] += dpc[i - 1][j] + dpc[i][j - 1];
//			}
//			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
//		}
//	}
//	dpc1[n][m] = 1;
//	queue<pair<int, int>>q;
//
//	q.push({ n,m });
//	while (!q.empty()) {
//		int siz = q.size();
//		while (siz--) {
//			auto [x, y] = q.front();
//			q.pop();
//			inq[x][y] = 0;
//			if (from[x][y] == 1) {
//				if (!inq[x][y - 1]) {
//					q.push({ x,y - 1 });
//					inq[x][y-1] = 1;
//				}
//				dpc1[x][y - 1] += dpc1[x][y];
//			}
//			else if (from[x][y] == 2) {
//				if (!inq[x - 1][y]) {
//					q.push({ x - 1,y });
//					inq[x-1][y]=1;
//				}
//				dpc1[x - 1][y] += dpc1[x][y];
//			}
//			else if (from[x][y] == 3) {
//				if (!inq[x][y - 1]) {
//					q.push({ x,y - 1 });
//					inq[x][y - 1] = 1;
//				}
//				dpc1[x][y - 1] += dpc1[x][y];
//				if (!inq[x - 1][y]) {
//					q.push({ x - 1,y });
//					inq[x - 1][y] = 1;
//				}
//				dpc1[x - 1][y] += dpc1[x][y];
//			}
//		}
//	}
//	//{
//	//	for (int i = 1; i <= n; i++) {
//	//		for (int j = 1; j <= m; j++) {
//	//			cout << dp[i][j] << " ";
//	//		}cout << endl;
//	//	}cout << endl;
//	//	for (int i = 1; i <= n; i++) {
//	//		for (int j = 1; j <= m; j++) {
//	//			cout << dpc[i][j] << " ";
//	//		}cout << endl;
//	//	}cout << endl;
//	//	for (int i = 1; i <= n; i++) {
//	//		for (int j = 1; j <= m; j++) {
//	//			cout << dpc1[i][j] << " ";
//	//		}cout << endl;
//	//	}cout << endl;
//	//}
//	auto run = [&](int xx, int yy)->int {
//		a[xx][yy] = -a[xx][yy];
//		vector<vector<int>>dp1(dp);
//		for (int i = xx; i <= n; i++) {
//			for (int j = yy; j <= m; j++) {
//				dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + a[i][j];
//			}
//		}
//		a[xx][yy] = -a[xx][yy];
//		//for (int i = 1; i <= n; i++) {
//		//	for (int j = 1; j <= m; j++) {
//		//		cout << dp1[i][j] << " ";
//		//	}cout << endl;
//		//}cout << endl;
//		return dp1[n][m];
//		};
//	int ans = dp[n][m];
//	//ans = min(ans, run(1, 1));
//	//ans = min(ans, run(n, m));
//	//int mxx=-1, mxy=-1;
//	//int mx = LLONG_MIN;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			if (dpc[i][j]*dpc1[i][j] == dpc[n][m]&&a[i][j]>0&&dp[n][m]-2*a[i][j]<ans) {
//				//cout << i << " " << j << "**\n";
//				ans = min(run(i, j), ans);
//				//cout << ans << endl;
//		/*		if (a[i][j] > mx) {
//					mx = a[i][j];
//					mxx = i;
//					mxy = j;
//				}*/
//			}
//		}
//	}
//	//if (mx != LLONG_MIN) {
//	//	ans = min(ans, run(mxx, mxy));
//	//}
//	cout << ans << endl;
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	while (t--) {
//		donkey();
//	}
//}
//1
//3 3
//1 3 3
//3 4 6
//2 -1 5