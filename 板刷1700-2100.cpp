//2148G
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 10;
//int spf[N];
//int prime[N];
//int cnt = 0;
//void eular() {
//	for (int i = 1; i < N; i++) {
//		spf[i] = i;
//	}
//	for (int i = 2; i <N; i++) {
//		if (spf[i]==i)prime[cnt++] = i;
//		for (int j = 0; j < cnt; j++) {
//			if (prime[j] * i >= N)break;
//			spf[prime[j] * i] = prime[j];
//			if (i % prime[j] == 0)break;
//		}
//	}
//}
//int gcd(int a, int b) {
//	while (b != 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	unordered_map<int, int>b;//所有数除以总gcd后每个因数对应包含的数的个数
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	cout << 0 << " ";
//	int pgcd = a[1];
//	unordered_set<int>tmp;
//	int t = a[1]/pgcd;
//	while (spf[t] != 1) {
//		tmp.insert(spf[t]);
//		t /= spf[t];
//	}
//	for (auto v : tmp) {
//		b[v]++;
//	}
//	int mx = 0;
// 其实这里没有必要一定要除以整体gcd后再看，可以只统计出现频率小于目前所有数字的即可
//	for (int i = 2; i <= n; i++) {
//		int cgcd = gcd(pgcd, a[i]);
//		if (cgcd < pgcd) {
//			int x = pgcd / cgcd;
//			//暴力修改,最多logn次
//			b.clear();
//			for (int j = 1; j <= i; j++) {
//				int t = a[j];
//				t /= cgcd;
//				tmp.clear();
//				while (spf[t] != 1) {
//					tmp.insert(spf[t]);
//					t /= spf[t];
//				}
//				for (auto v : tmp) {
//					b[v]++;
//				}
//			}
//			mx = 0;
//			for (auto [u, cn] : b) {
//				mx = max(mx, cn);
//			}
//		}
//		else {
//			int t = a[i]/cgcd;
//			tmp.clear();
//			while (spf[t] != 1) {
//				tmp.insert(spf[t]);
//				t /= spf[t];
//			}
//			for (auto v : tmp) {
//				if (++b[v] > mx) {
//					mx = b[v];
//				}
//			}
//		}
//		pgcd = cgcd;
//		cout << mx<< ' ';
//		//for (auto [u, v] : b) {
//		//	cout << '(' << u << ',' << v << ')' << " ";
//		//}cout << "**\n";
//	}
//	cout << "\n";
//}
//void prepare() {
//	eular();
//}
//int main() {
//	prepare();
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
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	int mx = -1;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		mx = max(a[i], mx);
//	}
//	int diff = 0;
//	for (int i = 1; i <= n; i++) {
//		diff += mx - a[i];
//	}
//	if (diff > k) {
//		cout << -1 << '\n';
//		return;
//	}
//	int tar = mx + (k - diff) / n;
//	int mn = INT_MAX;
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		mn = min(a[i], mn);
//		ans += tar - a[i];
//	}
//	ans -= tar - mn;
//	for (int i = 1; i <= n; i++) {
//		if (a[i] == mn)ans--;
//	}
//	ans++;
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
//	int n;
//	cin >> n;
//	vector<vector<int>>a(n + 1);
//	int mx = -1;
//	for (int i = 1,k; i <= n; i++) {
//		cin >> k;
//		mx = max(mx, k);
//		a[i].resize(k + 2);
//		for (int j = 1; j <= k; j++) {
//			cin >> a[i][j];
//		}
//		a[i][k + 1] = i;//第k+1位置存储编号
//	}
//	//cout << "xixi\n";
//	vector<vector<int>>pro(mx+1);//当前位置按优先级排序的编号顺序
//	vector<vector<int>>id(n + 1);//当前编号在该位置优先级
//	for (int i = 1; i <= n; i++) {
//		id[i].resize(a[i].size());
//	}
//	sort(a.begin()+1, a.end(), [&](vector<int>& x, vector<int>& y) {
//		return x.size() > y.size();
//		});
//	int r = 1;
//	for (int i = mx; i >= 1; i--) {
//		while (r<=n&&a[r].size() - 1 >= i) {
//			r++;
//		}
//		//for (int i = 1; i < r; i++) {
//		//	cout << a[i].back()<<"**\n";
//		//}
//		//cout << "-----\n";
//		sort(a.begin() + 1, a.begin()+r, [&](vector<int>& x, vector<int>& y) {
//			if (i >= x.size() - 1||i>=y.size()-1) {
//				return x.size()>y.size();
//			}
//			if (x[i] == y[i]) {
//				if (i == mx) {
//					return x[i] < y[i];
//				}
//				else {
//					return id[x.back()][i + 1] < id[y.back()][i + 1];
//				}
//			}
//			return x[i] < y[i];
//		});
//		//cout << "fuck!\n";
//		for (int j = 1; j <= n; j++) {
//			if (i >= a[j].size() - 1) {
//				break;
//			}
//			pro[i].emplace_back(a[j].back());
//			id[a[j].back()][i] = j;
//		}
//	}
//	vector<int>pos(n + 1);
//	for (int i = 1; i <= n; i++) {
//		//cout << a[i].back() << '\n';
//		pos[a[i].back()] = i;
//	}
//	vector<bool>used(n + 1);
//	vector<int>ans(mx+1);
//	for (int i = 1; i <= mx;) {
//		int p;
//		for (int j = 0; j < pro[i].size(); j++) {
//			if (!used[pro[i][j]]) {
//				p = pro[i][j];
//				used[p] = true;
//				break;
//			}
//		}
//		//cout << i << " " << p << '\n';
//		//cout << pos[p] << "\n";
//		while (i < a[pos[p]].size()-1) {
//			ans[i]=a[pos[p]][i];
//			i++;
//		}
//	}
//	//for (int i = 1; i <= mx; i++) {
//	//	for(int j=0;j<n;j++){
//	//		cout << pro[i][j] << " ";
//	//	}
//	//	cout << "\n";
//	//}
//	for (int i = 1; i <= mx; i++) {
//		cout << ans[i] << ' ';
//	}
//	cout << "\n";
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
//const int N = 2e5 + 5;
//int dp[N];
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	dp[1] = a[1];
//	dp[0] = 0;
//	for (int i = 2; i <= n; i++) {
//		//情况1,直接砍死
//		dp[i] = a[i]+dp[i-1];
//		//情况2,跌一下再砍死
//		//1.从i-1上直接跌落 i-1是被砍死的
//		dp[i] = min(dp[i-2]+a[i - 1] + max(0ll,a[i] - (i - 1)), dp[i]);	
//		//i-1是被跌后再砍死的或者i-1直接被砍死
//		dp[i] = min(dp[i - 1] + a[i] - 1, dp[i]);
//	}
//	cout << dp[n] << "\n";
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
//int lk, rk;
//int reply;
//vector<char>ans;
//void query(int a,int b) {
//	cout << "? ";
//	cout <<6<<" "<< a << " " << rk << " " << b << " " << rk << " " << lk << " " << rk << endl;
//	cin >> reply;
//	if (reply == 6) {
//		ans[a] = '(';
//		ans[b] = '(';
//	}
//	else if (reply == 2) {
//		ans[a] = '(';
//		ans[b] = ')';
//	}
//	else if (reply == 3) {
//		ans[a] = ')';
//		ans[b] = '(';
//	}
//	else {
//		ans[a] = ')';
//		ans[b] = ')';
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	int l = 1, r = n;
//	ans.assign(n + 1, ' ');
//	int reply;
//	int an = n;
//	while (l <= r) {
//		int mid = l + r >> 1;
//		cout << "? "<<mid<<" ";
//		for (int i = 1; i <= mid; i++) {
//			cout << i << " ";
//		}
//		cout << endl;
//		cin >> reply;
//		if (reply > 0) {
//			an = mid;
//			r = mid - 1;
//		}
//		else {
//			l = mid + 1;
//		}
//	}
//	if (l>n) {
//		lk = n;
//		rk = 1;
//		ans[lk] = '(';
//		ans[rk] = ')';
//	}
//	else {
//		lk = an - 1;
//		rk = an;
//		ans[lk] = '(';
//		ans[rk] = ')';
//	}
//	int a = -1, b = -1;
//	for (int i = 1; i <= n; i++) {
//		if (i == lk || i == rk)continue;
//		if (a == -1) {
//			a = i;
//		}
//		else if (b == -1) {
//			b = i;
//			query(a, b);
//			a = -1;
//			b = -1;
//		}
//	}
//	if (a != -1) {
//		query(a, a);
//	}
//	cout << "! ";
//	for (int i = 1; i <= n; i++) {
//		cout << ans[i];
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



//#include<bits/stdc++.h>
//using namespace std;
//int lk, rk;
//int reply;
//vector<char>ans;
//void query(vector<int>&num) {
//	cout << "? ";
//	cout << 492 << " ";
//	int cnt = 0;
//	for (int k = 11, i = 0; k >= 0; k--,i++) {
//		int t = (1 << (k >> 1)) - 1;
//		cnt += t * (t + 1);
//		for (int j = 1; j <= t; j++) {
//			cout << lk << " " << rk << " ";
//		}
//		cout << num[i] << " " << rk<<" ";
//		for (int j = 1; j <= t; j++) {
//			cout << lk << " " << rk << " ";
//		}
//		cout << rk<<" ";
//	}	
//	cout << endl;
//	cin >> reply;
//	reply -= 2604;
//	for (int i = 0; i <= 11; i++) {
//		if ((reply >> i) & 1) {
//			ans[11 - i] = '(';
//		}
//		else {
//			ans[11 - i] = ')';
//		}
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	int l = 1, r = n;
//	ans.assign(n + 1, ' ');
//	int reply;
//	int an = n;
//	while (l <= r) {
//		int mid = l + r >> 1;
//		cout << "? " << mid << " ";
//		for (int i = 1; i <= mid; i++) {
//			cout << i << " ";
//		}
//		cout << endl;
//		cin >> reply;
//		if (reply > 0) {
//			an = mid;
//			r = mid - 1;
//		}
//		else {
//			l = mid + 1;
//		}
//	}
//	if (l > n) {
//		lk = n;
//		rk = 1;
//		ans[lk] = '(';
//		ans[rk] = ')';
//	}
//	else {
//		lk = an - 1;
//		rk = an;
//		ans[lk] = '(';
//		ans[rk] = ')';
//	}
//	vector<int>tmp;
//	for (int i = 1; i <= n; i++) {
//		if (i == lk || i == rk)continue;
//		if (tmp.size() < 12) {
//			tmp.push_back(i);
//		}
//		if (tmp.size() == 12) {
//			query(tmp);
//			tmp.clear();
//		}
//	}
//	if (tmp.size() > 0 && tmp.size() < 12) {
//		while (tmp.size() != 12) {
//			tmp.push_back(tmp[0]);
//		}
//		query(tmp);
//	}
//	cout << "! ";
//	for (int i = 1; i <= n; i++) {
//		cout << ans[i];
//	}
//	cout << endl;
//}
//int main() {
//	//int cnt = 0;
//	//int cnt1 = 0;
//	//for (int i = 11; i >= 0; i--) {
//	//	int tmp = (1 << (i >> 1)) - 1;
//	//	cnt += ((1 << (i >> 1)) - 1) * 4 + 2 + 1;
//	//	cnt1 += tmp * (tmp + 1);
//	//}
//	//cout << cnt << '\n';
//	//cout << cnt1 << "\n";
//
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//struct Point {
//	int x, y;
//	int id;
//};
//void solve() {
//	int n;
//	cin >> n;
//	vector<Point>a(n+1);
//	vector<int>vsort;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i].x>>a[i].y;
//		a[i].id = i;
//		vsort.push_back(a[i].y);
//	}
//	sort(vsort.begin(), vsort.end());
//	vsort.erase(unique(vsort.begin(), vsort.end()), vsort.end());
//	sort(a.begin()+1, a.end(), [&](auto x, auto y) {
//		return x.x < y.x;
//		});
//	vector<Point>p1;
//	vector<int>py1;
//	vector<Point>p2;
//	vector<int>py2;
//	for (int i = 1; i <= n / 2; i++) {
//		p1.push_back(a[i]);
//	}
//	sort(p1.begin(), p1.end(), [=](Point x,Point y) {
//		return x.y < y.y;
//		});
//	for (int i = 0; i < n / 2; i++) {
//		py1.push_back(p1[i].y);
//	}
//	for (int i = n/2+1; i <= n; i++) {
//		p2.push_back(a[i]);
//	}
//	sort(p2.begin(), p2.end(), [=](auto x,auto y) {
//		return x.y < y.y;
//		});
//	for (int i = -0; i < n / 2; i++) {
//		py2.push_back(p2[i].y);
//	}
//	//for (int i = 0; i < p1.size(); i++) {
//	//	cout << p1[i].x << "__" << p1[i].y <<"__"<<p1[i].id<<"   ";
//	//}
//	//cout << "\n";
//	//for (int i = 0; i < p2.size(); i++) {
//	//	cout << p2[i].x << "__" << p2[i].y <<"__"<<p2[i].id<< "   ";
//	//}
//	//cout << "\n";
//	int splitv = 0;
//	int split=-1;
//	for (auto v : vsort) {
//		int bu1 = upper_bound(py1.begin(), py1.end(),v) - py1.begin();
//		int bl1 = lower_bound(py1.begin(), py1.end(),v) - py1.begin();
//		int bu2 = upper_bound(py2.begin(), py2.end(),v) - py2.begin();
//		int bl2 = lower_bound(py2.begin(), py2.end(),v) - py2.begin();
//		int sp1 = bl1;//p1中小于v的个数
//		int ep1 = bu1 - bl1;//等于
//		int sp2 = n/2-bu2;
//		int ep2 = bu2 - bl2;
//		if (!(sp2 + ep2<sp1 ||sp2>sp1 + ep1)) {
//			//cout << sp1 << " " << ep1 << " " << sp2 << " " << ep2 << "&&&&&\n";
//			split = max(sp1, sp2);
//			splitv = v;
//			break;
//		}
//	}
//	assert(split != -1);
//	//cout << splitv<<" "<<split << "**\n";
//	//int ans = 0;
//	//for (int i = 0; i < split; i++) {
//	//	ans -= p1[i].x;
//	//	ans -= p1[i].y;
//	//}
//	//for (int i = split; i < n / 2; i++) {
//	//	ans -= p1[i].x;
//	//	ans += p1[i].y;
//	//}
//	//cout << ans << "\n";
//	//for (int i = 0; i < n/2-split; i++) {
//	//	ans += p2[i].x;
//	//	ans -= p2[i].y;
//	//}
//	//cout << ans << "\n";
//	//for (int i =n/2-split; i < n / 2; i++) {
//	//	ans += p2[i].x;
//	//	ans += p2[i].y;
//	//}
//	//cout << ans << "\n";
//	for (int i = 0,j=n/2-split; i < split; i++,j++) {
//		cout << p1[i].id << " " << p2[j].id<<"\n";
//	}
//	for (int i = split,j=0; i < n / 2; i++,j++) {
//		cout << p1[i].id << " " << p2[j].id << "\n";
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
//int B = 2e5 + 5;//偏移量,防止线段树下标是负数
//const int N = 8e5 + 5;
//long long sum[N << 2];//指标小于当前值的a总和
//int num[N << 2];//指标小于当前值的个数
//void up(int i) {
//	num[i] = num[i << 1] + num[i << 1 | 1];
//	sum[i] = sum[i << 1] + sum[i<< 1 | 1];
//}
//void add(int x, long long v, int l, int r, int i) {
//	if (l == r) {
//		sum[i] += v;
//		num[i] += 1;
//		return;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		add(x, v, l, mid, i << 1);
//	}
//	else {
//		add(x, v, mid + 1, r, i << 1|1);
//	}
//	up(i);
//}
//long long querySum(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	long long ans = 0;
//	int mid = l + r >> 1;
//	if (jl <= mid) {
//		ans += querySum(jl, jr, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		ans += querySum(jl, jr, mid + 1, r, i << 1|1);
//	}
//	return ans;
//}
//int queryCnt(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return num[i];
//	}
//	int ans = 0;
//	int mid = l + r >> 1;
//	if (jl <= mid) {
//		ans += queryCnt(jl, jr, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		ans += queryCnt(jl, jr, mid + 1, r, i << 1 | 1);
//	}
//	return ans;
//}
//void build(int l,int r,int i) {
//	if (l == r) {
//		sum[i] = num[i] = 0;
//		return;
//	}
//	int mid = l + r >> 1;
//	build(l, mid, i << 1);
//	build(mid+1, r, i << 1|1);
//	up(i);
//}
//void debug(int l, int r, int i) {
//	if (l == r) {
//		cout << '(' << l-B << "," << sum[i] << "," << num[i] << ")" << " ";
//		return;
//	}
//	int mid = l + r >> 1;
//	debug(l, mid, i << 1);
//	debug(mid+1, r, i << 1|1);
//}
//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s = " " + s;
//	vector<long long>psum(n + 1);
//	for (int i = 1; i <= n; i++) {
//		psum[i] = psum[i - 1] + s[i] - '0';
//	}
//	B = 2*n+1;
//	int nn = 2 * n+1+B;
//	build(1, nn,1);
//	long long ans = 0;
//	add(B, 0, 1, nn, 1);
//	//cout << B << "\n";
//	//debug(1, nn, 1);
//	//cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
//	for (int i = 1; i <= n; i++) {
//		int tar = 2*psum[i] - i;//当前位置指标
//		//cout << tar +B<< "\n";
//		//cout << queryCnt(1, tar + B, 1, nn, 1)<<"&**&&\n";
//		ans += queryCnt(1, tar + B, 1, nn, 1)*psum[i];
//		ans -= querySum(1, tar + B, 1, nn, 1);
//		add(tar + B, psum[i], 1, nn, 1);
//		//cout << ans << "*\n";
//		//debug(1,nn,1);
//		//cout << "\n-----------------------\n";
//	}
//	//cout << "-------\n";
//	build(1, nn, 1);
//	for (int i = 1; i <= n; i++) {
//		psum[i] = i - psum[i];
//	}
//	add(B, 0, 1, nn, 1);
//	for (int i = 1; i <= n; i++) {
//		int tar = 2 * psum[i] - i;
//		//这里-1处理,使01数量相同的子串仅在统计1时被统计
//		ans += queryCnt(1, tar + B-1, 1, nn, 1)*psum[i];
//		ans -= querySum(1, tar + B-1, 1, nn, 1);
//		add(tar + B, psum[i], 1, nn, 1);
//		//cout << ans << "*\n";
//	}
//	cout << ans << "\n";
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}
//
//解决方案二，贡献可计算化，一个子段的贡献为max(c0,c1)=(c0+c1+|c0-c1|)/2
//设该子段右端点为r左端点为l则贡献为r-l+1+|pref(r)-pref(l)|;
//pref(i)为0-i上1个数-0个数的值//前半部分可O(1)求,后半部分对pref排序即可



//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//void solve() {
//	int n;
//	ll s;
//	int x;
//	cin >> n >> s >> x;
//	vector<int>a(n + 1);
//	vector<int>ex;//存储等于x的a[i]的位置
//	a[0] = LLONG_MAX;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		if (a[i] == x) {
//			ex.emplace_back(i);
//		}
//	}
//	vector<ll>psum(n + 1);
//	for (int i = 1; i <= n; i++) {
//		psum[i] = psum[i - 1] + a[i];
//	}
//	if (ex.empty()) {
//		cout << 0 << "\n";
//		return;
//	}
//	ll ans = 0;
//	stack<int>sta;
//	vector<int>ls(n + 1);
//	vector<int>rs(n + 1);
//	for (int i = 1; i <= n; i++) {
//		if (a[i] < x)continue;
//		if (a[i] > x) {
//			if (!sta.empty() && a[sta.top()] == x) {
//				rs[sta.top()] = i;
//			}
//			sta.push(i);
//		}
//		else {
//			if (!sta.empty() && a[sta.top()] == x) {
//				rs[sta.top()] = i;
//				sta.pop();
//			}
//			if (sta.empty()) {
//				ls[i] = 0;
//			}
//			else {
//				ls[i] = sta.top();
//			}
//			sta.push(i);
//		}
//	}
//	if (!sta.empty() && a[sta.top()] == x) {
//		rs[sta.top()] = n + 1;
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	cout << '(' << ls[i] << "," << rs[i] << ')' << " ";
//	//}
//	//cout << "\n------\n";
//	/*{
//		for (auto v : p) {
//			cout << v << " ";
//		}
//		cout << "***\n";
//	}*/
//	map<ll, int>mp;
//	int lstl = -1, lstr = -1;
//	for (int i = 0; i < ex.size(); i++) {
//		int cp = ex[i];
//		int l = ls[cp];
//		int r = rs[cp];
//		//cout << cp << " " << l << " " << r << "-----\n";
//		if (l != lstl) {
//			mp.clear();
//			lstl = l;
//			lstr = cp;
//		}
//		else {
//			l = lstr;
//			lstr = cp;
//		}
//		for (int j = l; j < cp; j++) {
//			mp[psum[j]]++;
//		}
//		for (int j = cp; j < r; j++) {
//			if (mp.count(psum[j] - s)) {
//				ans += mp[psum[j] - s];
//			}
//		}
//	}
//	cout << ans << "\n";
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//鸽巢原理！！！C(n,m)的运算数量取决于min(n-m,m);
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 1e9 + 7;
//int qpow(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a%mod;
//		}
//		b >>= 1;
//		a = a * a % mod;
//	}
//	return ans;
//}
//void prepare() {
//
//}
//void solve() {
//	int a, b, k;
//	cin >> a >> b >> k;
//	int x = (k * (a - 1) % mod + 1)%mod;
//	int y = (b - 1) * k % mod;
//	for (int i = 0; i < a; i++) {
//		y = y * (x - i + mod) % mod * qpow((a - i + mod)%mod,mod-2)%mod%mod;
//	}
//	y = (y + 1) % mod;
//	cout << x << " " << y << "\n";
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
//const int N = 2e5 + 5;
//struct Edge{
//	int u, v, w;
//};
//int fa[N];
//int mne[N];//当前该集合可达所有边的最小值
//void build(int n) {
//	for (int i = 0; i <= n; i++) {
//		fa[i] = i;
//		mne[i] = INT_MAX;
//	}
//}
//int find(int x) {
//	if (fa[x] != x) {
//		fa[x] = find(fa[x]);
//	}
//	return fa[x];
//}
//bool Union(int x, int y) {
//	int fx = find(x);
//	int fy = find(y);
//	if (fx == fy)return false;
//	else {
//		fa[fx] = fy;
//		mne[fy] = min(mne[fx], mne[fy]);
//		return true;
//	}
//}
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	build(n+5);
//	vector<Edge>e(m);
//	vector<int>pm(n + 1,INT_MAX);//当前点关联的所有边的权值最小值
//	for (int i = 0; i < m; i++) {
//		cin >> e[i].u >> e[i].v >> e[i].w;
//		pm[e[i].u] = min(pm[e[i].u], e[i].w);
//		pm[e[i].v] = min(pm[e[i].v], e[i].w);
//	}
//	for (int i = 1; i <= n; i++) {
//		mne[i] = pm[i];
//	}
//	sort(e.begin(), e.end(), [&](Edge& x, Edge& y) {
//		return x.w < y.w;
//		});
//	int ans = LLONG_MAX;
//	int stop = -1;
//	for (int i = 0; i <m; i++) {
//		if (Union(e[i].u, e[i].v)) {
//			if (find(1) == find(n)) {
//				ans = e[i].w+mne[find(1)];
//				stop = i+1;
//				break;
//			}
//		}
//	}
//	assert(stop != -1);
//	int f1 = find(1);
//	for (int i = stop; i < m; i++) {
//		Union(e[i].u, e[i].v);
//		f1 = find(1);
//		ans = min(ans, mne[f1] + e[i].w);
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

//dijkstra做法
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2e5 + 5;
//int n=0, m=0;
//struct Edge {
//	int u, v, w;
//};
//int dis1[N];
//int disn[N];
//bool vis[N];
//void solve() {
//	cin >> n >> m;
//	for (int i = 0; i <= n; i++) {
//		dis1[i] = LLONG_MAX;
//		disn[i] = LLONG_MAX;
//		vis[i] = false;
//	}
//	vector<Edge>e(m);
//	vector<vector<array<int, 2>>>g(n+1);
//	for (int i = 0; i < m; i++) {
//		cin >> e[i].u >> e[i].v >> e[i].w;
//		g[e[i].u].push_back({ e[i].v,e[i].w });
//		g[e[i].v].push_back({ e[i].u,e[i].w });
//	}
//	auto tcmp=[&](array<int, 2>& x, array<int, 2>& y) {
//		return x[1] > y[1];
//		};
//	priority_queue<array<int, 2>,vector<array<int, 2>>,decltype(tcmp)> pq(tcmp);
//	pq.push({ 1,0 });
//	dis1[1] = 0;
//	while (!pq.empty()) {
//		auto [u, w] = pq.top();
//		pq.pop();
//		if (vis[u])continue;
//		vis[u] = true;
//		for (auto v : g[u]) {
//			int newmax = max(w, v[1]);
//			if (!vis[v[0]] && newmax < dis1[v[0]]) {
//				pq.push({ v[0],newmax });
//				dis1[v[0]] = newmax;
//			}
//		}
//	}
//	for (int i = 0; i <= n; i++) {
//		vis[i] = false;
//	}
//	pq.push({ n,0 });
//	disn[n] = 0;
//	while (!pq.empty()) {
//		auto [u, w] = pq.top();
//		pq.pop();
//		if (vis[u])continue;
//		vis[u] = true;
//		for (auto v : g[u]) {
//			int newmax = max(w, v[1]);
//			if (!vis[v[0]] && newmax < disn[v[0]]) {
//				pq.push({ v[0],newmax });
//				disn[v[0]] = newmax;
//			}
//		}
//	}
//	int ans = LLONG_MAX;
//	for (int i = 0; i < m; i++) {
//		int u = e[i].u, v = e[i].v, w = e[i].w;
//		int cost1 = max({ dis1[u], disn[v], w }) + w;
//		int cost2 = max({ dis1[v], disn[u], w }) + w;
//		ans = min(ans, min(cost1, cost2));
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
//const int mod = 1e9 + 7;
//const int N = 2e5 + 5;
//int head[N];
//int dep[N];
//int nex[N << 1];
//int to[N << 1];
//int cnt = 1;
//int n=0;
//vector<int>leaves;
//int branch=-1;
//void addEdge(int u,int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//void dfs(int u, int fa) {
//	dep[u] = dep[fa] + 1;
//	int sons = 0;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa)continue;
//		sons++;
//		dfs(to[ui], u);
//	}
//	if (sons==0) {
//		leaves.push_back(u);
//	}
//	else if (sons == 2) {
//		branch = u;
//	}
//}
//int qpow(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a % mod;
//		}
//		b >>= 1;
//		a = a * a % mod;
//	}
//	return ans;
//}
//void solve() {
//	memset(head, 0, sizeof(int) * (n + 5));
//	memset(dep, 0, sizeof(int) * (n + 5));
//	cnt = 1;
//	branch = -1;
//	leaves.clear();
//	cin >> n;
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dep[1] = 1;
//	dfs(1, 0);
//	if (leaves.size() > 2) {
//		cout << 0 << "\n";
//		return;
//	}
//	else if (leaves.size() == 1) {
//		cout << qpow(2, dep[leaves[0]]) << "\n";
//		return;
//	}
//	assert(branch != -1);
//	int l = dep[leaves[0]] - dep[branch];
//	int r = dep[leaves[1]] - dep[branch];
//	if (l > r) {
//		swap(l, r);
//	}
//	int ans = qpow(2, dep[branch]);
//	ans = ans * ((qpow(2, r - l) + qpow(2, max(0ll, r - l - 1)))%mod)%mod;
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
//using namespace std;
//const int N = 1e6+5;
//int cnt = 0;
//int prime[N];
//int spf[N];
//int x, y, k;
//void eular() {
//	for (int i = 1; i < N; i++) {
//		spf[i] = i;
//	}
//	for (int i = 2; i < N; i++) {
//		if (spf[i] == i) {
//			prime[cnt++] = i;
//		}
//		for (int j = 0; j < cnt; j++) {
//			if (i * prime[j] >= N)break;
//			spf[i * prime[j]] = prime[j];
//			if (i % prime[j] == 0)break;
//		}
//	}
//}
//int gcd(int a,int b) {
//	while (b != 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//void solve() {
//	cin >> x >> y >> k;
//	int gxy = gcd(x, y);
//	x /= gxy;
//	y /= gxy;
//	set<int>a;
//	set<int>b;
//	for (int i = 2; i * i <= x; i++) {
//		if (x % i == 0) {
//			if(i<=k)a.insert(i);
//			if(x/i<=k)a.insert(x/i);
//		}
//	}
//	if(x<=k)a.insert(x);
//	for (int i = 2; i * i <= y; i++) {
//		if (y % i == 0) {
//			if(i<=k)b.insert(i);
//			if(y/i<=k)b.insert(y/i);
//		}
//	}
//	if(y<=k)b.insert(y);
//	int tt = x;
//	while (tt != 1) {
//		if (spf[tt] > k) {
//			cout << -1 << "\n";
//			return;
//		}
//		tt /= spf[tt];
//	}
//	tt = y;
//	while (tt != 1) {
//		if (spf[tt] > k) {
//			cout << -1 << "\n";
//			return;
//		}
//		tt /= spf[tt];
//	}
//	//cout << x << "\n";
//	//for (auto v : a) {
//	//	cout << v << " ";
//	//}
//	//cout << "\n\n";
//	//cout << y << "\n";
//	//for (auto v : b) {
//	//	cout << v << " ";
//	//}
//	//cout << "\n\n";
//	int ans = 0;
//	auto work = [&](set<int>&ar,int t)->int {
//		if (t == 1)return 0;
//		set<int>st;
//		st.insert(1);
//		int level = 0;
//		while (!st.contains(t)) {
//			set<int>tmp;
//			for (auto v : st) {
//				for (auto u : ar) {
//					tmp.insert(v * u);
//				}
//			}
//			for (auto v : tmp) {
//				st.insert(v);
//			}
//			level++;
//		}
//		return level;
//	};
//	ans+=work(a, x);
//	ans+=work(b, y);
//	cout << ans << "\n";
//}
//int main() {
//	eular();
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
////b-c 1
////c-b 2
////b-a 3
////c-a 4
//void solve() {
//	int n, q;
//	cin >> n >> q;
//	string s;
//	cin >> s;
//	int bc = 0;
//	int cb = 0;
//	int ba = 0;
//	int ca = 0;
//	int b_c_a = 0;
//	int c_b_a = 0;
//	for (int i = 1; i <= q; i++) {
//		char x,y;
//		cin >> x >> y;
//		if (x == 'a')continue;
//		if (x == 'b') {
//			if (y == 'c') {
//				bc++;
//			}
//			else if (y == 'a') {
//				ba++;
//				if (cb != 0) {
//					cb--;
//					c_b_a++;
//				}
//			}
//		}
//		if (x == 'c') {
//			if (y == 'b') {
//				cb++;
//			}
//			else if (y == 'a') {
//				ca++;
//				if (bc != 0) {
//					bc--;
//					b_c_a++;
//				}
//			}
//		}
//	}
//	int cta = ca - b_c_a;//仅可由c_a的c_a
//	int bta = ba - c_b_a;//仅可由b_a的b_a
//	//cout << cta << " " << bta << " " << b_c_a << " " << c_b_a << " " << bc << " " << cb << "\n";
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] == 'b') {
//			if (bta != 0) {
//				s[i] = 'a';
//				bta--;
//			}
//			else {
//				if (c_b_a != 0) {
//					s[i] = 'a';
//					c_b_a--;
//					cb++;
//				}
//				else if (b_c_a != 0) {
//					s[i] = 'a';
//					b_c_a--;
//				}
//			}
//		}
//		else if (s[i] == 'c') {
//			if (cta != 0) {
//				s[i] = 'a';
//				cta--;
//			}
//			else {
//				if (b_c_a != 0) {
//					s[i] = 'a';
//					b_c_a--;
//					bc++;
//				}
//				else if (c_b_a != 0) {
//					s[i] = 'a';
//					c_b_a--;
//				}
//				else if (cb!=0) {
//					cb--;
//					s[i] = 'b';
//				}
//			}
//		}
//	}
//	cout << s << "\n";
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
//const int M = 3e5 + 5;
//int n, m;
//int head[N];
//int nex[M];
//int to[M];
//int W[M];
//int cnt = 1;
//vector<int>b(n + 1);
//void addEdge(int u, int v, int w) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	W[cnt] = w;
//	head[u] = cnt++;
//}
//int dp[N];//到达当前点时可以拥有的最大电池数量
//void dfs(int u) {
//	dp[u] += b[u];
//
//}
//bool check(int lim) {
//	vector<int>best(n + 1, 0);
//	for (int i = 1; i <= n; i++) {
//		if (i > 1 && best[i] == 0)continue;
//		best[i] += b[i];
//		best[i] = min(best[i], lim);
//		for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//			if (W[ui] <= best[i]) {
//				best[to[ui]] = max(best[to[ui]], best[i]);
//			}
//		}
//	}
//	return best[n] > 0;
//}
//void solve() {
//	for (int i = 0; i <= n; i++) {
//		head[i] = 0;
//	}
//	cnt = 1;
//	cin >> n >> m;
//	b.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	int mx = -1;
//	for (int i = 1, s, t, w; i <= m; i++) {
//		cin >> s >> t >> w;
//		addEdge(s, t, w);
//		mx = max(mx, w);
//	}
//	int ans = -1;
//	int l = 0, r = mx;
//	while (l <= r) {
//		int mid = l + r >> 1;
//		if (check(mid)) {
//			ans = mid;
//			r = mid - 1;
//		}
//		else {
//			l = mid + 1;
//		}
//	}
//	cout << ans << "\n";
//
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
//	int n, m, l;
//	cin >> n >> m >> l;
//	int maxod=0, maxev = 0;
//	int mnod = INT_MAX;
//	for (int i = 1,u; i <= l; i++) {
//		cin >> u;
//		maxod += u;
//		maxev += u;
//		if (u & 1) {
//			mnod = min(mnod, u);
//		}
//	}
//	if (mnod == INT_MAX) {
//		maxod = 0;
//	}
//	else {
//		if (maxev & 1) {
//			maxev -= mnod;
//		}
//		else {
//			maxod -= mnod;
//		}
//	}
//	vector<vector<int>>g(n + 1);
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	vector<int>disod(n+1,INT_MAX);//所有点到1的奇数最短长度
//	vector<int>visod(n + 1, false);
//	vector<int>disev(n+1,INT_MAX);//所有点到1的偶数最短长度
//	vector<int>visev(n + 1, false);
//	auto tcmp = [&](array<int,2>&a,array<int,2>&b) {
//		return a[1] > b[1];
//		};
//	priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(tcmp)>pq(tcmp);
//	disev[1] = 0;
//	pq.push({ 1,0 });
//	while (!pq.empty()) {
//		auto [u, w] = pq.top();
//		pq.pop();
//		if (w & 1) {
//			if (visod[u])continue;
//			visod[u] = true;
//			int d = w + 1;
//			for (auto v : g[u]) {
//				if (d < disev[v]) {
//					disev[v] = d;
//					pq.push({ v,d });
//				}
//			}
//		}
//		else {
//			if (visev[u])continue;
//			visev[u] = true;
//			int d = w + 1;
//			for (auto v : g[u]) {
//				if (d < disod[v]) {
//					disod[v] = d;
//					pq.push({ v,d });
//				}
//			}
//		}
//	}
//	//cout << maxev << " " << maxod << "\n";
//	//for (int i = 1; i <= n; i++) {
//	//	cout << "("<<i<<',' << disev[i] << "," << disod[i] << ')' << "  ";
//	//}
//	//cout << '\n';
//	string ans = "1";
//	for (int i = 2; i <= n; i++) {
//		if (maxod >= disod[i] || maxev >= disev[i]) {
//			ans += '1';
//		}
//		else ans += '0';
//	}
//	cout << ans << "\n";
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
//int mx[N << 2];
//int addlzt[N << 2];
//int updlzt[N << 2];
//string s;
//void up(int i) {
//	mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
//}
//void addlazy(int i, int v) {
//	mx[i] += v;
//	addlzt[i] += v;
//}
//void updlazy(int i, int v) {
//	mx[i] = v;
//	addlzt[i] = 0;
//	updlzt[i] = v;
//}
//void down(int i) {
//	if (updlzt[i]!=-1) {
//		updlazy(i << 1, updlzt[i]);
//		updlazy(i << 1|1, updlzt[i]);
//		updlzt[i] = -1;
//	}
//	if (addlzt[i] != 0) {
//		addlazy(i << 1, addlzt[i]);
//		addlazy(i << 1|1, addlzt[i]);
//		addlzt[i] = 0;
//	}
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		mx[i] = 0;
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	addlzt[i] = 0;
//	updlzt[i] = -1;
//}
//void add(int jl, int jr,int v, int l, int r, int i) {
//	if (jl > jr)return;
//	if (jl <= l && jr >= r) {
//		addlazy(i, v);
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
//void add(int x, int v, int l, int r, int i) {
//	if (l == r) {
//		mx[i] += v;
//		return;
//	}
//	int mid = l + r >> 1;
//	down(i);
//	if (x <= mid) {
//		add(x, v, l, mid, i << 1);
//	}
//	else {
//		add(x, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//void upd(int jl, int jr, int v, int l, int r, int i) {
//	if (jl > jr)return;
//	if (jl <= l && jr >= r) {
//		updlazy(i, v);
//		return;
//	}
//	int mid = l + r >> 1;
//	down(i);
//	if (jl <= mid) {
//		upd(jl, jr, v, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		upd(jl, jr, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//void upd(int x, int v, int l, int r, int i) {
//	if (l == r) {
//		mx[i] = v;
//		return;
//	}
//	int mid = l + r >> 1;
//	down(i);
//	if (x <= mid) {
//		upd(x, v, l, mid, i << 1);
//	}
//	else {
//		upd(x, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//void solve() {
//	int n;
//	cin >> n;
//	cin >> s;
//	s = " " + s;
//	int ans = INT_MIN;
//	build(1, n, 1);
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == '0') {
//			add(1, i - 1, i - 1, 1, n, 1);
//			add(i + 1, n, n - i, 1, n, 1);
//			upd(i, 0, 1, n, 1);
//		}
//		else {
//			add(i, 1, 1, n, 1);
//			upd(1, i - 1, 0, 1, n, 1);
//			upd(i+1, n, 0, 1, n, 1);
//		}
//		ans = max(ans, mx[1]);
//	}
//	cout << ans << "\n";
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//傻逼了，把题读难了
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int sum[N << 2];//0-l上小于i的数的个数
//int lzt[N << 2];
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//void lazy(int i, int v, int n) {
//	sum[i] += v * n;
//	lzt[i] += v;
//}
//void down(int i, int ln, int rn) {
//	if (lzt[i] != 0) {
//		lazy(i << 1, lzt[i], ln);
//		lazy(i << 1 | 1, lzt[i], rn);
//		lzt[i] = 0;
//	}
//}
//void add(int jl, int jr,int v, int l, int r, int i) {
//	if (jl > jr)return;
//	if (jl <= l && jr >= r) {
//		lazy(i, v, r - l + 1);
//		return;
//	}
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	if (jl <= mid) {
//		add(jl, jr, v, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		add(jl, jr, v, mid + 1,r, i << 1 | 1);
//	}
//	up(i);
//}
//int query(int x, int l, int r, int i) {
//	if (l == r) {
//		return sum[i];
//	}
//	int mid = l + r >> 1;
//	down(i, mid - l + 1, r - mid);
//	if (x <= mid) {
//		return query(x, l, mid, i << 1);
//	}
//	else {
//		return query(x, mid + 1, r, i << 1 | 1);
//	}
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = 0;
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	lzt[i] = 0;
//}
//void debug(int l, int r, int i) {
//	if (l == r) {
//		cout << '(' << l << " " << sum[i] << ')' << " ";
//	}
//	else {
//		int mid = l + r >> 1;
//		down(i, mid - l + 1, r - mid);
//		debug(l, mid, i << 1);
//		debug(mid + 1, r, i << 1 | 1);
//	}
//}
//void solve() {
//	int n, q;
//	cin >> n >> q;
//	vector<int>a(n + 1);
//	vector<int>pos(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		pos[a[i]] = i;
//	}
//
//	vector<array<int, 3>>qry;
//	vector<vector<int>>task(n + 1);
//	vector<map<int,int>>del(n + 1);
//	for (int i = 1,l,r,k; i <= q; i++) {
//		cin >> l >> r >> k;
//		qry.push_back({ l,r,k });
//		task[l - 1].push_back(k);
//		task[r].push_back(k);
//	}
//
//	build(1, n, 1);
//	for (int i = 1; i <= n; i++) {
//		add(a[i]+1,n,1, 1, n, 1);
//		for (auto v : task[i]) {
//			del[i][v] = query(v, 1, n, 1);
//		}
//		//debug(1, n, 1);
//		//cout << "\n----\n";
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	cout << i << ":\n";
//	//	for (auto v : del[i]) {
//	//		cout << v.first << "__" << v.second << "   ";
//	//	}
//	//	cout << "\n";
//	//}
//	for (auto [l, r, k] : qry) {
//		if (pos[k] > r || pos[k] < l) {
//			cout << -1 << " ";
//		}
//		else {
//			int sma = 0, big = 0;
//			int tsma=0, tbig = 0;
//			int ok = 0;
//			int p = pos[k];
//			int tl = l, tr = r,mid;
//			while (tl <= tr) {
//				mid = tl + tr >> 1;	
//				if (p > mid) {
//					tl = mid + 1;
//					tsma++;
//					if (a[mid] < k)ok++;
//					else {
//						big++;
//					}
//				}
//				else if(p<mid){
//					tr = mid - 1;
//					tbig++;
//					if (a[mid] > k)ok++;
//					else {
//						sma++;
//					}
//				}
//				else {
//					break;
//				}
//			}
//			int s = del[r][k] - del[l - 1][k];
//			int b = r - l + 1 - s;
//			cout << "\n" << l << " " << r << " " << s <<" "<<tsma<<" "<<tbig<<"**\n";
//			if (s < tsma||b<tbig) {
//				cout << -1 << " ";
//			}
//			else {
//				cout << abs(sma - big) + sma + big << " ";
//			}
//		}
//	}
//	cout << "\n";
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
//正解
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//void solve() {
//	int n, q;
//	cin >> n >> q;
//	vector<int>a(n + 1);
//	vector<int>pos(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		pos[a[i]] = i;
//	}
//	vector<array<int, 3>>qry;
//	for (int i = 1,l,r,k; i <= q; i++) {
//		cin >> l >> r >> k;
//		qry.push_back({ l, r, k });
//	}
//	for (auto [l,r,k]:qry) {
//		if (pos[k] > r || pos[k] < l) {
//			cout << -1 << " ";
//			continue;
//		}
//		int sma = 0, big = 0;
//		int tsma = 0, tbig = 0;
//		int ok = 0;
//		int p = pos[k];
//		int tl = l, tr = r, mid;
//		while (tl <= tr) {
//			mid = tl + tr >> 1;
//			if (p > mid) {
//				tl = mid + 1;
//				tsma++;
//				if (a[mid] < k)ok++;
//				else {
//					big++;
//				}
//			}
//			else if (p < mid) {
//				tr = mid - 1;
//				tbig++;
//				if (a[mid] > k)ok++;
//				else {
//					sma++;
//				}
//			}
//			else {
//				break;
//			}
//		}
//		int s = k-1;
//		int b = n-k;
//		//cout << "\n" << l << " " << r << " " << s << " " << tsma << " " << tbig << "**\n";
//		if (s < tsma || b < tbig) {
//			cout << -1 << " ";
//		}
//		else {
//			cout << abs(sma - big) + sma + big << " ";
//		}
//	}
//	cout << "\n";
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


//666
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	map<int, int>cntver, cntdiag;
//	for (int i = 0; i < n; i++) {
//		int x, y;
//		cin >> x >> y;
//		cntver[x]++;
//		cntdiag[x + y]++;
//	}
//	int s, t;
//	for (auto [c, cnt] : cntver) {
//		if (cnt % 2 == 1) {
//			s = c;
//			break;
//		}
//	}
//	for (auto [c, cnt] : cntdiag) {
//		if (cnt % 2 == 1) {
//			t = c - s;
//			break;
//		}
//	}
//	cout << s << " " << t << '\n';
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
//const int N = 1e3 + 5;
//const int inf = 1e17;
//int n;
////same表示是否有位置与前面相同
////cna表示是否有位置加一后与前面相同
////dp[i]表示当前位置加或不加的情况下确保前面美丽的最小价值
//int run(vector<bool>& same, vector<bool>& cna,vector<bool>&cns,vector<int>&cost) {
//	vector<array<int, 2>>dp(n+1, {inf,inf});
//	dp[0][0] = 0;
//	dp[0][1] = 0;
//	for (int i = 1; i <= n; i++) {
//		if (same[i]) {
//			if(!cns[i])dp[i][0] = min({dp[i][0],dp[i - 1][1]});
//			if(!cna[i])dp[i][1] = min(dp[i][1], dp[i - 1][0] + cost[i]);
//		}
//		else {
//			if (cns[i]) {
//				dp[i][0] = min(dp[i][0], dp[i - 1][0]);
//			}
//			else {
//				dp[i][0] = min({dp[i][0], dp[i - 1][0], dp[i - 1][1]});
//			}
//			if (cna[i]) {
//				dp[i][1] = min(dp[i][1], dp[i - 1][1] + cost[i]);
//			}
//			else {
//				dp[i][1] = min({dp[i][1],dp[i-1][1]+cost[i],dp[i-1][0]+cost[i]});
//			}
//		}
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	cout << '(' << dp[i][0] << " " << dp[i][1] << ")   ";
//	//}
//	//cout << "\n";
//	int ans = min(dp[n][0], dp[n][1]);
//	return ans == inf ? -1 : ans;
//}
//void solve() {
//	cin >> n;
//	vector<vector<int>>g(n+1);
//	for (int i = 1; i <= n; i++) {
//		g[i].resize(n + 1);
//		for (int j = 1; j <= n; j++) {
//			cin >> g[i][j];
//		}
//	}
//	vector<int>a(n + 1);
//	vector<int>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	vector<bool>same(n + 1);
//	vector<bool>cna(n + 1);
//	vector<bool>cns(n + 1);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 2; j <= n; j++) {
//			if (g[j][i] == g[j - 1][i]) {
//				same[j] = true;
//			}
//			if (g[j][i] == g[j - 1][i] + 1) {
//				cns[j] = true;
//			}
//			if (g[j][i] + 1 == g[j - 1][i]) {
//				cna[j] = true;
//			}
//		}
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	cout << '(' << same[i] << ',' << cna[i] << ',' << cns[i] << ')' << "   ";
//	//}
//	//cout << "\n\n";
//	int a1 = run(same,cna,cns,a);
//	if (a1 == -1) {
//		cout << -1 << "\n";
//		return;
//	}
//	same.assign(n + 1, false);
//	cns.assign(n + 1, false);
//	cna.assign(n + 1, false);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 2; j <= n; j++) {
//			if (g[i][j] == g[i][j-1]) {
//				same[j] = true;
//			}
//			if (g[i][j] == g[i][j-1] + 1) {
//				cns[j] = true;
//			}
//			if (g[i][j] + 1 == g[i][j-1]) {
//				cna[j] = true;
//			}
//		}
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	cout << '(' << same[i] << ',' << cna[i] << ',' << cns[i] << ')' << "   ";
//	//}
//	//cout << "\n\n";
//	int a2 = run(same, cna, cns, b);
//	if (a2 == -1) {
//		cout << -1 << "\n";
//		return;
//	}
//	//cout << a1 << " " << a2 << "**\n";
//	cout << a1 + a2 << "\n";
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
//void solve() {
//	int n, q;
//	cin >> n >> q;
//	vector<int>a(n + 1);
//	map<int, vector<int>>pos;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		if(a[i]!=1)pos[a[i]].push_back(i);
//	}
//	for (int j = 1,k,l,r; j <= q; j++) {
//		cin >> k >> l >> r;
//		vector<int>tmp;
//		for (int i = 1; i * i <= k;i++) {
//			if (k % i == 0) {
//				auto it = lower_bound(pos[i].begin(), pos[i].end(), l);
//				if (it != pos[i].end()) {
//					int p1 = *it;
//					if (p1 <= r)tmp.push_back(p1);
//				}
//				if (k / i != i) {
//					auto it1 = lower_bound(pos[k / i].begin(), pos[k / i].end(), l);
//					if (it1 != pos[k/i].end()) {
//						int p2 = *it1;
//						if (p2 <=r) {
//							tmp.push_back(p2);
//						}
//					}
//				}
//			}
//		}
//		sort(tmp.begin(), tmp.end());
//		int ls = l;
//		int ans = 0;
//		for (int i = 0; i <tmp.size(); i++) {
//			ans += (tmp[i] - ls) * k;
//			while(k % a[tmp[i]] == 0) {
//				k /= a[tmp[i]];
//			}
//			ls = tmp[i];
//		}
//		ans += (r+1 - ls) * k;
//		cout << ans << "\n";
//	}
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//666
//#include<bits/stdc++.h>
//using namespace std;
////默认生成int范围内的非负整数 0---pow(2,32)-1;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//void solve() {
//	int n, q;
//	cin >> n >> q;
//	vector<int>a(n + 1);
//	vector<int>vsort;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		vsort.push_back(a[i]);
//	}
// //这里还可以参考算法讲解116最后一题,只用对数组排序即可实现相同功能
//	sort(vsort.begin(), vsort.end());
//	vsort.erase(unique(vsort.begin(), vsort.end()), vsort.end());
//	for (int i = 1; i <= n; i++) {
//		a[i] = lower_bound(vsort.begin(), vsort.end(), a[i]) - vsort.begin();
//	}
//	vector<vector<int>>pos(vsort.size() + 1);
//	for (int i = 1; i <= n; i++) {
//		pos[a[i]].push_back(i);
//	}
//	for (int i = 1,l,r; i <= q; i++) {
//		cin >> l >> r;
//		vector<int>tmp;
//		for (int j = 1; j <= 50; j++) {
//			int num = a[rng() % (r - l + 1) + l];
//			//cout << num << "^\n";
//			auto itr = upper_bound(pos[num].begin(), pos[num].end(), r);
//			auto itl = lower_bound(pos[num].begin(), pos[num].end(), l);
//			if (itl == pos[num].end() || *itl > r)continue;
//			int cnt = itr - itl;
//			if (cnt > (r - l + 1) / 3) {
//				tmp.push_back(vsort[num]);
//			}
//		}
//		if (tmp.empty()) {
//			cout << -1 << '\n';
//			continue;
//		}
//		sort(tmp.begin(), tmp.end());
//		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
//		for (auto v : tmp) {
//			cout << v << " ";
//		}
//		cout << '\n';
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}
//
////Misra-Gries算法(摩尔投票的推广)
//#include<bits/stdc++.h>
//#define pii pair<int,int>
//using namespace std;
//const int N = 2e5 + 5;
//vector<pii> val[N<< 2];
//vector<pii> add(vector<pii>a, vector<pii>b, int k) {//一个合并候选集的函数,a和b是候选集,k是候选集大小
//	for (int i = 0; i < k; i++) {
//		int p = -1;
//		//检查是否已有该元素
//		for (int j = 0; j < k; j++) {
//			if (b[i].first == 0)continue;
//			if (b[i].first == a[j].first) {
//				p = j;
//			}
//		}
//		//检查a中是否有空位
//		int q = -1;
//		for (int j = 0; j < k; j++) {
//			if (!a[j].first) {
//				q = j;
//			}
//		}
//		if (p != -1) {
//			a[p].second += b[i].second;
//		}
//		else if (q != -1) {
//			a[q] = b[i];
//		}
//		else {
//			int mn = b[i].second;
//			for (int j = 0; j < k; j++) {
//				mn = min(mn, a[j].second);
//			}
//			for (int j = 0; j < k; j++) {
//				a[j].second -= mn;
//			}
//			b[i].second -= mn;
//			for (int j = 0; j < k; j++) {
//				if (!a[j].second) {
//					if (b[i].second > 0) {
//						a[j] = b[i];
//						b[i].second = 0;
//					}
//					else {
//						a[j].first = 0;
//					}
//				}
//			}
//		}
//	}
//	return a;
//}
//void build(int l,int r,int i,vector<int>& a, int k) {
//	if (l == r) {
//		val[i].assign(k,{0,0});
//		val[i][0] = make_pair(a[l], 1);
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1, a, k);
//		build(mid+1, r, i << 1|1, a, k);
//		val[i] = add(val[i << 1], val[i << 1 | 1], k);
//	}
//}
//vector<pii> query(int jl, int jr, int l, int r, int i,int k) {
//	if (jl <= l && jr >= r) {
//		return val[i];
//	}
//	vector<pii>ans(k);
//	int mid = l + r >> 1;
//	if (jl <= mid) {
//		ans = add(ans, query(jl, jr, l, mid, i << 1, k),k);
//	}
//	if (jr > mid) {
//		ans = add(ans, query(jl, jr, mid + 1, r, i << 1 | 1, k),k);
//	}
//	return ans;
//}
//void solve() {
//	int n, q;
//	cin >> n >> q;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	vector<pair<int, int>>pos;
//	for (int i = 1; i <= n; i++) {
//		pos.push_back({ a[i], i });
//	}
//	sort(pos.begin(),pos.end());
//	auto query1 = [&](int c, int l, int r) {
//		return upper_bound(pos.begin(), pos.end(), pii(c, r)) - lower_bound(pos.begin(), pos.end(), pii(c, l));
//		};
//	build(1, n, 1, a, 2);
//	for (int i = 1, l, r; i <= q; i++) {
//		cin >> l >> r;
//		vector<pii>tmp = query(l, r, 1, n, 1, 2);
//		vector<int>an;
//		for (auto [a, b] : tmp) {
//			//cout << a << "**\n";
//			if (query1(a, l, r) > (r - l+1) / 3)an.push_back(a);
//		}
//		if (an.empty()) {
//			cout << -1 << '\n';
//		}
//		else {
//			sort(an.begin(), an.end());
//			for (auto v : an)cout << v << " ";
//			cout << "\n";
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
//const int N = 2e5 + 5;
//int n, k;
//int fa[N];
//int head[N];
//int nex[N << 1];
//int to[N << 1];
//int siz[N];
//int son[N];
//int near[N];
//int color[N];
//int weight[N];
//int cnt = 1;
//void addEdge(int u, int v) {
//	nex[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//void dfs1(int u, int pa) {
//	fa[u] = pa;
//	siz[u] = 1;
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == pa)continue;
//		dfs1(to[ui], u);
//		if (siz[to[ui]] > siz[son[u]]) {
//			son[u] = to[ui];
//		}
//		siz[u] += siz[to[ui]];
//	}
//}
//set<int>ap;
//set<int>sc;
//int ans = 0;
//void check(int u) {
//	if (ap.count(color[u])&&!sc.count(color[u])) {
//		sc.insert(color[u]);
//	}
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa[u])continue;
//		check(to[ui]);
//	}
//}
//void effect(int u) {
//	if (color[u] != 0) {
//		ap.insert(color[u]);
//	}
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa[u])continue;
//		effect(to[ui]);
//	}
//}
//void dfs2(int u,bool keep) {
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa[u] || to[ui] == son[u])continue;
//		dfs2(to[ui], false);
//	}
//	if (son[u] != 0)dfs2(son[u], true);
//	sc.clear();
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa[u] || to[ui] == son[u])continue;
//		check(to[ui]);
//		effect(to[ui]);
//	}
//	//cout << u << " " << same << "**\n";
//	if (sc.size() >= 2 || sc.size()>0 && color[u] != 0 && *sc.begin() != color[u]) {
//		ans += weight[u];
//	}
//	if (color[u] == 0) {
//		if (sc.size() != 0) {
//			//cout << u << "xixi\n";
//			color[u] = *sc.begin();
//		}
//		else {
//			if (son[u] != 0) {
//				if(!ap.empty())color[u] = *ap.begin();
//				//cout << u << "haha\n";
//			}
//			//else {
//			//	color[u] = 1;
//			//	//if (!unused.empty()) {
//			//	//	auto it = unused.begin();
//			//	//	color[u] = *it;
//			//	//	unused.erase(it);
//			//	//}
//			//	//else {//cout << u << "ohyeah\n";
//			//	//	color[u] = near[u];
//			//	//}
//			//}
//		}
//	}
//	if(color[u]!=0)ap.insert(color[u]);
//	if (!keep) {
//		ap.clear();
//	}
//}
//void dfs5(int u) {
//	if (color[u] == 0) {
//		color[u] = color[fa[u]];
//	}
//	for (int ui = head[u]; ui != 0; ui = nex[ui]) {
//		if (to[ui] == fa[u])continue;
//		dfs5(to[ui]);
//	}
//}
//void clear() {
//	for (int i = 1; i <= n; i++) {
//		head[i] = 0;
//		son[i] = 0;
//		fa[i] = 0;
//		near[i] = 0;
//	}
//	ap.clear();
//	sc.clear();
//	cnt = 1;
//	ans = 0;
//}
//void solve() {
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++) {
//		cin >> weight[i]; 
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> color[i];
//	}
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//	dfs1(1, 0);
//	dfs2(1, 1);
//	cout << ans << "\n";
//	dfs5(1);
//	for (int i = 1; i <= n; i++) {
//		if (!color[i]) {
//			color[i] = 1;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << color[i] << " ";
//	}
//	cout << '\n';
//	clear();
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int N = 250000 + 5;
//vector<vector<array<int,2>>>g;
//int st[N][23];
//int stmin[N][23];
//int dfn[N];
//int seg[N];
//int siz[N];
//int dep[N];
//int cntdfn = 0;	
//int n;
//void dfs(int u, int fa,int w) {
//	st[u][0] = fa;
//	stmin[u][0] = w;
//	dep[u] = dep[fa] + 1;
//	dfn[u] = ++cntdfn;
//	seg[cntdfn] = u;
//	siz[u] = 1;
//	for (int p = 1; p <= 22; p++) {
//		st[u][p] = st[st[u][p - 1]][p - 1];
//		stmin[u][p] = min(stmin[u][p - 1], stmin[st[u][p - 1]][p - 1]);
//	}
//	for (auto [v, w1] : g[u]) {
//		if (v == fa)continue;
//		dfs(v, u, w1);
//		siz[u] += siz[v];
//	}
//}
//int lca(int u, int v) {
//	if (dep[u] < dep[v])swap(u, v);
//	for (int p = 22; p >= 0; p--) {
//		if (dep[st[u][p]] >= dep[v]) {
//			u = st[u][p];
//		}
//	}
//	if (u == v) {
//		return u;
//	}
//	for (int p = 22; p >= 0; p--) {
//		if (st[u][p] != st[v][p]) {
//			u = st[u][p];
//			v = st[v][p];
//		}
//	}
//	return st[u][0];
//}
//int getmin(int u, int fu) {
//	if (dep[u] < dep[fu])swap(u, fu);
//	int ans = INT_MAX;
//	for (int p = 22; p >= 0; p--) {
//		if (dep[st[u][p]] >= dep[fu]) {
//			ans = min(ans, stmin[u][p]);
//			u = st[u][p];
//		}
//	}
//	return ans;
//}
//ll f(int u, int fa, unordered_map<int, vector<array<int, 2>>>&g1,set<int>&key) {
//	ll ans = 0;
//	for (auto [v, w] : g1[u]) {
//		if (v == fa)continue;
//		if (key.count(v)) {
//			ans += w;
//		}
//		else {
//			ans += min((ll)w, f(v, u, g1, key));
//		}
//	}
//	return ans;
//}	
//void solve() {
//	int k;
//	cin >> k;
//	vector<int>p(k);
//	set<int>key;
//	for (int i = 0; i < k; i++) {
//		cin >> p[i];
//		key.insert(p[i]);
//	}
//	sort(p.begin(), p.end(), [&](int x, int y) {
//		return dfn[x] < dfn[y];
//		});
//	stack<int>sta;
//	sta.push(1);
//	unordered_map<int, vector<array<int, 2>>>g1;
//	for (int i = 0; i < k; i++) {
//		int anc = lca(p[i], sta.top());
//		if (anc == sta.top())sta.push(p[i]);
//		else {
//			int lst = 0;
//			while (!sta.empty()&&dep[sta.top()] > dep[anc]) {
//				if (lst != 0) {
//					int mn = getmin(lst, sta.top());
//					g1[lst].push_back({ sta.top(),mn });
//					g1[sta.top()].push_back({ lst,mn });
//				}
//				lst = sta.top();
//				sta.pop();
//			}
//			if (sta.empty() || dep[sta.top()] < anc) {
//				sta.push(anc);
//			}
//			int mn = getmin(lst, sta.top());
//			g1[lst].push_back({ sta.top(),mn });
//			g1[sta.top()].push_back({ lst,mn });
//			sta.push(p[i]);
//		}
//	}
//	int lst = 0;
//	while (!sta.empty()) {
//		if (lst != 0) {
//			int mn = getmin(lst, sta.top());
//			g1[lst].push_back({ sta.top(),mn });
//			g1[sta.top()].push_back({ lst,mn });
//		}
//		lst = sta.top();
//		sta.pop();
//	}
//	cout << f(1, 0, g1,key)<<"\n";
//}
//signed main() {
//	cin >> n;
//	g.assign(n + 1, {});
//	for (int i = 1,u,v,w; i < n; i++) {
//		cin >> u >> v >> w;
//		g[u].push_back({ v,w });
//		g[v].push_back({ u,w });
//	}
//	dep[0] = 0;
//	dfs(1, 0, INT_MAX);
//	int m;
//	cin >> m;
//	while (m--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//int gcd(int a, int b) {
//	while (b != 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//void solve() {
//	int n, m, q;
//	cin >> n >> m >> q;
//	vector<int>a(n + 1, 0);
//	vector<int>d(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		d[i] = ((a[i] - a[i - 1]) % m + m) % m;
//	}
//	map<int, long long>mp;
//	for (int i = 1; i * i <= m; i++) {
//		if (m % i == 0) {
//			if (!mp.count(i)) {
//				long long val = 0;
//				for (int j = 1; j <= n; j++) {
//					val += d[j] % i;
//				}
//				mp[i] = val;
//			}
//			if (!mp.count(m / i)) {
//				long long val = 0;
//				for (int j = 1; j <= n; j++) {
//					val += d[j] % (m / i);
//				}
//				mp[m / i] = val;
//			}
//		}
//	}
//	for (int i = 1, op, p, x; i <= q; i++) {
//		cin >> op;
//		if (op == 1) {
//			cin >> p >> x;
//			for (auto [u, v] : mp) {
//				if (p != n) {
//					mp[u] -= ((a[p + 1] - a[p]) % m + m) % m % u;
//					mp[u] += ((a[p + 1] - x) % m + m) % m % u;
//				}
//				mp[u] -= ((a[p] - a[p - 1]) % m + m) % m % u;
//				mp[u] += ((x - a[p - 1]) % m + m) % m % u;
//
//			}
//			a[p] = x;
//		}
//		else {
//			cin >> x;
//			int g = gcd(x, m);
//			if (mp[g] < m) {
//				cout << "YES\n";
//			}
//			else {
//				cout << "NO\n";
//			}
//		}
//	}
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
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
//	vector<int>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	vector<vector<int>>g(4 * q + 1);
//	int cnt = 1;//用于给某个大小关系分配编号//同一关系分配相同编号
//	map<int, array<int, 2>>mp;
//	set<array<int, 3>>ef;//目前在生效的关系 0<1 2是编号
//	for (int i = 1, x, y, z; i <= q; i++) {
//		cin >> x >> y >> z;
//		int id1 = -1,id2=-1;
//		if (y != z) { 
//			id1 = cnt++;
//			mp[id1] = { z,y };
//			for (auto p : ef) {
//				if (p[0] == z || p[1] == z) {
//					g[id1].push_back(p[2]);
//					ef.erase(p);
//				}
//			}
//		}
//		if (x != z) { 
//			id2 = cnt++;
//			mp[id2] = { z,x };
//			for (auto p : ef) {
//				if (p[0] == z || p[1] == z) {
//					g[id2].push_back(p[2]);
//					ef.erase(p);
//				}
//			}
//		}
//		if(id1!=-1){
//			ef.insert({ z,y,id1 });
//		}
//		if(id2!=-1){
//			ef.insert({ z,x,id2 });
//		}
//	}
//
//	set<array<int, 3>>nex;//下一层将生效的关系
//	vector<bool>ajb(n + 1, false);//当前层该位置是否可以向大调整
//	for (auto [x, y, id] : ef) {
//		if (b[x] > b[y]) {
//			if (!ajb[y]) {
//				cout << -1 << "\n";
//				return;
//			}
//			else {
//				b[y]=
//			}
//		}
//		
//	}
//
//
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
//	int n, q;
//	cin >> n >> q;
//	vector<int>b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	vector<int>save(b);
//	vector<array<int, 3>>op;
//	for (int i = 1,x,y,z; i <= q; i++) {
//		cin >> x >> y >> z;
//		op.push_back({ x,y,z });
//	}
//	for (int i = q - 1; i >= 0; i--) {
//		int x = op[i][0], y = op[i][1], z = op[i][2];
//		if (b[x] < b[z]) {
//			b[x] = b[z];
//		}
//		if (b[y] < b[z]) {
//			b[y] = b[z];
//		}
//		if (y != z && x != z) {
//			b[z] = 0;
//		}
//	}
//	vector<int>tmp(b);
//	for (int i = 0; i < q; i++) {
//		int x = op[i][0], y = op[i][1], z = op[i][2];
//		tmp[z] = min(tmp[x], tmp[y]);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (tmp[i] != save[i]) {
//			cout << -1 << "\n";
//			return;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << b[i] << " ";
//	}
//	cout << "\n";
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
//const int N = 1e5 + 5e4+5;
//vector<vector<int>>g;
//int dep[N];
//void dfs(int u, int fa) {
//	dep[u] = dep[fa] + 1;
//	for (auto v : g[u])if (v != fa) {
//		dfs(v, u);
//	}
//}
//int down[N];//当前树最深处编号最大的叶子节点的编号
//int top[N];//长链剖分
//int height[N];
//int son[N];
//void dfs1(int u,int fa) {
//	dep[u] = dep[fa] + 1;
//	height[u] = 1;
//	bool gotson = false;
//	for (auto v : g[u])if (v != fa) {
//		dfs1(v, u);
//		if (height[v] > height[son[u]]||
//			(height[v] == height[son[u]] && down[v] > down[son[u]])) {
//			son[u] = v;
//		}
//		height[u] = max(1 + height[v], height[u]);
//		gotson = true;
//	}
//	if (!gotson) {
//		down[u] = u;
//	}
//	else {
//		down[u] = down[son[u]];
//	}
//}
//vector<array<int, 3>>ans;
//void dfs2(int u, int fa) {
//	if (fa == 0 || son[fa] != u) {
//		top[u] = u;
//	}
//	else {
//		top[u] = top[fa];
//	}
//	bool gotson = 0;
//	for (auto v : g[u])if (v != fa) {
//		dfs2(v, u);
//		gotson = true;
//	}
//	if (!gotson) {
//		ans.push_back({ top[u],u,dep[u]-dep[top[u]]+1});
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	g.assign(n + 1, {});
//	for (int i = 1,u,v; i < n; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	dfs(1, 0);
//	int mxdep = 0;
//	int rt = 0;
//	for (int i = 1; i <= n; i++) {
//		if (dep[i] > mxdep) {
//			mxdep = dep[i];
//			rt = i;
//		}
//	}
//	//从能做直径端点的点里选一个编号最大的做根
//	int final = 0;
//	dfs(rt, 0);
//	mxdep = 0;
//	for (int i = 1; i <= n; i++) {
//		mxdep = max(mxdep, dep[i]);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (dep[i] == mxdep)final = max(final, i);
//	}
//	//cout << final << "**\n";
//	dfs(final, 0);
//	for (int i = 1; i <= n; i++) {
//		mxdep = max(mxdep, dep[i]);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (dep[i] == mxdep)final = max(final, i);
//	}
//	rt = final;
//
//	//cout << rt << "***\n";
//	dfs1(rt, 0);
//	//for (int i = 1; i <= n; i++) {
//	//	cout << height[i] << " ";
//	//}cout << "____\n";
//	//for (int i = 1; i <= n; i++) {
//	//	cout << son[i] << " ";
//	//}cout << "____\n";
//	dfs2(rt, 0);
//	//for (int i = 1; i <= n; i++) {
//	//	cout << top[i] << " ";
//	//}cout << "__&&\n";
//	sort(ans.begin(), ans.end(), [&](auto x,auto y) {
//		assert(x[1] != y[1] && x[1] != y[0] && x[0] != y[1] && x[0] != y[0]);
//		if (x[2] == y[2]) {
//			return max(x[1], x[0]) > max(y[1], y[0]);
//		}
//		return x[2] > y[2];
//		});
//	for (int i = 0; i < ans.size(); i++) {
//		if (ans[i][0] > ans[i][1])swap(ans[i][0], ans[i][1]);
//		cout << ans[i][2] << " " << ans[i][1] << " " << ans[i][0] << " ";
//	}
//	cout << "\n";
//	ans.clear();
//	for (int i = 1; i <= n; i++) {
//		son[i] = 0;
//		down[i] = 0;
//		height[i] = 0;
//		top[i] = 0;
//		dep[i] = 0;
//	}
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




//复杂度证明很妙
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 150005;
//vector<vector<int>>g;
//set<int>used;
//set<int>rest;
//vector<array<int, 3>>ans;
//int dep[N];
//int fa[N];
//int mxdep = 0;
//void dfs(int u, int pa, int& rt) {
//	dep[u] = dep[pa] + 1;
//	fa[u] = pa;
//	if (dep[u] > mxdep) {
//		mxdep = dep[u];
//		rt = u;
//	}
//	else {
//		if (dep[u] == mxdep && u > rt) {
//			rt = u;
//		}
//	}
//	for (auto v : g[u])if (!used.count(v) && v != pa) {
//		dfs(v, u, rt);
//	}
//}
//void run(int u) {
//	mxdep = 0;
//	dep[u] = 0;
//	int rt = u;
//	dfs(u, u, rt);
//	//从能做直径端点的点里选一个编号最大的做根
//	int final = 0;
//	dep[rt] = 0;
//	dfs(rt, rt, rt);
//	int a = rt;
//	dfs(a, a, rt);
//	int b = rt;
//	int cnt = 1;
//	used.insert(a);
//	while (b != a) {
//		used.insert(b);
//		b = fa[b];
//		cnt++;
//	}
//	ans.push_back({ a,rt,cnt });
//}
//void solve() {
//	int n;
//	cin >> n;
//	g.assign(n + 1, {});
//	for (int i = 1; i <= n; i++)rest.insert(i);
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	vector<int>del;
//	while (!rest.empty()) {
//		for (auto v : rest) {
//			if(!used.count(v))
//			run(v);
//		}
//		for (auto v : rest) {
//			if (used.count(v))del.push_back(v);
//		}
//		for (auto v : del) {
//			rest.erase(v);
//		}
//		del.clear();
//	}
//	sort(ans.begin(), ans.end(), [&](auto x, auto y) {
//		assert(x[1] != y[1] && x[1] != y[0] && x[0] != y[1] && x[0] != y[0]);
//		if (x[2] == y[2]) {
//			return max(x[1], x[0]) > max(y[1], y[0]);
//		}
//		return x[2] > y[2];
//		});
//	for (int i = 0; i < ans.size(); i++) {
//		if (ans[i][0] > ans[i][1])swap(ans[i][0], ans[i][1]);
//		cout << ans[i][2] << " " << ans[i][1] << " " << ans[i][0] << " ";
//	}
//	cout << "\n";
//	used.clear();
//	rest.clear();
//	ans.clear();
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
//const int N = 7e6 + 5;
//int tree[N][2];
//int rst[N];//能走到当前结点的所有数里下标最靠右的那一个的下标
//int cnt = 0;
//int getk(int x, int k) {
//	return (x >> k) & 1;
//}
//void insert(int x, int idx) {
//	int cur = 0;
//	for (int i = 32; i >= 0; i--) {
//		int b = getk(x, i);
//		if (tree[cur][b] == 0) {
//			tree[cur][b] = ++cnt;
//		}
//		cur = tree[cur][b];
//		rst[cur] = idx;
//	}
//}
//void solve() {
//	for (int i = 0; i <= cnt + 5; i++) {
//		tree[i][0] = tree[i][1] = 0;
//		rst[i] = 0;
//	}
//	cnt = 0;
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	if (k == 0) {
//		cout << 1 << "\n";
//		return;
//	}
//	int ans = INT_MAX;
//	for (int i = 1; i <= n; i++) {
//		//cout << "\n------------\n";
//		//cout << bitset<33>(a[i])<<"\n";
//		//cout << bitset<33>(k) << "\n";
//		int cur = 0;
//		int cnt = 0;
//		for (int j = 32; j >= 0; j--,cnt++) {
//			int b = getk(a[i], j);
//			//cout << b ;
//			if (getk(k, j) == 0) {
//				if (b == 1) {
//					if (tree[cur][0] != 0) {
//						ans = min(ans, i - rst[tree[cur][0]] + 1);
//					}
//				}
//				else {
//					if (tree[cur][1] != 0) {
//						ans = min(ans, i - rst[tree[cur][1]] + 1);
//					}
//				}
//				if (tree[cur][b] == 0)break;
//				cur = tree[cur][b];
//			}
//			else {
//				if (b == 1) {
//					if (tree[cur][0] == 0) {
//						break;
//					}
//					cur = tree[cur][0];
//				}
//				else {
//					if (tree[cur][1] == 0) {
//						break;
//					}
//					cur = tree[cur][1];
//				}
//			}
//		}
//		if (cnt == 33)ans = min(ans, i - rst[cur] + 1);
//		insert(a[i], i);
//		//cout << "\n-------------\n";
//	}
//	cout << (ans==INT_MAX?-1:ans) << "\n";
//}
//signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}




//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	map<string, int>mp;
//	int cntid = 0;
//	string s;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> s;
//		if (!mp.count(s))mp[s] = ++cntid;
//		a[i] = mp[s];
//	}
//	vector<vector<int>>b(m + 1);
//	for (int i = 1; i <= m; i++) {
//		b[i].resize(n + 1);
//		for (int j = 1; j <= n; j++) {
//			cin >> s;
//			if (!mp.count(s))mp[s] = ++cntid;
//			b[i][j] = mp[s];
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		bool flag = 0;
//		for (int j = 1; j <= m; j++) {
//			if (b[j][i] == a[i]) {
//				flag = true;
//				break;
//			}
//		}
//		if (!flag) {
//			cout << -1 << "\n";
//			return;
//		}
//	}
//	int ans = 0;
//	for (int j = 1; j <= m; j++) {
//		int cnt = 0;
//		for (int i = 1; i <= n; i++) {
//			if (a[i] == b[j][i])cnt++;
//		}
//		ans = max(ans, cnt);
//	}
//	cout << 3* n - 2*ans << "\n";
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
//const int mod = 1e9 + 7;
//using namespace std;
//int qpow(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a % mod;
//		}
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ans;
//}
//void solve() {
//	int n, m, k;
//	cin >> n >> m >> k;
//	int nei = (n - 2) * (m - 2) + 4;
//	int wai = n*m-nei;//对应内外和角落未被填的格子角落和内合并了,因为填不填不影响奇偶
//	int cur = 0;//当前奇偶性
//	for (int i = 1,x,y,c; i <= k; i++) {
//		cin >> x >> y >> c;
//		if ((x != 1 && x != n && y != 1 && y != m) || ((x == 1 || x == n) && (y == 1 || y == m))) {
//			nei--;
//		}
//		else {
//			wai--;
//			if (c == 1) {
//				cur^=1;
//			}
//		}
//	}
//	if (wai == 0) {
//		if (cur == 1)cout << 0 << "\n";
//		else cout << qpow(2, nei) << "\n";
//	}
//	else cout<<qpow(2, nei)*qpow(2,wai-1)%mod<<"\n";
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
//	int n;
//	cin >> n;
//	set<int>st;
//	for (int i = 1; i <= n * n + 1; i++) {
//		st.insert(i);
//	}
//	vector<int>tmp;
//	vector<int>dp(n * n + 2);
//	int c;
//	for (int i = 1; i <= n; i++) {
//		cout << "? "<<st.size()<<" ";
//		for (auto v : st) {
//			cout << v << " ";
//		}cout << endl;
//		cin >> c;
//		tmp.resize(c);
//		for (int i = 0; i < c; i++) {
//			cin >> tmp[i];
//		}
//		if (c >= n + 1) {
//			cout << "! ";
//			for (int i = 0; i <= n; i++) {
//				cout << tmp[i] << " ";
//			}
//			cout << endl;
//			return;
//		}
//		for (auto v : tmp) {
//			st.erase(v);
//			dp[v] = i;
//		}
//	}
//	for (auto v : st) {
//		dp[v] = n + 1;
//	}
//	vector<int>ans;
//	int cur = n + 1;
//	for (int i = n * n + 1; i >= 1; i--) {
//		if (dp[i] == cur) {
//			ans.push_back(i);
//			cur--;
//		}
//		
//	}
//	reverse(ans.begin(), ans.end());
//	cout << "! ";
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i] << " ";
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




//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod=998244353;
//int n=0, m=0, d=0;
//int dp[2005][2005];//仅从下面到当前位置的方案
//int dp1[2005][2005];//从当前行移到该位置的方案数
//void solve() {
//	for (int i = 0; i <= n + 4; i++) {
//		for (int j = 0; j < m + 4; j++) {
//			dp[i][j] =dp1[i][j]= 0;
//		}
//	}
//	cin >> n >> m >> d;
//	vector<string>g(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> g[i];
//		g[i] = " " + g[i];
//	}
//	vector<int>psum(m + 1);//上一行dp0和dp1的前缀和
//	vector<int>pcsum(m + 1);//该行dp0的前缀和
//	for (int i = 1; i <= m; i++) {
//		if (g[n][i] == 'X') {
//			dp[n][i] = 1;
//		}
//	}
//	for (int i = 1; i <= m; i++) {
//		pcsum[i] = (dp[n][i] + pcsum[i - 1])%mod;
//	}
//	for (int i = 1; i <= m; i++) {
//		if (g[n][i] == 'X') {
//			int r = min(m, i + d);
//			int l = max(0ll, i - d - 1);
//			assert(r <= m && l >= 0);
//			dp1[n][i] = ((pcsum[r] - pcsum[l] + mod) % mod - dp[n][i] + mod)%mod;
//		}
//	}
//	for (int i = 1; i <= m; i++) {
//		psum[i] = ((dp1[n][i] + dp[n][i]) % mod + psum[i - 1])%mod;
//	}
//	for (int i = n - 1; i >= 1; i--) {
//		for (int j = 1; j <= m; j++) {
//			if (g[i][j] == 'X') {
//				int d1 = sqrt(d * d - 1);
//				int r = min(m,j+d1);
//				int l = max(0ll, j - d1 - 1);
//				//cout << i << " " << j << " " << r << " " << l << " " << d1<<" "<<psum[r]-psum[l] << "***\n";
//				assert(r <= m && l >= 0);
//				dp[i][j] = (psum[r] - psum[l] + mod)%mod;
//			}
//		}
//		for (int j = 1; j <= m; j++) {
//			pcsum[j] = (pcsum[j - 1] + dp[i][j])%mod;
//		}
//		for (int j = 1; j <= m; j++) {
//			if (g[i][j] == 'X') {
//				int r = min(m, j + d);
//				int l = max(0ll, j - d - 1);
//				assert(r <= m && l >= 0);
//				dp1[i][j] = ((pcsum[r] - pcsum[l] + mod) % mod - dp[i][j] + mod)%mod;
//			}
//		}
//		for (int j = 1; j <= m; j++) {
//			psum[j] = ((psum[j - 1] + dp1[i][j]) % mod + dp[i][j])%mod;
//		}
//	}
//	cout << psum[m] << "\n";
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
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(2*n + 1);
//	vector<int>b(2*n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		a[n + i] = a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//		b[i + n] = b[i];
//	}
//	int ans=0;
//	int sum = 0;
//	deque<int>q;
//	for (int i = 1; i <= 2 * n; i++) {
//		if (a[i] - b[i] + sum > 0) {
//			q.push_back(a[i] - b[i]);
//			sum += a[i] - b[i];
//		}
//		else {
//			sum += a[i] - b[i];
//			q.push_back(a[i] - b[i]);
//			ans = max(ans, (int)q.size());
//			while (!q.empty()&&sum <= 0) {
//				sum -= q.front();
//				q.pop_front();
//			}
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

//喵喵贪心>^w^<
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	priority_queue<int>pq;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		pq.push(a[i]);
//		if ((n - i+1) % (k + 1) == 0 && !pq.empty()) {
//			ans += pq.top();
//			pq.pop();
//		}
//
//	}
//	cout << ans << "\n";
//
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
//const int mod = 1e9 + 7;
//int qpow(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a % mod;
//		}
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ans;
//}
//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s = "0" + s;
//	vector<int>dp1(n + 1,0);//右移至当前位置最后是1的概率
//	vector<int>dp0(n + 1,0);//右移至当前位置最后是0的概率
//	for (int i = n; i >= 1; i--) {
//		if (s[i] == '1') {
//			for (int j = i + 1; j <= n; j++) {
//				dp0[i] = (dp0[i] + dp1[j] * qpow(2, mod - 2)%mod)%mod;
//				if (s[j] == '0')break;
//			}
//			dp1[i] = (1 - dp0[i] + mod) % mod;
//		}
//		else {
//			for (int j = i + 1; j <= n; j++) {
//				dp1[i] = (dp1[i] + dp1[j] * qpow(2, mod - 2) % mod) % mod;
//				if (s[j] == '0')break;
//			}
//			dp0[i] = (1 - dp1[i] + mod) % mod;
//		}
//	}
//	for (int i = 2; i <= n; i++) {
//		dp1[0] = (dp1[0] + dp1[i] * qpow(2, mod - 2)%mod)%mod;
//		if (s[i] == '0')break;
//	}
//	dp0[0] = (1 - dp1[0] + mod) % mod;
//	cout << ((n-1)*dp0[0] % mod + n * dp1[0] % mod) % mod << "\n";
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
//const int mod = 1e9 + 7;
//int qpow(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a % mod;
//		}
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ans;
//}
//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s = "0" + s;
//	vector<double>dp1(n + 1, 0);//右移至当前位置最后是1的概率
//	vector<double>dp0(n + 1, 0);//右移至当前位置最后是0的概率
//	for (int i = n; i >= 0; i--) {
//		if (s[i] == '1') {
//			for (int j = i + 1; j <= n; j++) {
//				dp0[i] = dp0[i] + dp1[j]/2;
//				if (s[j] == '0')break;
//			}
//			dp1[i] = 1 - dp0[i];
//		}
//		else {
//			for (int j = i + 1; j <= n; j++) {
//				dp1[i] = dp1[i] + dp1[j]/2;
//				if (s[j] == '0')break;
//			}
//			dp0[i] = 1 - dp1[i];
//		}
//	}
//	for (int i = n; i >= 0; i--) {
//		cout << dp0[i] << "__" << dp1[i] << "\n";
//	}
//	//cout << (n * dp0[0] % mod + (n + 1) * dp1[0] % mod) % mod << "\n";
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
//void solve() {
//	int n;
//	cin >> n;
//	vector<array<int, 2>>dl, dr;
//	char op;
//	for (int i = 1,u; i <= n; i++) {
//		cin >> op>>u;
//		if (op == 'x') {
//			dl.push_back({ u,1 });
//		}
//		else {
//			dl.push_back({ u,0 });
//		}
//		cin >> op >> u;
//		if (op == 'x') {
//			dr.push_back({ u,1 });
//		}
//		else {
//			dr.push_back({ u,0 });
//		}
//	}
//	vector<int>dp(n + 1,0);//在当前门前(全是加就与后面一致)，人应该放在那边,l是0,r是1
//	for (int i = n - 1; i >= 1; i--) {
//		if (dl[i][1] != 1 && dr[i][1] != 1) { 
//			dp[i] = dp[i + 1];
//			continue;
//		}
//		if (dl[i][1] == 1 && dr[i][1] == 1) {
//			if (dl[i][0] > dr[i][0]) {
//				dp[i] = 0;
//			}
//			else if (dr[i][0] > dl[i][0]) {
//				dp[i] = 1;
//			}
//			else {
//				dp[i] = dp[i + 1];
//			}
//		}
//		else if (dl[i][1] == 1) {
//			dp[i] = 0;
//		}
//		else {
//			dp[i] = 1;
//		}
//
//	}
//	int l = 1, r = 1,sav=0;//左边道上的人,右边道上的人,当前攒着还没放的人
//	for (int i = 0; i < n; i++) {
//		if (dl[i][1] == 1 || dr[i][1] == 1) {
//			if (dp[i] == 0) {
//				l += sav;
//			}
//			else {
//				r += sav;
//			}
//			sav = 0;
//			if (dl[i][1] == 1) {
//				sav += (dl[i][0] - 1) * l;
//			}
//			else {
//				sav += dl[i][0];
//			}
//			if (dr[i][1] == 1) {
//				sav += (dr[i][0] - 1) * r;
//			}
//			else {
//				sav += dr[i][0];
//			}
//		}
//		else {
//			sav += dl[i][0] + dr[i][0];
//		}
//		//cout << l << " " << r << " " << dp[i] << "**\n";
//	}
//	cout << l + r + sav << "\n";
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
//void solve() {
//	int tmp;
//	cout << 0 << endl;
//	cin >> tmp;
//	bitset<33>a(tmp);
//	vector<int>sm(33,0);//0表示是0_0 1表示是1_0 2表示是1_1
//	vector<bool>jin(33, 0);//表示当前位是否被后面进了一位
//	int q1 = 0;
//	bool got0 = false;
//	int ad = 1;
//	for (int i = 0; i < 30; i++) {
//		if (got0) {
//			q1 += ad << i;
//			ad ^= 1;
//			continue;
//		}
//		if (a[i] == 0) {
//			q1 += ad << i;
//			ad ^= 1;
//			got0 = true;
//		}
//	}
//	//cout << bitset<32>(q1)<<"\n";
//	cout << q1 << endl;
//	cin >> tmp;
//	//cout << bitset<32>(tmp) << "**\n";
//	bitset<33>b(tmp);
//	int i = 0;
//	while (a[i] == 1) {
//		sm[i] = 1;
//		i++;
//	}
//	bool ad1=1;
//	while (i < 30) {
//		//cout << i << " " << ad1 <<" "<<a[i]<<" "<<b[i]<< "**\n";
//		if (ad1) {
//			if (a[i] == 0) {
//				if (!jin[i]) {
//					//当前位置原本是0,在a+b中没被进位,现在或了1(该位不可能是0_1)
//					if (a[i + 1] == b[i + 1]) {
//						sm[i] = 2;
//						jin[i + 1] = 1;
//					}
//					else {
//						sm[i] = 0;
//					}
//				}
//				else {
//					//当前位置原本是0,在a+b中被进位,现在或了1(该位不可能是0_1)
//					sm[i] = 1;
//					jin[i + 1] = 1;
//				}
//			}
//			else {
//				if (!jin[i]) {
//					//当前位置原本是1,在a+b中没被进位,现在或了1(该位不可能是0_1)
//					sm[i] = 1;
//				}
//				else {
//					//当前位置原本是1,在a+b中被进位,现在或了1(该位不可能是0_1)
//					if (a[i + 1] == b[i + 1]) {
//						sm[i] = 2;
//						jin[i + 1] = 1;
//					}
//					else {
//						sm[i] = 0;
//					}
//				}
//			}
//		}
//
//
//		else {
//			if (a[i] == 0) {
//				if (!jin[i]) {
//					//当前位置原本是0,在a+b中没被进位,现在或了0(该位不可能是0_1)
//					if (b[i + 1] == 1) {
//						sm[i] = 2;
//						jin[i + 1] = 1;
//					}
//					else {
//						sm[i] = 0;
//					}
//				}
//				else {
//					//当前位置原本是0,在a+b中被进位,现在或了0(该位不可能是0_1)
//					sm[i] = 1;
//					jin[i + 1] = 1;
//				}
//			}
//			else {
//				if (!jin[i]) {
//					//当前位置原本是1,在a+b中没被进位,现在或了0(该位不可能是0_1)
//					sm[i] = 1;
//				}
//				else {
//					//当前位置原本是1,在a+b中被进位,现在或了0(该位不可能是0_1)
//					if (b[i + 1] == 1) {
//						sm[i] = 2;
//						jin[i + 1] = 1;
//					}
//					else {
//						sm[i] = 0;
//					}
//				}
//			
//			}
//
//
//		}
//		i++;
//		ad1 ^= 1;
//	}
//	//for (int i = 0; i <= 10; i++) {
//	//	cout << sm[i] << "_"<<jin[i]<<"  ";
//	//}
//	//cout << "**\n";
//	cout << "!" << endl;
//	int qry;
//	cin >> qry;
//	int aa = 0, bb = 0;
//	for (int i = 0; i < 30; i++) {
//		if (sm[i] == 1) {
//			aa |= 1ll << i;
//		}
//		else if(sm[i]==2) {
//			aa |= 1ll << i;
//			bb |= 1ll << i;
//		}
//	}
//	//cout << aa << " " << bb << "&&\n";
//	cout << (aa | qry) + (bb | qry) << "\n";
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
//const int N = 405;
//int dp[N][N];
//void solve() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			dp[i][j] = 0;
//		}
//	}
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i+2 <= n; i++) {
//		dp[i][i + 2] = a[i] * a[i + 1] * a[i + 2];
//	}
//	for (int len = 3; len <= n; len++) {
//		for (int l = 1; l + len - 1 <= n; l++) {
//			int r = l + len - 1;
//			for (int k = l + 1; k < r; k++) {
//				dp[l][r] =max(dp[l][r], a[l] * a[r] * a[k] + dp[l + 1][k - 1] + dp[k + 1][r - 1]);
//			}
//			for (int k = l; k < r; k++) {
//				dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
//			}
//		}
//	}
//	cout << dp[1][n] << "\n";
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
//int g(int x) {
//	for (int i = 0; i <= 31; i++) {
//		if ((1ll << i) >= x) {
//			return 1ll << i;
//		}
//	}
//	return -1;
//}
//int f(int l1, int r1, int l2, int r2) {
//	//cout << l1 << " " << r1 << " " << l2 << " " << r2 << "**\n";
//	if (l1 >= r1 || l2 >= r2)return 0;
//	if (l1 + 1 == r1)return r2 - l2;
//	if (l2 + 1 == r2)return r1 - l1;
//	int w = r1 - l1;
//	int h = r2 - l2;
//	if (w < h && (w == (w & (-w))) && r1 % w == 0 && l1 % w == 0) {
//		int u = r2 / w * w;
//		int d = (l2 + w - 1) / w * w;
//		assert(d >= l2);
//		//cout << u << " " << d << "*\n";
//		return (u - d) / w + f(l1, r1, l2, d) + f(l1, r1, u, r2);
//	}
//	if (h < w &&h==(h&(-h))&& r2 % h == 0 && l2 % h == 0) {
//		int u = r1 / h * h;
//		int d = (l1 + h - 1) / h * h;
//		assert(d >= l1);
//		//cout << u << ' ' << d << "**\n";
//		return (u - d) / h + f(l1, d, l2, r2) + f(u, r1, l2, r2);
//	}
//	if (w == h && (w == (w & (-w))) && l1 % w == 0 && r1 % w == 0 && l2 % w == 0 && r2 % w == 0)return 1;
//	if (w > h) {
//		int t = g(w) / 2;
//		int m = (r1 - 1) / t * t;
//		return f(l1, m, l2, r2) + f(m, r1, l2, r2);
//	}
//	else {
//		int t = g(h) / 2;
//		int m = (r2 - 1) / t * t;
//		//cout << t << " " << m << "&\n";
//		return f(l1, r1, l2, m) + f(l1, r1, m, r2);
//	}
//
//}
//void solve() {
//	int l1, r1, l2, r2;
//	cin >> l1 >> r1 >> l2 >> r2;
//	cout << f(l1, r1, l2, r2) << "\n";
//}
//signed main() {
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
//void add(int jl,int jr,int l, int r, vector<int>& a) {
//	//cout <<jl<<" "<< l <<" "<<jr<<" "<< r << "\n";
//	if (l == r)return;
//	if (jl <= l && jr >= r) {
//		a.push_back(r - l);
//		return;
//	}
//	int mid = l + r >> 1;
//	if (jl < mid) {
//		add(jl, jr, l, mid, a);
//	}
//	if (jr > mid) {
//		add(jl, jr, mid, r, a);
//	}
//}
//void solve() {
//	int l1, r1, l2, r2;
//	cin >> l1 >> r1 >> l2 >> r2;
//	vector<int>d;
//	vector<int>d1;
//	add(l1, r1, 0, 1 << 25, d);
//	add(l2, r2, 0, 1 << 25, d1);
//	int ans = 0;
//	for (auto v : d) {
//		for (auto u : d1) {
//			ans += max(u, v) / min(u, v);
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
//int p;
//vector<int>a;
//int n;
//int cal(int x) {
//	if (x <= 2 * n)return a[x];
//	if (x % 2 == 1) {
//		x -= 1;
//	}
//	int m = x >> 1;
//	if (m & 1)return p;
//	else {
//		return p ^ cal(m);
//	}
//}
//void solve() {
//	int l, r;
//	cin >> n >> l >> r;
//	a.assign(2*n +3,0);
//	vector<int>pxor(n + 2);
//	p = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		pxor[i] = a[i] ^ pxor[i - 1];
//	}
//	if (!(n & 1)) {
//		n++;
//		a[n] = pxor[n >> 1];
//		pxor[n] = pxor[n - 1] ^ a[n];
//	}
//	for (int i = n + 1; i <= 2*n; i++) {
//		a[i] = pxor[i>>1];
//	}
//	p = pxor[n];
//	cout << cal(l) << "\n";
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
//int cl[26];
//int cr[26];
//int ccl[26];
//int ccr[26];
//void clear() {
//	for (int i = 0; i < 26; i++) {
//		cl[i] = cr[i] = 0;
//		ccl[i] = ccr[i] = 0;
//	}
//}
//void solve() {
//	clear();
//	string s;
//	cin >> s;
//	int n = s.size();
//	s = " " + s;
//	int mid = n >> 1;
//	for (int i = 1; i <= mid; i++) {
//		cl[s[i] - 'a']++;
//	}
//	for (int i = mid + 1; i <= n; i++) {
//		cr[s[i] - 'a']++;
//	}
//	bool same = true;
//	for (int i = 0; i < 26; i++) {
//		if (cl[i] != cr[i]) {
//			same = false; break;
//		}
//	}
//	if (same) {
//		int l = -1,r=-2;
//		for (int i = 1; i <= mid; i++) {
//			if (s[i] != s[n - i + 1]) {
//				r = i;
//				if (l == -1)l = i;
//			}
//		}
//		cout << r - l + 1 << "\n";
//		return;
//	}
//	int l = 1, r = n;
//	while (l<=mid&&ccl[s[l] - 'a'] + 1 <= (cl[s[l] - 'a'] + cr[s[l] - 'a']) / 2) {
//		ccl[s[l] - 'a']++;
//		l++;
//	}
//	while (r>mid&&ccr[s[r] - 'a'] + 1 <= (cl[s[r] - 'a'] + cr[s[r] - 'a']) / 2) {
//		ccr[s[r] - 'a']++;
//		r--;
//	}
//	int dif = 1;
//	while (dif<=mid&&s[dif] == s[n - dif + 1])dif++;
//	//cout << l << " " << r << " " << dif << "*\n";
//	cout << min(n - dif + 1 - l + 1,r - dif + 1) << "\n";
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
//	s = " " + s;
//	int w = 0,ww=0;
//	int fr = -1;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == 'W') {
//			ww++;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == 'W') {
//			w++;
//		}
//		else {
//			break;
//		}
//	}
//	if (w * 2 < ww||ww&1) {
//		cout << "NO\n";
//		return;
//	}
//	int r = 0, rr = 0;
//	for (int i = 2 * n; i > n; i--) {
//		if (s[i] == 'R') {
//			rr++;
//		}
//	}
//	for (int i = 2 * n; i > n; i--) {
//		if (s[i] == 'R') {
//			r++;
//		}
//		else {
//			break;
//		}
//	}
//	if (r * 2 < rr||rr&1) {
//		cout << "NO\n";
//		return;
//	}
//	cout << "YES\n";
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
//int main() {
//	int n;
//	cin >> n;
//	vector<string>a(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	string t;
//	cin >> t;
//	string ans = "";
//	vector<int>res(n), p(n, 0);
//	iota(res.begin(), res.end(), 0);
//	for (int i = 0; i < t.size(); i++) {
//		vector<int>nres;
//		for (auto j:res) {
//			int& k = p[j];
//			while (k < a[j].size() && a[j][k] != t[i]) {
//				ans += a[j][k++];
//			}
//			if (k < a[j].size()) {
//				nres.push_back(j);
//			}
//		}
//		res = move(nres);
//		if (res.empty()) {
//			break;
//		}
//		if (i == t.size() - 1) {
//			cout << "NO\n";
//			return 0;
//		}
//		ans += t[i];
//		for (auto j : res) {
//			int& k = p[j];
//			if (k < a[j].size() && a[j][k] == t[i]) {
//				k++;
//			}
//		}
//	}
//	cout << "YES\n";
//	cout << ans << "\n";
//}


//#include<bits/stdc++.h>	
//using namespace std;
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	vector<bool>vis(n + 1, 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int ans = 0;
//	sort(a.begin()+1, a.end());
//	vector<int>sma;
//	int bigg = 0;
//	for (int i = 1; i <= n; i++) {
//		if (a[i] < k)sma.push_back(a[i]);
//		else {
//			bigg++;
//		}
//	}
//	int pr = sma.size() - 1, pl = 0;
//	int smak = 0;
//	while (pl < pr) {
//		while (pr>pl&&sma[pl] + sma[pr] >= k) {
//			pr--;
//		}
//		if (pr > pl) {
//			pr--;
//			pl++;
//			smak++;
//		}
//
//	}
//	int rst = sma.size() - 2*smak;
//	if (bigg >= smak) {
//		bigg -= smak;
//		ans += smak;
//		smak = 0;
//	}
//	else {
//		smak -= bigg;
//		ans += bigg;
//		bigg = 0;
//	}
//	if (smak != 0) {
//		if (rst >= smak) {
//			rst -= smak;
//			ans += smak;
//			smak = 0;
//		}
//		else {
//			smak -= rst;
//			ans += rst;
//			rst = 0;
//		}
//	}
//	if (smak != 0) {
//		ans += (smak*2 + 3 - 1) / 3;
//		cout << ans - 1 << "\n";
//		return;
//	}
//	else {
//		//任意两数之和大于k
//		if (bigg >= rst) {
//			ans += bigg;
//		}
//		else {
//			ans += bigg;
//			rst -= bigg;
//			ans += (rst + 1) / 2;
//		}
//		/*if (bigg >= rst * 2) {
//			bigg -= rst;
//			ans += rst;
//			rst = 0;
//			ans += bigg;
//		}
//		else {
//			ans += bigg / 2;
//			rst -= bigg / 2;
//			bigg %= 2;
//			if (bigg != 0) {
//				if (rst == 1) {
//					bigg = 0;
//					rst = 0;
//					ans += 1;
//				}
//				else if (rst == 0) {
//					ans += bigg;
//				}
//				else {
//					rst -= 2;
//					ans += 1;
//					bigg = 0;
//				}
//			}
//			ans += rst / 3;
//		}*/
//	}
//	cout << ans-1 << "\n";
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
//	int cnt0=0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		if (a[i] == 0)cnt0++;
//	}
//	set<int>st;
//	vector<bool>b(n+1,0);//当前位置右侧能不能加0
//	int mex = 1;//当前右侧mex;
//	st.insert(0);
//	for (int i = n; i >= 1; i--) {
//		while (st.count(mex))mex++;
//		if (a[i] >= mex) {
//			b[i] = 1;
//		}
//		if (a[i] != 0) {
//			st.insert(a[i]);
//		}
//	}
//	bool got0 = false;
//	for (int i = 1; i <= n; i++) {
//		if (a[i] == 0)got0 = true;
//		else if (!b[i]) {
//			if (got0) {
//				cout << n - cnt0 + 1 << "\n";
//			}
//			else cout << n - cnt0 << "\n";
//			return;
//		}
//	}
//	if (got0) {
//		cout << n - cnt0 + 1 << "\n";
//	}
//	else {
//		cout << n - cnt0<<"\n";
//	}
//
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}
//1
//2 6
//6 8
//50
//28
//25
//45
//16
//8
//1
//8 6
//45 5 54 50 2 45 25 49
//36
//33
//53
//53
//16
//42
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
////const int T = N * 32;
////int cnt = 0;
////int tree[N][2];
////void insert(int num, int id) {
////	int cur = 0;
////	for (int i = 30; i >= 0; i--) {
////		int path = (num >> i) & 1;
////		if (tree[cur][path] == 0) {
////			tree[cur][path] = ++cnt;
////		}
////		cur = tree[cur][path];
////	}
////
////}
//int high1(int x) {
//	int ans = 0;
//	while (x != 0) {
//		x >>= 1;
//		ans++;
//	}
//	return ans;
//}
////int bs(vector<int>& hh, int l, int r,int t) {
////	int ans = 0;
////	while (l <= r) {
////		int mid = l + r >> 1;
////		if (hh[mid] >= t) {
////			ans = mid;
////			l = mid + 1;
////		}
////		else {
////			r = mid - 1;
////		}
////	}
////	return ans;
////}
//void solve() {
//	int n, q;
//	cin >> n >> q;
//	vector<int>w(n + 2);
//	for (int i = 1; i <= n; i++) {
//		cin >> w[i];
//	}
//	vector<int>bxor(n + 2);
//	for (int i = n; i >= 1; i--) {
//		bxor[i] = w[i] ^ bxor[i + 1];
//	}
//	//vector<vector<int>>jp(n + 2, vector<int>(32));//i位置左侧第一个在j位置上有1的位置
//
//	//for (int i = 1; i <= n + 1; i++) {
//	//	for (int j = 0; j <= 30; j++) {
//	//		jp[i][j+1] = tmp[j+1];
//	//		if ((w[i] >> j) & 1) {
//	//			tmp[j+1] = i;
//	//		}
//	//	}
//	//}
//	//vector<int>lb(n+2);
//	//stack<int>sta;
//	//vector<int>hh(n + 2);
//	//for (int i = 1; i <= n; i++) {
//	//	hh[i] = high1(w[i]);
//	//}
//	//for (int i = n; i >= 1; i--) {
//	//	hh[i] = max(hh[i], hh[i + 1]);
//	//}
//	vector<int>tmp(33);
//	vector<vector<int>>dp(n + 2, vector<int>(33));//当前i位置之前第一个最高位>=j的数的位置
//	for (int i = 1; i <= n+1; i++) {
//		for (int j = 30; j >= 0; j--) {
//			dp[i][j+1] = max(tmp[j+1], dp[i][j + 2]);
//		}
//		for (int j = 0; j <= 30; j++) {
//			if ((w[i] >> j) & 1) {
//				tmp[j + 1] = i;
//			}
//		}
//	}
//	/*for (int i = 1; i <= n; i++) {
//		while (!sta.empty()&&hh[sta.top()]<hh[i]) {
//			sta.pop();
//		}
//		if (!sta.empty()) {
//			lb[i] = sta.top();
//		}
//		sta.push(i);
//	}*/
//	//for (int i = 1; i <= n; i++) {
//	//	cout << hh[i] << " ";
//	//}cout << "&&&\n";
//	//for (int i = 1; i <= n; i++) {
//	//	cout << bitset<10>(w[i]) << "\n";
//	//}
//	//cout << "_________\n";
//
//	vector<int>ans;
//	for (int i = 1, x; i <= q; i++) {
//		cin >> x;
//		int l, cur = n + 1;//ll表示目前x能到达的可能左边界
//
//		//cout << "ll : " << ll << '\n';
//		while (true) {
//			if (x == 0) {
//				ans.emplace_back(n - (cur - 1));
//				break;
//			}
//			int h1 = high1(x);
//			l = dp[cur][h1];
//			//cout << "l : " << l << "\n";
//			//cout << bitset<10>(x) << "**\n";
//			//cout << "h1 : " << h1 << "\n";
//			if (l == 0) {
//				ans.emplace_back(n);
//				break;
//			}
//
//	
//			//cout << "ll : " << ll << "\n";
//			/*if (l <= ll) {
//				ans.emplace_back(n - ll);
//				break;
//			}
//			ll = max({ ll, jp[l][h1],lb[l] });*/
//			//cout << jp[l][h1] << "\n";
//			//cout << "ll : " << ll << "\n";
//			//cout << bitset<10>(bxor[l + 1] ^ bxor[cur]) << "haha\n";
//			x ^= bxor[l + 1] ^ bxor[cur];
//			//cout << bitset<10>(x)<<"\n";
//			if (x >= w[l]) {
//				//cout << w[l] << "wl\n";
//				x ^= w[l];
//			}
//			else {
//				ans.emplace_back(n - l);
//				break;
//			}
//			cur = l;
//			//cout << bitset<10>(x) << "\n";
//		}
//		//cout << "\n_______________\n";
//	}
//	for (auto v : ans)cout << v << " ";
//	cout << "\n";
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
//终于tm调出来了！！！！！！！
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int high1(int x) {
//	int ans = 0;
//	while (x != 0) {
//		x >>= 1;
//		ans++;
//	}
//	return ans;
//}
//void solve() {
//	int n, q;
//	cin >> n >> q;
//	vector<int>w(n + 2);
//	for (int i = 1; i <= n; i++) {
//		cin >> w[i];
//	}
//	vector<int>bxor(n + 2);
//	for (int i = n; i >= 1; i--) {
//		bxor[i] = w[i] ^ bxor[i + 1];
//	}
//	vector<int>tmp(33);
//	vector<vector<int>>dp(n + 2, vector<int>(33));//当前i位置之前第一个最高位>=j的数的位置
//	for (int i = 1; i <= n + 1; i++) {
//		for (int j = 30; j >= 0; j--) {
//			dp[i][j + 1] = max(tmp[j + 1], dp[i][j + 2]);
//		}
//		for (int j = 0; j <= 30; j++) {
//			if ((w[i] >> j) & 1) {
//				tmp[j + 1] = i;
//			}
//		}
//	}
//	vector<int>ans;
//	for (int i = 1, x; i <= q; i++) {
//		cin >> x;
//		int l, cur = n + 1;
//		while (true) {
//			if (x == 0) {
//				ans.emplace_back(n - (cur - 1));
//				break;
//			}
//			int h1 = high1(x);
//			l = dp[cur][h1];
//			if (l == 0) {
//				ans.emplace_back(n);
//				break;
//			}
//			x ^= bxor[l + 1] ^ bxor[cur];
//			if (x >= w[l]) {
//				x ^= w[l];
//			}
//			else {
//				ans.emplace_back(n - l);
//				break;
//			}
//			cur = l;
//		}
//	}
//	for (auto v : ans)cout << v << " ";
//	cout << "\n";
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
//using namespace std;
//int s, k, d;
//vector<bool>pos;
//vector<bool>posn;
//void bfs() {
//	queue<int>q;
//	for (int i = 0; i <= s; i++) {
//		if (pos[i]) {
//			q.push(i);
//		}
//	}
//	while (!q.empty()) {
//		int x = q.front();
//		q.pop();
//		int y = x + d * k;
//		if (y >= 0 && y<=s&&!posn[y]) {
//			posn[y] = 1;
//			q.push(y);
//		}
//	}
//	swap(pos, posn);
//}
//void solve() {
//	d = 1;
//	cin >> s >> k;
//	if (s >= k * k) {
//		if (s % k == 0) {
//			cout << k << endl;
//			return;
//		}
//		else {
//			cout << max(1,k - 2) << endl;
//			return;
//		}
//	}
//	pos.assign(s + 1,false);
//	posn.assign(s + 1,false);
//	pos[0] = true;
//	int down = max(1, (int)sqrt(k) - 3);
//	for (int i = k; i>=down; i--) {
//		bfs();
//		if (pos[s]) {
//			cout << i << "\n";
//			return;
//		}
//		/*if (s < 100) {
//			for (int i = 0; i <= s; i++) {
//				cout << pos[i] << " ";
//			}cout << "**\n";
//		}*/
//		for (int i = 0; i <= s; i++) {
//			posn[i] = 0;
//		}
//		d *= -1;
//		k = max(1, k - 1);
//	}
//	cout << 1 << "\n";
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
//int main() {
//	int n;
//	cin >> n;
//	if (n == 4) {
//		cout << 4 << endl;
//		cout << 1 << " " << 4 << endl;
//		cout << 3 << " " << 1 << endl;
//		cout << 2 << " " << 1 << endl;
//		cout << 3 << " " << 1 << endl;
//		return 0;
//	}
//	vector<pair<int, int>>op;
//	for (int i = 1; i <= 358; i++) {
//		for (int j = min(250000,i * 700); j >= min(250001,(i - 1) * 700+1); j--) {
//			op.push_back({ j,i * 700 + 1 - j });
//		}
//	}
//	cout << op.size() << endl;
//	for (auto v : op) {
//		cout << v.first << " " << v.second << endl;
//	}
//}
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	for (int i = 1; i <= 250000; i++) {
		if (2*250000 / i * 1000 + (1 + i) * i / 2*i <= 1000000)cout << i << endl;
	}
}