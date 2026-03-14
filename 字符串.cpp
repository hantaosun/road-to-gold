//kmp
//#include<bits/stdc++.h>
//using namespace std;
//int nex[1000005];
//void getNex(string t) {
//	nex[0] = -1;
//	if (t.size() == 1)return;
//	nex[1] = 0;
//	int i = 2, cn = 0;
//	while (i < t.size()) {
//		if (t[i - 1] == t[cn]) {
//			nex[i++] = ++cn;
//		}
//		else if (cn > 0) {
//			cn = nex[cn];
//		}
//		else {
//			nex[i++] = 0;
//		}
//	}
//}
//bool kmp(string s, string t) {
//	int n = s.size(), m = t.size();
//	int i = 0, j = 0;
//	while (i < n && j < m) {
//		if (s[i] == t[j]) {
//			i++;
//			j++;
//		}
//		else if (j == 0) {//完全配不出来
//			i++;
//		}
//		else {
//			j = nex[j];
//		}
//	}
//	return j == m;
//}
//char chg(int a) {
//	switch (a) {
//	case 10:return 'A';
//	case 11:return 'B';
//	case 12:return 'C';
//	case 13:return 'D';
//	case 14:return 'E';
//	case 15:return 'F';
//	}
//	return '$';
//}
//string get(int n, int k) {
//	string s = "";
//	stack<int>stack;
//	for (int i = 0; i <= n; i++) {
//		if (i < k) {
//			s.append(to_string(i));
//		}
//		else {
//			int t = i;
//			while (t != 0) {
//				stack.push(t % k);
//				t /= k;
//			}
//			while (!stack.empty()) {
//				if (stack.top() >= 10) {
//					s += chg(stack.top());
//				}
//				else {
//					s.append(to_string(stack.top()));
//				}
//				stack.pop();
//			}
//		}
//	}
//	return s;
//}
//int main() {
//	int n;
//	cin >> n;
//	string t;
//	cin >> t;
//	getNex(t);
//	for (int k = 2; k <= 16; k++) {
//		string s = get(n, k);
//		if (kmp(s, t)) {
//			cout << "yes\n";
//			return 0;
//		}
//	}
//	cout << "no\n";
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
////10
////8 4 7
////1 3 7 8 7 9 10 2
////7 5 1 0
//int nex[200005];//当前位置配不上去哪配
////void getNex(vector<int>&b) {//从1下标开始生成
////	nex[1] = 0;
////	int i = 2, cn = 0;
////	while (i < b.size()) {
////		if (b[i-1] == b[cn]) {
////			nex[i++] = ++cn;
////		}
////		else if(cn>1){
////			cn = nex[cn];
////		}
////		else {
////			nex[i++] = 1;
////		}
////	}
////}
////int kmp(vector<int>&a,vector<int>&b) {
////	int n = a.size(), m = b.size();
////	int i = 1, j = 1;
////	int cnt = 0;
////	while (i < n&&j<m) {
////		if (a[i] == b[j]) {
////			i++;
////			j++;
////		}
////		else if (j==1) {
////			i++;
////		}
////		else {
////			j = nex[j];
////		}
////		if (j == m) {
////			j = nex[j];
////			cnt++;
////		}
////	}
////	return cnt;
////}
//void getNex(vector<int>& b) {
//    int m = b.size() - 1; // 有效长度：b[1]到b[m]（因b[0]无效）
//    if (m == 0) return;   // 空串处理
//
//    nex[1] = 0;           // 第一个有效字符无前缀
//    int cn = 0;           // 当前最长前缀长度（对应b[1..cn]）
//
//    for (int i = 2; i <= m; ++i) { // 处理b[2]到b[m]
//        // 回退：找最长前缀使得b[i]与前缀末尾匹配
//        while (cn > 0 && b[i] != b[cn + 1]) {
//            cn = nex[cn];
//        }
//        // 匹配则前缀长度+1
//        if (b[i] == b[cn + 1]) {
//            cn++;
//        }
//        nex[i] = cn;
//    }
//}
//
//// a和b从1开始匹配（a[0]、b[0]无效），返回匹配次数
//int kmp(vector<int>& a, vector<int>& b) {
//    int n = a.size() - 1; // a的有效长度：a[1]到a[n]
//    int m = b.size() - 1; // b的有效长度：b[1]到b[m]
//    if (m == 0 || n < m) return 0;
//
//    getNex(b);
//    int cnt = 0;
//    int j = 0; // 已匹配的前缀长度（对应b[1..j]）
//
//    for (int i = 1; i <= n; ++i) { // 遍历a的有效元素
//        // 不匹配时回退
//        while (j > 0 && a[i] != b[j + 1]) {
//            j = nex[j];
//        }
//        // 匹配则增加已匹配长度
//        if (a[i] == b[j + 1]) {
//            j++;
//        }
//        // 完全匹配时计数并回退
//        if (j == m) {
//            cnt++;
//            j = nex[j];
//        }
//    }
//    return cnt;
//}
//void solve() {
//	int n,m,k;
//	cin >> n >> m >> k;
//	vector<int>a(n);
//	vector<int>b(m);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		a[i] %= k;
//	}
//	for (int i = 0; i < m; i++) {
//		cin >> b[i];
//		b[i] = b[i] % k;
//	}
//	for (int i = m-1; i >=1; i--) {
//		b[i] = ((b[i - 1] - b[i]) % k + k)%k;
//	}
//	for (int i = n-1; i >= 1; i--) {
//		a[i] = ((a[i] - a[i-1]) % k + k)%k;
//	}
//	//for (int i = 1; i < n; i++) {
//	//	cout << a[i] << " ";
//	//}cout << '\n';
//	//for (int j = 1; j < m; j++) {
//	//	cout << b[j] << " ";
//	//}cout << '\n';
//	getNex(b);
//	//for (int i = 1; i < b.size(); i++) {
//	//	cout << nex[i] << " ";
//	//}cout << '\n';
//	cout << kmp(a, b)<<'\n';
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int nex[2000005];
//const int mod = 998244353;
//void getNex(string t) {
//	nex[0] = -1;
//	nex[1] = 0;
//	int i = 2, cn = 0;
//	while (i <= t.size()) {//注意统计子串数量时由于要跳回来,务必要计算t.size()的nex值
//		if (t[i - 1] == t[cn]) {
//			nex[i++] = ++cn;
//		}
//		else if (cn > 0) {
//			cn = nex[cn];
//		}
//		else {
//			nex[i++] = 0;
//		}
//	}
//}
//int kmp(string t, string s) {
//	int n = s.size(), m = t.size();
//	int x = 0, y = 0;
//	int ans = 0;
//	while (x < m && y < n) {
//		if (t[x] == s[y]) {
//			x++;
//			y++;
//		}
//		else if (x > 0) {
//			x = nex[x];
//		}
//		else {
//			y++;
//		}
//		if (x == m) {
//			x = nex[x];
//			ans++;
//		}
//	}
//	return ans;
//}
//signed main() {
//	int n;
//	cin >> n;
//	vector<string>a;
//	int msize = INT_MAX;
//	string ms;
//	string s;
//	for (int i = 0; i < n; i++) {
//		cin >> s;
//		a.push_back(s);
//		if (s.size() < msize) {
//			msize = s.size();
//			ms = s;
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		if (a[i].size() == msize && a[i] != ms) {
//			for (int i = 0; i < n; i++) {
//				cout << 0 << '\n';
//			}
//			return 0;
//		}
//	}
//	getNex(ms);
//	int ans = 1;
//	for (int i = 0; i < n; i++) {
//		ans = ans % mod * kmp(ms, a[i]) % mod;
//	}
//	for (int i = 0; i < n; i++) {
//		if (a[i].size() != msize) {
//			cout << 0 << '\n';
//		}
//		else {
//			cout << ans << '\n';
//		}
//	}
//}



//前缀树
//#include<bits/stdc++.h>
//using namespace std;
//const int d = 10000;
//int main() {
//	int n;
//	cin >> n;
//	vector<int>a(n+1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	vector<vector<int>>dp(n+1, vector<int>(20001));
//	dp[0][d] = true;
//	for (int i = 1; i <= n; i++) {
//		int w = a[i];
//		for (int j = 0; j <= 20000; j++) {
//			dp[i][j] = dp[i - 1][j];
//			if(j+w<=20000)
//			dp[i][j] |= dp[i - 1][j + w];
//			if (j - w >= 0)
//			dp[i][j] |= dp[i - 1][j - w];
//		}
//	}
//	int m; cin >> m;
//	int k;
//	while (m--) {
//		cin >> k;
//		if (k > 10000) {
//			cout << "NO\n";
//			continue;
//		}
//		cout << (dp[n][k+d] ? "YES\n" : "NO\n");
//	}
//
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e6 + 5;
//int tried[N][26];
//int paval[N];
//int pass[N];
//int edval[N];
//int ed[N];
//int lzt[N];
//int cnt = 1;
//void lazy(int i, int v) {
//	//cout << "lazy:" << i << " " << v << '\n';
//	paval[i] += v * pass[i];
//	edval[i] += v * ed[i];
//	lzt[i] += v;
//}
//void down(int cur) {
//	if (lzt[cur] != 0) {
//		for (int i = 0; i < 26; i++) {
//			int to = tried[cur][i];
//			if (to != 0) {
//				lazy(to, lzt[cur]);
//			}
//		}
//		lzt[cur] = 0;
//	}
//}
//void insert(string name, int val) {
//	int cur = 1;
//	for (int i = 0; i < name.size(); i++) {
//		down(cur);
//		int c = name[i] - 'a';
//		paval[cur] += val;
//		pass[cur]++;
//		if (tried[cur][c] == 0) {
//			tried[cur][c] = ++cnt;
//		}
//		cur = tried[cur][c];
//	}
//	paval[cur] += val;
//	pass[cur]++;
//	edval[cur] += val;
//	ed[cur]++;
//}
//int queryPre(string prefix) {
//	int cur = 1;
//	for (int i = 0; i < prefix.size(); i++) {
//		int c = prefix[i] - 'a';
//		down(cur);
//		if (tried[cur][c] == 0) return 0;
//		cur = tried[cur][c];
//	}
//	return paval[cur];
//}
//int queryName(string name) {
//	int cur = 1;
//	for (int i = 0; i < name.size(); i++) {
//		int c = name[i] - 'a';
//		down(cur);
//		if (tried[cur][c] == 0)return 0;
//		cur = tried[cur][c];
//	}
//	return edval[cur];
//}
////bool check(string name) {
////	int cur = 1;
////	for (int i = 0; i < name.size(); i++) {
////		int c = name[i] - 'a';
////		if (tried[cur][c] == 0)return false;
////		cur = tried[cur][c];
////	}
////	return true;
////}
//void change(string prefix, int d) {
//	//if (!check(prefix))return;
//	int cur = 1;
//	int num = 0;//前缀为prefix的num数量
//	for (int i = 0; i < prefix.size(); i++) {
//		int c = prefix[i] - 'a';
//		down(cur);
//		if (tried[cur][c] == 0) { return; }
//		cur = tried[cur][c];
//	}
//	num = pass[cur];
//	cur = 1;
//	for (int i = 0; i < prefix.size(); i++) {
//		int c = prefix[i] - 'a';
//		paval[cur] += d * num;
//		down(cur);
//		if (tried[cur][c] == 0) { return; }
//		cur = tried[cur][c];
//	}
//	lazy(cur, d);
//}
//signed main() {
//	int n;
//	cin >> n;
//	string s, p;
//	for (int i = 1, o, a, d; i <= n; i++) {
//		//{
//		//	cout << "paval: ";
//		//	for (int i = 1; i <= 10; i++) {
//		//		cout << paval[i] << ' ';
//		//	}cout << '\n';
//		//	cout << "pass: ";
//		//	for (int i = 1; i <= 10; i++) {
//		//		cout << pass[i] << ' ';
//		//	}cout << '\n';
//		//	cout << "edval: ";
//		//	for (int i = 1; i <= 10; i++) {
//		//		cout << edval[i] << ' ';
//		//	}cout << '\n';
//		//	cout << "ed: ";
//		//	for (int i = 1; i <= 10; i++) {
//		//		cout << ed[i] << ' ';
//		//	}cout << '\n';
//		//	cout << "---------\n";
//		//}
//		cin >> o;
//		switch (o) {
//		case 1: {
//			cin >> s >> a;
//			insert(s, a);
//			break;
//		}
//		case 2: {
//			cin >> p >> d;
//			change(p, d);
//			break;
//		}
//		case 3: {
//			cin >> s;
//			cout << queryName(s) << '\n';
//			break;
//		}
//		case 4: {
//			cin >> p;
//			cout << queryPre(p) << '\n';
//			break;
//		}
//		}
//	}
//}



//AC自动机
//模板回顾
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int ed[N];//当前编号的字符串结尾在前缀树上在哪个位置
//int tree[N][26];
//int fail[N];//当前结点匹配不上去哪
//int cnt = 0;
//int box[N];//辅助容器(队列)
//int times[N];//计数
//int l, r;
//void insert(int id, string s) {
//	int cur = 0;//注意,字典树一般用一号结点开始,但因为数组默认是0,从0号结点开始更方便
//	//即任何字符初始时不匹配都可以回到根节点重新开始匹配,0节点可以认为是空串
//	for (int i = 0; i < s.size(); i++) {
//		int c = s[i] - 'a';
//		if (tree[cur][c] == 0) {
//			tree[cur][c] = ++cnt;
//		}
//		cur = tree[cur][c];
//	}
//	ed[id] = cur;
//}
//void setFail(){
//	l = 0, r = 0;
//	for (int i = 0; i < 26; i++) {//第一层结点入队列
//		if (tree[0][i] != 0) {
//			box[r++] = tree[0][i];
//		}
//	}
//	while (l < r) {
//		int u = box[l++];
//		for (int i = 0; i < 26; i++) {
//			if (tree[u][i] == 0) {//注意fail[u]代表的字符一定与u代表的字符一样
//				tree[u][i] = tree[fail[u]][i];
//			}//设置直通表和fail指针都要去往与自己代表字符相同的节点
//			else {
//				fail[tree[u][i]] = tree[fail[u]][i];
//				box[r++] = tree[u][i];
//			}
//		}
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n;
//	string t;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> t;
//		insert(i, t);
//	}
//	setFail();
//	string s;
//	cin >> s;
//	for (int i = 0,u=0; i < s.size(); i++) {
//		u = tree[u][s[i]-'a'];
//		times[u]++;
//	}
//	l = r = 0;
//	vector<int>ide(cnt+1,0);
//	for (int i = 0; i <=cnt; i++) {
//		ide[fail[i]]++;
//	}
//	for (int i = 0; i <=cnt; i++) {
//		if (ide[i] == 0) {
//			box[r++] = i;
//		}
//	}
//	while (l < r) {
//		int u = box[l++];
//		times[fail[u]] += times[u];
//		if (--ide[fail[u]] == 0) {
//			box[r++] = fail[u];
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		cout << times[ed[i]] << '\n';
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//constexpr int N = 1e6 + 5;
//
//struct AC {
//	struct Node {
//		int son[26];
//		int fail;
//		int len;//如果是某个字符串结尾则为其长度否则为0
//		int idx;//如果是某个字符串的结尾则为其编号否则为0
//		void init() {
//			memset(son, 0, sizeof(son));
//			idx = len = 0;
//			//fail = 0;
//		}
//	}tree[N];
//	int cnt = 0;
//	void init() {
//		for (int i = 0; i <= cnt; i++) {
//			tree[i].init();
//		}
//		cnt = 0;
//	}
//	void insert(string&s, int id) {
//		int cur = 0;
//		for (int i = 0; i < int(s.size()); i++) {
//			int c = s[i] - 'a';
//			if (tree[cur].son[c] == 0) {
//				tree[cur].son[c] = ++cnt;
//				tree[tree[cur].son[c]].init();
//			}
//			cur = tree[cur].son[c];
//		}
//		tree[cur].len = s.size();
//		tree[cur].idx = id;
//	}
//	void setFail() {
//		queue<int>q;
//		for (int i = 0; i < 26; i++) {
//			if (tree[0].son[i] != 0) {
//				q.push(tree[0].son[i]);
//			}
//		}
//		while (!q.empty()) {
//			int u = q.front();
//			q.pop();
//			for (int i = 0; i < 26; i++) {
//				if (tree[u].son[i] == 0) {
//					tree[u].son[i] = tree[tree[u].fail].son[i];
//				}
//				else {
//					tree[tree[u].son[i]].fail = tree[tree[u].fail].son[i];
//					q.push(tree[u].son[i]);
//				}
//			}
//		}
//	}
//	vector<vector<int>> getPos(const string& t, int num_pattern) {
//		vector<vector<int>> pos(num_pattern + 1);
//		int u = 0, res = 0;
//		for (int i = 0; i < (int)t.length(); i++) {
//			u = tree[u].son[t[i] - 'a'];
//			for (int j = u; j; j = tree[j].fail) {
//				if (tree[j].idx) {
//					pos[tree[j].idx].emplace_back(i - tree[j].len + 1);
//					res++;
//				}
//			}
//		}
//		return pos;
//	}
//
//	int querycnt(const string& t) {
//		int u = 0, res = 0;
//		for (int i = 0; i < (int)t.length(); i++) {
//			u = tree[u].son[t[i] - 'a'];
//			for (int j = u; j; j = tree[j].fail) {
//				if (tree[j].idx) {
//					res++;
//				}
//			}
//		}
//		return res;
//	}
//	//vector<vector<int>> getPos(string&s,int n) {
//	//	vector<vector<int>>ans(n);
//	//	for (int i = 0,u=0; i < s.size(); i++) {
//	//		u = tree[u].son[s[i] - 'a'];
//	//		if (tree[u].idx != 0) {
//	//			ans[tree[u].idx].push_back(i - tree[u].len+1);
//	//		}
//	//	}
//	//	return ans;
//	//}
//	//
//	//
//	//int querycnt(string s) {//统计该串中匹配上了多少子串
//	//	int u = 0, ans = 0;
//	//	for (int i = 0; i < int(s.size()); i++) {//由于去包含了不需要绕fail指针了
//	//		u = tree[i].son[s[i] - 'a'];
//	//		if (tree[u].idx != 0) {
//	//			ans++;
//	//		}
//	//	}
//	//	return ans;
//	//}
//	
//	vector<int> collect(int u=0) {//收集是极小前后缀的字符串的编号
//		queue<int>q;
//		vector<int>res;
//		q.push(u);
//		while (!q.empty()) {
//			int u = q.front();
//			q.pop();
//			if (tree[u].idx != 0) {
//				res.emplace_back(tree[u].idx);
//				continue;
//			}
//			for (int i = 0; i < 26; i++) {
//				if (tree[u].son[i] != 0) {
//					q.push(tree[u].son[i]);
//				}
//			}
//		}
//		return res;
//	}
//}preA,sufA;
////void Debug(string s) {
////	cout << s << '\n';
////}
//string pre[N], suf[N];
//void solve() {
//	int l, r;
//	string S;
//	cin >> l >> r;
//	//0下标不用
//	for (int i = 1; i <= l; i++) {
//		cin >> pre[i];
//	}
//	for (int i = 1; i <= r; i++) {
//		cin >> suf[i];
//	}
//	cin >> S;
//
//	//---------
//
//	preA.init();
//	sufA.init();
//	for (int i = 1; i <= l; i++) {
//		preA.insert(pre[i],i);
//	}
//	for (int i = 1; i <= l; i++) {
//		reverse(suf[i].begin(), suf[i].end());
//		sufA.insert(suf[i],i);
//	}
//	
//	//仅去重无需setFail
//	vector<int>upre = preA.collect();
//	vector<int>usuf = sufA.collect();
//	
//	//--------
//	
//	preA.init();
//	sufA.init();
//	for (int i = 0; i < upre.size(); i++) {
//		preA.insert(pre[upre[i]], upre[i]);
//	}
//	for (int i = 0; i < usuf.size(); i++) {
//		reverse(suf[usuf[i]].begin(), suf[usuf[i]].end());
//		sufA.insert(suf[usuf[i]], usuf[i]);
//	}
//
//	//{
//	//	cout << "-------------\n";
//	//	for (int i = 0; i < upre.size(); i++) {
//	//		cout << pre[upre[i]] << '\n';
//	//	}
//	//	cout << "\n";
//	//	for (int i = 0; i < usuf.size(); i++) {
//	//		cout << suf[usuf[i]] << '\n';
//	//	}
//	//	cout << "--------------\n";
//	//}
//
//
//
//
//	preA.setFail();
//	sufA.setFail();
//	vector<vector<int>>pA = preA.getPos(S,l+1);
//	vector<vector<int>>sA = sufA.getPos(S, r+1);
//	vector<int>sum(S.size() + 1,0);//记录当前位置往后有多少后缀串
//	
//	//{
//	//	for (int i = 1; i < pA.size(); i++) {
//	//		cout << pre[i] << '\n';
//	//		for (auto v : pA[i]) {
//	//			cout << v << " **";
//	//		}
//	//		cout << '\n';
//	//	}
//	//	for (int i = 1; i < sA.size(); i++) {
//	//		cout << suf[i] << '\n';
//	//		for (auto v : sA[i]) {
//	//			cout << v << " **";
//	//		}
//	//		cout << '\n';
//	//	}
//	//
//	//}
//
//
//	for (int i = 0; i < usuf.size(); i++) {
//		int id = usuf[i];
//		for (int j = 0; j < sA[id].size(); j++) {
//			sum[sA[id][j]]++;
//		}
//	}
//	for (int i = S.size() - 1; i > 0; i--) {
//		sum[i-1] += sum[i];
//	}
//	long long ans = 0;
//	for (int i = 0; i < upre.size(); i++) {
//		int id = upre[i];
//		for (int j = 0; j < pA[id].size(); j++) {
//			ans += sum[pA[id][j]];
//		}
//		auto inner = sufA.querycnt(pre[id].substr(0, pre[id].size() - 1));
//		ans -= inner * pA[id].size();
//	}
//	cout << ans << '\n';
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 998244353;
//const int N = 100;
//int fail[N];
//int id[N];
//int tree[N][26];
//int box[N];
//int l, r;
//int cnt = 0;
//void insert(string s,int i) {
//	int cur = 0;
//	for (int i = 0; i < s.size(); i++) {
//		int c = s[i] - 'a';
//		if (tree[cur][c] == 0) {
//			tree[cur][c] = ++cnt;
//		}
//		cur = tree[cur][c];
//	}
//	id[cur] = i;
//}
//void setFail() {
//	l = r = 0;
//	for (int i = 0; i < 26; i++) {
//		if (tree[0][i] != 0) {
//			box[r++] = tree[0][i];
//		}
//	}
//	while (l < r) {
//		int u = box[l++];
//		for (int i = 0; i < 26; i++) {
//			if (tree[u][i] == 0) {
//				tree[u][i] = tree[fail[u]][i];
//			}
//			else {
//				fail[tree[u][i]] = tree[fail[u]][i];
//				box[r++] = tree[u][i];
//			}
//		}
//	}
//}
////当前来到第几个字符,目前字符串匹配情况,在自动机上的哪个节点
//int mask;
//int n, L;
//int dp[105][(1 << 9) + 5][105];
//int f(int cur, int s, int u) {
//	if (dp[cur][s][u] != -1)return dp[cur][s][u];
//	for (int j = u; j; j = fail[j]) {
//		if (id[j] != 0) {
//			s |= 1ll << id[j];
//		}
//	}
//	if (cur == L) {
//		return s == mask;
//	}
//	int ans = 0;
//
//	for (int i = 0; i < 26; i++) {
//		ans = (ans + f(cur+1, s, tree[u][i])) % mod;
//	}
//	return dp[cur][s][u]=ans;
//}
//signed main() {
//	memset(dp, -1, sizeof(dp));
//	cin >> n >> L;
//	mask = ((1ll << n) - 1) << 1;
//	vector<string>a(n+1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		insert(a[i],i);
//	}
//	setFail();
//	cout << f(0, 0, 0)<<'\n';
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1201;
//string s;
//void manacherss(string ss) {
//	int n = 2 * ss.size() + 1;
//	s.resize(n);
//	for (int i = 0, j = 0; i < n; i++) {
//		if (i & 1)s[i] = ss[j++];
//		else {
//			s[i] = '#';
//		}
//	}
//}
//int p[N];
//int manacher(string ss) {
//	manacherss(ss);
//	int ans = -1;
//	int n = 2 * ss.size() + 1;
//	for (int i = 0, c = 0, r = 1,len; i < n; i++) {
//		len = r > i ?min(r-i,p[2*c-i]) : 1;
//		while (i + len < n && i - len >= 0&&s[i+len]==s[i-len]) {
//			len++;
//		}
//		p[i] = len;
//		ans = max(ans, len);
//		if (i + len > r) {
//			r = i + len;
//			c = i;
//		}
//	}
//	return ans-1;
//}
//int main() {
//	string sss;
//	while (cin >> sss) {
//		cout << manacher(sss) << '\n';
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 4;
//string a;
//string b;
//int pA[N];
//int pB[N];
//int amax;
//int bmax;
//void manacher() {
//	int n = a.size();
//	amax = -1;
//	bmax = -1;
//	for (int i = 0, c = 0, r = 1, len; i < n; i++) {
//		len = r > i ? min(r - i, pA[2 * c - i]) : 1;
//		while (i + len < n && i - len >= 0 && a[i + len] == a[i - len]) {
//			len++;
//		}
//		amax = max(amax, len);
//		pA[i] = len;
//		if (i + len > r) {
//			r = i + len;
//			c = i;
//		}
//	}
//	for (int i = 0, c = 0, r = 1, len; i < n; i++) {
//		len = r > i ? min(r - i, pB[2 * c - i]) : 1;
//		while (i + len < n && i - len >= 0 && b[i + len] == b[i - len]) {
//			len++;
//		}
//		bmax = max(bmax, len);
//		pB[i] = len;
//		if (i + len > r) {
//			r = i + len;
//			c = i;
//		}
//	}
//}
//int query() {
//	int ans = 0;
//	for (int i = 0; i < a.size(); i++) {
//		int tmp = pA[i];
//		while (i-tmp>=0&&i+tmp<a.size()&&a[i - tmp] == b[i + tmp]) {
//			tmp++;
//		}
//		ans = max(ans, tmp);
//	}
//	return ans - 1;
//}
//int main() {
//	int n;
//	cin >> n;
//	string aa, bb;
//	cin >> aa >> bb;
//	a.resize(2 * n + 1);
//	b.resize(2 * n + 1);
//	for (int i = 0, j = 0; i < 2 * n + 1; i++) {
//		a[i] = i & 1 ? aa[j++] : '#';
//	}
//	for (int i = 0, j = 0; i < 2 * n + 1; i++) {
//		b[i] = i & 1 ? bb[j++] : '#';
//	}
//	int ans = query();
//	cout << ans << '\n';
//}
//
//



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 4e5 + 5;
//int a[N];
//int b[N];
//int p[N];
//int prexor[N];
//int manacher(int n) {
//	int ans = 1;
//	for (int i = 0, c = 0, r = 1, len; i < n; i++) {
//		len = r - i > 0 ? min(p[2 * c - i], r - i) : 1;
//		while (i + len < n && i - len >= 0 && b[i + len] == b[i - len]) {
//			len++;
//		}
//		p[i] = len;
//		ans = max(ans, len);
//		if (i + len > r) {
//			r = i + len;
//			c = i;
//		}
//	}
//	//     cout<<"n:"<<n<<'\n';
//	//     cout<<ans<<'\n';
//	//     for(int i=0;i<n;i++){
//	//         cout<<b[i]<<" ";
//	//     }cout<<'\n';
//	return 2 * ans - 1;
//}
//bool check(int k, int n) {//一块几个,有多少块
//	for (int i = 0; i < k; i++) {
//		for (int j = 0; j < n; j++) {
//			b[j] = prexor[(j + 1) * k + i] ^ prexor[(j)*k + i];
//		}
//		for (int j = 0; j < n; j++) {
//			b[j + n] = b[j];
//		}
//		if (manacher(2 * n) >= n)return true;
//	}
//	return false;
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		prexor[i] = prexor[i - 1] ^ a[i - 1];
//	}
//	for (int i = n + 1; i <= 2 * n; i++) {
//		prexor[i] = prexor[i - 1] ^ a[i - n - 1];
//	}
//	//     for(int i=2*n+1;i<=3*n;i++){
//	//         prexor[i]=prexor[i-1]^a[i-2*n-1];
//	//     }
//	int ans = 1;
//	for (int i = 1; i * i <= n; i++) {
//		if (n % i == 0) {
//			if (check(n / i, i))ans = max(ans, i);
//			if (check(i, n / i))ans = max(ans, n / i);
//		}
//	}
//	cout << ans << '\n';
//}


//#include<bits/stdc++.h>
//#define ull unsigned long long
//using namespace std;
//const int N = 1e6+5;
//string t;
//string s;
//int n,m;
//const ull base = 499;
//ull power[N];
//ull Hash[N];
//ull Hash1[N];
//set<ull>dic;
//
//ull getHash1(int r, int l) {
//	ull ans = Hash1[r];
//	if (l > 0) {
//		ans -= Hash1[l - 1] * power[r - l+1];
//	}
//	return ans;
//}
//void solve() {
//	cin >> s;
//	Hash1[0] = s[0] - 'a' + 1;
//	for (int i = 1; i < s.size(); i++) {
//		Hash1[i] = Hash1[i-1] * base + s[i] - 'a' + 1;
//	}
//	int cnt = 0;
//	for (int i = m - 1; i < s.size(); i++) {
//		if (dic.count(getHash1(i, i - m+1)))cnt++;
//	}
//	cout << cnt << '\n';
//}
//ull getHash(int r,int l) {
//	ull ans = Hash[r];
//	if (l > 0) {
//		ans -= Hash[l - 1] * power[r - l+1];
//	}
//	return ans;
//}
//void prepare() {
//	power[0] = 1;
//	for (int i = 1; i <= N; i++) {
//		power[i] = power[i - 1] * base;
//	}
//	Hash[0] = t[0] - 'a' + 1;
//	for (int i = 1; i < t.size(); i++) {
//		Hash[i] = Hash[i-1] * base + t[i] - 'a' + 1;
//	}
//	dic.insert(Hash[t.size() / 2 - 1]);
//	for (int i = m-1 ; i <= t.size()-1; i++) {
//		//for (int j = i - m + 1; j <= i; j++)cout << t[j]; cout << '\n';
//		//cout << getHash(i, i - m) << '\n';
//		dic.insert(getHash(i, i - m+1));
//	}
//}
//int main() {
//	cin >> t;
//	m = t.size();
//	t = t + t;
//	cin >> n;
//
//	prepare();
//	//for (auto v : dic) {
//	//	cout << v << "   ";
//	//}cout << "\n";
//
//	for (int i = 1; i <= n; i++) {
//		solve();
//	}
//}



//#include<bits/stdc++.h>
//#define ull unsigned long long
//using namespace std;
//const int N = 10000;
//const int base = 499;
//string s;
//ull Hash[N+5];
//ull power[N];
//int main() {
//	power[0] = 1;
//	for (int i = 1; i <= N; i++) {
//		power[i] = power[i - 1] * base;
//	}
//	cin >> s;
//	int n;
//	cin >> n;
//	string t;
//	for (int i = 0; i < n; i++) {
//		cin >> t;
//		Hash[0] = t[0] - 'a' + 1;
//		for (int i = 1; i < t.size(); i++) {
//			Hash[i] = Hash[i - 1] * base + t[i] - 'a' + 1;
//		}
//
//	}
//}