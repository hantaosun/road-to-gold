//manacher算法模板
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 11000001;
//int p[MAXN<<1];
//string ss;
//void manacherss(string s) {
//	ss.resize(2 * s.size() + 1);
//	for (int i = 0,j=0; i < 2*s.size()+1; i++) {
//		ss[i] = i & 1 ? s[j++] : '#';
//	}
//}
//int manacher(string s) {
//	manacherss(s);
//	int n = s.size()*2+1;
//	int ans = 0;
//	for (int i = 0, c = 0, r = 0, len; i < n; i++) {
//		len = r > i ? min(p[2 * c - i], r - i):1;//被包住则初始长度取决于关于中心位置对称的点的对称半径,否则则是单个字符为1
//		while (i + len < n && i - len >= 0 && ss[i + len] == ss[i - len]) {
//			len++;
//		}
//		if (i + len > r) {
//			r = i+len;
//			c = i;
//		}
//		ans = max(ans, len);
//		p[i] = len;
//	}
//	return ans - 1;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	string s;
//	cin >> s;
//	cout << manacher(s) << endl;
//}


//扩展kmp
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int MAXN = 20000001;
//string a, b;
//int z[MAXN];
//int e[MAXN];
//void zArray(string b) {
//	z[0] = b.size();
//	for (int i = 1, c = 1, r = 1, len; i < b.size(); i++) {
//		len = r > i ? min(r - i, z[i - c]) : 0;
//		while (i + len < b.size() && b[i + len] == b[len]) {
//			len++;
//		}
//		if (i + len > r) {
//			r = i + len;
//			c = i;
//		}
//		z[i] = len;
//	}
//}
//void eArray(string a) {
//	for (int i = 0, c = 0, r = 0, len; i < a.size(); i++) {
//		len = r > i ? min(z[i-c], r - i) : 0;
//		while (i + len < a.size() &&len<b.size()&& a[i + len] == b[len]) {
//			len++;
//		}
//		if (i + len > r) {
//			r = i + len;
//			c = i;
//		}
//		e[i] = len;
//	}
//}
//int main() {
//	cin >> a >> b;
//	zArray(b);
//	eArray(a);
//	ll wz=0,we=0;
//	for (int i = 0; i < b.size(); i++) {
//		wz ^= (ll)(z[i] + 1) * (i + 1);
//	}
//	for (int i = 0; i < a.size(); i++) {
//		we ^= (ll)(e[i] + 1) * (i + 1);
//	}
//	cout << wz << endl;
//	cout << we << endl;
//}


//将单词恢复初始状态所需的最短时间
//#include<bits/stdc++.h>
//using namespace std;
//int z[1000010];
//void zArray(string word) {
//    z[0] = word.size();
//    for (int i = 1, c = 1, r = 1, len; i < word.size(); i++) {
//        len = r > i ? min(r - i, z[i - c]) : 0;
//        while (i + len < word.size() && word[i + len] == word[len]) {
//            len++;
//        }
//        if (i + len > r) {
//            c = i;
//            r = i + len;
//        }
//        z[i] = len;
//    }
//}
//class Solution {
//public:
//    int minimumTimeToInitialState(string word, int k) {
//        zArray(word);
//        for (int i = k; i < word.size(); i += k) {
//            if (z[i] + i == word.size()) {
//                return i / k;
//            }
//        }
//        return (word.size() + k - 1) / k;
//    }
//};


//最长回文子串
//#include<bits/stdc++.h>
//using namespace std;
//int p[2005];
//string ss;
//void manacherss(string s) {
//    ss.resize(s.size() * 2 + 1);
//    for (int i = 0, j = 0; i < s.size() * 2 + 1; i++) {
//        ss[i] = i & 1 ? s[j++] : '#';
//    }
//}
//void manacher() {
//    for (int i = 0, c = 0, r = 0, len; i < ss.size(); i++) {
//        len = r > i ? min(r - i, p[2 * c - i]) : 1;
//        while (i + len < ss.size() && i - len >= 0 && ss[i + len] == ss[i - len]) {
//            len++;
//        }
//        if (i + len > r) {
//            r = i + len;
//            c = i;
//        }
//        p[i] = len;
//    }
//}
//class Solution {
//public:
//    string longestPalindrome(string s) {
//        int M = -1, pos = -1;
//        manacherss(s);
//        manacher();
//        for (int i = 0; i < ss.size(); i++) {
//            if (p[i] > M) {
//                M = p[i];
//                pos = i;
//            }
//        }
//        string ans = "";
//        for (int i = pos - M + 1; i <= pos + M - 1; i++) {
//            if (ss[i] != '#') {
//                ans += ss[i];
//            }
//        }
//        return ans;
//    }
//};


//回文子串
//#include<bits/stdc++.h>
//using namespace std;
//string ss;
//int p[2010];
//void manacherss(string s) {
//    ss.resize(2 * s.size() + 1);
//    for (int i = 0, j = 0; i < 2 * s.size() + 1; i++) {
//        ss[i] = i & 1 ? s[j++] : '#';
//    }
//}
//void manacher() {
//    for (int i = 0, c = 0, r = 0, len; i < ss.size(); i++) {
//        len = r > i ? min(r - i, p[2 * c - i]) : 1;
//        while (i + len < ss.size() && i - len >= 0 && ss[i + len] == ss[i - len]) {
//            len++;
//        }
//        if (i + len > r) {
//            r = i + len;
//            c = i;
//        }
//        p[i] = len;
//    }
//}
//class Solution {
//public:
//    int countSubstrings(string s) {
//        manacherss(s);
//        manacher();
//        int ans = 0;
//        for (int i = 0; i < ss.size(); i++) {
//            cout << p[i] << endl;
//            ans += p[i] / 2;
//        }
//        return ans;
//    }
//};


//不重叠回文子字符串的最大数目
//#include<bits/stdc++.h>
//using namespace std;
//string ss;
//void manacherss(string s) {
//    int n = s.size();
//    ss.resize(2 * n + 1);
//    for (int i = 0, j = 0; i < 2 * n + 1; i++) {
//        ss[i] = i & 1 ? s[j++] : '#';
//    }
//}
//int p[4005];
//int  manacher(int l,int k) {
//    int n = ss.size();
//    for (int i = l, c = l, r = l, len; i < n; i++) {
//        len = r > i ? min(r - i, p[2 * c - i]) : 1;
//        while (i + len < n && i - len >= l && ss[i + len] == ss[i - len]) {
//            if (++len > k) {
//                return i + k + (ss[i + k] != '#');
//            }
//            if (++len > k) {
//                return i + len - (ss[i + len - 1] == '#');//这样写也对,i+len是回文串的下一个位置
//            }
//        }
//        if (i + len > r) {
//            r = i + len;
//            c = i;
//        }
//        p[i] = len;
//    }
//    return -1;
//}
//int dp[4005];
//class Solution {
//public:
//    int maxPalindromes(string s, int k) {
//        manacherss(s);
//        int a=manacher(0,k);
//        int ans = 0;
//        while (a != -1) {
//            a = manacher(a, k);
//            ans++;
//        }
//        return ans;
//    }
//};


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n, k;
//const int mod = 19930726;
//char c[1000010];
//char ss[2000010];
//int p[2000010];
//void manacherss() {
//	for (int i = 0, j = 0; i < n * 2 + 1; i++) {
//		ss[i] = i & 1 ? c[j++] : '#';
//	}
//}
//void manacher() {
//	for (int i = 0, r = 0, c = 0, len; i < 2 * n + 1; i++) {
//		len = r > i ? min(r - i, p[2 * c - i]) : 1;
//		while (i + len < 2 * n + 1 && i - len >= 0 && ss[i + len] == ss[i - len]) {
//			len++;
//		}
//		if (i + len > r) {
//			r = i + len;
//			c = i;
//		}
//		p[i] = len;
//	}
//}
//int qmi(int a, int b) {
//	
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = (ans * a) % mod;
//		}
//		b >>= 1;
//		a = (a * a) % mod;
//	}
//	return ans;
//}
//int di[2000010];
//signed main() {
//	cin >> n >> k;
//	for (int i = 0; i < n; i++) {
//		cin >> c[i];
//	}
//	manacherss();
//	manacher();
//	/*for (int i = 0; i < 2 * n + 1; i++) {
//		cout << p[i] << " ";
//	}
//	cout << endl;*/
//	int sum = 0;
//	for (int i = 0; i < 2 * n + 1; i++) {
//		if ((p[i] - 1) % 2) {
//			sum += p[i] - 1;
//		}
//		if (i & 1) {
//			di[1] += 1;
//			di[p[i]+1] -= 1;
//		}
//		else {
//			di[0] += 1;
//			di[p[i]+1] -= 1;
//		}
//	}
//	if (sum < k) {
//		cout << -1 << endl;
//		return 0;
//	}
//	//for (int i = 0; i < 2 * n + 1; i++) {
//	//	cout << di[i] << " ";
//	//}
//	//cout << endl;
//	int ans = 1;
//	for (int i = 2; i < 2 * n + 1; i++) {
//		di[i] = di[i] + di[i - 2];
//	}
//	//for (int i = 0; i < 2 * n + 1; i++) {
//	//	cout << di[i] << " ";
//	//}
//	//cout << endl;
//	for (int i = n,cnt=0; cnt<k&&i >= 1; i--) {
//		if ((i & 1) && di[i] != 0) {
//			ans = (ans * qmi(i, min(k - cnt, di[i])))%mod;
//			cnt += min(k - cnt, di[i]);
//		}
//	}
//	cout << ans << endl;
//}


//最长双回文串***********
//#include<bits/stdc++.h>
//using namespace std;
//string s,ss;
//int p[200010];
//int lef[200010];
//int rig[200010];
//void manacherss() {
//	ss.resize(s.size()*2+1);
//	for (int i = 0,j=0; i < ss.size(); i++) {
//		ss[i] = i & 1?s[j++] : '#';
//	}
//}
//void manacher() {
//	for (int i = 0,c=0,r=0,len; i < ss.size(); i++) {
//		len = r - i > 0 ? min(r - i, p[2 * c - i]) : 1;
//		while (i + len < ss.size() && i - len >= 0 && ss[i + len] == ss[i - len]) {
//			len++;
//		}
//		if (i + len > r) {
//			r = i + len;
//			c = i;
//		}
//		p[i] = len;
//	}
//}
//int main() {
//	cin >> s;
//	manacherss();
//	manacher();
//	for (int i = 0,j=0; i < ss.size(); i++) {
//		while (i + p[i] > j) {
//			lef[j] = j - i;
//			j += 2;
//		}
//	}
//	for (int i = ss.size() - 1, j = ss.size() - 1; i >= 0; i--) {
//		while (i - p[i] < j) {
//			rig[j] = i - j;
//			j -= 2;
//		}
//	}
//	int ans = 0;
//	for (int i = 2; i < ss.size()-2; i += 2) {
//		ans = max(ans,lef[i]+rig[i]);
//	}
//	cout << ans << endl;
//}