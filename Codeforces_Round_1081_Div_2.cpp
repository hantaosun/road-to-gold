// #include<bits/stdc++.h>
// using namespace std;
// void donkey(){
//     int n;
//     cin>>n;
//     string s;
//     cin>>s;
//     s=" "+s;
//     int ans=0;
//     bool got2=0;
//     for(int i=2;i<=n;i++){
//         if(s[i]!=s[i-1])ans++;
//         else got2=1;
//     }
//     ans++;
//     if(s[1]==s[n]){
//         cout<<ans<<endl;
//         return;
//     }
//     else {
//         if(got2){
//             ans++;
//         }
//         cout<<ans<<endl;
//     }
// }
// signed main(){
//     //freopen("donkey.in","r",stdin);
//     int t;
//     cin>>t;
//     while(t--){
//         donkey();
//     }
// }


// #include<bits/stdc++.h>
// using namespace std;
// void donkey(){
//     int n;
//     cin>>n;
//     string s;
//     cin>>s;
//     s=" "+s;
//     int one=0;
//     int zero=0;
//     for(int i=1;i<=n;i++){
//         if(s[i]=='1')one++;
//         else zero++;
//     }
//     if((one&1)&&(!(zero&1))){
//         cout<<-1<<endl;
//         return;
//     }
//     if(!(one&1)){
//         cout<<one<<endl;
//         if(one!=0){
//             for(int i=1;i<=n;i++){
//                 if(s[i]=='1'){
//                     cout<<i<<" ";
//                 }
//             }cout<<endl;
//         }
//     }
//     else{
//         cout<<zero<<endl;
//         for(int i=1;i<=n;i++){
//             if(s[i]=='0'){
//                 cout<<i<<" ";
//             }
//         }cout<<endl;
//     }
// }
// signed main(){
//     //freopen("donkey.in","r",stdin);
//     int t;
//     cin>>t;
//     while(t--){
//         donkey();
//     }
// }


// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// void donkey(){
//     int n,h,k;
//     cin>>n>>h>>k;
//     vector<int>a(n+1);
//     vector<int>bmax(n+2,-1);
//     int sum=0;
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//         sum+=a[i];
//     }
//     for(int i=n;i>=1;i--){
//         bmax[i]=max(bmax[i+1],a[i]);
//     }
//     if(h%sum==0){
//         cout<<h/sum*n+((h/sum)-1)*k<<endl;
//         return;
//     }
//     int ans=0;
//     ans+=h/sum*n+(h/sum)*k;
//     h%=sum;
//     int pmin=INT_MAX;
//     int tsum=0;
//     for(int i=1;i<=n;i++){
//         tsum+=a[i];
//         pmin=min(pmin,a[i]);
//         if(tsum-pmin+bmax[i+1]>=h){
//             cout<<ans+i<<endl;
//             return;
//         }
//         if(tsum>=h){
//             cout<<ans+i<<endl;
//             return;
//         }
//     }
//     cout<<-1<<endl;
// }
// signed main(){
//     //freopen("donkey.in","r",stdin);
//     int t;
//     cin>>t;
//     while(t--){
//         donkey();
//     }
// }


#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>a;
vector<vector<int>>son;
vector<vector<int>>mdl;
vector<vector<int>>mdr;
vector<int>sm;
vector<int>mxd;
vector<vector<int>>g;
vector<int>ans;
vector<int>fans;
void dfs(int u,int fa){
    int mxds=0;
    sm[u]=a[u];
    for(auto v:g[u]){
        if(v==fa)continue;
        dfs(v,u);
        sm[u]+=sm[v];
        mxds=max(mxds,mxd[v]);
        son[u].push_back(v);
        mdl[u].push_back(mxd[v]);
        mdr[u].push_back(mxd[v]);
    }
    for(int i=1;i<mdl[u].size();i++){
        mdl[i]=max(mdl[i],mdl[i-1]);
    }
    for(int i=mdr.size()-2;i>=0;i--){
        mdr[i]=max(mdr[i],mdr[i+1]);
    }
    mxd[u]=1+mxds;
}
void dfs1(int u,int fa){
    for(auto v:g[u]){
        if(v==fa)continue;
        dfs1(v,u);
        ans[u]+=ans[v]+sm[v];
    }
}
void dfs2(int u,int fa){
    int an=0;
    for(auto v:g[u]){
        if(v==fa)continue;
        dfs2(v,u);
        an=max(an,ans[u]+fans[v]-ans[v]);   
    }
    if(son[u].size()==1){
        fans[u]=ans[u]+fans[son[u][0]]-ans[son[u][0]];
    }
    else{
        for(int i=0;i<son[u].size();i++){
            int v=son[u][i];
            int mdd=0;
            if(i==0){
                if(i+1<son[u].size()){
                    mdd=mdr[u][i+1];
                }
            }
            else if(i==son[u].size()-1){
                if(i-1>=0){
                    mdd=mdl[u][i-1];
                }
            }
            else{
                mdd=max(mdl[u][i-1],mdr[u][i+1]);
            }
            //cout<<i<<" "<<u<<" "<<v<<" "<<mdd<<"**\n";
            an=max(an,ans[u]+(mdd)*sm[v]);
        }
        fans[u]=an;
    }
}
void donkey(){
    int n;
    cin>>n;
    a.assign(n+1,0);
    g.assign(n+1,{});
    sm.assign(n+1,0);
    son.assign(n+1,{});
    mxd.assign(n+1,0);
    mdl.assign(n+1,{});
    mdr.assign(n+1,{});
    ans.assign(n+1,0);
    fans.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    dfs1(1,0);
    dfs2(1,0);
    // for(int i=0;i<son[2].size();i++){
    //     cout<<mdr[3][i]<<" "<<mdl[3][i]<<endl;
    // }
    // for(int i=1;i<=n;i++){
    //     cout<<sm[i]<<" ";
    // }cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<mxd[i]<<" ";
    // }cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<ans[i]<<" ";
    // }cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<fans[i]<<" ";
    }cout<<endl;
   // cout<<"-------------\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("donkey.in","r",stdin);
    int t;
    cin>>t;
    while(t--){
        donkey();
    }
}