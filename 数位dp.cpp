//统计各位数字都不同的数字个数
//#include<bits/stdc++.h>
//using namespace std;
//class Solution {
//public:
//    int countNumbersWithUniqueDigits(int n) {
//        if (n == 0)return 1;
//        if (n == 1)return 10;
//        int ans = 10;
//        int t = 9;
//        for (int i = 0; i < n - 1; i++) {
//            t *= 9 - i;
//            ans += t;
//        }
//        return ans;
//    }
//};


//最大为N的数字组合
//#include<bits/stdc++.h>
//using namespace std;
//class Solution {
//public:
//    int f(vector<string>& digits, int n, int offset, int len, int free, int fix) {
//        if (len == 0)return fix;
//        int ans = 0;
//        if (!fix) {
//            ans += f(digits, n, offset / 10, len - 1, 1, 0);
//        }
//        int cur = (n / offset) % 10;
//        if (free) {
//            ans += digits.size() * f(digits, n, offset / 10, len - 1, 1, 1);
//        }
//        else {
//            for (string a : digits) {
//                if (a[0] - '0' < cur) {
//                    ans += f(digits, n, offset / 10, len - 1, 1, 1);
//                }
//                else if (a[0] - '0' == cur) {
//                    ans += f(digits, n, offset / 10, len - 1, 0, 1);
//                }
//                else break;
//            }
//        }
//        return ans;
//    }
//    int atMostNGivenDigitSet(vector<string>& digits, int n) {
//        sort(digits.begin(), digits.end());
//        int t = n / 10;
//        int offset = 1;
//        int len = 1;
//        while (t != 0) {
//            len++;
//            offset *= 10;
//            t /= 10;
//        }
//        return f(digits, n, offset, len, 0, 0);
//    }
//};


//统计整数数目
//#include<bits/stdc++.h>
//using namespace std;
//const int mod = 1e9 + 7;
//int MIN;
//int MAX;
//string num;
//int len;
//int dp[1000][30][3];
//class Solution {
//public:
//    int f(int sum, int i, int free) {
//        if (sum > MAX)return 0;
//        if (sum + (len - i) * 9 < MIN)return 0;
//        if (i == len)return 1;
//        if (dp[sum][i][free] != -1)return dp[sum][i][free];
//        int ans = 0;
//        int cur = num[i] - '0';
//        if (free) {
//            for (int j = 0; j <= 9; j++) {
//                ans = (ans + f(sum + j, i + 1, 1)) % mod;
//            }
//        }
//        else {
//            for (int j = 0; j < cur; j++) {
//                ans = (ans + f(sum + j, i + 1, 1)) % mod;
//            }
//            ans = (ans + f(sum + cur, i + 1, 0)) % mod;
//        }
//        dp[sum][i][free] = ans;
//        return ans;
//    }
//    int count(string num1, string num2, int min_sum, int max_sum) {
//        memset(dp, -1, sizeof(dp));
//        int a = 0, sum = 0;
//        for (int i = 0; i < num1.size(); i++) {
//            sum += num1[i] - '0';
//        }
//        if (sum >= min_sum && sum <= max_sum)a = 1;
//        MIN = min_sum;
//        MAX = max_sum;
//        num = num2;
//        len = num2.size();
//        int a2 = f(0, 0, 0);
//        num = num1;
//        memset(dp, -1, sizeof(dp));
//        len = num1.size();
//        int a1 = f(0, 0, 0);
//        return ((a2 - a1 + mod) % mod + a) % mod;
//    }
//};


//统计特殊整数
//#include<bits/stdc++.h>
//using namespace std;
//string num;
//int len;
//int dp[11][(1 << 10) + 5][2][2];
//class Solution {
//public:
//    int f(int i, int s, int free, int first) {//首位不为0的所有可能情况
//        if (i == len)return 1;
//        if (dp[i][s][free][first] != -1)return dp[i][s][free][first];
//        int cur = num[i] - '0';
//        int ans = 0;
//        if (first) {
//            for (int k = 1; k < cur; k++) {
//                ans += f(i + 1, s | (1 << k), 1, 0);
//            }
//            ans += f(i + 1, s | (1 << cur), 0, 0);
//        }
//        else {
//            if (free) {
//                for (int k = 0; k <= 9; k++) {
//                    if ((s & (1 << k)) == 0) {
//                        ans += f(i + 1, s | (1 << k), 1, 0);
//                    }
//                }
//            }
//            else {
//                for (int k = 0; k < cur; k++) {
//                    if ((s & (1 << k)) == 0) {
//                        ans += f(i + 1, s | (1 << k), 1, 0);
//                    }
//                }
//                if ((s & (1 << cur)) == 0)ans += f(i + 1, s | (1 << cur), 0, 0);
//            }
//        }
//        dp[i][s][free][first] = ans;
//        return ans;
//    }
//    int countSpecialNumbers(int n) {
//        memset(dp, -1, sizeof(dp));
//        num = to_string(n);
//        len = num.size();
//        int ans = 0;
//        int h = 9;
//        for (int i = 1; i <= min(10, int(num.size() - 1)); i++) {
//            ans += h;
//            h *= 10 - i;
//        }
//        ans += f(0, 0, 0, 1);
//        return ans;
//    }
//};


//至少有 1 位重复的数字 与上题其实是同一题互补而已
//统计特殊整数
//#include<bits/stdc++.h>
//using namespace std;
//string num;
//int len;
//int dp[11][(1 << 10) + 5][2][2];
//class Solution {
//public:
//    int f(int i, int s, int free, int first) {//首位不为0的所有可能情况
//        if (i == len)return 1;
//        if (dp[i][s][free][first] != -1)return dp[i][s][free][first];
//        int cur = num[i] - '0';
//        int ans = 0;
//        if (first) {
//            for (int k = 1; k < cur; k++) {
//                ans += f(i + 1, s | (1 << k), 1, 0);
//            }
//            ans += f(i + 1, s | (1 << cur), 0, 0);
//        }
//        else {
//            if (free) {
//                for (int k = 0; k <= 9; k++) {
//                    if ((s & (1 << k)) == 0) {
//                        ans += f(i + 1, s | (1 << k), 1, 0);
//                    }
//                }
//            }
//            else {
//                for (int k = 0; k < cur; k++) {
//                    if ((s & (1 << k)) == 0) {
//                        ans += f(i + 1, s | (1 << k), 1, 0);
//                    }
//                }
//                if ((s & (1 << cur)) == 0)ans += f(i + 1, s | (1 << cur), 0, 0);
//            }
//        }
//        dp[i][s][free][first] = ans;
//        return ans;
//    }
//    int numDupDigitsAtMostN(int n) {
//        memset(dp, -1, sizeof(dp));
//        num = to_string(n);
//        len = num.size();
//        int ans = 0;
//        int h = 9;
//        for (int i = 1; i <= min(10, int(num.size() - 1)); i++) {
//            ans += h;
//            h *= 10 - i;
//        }
//        ans += f(0, 0, 0, 1);
//        return n - ans;
//    }
//};


//windy数
//#include<bits/stdc++.h>
//using namespace std;
//string num;
//int len;
//int f(int i,int last,int free,int fix) {
//	if (i == len)return fix;
//	int ans = 0;
//	int cur = num[i] - '0';
//	if (free) {
//		if (fix) {
//			for (int k = 0; k <= 9; k++) {
//				if(abs(last-k)>=2)
//				ans += f(i + 1, k, 1, 1);
//			}
//		}
//		else {
//			ans += f(i + 1, -2, 1, 0);
//			for (int k = 1; k <= 9; k++) {
//				ans += f(i + 1, k, 1, 1);
//			}
//		}
//	}
//	else {
//		if (fix) {
//			for (int k = 0; k < cur; k++) {
//				if(abs(k-last)>=2)
//				ans += f(i + 1, k, 1, 1);
//			}
//			if (abs(last - cur) >= 2)ans += f(i + 1, cur, 0, 1);
//		}
//		else {
//			ans += f(i + 1, -2, 1, 0);
//			for (int k = 1; k < cur; k++) {
//				ans += f(i + 1, k, 1, 1);
//			}
//			ans += f(i + 1, cur, 0, 1);	
//		}
//	}
//	return ans;
//}
//int main() {
//	int a, b;
//	cin >> a >> b;
//	string a1 = to_string(a-1);
//	string b1 = to_string(b);
//	num = a1;
//	len = a1.size();
//	int a2 = f(0,-2,0,0);
//	num = b1;
//	len = b1.size();
//	int b2 = f(0,-2,0,0);
//	if (a - 1 == 0)a2 = 0;
//	cout <<b2-a2 << endl;
//}


//萌数
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int mod = 1e9 + 7;
//string num;
//int len;
//int dp[1005][12][12][2][2];
//ll f(int i, int p, int pp, int free, int fix) {
//	if (i == len)return fix&&i>=2;
//	if (dp[i][p][pp][free][fix] != -1)return dp[i][p][pp][free][fix];
//	int ans = 0;
//	int cur = num[i] - '0';
//	if (!fix) {
//		ans = (ans + f(i + 1, -1, -1, 1, 0)) % mod;
//	}
//	if (free) {
//		for (int k = fix ? 0 : 1; k <= 9; k++) {
//			if (k != p && k != pp)
//				ans = (ans + f(i + 1, k, p, 1, 1)) % mod;
//		}
//	}
//	else {
//		for (int k = fix ? 0 : 1; k < cur; k++) {
//			if (k != p && k != pp)
//				ans = (ans + f(i + 1, k, p, 1, 1)) % mod;
//		}
//		if (cur != p && cur != pp) {
//			ans = (ans + f(i + 1, cur, p, 0, 1)) % mod;
//		}
//	}
//	dp[i][p][pp][free][fix] = ans;
//	return ans;
//}
//int main() {
//	string l, r;
//	cin >> l >> r;
//	num = l;
//	len = l.size();
//	memset(dp, -1, sizeof(dp));
//	int a1 = f(0, 10, 10, 0, 0);
//	num = r;
//	len = r.size();
//	memset(dp, -1, sizeof(dp));
//	int a2 = f(0, 10, 10, 0, 0);
//	int a = 1;
//	for (int i = 1; i < l.size(); i++) {
//		if (i > 0 && l[i] == l[i - 1]) {
//			a = 0;
//			break;
//		}
//		if (i > 1 && l[i] == l[i - 2]) {
//			a = 0;
//			break;
//		}
//	}
//	if (l.size() < 2)a = 0;
//	int noMeng = a2 - a1 + a;
//	ll ln = 0, rn = 0;
//	for (int i = 0; i <l.size(); i++) {
//		ln = ((ln * 10) % mod + l[i]-'0') % mod;
//	}
//	for (int i = 0; i < r.size(); i++) {
//		rn = ((rn * 10) % mod + r[i]-'0') % mod;
//	}
//	cout << ((rn - ln + 1 + mod) % mod - noMeng + mod)%mod << endl;
//}


//不含连续1的非负整数
//建议看左程云解法
//#include<bits/stdc++.h>
//using namespace std;
//string num;
//int len;
//int dp[35][2][2][2];
//int f(int i, int p, int free, int fix) {
//    if (i == len)return fix;
//    if (dp[i][p][free][fix] != -1)return dp[i][p][free][fix];
//    int ans = 0;
//    int cur = num[i] - '0';
//    if (!fix) {
//        ans += f(i + 1, 0, 1, 0);
//    }
//    if (free) {
//        if (fix)ans += f(i + 1, 0, 1, 1);
//        if (p != 1)ans += f(i + 1, 1, 1, 1);
//    }
//    else {
//        if (cur == 0) {
//            if (fix)ans += f(i + 1, 0, 0, 1);
//        }
//        if (cur == 1) {
//            if (fix)ans += f(i + 1, 0, 1, 1);
//            if (p != 1)ans += f(i + 1, 1, 0, 1);
//        }
//    }
//    dp[i][p][free][fix] = ans;
//    return ans;
//}
//class Solution {
//public:
//    int findIntegers(int n) {
//        memset(dp, -1, sizeof(dp));
//        string tnum = "";
//        while (n != 0) {
//            if (n % 2) {
//                tnum += '1';
//            }
//            else {
//                tnum += '0';
//            }
//            n /= 2;
//        }
//        reverse(tnum.begin(), tnum.end());
//        num = tnum;
//        len = tnum.size();
//        return f(0, 0, 0, 0) + 1;//加上0
//    }
//};


//数字计数
//建议看左程云解法
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//string num;
//int len;
//int d;
//int dp[64][2][2][64];
//int f(int i, int free, int fix, int cnt) {
//	if (i == len) {
//		if (fix)return cnt;
//		return 0;
//	}
//	if (dp[i][free][fix][cnt] != -1)return dp[i][free][fix][cnt];
//	int ans = 0;
//	int cur = num[i] - '0';
//	if (!fix) {
//		ans += f(i + 1, 1, 0, cnt);
//	}
//	if (free) {
//		for (int k = fix ? 0 : 1; k <= 9; k++) {
//			if (k == d) {
//				ans += f(i + 1, 1, 1, cnt + 1);
//			}
//			else {
//				ans += f(i + 1, 1, 1, cnt);
//			}
//		}
//	}
//	else {
//		for (int k = fix ? 0 : 1; k < cur; k++) {
//			if (k == d) {
//				ans += f(i + 1, 1, 1, cnt + 1);
//			}
//			else {
//				ans += f(i + 1, 1, 1, cnt);
//			}
//		}
//		if (cur == d) {
//			ans += f(i + 1, 0, 1, cnt + 1);
//		}
//		else {
//			ans += f(i + 1, 0, 1, cnt);
//		}
//	}
//	dp[i][free][fix][cnt] = ans;
//	return ans;
//}
//signed main() {
//	string a, b;
//	cin >> a >> b;
//	for (int i = 0; i <= 9; i++) {
//		int cntA = 0;
//		d = i;
//		for (int j = 0; j < a.size(); j++) {
//			if (a[j]-'0' == i) {
//				cntA++;
//			}
//		}
//		num = b;
//		len = b.size();
//		memset(dp, -1, sizeof(dp));
//		int b1 = f(0, 0, 0, 0);
//		num = a;
//		len = a.size();
//		memset(dp, -1, sizeof(dp));
//		int a1 = f(0, 0, 0, 0);
//		cout << b1 - a1 + cntA<<" ";
//	}
//	cout << endl;
//}