//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	if (n == 1){
//		cout << 1 << endl;
//		return;
//	}
//	int ans = 0;
//	vector<double>dp(n+1);
//	dp[n] = 1;
//	for (int i = n - 1; i >= 1; i--) {
//		double p = double(a[i]) / 1000;
//		dp[i] = min(1+dp[i+1], 1 - p + 21 * p + p * dp[i + 1]);
//	}
//	cout << dp[1] << endl;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int T;
//	cin >> T;
//	cout << std::fixed << std::setprecision(10);
//	while (T--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 1e9 +7;
//int qmi(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = (ans * a)%mod;
//		}
//		a = (a * a)%mod;
//		b >>= 1;
//	}
//	return ans;
//}
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<int>q(n + 1);
//	vector<int>k(m + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> q[n];
//	}
//	for (int i = 1; i <= m; i++) {
//		cin >> k[i];
//	}
//	int ans = 1;
//	for (int i = 1;i<= n; i++) {
//		ans = (ans * i)%mod;
//	}
//	cout << qmi(ans, m) << endl;
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//vector<int>a;
//int n, m, k, p;
//bool check(int r) {//r个月能不能收齐m元
//	int ans = 0;
//	int people = 0;
//	vector<int>rest;
//	for (int i = 1; people <= p * r && i <= n; i++) {
//		int t = a[i];
//		if (people + min(a[i] / k, r) > p * r) {
//			ans += (p * r - people) * k;
//			people += p * r - people;
//		}
//		else {
//			people += min(a[i] / k, r);
//			ans += min(a[i] / k, r) * k;
//			t -= min(a[i] / k, r) * k;
//			if (min(a[i] / k, r) < r) {
//				rest.push_back(t);
//			}
//		}
//
//	}
//	sort(rest.begin(), rest.end(), [&](int x, int y) {
//		return x > y;
//		});
//	for (int i = 0; people < p * r && i < rest.size(); i++) {
//		ans += min(k, rest[i]);
//		people++;
//	}
//	//cout << r << " " << ans << " " << m << endl;
//	if (ans >= m)return true;
//	return false;
//}
//void solve() {
//
//	cin >> n >> m >> k >> p;
//	a.resize(n + 1);
//	sort(a.begin() + 1, a.end(), [&](int x, int y) {
//		return x > y;
//		});
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int l = 0, r = (m + k - 1 / k), mid, ans = -1;
//	while (l <= r) {
//		mid = l + r >> 1;
//		if (check(mid)) {
//			ans = mid;
//			r = mid - 1;
//		}
//		else {
//			l = mid + 1;
//		}
//	}
//	cout << ans << endl;
//}
//signed main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}

//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n+1), b(n+1);
//	for (int i = 1, u; i <= n; i++) {
//		cin >> u;
//		a[u] = i;
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	int cnt = 1;
//	for (int i = 1; i < n; i++) {
//		if (a[b[i]] + 1 != a[b[i + 1]])cnt++;
//	}
//	cout << cnt << endl;
//}
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//bool cmp(int x, int y) {
//	return x > y;
//}
//void solve() {
//	int a, b, c, d;
//	cin >> a >> b >> c >> d;
//	vector<int>item11;
//	vector<int>item12;
//	vector<int>item13;
//	vector<int>item22;
//	int k11,k12,k13,k22;
//	cin >> k11;
//	item11.assign(k11 + 1,0);
//	for (int i = 1; i <= k11; i++) {;
//		cin >> item11[i];
//	}
//	cin >> k12;
//	item12.assign(k12 + 1, 0);
//	for (int i = 1; i <= k12; i++) {
//		cin >> item12[i];
//	}
//	cin >> k13;
//	item13.assign(k13 + 1, 0);
//	for (int i = 1; i <= k13; i++) {
//		cin >> item13[i];
//	}
//	cin >> k22;
//	item22.assign(k22 + 1, 0);
//	for (int i = 1; i <= k22; i++) {
//		cin >> item22[i];
//	}
//	sort(item11.begin()+1, item11.end(), cmp);
//	sort(item12.begin()+1, item12.end(), cmp);
//	sort(item13.begin()+1, item13.end(), cmp);
//	sort(item22.begin()+1, item22.end(), cmp);
//	int ans=-1;
//	int sum = a + b * 2 + c * 3 + d * 4;
//	for (int i = 1; i < item11.size(); i++)item11[i] += item11[i - 1];
//	for (int i = 1; i < item12.size(); i++)item12[i] += item12[i - 1];
//	for (int i = 1; i < item13.size(); i++)item13[i] += item13[i - 1];
//	for (int i = 1; i < item22.size(); i++)item22[i] += item22[i - 1];
//	
//	
//	for (int i = 0; i <= min(d, k22); i++) {//枚举2*2
//		for (int j = 0; j <= min(c, k13); j++) {//枚举1*3
//			int r22 = d - i;//剩余的2*2格子数
//			int r13 = c - j;//剩余的1*3格子数
//			for (int k = 0; k <= min(r13 + r22 * 2 + b, k12); k++) {//枚举1*2
//				ans = max(ans, item22[i] + item13[j] + item12[k] + item11[min(k11, sum - i * 4 - j * 3 - k * 2)]);
//			}
//		}
//	}
//	cout << ans << endl;
//}
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}



//双端魔咒
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int l, r;
//	vector<>
//}
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}