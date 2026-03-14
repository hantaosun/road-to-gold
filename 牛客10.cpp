//#include<bits/stdc++.h>
//using namespace std;
//const int mod = 998244353;
//void solve() {
//	int n;
//	cin >> n;
//	if (n > 3 && (n - 1) % 3 == 0 && ((n - 1) / 3)&1) {
//		cout << 2 << '\n';
//	}
//	else {
//		cout << 0 << endl;
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
//const int mod = 998244353;
//void solve() {
//	string s;
//	cin >> s;
//	if (s[0] == s[2] || (s[1] == '-' && s[0] != '0')) {
//		cout << "No\n";
//	}
//	else {
//		cout << "Yes\n";
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}



//#include <bits/stdc++.h>
//
//using namespace std;
//typedef long long ll;
//int gcd(int a, int b) {
//    while (b != 0) {
//        int tmp = b;
//        b = a % b;
//        a = tmp;
//    }
//    return a;
//}
//ll n, m;
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr), cout.tie(nullptr);
//    cin >> n >> m;
//    vector<vector<int>>a(n + 1,vector<int>(m+1));
//    if (gcd(n, m) != 1) cout << "NO" << endl;
//    ll xx = 1, yy = 1;
//    
//    for (int i = 1; i <= n * m; i++) {
//        a[xx][yy] = i;
//        if (i & 1) {
//            xx += i;
//        }
//        else {
//            yy += i;
//        }
//        if (xx > n) xx %= n;
//        if (yy > m) yy %= m;
//    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//vector<int>a;
//int n, m;
//array<int,3> check(int mid) {
//	set<int>lset;
//	set<int>rset;
//	int l = 1, r = n;
//	while (lset.size() < mid) {
//		lset.insert(a[l++]);
//	}
//	while()
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n >> m;
//	a.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int l = 0, r = n,ans=0,b1=1,b2=2;
//	while (l <= r) {
//		int mid = l + r >> 1;
//		auto t = check(mid);
//		if (t[0]!=0) {
//			b1 = t[1];
//			b2 = t[2];
//			l = m + 1;
//			ans = mid;
//		}
//		else {
//			r = m - 1;
//		}
//	}
//	cout << ans << '\n';
//}


//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int  n;
//	cin >> n;
//	vector<int>shop(n);
//	vector<int>sot;
//	vector<int>cn(1000005);
//	for (int i = 0; i < n; i++) {
//		cin >> shop[i];
//		cn[shop[i]]++;
//	}
//	vector<array<int,2>>a;
//	for (int i = 0; i < n; i++) {
//		if (cn[shop[i]] >= 3) {
//			a.push_back({shop[i],i});
//		}
//	}
//	vector<array<int, 3>>ex(1000005,{0,0,0});//记录在l,m,r中的存在情况
//	map<int,int>l;
//	map<int, int>m;
//	map<int, int>r;
//	for (int i = 0; i < a.size(); i++) {
//		r[a[i][0]]++;
//		ex[a[i][0]][2] = 1;
//	}
//	int ans = 0;
//	int ls = 0, rs = 1;
//	set<int>zhi;//记录这些数
//	vector<array<int,3>>tex;
//	for (int i = 0; i < a.size(); i++) {
//		m.clear();
//		zhi.clear();
//		l[a[i][0]]++;
//		ex[a[i][0]][0] = 1;
//		
//		if (--r[a[i][0]] == 0) {
//			ex[a[i][0]][2] = 0;
//		}
//		tex = ex;
//		map<int, int>temp = r;
//		for (int j = i + 1; j < a.size(); j++) {
//			m[a[j][0]]++;
//			ex[a[j][0]][1] = 1;
//			if (--r[a[j][0]] == 0) {
//				ex[a[j][0]][2] = 0;
//			}
//			if (ex[a[j][0]][0] == 1 && ex[a[j][0]][1] == 1 && ex[a[j][0]][2] == 1) {
//				zhi.insert(a[j][0]);
//			}
//			else {
//				zhi.erase(a[j][0]);
//			}
//			if (ans < zhi.size()) {
//				ans = zhi.size();
//				ls = a[i][1];
//				rs = a[j][1];
//			}
//
//			//{
//			//	cout << i << " " << j << "*\n";
//			//	for (auto i : l) {
//			//		cout <<'(' <<i.first << "," << i.second << ") ";
//			//	}
//			//	cout << "\n";
//			//	for (auto i : m) {
//			//		cout <<'(' <<i.first << "," << i.second << ") ";
//			//	}
//			//	cout << "\n";
//			//	for (auto i : r) {
//			//		cout <<'(' <<i.first << "," << i.second << ") ";
//			//	}
//			//	cout << "\n";
//			//	for (auto i : zhi) {
//			//		cout << i << " ";
//			//	}
//			//	cout << '\n';
//			//}
//		}
//		ex = tex;
//		r= temp;
//	}
//	cout << ans << '\n';
//	cout << ls+2 << " " << rs+2 << '\n';
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}
//


//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
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
//void solve()
//{
//    int n, m;
//    cin >> n >> m;
//    int a[n + 1];
//    rep(i, 1, n)cin >> a[i];
//    int mx = *max_element(a + 1, a + n + 1),
//        mn = *min_element(a + 1, a + n + 1);
//    if (m == 1)
//    {
//        int head = 0;
//        int ans = 0;
//        rep(i, 1, n)
//        {
//            int d = mx - a[i];
//            ans += max(0, d - head);
//            head = d;
//        }
//        cout << ans << endl;
//        return;
//    }
//
//    int ans = inf;
//
//    for (int m2 = mn; m2 <= mx; m2++)
//        for (int m1 = m2 + 1; m1 <= mx + 100; m1++)
//        {
//            vector<vector<int>>dp(n + 1, vector<int>(mx - mn + 110, 10000000));
//
//            int d = mx - mn + 109;
//            if (m1 >= a[1])dp[1][m1 - a[1]] = m1 - a[1];
//            if (m2 >= a[1])dp[1][m2 - a[1]] = m2 - a[1];
//            rep(i, 2, n)
//            {
//                rep(j, 0, d)
//                {
//                    if (m1 >= a[i])
//                    {
//                        dp[i][m1 - a[i]] = min(dp[i][m1 - a[i]], dp[i - 1][j] + max(0, m1 - a[i] - j));
//                    }
//                    if (m2 >= a[i])
//                    {
//                        dp[i][m2 - a[i]] = min(dp[i][m2 - a[i]], dp[i - 1][j] + max(0, m2 - a[i] - j));
//                    }
//                }
//            }
//            ans = min(ans, *min_element(dp[n].begin(), dp[n].end()));
//        }
//
//    cout << ans << endl;
//    return;
//}
//
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int t = 1;
//    cin >> t;
//    while (t--)
//    {
//        solve();
//    }
//    return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int mx = INT_MIN, mn = INT_MAX;
//	for (auto v : a) {
//		mx = max(mx, v);
//		mn = min(mn, v);
//	}
//	if (m == 1) {
//		int ans = 0;
//		ans += mx - a[1];
//		for (int i = 2; i <= n; i++) {
//			if (a[i - 1] > a[i]) {
//				ans += a[i - 1] - a[i];
//			}
//		}
//		cout << ans << '\n';
//		return;
//	}
//	int ans = INT_MAX;
//	for (int sma = mn; sma <= mx + 25; sma++) {
//		for (int big = sma; big <= mx + 25; big++) {
//			vector<vector<int>>dp(n + 1, vector<int>(2, INT_MAX));
//			//0表示变为较小值，1表示较大值
//			if (sma >= a[1])dp[1][0] = sma - a[1];
//			if (big >= a[1])dp[1][1] = big - a[1];
//			if (dp[1][0] == INT_MAX && dp[1][1] == INT_MAX)continue;
//			for (int i = 2; i <= n; i++) {
//				if (a[i] <= sma) {
//					if (dp[i - 1][0] != INT_MAX)
//						dp[i][0] = min(dp[i][0], dp[i - 1][0] + max(0, a[i - 1] - a[i]));//max(0,sma-a[i]-(sma-a[i-1]))
//					if (dp[i - 1][1] != INT_MAX)
//						dp[i][0] = min(dp[i][0], dp[i - 1][1] + max(0, sma - big + a[i - 1] - a[i]));//max(0,sma-a[i]-(big-a[i-1]))
//				}
//
//				if (a[i] <= big) {
//					if (dp[i - 1][0] != INT_MAX)
//						dp[i][1] = min(dp[i][1], dp[i - 1][0] + max(0, big - sma + a[i - 1] - a[i]));//同上
//					if (dp[i - 1][1] != INT_MAX)
//						dp[i][1] = min(dp[i][1], dp[i - 1][1] + max(0, a[i - 1] - a[i]));//同上
//				}
//			}
//			ans = min({ ans, dp[n][0], dp[n][1] });
//		}
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
//const int N = 1e6 + 5;
//int mx[N << 2];
//int mxp[N << 2];
//int ad[N << 2];
//void lazy(int i, int v) {
//	ad[i] += v;
//	mx[i] += v;
//}
//void up(int i) {
//	if (mx[i << 1] > mx[i << 1 | 1]) {
//		mx[i] = mx[i << 1];
//		mxp[i] = mxp[i << 1];
//	}
//	else {
//		mx[i] = mx[i << 1 | 1];
//		mxp[i] = mxp[i << 1 | 1];
//	}
//}
//void down(int i) {
//	if (ad[i] != 0) {
//		lazy(i << 1, ad[i]);
//		lazy(i << 1 | 1, ad[i]);
//		ad[i] = 0;
//	}
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		mx[i] = 0;
//		mxp[i] = l;
//		ad[i] = 0;
//		return;
//	}
//	ad[i] = 0;
//	int mid = l + r >> 1;
//	build(l, mid, i << 1);
//	build(mid + 1, r, i << 1 | 1);
//	up(i);
//}
//void add(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v);
//		return;
//	}
//	int mid = l + r >> 1;
//	down(i);
//	if (jl <= mid) {
//		add(jl, jr, v, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		add(jl, jr, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//array<int, 2> query(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return { mx[i] ,mxp[i] };
//	}
//	int mid = l + r >> 1;
//	down(i);
//	array<int, 2> ans = { INT_MIN,-1 };
//	if (jl <= mid) {
//		auto info = query(jl, jr, l, mid, i << 1);
//		if (ans[0] < info[0]) {
//			ans = info;
//		}
//	}
//	if (jr > mid) {
//		auto info = query(jl, jr, mid + 1, r, i << 1 | 1);
//		if (ans[0] < info[0]) {
//			ans = info;
//		}
//	}
//	return ans;
//}
//void debug(int l, int r, int i) {
//	if (l == r) {
//		cout << "(" << l << ',' << mx[i] << ')' << " ";
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i);
//		debug(l, mid, i << 1);
//		debug(mid + 1, r, i << 1 | 1);
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	vector<int>nex(N, 0);
//	vector<int>last(N, 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		nex[last[a[i]]] = i;
//		last[a[i]] = i;
//	}
//	int ans = INT_MIN;
//	int ls = 1, rs = 2;//ls表示区间最后一个元素位置,rs表示中间区间最后一个元素位置
//	set<int>got;
//
//
//	//cout << "----\n";
//	build(1, n, 1);
//	for (int l = 1; l < n - 1; l++) {//l
//		//cout << "-------------\n";
//		//cout << "l:" << l << '\n';
//		//cout << l + 1 << " " << nex[l] - 1 << '\n';
//		bool has = got.count(a[l]);
//		if (has && nex[l] && l + 1 <= nex[l] - 1) {
//			//cout << "way1:" << l + 1 << " " << nex[l] - 1 << '\n';
//			add(l + 1, nex[l] - 1, -1, 1, n, 1);
//		}
//		if (!has && nex[l] && nex[l] <= last[a[l]] - 1) {
//			//cout << "way2:" << nex[l] << " " << last[a[l]] - 1 << " " << '\n';
//			add(nex[l], last[a[l]] - 1, 1, 1, n, 1);
//			got.insert(a[l]);
//		}
//
//		auto t = query(l + 1, n - 1, 1, n, 1);
//		if (ans < t[0]) {
//			ans = t[0];
//			ls = l;
//			rs = t[1];
//		}
//
//		//debug(1, n, 1);
//		//cout << '\n';
//		//cout << "-------------\n";
//	}
//	cout << ans << '\n';
//	cout << ls + 1 << " " << rs + 1 << '\n';
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}