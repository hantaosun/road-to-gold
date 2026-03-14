#include<bits/stdc++.h>
#define int  long long
using namespace std;
signed main(){
	int n,k;
	cin>>n>>k;
	vector<int>d(n+1);
	vector<int>r(n+1);
	vector<int>l(n+1);
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	int rr=1;
	for(int i=1;i<=n;i++){
		while(rr<=n&&1+(rr-i)*k<d[rr])rr++;
		r[i]=rr;
	}
	int ll=n;
	for(int i=n;i>=1;i--){
		while(ll>=1&&1+(i-ll)*k<d[ll])ll--;
		l[i]=ll;
	}
//	for(int i=1;i<=n;i++){
//		cout<<"("<<l[i]<<','<<r[i]<<")  ";
//	}cout<<endl;
	int mxp=-1,mx=0;
	for(int i=1;i<=n;i++){
		int ans=(1+(1+(r[i]-i-1)*k))*(r[i]-i)/2+(1+(1+(i-l[i]-1)*k))*(i-l[i])/2-1;
		if(l[i]>=1){
			ans+=d[l[i]];
		}
		if(r[i]<=n){
			ans+=d[r[i]];
		}
		if(ans>mx){
			mx=ans;
			mxp=i;
		}
	}
	cout<<mxp<<" "<<mx<<endl;
}
