//#include<bits/stdc++.h>
//using namespace std;
//void donkey(){
//	int n;
//	cin>>n;
//	map<int,int>mp;
//	for(int i=1,u;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cin>>u;
//			mp[u]++;
//		}
//	}
//	if(n==1){
//		cout<<"NO\n";
//		return;
//	}
//	for(auto [x,y]:mp){
//		if(y>(n-1)*n){
//			cout<<"NO\n";
//			return;
//		}
//	}
//	cout<<"YES\n";
//}
//int main(){
//	int t;
//	cin>>t;
//	while(t--){
//		donkey();
//	}
//}
////1 1 
////1 2 1
////  1 1


//#include<bits/stdc++.h>
//using namespace std;
//struct cmp{
//	bool operator()(pair<int,int>&a,pair<int,int>&b){
//		if(a.first==b.first){
//			return a.second>b.second;
//		}
//		return a.first>b.first;
//	}
//};
//void donkey(){
//	int n,k,p,m;
//	cin>>n>>k>>p>>m;
//	vector<pair<int,int>>a(n+1);
//	for(int i=1;i<=n;i++){
//		cin>>a[i].second;
//		if(i==p){
//			a[i].first=0;
//		}
//		else a[i].first=1;
//	}
//	deque<pair<int,int>>dq;
//	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
//	for(int i=1;i<=k;i++){
//		pq.push({a[i]});
//		//cout<<a[i].first<<" "<<a[i].second<<"^\n";
//	}
//	for(int i=k+1;i<=n;i++){
//		dq.push_back(a[i]);
//		//cout<<a[i].first<<" "<<a[i].second<<"^\n";
//	}
//	int ans=0;
//	while(m>0){
//		//cout<<m<<"*\n";
//		auto v=pq.top();
//		//cout<<v.first<<" "<<v.second<<"&\n";
//		pq.pop();
//		if(v.second>m)break;
//		m-=v.second;
//		if(v.first==0){
//			ans++;
//		}
//		if(dq.empty()){
//			pq.push(v);
//			continue;
//		}
//		pq.push(dq.front());
//		dq.pop_front();
//		dq.push_back(v);
//	}
//	cout<<ans<<endl;
//}
//int main(){
//	int t;
//	cin>>t;
//	while(t--){
//		donkey();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//void donkey(){
//	int n;
//	cin>>n;
//	vector<int>c(n+1);
//	vector<int>p(n+1);
//	for(int i=1;i<=n;i++){
//		cin>>c[i]>>p[i];
//	}
//	vector<double>dp(n+2,0);
//	for(int i=n;i>=1;i--){
//		dp[i]=max(c[i]+(100-p[i])/100.0*dp[i+1],dp[i+1]);
//	}
//	cout<<fixed<<setprecision(7)<<dp[1]<<endl;
//}
//int main(){
//	int t;
//	cin>>t;
//	while(t--){
//		donkey();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//string g[8005];
//short dis[8005][8005];
//int vis[8005];
//vector<vector<int>>g1;
//vector<vector<int>>g2;
//int n;
//struct cmp{
//	bool operator()(pair<int,int>&x,pair<int,int>&y){
//		return x.second>y.second;
//	}
//};
//void getmin(int s){
//	queue<int>q;
//	q.push(s);
//	int level=0;
//	while(!q.empty()){
//		int siz=q.size();
//		for(int i=1;i<=siz;i++){
//			int u=q.front();
//			q.pop();
//			dis[s][u]=level;
//			for(auto v:g1[u]){
//				q.push(v);
//			}
//		}
//		level++;
//	}
//}
//bool ok=1;
//void dfs(int u,int fa){
//	if(vis[u]){
//		ok=false;
//		return;
//	}
//	vis[u]=1;
//	for(auto v:g2[u]){
//		if(v!=fa){
//			dfs(v,u);
//		}
//	}
//}
//bool dfs1(int u) {
//	if (vis[u] == 1) return true;  // 遇到递归栈里的点 → 有环！
//	if (vis[u] == 2) return false; // 已经处理完，无环
//	
//	vis[u] = 1;  // 标记：正在访问
//	for (int v : g1[u]) {
//		if (dfs1(v)) return true;
//	}
//	vis[u] = 2;  // 标记：访问完成
//	return false;
//}
//
//bool has_circle(int n) {
//	for(int i=1;i<=n;i++){
//		vis[i]=0;
//	}
//	for (int i=1; i<=n; i++) {
//		if (vis[i] == 0) {
//			if (dfs1(i)) return true;
//		}
//	}
//	return false;
//}
//void donkey(){
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>g[i];
//		g[i]=" "+g[i];
//	}
//	g1.assign(n+1,{});
//	vector<pair<int,int>>ans;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			dis[i][j]=SHRT_MAX;
//		}
//	}
//	//cout<<"&\n";
//	for(int i=1;i<=n;i++){
//		if(g[i][i]!='1'){
//			cout<<"No\n";
//			return;
//		}
//		for(int j=1;j<=n;j++){
//			if(i!=j&&g[i][j]=='1'&&g[j][i]=='1'){
//				cout<<"No\n";
//				return;
//			}
//			else if(i!=j&&g[i][j]=='1'){
//				g1[i].push_back(j);
//				//cout<<i<<" "<<j<<"%\n";
//			}
//		}
//	}
////	for(int i=1;i<=n;i++){
////		for(auto v:g1[i]){
////			cout<<v<<" ";
////		}cout<<endl;
////	}
//	
//	if(has_circle(n)){
//		cout<<"No\n";
//		return;
//	}
////	cout<<"xixi"<<endl;
//	ok=1;
//	for(int i=1;i<=n;i++)getmin(i);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(g[i][j]=='0'&&dis[i][j]!=SHRT_MAX){
//				cout<<"No\n";
//				return;
//			}
//		}
//	}
////	for(int i=1;i<=n;i++){
////		for(int j=1;j<=n;j++){
////			cout<<dis[i][j]<<" ";
////		}cout<<endl;
////	}
//	g2.assign(n+1,{});
//	ok=1;
//	for(int i=1;i<=n;i++)vis[i]=0;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(dis[i][j]==1){
//				g2[i].push_back(j);
//				g2[j].push_back(i);
//			}
//		}
//	}	
//	dfs(1,0);
//	for(int i=1;i<=n;i++){
//		if(!vis[i])ok=false;
//	}
//	if(!ok){
//		cout<<"No\n";
//		return;
//	}
//	cout<<"Yes\n";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(dis[i][j]==1){
//				cout<<i<<" "<<j<<endl;	
//			}
//		}
//	}
//}
//int main(){
////	ios_base::sync_with_stdio(false);
////	cin.tie(nullptr);
//	int t;
//	cin>>t;
//	while(t--){
//		donkey();
//	}
//}



#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e4+5;
int n, id[N], cnt[N];
bool vs[N], e[N][N];
struct Dsu {
	int fa[N];
	void init(int n) {
		for (int i = 1; i <= n; i++) fa[i] = i;
	}
	int find(int x) {
		if (x == fa[x]) return x;
		return fa[x] = find(fa[x]);
	}
	void merge(int x, int y) {
		fa[find(x)] = find(y);
	}
} dsu;
bool reach[N];
vector<int> tree[N];
void search(int u) {
	reach[u] = 1;
	for (int v : tree[u]) {
		search(v);
	}
}
void solve(int tid) {
	cin >> n;
	for (int i = 1; i <= n; i++) cnt[i] = 0, tree[i].clear();
	for (int u = 1; u <= n; u++) {
		id[u] = u;
		string s;
		cin >> s;
		for (int v = 1; v <= n; v++) {
			e[u][v] = s[v-1]-'0';
			cnt[u] += e[u][v];
		}
	}
	sort(id + 1, id + n + 1, [&](int u, int v) {
		return cnt[u] > cnt[v];
	});
	vector<pair<int, int >> edges;
	for (int u = 1; u <= n; u++) {
		for(int i = 1; i <= n; i++) {
			vs[i] = false;
		}
		vs[u] = true;
		for (int i = 1; i <= n; i++) {
			int v = id[i];
			if (!vs[v] && e[u][v]) {
				edges.push_back({u, v});
				if(edges.size() >= n) {
					cout << "No" << "\n";
					return ;
				}
				for (int w = 1; w <= n; w++) {
					if (e[v][w]) {
						vs[w] = true;
					}
				}
			}
		}
	}
	if (edges.size() != n - 1) {
		cout << "No" << "\n";
		return ;
	}
	sort(edges.begin(), edges.end());
	dsu.init(n);
	for (auto [u, v] : edges) {
		dsu.merge(u, v);
		tree[u].push_back(v);
	}
	int flag = 1;
	for (int i = 1; i <= n; i++) flag &= (dsu.find(i) == dsu.find(1));
	if (!flag) {
		cout << "No" << "\n";
		return ;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) reach[j] = 0;
		search(i);
		for (int j = 1; j <= n; j++) {
			if (reach[j] != e[i][j]) {
				cout <<  "No" << "\n";
				return ;
			}
		}
	}
	cout<< "Yes\n";
	for (auto [u, v] : edges) {
		cout << u << ' ' << v << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) solve(i);
	return 0;
}
