//带权并查集模板题 一维数轴模型(不过这里是范围和)通过右侧边界+1的转换即可变成数轴模型
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 5;
//int n, m, q;
//int fa[N];
//int dist[N];//当前节点相对头结点的某个指标,这里是距离
//void prepare() {
//	for (int i = 1; i <N; i++) {
//		fa[i] = i;
//		dist[i] = 0;
//	}
//}
//int find(int i) {
//	if (i != fa[i]) {
//		int tmp = fa[i];
//		fa[i] = find(tmp);
//		dist[i] += dist[tmp];//修正节点信息公式,本题中是当前节点距离加上其父亲结点的距离
//	}
//	return fa[i];
//}
//void Union(int l, int r, int v) {
//	int lf = find(l);
//	int rf = find(r);
//	if (lf == rf)return;
//	fa[lf] = rf;
//	dist[lf] = v + dist[r] - dist[l];//可由 x实际坐标等于fa[x]的坐标加上weight[x]推导而来,其余情况类似
//}
//signed main() {
//	cin >> n >> m >> q;
//	prepare();
//	for (int i = 1, l, r, s; i <= m; i++) {
//		cin >> l >> r >> s;
//		Union(l, r+1, s);
//	}
//	for (int i = 1, l, r; i <= q; i++) {
//		cin >> l >> r;
//		int lf = find(l);
//		int rf = find(r+1);
//		if (lf != rf) {
//			cout << "UNKNOWN\n";
//		}
//		else {
//			cout << dist[l] - dist[r+1] << '\n';
//		}
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 105;
//int n, m;
//int fa[N];
//int dist[N];
//void prepare() {
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//		dist[i] = 0;
//	}
//}
//int find(int x) {
//	if (x != fa[x]) {
//		int tmp = fa[x];
//		fa[x] = find(tmp);
//		dist[x] += dist[tmp];
//	}
//	return fa[x];
//}
//bool merge(int l,int r,int v) {
//	int lf = find(l);
//	int rf = find(r);
//	if (lf == rf) {
//		if (dist[l] - dist[r] == v)return true;
//		else return false;
//	}
//	fa[lf] = rf;
//	dist[lf] = v + dist[r] - dist[l];
//	return true;
//}
//void solve() {
//	cin >> n >> m;
//	n++;
//	prepare();
//	bool flag = true;
//	for (int i = 1,l,r,v; i <= m; i++) {
//		cin >> l >> r >> v;
//		if (!merge(l, r + 1, v)) {
//			flag = false;
//		}
//	}
//
//	cout << (flag ? "true\n" : "false\n");
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
//const int N = 3e4 + 5;
//int fa[N];
//int dist[N];
//int siz[N];
//void prepare() {
//	for (int i = 0; i < N; i++) {
//		fa[i] = i;
//		siz[i] = 1;
//		dist[i] = 0;
//	}
//}
//int find(int x) {
//	if (x != fa[x]) {
//		int tmp = fa[x];
//		fa[x] = find(tmp);
//		dist[x] += dist[tmp];
//	}
//	return fa[x];
//
//}
//void merge(int i, int j) {
//	int lf = find(i);
//	int rf = find(j);
//	if (lf == rf)return;
//	fa[lf] = rf;
//	dist[lf] += siz[rf];
//	siz[rf] += siz[lf];
//}
//int main() {
//	prepare();
//	int t;
//	cin >> t;
//	char op;
//	for (int i = 1,x,y; i <= t; i++) {
//		cin >> op>>x>>y;
//		if (op == 'M') {
//			merge(x, y);
//		}
//		else if (op == 'C') {
//			int fx = find(x);
//			int fy = find(y);
//			if (fx != fy) {
//				cout << -1 << '\n';
//			}
//			else {
//				cout << abs(dist[x] - dist[y])-1<<'\n';
//			}
//		}
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 45;
//int fa[N];
//double dist[N];
//void prepare() {
//    for (int i = 0; i < N; i++) {
//        fa[i] = i;
//        dist[i] = 1;
//    }
//}
//int find(int x) {
//    if (x != fa[x]) {
//        int tmp = fa[x];
//        fa[x] = find(tmp);
//        dist[x] *= dist[tmp];
//    }
//    return fa[x];
//}
//
//void merge(int x, int y, double v) {
//    int fx = find(x);
//    int fy = find(y);
//    if (fx == fy)return;
//    fa[fx] = fy;
//    dist[fx] = v * dist[y] / dist[x];
//}
//class Solution {
//public:
//    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//        prepare();
//        unordered_map<string, int>mp;
//        int cnt = 0;
//        for (int i = 0; i < equations.size(); i++) {
//            string a = equations[i][0];
//            string b = equations[i][1];
//            if (!mp.count(a)) {
//                mp[a] = ++cnt;
//            }
//            if (!mp.count(b)) {
//                mp[b] = ++cnt;
//            }
//            merge(mp[a], mp[b], values[i]);
//        }
//        vector<double> ans(queries.size());
//        for (int i = 0; i < queries.size(); i++) {
//            if (!mp.count(queries[i][0]) || !mp.count(queries[i][1])) {
//                ans[i] = -1;
//                continue;
//            }
//            int fx = find(mp[queries[i][0]]);
//            int fy = find(mp[queries[i][1]]);
//            if (fx != fy) {
//                ans[i] = -1;
//            }
//            else {
//                ans[i] = dist[mp[queries[i][0]]] / dist[mp[queries[i][1]]];
//            }
//        }
//        return ans;
//    }
//};


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 5e5 + 5;
//int n, k;
//int fa[N];
//int dist[N];//0表示与头是同类 1表示吃头 2表示被头吃
//
//int find(int x) {
//	if (x != fa[x]) {
//		int tmp = fa[x];
//		fa[x] = find(tmp);
//		dist[x] = (dist[x] + dist[tmp] + 3) % 3;
//	}
//	return fa[x];
//}
//
//bool merge(int x, int y,int v) {
//	if (x > n || y > n||v==1&&x==y)return false;
//	int fx = find(x);
//	int fy = find(y);
//	if (fx == fy) {
//		return ((dist[x] - dist[y] + 3) % 3) == v;
//	}
//	fa[fx] = fy;
//	dist[fx] = (v + dist[y] - dist[x] + 3) % 3;
//	return true;
//}
//void prepare() {
//	fa[0] = dist[0] = 0;
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//		dist[i] = 0;
//	}
//}
//int main() {
//	cin >> n >> k;
//	prepare();
//	int cnt = 0;
//	for (int i = 1,op,x,y; i <= k; i++) {
//		cin >> op>>x>>y;
//		op--;
//		if(!merge(x, y, op))cnt++;
//	}
//	cout << cnt << '\n';
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e4 + 5;
//int enemy[N];
//int fa[N];
//void prepare() {
//	for (int i = 1; i < N; i++) {
//		fa[i] = i;
//	}
//}
//int find(int x) {
//	if (x != fa[x]) {
//		fa[x] = find(fa[x]);
//	}
//	return fa[x];
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	prepare();
//	vector<array<int, 3>>a(m);
//	for (int i = 0; i < m; i++) {
//		cin >> a[i][0] >> a[i][1] >> a[i][2];
//	}
//	sort(a.begin(), a.end(), [&](auto x,auto y) {
//		return x[2] > y[2];
//		});
//	for (int i = 0; i < m; i++) {
//		int x = a[i][0], y = a[i][1];
//		int fx = find(x);
//		int fy = find(y);
//		if (fx == fy) {
//			cout << a[i][2] << '\n';
//			return 0;
//		}
//		if (enemy[x] == 0) {
//			enemy[x] = y;
//		}
//		else {
//			fa[fy] = find(enemy[x]);
//		}
//		if (enemy[y] == 0) {
//			enemy[y] = x;
//		}
//		else {
//			fa[fx] = find(enemy[y]);
//		}
//	}
//	cout << 0 << '\n';
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e3 + 5;
//int n,m;
//int fa[N];
//int enemy[N];
//void prepare() {
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//		enemy[i] = 0;
//	}
//}
//int find(int x) {
//	if (x != fa[x]) {
//		fa[x] = find(fa[x]);
//	}
//	return fa[x];
//}
//void merge(int x,int y) {
//	int fx = find(x);
//	int fy = find(y);
//	if (fx == fy)return;
//	fa[fx] = fy;
//}
//int main() {
//	cin >> n >> m;
//	prepare();
//	char op;
//	for (int i = 1,p,q; i <= m; i++) {
//		cin >> op >> p >> q;
//		if (op == 'F') {
//			merge(p, q);
//		}
//		else {
//			if (enemy[p] == 0) {
//				enemy[p] = q;
//			}
//			else {
//				merge(q, enemy[p]);
//			}
//			if (enemy[q] == 0) {
//				enemy[q] = p;
//			}
//			else {
//				merge(p, enemy[q]);
//			}
//		}
//	}
//	int cnt = 0;
//	for (int i = 1; i <= n; i++) {
//		if (fa[i] == i) {
//			cnt++;
//		}
//	}
//	cout << cnt << '\n';
//}