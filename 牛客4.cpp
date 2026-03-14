//F
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//signed main() {
//	int n, k, c;
//	cin >> n >> k >> c;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		a[i] -= c * i;
//	}
//	nth_element(a.begin() + 1, a.begin() + 1 + n - k, a.end());
//	int ans = c * k * (k + 1) / 2;
//	for (int i = n - k + 1; i < a.size(); i++) {
//		ans += a[i];
//	}
//	cout << ans << endl;
//}


//B
//#include<bits/stdc++.h>
//using namespace std;
//int n, m, k;
//int ll, rr;
//vector<string>mp(n);
//vector<vector<bool>>start;
//vector<vector<bool>>final;
//vector<vector<bool>>visi;
//void dfs1(int x, int y) {
//	if (x >= n || x < 0 || y >= m || y < 0 || mp[x][y] == '1' || final[x][y])return;
//	final[x][y] = 1;
//	dfs1(x - 1, y);
//	dfs1(x + 1, y);
//	dfs1(x, y - 1);
//}
//void dfs2(int x, int y) {
//	if (x >= n || x < 0 || y >= m || y < 0 || mp[x][y] == '1' || start[x][y])return;
//	start[x][y] = 1;
//	dfs2(x - 1, y);
//	dfs2(x + 1, y);
//	dfs2(x, y + 1);
//}
//void dfs3(int x, int y) {
//	if (x >= n || x < 0 || y >= m || y < 0 ||
//		mp[x][y] == '1' || final[x][y] ||
//		!start[x][y] || visi[x][y])return;
//	visi[x][y] = 1;
//	rr = max(rr, y);
//	ll = min(ll, y);
//	dfs3(x - 1, y);
//	dfs3(x + 1, y);
//	dfs3(x, y + 1);
//}
//
//void solve() {
//	cin >> n >> m >> k;
//	mp.clear();
//	mp.resize(n);
//	start.assign(n, vector<bool>(m, 0));
//	final.assign(n, vector<bool>(m, 0));
//	visi.assign(n, vector<bool>(m, 0));
//	for (int i = 0; i < n; i++) {
//		cin >> mp[i];
//	}
//	dfs1(0, m - 1);
//	dfs2(0, 0);
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			if (start[j][i] && !final[j][i] && !visi[j][i]) {
//				ll = rr = i;
//				dfs3(j, i);
//				if (rr - ll + 1 >= k) {
//					cout << "YES\n";
//					return;
//				}
//			}
//		}
//	}
//	cout << "NO\n";
//}
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}
//jiangly dp做法代码
//#include <bits/stdc++.h>
//
//using i64 = long long;
//using u64 = unsigned long long;
//using u32 = unsigned;
//
//using u128 = unsigned __int128;
//using i128 = __int128;
//
//void solve() {
//    int N, M, K;
//    std::cin >> N >> M >> K;
//
//    std::vector<std::string> s(N);
//    for (int i = 0; i < N; i++) {
//        std::cin >> s[i];
//    }
//
//    std::vector vis(N, std::vector<bool>(M));
//    vis[0][0] = true;
//    for (int j = 0; j < M; j++) {
//        if (j) {
//            for (int i = 0; i < N; i++) {
//                if (s[i][j] == '0' && vis[i][j - 1]) {
//                    vis[i][j] = true;
//                }
//            }
//        }
//        for (int i = 1; i < N; i++) {
//            if (s[i][j] == '0' && vis[i - 1][j]) {
//                vis[i][j] = true;
//            }
//        }
//        for (int i = N - 2; i >= 0; i--) {
//            if (s[i][j] == '0' && vis[i + 1][j]) {
//                vis[i][j] = true;
//            }
//        }
//    }
//
//    std::vector dp(N, std::vector<int>(M, -1));
//
//    for (int j = M - 1; j >= 0; j--) {
//        for (int i = 0; i < N; i++) {
//            if (s[i][j] == '0') {
//                dp[i][j] = j;
//            }
//        }
//        if (j < M - 1) {
//            for (int i = 0; i < N; i++) {
//                if (s[i][j] == '0') {
//                    dp[i][j] = std::max(dp[i][j], dp[i][j + 1]);
//                }
//            }
//        }
//        for (int i = 1; i < N; i++) {
//            if (s[i][j] == '0') {
//                dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
//            }
//        }
//        for (int i = N - 2; i >= 0; i--) {
//            if (s[i][j] == '0') {
//                dp[i][j] = std::max(dp[i][j], dp[i + 1][j]);
//            }
//        }
//    }
//
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            if (vis[i][j] && dp[i][j] >= j + K - 1 && dp[i][j] < M - 1) {
//                std::cout << "Yes\n";
//                return;
//            }
//        }
//    }
//    std::cout << "No\n";
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//
//    int T;
//    std::cin >> T;
//
//    while (T--) {
//        solve();
//    }
//
//    return 0;
//}


//D
//#include<iostream>
//#define int long long
//using namespace std;
//int a[300][300];
//void print2(int i, int j) {
//	a[i][j] = 1;
//	a[i][j + 1] = 0;
//	a[i][j + 2] = 1;
//	a[i + 1][j] = 1;
//	a[i + 1][j + 1] = 1;
//	a[i + 1][j + 2] = 0;
//	a[i + 2][j] = 0;
//	a[i + 2][j + 1] = 1;
//	a[i + 2][j + 2] = 1;
//}
//void print1(int i,int j) {
//	a[i][j] = 1;
//	a[i][j + 1] = 0;
//	a[i][j + 2] = 0;
//	a[i + 1][j] = 0;
//	a[i + 1][j + 1] = 1;
//	a[i + 1][j + 2] = 0;
//	a[i + 2][j] = 0;
//	a[i + 2][j + 1] = 0;
//	a[i + 2][j + 2] = 1;
//}
//void printm1(int i, int j) {
//	a[i][j] = 0;
//	a[i][j + 1] = 0;
//	a[i][j + 2] = 1;
//	a[i + 1][j] = 0;
//	a[i + 1][j + 1] = 1;
//	a[i + 1][j + 2] = 0;
//	a[i + 2][j] = 1;
//	a[i + 2][j + 1] = 0;
//	a[i + 2][j + 2] = 0;
//}
//signed main() {
//	int N;
//	cin >> N;
//	cout << 99 << endl;
//	for (int i = 96,p=32; i >= 0; i -= 3,p--) {
//		if (N & ((int)(1) << p)) {
//			if (p & 1) {
//				printm1(0, i);
//			}
//			else print1(0, i);
//		}
//	}
//	for (int i = 3; i <= 96; i+=3) {
//		print1(i, i);
//		print2(i, i - 3);
//	}
//	for (int i = 0; i <= 98; i++) {
//		for (int j = 0; j <= 98; j++) {
//			cout << a[i][j];
//		}
//		cout << endl;
//	}
//}

//#define _CRT_SECURE_NO_WARNINGS
//#define ll long long int
//#include<iostream>
//#include<iomanip>
//#include<cstdio>
//#include<cctype>
//#include<cstring>
//#include<algorithm>
//#include<math.h>
//#include<vector>
//#include<string>
//#include<set>
//#include<bit>
//#include<map>
//#include<list>
//#include<array>
//#include<stack>
//#include<queue>
//#include<deque>
//#include<random>
//#include<chrono>
//#include<bitset>
//#include<climits>
//#include<numbers>
//#include<numeric>
//#include<unordered_map>
//#include<unordered_set>
//const int INF = INT_MAX;
//using namespace std;
//
//const int MAXN = 1000007;
//const int MOD = 998244353;
//const int inv2 = (MOD + 1) / 2;
//ll sum[MAXN], f[MAXN], suf[MAXN], pref[MAXN];
//
//int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int T = 1;
//    //cin >> T;
//    while (T--) {
//        string s;
//        ll ans = 0;
//        cin >> s;
//        ll n = s.size();
//        f[0] = 1;
//        for (int i = 1; i <= n; i++) {
//            f[i] = f[i - 1] * 2 % MOD;
//        }
//        for (int i = 0; i < n; i++) {
//            sum[i + 1] = sum[i] + (s[i] == '(' ? 1 : -1);
//        }
//        for (int i = n; i > 0; --i) {
//            suf[i] = suf[i + 1] + (s[i - 1] == ')');
//        }
//        for (int i = 1; i <= n; i++) {
//            pref[i] = pref[i - 1] + (s[i - 1] == '(');
//        }
//        int R = 1;
//        for (int i = 1; i <= n; i++) {
//            R = max(R, i);
//            while (R <= n && sum[R] > 1) {//()(())() //()((i)r
//                R++;
//            }
//            if (s[i - 1] == '(') {
//                //cout << "updating\n";
//                ans = (ans + f[suf[R + 1]] * f[pref[i - 1]]) % MOD;
//            }
//            //cout << "i at " << i << " R at " << R << " suf " << suf[R + 1] << " pref " << pref[i - 1] <<" " << ans << "\n";
//        }
//        ans = (ans + f[n / 2]) % MOD;
//        for (int i = 1; i <= n; i++) {
//            ans = ans * inv2 % MOD;
//        }
//        cout << ans << "\n";
//    }
//    return 0;
//}
//mt19937_64 rng((unsigned ll)chrono::high_resolution_clock::now().time_since_epoch().count());
//G
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 1e6 + 10;
//const int mod = 998244353;
//int preL[MAXN];//i位置及以前共几个左括号
//int sufR[MAXN];//i位置及以后共几个左括号
//int presum[MAXN];
//int qmi(int a, int b) {
//    int ans = 1;
//    while (b != 0) {
//        if (b & 1) {
//            ans = (ans * a)%mod;
//        }
//        a = (a * a)%mod;
//        b >>= 1;
//    }
//    return ans;
//}
//signed main() {
//    string c;
//    cin >> c;
//	string s=" "+c;
//    int len = s.size()-1;
//    for (int i = 1; i <=len; i++) {
//        preL[i] = preL[i-1] + (s[i] == '(');
//        presum[i] = presum[i-1] + (s[i] == '(' ? 1 : -1);
//    }
//    for (int i = len; i >= 1; i--) {
//        sufR[i] = sufR[i + 1] + (s[i] == ')');
//    }
//    int ans = 0;
//    int r = 0;
//    for (int i = 1; i <=len; i++) {
//        if (s[i] == ')')continue;
//        r = max(i, r);
//        while (presum[r]>1&&r<=len) {
//            r++;
//        }
//        //cout << i << " " << r << endl;
//        ans = (ans + qmi(2, preL[i - 1]) * qmi(2, sufR[r + 1]) % mod) % mod;
//        //cout << ans << endl;
//    }
//    ans = (ans + qmi(2, len / 2)) % mod;//补上全右的情况
//    //cout << ans << endl;
//    ans = (ans * qmi(qmi(2, len), mod - 2)) % mod;
//    cout << ans << endl;
//}


//I
//#include<bits/stdc++.h>
//using namespace std;
//int n, m;
//vector<string>mp;
//vector<vector<int>>box;
//vector<vector<int>>target;
//bool wall[55][55];
//struct DSU {
//	std::vector<int> f, siz;
//
//	DSU() {}
//	DSU(int n) {
//		init(n);
//	}
//
//	void init(int n) {
//		f.resize(n);
//		std::iota(f.begin(), f.end(), 0);
//		siz.assign(n, 1);
//	}
//
//	int find(int x) {
//		while (x != f[x]) {
//			x = f[x] = f[f[x]];
//		}
//		return x;
//	}
//
//	bool same(int x, int y) {
//		return find(x) == find(y);
//	}
//
//	bool merge(int x, int y) {
//		x = find(x);
//		y = find(y);
//		if (x == y) {
//			return false;
//		}
//		siz[x] += siz[y];
//		f[y] = x;
//		return true;
//	}
//
//	int size(int x) {
//		return siz[find(x)];
//	}
//};
//
//int dx[] = {1,0,-1,0};
//int dy[] = {0,1,0,-1};
//string str = "DRUL";
//auto getPath(vector<int>& a, vector<int>& b) {
//	vector<vector<vector<int>>>visi(n, vector<vector<int>>(m, vector<int>(2,-1)));
//	visi[a[0]][a[1]] = a;
//	queue<vector<int>>q;
//	q.push(a);
//	while (!q.empty()) {
//		auto v = q.front();
//		int x = v[0], y = v[1];
//		q.pop();
//		for (int k = 0; k < 4; k++) {
//			int nx = x + dx[k];
//			int ny = y + dy[k];
//			if (0 <= nx && nx < n && 0 <= ny && ny < m && !wall[nx][ny] && visi[nx][ny][0] == -1) {
//				visi[nx][ny][0] = x;
//				visi[nx][ny][1] = y;
//				q.push({ nx,ny });
//			}
//		}
//	}
//	vector<vector<int>>path;
//	while (b != a) {
//		path.push_back(b);
//		b = visi[b[0]][b[1]];
//	}
//	return path;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n >> m;
//	mp.resize(n);
//	for (int i = 0; i < n; i++) {
//		cin >> mp[i];
//		for (int j = 0; j < m; j++) {
//			if (mp[i][j] == '#') {
//				wall[i][j] = true;
//			}
//			if (mp[i][j] == '@' || mp[i][j] == '!') {
//				box.push_back({ i,j });
//			}
//			if (mp[i][j] == '*' || mp[i][j] == '!') {
//				target.push_back({ i,j });
//			}
//		}
//	}
//	DSU dsu(n * m);
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (!wall[i][j]) {
//				if (i && !wall[i - 1][j]) {
//					dsu.merge(i * m + j, (i - 1) * m + j);
//				}
//				if (j && !wall[i][j - 1]) {
//					dsu.merge(i * m + j, i * m + j - 1);
//				}
//			}
//		}
//	}
//	sort(box.begin(), box.end(),
//		[&](auto a, auto b) {
//			return dsu.find(a[0] * m + a[1]) < dsu.find(b[0] * m + b[1]);
//		});
//	sort(target.begin(), target.end(),
//		[&](auto a, auto b) {
//			return dsu.find(a[0] * m + a[1]) < dsu.find(b[0] * m + b[1]);
//		});
//	const int k = box.size();
//	for (int i = 0, a, b, c, d; i < k; i++) {
//		a = box[i][0]; b = box[i][1];
//		c = target[i][0]; d = target[i][1];
//		if (!dsu.same(a * m + b, c * m + d)) {
//			cout << -1 << endl;
//			return 0;
//		}
//	}
//	vector<vector<vector<int>>>path(k);
//	for (int i = 0; i < k; i++) {
//		path[i] = getPath(box[i], target[i]);
//	}
//	vector < tuple<int, int, char> >ans;
//	while (true) {
//		int b = -1;
//		for (int i = 0; i < k; i++) {
//			if (!path[i].empty() && (b == -1 || path[i].size() < path[b].size())) {
//				b = i;
//			}
//		}
//		if (b == -1)break;
//		path[b] = getPath(box[b], target[b]);
//		while (!path[b].empty()) {
//			auto nxt = path[b].back();
//			path[b].pop_back();
//			int c = find(box.begin(), box.end(), nxt) - box.begin();
//			if (c < k) {
//				swap(box[b], box[c]);
//				path[c].push_back(box[b]);
//				continue;
//			}
//
//			int x = box[b][0], y = box[b][1];
//			for (int d = 0; d < 4; d++) {
//				int nx = x + dx[d];
//				int ny = y + dy[d];
//				if (nxt == vector<int>{nx, ny}) {
//					ans.push_back(tuple<int, int, char>{x + 1, y + 1, str[d]});
//					break;
//				}
//			}
//			box[b] = nxt;
//		}
//	}
//	cout << ans.size() << endl;
//	for (auto [x, y, d] : ans) {
//		cout << x << " " << y << " " << d << "\n";
//	}
//	return 0;
//}


//L
//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n, q;
//	cin >> n >> q;
//	vector<int>a(n + 1);
//	vector<int>sum(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i + 30 <= n; i++) {
//		for (int j = 0; j <= 30; j++) {
//			sum[i] += (1 << j) * (a[i + j] + 1);
//		}
//	}
//	int l, r;
//}