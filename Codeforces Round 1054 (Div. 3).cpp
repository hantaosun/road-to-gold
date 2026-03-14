//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	int ans = 0;
//	int minus = 0;
//	int mn=INT_MAX, mx = INT_MIN;
//	for (int i = 1,u; i <= n; i++) {
//		cin >> u;
//		if (u == 0) {
//			ans++;
//		}
//		if (u < 0) {
//			minus++;
//			mx = max(mx, u);
//		}
//		if (u > 0) {
//			mn = min(mn, u);
//		}
//	}
//	if (minus % 2 == 0)cout << ans << '\n';
//	else {
//			cout << ans + min(abs(mn), abs(mx)) + 1 << '\n';
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
//	sort(a.begin() + 1, a.end());
//	int ans = -1;
//	for (int i = 1; i <= n-1; i += 2) {
//		ans = max(ans, a[i + 1] - a[i]);
//	}
//	cout << ans << '\n';
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
//	int n,k;
//	cin >> n>>k;
//	map<int, int>mp;
//	for (int i = 1,u; i <= n; i++) {
//		cin >> u;
//		mp[u]++;
//	}
//	int ans = 0;
//	for (int i = 0; i <= k-1; i++) {
//		if (!mp.count(i)) {
//			ans++;
//		}
//	}
//	if (!mp.count(k)) {
//		cout << ans << '\n';
//	}
//	else {
//		cout << max(ans, mp[k]) << '\n';
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
//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s = " " + s;
//	int a = 0, b = 0;
//	int lp = -1;
//	int preA = 0, preB = 0;
//	vector<int>la(n+1), ra(n + 1);
//	vector<int>lb(n+1), rb(n + 1);
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == 'a') {
//			if (lp != -1) {
//				a += preA * (i - lp - 1);
//				la[i] = a;
//			}
//			lp = i;
//			preA++;
//		}
//	}
//	lp = -1;
//	a = 0;
//	preA = 0;
//	for (int i = n; i >= 1; i--) {
//		if (s[i] == 'a') {
//			if (lp != -1) {
//				a += preA * (lp - i - 1);
//				ra[i] = a;
//			}
//			lp = i;
//			preA++;
//		}
//	}
//	lp = -1;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == 'b') {
//			if (lp != -1) {
//				b += preB * (i - lp - 1);
//				lb[i] = b;
//			}
//			lp = i;
//			preB++;
//		}
//	}
//	lp = -1;
//	b = 0;
//	preB = 0;
//	for (int i = n; i >= 1; i--) {
//		if (s[i] == 'b') {
//			if (lp != -1) {
//				b += preB * (lp - i - 1);
//				rb[i] = b;
//			}
//			lp = i;
//			preB++;
//		}
//	}
//	int ans = LLONG_MAX;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == 'a') {
//			ans = min(ans, la[i] + ra[i]);
//		}
//		else {
//			ans = min(ans, lb[i] + rb[i]);
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
//void solve() {
//	int n, k, l, r;
//	cin >> n >> k >> l >> r;
//	vector<int>a(n + 1);
//	vector<int>vsort;
//	vsort.push_back(-1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		vsort.push_back(a[i]);
//	}
//	sort(vsort.begin() + 1, vsort.end());
//	vsort.erase(unique(vsort.begin() + 1, vsort.end()), vsort.end());
//	vector<vector<int>>pos(vsort.size());
//	for (int i = 1; i <= n; i++) {
//		a[i] = lower_bound(vsort.begin() + 1, vsort.end(),a[i]) - vsort.begin();
//		pos[a[i]].push_back(i);
//	}
//	set<int>st;
//	vector<int>b(n + 1);//右端点到i时的种类数
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		st.insert(a[i]);
//		b[i] = st.size();
//	}
//	if (lower_bound(b.begin() + 1, b.end(), k) == b.end()) {
//		cout << 0 << "\n";
//		return;
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	cout << b[i] << " ";
//	//}cout << "\n--------------------\n";
//	int tr = prev(upper_bound(b.begin() + 1, b.end(), k)) - b.begin();
//	int tl = lower_bound(b.begin() + 1, b.end(), k) - b.begin();
//	tr = min(r, tr);
//	tl = max(l, tl);
//	ans += tr - tl + 1;
//	//cout << "ans:" << ans << "^\n";
//	int diff = 0;
//	for (int i = 2; i <= n; i++) {
//		auto it = lower_bound(pos[a[i - 1]].begin()+1, pos[a[i - 1]].end(), i);
//		if (it != pos[a[i - 1]].end()) {
//			int p = *it-1;
//			if (b[p] >= k) {
//				while (b[p] >= k&&p>=1) {
//					b[p]--;
//					p--;
//				}
//			}
//		}
//		else {
//			int p = n;
//			if (b[p] >= k) {
//				while (b[p] >= k && p >= 1) {
//					b[p]--;
//					p--;
//				}
//			}
//		}
//		//for (int i = 1; i <= n; i++) {
//		//	cout << b[i] << " ";
//		//}cout << "\n--------------------\n";
//		auto it1 = lower_bound(b.begin() + 1, b.end(), k);
//		if (it1 == b.end())break;
//		//cout << "*it1： " << *it1 << "!@#$%^&*\n";
//		int rr = prev(upper_bound(b.begin()+1, b.end(), k)) - b.begin();
//		int ll =  it1- b.begin();
//		rr = min(i + r - 1, rr);
//		ll = max(i + l - 1, ll);
//		//cout << ans << "&*&*\n";
//		ans+=max(0,rr-ll+1);
//		//cout << i << " " << rr << " " << ll << "**\n";
//	}
//	cout << ans << '\n';
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



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n, k, l, r;
//	cin >> n >> k >> l >> r;
//	vector<int>a(n + 1);
//	map<int, int>mp1;
//	map<int, int>mp2;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int lp = 0, rp = 0;
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		while (lp<=n-1&&mp1.size()<k) {
//			mp1[a[++lp]]++;
//			if (mp1.size() == k) {
//				break;
//			}
//		}
//		while (rp<=n-1&&mp2.size() <= k) {
//			mp2[a[++rp]]++;
//			if (mp2.size() > k) {
//				break;
//			}
//		}
//		if (mp1.size() < k) {
//			lp = n + 1;
//		}
//		if (mp2.size() <= k) {
//			rp = n + 1;
//		}
//		ans += max(0ll , min(i + r, rp) - max(i + l - 1, lp));
//		//cout << lp << " " << rp << "&&\n";
//		/*if (rp > n) {
//			ans += max(0, min(i + r - 1, n) - max(i + l - 1, lp - 1) + 1);
//		}
//		else ans += max(0,min(i+r-1,rp-1) - max(i+l-1,lp-1));
//		*/if (--mp1[a[i]] == 0) {
//			mp1.erase(a[i]);
//		}
//		if (--mp2[a[i]] == 0) {
//			mp2.erase(a[i]);
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
//#define int long long
//using namespace std;
//int h, d;
//int cost(int x) {//一下动x格的花费
//	return (1 + x) * x / 2;
//}
//
//bool check(int x) {//最多歇x轮能不能到d
//	int hp = h;
//	int dis = d;
//	int a = dis / (x + 1);
//	dis %= (x + 1);
//	return dis * (a + 1) * (a + 2) / 2 + (x + 1 - dis) * a * (a + 1) / 2<=h+x-1;
//}
//void solve() {
//	cin >> h >> d;
//	int l = 0, r = d,mid;
//	int ans = 2 * d;
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
//	cout << ans+d << '\n';
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}