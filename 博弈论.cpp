//Bash博弈
//一共n颗石子,两人轮流拿,每次可以拿1-m颗石子
//拿到最后一颗获胜
//结论 n%(m+1)!=0先手赢 否则后手赢


//P4018 Roy& October之取石子
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	if (n % 6 != 0) {
//		cout << "October wins!\n";
//	}
//	else cout << "Roy wins!\n";
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//Nim博弈
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	int xo = 0;
//	for (int i = 1, v; i <= n; i++) {
//		cin >> v;
//		xo ^= v;
//	}
//	if (xo != 0) {
//		cout << "Yes\n";
//	}
//	else cout << "No\n";
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//反Nim博弈
//必胜态 仅一堆大于1剩余小于等于1 此时异或不是0 与正Nim一样
//全1时要判断奇偶性
//让先手先撞上赢的状态 正Nim让后手先撞上输的状态
//小约翰的游戏
//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n;
//	cin >> n;
//	int sum = 0;
//	int xo = 0;
//	for (int i = 1,u; i <= n; i++) {
//		cin >> u;
//		xo ^= u;
//		sum += u == 1 ? 1 : 0;
//	}
//	if (sum == n) {
//		if (sum & 1) {
//			cout << "Brother\n";
//		}
//		else cout << "John\n";
//	}
//	else {
//		if (xo == 0) {
//			cout << "Brother\n";
//		}
//		else cout << "John\n";
//	}
//
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//斐波那契博弈
//任意正整数一定可以拆为若干个不相邻的斐波那契数的和
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e15 + 5;
//vector<int>fib;
//void prepare() {
//	fib.emplace_back(1);
//	fib.emplace_back(2);
//	while (fib.back() < N) {
//		fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
//	}
//}
//signed main() {
//	prepare();
//	int n;
//	cin >> n;
//	while (n != 1) {
//		auto it = upper_bound(fib.begin(), fib.end(), n);
//		int id = it - fib.begin() - 1;
//		if (fib[id] == n) {
//			cout << n << '\n';
//			return 0;
//		}
//		else {
//			n -= fib[id];
//		}
//	}
//	cout << 1 << '\n';
//}



//分裂游戏
//#include<bits/stdc++.h>
//using namespace std;
//int sg[21];
//int appear[200];
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n);
//	int xo = 0;
//	for (int i = n - 1; i >= 0; i--) {
//		cin >> a[i];
//		if (a[i] & 1) {
//			xo ^= sg[i];
//		}
//	}
//	if (xo == 0) {
//		cout << -1 << " " << -1 << " " << -1 << '\n';
//		cout << 0 << "\n";
//		return;
//	}
//	int ni=-1, nj, nk;
//	int cnt = 0;
//	for (int i = n - 1; i >= 1; i--) {
//		if (a[i] != 0) {
//			for (int j = i - 1; j >= 0; j--) {
//				for (int k = j; k >= 0; k--) {
//					if ((xo ^ sg[i] ^ sg[j] ^ sg[k]) == 0) {
//						cnt++;
//						if (ni == -1) {
//							ni = i;
//							nj = j;
//							nk = k;
//						}
//					}
//				}
//			}
//		}
//	}
//	cout << n - 1 - ni << " " << n - 1 - nj << " " << n - 1 - nk << '\n';
//	cout << cnt << '\n';
//}
//void prepare() {
//	for (int i = 1; i < 21; i++) {
//		for (int j = i - 1; j >= 0; j--) {
//			for (int k = j; k >= 0; k--) {
//				appear[sg[j]^sg[k]] = 1;
//			}
//		}
//		for (int j = 0; j < 200; j++) {
//			if (!appear[j]) {
//				sg[i] = j;
//				break;
//			}
//		}
//	}
//}
//int main() {
//	prepare();
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}