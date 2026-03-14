//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e6 + 5;
//const int mod = 998244353;
//int n;
//int fac[N];
//int a[N];
//int lowbit(int x) {
//	return x & (-x);
//}
//void add(int i) {
//	while (i <= n) {
//		a[i]++;
//		i += lowbit(i);
//	}
//}
//int sum(int i) {
//	int ans = 0;
//	while (i != 0) {
//		ans+=a[i];
//		i -= lowbit(i);
//	}
//	return ans;
//}
//void prepare(){
//	fac[0] = 1;
//	for (int i = 1; i <= n; i++) {
//		fac[i] = fac[i - 1] * i%mod;
//	}
//}
//signed main() {
//	cin >> n;
//	prepare();
//	vector<int>p(n + 1);
//	vector<int>rsma(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//	}
//	for (int i = n; i >= 1; i--) {
//		rsma[i] = sum(p[i] - 1);
//		add(p[i]);
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		//cout << rsma[i] << '\n';
//		ans = (ans + rsma[i] * fac[n - i] % mod) % mod;
//	}
//	cout << ans+1 << '\n';
//}


//逆康托展开
//#include<bits/stdc++.h>
//#define int long long
//const int N = 1e5 + 5;
//using namespace std;
//int sum[N << 2];
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = 1;
//		return;
//	}
//	int mid = l + r >> 1;
//	build(l, mid, i << 1);
//	build(mid+1, r, i << 1|1);
//	up(i);
//}
//void add(int x, int v, int l, int r, int i) {
//	if (l == r && r == x) {
//		sum[i] += v;
//		return;
//	}
//	int mid = l + r >> 1;
//	if (x <= mid) {
//		add(x, v, l, mid, i << 1);
//	}
//	else {
//		add(x, v, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//}
//int query(int jl,int jr,int l,int r,int i) {
//	if (jl <= l && jr >= r) {
//		return sum[i];
//	}
//	int mid = l + r >> 1;
//	int ans = 0;
//	if (jl <= mid) {
//		ans+=query(jl, jr, l, mid, i << 1);
//	}
//	if (jr > mid) {
//		ans += query(jl, jr, mid + 1, r, i << 1 | 1);
//	}
//	return ans;
//}
//int getAndDelete(int x,int l,int r,int i) {
//	int ans;
//	if (l == r) {
//		sum[i]--;
//		ans = l;
//	}
//	else {
//		int mid = l + r >> 1;
//		if (sum[i << 1] >= x) {
//			ans = getAndDelete(x ,l, mid, i<<1);
//		}
//		else {
//			ans = getAndDelete(x - sum[i << 1], mid + 1, r, i << 1 | 1);
//		}
//		up(i);
//	}
//	return ans;
//}
//signed main() {
//	int n,m;
//	cin >> n>>m;
//	vector<int>p(n + 1);
//	vector<int>a(n + 1);
//
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//	}
//	build(1, n, 1);//sum[i]的叶子节点代表当前数字的词频一开始build时全为1从左往右逐渐减
//	for (int i = 1,x; i <= n; i++) {
//		x = p[i];
//		if (x == 1) {
//			p[i] = 0;
//		}
//		else {
//			p[i] = query(1, x - 1, 1, n, 1);
//		}
//		add(x, -1, 1, n, 1);
//	}
//	p[n] += m;
//	for (int i = n; i >= 1; i--) {
//		p[i - 1] += p[i] / (n - i + 1);
//		p[i] %= (n - i + 1);
//	}
//	build(1, n, 1);
//	for (int i = 1; i <= n; i++) {
//		p[i] = getAndDelete(p[i]+1, 1, n, 1);
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << p[i]<<" ";
//	}cout << '\n';
//}



//约瑟夫环
//加强问题:每次报的数字会变,存在数组中
// 解决方案递推时参数从数组中拿即可
//oldid=(newid+k-1)%n+1;//n为老环大小
//#include<bits/stdc++.h>
//using namespace std;
//int solve(int n,int k) {
//	int ans = 1;//最后一次死人后环中剩唯一节点，该节点编号必为1
//	for (int c = 2; c <= n; c++) {
//		ans = (ans + k - 1) % c + 1;//逐层往上退回原初存活编号
//	}
//	return ans;
//}
//int main() {
//	int n, k;
//	cin >> n >> k;
//	cout << solve(n, k) << '\n';
//}


//完美洗牌
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 23;
//int start[N];
//int split[N];
//int siz;
//void build(int n) {
//	siz = 0;
//	for (int s = 1, p = 2; p <= n; s *= 3, p = s * 3 - 1) {
//		start[++siz] = s;
//		split[siz] = p;
//	}
//}
//int to(int x,int l,int r) {
//	if (x <= (l + r >> 1)) {
//		return x + (x - l + 1);
//	}
//	else {
//		return x - (r - x + 1);
//	}
//}
//void reverse(vector<int>& arr,int l,int r) {
//	while (l < r) {
//		swap(arr[l], arr[r]);
//		l++, r--;
//	}
//}
//void rotate(vector<int>& arr, int l, int m, int r) {
//	reverse(l, r);
//	reverse(l, m);
//	reverse(m+1, r);
//}
//void circle(vector<int>& arr,int l,int r,int i) {
//	for (int j = 1, init, cur, nex, curv, nexv; j <= i; j++) {
//		init = cur = l + start[j] -1;
//		nex = to(cur, l, r);
//		curv = arr[cur];
//		while (nex != init) {
//			nexv = arr[nex];
//			arr[nex] = curv;
//			curv = nexv;
//			cur = nex;
//			nex = to(cur, l, r);
//		}
//		arr[init] = curv;
//	}
//}
//void shuffle(vector<int>&arr,int l,int r) {
//	int n = r - l + 1;
//	build(n);
//	for (int i = siz, m; n > 0;) {
//		if (split[i] <= n) {
//			m = (l + r) >> 1;
//			rotate(arr, l + split[i] / 2, m, m + split[i] / 2);//让要交换的部分相邻
//			circle(arr, l, l + split[i] - 1, i);//i表示有几个起点,开启下标循环怼
//			l += split[i];
//			n -= split[i];
//		}
//		else {
//			i--;
//		}
//	}
//}