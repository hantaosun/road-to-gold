//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	int zero = 0, one = 0,sum=0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		if (a[i] == 0)zero++;
//		else if (a[i] == 1)one++;
//		else sum += a[i];
//	}
//	int ans = 0;
//	if (zero > one) {
//		ans += 2 * one + zero - one;
//	}
//	else if (one >= zero) {
//		ans += zero*2 + one-zero;
//	}
//	cout << ans + sum << endl;
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
//	int n, s;
//	cin >> n >> s;
//	vector<int>a(n + 1);
//	int sum = 0;
//	int one=0, zero=0, two = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		sum += a[i];
//		if (a[i] == 0)zero++;
//		if (a[i] == 1)one++;
//		if (a[i] == 2)two++;
//	}
//	if (sum > s) {
//		for (int i = 1; i <= n; i++) {
//			cout << a[i] << " ";
//		}cout << endl;
//		return;
//	}
//	if (sum == s) {
//		cout << -1 << endl;
//		return;
//	}
//	int need = s - sum;
//	if (need == 1) {
//		for (int i = 1; i <= zero; i++) {
//			cout << 0 << " ";
//		}
//		for (int i = 1; i <= two; i++) {
//			cout << 2 << " ";
//		}
//		for (int i = 1; i <= one; i++) {
//			cout << 1 << " ";
//		}
//		cout << endl;
//	}
//	else {
//		cout << -1<<endl;
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
//const int N = 3005;
////int fa[N];
////int head[N];
////int nex[N<<1];
////int to[N<<1];
////int id[N << 1];
////void addEdge(int a,int b) {
////
////}
//void solve() {
//	int n;
//	cin >> n;
//	vector<array<int, 3>>e;
//	for (int i = 1, a, b; i <= n; i++) {
//		cin >> a >> b;
//		e.push_back({ a, b, i });
//	}
//	sort(e.begin(), e.end(), [&](auto a,auto b) {
//		if (a[0] == b[0])return a[1] > b[1];
//		return a[0] < b[0];
//		});
//	vector<int>ans;
//	//int cover = 0;
//	
//	for (int i = 0; i < e.size();) {
//		ans.push_back(e[i][2]);
//		int l=e[i][0],r = e[i][1];
//		i++;
//		while (i<e.size()&&e[i][0] < r) {
//			if (e[i][1] > r) {
//				ans.push_back(e[i][2]);
//				r = e[i][1];
//			}
//			i++;
//		}
//		//cover += r - l;
//	}
//	cout << ans.size()<<endl;
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i]<<" " << endl;
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}



//统计逆序对 考虑一个元素时仅考虑比他大的数,比他小的数在统计该小数时会统计两者的逆序对,
//由于逆序对是相互关系,所以每个元素考虑单向即可,正如统计数组中两两元素乘积和一样,遍历是i=1-n j=1-i 
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//int a[5005];
//int lowbit(int x) {
//	return x & (-x);
//}
//void add(int i, int x) {
//	while (i <= n) {
//		a[i] += x;
//		i += lowbit(i);
//	}
//}
//int sum(int i) {
//	int ans = 0;
//	while (i != 0) {
//		ans += a[i];
//		i -= lowbit(i);
//	}
//	return ans;
//}
//int range(int l, int r) {
//	return sum(r) - sum(l - 1);
//}
//void solve() {
//	cin >> n;
//	vector<int>p(n + 1);
//	vector<int>lbig(n + 1), rbig(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//	}
//	memset(a, 0, (n + 5) * sizeof(int));
//	for (int i = 1; i <= n; i++) {
//		lbig[i] = range(p[i]+1,n);
//		add(p[i], 1);
//	}
//	memset(a, 0, (n + 5) * sizeof(int));
//	for (int i = n; i >= 1; i--) {
//		rbig[i] = range(p[i] + 1, n );
//		add(p[i], 1);
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		ans += min(lbig[i], rbig[i]);
//	}
//	cout << ans<<endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}