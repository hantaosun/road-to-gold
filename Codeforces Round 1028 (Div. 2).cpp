//A
//#include<iostream>
//using namespace std;
//void solve() {
//	int a, b, c, d;
//	cin >> a >> b >> c >> d;
//	if (min(a, c) >= min(b, d)) {
//		cout << "Gellyfish" << "\n";
//	}
//	else {
//		cout << "Flower" << "\n";
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
//B
//#include<iostream>
//#define int long long
//using namespace std;
//int p[100005];
//int mp[100005][2];//q 0-i上最大的值及其下标
//int q[100005];
//int mq[100005][2];//q 0-i上最大的值及其下标
//const int mod = 998244353;
//int caculate(int t) {
//	int a = 2;
//	int ans = 1;
//	while (t != 0) {
//		if (t & 1) {
//			ans = (ans * a)%mod;
//		}
//		a = (a * a) % mod;
//		t >>= 1;
//	}
//	return ans;
//}
//void solve() {
//	int n;
//	cin >> n;
//	cin >> p[0];
//	mp[0][0] = p[0];
//	mp[0][1] = 0;
//	for (int i = 1; i < n; i++) {
//		cin >> p[i];
//		if (p[i] > mp[i - 1][0]) {
//			mp[i][0] = p[i];
//			mp[i][1] = i;
//		}
//		else {
//			mp[i][0] = mp[i - 1][0];
//			mp[i][1] = mp[i - 1][1];
//		}
//	}
//	cin >> q[0];
//	mq[0][0] = q[0];
//	mq[0][1] = 0;
//	for (int i = 1; i < n; i++) {
//		cin >> q[i];
//		if (q[i] > mq[i - 1][0]) {
//			mq[i][0] = q[i];
//			mq[i][1] = i;
//		}
//		else {
//			mq[i][0] = mq[i - 1][0];
//			mq[i][1] = mq[i - 1][1];
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		int a = mp[i][0],ai=mp[i][1],ao=q[i-ai];
//		int b = mq[i][0],bi=mq[i][1],bo=p[i-bi];
//		if (a > b) {
//			cout << (caculate(a) + caculate(ao)) %mod<< " ";
//		}
//		else if (b > a) {
//			cout << (caculate(b) + caculate(bo))%mod<< " ";
//		}
//		else {
//			if (ao >= bo) {
//				cout << (caculate(a) + caculate(ao))%mod << " ";
//			}
//			else {
//				cout << (caculate(b) + caculate(bo))%mod << " ";
//			}
//		}
//	}
//	cout << "\n";
//}
//signed main(){
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}
//
//C
//#include<iostream>
//#include<vector>
//#include<climits>
//#include<queue>
//#include<vector>
//#include<set>
//using namespace std;
//int arr[5005];
//int b[5005];
//int gcd(int a, int b) {
//	if (a < b) {
//		int t = a;
//		a = b;
//		b = t;
//	}
//	return b == 0 ? a : gcd(b, a % b);
//}
//int n;
//void solve() {	
//	cin >> n;
//	int tgcd;
//	cin >> arr[1];
//	tgcd = arr[1];
//	for (int i = 2; i <= n; i++) {
//		cin >> arr[i];
//		tgcd = gcd(arr[i], tgcd);
//	}
//	int cnt = 0;
//	for (int i = 1; i <= n; i++) {
//		if (arr[i] == tgcd)cnt++;
//	}
//	if (cnt != 0) {
//		cout << n - cnt << endl;
//		return;
//	}
//	vector<bool>visi(50005, 0);
//	vector<int>dis(50005, 100000);
//	queue<int>q;
//	for (int i = 1; i <= n; i++) {
//		visi[arr[i]] = 1;
//		dis[arr[i]] = 0;
//		q.push(arr[i]);
//	}
//	while (!visi[tgcd]) {
//		int y = q.front();
//		q.pop();
//		for (int i = 1; i <= n; i++) {
//			int x = gcd(arr[i],y);
//			if (dis[x] > dis[y] + 1) {
//				dis[x] = dis[y] + 1;
//			}
//			if (!visi[x]) {
//				q.push(x);
//				visi[x] = 1;
//			}
//		}
//	}
//	cout << n - 1 + dis[tgcd] << endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}