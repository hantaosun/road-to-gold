//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int a, b, c;
//	cin >> a >> b >> c;
//	int s = a + b + c;
//	if (s % 3 != 0) {
//		cout << "NO\n";
//		return;
//	}
//	if (a > s / 2 || b > s / 3) {
//		cout << "NO\n";
//		return;
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
//#define int long long
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 2);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	vector<int>bsum(n+2);
//	for (int i = n; i >= 1; i--) {
//		bsum[i] = a[i] + bsum[i + 1];
//	}
//	vector<int>pmax(n + 2);
//	for (int i = 1; i <= n; i++) {
//		pmax[i] = max(a[i], pmax[i - 1]);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (pmax[n - i] > a[n - i + 1]) {
//			cout << bsum[n - i + 1] - a[n - i + 1] + pmax[n - i] << " ";
//		}
//		else {
//			cout << bsum[n - i + 1] << ' ';
//		}
//	}cout << '\n';
//}
//signed main() {
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
//	s = ' ' + s;
//	if (s[n] == 'A' && s[1] == 'A') {
//		cout << "Alice\n";
//		return;
//	}
//	if (s[n] == 'B' && s[1] == 'B') {
//		cout << "Bob\n";
//		return;
//	}
//	if (s[n] == 'A' && s[1] == 'B') {
//		if (s[n - 1] == 'A') {
//			cout << "Alice\n";
//		}
//		else {
//			cout << "Bob\n";
//		}
//		return;
//	}
//	if (s[n] == 'B' && s[1] == 'A') {
//		for (int i = 2; i <= n - 1; i++) {
//			if (s[i] == 'B') {
//				cout << "Bob\n";
//				return;
//			}
//		}
//		cout << "Alice\n";
//		return;
//	}
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 9999999;
//int prime[N];//得到至少4e5个质数
//bool vis[N];
//int cnt = 0;
//void eular() {
//	for (int i = 2; i<N; i++) {
//		if (!vis[i]) {
//			prime[++cnt] = i;
//		}
//		for (int j = 1; j <= cnt; j++) {
//			if (prime[j] * i > N)break;
//			vis[prime[j] * i]=1;
//			if (i % prime[j] == 0)break;
//		}
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	int coin = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	sort(a.begin() + 1, a.end(), [&](int x,int y) {
//		return x > y;
//		});
//	for (int i = 1; i <= n; i++) {
//		if (a[i]+coin >= prime[i]) {
//			coin += a[i] - prime[i];
//		}
//		else {
//			cout << n - i + 1 << '\n';
//			return;
//		}
//	}
//	cout << 0 << '\n';
//}
//signed main() {
//	eular();
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//int nex[N][26];//当前字符右侧最近的j号字符的位置
//int nexM[N];
//int last[26];
//int dp[N];//当前格子要往右几步到INT_MAX
//int n, k;
//void prepare(string s) {
//	for (int i = 1; i <=n; i++) {
//		int cur = s[i] - 'a';
//		for (int j = last[cur]; j < i; j++) {
//			nex[j][cur] = i;
//		}
//		last[cur] = i;
//	}
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j < k; j++) {
//			if (nex[i][j] == 0) {
//				nexM[i] = INT_MAX;
//			}
//			else {
//				nexM[i] = max(nexM[i], nex[i][j]);
//			}
//		}
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n >> k;
//	string s;
//	cin >> s;
//	s = ' ' + s;
//	prepare(s);
//	//{
//	//	for (int i = 0; i <= n; i++) {
//	//		for (int j = 0; j < k; j++) {
//	//			cout << nex[i][j] << " ";
//	//		}cout << '\n';
//	//	}
//	//	cout << "-------------\n";
//	//	for (int i = 1; i <= n; i++) {
//	//		cout << nexM[i] << '\n';
//	//	}
//	//	cout << "-------------\n";
//	//}
//	dp[n] = 1;
//	for (int i = n - 1; i >= 1; i--) {
//		if (nexM[i] == INT_MAX)dp[i] = 1;
//		else {
//			dp[i] = dp[nexM[i]] + 1;
//		}
//	}
//	int q;
//	string t;
//	cin >> q;
//	for (int i = 1; i <= q; i++) {
//		cin >> t;
//		int cur = 0;
//		for (int j = 0; j < t.size(); j++) {
//			//cout << cur << " "<<t[j]-'a'<<" cur\n";
//			cur = nex[cur][t[j] - 'a'];
//			if (cur == 0) {
//				break;
//			}
//		}
//		//cout << cur << "***\n";
//		if (cur == 0) {
//			cout << 0 << '\n';
//			continue;
//		}
//		else {
//			//int cnt = 0;
//			//while (cur != INT_MAX) {
//			//	cur = nexM[cur];
//			//	cnt++;
//			//}
//			//cout << cnt << '\n';
//			cout << dp[cur] << '\n';
//		}
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//vector<pair<string, int>>aux;
//string S(int x) {
//	string t = to_string(x) + to_string(x + 1);
//	sort(t.begin(), t.end());
//	return t;
//}
//long long getNum(string s) {
//	int i = 0;
//	while (s[i] == '0') {
//		i++;
//	}
//	swap(s[0], s[i]);
//	return stoll(s);//string to long long
//}
//void get(string cur, bool nine) {//当前来到的位数 是否进入填9阶段？
//	if (*max_element(cur.begin(), cur.end()) > '0') {//不是0
//		long long x = getNum(cur);
//		aux.push_back(make_pair(S(x), x));
//	}
//	if (cur.size() < 9) {
//		if (nine) {
//			get(cur + '9', true);
//		}
//		else {
//			for (char c = '0'; c <= '9'; c++) {
//				get(cur + string(1, c), c < cur.back());
//			}
//		}
//	}
//}
//int main() {
//	for (char c = '0'; c <= '9'; c++) {
//		get(string(1, c), false);
//	}
//	sort(aux.begin(), aux.end());
//	vector<long long>aux2;
//	for (int i = 0; i < aux.size(); i++) {
//		if (i == 0 || aux[i].first != aux[i - 1].first) {
//			aux2.push_back(aux[i].second);
//		}
//	}
//	sort(aux2.begin(), aux2.end());
//
//	int t;
//	cin >> t;
//	long long n;
//	while (t--) {
//		cin >> n;
//		cout << upper_bound(aux2.begin(), aux2.end(), n) - aux2.begin() << '\n';
//	}
//}