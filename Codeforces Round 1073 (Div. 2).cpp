//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<pair<int,int>>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i].first;
//		a[i].second = i;
//	}
//	sort(a.begin() + 1, a.end());
//	for (int i = 1; i < n; i++) {
//		if ((a[i].second & 1) == (a[i + 1].second & 1)) {
//			cout << "NO\n";
//			return;
//		}
//	}
//	cout << "YES\n";
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
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	int got0 = 0,got1=0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		if (a[i] == 0) {
//			got0++;
//		}
//		if (a[i] == 1)got1++;
//	}
//	if (got0==1) {
//		cout << "YES\n";
//	}
//	else {
//		if (got1&&got0!=0) {
//			cout << "YES\n";
//		}
//		else cout << "NO\n";
//	}
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
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s = " " + s;
//	int c1 = 0;
//	int lst0 = -1;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == '1') {
//			c1++;
//		}
//		else {
//			lst0 = i;
//		}
//	}
//	if (c1 == 0 || c1 == n || n - lst0==c1) {
//		cout << "Bob\n";
//		return;
//	}
//	cout << "Alice\n";
//	vector<int>ans;
//	for (int i = 1; i <= n - c1; i++) {
//		if (s[i] == '1') {
//			ans.push_back(i);
//		}
//	}
//	for (int i = n - c1 + 1; i <= n; i++) {
//		if (s[i] == '0') {
//			ans.push_back(i);
//		}
//	}
//	cout << ans.size() << endl;
//	for (auto v : ans) {
//		cout << v << " ";
//	}cout << endl;
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
//const int N = 2e5 + 5;
//int st[N][21];
//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s = " " + s;
//	int ans = -1;
//	int cur = 0;
//	vector<int>dp(n + 5);//从i位置往后选能获得的最长合法子序列的长度
//	int cnt = 0;
//	int cr = 0;
//	for (int i = n; i >= 1; i--) {
//		if (s[i] == ')') {
//			cr++;
//		}
//		else{
//			if (cr > 0) {
//				cnt++;
//				cr--;
//			}
//		}
//		dp[i] = cnt;
//	}
//	int rr = n + 1;
//	for (int i = n; i >= 1; i--) {
//		st[i][0] = rr;
//		if (s[i] == ')')rr = i;
//	}
//	for (int i = n; i >= 1; i--) {
//		for (int p = 1; p <= 20; p++) {
//			st[i][p] = st[st[i][p - 1]][p - 1];
//		}
//	}
//	vector<int>lsum(n+1);
//	vector<int>rsum(n+2);
//	vector<int>nxtl(n + 1);
//	int ll = n + 1;
//	for (int i = n; i >= 1; i--) {
//		nxtl[i] = ll;
//		if (s[i] == '(') {
//			ll = i;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		lsum[i] = lsum[i - 1] + (s[i] == '(');
//	}
//	for (int i = 1; i <= n; i++) {
//		rsum[i] = rsum[i - 1] + (s[i] == ')');
//	}
//	for (int i = 1; i < n; i++) {//枚举从第几位开始不同
//		if (s[i] == ')') {
//			int nd = cur + 1;
//			int pos = nxtl[i];
//			for (int p = 20; p >= 0; p--) {
//				if ((1 << p) < nd) {
//					pos = st[pos][p];
//					nd -= (1 << p);
//				}
//			}
//			pos = st[pos][0];
//			if (pos != n + 1&&pos>nxtl[i]) {
//				//cout << i + cur + 1 + dp[pos + 1] * 2 << "^^\n";
//				ans = max(ans, i + cur + 1 + dp[pos + 1]*2+2*min(lsum[pos]-lsum[i],rsum[n]-rsum[pos]-dp[pos+1]));
//			}
//			//cout << ans << "&&\n";
//			//cout << i << " "<<cur<<" " << pos << "**\n";
//		}
//		if (s[i] == '(') {
//			cur++;
//		}
//		else {
//			cur--; 
//		}
//	}
//	cout << ans << endl;
//	for (int i = 1; i <= n; i++) {
//		for (int p = 0; p <= 20; p++) {
//			st[i][p] = 0;
//		}
//	}
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
//const int mod = 998244353;
//int dp[105][105][105][3];
//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s = " " + s;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == '(') {
//			for (int b = 0; b <= n; b++) {
//				for(int )
//				dp[i][]
//			}
//		}
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}