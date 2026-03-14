//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	string s;
//	cin >> s;
//	if (s[0] == '-') {
//		int pos = s.size();
//		for (int i = 0; i < s.size(); i++) {
//			if (s[i] - '0' > 1) {
//				pos = i;
//				break;
//			}
//		}
//		for (int i = 0; i < pos; i++) {
//			cout << s[i];
//		}
//		cout << '1';
//		for (int i = pos; i < s.size(); i++) {
//			cout << s[i];
//		}
//		cout << '\n';
//	}
//	else {
//		int pos = s.size();
//		for (int i = 0; i < s.size(); i++) {
//			if (s[i] == '0') {
//				pos = i;
//				break;
//			}
//		}
//		for (int i = 0; i < pos; i++) {
//			cout << s[i];
//		}
//		cout << '1';
//		for (int i = pos; i < s.size(); i++) {
//			cout << s[i];
//		}
//		cout << '\n';
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//void solve() {
//	int n, H;
//	cin >> n >> H;
//	vector<pair<int,int>>h(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> h[i].first;
//		h[i].second = i;
//		h[i].first = h[i].first * (H - h[i].first);
//	}
//	sort(h.begin() + 1, h.end(), [&](auto a, auto b) {
//		if (a.first == b.first) {
//			return a.second < b.second;
//		}
//		return a.first < b.first;
//		});
//	for (int i = 1; i <= n; i++) {
//		cout << h[i].second << " ";
//	}cout << '\n';
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}

//for (int j = status; j > 0; j = (j - 1) & status) {
//	if (sum[j] <= k && f(cnt, sum, status ^ j, index + 1, dp)) {
//		ans = true;
//		break;
//	}
//}
//#include<bits/stdc++.h>
//using namespace std;
//int dic[] = { 0b1110111,0b0100100,0b1011101,0b1101101,0b0101110,0b1101011,0b1111011,0b0100101,0b1111111,0b1101111 };
//int popcount(int x) {
//	int count = 0;
//	while (x) {
//		count += x & 1; // 检查最低位是否为1
//		x >>= 1;        // 右移一位
//	}
//	return count;
//}
//int mask = 0b001111100111110011111;
//int mask1 = 0b00111110011111;
//int mask2 = 0b0011111;
//int mask3 = 0b010101110101011101010111;
//int mask4 = 0b0101011101010111;
//int mask5 = 0b01010111;
//int ma;
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<string>x(n + 1);
//	vector<long long>a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> x[i];
//		for (int j = 0; j < m; j++) {
//			a[i] |= dic[x[i][j] - '0'] << (7 * j);
//		}
//	}
//	unordered_set<int>hash1;
//	unordered_set<int>hash;
//	for (int i = 1; i <= n; i++) {
//		hash1.insert(a[i]);
//	}
//	
//	//for (int i = 1; i <= n; i++) {
//	//	cout << bitset<32>(a[i]) << endl;
//	//}
//	if (m == 1) {
//		ma = mask2;
//	}
//	else if (m == 2) {
//		ma = mask1;
//	}
//	else {
//		ma = mask;
//	}
//	int ans = INT_MAX;
//	//for (int x = 0; x <= (1 << 7) - 1; x++) {
//	//	if (popcount(x) > 5)continue;
//	//	for (int y = 0; y <= (1 << 7) - 1; y++) {
//	//		if (popcount(y) > 5)continue;
//	//		for (int z = 0; z <= (1 << 7) - 1; z++) {
//	//			if (popcount(z) > 5)continue;
//	//			int s = z | (y << 7) | (x << 14);
//	//			unordered_set<int>hash;//当前位数字和上位掩码后共有多少种
//	//			for (int i = 1; i <= n; i++) {
//
//	//				hash.insert(a[i] & s);
//	//				//cout << bitset<32>(cur) << endl;
//	//				//cout << bitset<32>(dic[cur] & s) << endl;
//	//			}
//	//			if (hash.size() >= hash1.size()) {
//	//				//cout << "haha\n";
//	//				ans = min(ans, popcount(s));
//	//				//cout << ans << endl;
//	//			}
//	//		}
//	//	}
//	//}
//	for (int s = ma; s > 0; s = (s - 1)&ma) {
//		hash.clear();//当前位数字和上位掩码后共有多少种
//		for (int i=1; i<=n;i++) {
//			
//			hash.insert(a[i] & s);
//			//cout << bitset<32>(cur) << endl;
//			//cout << bitset<32>(dic[cur] & s) << endl;
//		}
//		if (hash.size() >= hash1.size()) { 
//			//cout << "haha\n";
//			ans = min(ans, popcount(s));
//			//cout << ans << endl;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		hash.clear();
//		hash.insert(a[i] & 0);
//	}
//	if (hash.size() >= hash1.size())ans = min(ans, popcount(0));
//
//
//	if (m == 1) {
//		ma = mask5;
//	}
//	else if (m == 2) {
//		ma = mask4;
//	}
//	else {
//		ma = mask3;
//	}
//	for (int s = ma; s > 0; s = (s - 1) & ma) {
//		hash.clear();
//		for (int i = 1; i <= n; i++) {
//			hash.insert(a[i] & s);
//			//cout << bitset<32>(cur) << endl;
//			//cout << bitset<32>(dic[cur] & s) << endl;
//		}
//		if (hash.size() >= hash1.size()) {
//			//cout << "haha\n";
//			ans = min(ans, popcount(s));
//			//cout << ans << endl;
//		}
//	}
//
//	cout << ans << '\n';
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//bitset<1000000>a;
//bitset<1000000>b;
//void mul(string a, string b) {
//	a.assign(a);
//	b.assign(b);
//}
//bool sub(string a, string b) {
//	bool sign = 1;
//	if(b.size()>a.size())
//}
//void solve() {
//	string a, b;
//	cin >> a >> b;
//	reverse(a.begin(), a.end());
//	reverse(b.begin(), b.end());
//	string a1,a11,a2,a22,b1,b11,b2,b22;
//	for (int i = 0; i < a.size(); i+=4) {
//		a1 += a[i];
//	}
//	for (int i = 1; i < a.size(); i+=4) {
//		a2 += a[i];
//	}
//	for (int i = 2; i < a.size(); i+=4) {
//		a11 += a[i];
//	}
//	for (int i = 3; i < a.size(); i+=4) {
//		a22 += a[i];
//	}
//	a11 = '0' + a11;
//	a22 = '0' + a22;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//int jo[]
//void solve() {
//	int n, A, B, C;
//	cin >> n >> A >> B >> C;
//	int U = (1 << 30) - 1;
//	int fm3 = A & U;
//	int fm2 = B & U;
//	int fm1 = C & U;
//	int l, r, d;
//	for (int i = 0; i < n; i++) {
//		int g0 = fm3 ^ ((fm3 << 16) & U);
//		int h0 = g0 ^ (g0 >> 5);
//		int f0 = h0 ^ ((h0 << 1) & U) ^ fm2 ^ fm1;
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//void solve() {
//	int n, A, B, C;
//	int U = (1 << 30) - 1;
//	cin >> n >> A >> B >> C;
//	bool joN = 0;//当前序列中逆序对数量的奇偶性
//	array<int, 3>f = {C&U,B&U,A&U};
//	for (int i = 0, g, h, fc; i <= n - 1; i++) {
//		g = f[2] ^ ((f[2] << 16) & U);
//		h = g ^ (g >> 5);
//		fc = h ^ ((h << 1) & U) ^ f[1] ^ f[0];
//		if (fc % (n - i)!=0)joN ^= 1;
//		f[2] = f[1];
//		f[1] = f[0];
//		f[0] = fc;
//		//cout <<fc<<endl;
//	}
//	string ans = "";
//	if (joN)ans += '1';
//	else ans += '0';
//	int l, r,d;
//	for (int i = 1, g, h, fc; i <= n - 1; i++) {
//		for (int j = 1; j <= 3;j++) {
//			g = f[2] ^ ((f[2] << 16) & U);
//			h = g ^ (g >> 5);
//			fc = h ^ ((h << 1) & U) ^ f[1] ^ f[0];
//			f[2] = f[1];
//			f[1] = f[0];
//			f[0] = fc;
//		}
//		//for (int j = 0; j < 3; j++) {
//		//	cout << f[j] << " ";
//		//}cout << '\n';
//		l = min(f[2]%n, f[1]%n), r = max(f[2]%n, f[1]%n),d=f[0]%n+1;
//		if (((r - l + 1) & 1) == 0 && d & 1) {
//			joN ^= 1;
//		}
//		if (joN)ans += '1';
//		else ans += '0';
//	}
//	cout << ans << endl;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}


//#include<bits/stdc++.h>
//using namespace std;
//int dic[] = { 0b1110111,0b0100100,0b1011101,0b1101101,0b0101110,0b1101011,0b1111011,0b0100101,0b1111111,0b1101111 };
//int popcount(int x) {
//	int count = 0;
//	while (x) {
//		count += x & 1; // 检查最低位是否为1
//		x >>= 1;        // 右移一位
//	}
//	return count;
//}
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<string>x(n + 1);
//	vector<long long>a(n + 1);
//	unordered_set<int>hash1;
//	for (int i = 1; i <= n; i++) {
//		cin >> x[i];
//		for (int j = 0; j < m; j++) {
//			a[i] |= dic[x[i][j] - '0'] << (7 * j);
//		}
//		hash1.insert(a[i]);
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	cout << bitset<32>(a[i]) << '\n';
//	//}
//	int siz = hash1.size();
//	int ans = INT_MAX;
//	int up = (1 << (7 * m)) - 1;
//	for (int i = 0; i <= up; i++) {
//		int p = popcount(i);
//		if (p > 5 || p >= ans) {
//			continue;
//		}
//		unordered_set<int>hash;
//		for (int j = 1; j <= n; j++) {
//			hash.insert(a[j] & i);
//		}
//		if (hash.size() >= siz) {
//			ans = p;
//		}
//	}
//	cout << ans << endl;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}
//
//
//
//#include<bits/stdc++.h>
//using namespace std;
//
//// 7段LED的二进制表示（每个数字对应7位）
//int dic[] = { 0b1110111,0b0100100,0b1011101,0b1101101,0b0101110,
//              0b1101011,0b1111011,0b0100101,0b1111111,0b1101111 };
//
//// 计算二进制中1的个数
//int popcount(int x) {
//    int cnt = 0;
//    while (x) {
//        cnt += x & 1;
//        x >>= 1;
//    }
//    return cnt;
//}
//
//// 生成所有有k个1的21位数字（m最大3时7*3=21位）
//vector<int> generate_with_k_ones(int k, int bits) {
//    vector<int> res;
//    string mask(bits, '0');
//    fill(mask.end() - k, mask.end(), '1');
//    do {
//        int val = 0;
//        for (char c : mask) {
//            val = (val << 1) | (c == '1');
//        }
//        res.push_back(val);
//    } while (next_permutation(mask.begin(), mask.end()));
//    return res;
//}
//
//void solve() {
//    int n, m;
//    cin >> n >> m;
//    vector<string> x(n);
//    for (int i = 0; i < n; i++) {
//        cin >> x[i];
//    }
//
//    // 提取所有不同的原始LED状态
//    unordered_set<int> original_states;
//    for (string s : x) {
//        int state = 0;
//        for (int j = 0; j < m; j++) {
//            // 拼接每个数字的7段状态（j=0是最右位数字，左移0位；j=1左移7位，以此类推）
//            state |= dic[s[j] - '0'] << (7 * j);
//        }
//        original_states.insert(state);
//    }
//    int unique_cnt = original_states.size();
//
//    // 特殊情况：所有楼层状态相同，无需任何灯管
//    if (unique_cnt == 1) {
//        cout << 0 << endl;
//        return;
//    }
//
//    // 按1的个数从小到大枚举（保证找到的是最小值）
//    int total_bits = 7 * m;
//    for (int k = 1; k <= 5 * m; k++) {  // k是保留的灯管数量
//        // 生成所有有k个1的掩码
//        vector<int> masks = generate_with_k_ones(k, total_bits);
//        for (int mask : masks) {
//            // 检查当前掩码能否区分所有原始状态
//            unordered_set<int> transformed;
//            bool valid = true;
//            for (int s : original_states) {
//                int t = s & mask;  // 保留mask中1对应的灯管
//                if (transformed.count(t)) {
//                    // 两个不同的原始状态被映射到相同结果，无效
//                    valid = false;
//                    break;
//                }
//                transformed.insert(t);
//            }
//            if (valid) {
//                // 找到最小的k，直接返回
//                cout << k << endl;
//                return;
//            }
//        }
//    }
//
//    // 理论上不会走到这里（至少需要total_bits个灯管一定能区分）
//    cout << total_bits << endl;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    int t;
//    cin >> t;
//    while (t--) {
//        solve();
//    }
//    return 0;
//}


//#include<bits/stdc++.h>
//#include <nmmintrin.h>
//using namespace std;
//int msk[] = { 0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011 };
//vector<vector<int>>arr(16);
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; ++i) {
//		string s;
//		cin >> s;
//		for (int j = 0; j < m; ++j) {
//			a[i] |= msk[s[j] - '0'] << (7 * j);
//		}
//	}
//	for (int i = 0; i <= 5 * m; i++) {
//		for (auto j : arr[i]) {
//			bool ok = 1;
//			for (int k = 1; k <= n; k++) {
//				for (int p = 1; p < k; p++) {
//					if ((j & a[k]) == (a[p] & j)) {
//						ok = 0;
//						goto flag;
//					}
//				}
//
//			}
//			if (ok) {
//				cout << i << '\n';
//				return;
//			}
//		flag:;
//		}
//	}
//}
//void prepare() {
//	for (int i = 0; i <= (1 << 21) - 1; i++) {
//		if (__builtin_popcount(i) <= 15) {
//			arr[__builtin_popcount(i)].emplace_back(i);
//		}
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	prepare();
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}