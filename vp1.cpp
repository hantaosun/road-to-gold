//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	if (n == 0) {
//		cout << 0 << endl;
//		return;
//	}
//	while (k--) {
//		if (n % 2 == 0)n /= 2;
//		else {
//			n = n / 2 + 1;
//		}
//		if (n == 1) {
//			cout << 1 << endl;
//			return;
//		}
//	}
//	cout << n << endl;
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
//#define int long long
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	if (n == 0) {
//		cout << 0 << endl;
//		return;
//	}
//	vector<int>a(n + 1);
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		sum += a[i];
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		if (a[i] > sum / n)ans += a[i] - sum / n;
//	}
//	cout << ans << endl;
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
//	int k;
//	cin >> k;
//	string s;
//	cin >> s;
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0,u,v; i < m; i++) {
//		cin >> u >> v;
//	}
//	int a = (m - n + 2) % k == 0 ? k - 1 : (m - n + 2) % k-1;
//	if (s[a] == '1')cout << 2 << endl;
//	else cout << 1 << endl;
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
//int rankk(int t,int l,int r,vector<int>&a) {
//	int ans = -1;
//	int m;
//	while (l <= r) {
//		m = (l + r) / 2;
//		if (a[m] >= t) {
//			ans = m;
//			r = m - 1;
//		}
//		else {
//			l = m + 1;
//		}
//	}
//	return ans;
//}
//struct Compare {
//	bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
//		return a.second > b.second;
//	}
//};
//bool cmp(pair<int, int>& a, pair<int, int>& b) {
//	if (a.first == b.first)return a.second < b.second;
//	else return a.first < b.first;
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<pair<int, int>>line(n);
//	vector<int>a;
//	for (int i = 0; i < n; i++) {
//		cin >> line[i].first >> line[i].second;
//		a.emplace_back(line[i].first);
//		a.emplace_back(line[i].second);
//	}
//	sort(a.begin(), a.end());
//	int len = 0;
//	for (int i = 1; i < a.size(); i++) {
//		if (a[i] != a[len]) {
//			a[++len] = a[i];
//		}
//	}
//	for (int i = 0; i <n; i++) {
//		line[i].first = rankk(line[i].first, 0, len, a);
//		line[i].second = rankk(line[i].second, 0, len, a);
//	}//离散化
//	sort(line.begin(), line.end(), cmp);
//	//for (auto p : line) {
//	//	cout << p.first << " " << p.second << " *"<<endl;
//	//}
//	priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pq;
//	int used = 0;//小于used均以使用过
//	int ans = 0;
//	for (int i = 0; i < n; ) {
//		while (i<n&&line[i].first <= used) {
//			pq.push(line[i]);
//			i++;
//		}
//		if (i<n&&pq.empty()) {
//			used = line[i].first;
//			continue;
//		}
//		while(!pq.empty()){
//			auto p = pq.top();
//			cout << p.first << " " << p.second;
//			if (p.second < used) {
//				pq.pop();
//				cout << 1 << endl;
//				continue;
//			}
//			else {
//				pq.pop();
//				used++;
//				ans++;
//				break;
//			}
//		}
//	}
//	cout << ans << endl;
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
//void solve() {//菱形情况没去除
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>a(n + 3);
//	vector<int>indegree(n + 3, 0);
//	vector<vector<int>>a1(n + 3);
//	vector<int>indegree1(n + 3, 0);
//	vector<int>large(n + 3, 0);
//	vector<int>small(n + 3, 0);
//	for (int i = 1, u, v; i <= m; i++) {
//		cin >> u >> v;
//		indegree[u]++;
//		a[v].push_back(u);
//		indegree1[v]++;
//		a1[u].push_back(v);
//	}
//	queue<int>q;
//	for (int i = 1; i <= n; i++) {
//		if (indegree[i] == 0)q.push(i);
//	}
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//		for (int i : a[cur]) {
//			small[i] += small[cur] + 1;
//			if (--indegree[i] == 0) {
//				q.push(i);
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		if (indegree[i] != 0) {
//			for (int i = 1; i <= n; i++)cout << 0;
//			cout << endl;
//			return;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		if (indegree1[i] == 0)q.push(i);
//	}
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//		for (int i : a1[cur]) {
//			large[i] += large[cur] + 1;
//			if (--indegree1[i] == 0) {
//				q.push(i);
//			}
//		}
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	cout << large[i] << " " << small[i] <<" *"<< endl;
//	//}
//	for (int i = 1; i <= n; i++) {
//		if (large[i] > (n - 1) / 2 || small[i] > (n - 1) / 2)cout << 0;
//		else cout << 1;
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