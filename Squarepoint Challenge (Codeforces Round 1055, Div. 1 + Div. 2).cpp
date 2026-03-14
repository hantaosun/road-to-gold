//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	if (n == 1) {
//		cout << 1 << "\n";
//		return;
//	}
//	sort(a.begin(), a.end());
//	int kind = 1;
//	for (int i = 1; i < n; i++) {
//		if (a[i] != a[i - 1]) {
//			kind++;
//		}
//	}
//	cout << 2 * kind - 1<<"\n";
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
//	int n, rk, ck, rd, cd;
//	cin >> n >> rk >> ck >> rd >> cd;
//	int ans1 = abs(rk - rd);
//	if (rd > rk) {
//		ans1 += rk;
//	}
//	else {
//		ans1 += n - rk;
//	}
//	int ans2 = abs(ck - cd);
//	if (cd > ck) {
//		ans2 += ck;
//	}
//	else {
//		ans2 += n - ck;
//	}
//	if (rk != rd &&ck != cd) {
//		cout << max(ans1, ans2) << "\n";
//	}
//	else {
//		if (abs(rk - rd) > abs(ck - cd)) {
//			cout << ans1 << "\n";
//		}
//		else if (abs(ck - cd) > abs(rk - rd)) {
//			cout << ans2 << "\n";
//		}
//		else {
//			int a, b;
//			if (rd > rk) {
//				a = rk;
//			}
//			else {
//				a = n - rk;
//			}
//			if (cd > ck) {
//				b = ck;
//			}
//			else {
//				b = n - ck;
//			}
//			cout << abs(ck - cd) + max(a, b) << "\n";
//		}
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
//using namespace std;
//void solve() {
//	int n, q;
//	cin >> n >> q;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	vector<int>psum(n + 1,0);
//	vector<int>c1;
//	vector<int>c0;
//	for (int i = 1; i < n; i++) {
//		if (a[i] == a[i + 1]) {
//			if(a[i]==1)c1.push_back(i);
//			else {
//				c0.push_back(i);
//			}
//		}
//
//	}
//	for (int i = 1; i <= n; i++) {
//		psum[i] = a[i] + psum[i - 1];
//	}
//	for (int i = 1,l,r; i <= q; i++) {
//		cin >> l >> r;
//		int one = psum[r] - psum[l - 1];
//		if (one % 3 != 0 || (r - l + 1 - one) % 3 != 0) {
//			cout << -1 << "\n";
//			continue;
//		}
//		auto it=lower_bound(c1.begin(), c1.end(), l);
//		auto it1=lower_bound(c0.begin(), c0.end(), l);
//		
//		if ((it != c1.end() && *it <= r - 1) || (it1 != c0.end() && *it1 <= r - 1)) {
//			cout << (r - l + 1) / 3 << "\n";
//		}
//		else {
//			cout << (r - l + 1) / 3 + 1 << "\n";
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
//#define int long long
//using namespace std;
//int high1(int x) {
//	int ans = 0;
//	while (x != 0) {
//		ans++;
//		x >>= 1;
//	}
//	return ans - 1;
//}
//int popcount(int x) {
//	int ans = 0;
//	while (x != 0) {
//		if (x & 1) {
//			ans++;
//		}
//		x >>= 1;
//	}
//	return ans;
//}
//void solve() {
//	int n, q;
//	cin >> n >> q;
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		b[i] = high1(a[i]);
//		//cout << a[i]<<"   "<<b[i]<<"   " << bitset<10>(a[i]) << "\n";
//	}
//	vector<int>psum(n + 1,0);
//	vector<int>con(n + 1,0);
//	vector<int>psum1(n + 1, 0);
//	for (int i = 1; i <= n; i++) {
//		if (popcount(a[i] >> 1) >= 2) {
//			con[i] = 2;
//		}
//		else if (a[i] == 3 || (a[i] & 1 && popcount(a[i] >> 1) == 1)) {
//			con[i] = 1;
//		}
//		psum1[i] = psum1[i - 1] + con[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		psum[i] = b[i] + psum[i - 1];
//	}
//	for (int i = 1,l,r; i <= q; i++) {
//		cin >> l >> r;
//		cout << psum[r] - psum[l - 1] + (psum1[r] - psum1[l - 1])/2<<"\n";
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
//using namespace std;
//const int N = 250005;
//int st[N][23];
//int n=0,z;
//void solve() {
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j < 23; j++) {
//			st[i][j] = 0;
//		}
//	}
//	cin >> n>>z;
//	vector<int>x(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> x[i];
//	}
//	vector<int>ll(n + 1);
//	for (int i = 1; i <= n; i++) {
//		st[i][0] = upper_bound(x.begin() + 1, x.end(), x[i] + z)-x.begin();
//		ll[i] = lower_bound(x.begin() + 1, x.end(), x[i] - z) - x.begin()-1;
//	}
//	for (int p = 1; p <= 22; p++) {
//		st[n][p] = n+1;
//	}
//	for (int i = n-1; i >= 1; i--) {
//		for (int p = 1; p <= 22; p++) {
//			st[i][p] = st[st[i+1][p - 1]][p - 1];
//		}
//	}
//	for (int i = 1; i <= n; i++)cout << ll[i] << " ";
//	int q;
//	cin >> q;
//	for (int i = 1,l,r; i <= q; i++) {
//		cin >> l >> r;
//		int cur = l;
//		int rr = ll[r];
//		int ans=0;
//		for (int p = 22; p >= 0; p--) {
//			if (st[cur][p] <=rr) {
//				cur = st[cur][p];
//				ans += 1 << p;
//			}
//		}
//		cout << ans + 2 << "\n";
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}