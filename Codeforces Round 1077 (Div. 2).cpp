//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	int a = n, b = 1;
//	vector<int>tmp;
//	for (int i = 1; i <= n; i++) {
//		if (i & 1) {
//			tmp.push_back(b);
//			b++;
//		}
//		else {
//			tmp.push_back(a);
//			a--;
//		}
//	}
//	reverse(tmp.begin(), tmp.end());
//	for (auto v : tmp) {
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
//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s = "0" + s;
//	s += '0';
//	int ans = 0;
//	vector<bool>ok(n + 2);
//	ok[0] = ok[n + 1] = 1;
//	int c1 = 0;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == '1') {
//			ok[i - 1] = ok[i] = ok[i + 1] = 1;
//			c1++;
//		}
//	}
//	for (int i = 1; i <= n+1; i++) {
//		if (!ok[i - 1]) {
//			if (ok[i]) {
//				ans++;
//				ok[i - 1] = 1;
//			}
//			else {
//				ans++;
//				ok[i] = ok[i + 1] = 1;
//			}
//		}
//		if (ok[i])continue;
//	}
//	cout << ans+c1 << endl;
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
//const int N = 2e5 + 5;
//int fa[N];
//vector<int>a;
//vector<int>b;
//vector<int>c;
//int n;
//bool check(int k) {
//	//cout << k << "&&&\n";
//	if (k > a[b[n]] - a[b[1]])return false;
//	//int mxl=n+1, mnr=0;
//	//for (int i = 1; i <= n; i++) {
//	//	if (a[b[n]] - a[b[i]] < k) {
//	//		mxl = i;
//	//		break;
//	//	}
//	//}
//	//for (int i = n; i >= 1; i--) {
//	//	if (abs(a[b[1]] - a[b[i]]) < k) {
//	//		mnr = i;
//	//		break;
//	//	}
//	//}
//	////cout << mxl << " " << mnr << "^^\n";
//	//if (mxl > mnr)return 1;
//	//cout << k << "mid\n";
//	for (int i = 1; i <= n; i++) {
//		if (abs(a[b[i]] - a[b[1]]) < k && abs(a[b[i]] - a[b[n]]) < k) {
//			//cout << i << " " << b[i] << " " << a[b[i]] << "&\n";
//			int okl = lower_bound(c.begin() + 1, c.end(), a[b[i]]) - c.begin();
//			int okr = prev(upper_bound(c.begin() + 1, c.end(), a[b[i]])) - c.begin();
//			//cout << okl << " " << okr << "ok\n";
//			if (b[i] > okr || b[i] < okl)return false;
//		}
//	}
//	return 1;
//}
//void solve() {
//	cin >> n;
//	a.assign(n + 1, 0);
//	b.assign(n + 1, 0);
//	int r = -1;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		b[i] = i;
//		r = max(r, a[i]);
//	}
//	int ord = 1;
//	for (int i = 1; i <= n - 1; i++) {
//		if (a[i] > a[i + 1]) {
//			ord = 0;
//			break;
//		}
//	}
//	if (ord) {
//		cout << -1 << endl;
//		return;
//	}
//	sort(b.begin() + 1, b.end(), [&](int x,int y) {
//		return a[x] < a[y];
//		});
//	c = a;
//	sort(c.begin()+1, c.end());
//	//for (int i = 1; i <= n; i++)cout << b[i] << " ";
//	//cout << "BB\n";
//	int l = 0,ans=0;
//	while (l <= r) {
//		int mid = l + r >> 1;
//		if (check(mid)) {
//			ans = mid;
//			l = mid + 1;
//		}
//		else {
//			r = mid - 1;
//		}
//	}
//	cout << ans << "\n";
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
//vector<array<int,3>>op;
//bool is1(int x, int b) {
//	if (b < 0)return 0;
//	return (x >> b) & 1;
//}
//
////void v2(int x, int y) {
////	int x10 = -1, x20 = -1;
////	int y10 = -1, y20 = -1;
////	for (int i = 0; i <= 64; i++) {
////		if (!is1(x, i)) {
////			if (x10 == -1) {
////				x10 = i;
////			}
////			else if (x20 == -1) {
////				x20 = i;
////				break;
////			}
////		}
////	}
////	for (int i = 0; i <= 64; i++) {
////		if (!is1(y, i)) {
////			if (y10 == -1) {
////				y10 = i;
////			}
////			else if (y20 == -1) {
////				y20 = i;
////				break;
////			}
////		}
////	}
////	int px = 0, py = 0;
////	if (x10 != y10) {
////		px = 1 << x10;
////		py = 1 << y10;
////	}
////	else if (x10 == y10) {
////		if (x10)
////	}
////}
//int logic(int y, vector<bool>&used,int p) {
//	int sma = 0;
//	for (int i = 32; i >= 0; i--) {
//		if (sma) {
//			if (!used[i]) {
//				p |= 1ll << i;
//				used[i] = 1;
//			}
//		}
//		else {
//			if (is1(y, i)) {
//				if (used[i]) {
//					sma = 1;
//				}
//				else {
//					p |= 1ll << i;
//					used[i] = 1;
//				}
//			}
//		}
//	}
//	return p;
//}
//void v1(int x, int y) {
//	int px = 0, py = 0;
//	vector<bool>used(64);
//	bool got = 0;
//	for (int i = 0; i <= 30; i++) {
//		if (got) {
//			if (is1(x, i)) {
//				px |= 1ll << i;
//				used[i] = 1;
//			}
//			continue;
//		}
//		if (!is1(x, i)) {
//			px |= 1ll << i;
//			used[i] = 1;
//			got = 1;
//		}
//		else {
//			px |= 1ll << i;
//			used[i] = 1;
//		}
//	}
//	//cout << x<<" "<<px << "*****************\n";
//	py = logic(y, used, py);
//	//cout << px << " " << py << " " << x << " " << y << "**\n";
//	op.push_back({ px,py ,abs(x - px) + abs(y - py) });
//}
//void solve() {
//	int x, y;
//	cin >> x >> y;
//	int ox = x;
//	int oy = y;
//	//cout << bitset<32>(x) << endl;
//	//cout << bitset<32>(y) << endl;
//	//------
//	int px=0,py=0;
//	int pre = -1;
//	vector<bool>got(64, 0);
//	for (int i = 0; i <= 32; i++) {
//		if (is1(x, i) && !is1(y, i)) {
//			px |= 1ll << i;
//			got[i] = 1;
//		}
//		else if (!is1(x, i) && is1(y, i)) {
//			py |= 1ll << i;
//			got[i] = 1;
//		}
//	}
//	x -= px;
//	px = logic(x, got, px);
//	py = logic(y, got, py);
//	//cout << px << " " << py << "*\n";
//	op.push_back({ px,py,abs(ox - px) + abs(oy - py) });
//	//------
//	px=0,py=0;
//	x = ox; y = oy;
//	got.assign(64, 0);
//	for (int i = 0; i <= 32; i++) {
//		if (is1(x, i) && !is1(y, i)) {
//			px |= 1ll << i;
//			got[i] = 1;
//		}
//		else if (!is1(x, i) && is1(y, i)) {
//			py |= 1ll << i;
//			got[i] = 1;
//		}
//	}
//	y -= py;
//	py = logic(y, got, py);
//	px = logic(x, got, px);
//	//cout << px << " " << py << "*1\n";
//	op.push_back({ px,py,abs(ox - px) + abs(oy - py) });
//	//----
//	v1(ox, oy);
//	v1(oy, ox);
//	sort(op.begin(), op.end(), [&](auto aa, auto bb) {
//		return aa[2] < bb[2];
//		});
//	cout << op[0][0] << " " << op[0][1] << "\n";
//	op.clear();
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}