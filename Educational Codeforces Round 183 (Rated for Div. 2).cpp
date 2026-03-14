//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	cout << (3 - n % 3) % 3 << "\n";
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	string s;
//	cin >> s;
//	s = " " + s;
//	int top=0, bot = 0;
//	int unk = 0;
//	for (int i = 1; i <= k; i++) {
//		if (s[i] == '0')top++;
//		else if (s[i] == '1') {
//			bot++;
//		}
//		else {
//			unk++;
//		}
//	}
//	if (k == n) {
//		for (int i = 1; i <= n; i++) {
//			cout << "-";
//		}
//		cout << "\n";
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (top >= i || bot > n - i) {
//			cout << '-';
//		}
//		else if(top+unk>=i||bot+unk>n-i){
//			cout << '?';
//		}
//		else {
//			cout << '+';
//		}
//	}
//	cout << "\n";
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s = " " + s;
//	int ca=0, cb = 0;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == 'a')ca++;
//		else {
//			cb++;
//		}
//	}
//	if (ca == n || cb == n) {
//		cout << -1 << "\n";
//		return;
//	}
//	if (ca == cb) {
//		cout << 0 << "\n";
//		return;
//	}
//	vector<int>psum(n + 2);//前缀a-b的数量
//	vector<int>bsum(n + 2);
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == 'a') {
//			psum[i] = psum[i - 1] + 1;
//		}
//		else {
//			psum[i] = psum[i - 1] - 1;
//		}
//	}
//	for (int i = n; i >= 1; i--) {
//		if (s[i] == 'b') {
//			bsum[i] = bsum[i + 1] + 1;
//		}
//		else {
//			bsum[i] = bsum[i + 1] - 1;
//		}
//	}
//	int ans = LLONG_MAX;
//	map<int,vector<int>>mp;
//	for (int i = 1; i <= n+1; i++) {
//		mp[bsum[i]].push_back(i);
//	}
//	for (int i = 1; i <= n+1; i++) {
//		if (!mp.count(psum[i-1]))continue;
//		auto it = lower_bound(mp[psum[i - 1]].begin(), mp[psum[i - 1]].end(),i);
//		if (it == mp[psum[i - 1]].end())continue;
//		ans = min(ans, *it - i);
//	}
//	cout << (ans == LLONG_MAX||ans==n ? -1 : ans) << '\n';
//
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
//using namespace std;
//int b[31];
//int n,k;
////void prt(int mn, int r) {//最大值mx构造逆序对为r
////	int len = n - mn + 1;
////	int need = len * (len - 1) / 2-r;//要去掉几个逆序对
////	vector<int>vec;
////	int t = need;
////	int sum = 0;
////	for (int i = 30; i >= 2; i--) {
////		if (t - b[i] >= 0) {
////			t -= b[i];
////			vec.push_back(i);
////			sum += i;
////		}
////	}
////	if (t > 0) {
////		vec.push_back(2);
////		sum += 2;
////	}
////	if (sum <= n - mn + 1) {
////		int cur = n;
////		for (auto v : vec) {
////			for (int i = cur - v + 1; i <= cur; i++) {
////				cout << i << " ";
////			}
////			cur -= v;
////		}
////		for (int i = cur; i >= mn; i--) {
////			cout << i << " ";
////		}
////		return;
////	}
////	if (r == 0) {
////		for (int i = mn; i <= n; i++) {
////			cout << i << " ";
////		}return;
////	}
////	if (need == 0) {
////		for (int i = n; i >= mn; i--)cout << i << " ";
////		return;
////	}
////	cout << mn << " " << r << "%%\n";
////	cout << need << "&&\n";
////	for (int i = 30; i >= 1; i--) {
////		if (b[i] < need) {
////			
////			cout << i << " " << b[i] << " " << b[i + 1] << " " << need << "***\n";
////			prt(n-i, b[i + 1] - need);
////			//cout << "hahs\n";
////			for (int j = n-i-1; j >=mn; j--) {
////				cout <<j << " ";
////			}
////			break;
////		}
////	}
////}
//void solve() {
//	cin >> n >> k;
//	if (k < n - 1 && k != 0) {
//		cout << 0 << "\n";
//		return;
//	}
//	if (k == 0) {
//		for (int i = 1; i <= n; i++) {
//			cout << i << " ";
//		}
//		cout << "\n";
//		return;
//	}
//	//prt(1, k);
//	//cout << "\n";
//	
//}
//void prepare() {
//	for (int i = 2; i <= 30; i++) {
//		b[i] = i * (i - 1) / 2;
//	}
//}
//int main() {
//	prepare();
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//bool dp[31][466];
//void prepare() {
//	dp[0][0] = true;
//	for (int i = 0; i <= 30; i++) {
//		for (int j = 1; i + j <= 30; j++) {
//			for (int k = j * (j + 1) / 2; k < 466; k++)
//			dp[i + j][k] |= dp[i][k-j*(j+1)/2];
//		}
//	}
//}
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	k = n * (n + 1) / 2-k;
//	if (!dp[n][k]) {
//		cout << 0 << '\n';
//		return;
//	}
//	vector<int>ans;
//	for (int i = 1; i <= n; i++) {
//		if (dp[n - i][k - i * (i + 1) / 2]) {
//			k -= i * (i + 1) / 2;
//			n -= i;
//			for (int j = 1; j <= i; j++) {
//				ans.push_back(n + j);
//			}
//			i--;
//		}
//	}
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i] << ' ';
//	}
//	cout << '\n';
//}
//signed main() {
//	prepare();
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}