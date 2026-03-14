//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1e6 + 2;
//int spf[MAXN];
//void SPF() {
//	for (int i = 1; i <= MAXN; i++) {
//		spf[i] = i;
//	}
//	for (int i = 2; i * i < MAXN; ++i) {
//		if (spf[i] == i) {
//			for (int j = i; j * i < MAXN; j++) {
//				if (spf[i * j] == i * j) {
//					spf[i * j] = i;
//				}
//			}
//		}
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>ans;
//	for (int i = 2; i <= n; i++) {
//		int t = i;
//		int jo = 0;
//		while (t != 1) {
//			t /= spf[t];
//			jo ^= 1;
//		}
//		if (jo) {
//			ans.push_back(i);
//		}
//	}
//	for (int i = 0; i < n / 2; i++) {
//		cout << ans[i] << " ";
//	}cout << '\n';
//}
//int main() {
//	int t;
//	cin >> t;
//	SPF();
//	while (t--) {
//		solve();
//	}
//}





//#include<bits/stdc++.h>
//using namespace std;
//int id, m, k, n;
//int grid[100][100];
//void solve() {
//	string s = "";
//	for (int o = 1; o <= k; o++) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				cin >> grid[i][j];
//			}
//		}
//	}
//}
//int main() {
//	
//	cin >> id >> m >> k >> n;
//	while (m--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int mod = 998244353;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());//64位随机数
//std::uniform_int_distribution<int> int_dist(0, 1000000000000000000);
//ll qpow(ll a, ll b) {
//	ll ans = 1;
//	a %= mod;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a % mod;
//		}
//		b >>= 1;
//		a = a * a % mod;
//	}
//	return ans;
//}
//ll ans = 1;
//void f(ll a, ll b, ll c, ll d) {
//	//cout << a << " " << b << " " << c << " " << d << endl;
//	if (b > d) {
//		swap(b, d);
//		swap(a, c);
//	}
//	ll g = gcd(a, c);
//	ans = ans % mod * qpow(g, b) % mod;//cout << ans << endl;
//	if (d - b <= 0 || g == 1)return;
//	f(a / g, b, c, d - b);
//}
//ll solve(ll a,ll b,ll c,ll d) {
//	ans = 1;
//	if (b > d) {
//		swap(b, d);
//		swap(a, c);
//	}
//	f(a, b, c, d);
//	return ans;
//}
//
//ll qmi(ll a, ll b)
//{
//    a = a % mod;
//    ll ans = 1;
//    while (b)
//    {
//        if (b & 1)ans = (ans * a) % mod;
//        b >>= 1;
//        a = (a * a) % mod;
//    }
//    return ans;
//}
//
//
//ll solve1(ll a,ll b,ll c,ll d)
//{
//    b = b % (mod - 1);
//    d = d % (mod - 1);
//
//    if (gcd(a, c) == 1)
//    {
//        return 1;
//    }
//    ll g = gcd(a, c);
//    ll am = 0, cm = 0;//a c包含g的几次幂
//    while (a % g == 0)
//    {
//        a /= g;
//        am++;
//    }
//    while (c % g == 0)
//    {
//        c /= g;
//        cm++;
//    }
//
//    ll bb = b * am % (mod - 1);
//    ll dd = d * cm % (mod - 1);
//    // cerr<<am<<" "<<cm<<endl;
//    // cerr<<bb<<" "<<dd<<endl;
//    ll ans = 1;
//    if (bb > dd)
//    {
//        ll fc = gcd(g, c);
//        ll sum = 0, gg = g; \
//            // cerr<<gg<<" "<<fc<<endl;
//            while (gg % fc == 0 && fc != 1)
//            {
//                gg /= fc;
//                sum++;
//            }
//        // cerr<<g<<" "<<dd<<" "<<fc<<" "<<abs(bb-dd)<<" "<<sum;
//        if (fc != 1)ans = qmi(g, dd) % mod * (qmi(fc, min(d, (bb - dd) * sum % (mod - 1)))) % mod;
//        else ans = qmi(g, dd);
//    }
//    else if (bb < dd)
//    {
//        ll fa = gcd(g, a);
//        ll sum = 0, gg = g;
//        while (gg % fa == 0 && fa != 1)
//        {
//            gg /= fa;
//            sum++;
//        }
//        if (fa != 1)ans = qmi(g, bb) % mod * (qmi(fa, min(b, (dd - bb) * sum % (mod - 1)))) % mod;
//        else ans = qmi(g, bb);
//    }
//    else ans = qmi(g, bb) % mod;
//    return ans%mod;
//}
//int main() {
//    	int t;
//    	cin >> t;
//    	while (t--) {
//    		int a = abs(int(int_dist(rng)));
//    		int b = abs(int(int_dist(rng)));
//    		int c = abs(int(int_dist(rng)));
//    		int d = abs(int(int_dist(rng)));
//    		cout << a << " " << b << " " << c << " " << d << endl;
//    		if (solve(a, b, c, d) != solve(a, b, c, d)) {
//    			cout << a << " " << b << " " << c << " " << d << endl;
//    			break;
//    		}
//    	}
//    	cout << "ok\n";
//}



//#include<bits/stdc++.h>
//#define ll unsigned long long
//using namespace std;
//const int mod = 998244353;
//ll qpow(ll a, ll b) {
//	ll ans = 1;
//	a %= mod;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a % mod;
//		}
//		b >>= 1;
//		a = a * a % mod;
//	}
//	return ans;
//}
//ll ans = 1;
//void f(ll a, ll b, ll c, ll d) {
//	//cout << a << " " << b << " " << c << " " << d << endl;
//	if (b > d) {
//		swap(b, d);
//		swap(a, c);
//	}
//	ll g = gcd(a, c);
//	ans = ans % mod * qpow(g, b) % mod;//cout << ans << endl;
//	if (d - b <= 0 || g == 1)return;
//	f(a / g, b, c, d - b);
//}
//void solve() {
//	ans = 1;
//	ll a, b, c, d;
//	cin >> a >> b >> c >> d;
//	if (b > d) {
//		swap(b, d);
//		swap(a, c);
//	}
//	f(a, b, c, d);
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
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n+1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int cnt = 0;
//	for (int i = n-1; i >= 1; i--) {
//		if (a[i] > a[i + 1]) {
//			cnt = max(a[i] - a[i+1], cnt);
//			a[i] = a[i + 1];
//		}
//	}
//	cout << cnt << '\n';
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}