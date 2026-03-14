//K
//#include<bits/stdc++.h>
//#define pii pair<int,int>
//#define mp(a,b) make_pair(a,b)
//using namespace std;
//int main() {
//	int n;
//	cin >> n;
//	int cnt = 0;
//	vector<int>dr(n + 1);//记录某个房间有几个门
//	vector<vector<pii>>room(n+1,vector<pii>());
//	for (int i = 1,d; i <= n; i++) {
//		cin >> d;
//		dr[i] = d;
//		for (int j = 1,u; j <= d; j++) {
//			cin >> u;
//			room[i].push_back(mp(u,++cnt));
//		}
//	}
//	vector<int>nex(n*3+5);
//	vector<int>visi(n * 3 + 5);
//	vector<int>opp(n * 3 + 5);
//	vector<int>siz(n * 3 + 5);
//	for (int i = 1; i <= n; i++) {
//		for (auto p : room[i]) {
//			for (int j = 0; j < room[p.first].size();j++) {
//				if (room[p.first][j].first == i) {
//					opp[p.second] = room[p.first][j].second;
//					nex[p.second] = room[p.first][(j + 1)%dr[p.first]].second;
//				}
//			}
//		}
//	} //暴力枚举每个边的反边下一个边
//	for (int i = 1; i <= cnt; i++) {
//		if (visi[i])continue;
//		int c = i;
//		int cn = 1;
//		visi[i] = i;
//		while (nex[c] != i) {
//			c = nex[c];
//			if (visi[opp[c]]!=i) {
//				cn++;
//			}
//			visi[c] = i;
//		}
//		siz[i] = cn;
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << siz[visi[room[i][0].second]] << endl;
//	}
//}


//L
//离散化搭配树状数组做法
//#include<bits/stdc++.h>
//#define int long long
//#define pii pair<long long,long long>
//using namespace std;
//int len;
//int n, q;
//int rankk(int t, vector<int>& lisan) {
//	int m, l = 0, r = len, ans = 0;
//	while (l <= r) {
//		m = l + r >> 1;
//		if (lisan[m] >= t) {
//			ans = m;
//			r = m - 1;
//		}
//		else l = m + 1;
//	}
//	return ans + 1;
//}
//int tree[500005];
//int lowbit(int i) {
//	return i & (-i);
//}
//void add(int i, int v) {
//	while (i <= len + 1) {
//		tree[i] += v;
//		i += lowbit(i);
//	}
//}
//int sum(int i) {
//	int ans = 0;
//	while (i > 0) {
//		ans += tree[i];
//		i -= lowbit(i);
//	}
//	return ans;
//}
//int getN() {
//	int l = 1, r = len + 1, m, ans = 0;
//	while (l <= r) {
//		m = l + r >> 1;
//		if (sum(m) <= n - n / 2) {
//			ans = m;
//			l = m + 1;
//		}
//		else {
//			r = m - 1;
//		}
//	}
//	return sum(ans);
//}
//void solve() {
//	cin >> n >> q;
//	vector<int>lisan;
//	vector<int>a(n + 1);
//	vector<int>t(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		t[i] = a[i];
//		lisan.push_back(a[i]);
//	}
//	vector<pii>query(q + 1);
//	for (int i = 1; i <= q; i++) {
//		cin >> query[i].first >> query[i].second;
//		t[query[i].first] += query[i].second;
//		lisan.push_back(t[query[i].first]);
//	}
//	sort(lisan.begin(), lisan.end());
//	len = 0;
//	for (int i = 1; i < lisan.size(); i++) {
//		if (lisan[i] != lisan[len]) {
//			lisan[++len] = lisan[i];
//		}
//	}
//	for (int i = 0; i <= len + 1; i++) {
//		tree[i] = 0;
//		//cerr << lisan[i] << " ";
//	}
//	//cerr << endl;
//	for (int i = 1; i <= n; i++) {
//		add(rankk(a[i], lisan), 1);
//	}
//	for (int i = 1; i <= q; i++) {
//		add(rankk(a[query[i].first], lisan), -1);
//		a[query[i].first] += query[i].second;
//		add(rankk(a[query[i].first], lisan), 1);
//		//for (int j = 1; j <= len; j++)cout << tree[j] << " ";
//		//cout << endl;
//		cout << getN() << endl;
//	}
//}
//signed main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}
//双map模拟堆做法
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n, q;
//void solve() {
//	cin >> n >> q;
//	vector<int>a(n + 1);
//	vector<int>m(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		m[i] = a[i];
//	}
//	map<int, int>mp1;//存储小数
//	map<int, int>mp2;//存储前n/2个数
//	sort(m.begin(), m.end());
//	for (int i = n; i >= 1; i--) {
//		if (n-i+1<=n/2) {
//			mp2[m[i]]++;
//		}
//		else mp1[m[i]]++;
//	}
//	for (int i = 1,x,v; i <= q; i++) {
//		cin >> x >> v;
//		if (a[x] < mp2.begin()->first) {//判断元素在哪个堆
//			if (--mp1[a[x]] == 0) {
//				mp1.erase(a[x]);
//			}
//			if (a[x] + v < mp2.begin()->first) {
//				mp1[a[x] + v]++;
//			}
//			else { 
//				mp2[a[x] + v]++;
//				mp1[mp2.begin()->first]++;
//				if (--mp2[mp2.begin()->first] == 0) {//始终维护mp2中元素数量不变
//					mp2.erase(mp2.begin());
//				}
//			}
//		}
//		else {
//			if(--mp2[a[x]]==0)mp2.erase(a[x]);
//			mp2[a[x] + v]++;
//		}
//		a[x] += v;
//		if (mp1.rbegin()->first == mp2.begin()->first) {
//			cout << n - n / 2 - mp1.rbegin()->second<<endl;//mp1堆顶元素数量也满足
//		}
//		else cout << n - n / 2 << endl;
//	}
//}
//signed main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}


//I
//务必注意ll在函数,参数,返回值
//区间dp如何枚举,二分前缀处理用于查询满足某条件的所有元素中的最小值
//大区间从子区间获得信息整合出自己的信息,dp的信息可以是组合信息
//前缀还可以维护元素出现次数等
//#include<bits/stdc++.h>
//#define ll long long
//#define pii pair<long long,long long>
//#define fi first
//#define se second
//#define mp make_pair
//using namespace std;
//int n;
//vector<int>a;
//vector<ll>presum;
//ll bs(ll t, vector<pii>& a) {
//	int l = 0, r = a.size() - 1, m;
//	ll ans = -1;
//	while (l <= r) {
//		m = l + r >> 1;
//		if (a[m].second <= t) {
//			ans = a[m].first;
//			l = m + 1;
//		}
//		else {
//			r = m - 1;
//		}
//	}
//	return ans;
//}
//
//void solve() {
//	cin >> n;
//	a.resize(n + 1);
//	presum.resize(n + 1, 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		presum[i] = presum[i - 1] + a[i];
//	}
//	//dp[i][j]为一个数组存储从i到j这段上每个切割点切割后续能获得的最小代价及其对应不平衡度
//	vector<vector<vector<pii>>>dp(n + 1, vector<vector<pii>>(n + 1));
//	for (int i = 1; i <= n; i++) {
//		dp[i][i].push_back(mp(0, 0));//单根铁棒无需切割
//	}
//	//区间dp先枚举长度
//	for (int len = 2; len < n; len++) {//只用枚举2至n-1长度的区间即可 1长度为basecase n长度为最终汇总答案
//		for (int l = 1, r = l + len - 1; r <= n; l++, r++) {//枚举区间左端点
//			for (int k = l; k < r; k++) {//枚举割点(第k段右端点为割点)
//				ll L = presum[k] - presum[l - 1], R = presum[r] - presum[k];
//				ll cost = min(L, R) * ceil(log2(L + R));
//				ll b = abs(L - R);
//				ll lcost = bs(b, dp[l][k]), rcost = bs(b, dp[k + 1][r]);
//				if (lcost == -1 || rcost == -1)continue;
//				dp[l][r].emplace_back(mp(lcost + rcost + cost, b));
//			}
//			sort(dp[l][r].begin(), dp[l][r].end(), [](pii& a, pii& b) {
//				if (a.second == b.second) {
//					return a.first < b.first;
//				}
//				else return a.second < b.second;
//				});//先按不平衡度升序排,再按价格升序排,注意不平衡度相等时一定要按价格升序排,以确保前缀最小化正确
//			for (int i = 1; i < dp[l][r].size(); i++) {
//				dp[l][r][i].first = min(dp[l][r][i].first, dp[l][r][i - 1].first);
//			}//前缀最小化处理,只保留小于当前不平衡度的最小价格即可,确保二分能搜索到小于不平衡度的最大价格
//		}
//	}
//	for (int k = 1, l = 1, r = n; k < n; k++) {
//		ll L = presum[k] - presum[l - 1], R = presum[r] - presum[k];
//		ll cost = min(L, R) * ceil(log2(L + R));
//		ll b = abs(L - R);
//		ll lcost = bs(b, dp[l][k]), rcost = bs(b, dp[k + 1][r]);
//		if (lcost == -1 || rcost == -1)cout << -1 << " ";
//		else cout << cost + lcost + rcost << " ";
//	}
//	cout << endl;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}

//B
//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//#define rep(i,m,n) for(ll i=(m); i<=(n); i++)
//#define gcd(i,j) __gcd(i,j)
//#define lownd lower_bound
//#define upnd upper_bound
//#define endl "\n"
//#define decimal(i) std::fixed << std::setprecision(i)
//
//const int inf = 2147483647;
//int n, m;
//
//void solve()
//{
//
//	cin >> n >> m;
//	if (n < 0.8 * m && 2 * n - 1>1.2 * m)
//	{
//		cout << "-1" << endl;
//		return;
//	}
//
//	for (int k = 0; k <= n; k++)
//	{
//		if (0.8 * m <= k * (n - k) + n && k * (n - k) + n <= 1.2 * m)
//		{
//			for (int i = 0; i < k; i++)
//			{
//				cout << 0;
//			}
//			for (int i = k + 1; i <= n; i++)
//			{
//				cout << 1;
//			}
//			cout << endl;
//			return;
//		}
//	}
//
//
//	for (int t = 3; t <= 6; t++)
//	{
//		int now = (t - 1) * n * n / 2 / t;
//		if (0.8 * m <= now && now <= 1.2 * m)
//		{
//			int cnt = 0, len0 = n / t, block = 1;
//			for (int i = 0; i < t; i++)
//			{
//				for (int j = 0; j < len0; j++)
//				{
//					if (cnt < n)
//					{
//						cnt++;
//						cout << 0;
//					}
//				}
//				for (int j = 0; j < block; j++)
//				{
//					if (cnt < n)
//					{
//						cnt++;
//						cout << 1;
//					}
//				}
//				block++;
//			}
//			cout << endl;
//			return;
//		}
//	}
//	cout << "-1" << endl;
//	return;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int t = 1;
//	cin >> t;
//	while (t--)
//	{
//		solve();
//	}
//	return 0;
//}
//H分块待补
