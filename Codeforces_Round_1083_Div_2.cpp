// #include <bits/stdc++.h>
// using namespace std;
// void donkey(){
//    int n;
//    cin>>n;
//    vector<int>p(n+1);
//    int pos=-1;
//    for(int i=1;i<=n;i++){
//         cin>>p[i];
//         if(p[i]==n)pos=i;
//    }
//    swap(p[1],p[pos]);
//    for(int i=1;i<=n;i++){
//         cout<<p[i]<<" ";
//    }cout<<endl;
// }
// int main(){
//     freopen("donkey.in", "r", stdin);
//     int t;
//     cin >> t;
//     while (t--){
//         donkey();
//     }
// }



// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// void donkey(){
//    int n;
//    cin>>n;
//    //cout<<n<<"**\n";
//    int ans=1;
//    for(int i=2;i*i<=n;i++){
//      if(n%i==0){
//         ans*=i;
//         while(n%i==0){
//             n/=i;
//         }
//      }
//    }
//    if(n>1)ans*=n;
//    cout<<ans<<endl;
// }
// signed main(){
//     freopen("donkey.in", "r", stdin);
//     int t;
//     cin >> t;
//     while (t--){
//         donkey();
//     }
// }


// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// bool inq[1000005];
// void donkey(){
//    int n;
//    cin>>n;
//    vector<vector<int>>a(n+1);
//    vector<int>used(n+1);
//    queue<int>q;
//    set<int>tmp;
//    for(int i=1,l;i<=n;i++){
//         cin>>l;
//         vector<int>tm(l+1);
//         for(int j=1;j<=l;j++){
//             cin>>tm[j];
//         }
//         a[i].push_back(0);
//         for(int j=l;j>=1;j--){
//             if(!tmp.count(tm[j])){
//                 a[i].push_back(tm[j]);
//                 tmp.insert(tm[j]);
//             }
//         }
//         tmp.clear();
//    }
// //    for(int i=1;i<=n;i++){
// //         for(auto v:a[i]){
// //             cout<<v<<" ";
// //         }cout<<endl;
// //    }
//    for(int i=1;i<=n;i++){
//         int mx=-1;
//         for(int j=1;j<=n;j++){
//             if(used[j])continue;
//             if(mx==-1){
//                 mx=j;
//                 continue;
//             }
//             int r1=1,r2=1;
//             while(r1<a[mx].size()&&r2<a[j].size()){
//                 while(r1<a[mx].size()&&inq[a[mx][r1]]){
//                     r1++;
//                 }
//                 while(r2<a[j].size()&&inq[a[j][r2]]){
//                     r2++;
//                 }
//                 //cout<<r1<<" "<<r2<<" &"<<endl;
//                 if(r1>=a[mx].size()||a[mx][r1]<a[j][r2]){
//                     break;
//                 }
//                 if(r2>=a[j].size()||a[j][r2]<a[mx][r1]){
//                     mx=j;
//                     break;
//                 }
//                 r1++,r2++;
//                 if(r2>=a[j].size()){
//                     mx=j;
//                     break;
//                 }
//                 if(r1>=a[mx].size()){
//                     break;
//                 }
//             }
//             //cout<<r1<<" "<<r2<<endl;
//             //cout<<j<<" "<<mx<<" jmx"<<endl;
//         }
//         if(mx!=-1){
//             for(int i=1;i<a[mx].size();i++){
//                 if(!inq[a[mx][i]]){
//                     q.push(a[mx][i]);
//                     inq[a[mx][i]]=1;
//                 }
//             }
//             used[mx]=1;
//         }
//         //cout<<mx<<" "<<i<<"**"<<endl;
//    }
//     while(!q.empty()){
//      cout<<q.front()<<" ";
//      inq[q.front()]=false;
//      q.pop();
//     }cout<<endl;
// }
// signed main(){
//     //freopen("donkey.in", "r", stdin);
//     int t;
//     cin >> t;
//     while (t--){
//         donkey();
//     }
// }


// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// bool inq[1000005];
// void donkey(){
//    int n;
//    cin>>n;
//    vector<vector<int>>a(n+1);
//    vector<int>used(n+1);
//    queue<int>q;
//    set<int>ap;
//    for(int i=1,l;i<=n;i++){
//         cin>>l;
//         vector<int>tmp(l);
//         for(int j=0;j<l;j++){
//             cin>>tmp[j];
//         }
//         for(int j=l-1;j>=0;j--){
//             if(!ap.count(tmp[j])){
//                 ap.insert(tmp[j]);
//                 a[i].push_back(tmp[j]);
//             }
//         }
//         ap.clear();
//    }
//    for(int i=1;i<=n;i++){
//         vector<pair<vector<int>,int>>b;
//         for(int j=1;j<=n;j++){
//             if(used[j])continue;
//             vector<int>tmp;
//             for(auto v:a[j]){
//              if(!inq[v]){
//                  tmp.push_back(v);
//              }
//             } 
//            b.push_back({tmp,j});
//         }
//         sort(b.begin(), b.end(), [&](const pair<vector<int>, int>& x, const pair<vector<int>, int>& y) {
//          return x.first < y.first;
//         });
//         if(!b.empty()){
//             used[b[0].second]=1;
//             for(auto v:b[0].first){
//                 inq[v]=true;
//                 q.push(v);
//             }
//         }
//    }
//     while(!q.empty()){
//      cout<<q.front()<<" ";
//      inq[q.front()]=false;
//      q.pop();
//     }cout<<endl;
// }
// signed main(){
//     freopen("donkey.in", "r", stdin);
//     int t;
//     cin >> t;
//     while (t--){
//         donkey();
//     }
// }


// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e5+5;
// int mx[N];
// int mxsiz;
// int lowbit(int i){
//     return i&(-i);
// }
// void upd(int x,int v){
//     for(int i=x;i<=mxsiz;i+=lowbit(i)){
//         mx[i]=max(mx[i],v);
//     }
// }
// int query(int x){
//     int ans=0;
//     for(int i=x;i>0;i-=lowbit(i)){
//         ans=max(ans,mx[i]);
//     }
//     return ans;
// }
// void donkey(){
//     int n;
//     cin>>n;
//     vector<int>a(n+1);
//     vector<int>l(n+1);//以i位置结尾最长下降子序列
//     vector<int>r(n+1);//以i位置开头最长上升子序列
//     vector<int>vsort;
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//         vsort.push_back(a[i]);
//     }
//     sort(vsort.begin(),vsort.end());
//     vsort.erase(unique(vsort.begin(),vsort.end()),vsort.end());
//     mxsiz=vsort.size();
//     int ans=INT_MAX;
//     auto run=[&](int ls,int rs,int flag){
//         for(int i=0;i<=mxsiz;i++){
//             mx[i]=0;
//         }
//         for(int i=ls;i<=rs;i++){
//             int rnk=lower_bound(vsort.begin(),vsort.end(),a[i])-vsort.begin();
//             rnk=mxsiz-rnk;
//             l[i]=query(rnk-1)+1;
//             upd(rnk,l[i]);
//         }
//         for(int i=0;i<=mxsiz;i++){
//             mx[i]=0;
//         }
//         for(int i=rs;i>=ls;i--){
//             int rnk=lower_bound(vsort.begin(),vsort.end(),a[i])-vsort.begin();
//             rnk=mxsiz-rnk;
//             r[i]=query(rnk-1)+1;
//             upd(rnk,r[i]);
//         }
//         for(int i=ls;i<=rs;i++){
//             ans=min(ans,n-(l[i]+r[i]-1));
//         }
//         // cout<<flag<<" flag"<<endl;
//         // cout<<ls<<" "<<rs<<endl;
//         // for(int i=ls;i<=rs;i++){
//         //     cout<<"("<<l[i]<<","<<r[i]<<")  ";
//         // }cout<<endl;
//         // cout<<ans<<endl;
//     };
//     // vector<pair<int,int>>tmp;
//     // for(int i=1;i<=n;i++){
//     //     tmp.push_back({a[i],i});
//     // }
//     int mxv=-1,pos=1;
//     for(int i=1;i<=n;i++){
//         if(a[i]>mxv){
//             run(pos,i,1);
//             mxv=a[i];
//             pos=i;
//         }
//     }
//     mxv=-1,pos=n;
//     for(int i=n;i>=1;i--){
//         if(a[i]>mxv){
//             run(i,pos,1);
//             mxv=a[i];
//             pos=i;
//         }
//     }
//     for(int i=0;i<=mxsiz;i++){
//         mx[i]=0;
//     }
//     for(int i=1;i<=n;i++){
//         int rnk=lower_bound(vsort.begin(),vsort.end(),a[i])-vsort.begin();
//         rnk=mxsiz-rnk;
//         l[i]=query(rnk-1)+1;
//         upd(rnk,l[i]);
//     }
//     for(int i=0;i<=mxsiz;i++){
//         mx[i]=0;
//     }
//     for(int i=n;i>=1;i--){
//         int rnk=lower_bound(vsort.begin(),vsort.end(),a[i])-vsort.begin();
//         rnk=mxsiz-rnk;
//         r[i]=query(rnk-1)+1;
//         upd(rnk,r[i]);
//     }
//     for(int i=1;i<=n;i++){
//         cout<<l[i]<<" ";
//     }cout<<endl;
//     for(int i=1;i<=n;i++){
//         cout<<r[i]<<" ";
//     }cout<<endl;
//     mxv=-1,pos=1;
//     for(int i=1;i<=n;i++){
//         if(a[i]>mxv){
//             ans=min(ans,n-l[i]);
//             mxv=a[i];
//             pos=i;
//         }
//     }
//     mxv=-1,pos=n;
//     for(int i=n;i>=1;i--){
//         if(a[i]>mxv){
//             ans=min(ans,n-r[i]);
//             mxv=a[i];
//             pos=i;
//         }
//      }
//     cout<<ans<<endl;
// }
// int main(){
//     freopen("donkey.in","r",stdin);
//     int t;
//     cin>>t;
//     while(t--){
//         donkey();
//     }
// }