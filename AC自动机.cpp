//AC自动机模板
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 2e5 + 10;
//int ed[MAXN];//编号为i的字符串的结尾编号
//int tree[MAXN][26];//前缀树
//int fail[MAXN];//当前结点不匹配去往哪个结点开始匹配
//int box[MAXN];//一个辅助容器
//int times[MAXN];//记录当前节点到达过几次
//int cnt = 0;
//void insert(string s, int i) {
//	int u = 0;
//	for (int j = 0,c; j < s.size(); j++) {
//		c = s[j] - 'a';
//		if (tree[u][c] == 0) {
//			tree[u][c] = ++cnt;
//		}
//		u = tree[u][c];
//	}
//	ed[i] = u;
//}
//void setFail() {
//	int l=0, r=0;
//	for (int i = 0; i < 26; i++) {//把前缀树的第一层加入队列
//		if (tree[0][i] != 0) {
//			box[r++] = tree[0][i];
//		}
//	}
//	while (l < r) {//一个bfs设置fail指针的过程
//		int u = box[l++];
//		for (int i = 0; i < 26; i++) {
//			if (tree[u][i] == 0) {//该情况说明如果匹配到u结点且下一个要匹配i字符失败时
//				tree[u][i] = tree[fail[u]][i];//fail[u]指向与u结点代表字母相同且前缀能配上u所在字符串后缀的最长结点，该节点后续配字符i应该去哪配,这里有类似于动态规划的转移,避免了绕圈			}
//			}
//			else {
//				fail[tree[u][i]] = tree[fail[u]][i];//如果接下来还能匹配,fail[u]到达能匹配上u的最长前缀,从该节点出发看看如果接下来要匹配i应该去往哪，从而为i找到能匹配上的最长前缀,也有动态规划的转移过程
//				box[r++] = tree[u][i];//有节点记得入队列
//			}
//		}
//	}
//}
//
//int nex[MAXN];
//int to[MAXN];
//int head[MAXN];
//int cntg = 1;
//void addEdge(int u, int v) {
//	nex[cntg] = head[u];
//	to[cntg] = v;
//	head[u] = cntg++;
//}
//void dfs(int i) {
//	for (int ui = head[i]; ui != 0; ui = nex[ui]) {
//		dfs(to[ui]);
//		times[i] += times[to[ui]];
//	}
//}
//int main() {
//	int n;
//	cin >> n;
//	string t,s;
//	for (int i = 1; i <= n; i++) {
//		cin >> t;
//		insert(t, i);
//	}
//	setFail();
//	cin >> s;
//	for (int u = 0, i = 0; i < s.size(); i++) {
//		u = tree[u][s[i] - 'a'];
//		times[u]++;
//	}
//	for (int i = 1; i <= cnt; i++) {
//		addEdge(fail[i], i);
//	}
//	dfs(0);
//	for (int i = 1; i <= n; i++) {
//		cout << times[ed[i]] << "\n";
//	}
//}


//数数
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 1e9 + 7;
//const int MAXM = 1500;
//const int MAXS = 2000;
//string n;
//int len;
//int m;
//int tree[MAXS][10];
//int fail[MAXS];
//bool alert[MAXS];
//int box[MAXS];
//int ed[MAXM];
//int cnt = 0;
//void insert(string s, int i) {
//	int u = 0;
//	for (int i = 0; i < s.size(); i++) {
//		int c = s[i] - '0';
//		if (tree[u][c] == 0) {
//			tree[u][c] = ++cnt;
//		}
//		u = tree[u][c];
//	}
//	ed[i] = u;
//	alert[u] = 1;
//}
//void setFail() {
//	int l = 0, r = 0;
//	for (int i = 0; i < 10; i++) {
//		if (tree[0][i] != 0) {
//			box[r++] = tree[0][i];
//		}
//	}
//	while (l < r) {
//		int u = box[l++];
//		for (int i = 0; i < 10; i++) {
//			if (tree[u][i] == 0) {
//				tree[u][i] = tree[fail[u]][i];
//			}
//			else {
//				fail[tree[u][i]] = tree[fail[u]][i];
//				box[r++] = tree[u][i];
//			}
//			alert[u] |= alert[fail[u]];
//		}
//	}
//}
//int dp[1300][2][2][2000];
//int f(int i, int free,int fix,int k) {//当前来到i位置,是否可以自由选择,在前缀树上来到k节点
//	if (alert[k])return 0;
//	if (i == len)return fix;
//	if (dp[i][free][fix][k] != -1)return dp[i][free][fix][k];
//	int ans = 0;
//	int cur = n[i] - '0';
//	if (!fix) {
//		ans = (ans + f(i + 1, 1, 0, k))%mod;
//	}
//	if (free) {
//		for (int j = fix ? 0 : 1; j < 10; j++) {
//			ans = (ans + f(i + 1, 1, 1, tree[k][j]))%mod;
//		}
//	}
//	else {
//		for (int j = fix ? 0 : 1; j < cur; j++) {
//			ans = (ans + f(i + 1, 1, 1, tree[k][j]))%mod;
//		}
//		ans = (ans + f(i + 1, 0, 1, tree[k][cur]))%mod;
//	}
//	dp[i][free][fix][k] = ans;
//	return ans;
//}
//signed main() {
//	cin >> n;
//	cin >> m;
//	string s;
//	len = n.size();
//	for (int i = 1; i <= m; i++) {
//		cin >> s;
//		insert(s, i);
//	}
//	setFail();
//	memset(dp, -1, sizeof(dp));
//	cout << f(0, 0, 0, 0) << endl;
//}