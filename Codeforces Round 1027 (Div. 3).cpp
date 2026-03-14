//D
//#include<iostream>
//#include<vector>
//#include<climits>
//#define int long long
//#define INT_MAX LLONG_MAX
//#define INT_MIN LLONG_MIN
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<pair<int, int>>mon(n+5);
//	vector<int>shangmin(n+5),zuomin(n+5),youmax(n+5),xiamax(n+5),shangmin1(n+5),
//		zuomin1(n+5), youmax1(n + 5), xiamax1(n + 5);
//	shangmin[0] = INT_MAX;
//	zuomin[0] = INT_MAX;
//	youmax[0] = INT_MIN;
//	xiamax[0] = INT_MIN;
//	shangmin1[n+1] = INT_MAX;
//	zuomin1[n+1] = INT_MAX;
//	youmax1[n+1] = INT_MIN;
//	xiamax1[n+1] = INT_MIN;
//	for (int i = 1; i <= n; i++) {
//		cin >> mon[i].first >> mon[i].second;
//	}	
//	if (n == 1) {
//		cout << 1 << endl;
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		shangmin[i] = min(mon[i].first, shangmin[i - 1]);
//		zuomin[i] = min(mon[i].second, zuomin[i - 1]);
//		xiamax[i] = max(mon[i].first, xiamax[i - 1]);
//		youmax[i] = max(mon[i].second, youmax[i - 1]);
//	}
//	for (int i = n; i >= 1; i--) {
//		shangmin1[i] = min(mon[i].first, shangmin1[i + 1]);
//		zuomin1[i] = min(mon[i].second, zuomin1[i + 1]);
//		xiamax1[i] = max(mon[i].first, xiamax1[i + 1]);
//		youmax1[i] = max(mon[i].second, youmax1[i + 1]);
//	}
//	int ans = INT_MAX;
//	for (int i = 1,shang,xia,zuo,you; i <= n; i++) {
//		shang = min(shangmin[i - 1], shangmin1[i + 1]);
//		xia = max(xiamax[i - 1], xiamax1[i + 1]);
//		zuo = min(zuomin[i - 1], zuomin1[i + 1]);
//		you = max(youmax[i - 1], youmax1[i + 1]);
//		int chang = xia - shang + 1,kuan=you-zuo+1;
//		/*cout << shang << " " << xia << " " << zuo << " " << you << endl;
//		cout << chang << " " << kuan <<"**"<< endl;*/
//		if (chang*kuan==n-1) {
//			ans = min(ans, chang * kuan + min(chang, kuan));
//		}
//		else {
//			ans = min(ans, chang * kuan);
//		}
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
//
//E
//#include<iostream>
//#include<vector>
//#define int long long
//using namespace std;
//void dfs(int fa,int cur,vector<vector<int>>&edges,vector<pair<int,int>>&presum,vector<int>&dan) {
//	if (presum[fa].first < 0) {
//		presum[cur].second = dan[cur] - presum[fa].first;
//	}
//	else {
//		presum[cur].second = dan[cur];
//	}
//	if (presum[fa].second > 0) {
//		presum[cur].first = dan[cur] - presum[fa].second;
//	}
//	else {
//		presum[cur].first = dan[cur];
//	}
//	for (int i : edges[cur]) {
//		if (i == fa)continue;
//		dfs(cur, i, edges, presum, dan);
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>dan(n + 5);
//	vector<vector<int>>edges(n+5);
//	vector<pair<int,int>>presum(n+5);//从该节点到根节点路径上最小的交替和与最大的交替和
//	for (int i = 1; i <= n; i++) {
//		cin >> dan[i];
//	}
//	for(int i=1,u,v;i<=n-1;i++){
//		cin >> u >> v;
//		edges[u].push_back(v);
//		edges[v].push_back(u);
//	}
//	dfs(1, 1, edges, presum, dan);
//	for (int i = 1; i <= n; i++) {
//		cout << presum[i].second << " ";
//	}
//	cout << endl;
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}