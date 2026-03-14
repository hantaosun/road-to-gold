//#include<bits/stdc++.h>
//using namespace std;
//using ll=long long;
//mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
//constexpr ll N=1e5+10,inf=1e16;
//ll h[N],to[N<<1],nxt[N<<1],w[N<<1],dp[N][2],lk,ans;
//void addedge(ll u,ll v,ll k){
//	to[++lk]=v;
//	w[lk]=k;
//	nxt[lk]=h[u];
//	h[u]=lk;
//}
//void dfs(ll u,ll pa){
//	ll i,x;
//	dp[u][0]=dp[u][1]=0;
//	vector<ll> z0,z1,pr1,sf1;
//	for(i=h[u];i;i=nxt[i]){
//		if(to[i]==pa){
//			x=w[i];
//			continue;
//		}
//		dfs(to[i],u);
//		z0.push_back(w[i]+dp[to[i]][0]);
//		z1.push_back(dp[to[i]][1]);
//	}
//	dp[u][1]=x;
//	if(z0.empty()) return;
//	dp[u][0]+=*max_element(z0.begin(),z0.end());
//	dp[u][1]+=*max_element(z1.begin(),z1.end());
//	pr1=z1,sf1=z1;
//	for(i=1;i<z1.size();++i){
//		pr1[i]=max(pr1[i-1],pr1[i]);
//	}
//	for(i=z1.size()-2;i>=0;--i){
//		sf1[i]=max(sf1[i+1],sf1[i]);
//	}
//	for(i=0;i<z0.size();++i){
//		x=0;
//		if(i>0) x=max(x,pr1[i-1]);
//		if(i<=z0.size()-2) x=max(x,sf1[i+1]);
//		ans=max(ans,z0[i]+x);
//		ans=max(ans,z1[i]);
//	}
//}
//void solve(){
//	ll i,j,l,r,x,y,z,n,s;cin>>n>>s;
//	z=0;
//	for(i=1;i<n;++i){
//		cin>>x>>y>>l>>r;
//		z+=l+r;
//		addedge(x,y,l),addedge(y,x,r);
//	}
//	ans=0;
//	dfs(1,1);
//	cout<<z<<" "<<ans<<endl;
//	cout<<z-ans<<endl;
//}
//signed main(){
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr),cout.tie(nullptr);
//	int tt=1;
//	while(tt--){
//		solve();
//	}
//}
