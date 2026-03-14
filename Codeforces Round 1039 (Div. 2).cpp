//#include<bits/stdc++.h>
//#define i64 long long
//using namespace std;
//void solve() {
//	i64 n, c;
//	cin >> n >> c;
//	vector<i64>a(n + 1);
//	int cost = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	sort(a.begin() + 1, a.end(), [&](int x, int y) {return x > y; });
//	int move = 0;
//	int sheng = 0;
//	for (int i = 1; i <= n; i++) {
//		if ((a[i] << move) <= c) {
//			move++;
//			sheng++;
//		}
//	}
//	cout << n - sheng << endl;
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
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	vector<bool>needR(n+1);
//	int up = 1, down = 1;
//	for(int l = 2, r = n; l <= r; l++) {
//		if (a[l] > a[l - 1]) {
//			up++;
//			down = 1;
//		}
//		else {
//			down++;
//			up = 1;
//		}
//		if (up == 5) {
//			if (a[r] > a[l - 1]) {
//				needR[l - 2]=1;
//			}
//			else {
//				needR[l - 1] = 1;
//			}
//			up = 2;
//			r--;
//		}
//		if (down == 5) {
//			if (a[r] < a[l - 1]) {
//				needR[l - 2] = 1;
//			}
//			else {
//				needR[l - 1] = 1;
//			}
//			r--;
//			down = 2;
//		}
//	}
//	int cnt = 0;
//	for (int i = 1; i <= n; i++) {
//		cout << 'L'; cnt++;
//		if (needR[i]) {
//			cout << 'R';
//			cnt++;
//		}
//		if (cnt == n)break;
//	}
//	cout << endl;
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
//	vector<int>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	vector<int>rmax(n + 2);
//	for (int i = n; i >= 1; i--) {
//		rmax[i] = max(rmax[i+1], b[i]);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (rmax[i + 1] >= b[i] * 2) {
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
//#define i64 long long
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<i64>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	vector<i64>dp(n + 1);//以i位置为结尾 l从到1到i所有区间的最长递减子序列的长度和
//	dp[1] = 1;
//	dp[2] = a[1] > a[2] ? 3 : 2;
//	for (int i = 3; i <= n; i++) {
//		dp[i] = 1;
//		if (a[i] < a[i - 1] && a[i] < a[i - 2]) {
//			dp[i] += dp[i - 1] + i - 1;
//		}
//		else if(a[i]<a[i-1]) {
//			dp[i] += dp[i - 1] + i - 1;
//		}
//		else {
//			dp[i] += dp[i - 2] + i - 2;
//			dp[i] += 1;
//		}
//	}
//	i64 ans = 0;
//	for (int i = 1; i <= n; i++) {
//		ans +=dp[i];
//	}
//	cout << ans << endl;
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
//int n, k;
//int r = -1, l = 0;
//bool check(int t,const vector<int>&a) {//检查是否存在大于等于t的中位数
//	vector<int>presum(n+1);
//	//cout << "-----------------------\n";
//	for (int i = 1; i <= n; i++) {
//		presum[i] = presum[i - 1] + (a[i] >= t ? 1 : -1);
//		//cout << presum[i] << " ";
//	}; //cout << endl;
//	int premin = 0;
//	l = 0;
//	for (int i = k; i <= n; i++) {
//		//cout << presum[i] << " " << premin << " " << l << endl;
//		if (presum[i] - premin >= 0) {
//			//cout <<t<<" "<<i << " " << l << " " << presum[i] << " " << premin << "***" << endl;
//			r = i;
//			return true;
//		}
//		if (presum[i - k + 1] < premin) {
//			premin = presum[i - k + 1];
//			l = i - k + 1;
//		}
//	}
//	return false;
//}
//
//void solve() {
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int ans = 1;
//	for (int pw = 1 << 20; pw >= 1; pw >>= 1) {
//		if (ans + pw <= n && check(ans+pw, a)) {
//			ans +=pw;
//		}
//	}
//	check(ans, a);
//	cout << ans <<" "<<l+1<<" "<<r<<"\n";
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define sz(x) int(x.size())
//#define pii pair<int,int>
//using namespace std;
//int n, k;
//vector<int>a;
//vector<pii>ans;
//multiset<int>inf, sup;//维护当前小的一半和大的一半
//void balance() {
//	if (sz(inf)+1 < sz(sup)) {
//		auto it = sup.begin();
//		inf.insert(*it);
//		sup.erase(it);
//	}
//	else if (sz(sup) + 1 < sz(inf)) {
//		auto it = inf.end();
//		it--;
//		sup.insert(*it);
//		inf.erase(it);
//	}
//}
//void add(int x) {
//	if (x < *sup.begin()) {
//		inf.insert(x);
//	}
//	else {
//		sup.insert(x);
//	}
//	balance();
//}
//void del(int x) {
//	if (x >= *sup.begin()) {
//		auto it = sup.find(x);
//		if(it!=sup.end())sup.erase(it);
//	}
//	else {
//		auto it = inf.find(x);
//		if(it!=inf.end())inf.erase(it);
//	}
//	balance();
//}
//void setAns(int ls,int rs) {
//	if (sz(inf) == sz(sup)) {
//		auto it = inf.rbegin();
//		int l = *it, r = *sup.begin();
//		for (int i = l; i <= r; i++) {
//			if (ans[i].first != -1)continue;
//			ans[i].first = ls;
//			ans[i].second = rs;
//		}
//	}
//	else {
//		if (sz(inf) < sz(sup)) {
//			auto t = sup.begin();
//			if (ans[*t].first != -1)return;
//			ans[*t].first = ls;
//			ans[*t].second = rs;
//		}
//		else {
//			auto t = inf.rbegin();
//			if (ans[*t].first != -1)return;
//			ans[*t].first = ls;
//			ans[*t].second = rs;
//		}
//	}
//}
//pair<int, int> check(int t) {
//	vector<int>presum(n + 1);
//	for (int i = 1; i <= n; i++) {
//		presum[i] = presum[i - 1] + (a[i] >= t ? 1 : -1);
//	}
//	int preMin = 0;
//	int l = 0, r;
//	for (r = k; r <= n; r++) {
//		if (presum[r] - preMin >= 0) {
//			return make_pair(l + 1, r);
//		}
//		if (presum[r - k + 1] < preMin) {
//			l = r - k + 1;
//			preMin = presum[r - k + 1];
//		}
//	}
//	return make_pair(-1, -1);
//}
//pair<int, int> check1(int t) {
//	vector<int>presum(n + 1);
//	for (int i = 1; i <= n; i++) {
//		presum[i] = presum[i - 1] + (a[i] <= t ? 1 : -1);
//	}
//	int preMin = 0;
//	int l = 0, r;
//	for (r = k; r <= n; r++) {
//		if (presum[r] - preMin >= 0) {
//			return make_pair(l + 1, r);
//		}
//		if (presum[r - k + 1] < preMin) {
//			l = r - k + 1;
//			preMin = presum[r - k + 1];
//		}
//	}
//	return make_pair(-1, -1);
//}
//pair<int, int> getMaxM() {
//	int l = 1, r = n, m;
//	pii ans;
//	while (l <= r) {
//		m = l + r >> 1;
//		pii a = check(m);
//		if (a.first == -1) {
//			r = m - 1;
//		}
//		else {
//			ans = a;
//			l = m + 1;
//		}
//	}
//	return ans;
//}
//pair<int, int>getMinM() {
//	int l = 1, r = n, m;
//	pii ans;
//	while (l <= r) {
//		m = l + r >> 1;
//		pii a = check1(m);
//		if (a.first == -1) {
//			l = m + 1;
//		}
//		else {
//			ans = a;
//			r = m - 1;
//		}
//	}
//	return ans;
//}
//void debug() {
//	cout << inf.size() << " " << sup.size() << endl;
//	cout << "inf:";
//	for (auto i : inf) {
//		cout << i << " ";
//	}
//	cout << endl;
//	cout << "sup:";
//	for (auto i : sup) {
//		cout << i << " ";
//	}
//	cout << endl;
//	for (int i = 1; i <= n; i++) {
//		if (ans[i].first != -1)cout << '(' << i << "," << ans[i].first << "," << ans[i].second << ')' << " ";
//	}
//	cout << endl;
//}
//void solve() {
//	cin >> n >> k;
//	a.resize(n + 1);
//	ans.assign(n + 1, { -1,-1 });
//	inf.clear();
//	sup.clear();
//	inf.insert(INT_MIN);
//	sup.insert(INT_MAX);//防止初始加入元素时解引用begin()出现报错
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//
//	pii sma = getMinM();
//	pii big = getMaxM();
//
//	//cout << "sma:"<<sma.first << " " << sma.second<< endl;
//	//cout << "big:"<<big.first << " " << big.second<< endl;
//	if (sma.second > big.second) {
//		swap(sma, big);
//	}
//	int l = sma.first, r =l;
//	while (r<=n&&r<= sma.second) {//先将sma内数字加入堆中
//		add(a[r]);
//		//cout << l << " " << r << endl;
//		//debug();
//		r++;
//	}
//	setAns(sma.first, sma.second);
//	//debug();
//	while (r<=n&&r<= big.first) {
//		add(a[r]);
//		setAns(l, r);
//		//cout << l << " " << r << endl;
//		//debug();
//		r++;
//	}
//	while (r<=n&&r <= big.second) {
//		add(a[r]);
//		setAns(l, r);
//		//cout << l << " " << r << endl;
//		//debug();
//		r++;
//	}
//	if (r > big.second)r--;
//	//cout << l << " " << r << endl;
//	//debug();
//	while (l-1>=1&&l > big.first) {
//		add(a[l-1]);
//		l--;
//		setAns(l, r);
//		//cout << l << " " << r << endl;
//		//debug();
//	}
//	//cout << l << " " << r << endl;
//	//debug();
//	while (l<=n&&l < big.first) {
//		del(a[l]);
//		l++;
//		//cout << l << " " << r << endl;
//		//debug();
//		setAns(l, r);
//	}
//	//cout << l << " " << r << endl;
//	//debug();
//	int cnt = 0;
//	for (int i = 1; i <= n; i++) {
//		if (ans[i].first != -1) {
//			cnt++;
//		}
//	}
//	cout << cnt << "\n";
//	for (int i = 1; i <= n; i++) {
//		if (ans[i].first != -1) {
//			cout << i << " " << ans[i].first << " " << ans[i].second<<"\n";
//		}
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}