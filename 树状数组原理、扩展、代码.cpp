//一般用来维护可差分信息
//树状数组模板1 范围和查询与单点修改
//#include<bits/stdc++.h>
//using namespace std;
//int n,m;
//vector<int>a;
//int lowbit(int i) {
//	return i & (-i);
//}
//void add(int i, int num) {
//	while (i <= n) {
//		a[i] += num;
//		i += lowbit(i);
//	}
//}
//int sum(int i) {
//	int ans = 0;
//	while (i > 0) {
//		ans += a[i];
//		i -= lowbit(i);
//	}
//	return ans;
//}
//int range(int i, int j) {
//	return sum(j) - sum(i - 1);
//}
//int main() {
//	cin >> n >> m;
//	a.resize(n+2,0);
//	for (int i = 1,u; i <= n; i++) {
//		cin >> u;
//		add(i,u);
//	}
//	for (int i = 0,a,x,y; i < m; i++) {
//		cin >> a >> x >> y;
//		if (a == 1) {
//			add(x, y);
//		}
//		else {
//			cout << range(x, y)<<endl;
//		}
//	}
//}


//树状数组模板2 范围增加与单点查询
//#include<bits/stdc++.h>
//using namespace std;
//int n, m;
//vector<int>a;
//int lowbit(int i) {
//	return i & (-i);
//}
//void add(int i, int num) {
//	while (i <= n) {
//		a[i] += num;
//		i += lowbit(i);
//	}
//}
//int sum(int i) {
//	int ans = 0;
//	while (i > 0) {
//		ans += a[i];
//		i -= lowbit(i);
//	}
//	return ans;
//}
//int range(int l, int r) {
//	return sum(r) - sum(l - 1);
//}
//int main() {
//	cin >> n >> m;
//	a.resize(n + 1, 0);
//	for (int i = 1,u; i <= n; i++) {
//		cin >> u;
//		add(i, u);
//		add(i + 1, -u);
//	}
//	for (int i = 0,o; i < m; i++) {
//		cin >> o;
//		if (o == 1) {
//			int x, y, k;
//			cin >> x >> y >> k;
//			add(x, k);
//			add(y + 1, -k);
//		}
//		else {
//			int x;
//			cin >> x;
//			cout << sum(x) << endl;
//		}
//	}
//}


//树状数组模板3 范围增加与范围查询
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n, m;
//vector<int>d;
//vector<int>d1;
//int lowbit(int i) {
//	return  i & (-i);
//}
//void add(vector<int>& a, int i, int num) {
//	while (i <= n) {
//		a[i] += num;
//		i += lowbit(i);
//	}
//}
//int sum(vector<int>& a, int i) {
//	int ans = 0;
//	while (i > 0) {
//		ans += a[i];
//		i -= lowbit(i);
//	}
//	return ans;
//}
//int range(int l, int r) {
//	return sum(d,r)*r - sum(d1,r)-sum(d,l-1)*(l-1)+sum(d1,l-1);//sum(d,r)*r-sum(d1,r)为原始数组中1-r上累加和,是由公式推导出来的
//}
//void tadd(int l,int r,int num) {
//	add(d, l, num);
//	add(d, r + 1, -num);
//	add(d1, l, (l - 1) * num);
//	add(d1, r + 1, -(r)*num);
//}
//signed main() {
//	cin >> n >> m;
//	d.resize(n + 1);
//	d1.resize(n + 1);
//	for (int i = 1,u; i <= n; i++) {
//		cin >> u;
//		tadd(i, i, u);
//	}
//	for (int i = 0,o; i < m; i++) {
//		cin >> o;
//		if (o == 1) {
//			int l, r, v;
//			cin >> l >> r >> v;
//			tadd(l, r, v);
//		}
//		else {
//			int x, y;
//			cin >> x >> y;
//			cout << range(x, y) << endl;
//		}
//	}
//}


//二维数组维护单点更新与范围和
//#include<bits/stdc++.h>
//using namespace std;
//int n, m;
//vector<vector<int>>a;
//int lowbit(int i) {
//	return i & (-i);
//}
//void add(int x, int y, int num) {
//	for (int i = x; i <= n; i += lowbit(i)) {
//		for (int j = y; j <= m; j += lowbit(j)) {
//			a[i][j] += num;
//		}
//	}
//}
//int sum(int x, int y) {
//	int ans = 0;
//	for (int i = x; i > 0; i -= lowbit(i)) {
//		for (int j = y; j > 0; j -= lowbit(j)) {
//			ans += a[i][j];
//		}
//	}
//	return ans;
//}
//void update(int x, int y, int d) {
//	add(x, y, d-a[x][y]);
//	a[x][y] = d;
//}
//int sumRegion(int a, int b, int c, int d) {
//	return sum(c, d) - sum(c, b - 1) - sum(a - 1, d) + sum(a - 1, b - 1);
//}


//二维数组维护范围更新与范围和
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 2050;
//int n, m;
//int a1[MAXN][MAXN], a2[MAXN][MAXN], a3[MAXN][MAXN], a4[MAXN][MAXN];
//int lowbit(int i) {
//	return i & (-i);
//}
//void add(int x,int y,int v) {
//	for (int i = x; i <= n; i += lowbit(i)) {
//		for (int j = y; j <= m; j += lowbit(j)) {
//			a1[i][j] += v;
//			a2[i][j] += x * v;
//			a3[i][j] += y * v;
//			a4[i][j] += x * y * v;
//		}
//	}
//}
//void add(int a, int b, int c, int d, int v) {
//	add(a, b, v);
//	add(a, d+ 1, -v);
//	add(c + 1, b, -v);
//	add(c + 1, d + 1, v);
//}
//int sum(int a, int b) {
//	int ans = 0;
//	for (int i = a; i > 0; i -= lowbit(i)) {
//		for (int j = b; j > 0; j -= lowbit(j)) {
//			ans += (a + 1) * (b + 1) * a1[i][j] - (b + 1) * a2[i][j] - (a + 1) * a3[i][j] + a4[i][j];
//		}
//	}
//	return ans;
//}
//int range(int a, int b, int c, int d) {
//	return sum(c, d) + sum(a - 1, b - 1) - sum(c, b - 1) - sum(a - 1, d);
//}
//int main() {
//	char op;
//    int a, b, c, d, v;
//    scanf("%s", &op);
//    scanf("%d%d", &n, &m);
//    while (scanf("%s", &op) != EOF) {
//        if (op == 'X') {
//            scanf("%d%d", &n, &m);
//        } else if (op == 'L') {
//            scanf("%d%d%d%d%d", &a, &b, &c, &d, &v);
//            add(a, b, c, d, v);
//        } else {
//            scanf("%d%d%d%d", &a, &b, &c, &d);
//            printf("%d\n", range(a, b, c, d));
//        }
//    }
//    return 0;
//}