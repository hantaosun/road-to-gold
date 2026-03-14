//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 5;
//vector<vector<int>>g;
//int dep[2 * N];
//void dfs(int u, int pa) {
//	dep[u] = dep[pa] + 1;
//	for (auto v : g[u]){
//		if (v == pa)continue;
//		dfs(v, u);
//	}
//}
//void solve() {
//	int n;
//	cin >> n;
//	g.assign(2 * n + 1, {});
//	for (int i = 1,u,v; i < 2 * n; i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	dep[0] = 0;
//	dfs(1, 0);
//	vector<int>c(2 * n + 1);
//	vector<int>leaf;
//	int diff = 0;
//	for (int i = 1; i <= 2 * n; i++) {
//		if (dep[i] & 1) {
//			c[i] = 1;
//			diff++;
//		}
//		else {
//			c[i] = 0;
//			diff--;
//		}
//		if (g[i].size() == 1 && i != 1) {
//			leaf.push_back(i);
//		}
//	}
//	for (auto v : leaf) {
//		if (diff == 0)break;
//		if (diff < 0) {
//			if (c[v] == 0) {
//				diff += 2;
//				c[v] = 1;
//			}
//		}
//		else {
//			if (c[v] == 1) {
//				diff -= 2;
//				c[v] = 0;
//			}
//		}
//	}
//	for (int i = 1; i <= 2 * n; i++) {
//		cout << c[i] << " ";
//	}
//	cout << endl;
//}
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//}

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int qpow(int a, int b,int mod) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans =ans* a%mod;
//		}
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ans;
//}
//int exgcd(int a, int b, int& x, int& y) {
//	if (b == 0) {
//		x = 1;
//		y = 0;
//		return a;
//	}
//	int x1, y1;
//	int g = exgcd(b, a % b, x1, y1);
//	x = y1;
//	y = x1 - (a / b) * y1;
//	return g;
//}
//void solve() {
//	int a,b,n;
//	cin >> a >> b >> n;
//	int ivb, xx;
//	exgcd(b,a,ivb,xx);
//	int mod = a / gcd(a, b);
//	ivb = (ivb % mod + mod) % mod;
//	int x = (a - n % a)%a * ivb%a;
//	//cout << ivb << "************\n";
//	//cout <<ivb*b%a<<" "<<ivb << " " << x << "&\n";
//	//cout << x * b % a << " " << (a - n % a) % a << "^\n";
//	//cout << (n + x * b) % a << "&&&\n";
//	//cout << x << "--------------\n";
//	assert((n + x * b) % a == 0);
//	int nx = (n + x*b) / a;
//	cout << nx << "nx\n";
//	if (nx % a == 0) {
//		cout << "No1\n";
//		return;
//	}
//	if (nx % b != n % b) {
//		cout << "No\n";
//	}
//	else {
//		cout << "Yes\n";
//	}
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//string substr(string s, int l, int r) {
//	return s.substr(l, r - l + 1);
//}
////int stoi(string tt) {
////	cout << tt << endl;
////	int num = 0;
////	for (int i = 0; i < tt.size(); i++) {
////		num *= 10;
////		num += tt[i];
////	}
////}
//string fi;
//int fs;
//vector<int>ans;
//vector<int>op1;
//void dfs(vector<pair<string, int>>& sb, vector<int>& path, int i, int proms, int tim) {
//	if (!ans.empty())return;
//	if (i == sb.size()) {
//		int fsiz = fi.size();
//		{//Ã»Í¨¹ý
//			//for (auto v : path) {
//			//	cout << v << " ";
//			//}cout << endl;
//			//cout << proms << " " << tim << endl;
//			for (int j = 0; j < fsiz - 1; j++) {
//				for (int k = j + 1; k < fsiz - 1; k++) {
//					int pass = stoi(substr(fi, 0, j));
//					int ttim = stoi(substr(fi, j + 1, k));
//					string t = substr(fi, k + 1, fsiz - 1);
//					int ap = 0;
//					int tr = 0;
//					int ftim = 0;
//					int siz = t.size();
//					if (fs == 1) {
//						if (siz == 1) {
//							ap = 0;
//							ftim = 0;
//							if (proms + ap == pass && tim + ftim == ttim) {
//								ans = path;
//								op1 = { j,k,1 };
//								return;
//							}
//						}
//						else if(siz>1){
//							ap = 1;
//							ftim = stoi(substr(t, 0, siz - 2));
//							if (proms + ap == pass && tim + ftim == ttim) {
//								ans = path;
//								op1 = { j,k,1 };
//								return;
//							}
//						}
//					}
//					else {
//						if (siz>=1&&t[siz - 1] != '1') {
//							if (siz > 1) {
//								if (stoi(substr(t, 0, siz - 2)) < 300) {
//									ap = 1;
//									tr = stoi(substr(t, siz - 1, siz - 1));
//									ftim = stoi(substr(t, 0, siz - 2)) + (tr - 1) * 20;
//									if (proms + ap == pass && tim + ftim == ttim) {
//										ans = path;
//										op1 = { j,k,1 };
//										return;
//									}
//								}
//							}
//							else if(siz==1){
//								ap = 0;
//								ftim = 0;
//								if (proms + ap == pass && tim + ftim == ttim) {
//									ans = path;
//									op1 = { j,k,1 };
//									return;
//								}
//							}
//						}
//						if (siz>=2&&t[siz - 2] != '0') {
//							if (siz > 2) {
//								if (stoi(substr(t, 0, siz - 3)) < 300) {
//									ap = 1;
//									tr = stoi(substr(t, siz - 2, siz - 1));
//									ftim = stoi(substr(t, 0, siz - 3)) + (tr - 1) * 20;
//									if (proms + ap == pass && tim + ftim == ttim) {
//										ans = path;
//										op1 = { j,k,2 };
//										return;
//									}
//								}
//							}
//							else if(siz==2){
//								ap = 0;
//								ftim = 0;
//								if (proms + ap == pass && tim + ftim == ttim) {
//									ans = path;
//									op1 = { j,k,2 };
//									return;
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//		return;
//	}
//	string t = sb[i].first;
//	int ap = 0;
//	int tr = 0;
//	int ftim = 0;
//	int siz = t.size();
//	if (sb[i].second == 1) {
//		if (siz == 1) {
//			ap = 0;
//			ftim = 0;
//			path.push_back(1);
//			dfs(sb, path, i + 1, proms + ap, tim + ftim);
//			path.pop_back();
//		}
//		else if(siz>1){
//			ap = 1;
//			assert(siz - 2 >= 0);
//			ftim = stoi(substr(t, 0, siz - 2));
//			path.push_back(1);
//			dfs(sb, path, i + 1, proms + ap, tim + ftim);
//			path.pop_back();
//		}
//	}
//	else {
//		if (siz >= 1 && t[siz - 1] != '1') {
//			if (siz > 1) {
//				if (stoi(substr(t, 0, siz - 2)) < 300) {
//					ap = 1;
//					tr = stoi(substr(t, siz - 1, siz - 1));
//					ftim = stoi(substr(t, 0, siz - 2)) + (tr - 1) * 20;
//					path.push_back(1);
//					dfs(sb, path, i + 1, proms + ap, tim + ftim);
//					path.pop_back();
//				}
//			}
//			else if (siz == 1) {
//				ap = 0;
//				ftim = 0;
//				path.push_back(1);
//				dfs(sb, path, i + 1, proms + ap, tim + ftim);
//				path.pop_back();
//			}
//		}
//		if (siz>=2&&t[siz - 2] != '0') {
//			if (siz > 2) {
//				if (stoi(substr(t, 0, siz - 3)) < 300) {
//					ap = 1;
//					tr = stoi(substr(t, siz - 2, siz - 1));
//					ftim = stoi(substr(t, 0, siz - 3)) + (tr - 1) * 20;
//					path.push_back(2);
//					dfs(sb, path, i + 1, proms + ap, tim + ftim);
//					path.pop_back();
//				}
//			}
//			else if(siz==2){
//				ap = 0;
//				ftim = 0;
//				path.push_back(2);
//				dfs(sb, path, i + 1, proms + ap, tim + ftim);
//				path.pop_back();
//			}
//		}
//	}
//}
//string solve(string s) {
//	int n = s.size();
//	s = " " + s;
//	int i;
//	for (i = 1; i <= n; i++) {
//		if (!isdigit(s[i])) {
//			fi = substr(s, 1, i - 1);
//			if (s[i + 2] != 'y') {
//				fs = 0;
//			}
//			else {
//				fs = 1;
//			}
//			break;
//		}
//	}
//	while (i <= n && !isdigit(s[i]))i++;
//	vector<pair<string, int>>sb;
//	string t;
//	for (; i <= n;) {
//		if (!isdigit(s[i])) {
//			if (s[i + 2] != 'y') {
//				sb.push_back({ t,0 });
//				i = i + 5;
//			}
//			else {
//				sb.push_back({ t,1 });
//				i = i + 3;
//			}
//			t = "";
//		}
//		else {
//			t += s[i];
//			i++;
//		}
//	}
//	//cout << "xixix\n";
//	//cout << fi << " " << fs << "*\n";
//	//for (auto v : sb) {
//	//	cout << v.first << " " << v.second << "\n";
//	//}
//	//cout << "-----\n";
//	vector<int>path;
//	dfs(sb, path, 0, 0, 0);
//	//cout << "xixix*******\n";
//	if (ans.empty()) {
//		return "NOANS";
//	}
//	string fans = "";
//	fans += substr(fi, 0, op1[0]);
//	fans += " ";
//	fans += substr(fi, op1[0] + 1, op1[1]);
//	fans += " ";
//	if (op1[2] == 1) {
//		fans += substr(fi, op1[1] + 1, fi.size() - 2);
//		fans += " ";
//		fans += substr(fi, fi.size() - 1, fi.size() - 1);
//		fans += " ";
//		if (fs == 1) {
//			fans += "try ";
//		}
//		else fans += "tries ";
//	}
//	else {
//		fans += substr(fi, op1[1] + 1, fi.size() - 3);
//		fans += " ";
//		fans += substr(fi, fi.size() - 2, fi.size() - 1);
//		fans += " ";
//		if (sb[i].second == 1) {
//			fans += "try ";
//		}
//		else fans += "tries ";
//	}
//	for (int i = 0; i < ans.size(); i++) {
//		if (ans[i] == 1) {
//			fans += substr(sb[i].first, 0, sb[i].first.size() - 2);
//			fans += " ";
//			fans += substr(sb[i].first, sb[i].first.size() - 1, sb[i].first.size() - 1);
//			fans += " ";
//		}
//		else {
//			fans += substr(sb[i].first, 0, sb[i].first.size() - 3);
//			fans += " ";
//			fans += substr(sb[i].first, sb[i].first.size() - 2, sb[i].first.size() - 1);
//			fans += " ";
//		}
//		if (sb[i].second == 1) {
//			fans += "try ";
//		}
//		else fans += "tries ";
//	}
//	ans.clear();
//	op1.clear();
//	fi = "";
//	fs = -1;
//	return fans;
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<string>q;
//	string ss;
//	for (int i = 1; i <= n; i++) {	
//		cin >> ss;
//		q.push_back(ss);
//	}
//	vector<string>aans;
//	for (auto v : q) {
//		aans.push_back(solve(v));
//		if (aans.back() == "NOANS") {
//			cout << -1 << endl;
//			return 0;
//		}
//	}
//	for (auto v : aans) {
//		for (int i = 0; i < v.size(); i++) {
//			if (i==v.size()-1||i > 0 && v[i]==' '&&v[i - 1] == ' ') {
//				
//			}else cout << v[i];
//		}
//		cout << endl;
//	}
//}