//国旗计划
//#include<bits/stdc++.h>
//using namespace std;
//int pwd;
//int log2(int x) {
//	int t = 0;
//	while ((1 << t) <= (x >> 1)) {
//		t++;
//	}
//	return t;
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>a;
//	for (int i = 0, u, v; i < n; i++) {
//		cin >> u >> v;
//		if (u > v) {
//			v += m;
//		}
//		a.push_back({ u, v,i });
//	}
//	sort(a.begin(), a.end(), [](vector<int>& a, vector<int>& b) {
//		return a[0] < b[0];
//		});
//	int t = a.size();
//	for (int i = 0; i < t; i++) {
//		a.push_back({ a[i][0] + m,a[i][1] + m ,i });
//	}
//	pwd = log2(n);
//	int e = n << 1;
//	vector<vector<int>>st(n*2+5, vector<int>(pwd+5,0));
//	for (int i = 0, j=0; i < e; i++) {
//		while (j + 1 < e && a[j + 1][0] <= a[i][1]) {
//			j++;
//		}
//		st[i][0] = j;
//		//cout << "("<<a[i][0] << "," << a[i][1] << ") " << i << " " << st[i][1] << endl;
//	}
//	for (int p = 1; p <= pwd; p++) {
//		for (int i = 0; i < e; i++) {
//			st[i][p] = st[st[i][p - 1]][p - 1];
//			//cout << st[i][p] << " ";
//		}
//		//cout << endl;
//	}
//	vector<int>ans(n);
//	for (int i = 0; i < t; i++) {
//		int aim = a[i][0]+m;
//		int cur = i, next;
//		ans[a[i][2]] = 1;
//		for (int p = pwd; p >= 0; p--) {
//			next = st[cur][p];
//			//cout <<p<<" "<<a[next][1] << " " << aim  << endl;
//			if (next != 0 && a[next][1] < aim) {
//				ans[a[i][2]] += 1 << p;
//				cur = next;
//			}
//			//cout << i << " " << ans[a[i][2]] << endl;
//		}
//		ans[a[i][2]] += 1;
//	}
//	for (int i = 0; i < t; i++) {
//		cout << ans[i] << " ";
//	}
//	cout << endl;
//}


////Balanced Lineup G
//#include<bits/stdc++.h>
//using namespace std;
//int ox[50010];
//int stmax[500010][20];
//int stmin[500010][20];
//int log2(int x) {
//	int ans = 0;
//	while ((1 << ans) <= (x >> 1)) {
//		ans++;
//	}
//	return ans;
//}
//int main() {
//	int n,q;
//	cin >> n>>q;
//	for (int i = 1; i <= n; i++) {
//		cin >> ox[i];
//		stmax[i][0] = ox[i];
//		stmin[i][0] = ox[i];
//	}
//	for (int q = 1; q <= log2(n); q++) {
//		for (int i = 1; i+(1<<q)-1 <= n; i++) {
//			stmax[i][q] = max(stmax[i][q - 1], stmax[i + (1 << (q - 1))][q - 1]);
//			//cout << i <<" "<<q<< " " << stmin[i + (1 << (q - 1))][q - 1] << endl;
//			stmin[i][q] = min(stmin[i][q - 1], stmin[i + (1 << (q - 1))][q - 1]);
//		}
//	}
//	
//	//for (int q = 0; q <= log2(n); q++) {
//	//	for (int i = 1; i <= n; i++) {
//	//		cout << stmax[i][q]<<" ";
//	//	}
//	//	cout << endl;
//	//}cout << endl;
//	//for (int q = 0; q <= log2(n); q++) {
//	//	for (int i = 1; i <= n; i++) {
//	//		cout << stmin[i][q]<<" ";
//	//	}
//	//	cout << endl;
//	//}
//	for (int i = 1,l,r; i <= q; i++) {
//		cin >> l >> r;
//		int step = log2(r - l + 1);
//		cout << max(stmax[l][step], stmax[r - (1 << step) + 1][step])- min(stmin[l][step], stmin[r - (1 << step) + 1][step]) << endl;
//	}
//}


//gcd区间
//#include<bits/stdc++.h>
//using namespace std;
//int a[1005];
//int stgcd[1005][10];
//int log2(int x) {
//	int ans = 0;
//	while ((1 << ans) <= (x >> 1)) {
//		ans++;
//	}
//	return ans;
//}
//int gcd(int a, int b) {
//	if (a < b) {
//		a = a ^ b;
//		b = b ^ a;
//		a = a ^ b;
//	}
//	return b == 0 ? a : gcd(b, a%b);
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		stgcd[i][0] = a[i];
//	}
//	for (int p = 1; p <= log2(n); p++) {
//		for (int i = 1; i +(1<<p)-1<= n; i++) {
//			stgcd[i][p] = gcd(stgcd[i][p - 1], stgcd[i + (1 << (p - 1))][p - 1]);//注意转移
//		}
//	}
//	for (int i = 1,l,r; i <= m; i++) {
//		cin >> l >> r;
//		int step = log2(r - l + 1);
//		cout << gcd(stgcd[l][step], stgcd[r - (1 << step) + 1][step]) << endl;
//	}
//}


//Frequent values
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1e5 + 10;
//int a[MAXN];
//int st[MAXN][20];
//int bucket[MAXN];
//int lef[MAXN];
//int rig[MAXN];
//int log2(int x) {
//	int ans = 0;
//	while ((1 << ans) <= (x >> 1)) {
//		ans++;
//	}
//	return ans;
//}
//int main() {
//	int n, q;
//	cin >> n >> q;
//	int b = 1;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	lef[1] = 1;
//	for (int i = 1,pre=a[1]; i <= n; i++) {
//		if (a[i] != a[i-1]) { 
//			rig[b] = i - 1;
//			st[b][0] = rig[b] - lef[b]+1;
//			b++;
//			lef[b] = i;
//		}
//		bucket[i] = b;
//	}
//	rig[b] = n;
//	st[b][0] = rig[b] - lef[b] + 1;
//	for (int p = 1; p <= log2(b); p++) {
//		for (int i = 1; i+(1<<p)-1 <= b; i++) {
//			st[i][p] = max(st[i][p - 1], st[i + (1 << p - 1)][p - 1]);
//		}
//	}
//	//for (int p = 1; p <= log2(b); p++) {
//	//	for (int i = 1; i <= b; i++) {
//	//		cout << st[i][p] << " ";
//	//	}
//	//	cout << endl;
//	//}
//	for (int i = 1,l,r; i <= q; i++) {
//		if (l > r) {
//			l = l ^ r;
//			r = l ^ r;
//			l = l ^ r;
//		}
//		cin >> l;
//		if (l == 0)break;
//		cin >> r;
//		if (bucket[l] == bucket[r]) {
//			cout << r - l + 1<<endl;
//		}
//		else {
//			int lb = bucket[l], rb = bucket[r];
//			int lm = rig[lb] - l + 1;
//			int rm = r - lef[rb] + 1;
//			int step = log2(rb - 1 - lb - 1 + 1);
//			if (step <= 0) {
//				cout << max(lm, rm) << endl;
//			}
//			else {
//				int mid = max(st[lb + 1][step], st[rb - 1 - (1 << step) + 1][step]);
//				cout << max(mid, max(lm, rm)) << endl;
//			}
//		}
//	}
//}