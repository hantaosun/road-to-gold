//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	int ans=0;
//	for (int i = n,j=1;j<=n&&i>= 1; i--,j++) {
//		ans += abs(i - j);
//	}
//	cout << ans / 2 + 1 << '\n';
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
//int popcount(int x) {
//	int ans = 0;
//	while (x != 0) {
//		if (x & 1) {
//			ans++;
//		}
//		x >>= 1;
//	}
//	return ans;
//}
//void solve() {
//	int n, x;
//	cin >> n >> x;
//	if (x == 0 && n == 1) {
//		cout << -1 << '\n';
//		return;
//	}
//	int ones = popcount(x);
//	if (ones >= n) {
//		cout << x << '\n';
//	}
//	else {
//		if ((n - ones) & 1) {
//			if ((x & 1) == 0&&x!=0) {
//				cout << x + n - ones + 1 << '\n';
//				return;
//			}
//			if (ones > 1) {
//				cout << x + n - ones + 1 << '\n';
//			}
//			else {
//				cout << x + n - ones + 3 << "\n";
//			}
//		}
//		else {
//			cout << x + n - ones << '\n';
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
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	int len = 1;
//	for (int i = 1; i <= n; i++) {
//		if (a[i] != a[len]) {
//			a[++len] = a[i];
//		}
//	}
//	vector<int>idx(len+1);
//	iota(idx.begin(), idx.end(), 0);
//	sort(idx.begin()+1, idx.end(), [&](int x,int y) {
//		if (a[x] == a[y])return x < y;
//		return a[x] > a[y];
//		});
//	unordered_set<int>s;
//	for (int i = 1; i <= len; i++) {
//		if (!s.count(idx[i] - 1) && !s.count(idx[i] + 1)) {
//			ans++;
//		}
//		s.insert(idx[i]);
//	}
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
//int ask(int i) {
//	cout << "? " << i+1 << endl;
//	int t;
//	cin >> t;
//	return t;
//}
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(k);
//	vector<int>b(k);
//	for (int i = 0; i < k; i++) {
//		a[i] = ask(i);
//	}
//	for (int j = n-k; j < n; j++) {
//		b[j%k] = ask(j);
//	}
//	vector<int>vec;
//	int tot = 0;
//	for (int i = 0; i < k; i++) {
//		if (a[i] != b[i]) {
//			vec.push_back(i);
//			tot += (n - 2 * k) / k;//除去首尾两个k中间的每个k区间必然包含一个该数
//			if (i < (n - 2 * k) % k) {//中间的部分可能不完整,会剩(n-2*k)%k个数,如果该数在k周期中的位置在前(n-2*k)%k个则要额外计数
//				tot++;
//			}
//		}
//	}
//	int lo = -1, hi = tot;
//	//get函数用于将需要二分的元素中的元素的第i个转化到其在数组中实际位置
//	auto get = [&](int x)->int {//0-tot-1表示实际真正需要二分的元素
//		if (x == -1) {
//			return k - 1;
//		}
//		if (x == tot) {
//			return n - k;
//		}
//		return k + (x / vec.size()) * k + vec[x % vec.size()];
//		//k是初始位置,基于k偏移 x/vec.size(),表示在第几个周期里,vec[x%vec.size()]表示在周期里的哪个位置,注意vec里存的是位置
//	};
//	while (hi - lo > 1) {
//		int x = (lo + hi) / 2;
//		int i = get(x);
//		if (ask(i) == a[i % k]) {
//			lo = x;
//		}
//		else {
//			hi = x;
//		}
//	}
//	lo = get(lo);
//	hi = get(hi);
//	if (hi - lo > 1) {
//		cout << "! " << -1 << endl;
//	}
//	else {
//		cout << "! " << hi << " " << n - hi << endl;
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}