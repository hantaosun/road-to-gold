// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// const int N=2e6+6;
// int ok[N];
// void donkey(){
//     int n,m;
//     cin>>n>>m;
//     vector<int>a(n);
//     vector<int>b(m);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     int mx=-1;
//     for(int i=0;i<m;i++){
//         cin>>b[i];
//         mx=max(mx,b[i]);
//     }
//     sort(a.begin(),a.end());
//     a.erase(unique(a.begin(),a.end()),a.end());
//     int nn=a.size();
//     for(auto v:a){
//         if(ok[v])continue,nn--;
//         for(int i=1;i*v<=mx;i++){
//             ok[i*v]++;
//         }
//     }
//     int oa=0,ob=0;
//     for(int i=0;i<m;i++){
//         if(ok[b[i]]==nn){
//             oa++;
//         }
//         else if(ok[b[i]]==0){
//             ob++;
//         }
//     }
//     int ab=m-oa-ob;
//     if(ab&1){
//         ob--;
//     }
//     if(oa>ob){
//         cout<<"Alice\n";
//     }
//     else{
//         cout<<"Bob\n";
//     }
//     for(int i=0;i<=mx;i++){
//         ok[i]=0;
//     }
// }
// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     //freopen("donkey.in","r",stdin);
//     int t;
//     cin>>t;
//     while(t--){
//         donkey();
//     }
// }