//Miller Robin模板
//#include<bits/stdc++.h>
//using namespace std;
//long power(long n, long p, long mod) {
//	long ans = 1;
//	while (p > 0) {
//		if ((p & 1) == 1) {
//			ans = (ans * n) % mod;
//		}
//		n = (n * n) % mod;
//		p >>= 1;
//	}
//	return ans;
//}
//bool witness(long a, long n) {
//	long u = n - 1;
//	int t = 0;
//	while ((u & 1) == 0) {
//		t++;
//		u >>= 1;
//	}
//	long x1 = power(a, u, n), x2;
//	for (int i = 1; i <= t; i++) {
//		x2 = power(x1, 2, n);
//		if (x2 == 1 && x1 != 1 && x1 != n - 1) {
//			return true;
//		}
//		x1 = x2;
//	}
//	if (x1 != 1) {
//		return true;
//	}
//	return false;
//}
//long p[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
//bool millerRabin(long n) {
//	if (n <= 2) {
//		return n == 2;
//	}
//	if ((n & 1) == 0) {
//		return false;
//	}
//	for (int i = 0; i < 12 && p[i] < n; i++) {
//		if (witness(p[i], n)) {
//			return false;
//		}
//	}
//	return true;
//}
//int main() {
//	int n;
//	cin >> n;
//}


//埃氏筛与欧拉筛
//#include<bits/stdc++.h>
//using namespace std;
//bool visi[5000005];
//int ehrlich(int n) {
//	memset(visi, 0, sizeof(visi));
//	for (int i = 2; i * i <= n; i++) {
//		if (!visi[i]) {
//			for (int j = i * i; j <= n; j += i) {
//				visi[j] = 1;
//			}
//		}
//	}
//	int cnt = 0;
//	for (int i = 2; i <= n; i++) {
//		if (!visi[i])cnt++;
//	}
//	return cnt;
//}
//int prime[5000005];
//int eular(int n) {
//	memset(visi, 0, sizeof(visi));
//	int cnt = 0;
//	for (int i = 2; i <= n; i++) {
//		if (!visi[i]) {
//			prime[cnt++] = i;
//		}
//		for (int j = 0; j < cnt; j++) {
//			if (i * prime[j] > n)break;
//			visi[i * prime[j]] = 1;
//			if (!(i % prime[j]))break;
//		}
//	}
//	return cnt;
//}
//class Solution {
//public:
//	int countPrimes(int n) {
//		//return ehrlich(n - 1);
//		return eular(n - 1);
//	}
//};


//按公因数计算最大组件大小
//#include<bits/stdc++.h>
//using namespace std;
//int ar[100005];
//int fa[20005];
//int siz[20005];
//int find(int x) {
//    if (fa[x] != x) {
//        fa[x] = find(fa[x]);
//    }
//    return fa[x];
//}
//void Union(int x, int y) {
//    int fx = find(x), fy = find(y);
//    if (fx == fy)return;//一定要return掉不然siz会重复计算
//    siz[fy] += siz[fx];
//    fa[fx] = fy;
//}
//class Solution {
//public:
//    int largestComponentSize(vector<int>& nums) {
//        memset(ar, -1, sizeof(ar));
//        for (int i = 0; i < nums.size(); i++) {
//            fa[i] = i;
//            siz[i] = 1;
//        }
//        for (int j = 0, a; j < nums.size(); j++) {
//            a = nums[j];
//            for (int i = 2; i * i <= a; i++) {
//                if (a % i == 0) {
//                    if (ar[i] == -1)ar[i] = j;
//                    else {
//                        Union(j, ar[i]);
//                        //cout<<j<<" "<<a<<" "<<i<<" "<<ar[i]<<endl;
//                    }
//                }
//                while (a % i == 0) {
//                    a /= i;
//                }
//            }
//            if (a > 1) {
//                if (ar[a] == -1) {
//                    ar[a] = j;
//                }
//                else Union(j, ar[a]);
//            }
//        }
//        // for(int i=0;i<nums.size();i++){
//        //     cout<<fa[i]<<" "<<siz[i]<<endl;
//        // }
//        // for(int i=0;i<40;i++){
//        //     cout<<ar[i]<<endl;
//        // }
//        int ma = -1;
//        for (int i = 0; i < nums.size(); i++) {
//            ma = max(ma, siz[i]);
//        }
//        return ma;
//    }
//};