//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	int prev = -1;
//	int tmp;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	bool ok = 0;
//	for (int i = 2; i <= n; i++) {
//		if (a[i] < a[i - 1]) {
//			ok = 1;
//			prev = a[i - 1];
//			tmp = a[i];
//			break;
//		}
//	}
//	if (!ok)cout << "NO\n";
//	else {
//		cout << "YES\n";
//		cout << 2 << '\n';
//		cout << prev << " " << tmp << '\n';
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
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	if (a[1] >= a[2]) {
//		cout << a[1] + a[2] << '\n';
//	}
//	else {
//		cout << a[1]*2 << '\n';
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
//#define int long long
//#define pii pair<int,int>
//using namespace std;
//int gcd(int a, int b) {
//	while (b != 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	int ans = 1;
//	for (int i = 2; i <= n; i++) {
//		if (b[i] % b[i - 1] != 0) {
//			int t = b[i - 1] / gcd(b[i], b[i - 1]);
//			ans = ans * t / gcd(ans, t);
//		}
//	}
//	cout << ans << '\n';
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
//bool f(vector<int>a, int ma, int l, int r, int c) {//最多删c个ma的情况下能不能变成回文
//	//cout << l << " " << r << " " << ma << " " << c << endl;
//	if (l >= r)return true;
//	bool ans = false;
//	if (a[r] == a[l]) {
//		ans |= f(a, ma, l + 1, r - 1, c);
//	}
//	else {
//		if (a[r] == ma && c > 0) {
//			ans |= f(a, ma, l, r - 1, c - 1);
//		}
//		if (a[l] == ma && c > 0) {
//			ans |= f(a, ma, l + 1, r, c - 1);
//		}
//	}
//	return ans;
//}
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	vector<array<int, 2>>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		b[i][0] = a[i];
//		b[i][1] = i;
//	}
//	if (k == 1) {
//		cout << "YES\n";
//		return;
//	}
//	sort(b.begin() + 1, b.end(), [&](auto x, auto y) {
//		return x[0] < y[0];
//		});
//	vector<int>pos;//记录最小的k-1个的位置
//	for (int i = 1; i <= k - 1; i++) {
//		pos.push_back(b[i][1]);
//	}
//	int ma = a[pos.back()];
//	vector<int>an;
//	for (int i = 1; i <= n; i++) {
//		if (a[i] == ma)an.push_back(i);
//	}
//	int cnt = 0;
//	for (int i = 0; i < pos.size(); i++) {
//		if (a[pos[i]] != ma) {
//			cnt++;
//			an.push_back(pos[i]);
//		}
//	}
//	sort(an.begin(), an.end(), [&](auto x, auto y) {
//		return x < y;
//		});
//	for (int i = 0; i < an.size(); i++) {
//		an[i] = a[an[i]];
//		//cout << an[i] << " ";
//	}//cout << endl;
//	//cout << ma << " " << int(an.size()) - k + 1 << endl;
//	int l = 0, r = an.size() - 1, c = int(an.size()) - k + 1;
//	while (l < r) {
//		if (an[l] == an[r]) {
//			l++; r--;
//		}
//		else {
//			if (an[l] == ma && c > 0) {
//				l++;
//				c--;
//			}
//			else if (an[r] == ma && c > 0) {
//				r--;
//				c--;
//			}
//			else {
//				cout << "NO\n";
//				return;
//			}
//		}
//	}
//	cout << "YES\n";
//
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
//	vector<int>a(n + 1);
//	vector<int>pre(n + 2);
//	vector<int>suf(n + 2);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		pre[i] = a[i] + pre[i - 1];
//	}
//	for (int i = n; i >= 1; i--) {
//		suf[i] = suf[i + 1] + a[i];
//	}
//	bool ok = 0;
//	bool same = 0;
//	for (int i = 1; i < n; i++) {
//		if ((abs(pre[i] - suf[i + 1]) & 1) == 0) {
//			ok = 1;
//		}
//		if (abs(pre[i] - suf[i + 1]) == 0) {
//			same = 1; break;
//		}
//	}
//	if (same) {
//		cout << 1 << '\n';
//		for (int i = 1; i <= n; i++) {
//			cout << a[i] << " ";
//		}cout << '\n';
//		return;
//	}
//	if (!ok) {
//		cout << -1 << '\n';
//		return;
//	}
//	ok = 0;
//	int pos, v,mid;
//	for (int i = 1; i < n; i++) {
//		if ((abs(pre[i] - suf[i + 1]) & 1) == 0) {
//			int t = (abs(pre[i] - suf[i + 1])) / 2;
//			if (pre[i] > suf[i+1]) {
//				if (i == 1)continue;
//				for (int j = i; j >= 1; j--) {
//					if (pre[j] >= t && suf[j + 1] - suf[i + 1] >= t) {
//						ok = 1;
//						pos = j;
//						mid = i;
//						v = t;
//						break;
//					}
//				}
//			}
//			else {
//				if (i == n - 1)continue;
//				for (int j = i + 1; j < n; j++) {
//					if (pre[j] - pre[i] >= t && suf[j + 1] >= t) {
//						ok = 1;
//						pos = j;
//						mid = i;
//						v = t;
//						break;
//					}
//				}
//			}
//			if (ok)break;
//		}
//	}
//	//cout << pos << " " << v << " " << mid << endl;
//	if (!ok) {
//		cout << -1 << '\n';
//		return;
//	}
//	vector<int>ans(n + 1,0);
//	for (int j = pos, sum = 0;j >= 1;j--) {
//		if (sum + a[j] < v) {
//			ans[j] = a[j];
//			sum += a[j];
//			a[j] = 0;
//		}
//		else {
//			ans[j] = v - sum;
//			sum = v;
//			a[j] -= ans[j];
//			break;
//		}
//	}
//	for (int j = pos+1, sum = 0;j<=n;j++) {
//		if (sum + a[j] < v) {
//			ans[j] = a[j];
//			sum += a[j];
//			a[j] = 0;
//		}
//		else {
//			ans[j] = v - sum;
//			sum = v;
//			a[j] -= ans[j];
//			break;
//		}
//	}
//	if (!ok) {
//		cout << -1 << endl;
//		return;
//	}
//	if (count(ans.begin(), ans.end(), 0) == n) {
//		cout << 1 << endl;
//		for (int i = 1; i <= n; i++) {
//			cout << a[i] << " ";
//		}cout << '\n';
//	}
//	else {
//		cout << 2 << endl;
//		for (int i = 1; i <= n; i++) {
//			cout << ans[i] << " ";
//		}cout << '\n';
//		for (int i = 1; i <= n; i++) {
//			cout << a[i] << " ";
//		}cout << '\n';
//	}
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}