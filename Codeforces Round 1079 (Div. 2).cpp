//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int cal(int a) {
//	int sum = 0;
//	while (a != 0) {
//		sum += a % 10;
//		a /= 10;
//	}
//	return sum;
//}
//void donkey() {
//	int x;
//	cin >> x;
//	int ans = 0;
//	for (int i = 0; i <= 100; i++) {
//		if (cal(x + i) == i)ans++;
//	}
//	cout << ans << endl;
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		donkey();
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void donkey() {
//	int n;
//	cin >> n;
//	vector<int>p(n + 1);
//	vector<int>a(n + 1);
//	vector<int>pos(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//		pos[p[i]] = i;
//	}
//	int lp = -1;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		if (pos[a[i]] < lp) {
//			cout << "NO\n";
//			return;
//		}
//		lp = pos[a[i]];
//	}
//	cout << "YES\n";
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		donkey();
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void donkey() {
//	int p, q;
//	cin >> p >> q;
//	if (p >= q) {
//		cout << "Alice\n";
//		return;
//	}
//	if (3 * p < 2 * q) {
//		cout << "Alice\n";
//		return;
//	}
//	cout << "Bob\n";
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		donkey();
//	}
//}


//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//void donkey() {
//	int n;
//	cin >> n;
//	vector<ll>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	ll ans = 0;
//	unordered_map<ll, int>mp;
//	for (int k = 1; k * k <= n; k++) {
//		mp.clear();
//		for (int i = 1; i <= n; i++) {
//			if (a[i] == k) {
//				ans += mp[i];
//			}
//			if(i+k*a[i]<=n)mp[i + k * a[i]]++;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		if (a[i] * a[i] > n&&a[i]<=n) {
//			for (int j = i - a[i]; j >= 1; j -= a[i]) {
//				if (a[i] * a[j] == i - j)ans++;
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
//		donkey();
//	}
//}


//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//void donkey() {
//    int n;
//    cin >> n;
//    static vector<ll> a;
//    static vector<int> cnt;
//    a.resize(n + 1);
//    cnt.resize(n + 1, 0);
//    for (int i = 1; i <= n; i++) {
//        cin >> a[i];
//    }
//    ll ans = 0;
//    int mxk = sqrt(n);
//    for (int k = 1; k <= mxk; k++) {
//        fill(cnt.begin(), cnt.end(), 0);
//        for (int i = 1; i <= n; i++) {
//            if (a[i] == k) {
//                ans += cnt[i];
//            }
//            ll pos = i + k * a[i];
//            if (pos <= n) {
//                cnt[pos]++;
//            }
//        }
//    }
//    for (int i = 1; i <= n; i++) {
//        ll ai = a[i];
//        if (ai > n || ai <= mxk) continue;
//        for (int j = i - ai; j >= 1; j -= ai) {
//            if (ai * a[j] == i - j) {
//                ans++;
//            }
//        }
//    }
//
//    cout << ans << endl;
//    a.clear();
//    cnt.clear();
//}
//
//signed main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    cout.sync_with_stdio(false);
//    int t;
//    cin >> t;
//    while (t--) {
//        donkey();
//    }
//    return 0;
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void ask(int k) {
//	cout << "? " << k << endl;
//}
//bool ex[17][17];
//int dp[17];//��ǰ��������߳�������·��
//void donkey() {
//	memset(ex, 0, sizeof(ex));
//	memset(dp, 0, sizeof(dp));
//	int n;
//	cin >> n;
//	int cur = 2;
//	int cv;
//	dp[1] = 1;
//	vector<int>tmp;
//	tmp.reserve(17);
//	while (true) {
//		tmp.clear();
//		ask(cur);
//		cin >> cv;
//		if (cv == 0)break;
//		for (int i = 1,u; i <= cv; i++) {
//			cin >> u;
//			tmp.push_back(u);
//		}
//		if (dp[tmp.back()] != 0) {
//			if(tmp.size()>=2)ex[tmp[tmp.size() - 2]][tmp.back()] = 1;
//			for (int i = 0; i < tmp.size() - 1; i++) {
//				dp[tmp[i]] += dp[tmp.back()];
//			}
//			cur += dp[tmp.back()];
//		}
//		else {
//			for (int i = 0; i < tmp.size(); i++) {
//				dp[tmp[i]]++;
//				if (i > 0)ex[tmp[i - 1]][tmp[i]] = 1;
//			}
//			cur++;
//		}
//		//for (int i = 1; i <= n; i++) {
//		//	for (int j = 1; j <= n; j++) {
//		//		cout << ex[i][j] << " ";
//		//	}cout << endl;
//		//}cout << "\n";
//		//for (int i = 1; i <= n; i++) {
//		//	cout << dp[i] << " ";
//		//}cout << " dp\n";
//	}
//	vector<pair<int,int>>ans;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (ex[i][j])ans.push_back({ i,j });
//		}
//	}
//	cout <<"! "<< ans.size() << endl;
//	for (auto [u, v] : ans) {
//		cout << u << " " << v << endl;
//	}
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		donkey();
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//void donkey() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s = " " + s;
//	int l1 = 0, l2 = 0;
//	vector<int>ll1;
//	vector<int>rr1;
//	vector<int>rr2;
//	vector<int>ll2;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == ')')ll1.push_back(i);
//		if (s[i] == ']')ll2.push_back(i);
//	}
//	int p1 = 0, p2 = 0;
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == '(')l1++;
//		else if (s[i] == ')')l1--;
//		else if (s[i] == '[') {
//			l2++;
//		}
//		else {
//			l2--;
//		}
//		if (l1 < 0 && l2 < 0) {
//			if (ll1[p1] < ll2[p2]) {
//				s[ll1[p1]] = '[';
//			}
//			else {
//				s[ll2[p2]] = '(';
//			}
//			p1++;
//			p2++;
//			l1++;
//			l2++;
//			ans++;
//		}
//	}
//	for (int i = n; i >= 1; i--) {
//		if (s[i] == '(')rr1.push_back(i);
//		if (s[i] == '[')rr2.push_back(i);
//	}
//	p1 = 0; p2 = 0;
//	int r1 = 0, r2 = 0;
//	for (int i = n; i >= 1; i--) {
//		if (s[i] == ')')r1++;
//		else if (s[i] == '(')r1--;
//		else if (s[i] == ']') {
//			r2++;
//		}
//		else {
//			r2--;
//		}
//		if (r1 < 0 && r2 < 0) {
//			if (rr1[p1] > rr2[p2]) {
//				s[rr1[p1]] = ']';
//			}
//			else {
//				s[rr2[p2]] = ')';
//			}
//			p1++;
//			p2++;
//			r1++;
//			l2++;
//			ans++;
//		}
//	}
//	 l1 = 0;
//	 l2 = 0;
//	for (int i = 1; i <= n; i++) {
//		if (s[i] == '(')l1++;
//		else if (s[i] == ')')l1--;
//		else if (s[i] == '[') {
//			l2++;
//		}
//		else {
//			l2--;
//		}
//	}
//	if (l1 > 0) {
//		for (int i = n; i >= 1; i--) {
//			if (s[i] == '('&&l1-2>=0) {
//				s[i] = ')';
//				l1 -= 2;
//				ans++;
//			}
//		}
//	}
//	else {
//		for (int i = 1; i <= n; i++) {
//			if (s[i] == ')' && l1 + 2 <= 0) {
//				s[i] = '(';
//				l1 == 2;
//				ans++;
//			}
//		}
//	}
//	if (l2 > 0) {
//		for (int i = n; i >= 1; i--) {
//			if (s[i] == '['&&l2-2>=0) {
//				s[i] = ']';
//				l2 -= 2;
//				ans++;
//			}
//		}
//	}
//	else {
//		for (int i = 1; i <= n; i++) {
//			if (s[i] == ']' && l2 + 2 <= 0) {
//				s[i] = '[';
//				l2 == 2;
//				ans++;
//			}
//		}
//	}
//	if (l1 & 1)ans++;
//	cout << ans << endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		donkey();
//	}
//}