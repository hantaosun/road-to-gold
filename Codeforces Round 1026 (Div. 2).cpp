//C
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>d(n + 5);
//	vector<int>l(n + 5);
//	vector<int>r(n + 5);
//	vector<int>backmax(n + 5);
//	backmax[n + 1] = INT_MIN;
//	for (int i = 1; i <= n; i++) {
//		cin >> d[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> l[i] >> r[i];s
//	}
//	for (int i = n; i >= 0; i--) {
//		backmax[i] = max(r[i], backmax[i + 1]);
//	}
//	int cur = 0;
//	queue<int>q;
//	for (int i = 1; i <= n; i++) {
//		if (d[i] == -1)q.push(i);
//		else {
//			cur += d[i];
//		}
//		while (!q.empty() && cur < l[i]) {
//			d[q.front()] = 1;
//			q.pop();
//			cur++;
//		}
//		while (!q.empty()&&r[i] < cur + q.size()) {
//			d[q.front()] = 0;
//			q.pop();
//		}
//		if (cur < l[i]||cur>r[i]) {
//			cout << -1 << endl;
//			return;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << max(0,d[i]) << " ";
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
