//A
//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//ll t, n, a[500050], mod = 998244353, onenum, res;
//
//long long mul_mod(long long a, long long b, long long mod) {
//    long long res = 0;
//    a %= mod;
//    while (b > 0) {
//        if (b & 1) res = (res + a) % mod;
//        a = (a * 2) % mod;
//        b >>= 1;
//    }
//    return res;
//}
//
//long long fastpow(long long a, long long b, long long p) {
//    if (p == 1) return 0;  // 任何数模1为0
//    long long res = 1;
//    a %= p;  // 确保a在模p范围内
//    while (b > 0) {
//        if (b & 1) res = mul_mod(res, a, p);
//        a = mul_mod(a, a, p);
//        b >>= 1;
//    }
//    return res;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr), cout.tie(nullptr);
//    cin >> t;
//    while (t-- > 0) {
//        cin >> n;
//        res = 0;
//        onenum = 0;
//        for (int i = 1; i <= n; i++) {
//            cin >> a[i];
//            if (a[i] == -1) ++onenum;
//        }
//        onenum = fastpow(2, onenum, mod);
//        ll twonum = fastpow(2, onenum - 1, mod);
//        ll threenum = fastpow(2, onenum - 2, mod);
//        for (int i = 1; i <= n; i++) {
//            ll val = a[i];
//            ll pre = a[i - 1];
//            if (pre == 1) continue;
//            else if (pre == 0 && val == 1) res = (res + onenum) % mod;
//            else if (pre == 0 && val == -1) res = (res + twonum) % mod;
//            else if (pre == -1) {
//                if (val == 1) res = (res + twonum) % mod;
//                if (val == -1) res = (res + threenum) % mod;
//            }
//            cout << res << endl;
//        }
//        cout << res << "$" << endl;
//    }
//    return 0;
//}

//L
//#include<bits/stdc++.h>
//#define ll long long
//#define int long long
//using namespace std;
//const int mod = 998244353;
//int a[500010];
//ll qmi(ll a, ll b, ll mod)
//{
//	ll ans = 1;
//	while (b)
//	{
//		if (b & 1)ans = (ans * a) % mod;
//		b >>= 1;
//		a = (a * a) % mod;
//	}
//	return ans;
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	vector<bool>visi(n + 1, 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	vector<int>circle;
//	for (int i = 1; i <= n; i++) {
//		if (visi[i])continue;
//		else {
//			int cur = a[i];
//			visi[i] = 1;
//			int cnt = 1;
//			while (cur != i) {
//				visi[cur] = 1;
//				cur = a[cur];
//				cnt++;
//			}
//			circle.push_back(cnt);
//		}
//	}
//	int odd = 0;
//	for (int i = 0; i < circle.size(); i++) {
//		if (circle[i] % 2 == 1) {
//			odd++;
//		}
//	}
//	if (odd != 0 && odd != 2) {
//		cout << 0 << endl;
//		return;
//	}
//	if (odd == 2) {
//		int ans = 1;
//		for (int i = 0; i < circle.size(); i++) {
//			if (circle[i] == 2)continue;
//			if (circle[i] % 2 == 0) {
//				ans = (ans * 2) % mod;
//			}
//			else {
//				ans = (ans * circle[i]) % mod;
//			}
//		}
//		cout << ans << endl;
//	}
//	else if (odd == 0) {
//		int two = 0;
//		for (int i = 0; i < circle.size(); i++) {
//			if (circle[i] == 2) {
//				two++;
//			}
//		}
//		if (two == circle.size()) {
//			cout << two << endl;
//			return;
//		}
//		int k = qmi(2, circle.size() - two - 1, mod);
//		int k1 = qmi(2, circle.size() - two, mod);
//		int ans = 0;
//		for (int i = 0; i < circle.size(); i++) {
//			if (circle[i] == 2) {
//				ans = (ans + k1) % mod;
//			}
//			else {
//				ans = (ans + (circle[i] * circle[i] / 4 * k) % mod) % mod;
//			}
//			/*if ((circle[i] - 2) / 2 % 2 == 0) {
//				ans = (ans + ((circle[i] - 2) / 4 * circle[i] + circle[i] / 2)*k) % mod;
//			}
//			else {
//				ans = (ans + (((circle[i] - 2) / 4 + 1) * circle[i] + circle[i] / 2)*k)%mod;
//			}*/
//			//if (circle[i] % 4 == 0) {
//			//	ans += (circle[i] / 4)*circle[i];
//			//}
//			//else {
//			//	ans += (circle[i] / 4)*circle[i] + circle[i] / 2;
//			//}
//		}
//		cout << ans << endl;
//	}
//}
//signed main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}


//D
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//int n, V;
//vector<vector<ll>>chips;
//void solve() {
//	cin >> n >> V;
//	vector<vector<ll>>a(n, vector<ll>(3));
//	for (int i = 0; i <= n - 1; i++) {
//		cin >> a[i][0] >> a[i][1] >> a[i][2];
//	}
//	ll ans = 0;
//	for (int U = 1; U <= V; U++) {
//		chips.assign(U + 1, {});
//		for (int i = 0; i <= n - 1; i++) {
//			if (a[i][1] <= U) {
//				chips[a[i][1]].push_back(a[i][0] - a[i][2] * (V - U));
//			}
//		}
//		vector<ll>dp(U + 5, -(ll)(1e18 + 5));
//		dp[0] = 0;
//		for (int s = 1; s <= U; s++) {
//			int k = min(U / s, int(chips[s].size()));
//			nth_element(chips[s].begin(), chips[s].begin() + chips[s].size() - k, chips[s].end());//将前chips[s].size()个数放到数组左边后面的放到右边，不一定有序
//			for (int i = int(chips[s].size()) - 1; i >= int(chips[s].size()) - k; i--) {//注意!!!!使用size-x的操作务必注意size是无符号整形相减不会出现负数，最好先用int存储size
//				for (int j = U; j >= s; j--) {
//					dp[j] = max(dp[j], dp[j - s] + chips[s][i]);
//				}
//			}
//		}
//		// 		for (int s = 1; s <= U; s++)
//		// 		{
//		// 			int siz = chips[s].size();
//		// 			int k = min(U / s, (int)chips[s].size());
//		// 			nth_element(chips[s].begin(), chips[s].begin() + siz - k, chips[s].end());
//		// 			for (int i = 1; i <= U / s && i <= chips[s].size(); i++)
//		// 			{
//		// 				for (int j = U; j >= s; j--)
//		// 					dp[j] = max(dp[j], dp[j - s] + chips[s][siz - i]);
//		// 			}
//		//         }
//		ans = max(ans, dp[U]);
//	}
//	cout << ans << endl;
//}
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}