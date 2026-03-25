//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void donkey(){
//	int n,c,k;
//	cin>>n>>c>>k;
//	vector<int>a(n+1);
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	sort(a.begin()+1,a.end());
//	for(int i=1;i<=n;i++){
//		if(c<a[i])break;
//		else if(c==a[i])c+=a[i];
//		else{
//			if(k!=0){
//				int tmp=min(k,c-a[i]);
//				c+=a[i]+tmp;
//				k-=tmp;
//			}
//			else{
//				c+=a[i];
//			}		
//		}
//	}
//	cout<<c<<endl;
//}
//signed main(){
//	int t;
//	cin>>t;
//	while(t--){
//		donkey();
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void donkey(){
//	int n;
//	cin>>n;
//	vector<int>a(n+1);
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	for(int i=1;i<=n;i++){
//		int cnt=0;
//		int cnt1=0;
//		for(int j=i+1;j<=n;j++){
//			if(a[j]>a[i])cnt++;
//			else if(a[j]<a[i])cnt1++;
//		}
//		cout<<max(cnt1,cnt)<<" ";
//	}cout<<endl;
//}
//signed main(){
//	int t;
//	cin>>t;
//	while(t--){
//		donkey();
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int ask(int i,int j){
//	cout<<"? "<<i<<" "<<j<<endl;
//	int t;
//	cin>>t;
//	return t;
//}
//void donkey(){
//	int n;
//	cin>>n;
//	for(int i=1;i<=2*n-2;i+=2){
//		int tmp=ask(i,i+1);
//		if(tmp==1){
//			cout<<"! "<<i<<endl;
//			return;
//		}
//	}
//	int tmp=ask(2*n-2,2*n-1);
//	if(tmp==1){
//		cout<<"! "<<2*n-2<<endl;
//		return;
//	}
//	tmp=ask(2*n-3,2*n-1);
//	if(tmp==1){
//		cout<<"! "<<2*n-3<<endl;
//		return;
//	}
//	cout<<"! "<<2*n<<endl;
//}
//signed main(){
//	int t;
//	cin>>t;
//	while(t--){
//		donkey();
//	}
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void donkey(){
//	int r,g,b;
//	cin>>r>>g>>b;
//	vector<pair<int,char>>a(3);
//	a[0]={r,'R'};
//	a[1]={g,'G'};
//	a[2]={b,'B'};
//	sort(a.begin(),a.end());
//	if(a[2].first>=a[1].first+a[0].first){
//		for(int i=1;i<=a[0].first;i++){
//			cout<<a[2].second<<a[0].second;
//		}
//		for(int i=1;i<=a[1].first;i++){
//			cout<<a[2].second<<a[1].second;
//		}
//		if(a[2].first-a[1].first-a[0].first>0){
//			cout<<a[2].second;
//		}
//		cout<<endl;
//		return;
//	}
//	else{
//		int c0=a[2].first-a[1].first;
//		int c1=a[2].first-a[0].first;
//		int rst=a[2].first-c0-c1;
//		for(int i=1;i<=c0;i++){
//			cout<<a[0].second<<a[2].second;
//		}
//		for(int i=1;i<=c1;i++){
//			cout<<a[1].second<<a[2].second;
//		}
//		int cur=1;
//		for(int i=1;i<=rst;i++){
//			cout<<a[cur].second<<a[(cur+1)%3].second<<a[(cur+2)%3].second;
//			cur=(cur+1)%3;
//		}
//		cout<<endl;
//		return;
//	}
//}
//signed main(){
//	int t;
//	cin>>t;
//	while(t--){
//		donkey();
//	}
//}

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void donkey(){
//	int n,q;
//	cin>>n>>q;
//	string s;
//	cin>>s;	s=" "+s;
//	int l,r;
//	for(int i=1,ll,rr;i<=q;i++){
//		cin>>ll>>rr;
//		vector<int>z(rr-ll+2,0);
//		l=0,r=0;
//		int tn=rr-ll+1;
//		for(int i=1;i<tn;i++){
//			if (i > r) {
//				l = r = i;
//				while (r < tn && s[r+ll] == s[r - l+ll]) {
//					r++;
//				}
//				z[i] = r - l;
//				r--;
//			} 
//			else {
//				int k = i - l;
//				if (z[k] < r - i + 1) {
//					z[i] = z[k];
//				} 
//				else {
//					l = i;
//					while (r < tn && s[r+ll] == s[r - l+ll]) {
//						r++;
//					}
//					z[i] = r - l;
//					r--;
//				}
//			}
//		}		
//		z[0]=tn;
//		vector<int>dp(rr-ll+2,-1);//当前位置往后能配出多少个,如果当前位置不能配就是-1
//		int pmax=0;
//		int lst=rr-ll;
//		for(int i=rr-ll;i>=0;i--){
//			if(z[i]!=0){
//				if(i+z[i]>=lst-1){
//					dp[i]=pmax+1;
//				}
//			}
//			if(dp[i]!=-1){
//				lst=i;
//				pmax=max(pmax,dp[i]);
//			}
//		}
////		for(int i=0;i<=rr-ll;i++){
////			cout<<z[i]<<" ";
////		}cout<<endl;
////		for(int i=0;i<=rr-ll;i++){
////			cout<<dp[i]<<" ";
////		}cout<<endl;
//		cout<<dp[0]<<endl;
//	}
//}
//signed main(){
//	int t;
//	cin>>t;
//	while(t--){
//		donkey();
//	}
//}
