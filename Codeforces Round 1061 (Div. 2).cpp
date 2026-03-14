//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	int ans = 0;
//	while (n != 0) {
//		if (n <= 2) {
//			n = 0;
//		}
//		else {
//			int m = n / 3;
//			ans += m;
//			if (n % 3 ==1) {
//				n = n / 3+1;
//			}
//			else if (n % 3 == 2) {
//				n = n / 3 + 2;
//			}
//			else {
//				n = n / 3;
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

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n,q;
//	cin >> n>>q;
//	string s;
//	cin >> s;
//	bool allA = true;
//	for (int i = 0; i < n; i++) {
//		if (s[i] == 'B') {
//			allA = false;
//			break;
//		}
//	}
//	if (allA) {
//		for (int i = 1, a; i <= q; i++) {
//			cin >> a;
//			cout << a << "\n";
//		}
//		return;
//	}
//	for (int i = 1,a; i <= q; i++) {
//		cin >> a;
//		int cur = 0;
//		int ans = 0;
//		while (a != 0) {
//			if (s[cur] == 'A') {
//				a -= 1;
//			}
//			else {
//				a>>=1;
//			}
//			cur = (cur + 1) % n;
//			ans++;
//		}
//		cout << ans << "\n";
//	}
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}

//#include<bits/stdc++.h>
//const int N = 2e5 + 5;
//using namespace std;
//int n, k;
//int prime[N];
//int spf[N];
//int cnt = 0;
//void eular() {
//	for (int i = 1; i < N; i++) {
//		spf[i] = i;
//	}
//	for (int i = 2; i < N; i++) {
//		if (spf[i] == i) {
//			prime[++cnt] = i;
//		}
//		for (int j = 1; j <= cnt; j++) {
//			if (prime[j] * i >= N)break;
//			spf[prime[j] * i] = prime[j];
//			if (i % prime[j] == 0)break;
//		}
//	}
//}
//void solve() {
//	cin >> n >> k;
//	vector<int>a(n + 1);
//	map<int, int>mp;
//	vector<int>d(n + 2);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		int t = a[i] / 4;
//		d[0] += 1;
//		d[t+1] -= 1;
//		for (int j = 1; j * j <= a[i]; j++) {
//			if (a[i] % j == 0) {
//				if(j>t)mp[j]++;
//				if (a[i] / j != j&&a[i]/j>t) {
//					mp[a[i] / j]++;
//				}
//			}
//		}
//	}
//	int ans = 1;
//	for (int i = 1; i <= n; i++) {
//		d[i] += d[i - 1];
//		if (n - d[i]-mp[i] <= k) {
//			ans = i;
//		}
//		//cout << i << " " << d[i] <<" "<< mp[i] << "*\n";
//	}
//
//	cout << ans << "\n";
//}
//signed main() {
//	eular();
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int rly;
//void query(int i, int x) {
//	cout << "? " << i << " " << x << endl;
//	cin >> rly;
//}
//void solve() {
//	int n;
//	cin >> n;
//	set<int>nex;
//	set<int>nnex;
//	set<int>nnnex;
//	int ask = 1;
//	for (int i = 1; i <= n-1; i++) {
//		nex.insert(i);
//	}
//	int cur = 0,bit=0;
//	//cur表示目前答案bit位之前的值
//	while (true) {
//		//cout << bitset<10>(cur) << "*\n";
//		for(auto i:nex){
//			query(i, 1ll<<bit);
//			if (rly == 1) {
//				nnex.insert(i);
//			}
//		}
//		int sans = 0;
//		//cout << bit << "%^&\n";
//		for (int i = 1; i <= n; i++) {
//			if (((i & (max(0ll,(1ll << bit) - 1))) == cur) && ((1 << bit) & i) != 0) {
//				sans++;
//				//cout << i << "^^*\n";
//			}
//		}
//		//cout << bitset<5>(cur | (1 << bit)) << "^\n";
//		//cout << sans << "&&\n";
//		if (nnex.size() == sans) {//当前位是0的少了说明答案当前位是0
//			for (auto v : nex) {
//				if (!nnex.count(v)) {
//					nnnex.insert(v);
//				}
//			}
//		}
//		else {
//			cur |= 1ll << bit;
//			for (auto v : nnex) {
//				nnnex.insert(v);
//			}
//		}
//		bit++;
//		nex = nnnex;
//		nnex.clear();
//		nnnex.clear();
//		if (nex.empty()||bit>30)break;
//	}
//	for (int i = 1; i <= n; i++) {
//		if ((i & (1 << bit) - 1) == cur) {
//			cout <<"! "<< i << endl;
//			return;
//		}
//	}
//	
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}



