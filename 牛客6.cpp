//#include<bits/stdc++.h>
//using namespace std;
//int jie[100000];
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>dp1(n + 1);
//	dp1[1] = 1; dp1[2] = 3;
//	for (int i = 3; i <= n; i++) {
//		dp1[i] = jie[i - 1] + i * dp1[i - 1];
//	}
//	vector<int>dp2(n + 1);
//	dp2[1] = 1;
//	dp2[2] = 5;
//	for (int i = 3; i <= n; i++) {
//		dp2[i] = dp2[i - 1] + dp1[i] + jie[i];
//	}
//}
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<array<int, 2>>qu(m + 1);
//	int ll = n;//左括号未使用数量
//	for (int i = 1, l, r; i <= m; i++) {
//		cin >> l >> r;
//		qu[i] = { l,r };
//	}
//	sort(qu.begin() + 1, qu.end(), [&](auto a, auto b) {
//		return a[0] < b[0];
//		});
//	vector<int>ans(2 * n + 1);
//	for (int i = m; i >= 1;) {
//		int l = qu[i][0];
//		ans[l] = 1;
//		ll--;
//		if (ll < 0) {
//			cout << -1 << endl;
//			return;
//		}
//		while (qu[i][1] >= l) {
//			i--;
//		}
//	}
//
//	//cout << "ll:" << ll << endl;
//	//for (int i = 1; i <= 2 * n; i++) {
//	//	cout << ans[i] << " ";
//	//}cout << endl;
//
//	int presum = 0;
//	for (int i = 1; i <= 2 * n; i++) {
//		if (ans[i] == 1) {
//			presum += 1;
//		}
//		else {
//			if (ll > 0) {
//				ans[i] = 1;
//				ll--;
//				presum += 1;
//			}
//			else presum -= 1;
//		}
//		if (presum < 0) {
//			cout << -1 << endl;
//			return;
//		}
//	}
//	for (int i = 1; i <= 2 * n; i++) {
//		if (ans[i] == 1)cout << '(';
//		else cout << ')';
//	}cout << endl;
//}
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}
//#include <iostream>
//
//using namespace std;
//
//typedef long long LL;
//
//int qmi(int a, int k, int p) {
//	int res = 1 % p;
//	while (k) {
//		if (k & 1) res = (LL)res * a % p;
//		a = (LL)a * a % p;
//		k >>= 1;
//	}
//	return res;
//}
//
//// 定义求解
//int C(int a, int b, int p) {
//	if (b > a) return 0;
//	int res = 1;
//	for (int i = 1, j = a; i <= b; ++i, --j) {
//		res = (LL)res * j % p;
//		res = (LL)res * qmi(i, p - 2, p) % p;
//	}
//	return res;
//}
//
//int lucas(LL a, LL b, LL p) {               // 注意LL参数类型
//	if (a < p && b < p) return C(a, b, p);
//	return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;     // 递归让其到p范围内求解
//}
//const int mod = 998244353;
//int main() {
//
//	LL n, m;
//	cin >> n >> m;
//	cout << (LL)lucas(n * (n - 1) + m, m, mod) << endl;
//
//
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int gcd(int a, int b) {
//	while (b != 0) {
//		int temp = b;
//		b = a % b;
//		a = temp;
//	}
//	return a;
//}
//int spf(int x,vector<int>&a) {
//	for (int i = 1; i * i <= x; i++) {
//		if (x % i == 0) {
//			a.push_back(i);
//			while (x % i == 0) {
//				x / i;
//			}
//		}
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	vector<int>pregcd(n + 1), sufgcd(n + 1);
//	pregcd[1] = a[1];
//	for (int i = 2; i <= n; i++) {
//		pregcd[i] = gcd(a[i], pregcd[i - 1]);
//	}
//	for (int i = n - 1; i >= 1; i--) {
//		sufgcd[i] = gcd(a[i], sufgcd[i + 1]);
//	}
//	vector<int>di(n + 1);
//	di[1] = a[1];
//	for (int i = 2; i <= n; i++) {
//		di[i] = a[i] - a[i - 1];
//	}
//	for (int r = 2,l=2; r <= n; r++) {
//	int di
//	}
//}
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}


//
//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//#define rep(i,m,n) for(ll i=(m); i<=(n); i++)
//#define gcd(i,j) __gcd(i,j)
//#define lownd lower_bound
//#define upnd upper_bound
//#define endl "\n"
//#define decimal(i) std::fixed << std::setprecision(i)
//#define count1(i) __builtin_popcount(i)
//
//using u64 = unsigned long long;
//using u128 = unsigned __int128;
//using i128 = __int128;
//
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());//64位随机数
//
//
//const int inf = 2147483647;
//
//
//
//void solve()
//{
//    int n;
//    cin >> n;
//    int a[n + 1];
//    vector<int>p;
//    bool flag = 1;
//    rep(i, 1, n)
//    {
//        cin >> a[i];
//        if (a[i] != a[1])flag = 0;
//    }
//    if (n == 1 || flag)
//    {
//        cout << 0 << endl;
//        return;
//    }
//    int ans = 0;
//    for (int i = 1; i * i <= a[1]; i++)
//    {
//        if (a[1] % i == 0)
//        {
//            p.push_back(i);
//            p.push_back(a[1] / i);
//        }
//    }
//    //以a1因子为模
//    for (int x : p)
//    {
//        int yu = a[2] % x, cnt = 0;
//        rep(i, 2, n)
//        {
//            if (yu == 0 && a[i] % x == 0 && i != n)continue;
//            if (yu != 0 && a[i] % x == 0)
//            {
//                cnt++;
//            }
//            if (yu != 0 && yu != a[i] % x)
//            {
//                break;
//            }
//            if (cnt == 1 && a[i] % x != 0)
//            {
//                break;
//            }
//            if (i == n)
//            {
//                ans = max(ans, x);
//            }
//        }
//    }
//    p.clear();
//
//    for (int i = 1; i * i <= a[n]; i++)
//    {
//        if (a[n] % i == 0)
//        {
//            p.push_back(i);
//            p.push_back(a[n] / i);
//        }
//    }
//    // for(int i:p)cerr<<i<<endl;
//    //以an因子为模
//    for (int x : p)
//    {
//        int yu = a[1] % x, cnt = 0;
//        rep(i, 1, n - 1)
//        {
//            if (yu == 0 && a[i] % x == 0 && i != n - 1)continue;;
//            if (yu != 0 && a[i] % x == 0)
//            {
//                cnt++;
//            }
//            if (yu != 0 && yu != a[i] % x)
//            {
//                break;
//            }
//            if (cnt == 1 && a[i] % x != 0)
//            {
//                break;
//            }
//            if (i == n - 1)
//            {
//                ans = max(ans, x);
//            }
//        }
//    }
//    cout << ans << endl;
//    return;
//}
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int t = 1;
//    cin >> t;
//    while (t--){
//        solve();
//    }
//    return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//constexpr int N = 1E5;
//vector<int>d[N+1];
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	if (count(a.begin(), a.end(), a[1]) == n) {
//		cout << 0 << endl;
//		return;
//	}
//	int mid = 0;
//	for (int i = 1; i < n; i++) {
//		if (a[i] != a[i - 1]) {
//			mid = abs(a[i]-a[i-1]);
//			break;
//		}
//	}
//	int ans = 0;
//	for (auto v : { a[0],a[n - 1],mid }) {//mid间接包含了全局加的情况
//		for (auto x : d[v]) {
//			int lst = 0;
//			int v = 0;
//			bool ok = true;
//			for (auto a : a) {//注意与题解不同遍历的是a
//				a %= x;
//				if (v == 0) {
//					if (a) {
//						lst = a;
//						v = a;
//					}
//				}
//				else {
//					if (a != lst && a != 0) {
//						ok = false;
//						break;
//					}
//					lst = a;//间接考虑了不为d的倍数的数大于2的清况
//				}
//			}
//			if (ok) {
//				ans = max(ans, x);
//			}
//		}
//	}
//	cout << ans << '\n';
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	for (int i = 1; i <= N; i++) {
//		for (int j = i; j <= N; j += i) {
//			d[j].push_back(i);
//		}
//	}
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}

//#include <bits/stdc++.h>
//
//using i64 = long long;
//using u64 = unsigned long long;
//using u32 = unsigned;
//
//using u128 = unsigned __int128;
//using i128 = __int128;
//
//template<class T>
//constexpr T power(T a, u64 b, T res = 1) {
//    for (; b != 0; b /= 2, a *= a) {
//        if (b & 1) {
//            res *= a;
//        }
//    }
//    return res;
//}
//
//template<u32 P>
//constexpr u32 mulMod(u32 a, u32 b) {
//    return u64(a) * b % P;
//}
//
//template<u64 P>
//constexpr u64 mulMod(u64 a, u64 b) {
//    u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
//    res %= P;
//    return res;
//}
//
//constexpr i64 safeMod(i64 x, i64 m) {
//    x %= m;
//    if (x < 0) {
//        x += m;
//    }
//    return x;
//}
//
//constexpr std::pair<i64, i64> invGcd(i64 a, i64 b) {
//    a = safeMod(a, b);
//    if (a == 0) {
//        return { b, 0 };
//    }
//
//    i64 s = b, t = a;
//    i64 m0 = 0, m1 = 1;
//
//    while (t) {
//        i64 u = s / t;
//        s -= t * u;
//        m0 -= m1 * u;
//
//        std::swap(s, t);
//        std::swap(m0, m1);
//    }
//
//    if (m0 < 0) {
//        m0 += b / s;
//    }
//
//    return { s, m0 };
//}
//
//template<std::unsigned_integral U, U P>
//struct ModIntBase {
//public:
//    constexpr ModIntBase() : x(0) {}
//    template<std::unsigned_integral T>
//    constexpr ModIntBase(T x_) : x(x_% mod()) {}
//    template<std::signed_integral T>
//    constexpr ModIntBase(T x_) {
//        using S = std::make_signed_t<U>;
//        S v = x_ % S(mod());
//        if (v < 0) {
//            v += mod();
//        }
//        x = v;
//    }
//
//    constexpr static U mod() {
//        return P;
//    }
//
//    constexpr U val() const {
//        return x;
//    }
//
//    constexpr ModIntBase operator-() const {
//        ModIntBase res;
//        res.x = (x == 0 ? 0 : mod() - x);
//        return res;
//    }
//
//    constexpr ModIntBase inv() const {
//        return power(*this, mod() - 2);
//    }
//
//    constexpr ModIntBase& operator*=(const ModIntBase& rhs)& {
//        x = mulMod<mod()>(x, rhs.val());
//        return *this;
//    }
//    constexpr ModIntBase& operator+=(const ModIntBase& rhs)& {
//        x += rhs.val();
//        if (x >= mod()) {
//            x -= mod();
//        }
//        return *this;
//    }
//    constexpr ModIntBase& operator-=(const ModIntBase& rhs)& {
//        x -= rhs.val();
//        if (x >= mod()) {
//            x += mod();
//        }
//        return *this;
//    }
//    constexpr ModIntBase& operator/=(const ModIntBase& rhs)& {
//        return *this *= rhs.inv();
//    }
//
//    friend constexpr ModIntBase operator*(ModIntBase lhs, const ModIntBase& rhs) {
//        lhs *= rhs;
//        return lhs;
//    }
//    friend constexpr ModIntBase operator+(ModIntBase lhs, const ModIntBase& rhs) {
//        lhs += rhs;
//        return lhs;
//    }
//    friend constexpr ModIntBase operator-(ModIntBase lhs, const ModIntBase& rhs) {
//        lhs -= rhs;
//        return lhs;
//    }
//    friend constexpr ModIntBase operator/(ModIntBase lhs, const ModIntBase& rhs) {
//        lhs /= rhs;
//        return lhs;
//    }
//
//    friend constexpr std::istream& operator>>(std::istream& is, ModIntBase& a) {
//        i64 i;
//        is >> i;
//        a = i;
//        return is;
//    }
//    friend constexpr std::ostream& operator<<(std::ostream& os, const ModIntBase& a) {
//        return os << a.val();
//    }
//
//    friend constexpr bool operator==(const ModIntBase& lhs, const ModIntBase& rhs) {
//        return lhs.val() == rhs.val();
//    }
//    friend constexpr std::strong_ordering operator<=>(const ModIntBase& lhs, const ModIntBase& rhs) {
//        return lhs.val() <=> rhs.val();
//    }
//
//private:
//    U x;
//};
//
//template<u32 P>
//using ModInt = ModIntBase<u32, P>;
//template<u64 P>
//using ModInt64 = ModIntBase<u64, P>;
//
//struct Barrett {
//public:
//    Barrett(u32 m_) : m(m_), im((u64)(-1) / m_ + 1) {}
//
//    constexpr u32 mod() const {
//        return m;
//    }
//
//    constexpr u32 mul(u32 a, u32 b) const {
//        u64 z = a;
//        z *= b;
//
//        u64 x = u64((u128(z) * im) >> 64);
//
//        u32 v = u32(z - x * m);
//        if (m <= v) {
//            v += m;
//        }
//        return v;
//    }
//
//private:
//    u32 m;
//    u64 im;
//};
//
//template<u32 Id>
//struct DynModInt {
//public:
//    constexpr DynModInt() : x(0) {}
//    template<std::unsigned_integral T>
//    constexpr DynModInt(T x_) : x(x_% mod()) {}
//    template<std::signed_integral T>
//    constexpr DynModInt(T x_) {
//        int v = x_ % int(mod());
//        if (v < 0) {
//            v += mod();
//        }
//        x = v;
//    }
//
//    constexpr static void setMod(u32 m) {
//        bt = m;
//    }
//
//    static u32 mod() {
//        return bt.mod();
//    }
//
//    constexpr u32 val() const {
//        return x;
//    }
//
//    constexpr DynModInt operator-() const {
//        DynModInt res;
//        res.x = (x == 0 ? 0 : mod() - x);
//        return res;
//    }
//
//    constexpr DynModInt inv() const {
//        auto v = invGcd(x, mod());
//        assert(v.first == 1);
//        return v.second;
//    }
//
//    constexpr DynModInt& operator*=(const DynModInt& rhs)& {
//        x = bt.mul(x, rhs.val());
//        return *this;
//    }
//    constexpr DynModInt& operator+=(const DynModInt& rhs)& {
//        x += rhs.val();
//        if (x >= mod()) {
//            x -= mod();
//        }
//        return *this;
//    }
//    constexpr DynModInt& operator-=(const DynModInt& rhs)& {
//        x -= rhs.val();
//        if (x >= mod()) {
//            x += mod();
//        }
//        return *this;
//    }
//    constexpr DynModInt& operator/=(const DynModInt& rhs)& {
//        return *this *= rhs.inv();
//    }
//
//    friend constexpr DynModInt operator*(DynModInt lhs, const DynModInt& rhs) {
//        lhs *= rhs;
//        return lhs;
//    }
//    friend constexpr DynModInt operator+(DynModInt lhs, const DynModInt& rhs) {
//        lhs += rhs;
//        return lhs;
//    }
//    friend constexpr DynModInt operator-(DynModInt lhs, const DynModInt& rhs) {
//        lhs -= rhs;
//        return lhs;
//    }
//    friend constexpr DynModInt operator/(DynModInt lhs, const DynModInt& rhs) {
//        lhs /= rhs;
//        return lhs;
//    }
//
//    friend constexpr std::istream& operator>>(std::istream& is, DynModInt& a) {
//        i64 i;
//        is >> i;
//        a = i;
//        return is;
//    }
//    friend constexpr std::ostream& operator<<(std::ostream& os, const DynModInt& a) {
//        return os << a.val();
//    }
//
//    friend constexpr bool operator==(const DynModInt& lhs, const DynModInt& rhs) {
//        return lhs.val() == rhs.val();
//    }
//    friend constexpr std::strong_ordering operator<=>(const DynModInt& lhs, const DynModInt& rhs) {
//        return lhs.val() <=> rhs.val();
//    }
//
//private:
//    u32 x;
//    static Barrett bt;
//};
//
//template<u32 Id>
//Barrett DynModInt<Id>::bt = 998244353;
//
//using Z = ModInt<998244353>;
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//constexpr int mod = 998244353;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	sort(a.begin() + 1, a.end());
//	if (n & 1) {
//		int big = 0;
//		int sma = 0;
//		for (int i = 1; i <= n / 2 + 1; i++) {
//			big = (big * m % mod + a[i]) % mod;
//		}
//		for (int i = n; i > n / 2 + 1; i--) {
//			sma = (sma * m % mod + a[i]) % mod;
//		}
//		cout << (big + mod - sma) % mod<<endl;
//		return;
//	}
//	int diff = abs(a[2] - a[1]);
//	vector<int>p;
//	for (int i = 1; i < n; i++) {
//		diff = min(diff, a[i + 1] - a[i]);
//	}
//	for (int i = n / 2; i >= 1; i--) {
//		if (abs(a[i + 1] - a[i]) == diff)p.push_back(i);
//	}
//	for (int i = n / 2+1; i < n; i++) {
//		if (abs(a[i + 1] - a[i]) == diff)p.push_back(i);
//	}
//	int ans = INT_MAX;
//	for (auto p : p) {
//		int big = max(a[p], a[p + 1]);
//		int sma = min(a[p], a[p + 1]);
//		for (int i = 1, cnt = 0; cnt < n / 2 - 1 && i <= n; i++) {
//			if (i == p || i == p + 1)continue;
//			big = (big * m % mod + a[i]) % mod;
//			cnt++;
//		}
//		for (int i = n, cnt = 0; cnt < n / 2 - 1 && i >= 1; i--) {
//			if (i == p || i == p + 1)continue;
//			sma = (sma * m % mod + a[i]) % mod;
//			cnt++;
//		}
//		ans = min(ans, (big + mod - sma) % mod);
//	}
//	cout << ans << endl;
//}
//signed main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}