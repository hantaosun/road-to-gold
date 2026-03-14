//A
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	for (int i = 0; i < k; i++) {
//		cout << 1;
//	}
//	for (int i = k; i < n; i++) {
//		cout << 0;
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

//B 如何思考？
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	cout << 2 * n - 3 << endl;
//	for (int i = 2; i <= n; i++) {
//		cout << i << " " << 1 << " " << i << endl;
//	}
//	for (int i = 1; i <= n-2; i++) {
//		cout << i << " " << i + 1 << " " << n << endl;
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}

//C
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//void solve() {
//	ll n, k;
//	cin >> n >> k;
//	vector<ll>a(n + 2);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	vector<int>b(65,n);//统计某一位上有几个数字该位为0大于32全为n
//	ll ans = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; a[i]!=0&&j <= 64; j++) {
//			if ((a[i] & 1) != 0) {
//				ans++;
//				b[j]--;
//			}
//			a[i] >>= 1;
//		}
//	}
//	//for (int j = 1; j <= 63; j++) {
//	//	cout << b[j] << " ";
//	//}
//	//cout << endl;
//	for (int j = 1; j <= 63; j++) {
//		ll v = pow(2, j - 1);
//		if (b[j] == 0)continue;
//		if (v * b[j] <= k) {
//			k -= v * b[j];
//			ans += b[j];
//		}
//		else {
//			ans += k / v;
//			break;
//		}
//	}
//	cout << ans << endl;
//
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}

//D
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int bs1(int p,int t,vector<int>&p1,vector<int>&d1,int k) {
//	for (int i = 1; i <= p1.size(); i++) {
//		if (p1[i] >= p && (p1[i] - p + t % k) == d1[i])return p1[i];
//	}
//	return -1;
//}
//int bs2(int p, int t, vector<int>& p1, vector<int>& d1, int k) {
//	for (int i = p1.size()-1; i >=1; i++) {
//		if (p1[i] <= p && (p - p1[i] + t) % k == d1[i])return p1[i];
//	}
//}
//bool check(int p,vector<int>&p1,vector<int>&d1,int k) {
//	set<pair<int, pair<int, int>>>state;
//	int t = 0;
//	int d = 1;//初始朝向右边
//	while (!state.count(make_pair(p, make_pair(t, d)))) {
//		state.insert(make_pair(p, make_pair(t, d)));
//		if (d == 1) {
//			int nex=bs1(p, t, p1, d1,k);
//			if (nex == -1)return 1;
//			else {
//				d = -d;
//				t = (t + nex - p)%k;
//				p = nex;
//			}
//		}
//		else {
//			int nex = bs2(p, t, p1, d1,k);
//			if (nex == -1) {
//				return 1;
//			}
//			else {
//				d = -d;
//				t = t + (p - nex) % k;
//				p = nex;
//			}
//		}
//	}
//}
//void solve() {
//	int n, k,q;
//	cin >> n >> k;
//	vector<int>p1(n + 2),d(n+2);
//	vector<int>p(n + 2);//记录有效位置距离大于k的减去k
//	for (int i = 1; i <= n; i++) {
//		cin >> p1[i];
//		p[i] = (p1[i] - p[i - 1])%(k) +p[i-1]+k;
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> d[i];
//	}
//	cin >> q;
//	for (int i = 1,a; i <= q; i++) {
//		cin >> a;
//		if (check(a, p1, d,k))cout << "YES" << endl;
//		else {
//			cout << "NO" << endl;
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