//#include<bits/stdc++.h>
//using namespace std;
//const int base = 499;
//int f(char c) {
//	if (c >= '0' && c <= '9') {
//		return c - '0';
//	}
//	else if (c >= 'a' && c <= 'z') {
//		return 10 + c - 'a';
//	}
//	else return 36 + c - 'A';
//}
//int Hash(string s) {
//	int ans = 0;
//	for (int i = 0; i < s.size(); i++) {
//		ans = ans * base + f(s[i]);
//	}
//	return ans;
//}
//int main() {
//	int N;
//	cin >> N;
//	string s;
//	vector<int>num;
//	for (int i = 1; i <= N; i++) {
//		cin >> s;
//		num.push_back(Hash(s));
//	}
//	sort(num.begin(), num.end());
//	int cnt = 1;
//	for (int i = 1; i < num.size(); i++) {
//		if (num[i] != num[i - 1])cnt++;
//	}
//	cout << cnt << endl;
//}


//子串哈希值
//#include<bits/stdc++.h>
//#define ull unsigned long long
//using namespace std;
//const int base = 1314;
//ull power[10005];
//ull Hash[10005];
//class Solution {
//public:
//    int strStr(string haystack, string needle) {
//        power[0] = 1;
//        for (int i = 1; i < 10005; i++) {
//            power[i] = power[i - 1] * base;
//        }
//        ull h = 0;
//        for (int i = 0; i < haystack.size(); i++) {
//            h = h * base + haystack[i] - 'a' + 1;
//            Hash[i] = h;
//        }
//        h = 0;
//
//        for (int i = 0; i < needle.size(); i++) {
//            h = h * base + needle[i] - 'a' + 1;
//        }
//        if (h == Hash[needle.size() - 1])return 0;
//        // cout<<h<<endl;
//        // cout<<endl;
//        // for (int l = 1,r=needle.size(); r < haystack.size(); l++,r++) {
//        //     cout<<Hash[r] - Hash[l - 1] * power[r - l + 1]<<" ";
//        // }
//        for (int l = 1, r = needle.size(); r < haystack.size(); l++, r++) {
//            if (h == Hash[r] - Hash[l - 1] * power[r - l + 1])
//                return l;
//        }
//        return -1;
//    }
//};


//重复叠加子串匹配
//#include<bits/stdc++.h>
//#define ull unsigned long long
//using namespace std;
//const int base = 499;
//ull power[30005];
//ull Hash[30005];
//class Solution {
//public:
//    int repeatedStringMatch(string a, string b) {
//        string s = a;
//        while (s.size() < b.size()) {
//            s += a;
//        }
//        s += a;
//        power[0] = 1;
//        for (int i = 1; i < 30005; i++) {
//            power[i] = power[i - 1] * base;
//        }
//        Hash[0] = s[0] - 'a' + 1;
//        for (int i = 1; i < s.size(); i++) {
//            Hash[i] = Hash[i - 1] * base + s[i] - 'a' + 1;
//        }
//        ull h = 0;
//        for (int i = 0; i < b.size(); i++) {
//            h = h * base + b[i] - 'a' + 1;
//        }
//        if (h == Hash[b.size() - 1])return (b.size() + a.size() - 1) / a.size();
//        for (int l = 1, r = b.size(); r < s.size(); l++, r++) {
//            // cout<<h<<endl;
//            // cout<<r<<" "<<l<<" "<<Hash[r] - Hash[l-1] * power[r - l + 1]<<endl;
//            if (h == Hash[r] - Hash[l - 1] * power[r - l + 1]) {
//                return (r + a.size()) / a.size();
//            }
//        }
//        return -1;
//    }
//};



//#include<bits/stdc++.h>
//#include<unordered_map>
//#include<unordered_set>
//#define ull unsigned long long
//using namespace std;
//const int base = 499;
//ull f(string s) {
//    ull h = 0;
//    for (int i = 0; i < s.size(); i++) {
//        h = h * base + s[i] - 'a' + 1;
//    }
//    return h;
//}
//ull power[10005];
//ull Hash[10005];
//ull getH(int l, int r) {
//    if (l == 0)return Hash[r];
//    return Hash[r] - Hash[l] * (r - l + 1);
//}
//class Solution {
//public:
//    vector<int> findSubstring(string s, vector<string>& words) {
//        power[0] = 1;
//        for (int i = 1; i < 10005; i++) {
//            power[i] = power[i - 1] * base;
//        }
//        ull h = 0;
//        for (int i = 0; i < s.size(); i++) {
//            h = h * base + s[i] - 'a' + 1;
//            Hash[i] = h;
//        }
//        unordered_set<ull>dic;
//        int n = words[0].size();
//        for (auto ss : words) {
//            dic.insert(f(ss));
//        }
//        int kinds = 0;
//        vector<int>ans;
//        unordered_map<ull, int>map;
//        for (int k = 0; k < n; k++) {
//            int l = k, r = k;
//            while (r + n - 1 < s.size() && (r - l) / n < words.size()) {
//                int temp = getH(r, r + n - 1);
//                if (dic.count(temp)) {
//                    if (map[temp]++ == 0)kinds++;
//                }
//                r += n;
//            }
//            if (kinds == words.size())ans.push_back(l);
//            while (r + n - 1 < s.size()) {
//                int rt = getH(r, r + n - 1);
//                int lt = getH(l, l + n - 1);
//                if (dic.count(lt)) {
//                    if (--map[lt] == 0) {
//                        kinds--;
//                    }
//                }
//                if (dic.count(rt)) {
//                    if (map[rt]++ == 0) {
//                        kinds++;
//                    }
//                }
//                if (kinds == words.size())ans.push_back(l);
//                l += n;
//                r += n;
//            }
//        }
//        return ans;
//    }
//};



//DNA
//#include<iostream>
//#define ull unsigned long long
//using namespace std;
//string s, t;
//int g(char a) {
//	switch (a) {
//	case 'C':return 1;
//	case 'A':return 2;
//	case 'G':return 3;
//	case 'T':return 4;
//	}
//}
//const int base = 499;
//ull Shash[100010];
//ull Thash[100010];
//ull power[100010];
//ull SgetH(int l,int r) {
//	if (l == 0)return Shash[r];
//	return Shash[r] - Shash[l - 1] * power[r - l + 1];
//}
//ull TgetH(int l,int r) {
//	if (l == 0)return Thash[r];
//	return Thash[r] - Thash[l - 1] * power[r - l + 1];
//}
//int bs(int l, int r, int l1, int r1) {//在s的l-r上与t的l1-r1上找到第一个不相等的字符据l的长度
//	int l2 = 0, r2 = r - l;
//	int ans = -1;
//	while (l2<=r2) {
//		int m = l2+r2>>1;
//		//cout <<string(s,l,m+1)<<endl;
//		//cout << string(t, l1, m+1) << endl;
//		//cout << m << endl;
//		//cout << SgetH(l, l + m) << " " << TgetH(l1, l1 + m) << endl;
//		if (SgetH(l, l + m) == TgetH(l1, l1 + m)) {
//			l2 = m + 1;
//		}
//		else {
//			r2 = m - 1;
//			ans = m;
//		}
//	}
//	return ans==-1?-1:l+ans;
//}	
//bool judge(int l,int r) {
//	//cout << endl;
//	//cout << "--------------------\n";
//	//cout << string(s, l,t.size()) << " " << t << endl;
//	int a = bs(l, r, 0,t.size() - 1);
//	if (a== -1) {
//		return 1;
//	}
//	else {
//		//cout << "find the first\n";
//		//cout << "a："<< a << endl;
//		a =bs(a+1, r, a+1-l,t.size()-1);
//		if (a == -1)return 1;
//		else {
//			//cout << "find the second\n";
//			//cout << "a：" << a << endl;
//			a = bs(a + 1, r, a + 1 -l, t.size() - 1);
//			if (a == -1)return 1;
//			else {
//				//cout << "find the third\n";
//				//cout << "a：" << a << endl;
//				a =bs(a + 1, r, a + 1-l, t.size()-1);
//				if (a == -1) {
//					return 1;
//				}
//				else { 
//					//cout << "fine the forth\n";
//					//cout << "a:" << a << endl;
//					return 0;
//				}
//			}
//		}
//	}
//	return 0;
//}
//void solve() {
//
//	cin >> s >> t;
//	ull h = 0;
//	for (int i = 0; i < s.size(); i++) {
//		h= h * base + g(s[i]);
//		Shash[i] = h;
//	}
//	h = 0;
//	for (int i = 0; i < t.size(); i++) {
//		h= h * base + g(t[i]);
//		Thash[i] = h;
//	}
//	int ans = 0;
//	for (int l = 0, r = t.size() - 1; r < s.size(); l++,r++) {
//		if (judge(l, r)) {
//			ans++;
//		}
//	}
//	cout << ans << endl;
//}
//int main() {
//	power[0] = 1;
//	for (int i = 1; i < 100010; i++) {
//		power[i] = power[i - 1] * base;
//	}
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}