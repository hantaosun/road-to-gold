//二叉搜索子树的最大键值**
//#include<bits/stdc++.h>
//using namespace std;
//struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
//struct info {
//    bool isBst;
//    int  maxBstsum;
//    int  sum;
//    int  max;
//    int  min;
//    info(bool a,int b,int c,int d,int e) {
//        isBst = a;
//        maxBstsum = b;
//        sum = c;
//        max = d;
//        min = e;
//    }
//    info() {}
//};
//info f(TreeNode* root) {
//    if (root== NULL)return info(true, 0,0, INT_MIN,INT_MAX);
//    info li, ri;
//    li = f(root->left), ri = f(root->right);
//    bool isBst = li.isBst && ri.isBst && li.max < root->val && root->val < ri.min;
//    int sum = li.sum + ri.sum + root->val;
//    int maxBstsum=max(li.maxBstsum,ri.maxBstsum);
//    if (isBst) {
//        maxBstsum = max(maxBstsum,sum);
//    }
//    int ma = max(root->val, max(li.max, ri.max));
//    int mi = min(root->val, min(li.min, ri.min));
//    return info(isBst, maxBstsum,sum, ma, mi);
//}
//class Solution {
//public:
//    int maxSumBST(TreeNode* root) {
//        return f(root).maxBstsum;
//    }
//};

//二叉树的直径
//#include<bits/stdc++.h>
//using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//struct info {
//	int h;//该树深度
//	int b;//该树宽度
//	info() {};
//	info(int h, int b) {
//		this->h = h;
//		this->b = b;
//	}
//};
//info f(TreeNode* root) {
//	if (root == NULL) {
//		return info(0, 0);
//	}
//	info li = f(root->left), ri = f(root->right);
//	int h = max(li.h, ri.h) + 1;
//	int b = max(max(li.b, ri.b), li.h + ri.h);
//	return info(h, b);
//}
//class Solution {
//public:
//	int diameterOfBinaryTree(TreeNode* root) {
//		return f(root).b;
//	}
//};

//在二叉树中分配硬币
//#include<bits/stdc++.h>
//using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//
//};
//struct info {
//	int n;//该树有几颗结点
//	int c;//该树有几个硬币
//	info() {};
//	info(int n, int c) {
//		this->n = n;
//		this->c = c;
//	}
//};
//int ans = 0;
//info f(TreeNode* root) {
//	if (root == NULL)return info(0, 0);
//	info li = f(root->left), ri = f(root->right);
//	ans += abs(li.n - li.c) + abs(ri.n - ri.c);
//	return info(li.n + ri.n + 1,li.c + ri.c + root->val);
//}
//class Solution {
//public:
//	int distributeCoins(TreeNode* root) {
//		ans = 0;
//		f(root);
//		cout << ans;
//	}
//};

//没有上司的舞会
//#include<bits/stdc++.h>
//using namespace std;
//int head[6005];
//int nex[6005];
//int to[6005];
//int joy[6005];
//int boss[6005];
//int cnt = 1;
//int dp[6005][2];
//int f(int cur,bool ok) {//当前结点，能不能拿 在该情况下该树上能拿多大
//	if (dp[cur][ok] != -1) {
//		return dp[cur][ok];
//	}
//	int ans = 0,ans1=joy[cur];
//	for (int i = head[cur]; i != 0; i = nex[i]) {//不拿
//		ans += f(to[i], 1);
//	}
//	if (ok) {//能拿
//		for (int i = head[cur]; i != 0; i = nex[i]) {//拿
//			ans1 += f(to[i], 0);
//		}
//		ans = max(ans, ans1);
//	}
//	dp[cur][ok] = ans;
//	return ans;
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> joy[i];
//	}
//	for (int i = 0, l, k; i < n - 1;i++) {
//		cin >> l >> k;
//		boss[l] = 1;
//		to[cnt] = l;
//		nex[cnt] = head[k];
//		head[k] = cnt++;
//	}
//	memset(dp, -1, sizeof(dp));
//	int root;
//	for (int i = 1; i <= n; i++) {
//		if (!boss[i]) {
//			root = i;
//		}
//	}
//	cout << f(root, 1) << endl;
//}

//监控二叉树
//#include<bits/stdc++.h>
//using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//int ans = 0;
//int f(TreeNode* cur) {//0未覆盖 1覆盖未放监控 2覆盖且放监控
//	if (cur == NULL)return 1;
//	int l = f(cur->left), r = f(cur->right);
//	if (l==0 || r == 0) {
//		ans++;
//		return 2;
//	}
//	else {
//		if (l == 2 || r == 2) {
//			return 1;
//		}
//		else {
//			return 0;
//		}
//	}
//}
//class Solution {
//public:
//	int minCameraCover(TreeNode* root) {
//		ans = 0;
//		if(!f(root))ans++;
//		return ans;
//	}
//};

//路径总和III
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//int tar;
//int ans;
//map<ll,ll> f(TreeNode* cur) {//当前节点到其所有子节点可能的路径和及其数量
//	if (cur == NULL) {
//		map<ll,ll>p = {};
//		return p;
//	}
//	map<ll,ll> lm = f(cur->left), rm = f(cur->right);
//	map<ll,ll> cm;
//	cm.insert(make_pair(cur->val, 1));
//	for (auto p : lm) {
//		cm[p.first + cur->val] += p.second;
//	}
//	for (auto p : rm) {
//		cm[p.first + cur->val] += p.second;
//	}
//	if (cm.count(tar))ans += cm[tar];
//	return cm;
//}
//class Solution {
//public:
//	int pathSum(TreeNode* root, int targetSum) {
//		ans = 0;
//		tar = targetSum;
//		f(root);
//		return ans;
//	}
//};
//也可理解为树上前缀和 时间更好
//#include<bits/stdc++.h>
//#include<unordered_map>
//#define ll long long
//using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//int ans = 0;
//int tar;
//unordered_map<long long, int>m;//记录某条路径上的前缀和信息
//void f(TreeNode*cur,ll sum) {//该节点到根节点路径上的总和（不包括该节点）
//	if (cur == NULL)return;
//	sum += cur->val;
//	if (m.count(sum-tar)) {
//		ans += m[sum-tar];
//	}
//	m[sum]++;
//	f(cur->left, sum);
//	f(cur->right, sum);
//	m[sum]--;
//}
//class Solution {
//public:
//	int pathSum(TreeNode* root, int targetSum) {
//		ans = 0;
//		tar = targetSum;
//		m.clear();
//		m.insert(make_pair(0, 1));
//		f(root, 0);
//		return ans;
//	}
//};

//到达首都的最小油耗
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//struct info {
//    ll siz;//该子树大小
//    ll cost;//该节点所有子节点到达该节点的最少油耗
//    info() {}
//    info(ll siz, ll cost) {
//        this->siz = siz;
//        this->cost = cost;
//    }
//};
//int se;
//info f(int cur, int fa, vector<vector<int>>& gra) {//该节点所有子节点到达该节点的最少油耗
//    ll siz = 1;
//    ll cost = 0;
//    info t;
//    for (int i = 0; i < gra[cur].size(); i++) {
//        if (gra[cur][i] == fa)continue;
//        t = f(gra[cur][i], cur, gra);
//        siz += t.siz;
//        cost += t.cost + (t.siz + se - 1) / se;
//    }
//    return info(siz, cost);
//}
//class Solution {
//public:
//    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
//        se = seats;
//        vector<vector<int>>gra(roads.size() + 1);
//        for (int i = 0; i < roads.size(); i++) {
//            gra[roads[i][0]].push_back(roads[i][1]);
//            gra[roads[i][1]].push_back(roads[i][0]);
//        }
//        return f(0, 0, gra).cost;
//    }
//};

//相邻字符不同的最长路径
//#include<bits/stdc++.h>
//using namespace std;
//struct info {
//	int a;//到该节点的最长路径
//	int c;//该树上的最长路径
//	info() {}
//	info(int a, int c) {
//		this->a = a;
//		this->c = c;
//	}
//};
//string ss;
//info f(int cur, vector<vector<int>>& gra) {//包含该节点的相邻字符不同的最长路径
//	int c = 1;
//	int ma = 0, ma1 = 0;//字符不同的子树的最长和次长
//	for (int i = 0; i < gra[cur].size(); i++) {
//		info t = f(gra[cur][i], gra);
//		c = max(c, t.c);
//		if (ss[cur] != ss[gra[cur][i]]) {
//			if (t.a > ma) {
//				ma1 = ma;
//				ma = t.a;
//			}
//			else if (t.a > ma1) {
//				ma1 = t.a;
//			}
//		}
//	}
//	int a = ma + 1;
//	c = max(c, ma + ma1 + 1);
//	return info(a, c);
//}
//class Solution {
//public:
//	int longestPath(vector<int>& parent, string s) {
//		ss = s;
//		vector<vector<int>>gra(s.size());
//		for (int i = 0; i < parent.size(); i++) {
//			if (parent[i] == -1)continue;
//			gra[parent[i]].push_back(i);
//		}
//		return f(0, gra).c;
//	}
//};

//dfn序相关 适用于解决跨子树问题

//移除子树后的二叉树高度
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1e5 + 5;
//int dfn[MAXN];//值为i的节点的dfn序
//int siz[MAXN];//值为i的节点的树大小
//int dep[MAXN];//dfn序为i的节点所在深度
//int lm[MAXN];//dep数组中包括该位置左侧的最大值
//int rm[MAXN];//dep数组中包括该位置右侧的最大值
//int cnt = 0;
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//int dfs(TreeNode* root, int depth) {
//	if (root == NULL)return 0;
//	dfn[root->val] = ++cnt;
//	dep[dfn[root->val]] = depth;
//	int s = 1;
//	s += dfs(root->left, depth + 1);
//	s += dfs(root->right, depth + 1);
//	siz[dfn[root->val]] = s;
//	return s;
//}
//class Solution {
//public:
//	vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
//		cnt = 0;
//		vector<int>ans(queries.size());
//		int n = dfs(root, 0);
//		lm[0] = dep[0];
//		rm[n - 1] = dep[n - 1];
//		lm[0] = INT_MIN;
//		rm[n + 1] = INT_MIN;
//		for (int i = 1; i <= n; i++) {
//			lm[i] = max(lm[i - 1], dep[i]);
//		}
//		for (int i = n; i >= 1; i--) {
//			rm[i] = max(rm[i + 1], dep[i]);
//		}
//		for (int i = 0; i < queries.size(); i++) {
//			int c = dfn[queries[i]];
//			ans[i] = max(lm[c - 1], rm[c + siz[c]]);
//		}
//		return ans;
//	}
//};

//从树中删除边的最小分数
//#include<bits/stdc++.h>
//using namespace std;
//int cnt = 0;
//int dfs(int cur, int fa, vector<vector<int>>& gra, vector<int>& dfn, vector<int>& siz, vector<int>& val, vector<int>& nums) {
//    dfn[cur] = ++cnt;
//    val[dfn[cur]] = nums[cur];
//    int si = 0;
//    for (int i = 0; i < gra[cur].size(); i++) {
//        if (gra[cur][i] == fa)continue;
//        si += dfs(gra[cur][i], cur, gra, dfn, siz, val, nums);
//    }
//    siz[dfn[cur]] = si + 1;
//    return siz[dfn[cur]];
//}
//class Solution {
//public:
//    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
//        int n = nums.size();
//        cnt = 0;
//        vector<int>dfn(n + 5);
//        vector<int>siz(n + 5);
//        vector<int>val(n + 5);//dfn序号对应的节点的值
//        vector<vector<int>>gra(n + 5);
//        for (int i = 0; i < edges.size(); i++) {
//            gra[edges[i][0]].push_back(edges[i][1]);
//            gra[edges[i][1]].push_back(edges[i][0]);
//        }
//        dfs(0, 0, gra, dfn, siz, val, nums);//把0号当作根节点
//        vector<int>prexor(n + 5);
//        prexor[0] = 0;
//        int tor = 0;
//        for (int i = 1; i <= n; i++) {
//            prexor[i] = val[i] ^ prexor[i - 1];
//            tor ^= val[i];
//        }
//        int ans = INT_MAX;
//        for (int i = 2; i <= n; i++) {//选取两个节点
//            for (int j = i + 1; j <= n; j++) {
//                int p2 = prexor[j + siz[j] - 1] ^ prexor[j - 1];
//                int p1 = j < i + siz[i] ? prexor[i + siz[i] - 1] ^ prexor[i - 1] ^ p2 : prexor[i + siz[i] - 1] ^ prexor[i - 1];
//                int p3 = tor ^ p1 ^ p2;
//                ans = min(ans, max(p1, max(p2, p3)) - min(p1, min(p2, p3)));
//            }
//        }
//        return ans;
//    }
//};

//选课 树上有依赖的背包*****
//#include<bits/stdc++.h>
//#include<vector>
//using namespace std;
//int dp[305][305][305];
//int f(int cur,int m,int r,vector<int>&val,vector<vector<int>>&gra) {//当前根节点的子节点l到r上，能选课不超过i的情况下，能获得的最大学分
//	if (dp[cur][m][r]!=-1)return dp[cur][m][r];
//	if (m == 0)return 0;
//	if (r < 0 || m == 1)return val[cur];
//	int ans = f(cur,m,r-1,val,gra);		
//	int son = gra[cur][r];
//	for (int i = 1; i <m; i++) {
//		ans = max(ans, f(cur, m - i, r - 1, val, gra) + f(son,i,gra[son].size()-1, val, gra));
//	}
//	dp[cur][m][r] = ans;
//	return ans;
//}
//int main() {
//	int N, M;
//	cin >> N >> M;
//	memset(dp, -1, sizeof(dp));
//	vector<vector<int>>gra(N+5);
//	vector<int>val(N+5);
//	for (int i = 1,k,s; i <= N; i++) {
//		cin >> k >> s;
//		gra[k].push_back(i);
//		val[i] = s;
//	}
//	int ans = f(0, M+1, gra[0].size()-1, val, gra);
//	cout << ans << endl;
//}
 
//dfn序优化版
//#include<bits/stdc++.h>
//using namespace std;
//int cnt = 0;
//int dp[330][330];//从i往后所有节点中选k个的最大值
//int dfs(int cur, vector<vector<int>>& g, vector<int>& vald, vector<int>& val, vector<int>& siz) {
//	int i = ++cnt;
//	vald[i] = val[cur];
//	int size = 1;
//	for (int i = 0; i < g[cur].size(); i++) {
//		size += dfs(g[cur][i], g, vald, val, siz);
//	}
//	siz[i] = size;
//	return size;
//}
//int main() {
//	int N, M;
//	cin >> N >> M;
//	vector<vector<int>>g(N + 5);
//	vector<int>val(N + 5);
//	vector<int>dfn(N + 5);
//	vector<int>siz(N + 5);
//	vector<int>vald(N + 5);
//	for (int i = 1, k, s; i <= N; i++) {
//		cin >> k >> s;
//		g[k].push_back(i);
//		val[i] = s;
//	}
//	int t = dfs(0, g, vald, val, siz);
//	for (int j = 0; j <= M + 1; j++)dp[N + 2][j] = 0;
//	for (int i = N + 1; i >= 2; i--) {
//		for (int j = 1; j <= M; j++) {
//			dp[i][j] = max(dp[i + siz[i]][j], vald[i] + dp[i + 1][j - 1]);
//		}
//	}
//	cout << val[0] + dp[2][M];
//}