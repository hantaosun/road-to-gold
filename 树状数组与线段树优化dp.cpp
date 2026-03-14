//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//int n;
//ll help[100005];
//int merge(vector<ll>& nums, int l, int r, int m, int low, int high) {
//    int ans = 0;
//    for (ll i = m + 1, lw = l, rw = l, lo, hi; i <= r; i++) {
//        hi = nums[i] - low;
//        lo = nums[i] - high;
//        while (rw <= m && nums[rw] <= hi)rw++;
//        while (lw <= m && nums[lw] < lo)lw++;
//        ans += rw - lw;
//    }
//    int a = l, b = m + 1, c = 0;
//    while (a <= m && b <= r) {
//        if (nums[a] < nums[b]) {
//            help[c++] = nums[a++];
//        }
//        else {
//            help[c++] = nums[b++];
//        }
//    }
//    while (a <= m) {
//        help[c++] = nums[a++];
//    }
//    while (b <= r) {
//        help[c++] = nums[b++];
//    }
//    for (int i = 0; i < c; i++) {
//        nums[i + l] = help[i];
//    }
//    return ans;
//}
//int f(vector<ll>& nums, int l, int r, int low, int high) {
//    if (l == r) {
//        return nums[l] <= high && nums[l] >= low;
//    }
//    int mid = l + r >> 1;
//    return f(nums, l, mid, low, high) + f(nums, mid + 1, r, low, high) + merge(nums, l, r, mid, low, high);
//}
//class Solution {
//public:
//    int countRangeSum(vector<int>& nums, int lower, int upper) {
//        n = nums.size();
//        nums.insert(nums.begin(), 0);
//        vector<ll>presum(n + 1);
//        for (int i = 1; i <= n; i++) {
//            presum[i] = presum[i - 1] + nums[i];
//        }
//        return f(presum, 1, n, lower, upper);
//    }
//};



//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int N = 1e5 + 5;
//ll tree[N];
//int len;
//int lowbit(int i) {
//    return i & (-i);
//}
//void add(int i, int v) {
//    while (i <= len) {
//        tree[i] += v;
//        i += lowbit(i);
//    }
//}
//int query(int i) {
//    int ans = 0;
//    while (i > 0) {
//        ans += tree[i];
//        i -= lowbit(i);
//    }
//    return ans;
//}
//int range(int l, int r) {
//    return query(r) - query(l - 1);
//}
//class Solution {
//public:
//    int countRangeSum(vector<int>& nums, int lower, int upper) {
//        memset(tree, 0, sizeof(tree));
//        int n = nums.size();
//        nums.insert(nums.begin(), 0);
//        vector<ll>vsort;
//        vector<ll>sum(n + 1);
//        for (int i = 1; i <= n; i++) {
//            sum[i] = sum[i - 1] + nums[i];
//        }
//        for (int i = 1; i <= n; i++) {
//            vsort.emplace_back(sum[i]);
//        }
//        vsort.emplace_back(0);
//        sort(vsort.begin(), vsort.end());
//        vsort.erase(unique(vsort.begin(), vsort.end()), vsort.end());
//        len = vsort.size();
//        vsort.insert(vsort.begin(), 0);
//        int ans = 0;
//        // for(int i=1;i<vsort.size();i++){
//        //     cout<<vsort[i]<<' ';
//        // }cout<<'\n';
//        add(lower_bound(vsort.begin() + 1, vsort.end(), 0) - vsort.begin(), 1);
//        for (int i = 1; i <= n; i++) {
//            int cur = lower_bound(vsort.begin() + 1, vsort.end(), sum[i]) - vsort.begin();
//
//            ll lo = sum[i] - upper;
//            ll hi = sum[i] - lower;
//            int l = lower_bound(vsort.begin() + 1, vsort.end(), lo) - vsort.begin();
//            int r = upper_bound(vsort.begin() + 1, vsort.end(), hi) - vsort.begin();
//            // cout<<"---------\n";
//            // cout<<sum[i]<<" "<<lo<<" "<<hi<<'\n';
//            // cout<<cur<<" "<<l<<" "<<r-1<<'\n';
//            // cout<<range(l,r-1)<<'\n';
//            ans += range(l, r - 1);
//            add(cur, 1);
//        }
//        return ans;
//    }
//};


//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int N = 1e5 + 5;
//int len;
//ll tree[N];
//int lowbit(int i) {
//    return i & (-i);
//}
//void upd(int i, ll v) {
//    while (i <= len) {
//        tree[i] = max(v, tree[i]);
//        i += lowbit(i);
//    }
//}
//ll query(int i) {
//    ll ans = LLONG_MIN;
//    while (i > 0) {
//        ans = max(ans, tree[i]);
//        i -= lowbit(i);
//    }
//    return ans;
//}
//class Solution {
//public:
//    long long maxBalancedSubsequenceSum(vector<int>& nums) {
//        for (int i = 0; i < N; i++) {
//            tree[i] = LLONG_MIN;
//        }
//        int n = nums.size();
//        nums.insert(nums.begin(), 0);
//        vector<ll>a(n + 1);
//        for (int i = 1; i <= n; i++) {
//            a[i] = nums[i] - i;
//        }
//        vector<ll>vsort;
//        for (int i = 1; i <= n; i++) {
//            vsort.emplace_back(a[i]);
//        }
//        sort(vsort.begin(), vsort.end());
//        vsort.erase(unique(vsort.begin(), vsort.end()), vsort.end());
//        len = vsort.size();
//        vsort.insert(vsort.begin(), 0);
//        //由于只需要前缀最大值而不是任意区间最大值,可以使用树状数组维护
//        for (int i = 1; i <= n; i++) {
//            int cur = lower_bound(vsort.begin() + 1, vsort.end(), a[i]) - vsort.begin();
//            int to = upper_bound(vsort.begin() + 1, vsort.end(), a[i]) - vsort.begin() - 1;
//            upd(cur, max(0ll, query(to)) + nums[i]);
//        }
//        return query(len);
//    }
//};


//方伯伯的玉米田
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 5505;
//const int K = 505;
//int dp[N+1][K+1];//前i株玉米最多进行j次操作能得到的最长不下降子序列长度
//int n, k;
//int lowbit(int i) {
//	return i & (-i);
//}
//void upd(int x, int y, int v) {
//	for (int i = x; i <=N; i += lowbit(i)) {
//		for (int j = y; j <=k+1; j += lowbit(j)) {
//			dp[i][j] = max(dp[i][j], v);
//		}
//	}
//}
//int query(int x, int y) {
//	int ans = INT_MIN;
//	for (int i = x; i > 0; i -= lowbit(i)) {
//		for (int j = y; j > 0; j -= lowbit(j)) {
//			ans = max(ans, dp[i][j]);
//		}
//	}
//	return ans;
//}
//int main() {
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = k; j >= 0; j--) {
//			int v = a[i] + j;
//			int d = query(v, j + 1)+1;
//			upd(v, j + 1, d);
//		}
//	}
//	cout << query(N, k+1) << '\n';
//}


//线段树优化
//#include<bits/stdc++.h>
//using namespace std;
//int mx[120];
//void up(int i) {
//    mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
//}
//int query(int jl, int jr, int l, int r, int i) {
//    if (jl <= l && jr >= r) {
//        return mx[i];
//    }
//    int mid = l + r >> 1;
//    int ans = INT_MIN;
//    if (jl <= mid) {
//        ans = max(ans, query(jl, jr, l, mid, i << 1));
//    }
//    if (jr > mid) {
//        ans = max(ans, query(jl, jr, mid + 1, r, i << 1 | 1));
//    }
//    return ans;
//}
//void update(int x, int v, int l, int r, int i) {
//    if (l == r) {
//        mx[i] = max(mx[i], v);
//        return;
//    }
//    int mid = l + r >> 1;
//    if (x <= mid) {
//        update(x, v, l, mid, i << 1);
//    }
//    if (x > mid) {
//        update(x, v, mid + 1, r, i << 1 | 1);
//    }
//    up(i);
//}
//class Solution {
//public:
//    int longestIdealString(string s, int k) {
//        memset(mx, 0, sizeof(mx));
//        for (int i = 0; i < s.size(); i++) {
//            int cur = s[i] - 'a' + 1;
//            int l = max(1, cur - k), r = min(26, cur + k);
//            update(cur, query(l, r, 1, 26, 1) + 1, 1, 26, 1);
//        }
//        int ans = INT_MIN;
//        return query(1, 26, 1, 26, 1);
//    }
//};


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 35000 + 5;
//int mx[N << 2];
//int lzt[N << 2];
//void lazy(int i, int v) {
//	mx[i] += v;
//	lzt[i] += v;
//}
//void up(int i) {
//	mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
//}
//void down(int i) {
//	if (lzt[i] != 0) {
//		lazy(i << 1, lzt[i]);
//		lazy(i << 1|1, lzt[i]);
//		lzt[i] = 0;
//	}
//}
//void add(int jl, int jr,int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		lazy(i, v);
//		return;
//	}
//	down(i);
//	int mid = l + r >> 1;
//	if (jl <= mid) {
//		add(jl, jr, v, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		add(jl, jr, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//int query(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return mx[i];
//	}
//	int mid = l + r >> 1;
//	down(i);
//	int ans = INT_MIN;
//	if (jl <= mid) {
//		ans = max(ans, query(jl, jr, l, mid, i << 1));
//	}
//	if (jr > mid) {
//		ans = max(ans, query(jl, jr, mid + 1, r, i << 1 | 1));
//	}
//	return ans;
//}
//void build(int l, int r, int i, vector<int>& a) {
//	if (l == r) {
//		mx[i] = a[l];
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1,a);
//		build(mid + 1, r, i << 1 | 1, a);
//		up(i);
//	}
//	lzt[i] = 0;
//}
//vector<vector<int>>dp;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n + 1,0);
//	vector<int>last(n + 1,0);//当前位置数字上一次出现位置
//	vector<int>num(n + 1,0);//辅助数组
//	dp.assign(k + 1, vector<int>(n+1,0));
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		last[i] = num[a[i]];
//		num[a[i]] = i;
//	}
//	for (int j = 1; j <= k; j++) {
//		build(0, n, 1, dp[j - 1]);
//		for (int i = 1; i <= n; i++) {
//			add(last[i], i-1, 1, 0, n, 1);
//			if (i < j) {
//				dp[j][i] = dp[j-1][i];
//			}
//			else {
//				dp[j][i] = query(0, i-1, 0, n, 1);
//			}
//		}
//	}
//	cout << dp[k][n] << '\n';
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2e4 + 10;
//int mn[N << 2];
//int lzt[N << 2];
//void lazy(int i, int v) {
//	mn[i] += v;
//	lzt[i] += v;
//}
//void up(int i) {
//	mn[i] = min(mn[i << 1], mn[i << 1 | 1]);
//}
//void down(int i) {
//	if (lzt[i] != 0) {
//		lazy(i << 1, lzt[i]);
//		lazy(i << 1|1, lzt[i]);
//		lzt[i] = 0;
//	}
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
//int query(int jl, int jr, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		return mn[i];
//	}
//	int ans = LLONG_MAX;
//	down(i);
//	int mid = l + r >> 1;
//	if (jl <= mid) {
//		ans = min(ans, query(jl, jr, l, mid, i << 1));
//	}
//	if (jr > mid) {
//		ans = min(ans, query(jl, jr, mid + 1, r, i << 1 | 1));
//	}
//	return ans;
//}
//void build(int l, int r, int i, vector<int>& a) {
//	if (l == r) {
//		mn[i] = a[l];
//	}
//	else {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1, a);
//		build(mid+1, r, i << 1|1, a);
//		up(i);
//	}
//	lzt[i] = 0;
//}
//signed main() {
//	int n, k;
//	cin >> n >> k;
//	vector<int>pos(n + 2);
//	vector<int>fix(n + 2);
//	vector<int>s(n + 2);
//	vector<int>fine(n + 2);
//	for (int i = 2; i <= n; i++) {
//		cin >> pos[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> fix[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> s[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> fine[i];
//	}
//	pos[1] = 0;
//	pos[++n] = LLONG_MAX;
//	fix[n] = s[n] = fine[n] = 0;
//	vector<vector<int>>dp(k + 2, vector<int>(n + 1, 0));
//	vector<int>lft(n + 1);
//	vector<int>rht(n + 1);
//	vector<vector<int>>warn(n + 1);
//	for (int i = 1; i <= n; i++) {
//		int l = pos[i] - s[i];
//		int r = pos[i] + s[i];
//		lft[i] = lower_bound(pos.begin() + 1, pos.end(), l) - pos.begin();
//		rht[i] = upper_bound(pos.begin() + 1, pos.end(), r) - pos.begin() - 1;
//		warn[rht[i]].push_back(i);
//	}
//
//	for (int i = 1, w = 0; i <= n; i++) {
//		dp[1][i] = w + fix[i];
//		for (int v : warn[i]) {
//			w += fine[v];
//		}
//	}
//	for (int i = 2; i <= k + 1; i++) {
//		build(1, n, 1, dp[i - 1]);
//		for (int j = 1; j <= n; j++) {
//			dp[i][j] = dp[i - 1][j];
//			if (j >= i)dp[i][j] = min(dp[i][j], fix[j] + query(1, j - 1, 1, n, 1));
//			for (int v : warn[j]) {
//				if (lft[v] > 1)
//					add(1, lft[v] - 1, fine[v], 1, n, 1);
//			}
//		}
//	}
//	cout << dp[k + 1][n] << '\n';
//}