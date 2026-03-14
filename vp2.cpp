//#include<bits/stdc++.h>
//#include<unordered_set>
//using namespace std;
//int n;
//unordered_set<int>y;
//int  f(vector<int>& a) {
//	for (int i = n - 1; i >= 0; i--) {
//		int t = a[i];
//		for (int j = 2;; j++) {
//			if (t % j==0) {//遍历所有可能的因子，如果j*j>a[i]说明a[i]是质数返回a[i]
//				if (!y.count(j)) {
//					break;
//				}
//				else {
//					while (t % j==0) {
//						t /= j;
//					}
//				}
//			}
//			if (t == 1)return a[i];
//		}
//	}
//	return -1;
//}
//int main() {
//	cin >> n;
//	vector<int>a(n);
//	for (int i = 0; i < n;i++) {
//		cin >> a[i];
//		y.insert(a[i]);
//	}
//	sort(a.begin(), a.end());
//	cout << f(a)<<endl;
//}

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int fa[1000020];
//int siz[1000020];
//bool cmp(vector<int>&a,vector<int>&b) {
//	return a[2] > b[2];
//}
//void build(int n) {
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//		siz[i] = 1;
//	}
//}
//int find(int i) {
//	if (fa[i] != i) {
//		fa[i] = find(fa[i]);
//	}
//	return fa[i];
//}
//bool Union(int a, int b) {
//	int da = find(a), db = find(b);
//	if (da == db)return 0;
//	else {
//		fa[da] = fa[db];
//		return 1;
//	}
//}
//signed main() {
//	int n, m, S, T, K;
//	cin >> n >> m >> S >> T >> K;
//	build(n);
//	vector<vector<int>>edges;
//	for (int i = 0,u,v,w; i < m; i++) {
//		cin >> u >> v >> w;
//		edges.push_back(vector<int>{u, v, w});
//	}
//	sort(edges.begin(), edges.end(), cmp);
//	for (int i = 0; i < edges.size(); i++) {
//		if (Union(edges[i][0], edges[i][1])) {
//			if (find(T) == find(S)) {
//				cout << min(K,edges[i][2]) << endl;
//				return 0;
//			}
//		}
//	}
//	cout << 0 << endl;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int mod = 1e9 + 7;
//int a[500005];
//int dp[500005];//必须以包括i位置数字的情况下，在i-n上选所有可能的情况数
//bool cmp(pair<int, int>& a, pair<int, int>& b) {
//	return a.second < b.second;
//}
//int main() {
//	int n, k;
//	cin >> n >> k;
//	vector<pair<int, int>>a;
//	for (int i = 1,u; i <= n; i++) {
//		cin >> u;
//		a.push_back(make_pair(i, u));
//	}
//	sort(a.begin(), a.end(), cmp);
//	vector<int>b(n + 1);//位置i的数其后面有哪些位置的数与其差大于等于k
//	for(int i=1;i<)
//	dp[n] = 1;
//	for (int i = n - 1; i >= 1; i--) {
//		dp[i] = 1;
//		for (int j = i + 1; j <= n; j++) {
//			if (abs(a[j] - a[i]) >= k) {
//				dp[i] = (dp[i] + dp[j]) % mod;
//			}
//		}
//	}
//	int sum = 0;
//	for(int i=1;i<=n;i++){
//		sum = (sum + dp[i]) % mod;
//	}
//	cout << sum<< endl;
//}

//#include<bits/stdc++.h>
//using namespace std;
//double BG1w[9];
//double BG1l[9];
//double BG2w[9];
//double BG2l[9];
//double BG3l[9];
//double BG4w[9];
//double BG5w[9];
//
//double AG1w[9];
//double AG1l[9];
//double AG2w[9];
//double AG2l[9];
//double AG3l[9];
//double AG4w[9];
//double AG5w[9];
//int a[9][9];
//int main() {
//	for (int i = 1; i <= 8; i++) {
//		for (int j = 1; j <= 8; j++) {
//			cin >> a[i][j];
//		}
//	}
//	BG1w[1] = a[1][2];
//	BG1l[1] = a[2][1];
//	BG1w[2] = a[2][1];
//	BG1l[2] = a[1][2];
//	
//	AG1w[3] = a[3][4];
//	AG1l[3] = a[3][4];
//	AG1w[4] = a[3][4];
//	AG1l[4] = a[3][4];
//
//}

//#include<bits/stdc++.h>
//using namespace std;
//int a0, b0, a1, b1;
//void xuan(vector<vector<int>>& a) {
//	int n = a1 - a0 + 1;
//	vector<vector<int>>t(n, vector<int>(n));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			t[i][j] = a[i + a0][j + b0];
//		}
//	}
//	for (int i = b1, i1 = 0; i >= b0; i--, i1++) {
//		for (int j = a0, j1 = 0; j <= a1; j++, j1++) {
//			a[j][i] = t[i1][j1];
//		}
//	}
//}
//void lrfan(vector<vector<int>>& a) {
//	int n = a1 - a0 + 1;
//	vector<vector<int>>t(n, vector<int>(n));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			t[i][j] = a[i + a0][j + b0];
//		}
//	}
//	for (int i = a0, i1 = 0; i <= a1; i++, i1++) {
//		for (int j = b1, j1 = 0; j >= b0; j--, j1++) {
//			a[i][j] = t[i1][j1];
//		}
//	}
//}
//void udfan(vector<vector<int>>& a) {
//	int n = a1 - a0 + 1;
//	vector<vector<int>>t(n, vector<int>(n));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			t[i][j] = a[i + a0][j + b0];
//		}
//	}
//	for (int i = a1, i1 = 0; i >= a0; i--, i1++) {
//		for (int j = b0, j1 = 0; j <= b1; j++, j1++) {
//			a[i][j] = t[i1][j1];
//		}
//	}
//}
//void lurdfan(vector<vector<int>>& a) {
//	int n = a1 - a0 + 1;
//	vector<vector<int>>t(n, vector<int>(n));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			t[i][j] = a[i + a0][j + b0];
//		}
//	}
//	for (int i = 0; i <n; i++) {
//		for (int j = 0; j <n; j++) {
//			a[j+a0][i+b0] = t[i][j];
//		}
//	}
//}
//void ruldfan(vector<vector<int>>& a) {
//	lrfan(a);
//	lurdfan(a);
//	lrfan(a);
//}
//int main() {
//	int n, k;
//	cin >> n >> k;
//	vector<vector<int>>a(n + 1, vector<int>(n + 1));
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cin >> a[i][j];
//		}
//	}
//	for (int o = 0, cao; o < k; o++) {
//		cin >> cao >> a0 >> b0 >> a1 >> b1;
//		switch (cao) {
//		case 1:xuan(a); break;
//		case 2:lrfan(a); break;
//		case 3:udfan(a); break;
//		case 4:lurdfan(a); break;
//		case 5:ruldfan(a); break;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//}

//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//#define rep(i,m,n) for(int i=(m); i<=(n); i++)
//#define gcd(i,j) __gcd(i,j)
//#define lownd lower_bound
//#define upnd upper_bound
//#define endl "\n"
//#define kong " "
//const int inf = 2147483647;
//const int mod = 998244353;
//ll a[500010];
//
//ll qmi(ll a, ll b)
//{
//    ll ans = 1;
//    while (b)
//    {
//        if (b & 1)ans = (ans * a) % mod;
//        b >>= 1;
//        a = (a * a) % mod;
//    }
//    return ans;
//}
///*此题大致只有三种情况
//    1 子序列中仅包含1 例如 1 1 1 就是qmi(2,3)-1=2^3-1种
//    2 子序列是0 1 2……i型
//    3 子序列是0 1 2……i i+2型
//    注意 2 3对于每种数字都有情况1种可能
//*/
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        int n;
//        cin >> n;
//        map<ll, ll>mp;
//        rep(i, 1, n)
//        {
//            cin >> a[i];
//            mp[a[i]]++;
//        }
//        ll s = qmi(2, mp[1]) - 1;//考虑情况1
//        ll f[n + 1];//考虑情况2
//        ll d[n + 1];//考虑情况3
//        f[0] = qmi(2, mp[0]) - 1;
//
//        fill(f + 1, f + n + 1, 0);
//        fill(d + 1, d + n + 1, 0);//初始化
//        bool flag = 0, tg = 0;
//        rep(i, 1, n)
//        {
//            ll ad = qmi(2, mp[i]) - 1;
//            if (i >= 2 && !tg)
//            {
//                d[i] = (d[i - 1] + f[i - 2] * ad) % mod;
//                if (flag)tg = 1;
//            }
//            else if (i >= 2)d[i] = d[i - 1];
//
//            if (!mp[i])flag = 1;//假如i没出现过 则情况2断 并且情况3仅再计入一次
//
//            if (!flag)f[i] = f[i - 1] * ad;//fi表示查到mp[i]
//            else f[i] = 0;
//        }
//        ll num = 0;
//        rep(i, 0, n)num = (num + f[i]) % mod;
//        cout << (s + num + d[n]) % mod << endl;
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int dp[1005][1005];
//int f(int la, int lb,vector<int>&a,vector<int>&b) {//la-ra lb-rb 上完成匹配的最小值
//	if (dp[la][lb] != -1)return dp[la][lb];
//	int n = a.size()-1;
//	int sum = 0;
//	if (lb == n) {
//		int ans = 0;
//		for (int i = la; i <= n; i++) {
//			ans += abs(b[lb] - a[i]);
//		}
//		cout << la << " " << lb << " " << ans << endl;
//		return ans;
//	}
//	else if (la == n) {
//		int ans = 0;
//		for (int i = lb; i <= n; i++) {
//			ans += abs(a[la] - b[i]);
//		}
//		return ans;
//	}
//	int ans = abs(a[la] - b[lb]) + f(la + 1, lb + 1, a, b);
//	for (int i = lb; i <= n; i++) {
//		sum += abs(b[i]-a[la]);
//		ans = min(ans, sum + f(la + 1,i, a, b));
//	}
//	sum = 0;
//	for (int i = lb; i <= n; i++) {
//		sum += abs(a[i]-b[lb]);
//		ans = min(ans, sum + f(i,lb+1,a, b));
//	}
//	dp[la][lb] = ans;
//	cout << la << " " << lb << " " << ans << endl;
//	return ans;
//}
//void solve() {
//	int n;
//	cin >> n;
//	memset(dp, -1, sizeof(dp));
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	cout << f(1, 1, a, b);
//}
//int main() {
//	int  T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}