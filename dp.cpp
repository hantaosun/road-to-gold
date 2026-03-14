//E.Sponsor of Your Problems
//#include<bits/stdc++.h>
//using namespace std;
//int ans = 0;
//string l, r;
//void solve() {
//	cin >> l >> r;
//	int ans = 0;
//	bool free = 0;
//	int a = 0, b = 0;
//	for (int i = 0; i < l.size(); i++) {
//		a = a * 10 + l[i] - '0';
//		b = b * 10 + r[i] - '0';
//		if (b-a>= 2)free = 1;
//		if (!free) {
//			if (l[i] == r[i])ans += 2;
//			else ans += 1;
//		}
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


//D1.Red Light, Green Light(Easy version)
//#include <bits/stdc++.h>
//using namespace std;
//const long long MAX_POS = 1000000000000000LL; // 10^15
//void solve() {
//    int n, k;
//    cin >> n >> k;
//    vector<long long> positions(n);
//    for (int i = 0; i < n; i++) {
//        cin >> positions[i];
//    }
//    vector<int> delays(n);
//    for (int i = 0; i < n; i++) {
//        cin >> delays[i];
//    }
//    // Build sorted light positions and delay map
//    vector<long long> light_positions_sorted = positions;
//    sort(light_positions_sorted.begin(), light_positions_sorted.end());
//    map<long long, int> delay_map;
//    for (int i = 0; i < n; i++) {
//        delay_map[positions[i]] = delays[i];
//    }
//    int q;
//    cin >> q;
//    vector<long long> queries(q);
//    for (int i = 0; i < q; i++) {
//        cin >> queries[i];
//    }
//    for (long long start : queries) {
//        long long pos = start;
//        int dir = 1; // 1 for right, 0 for left.
//        int t_mod = 0;
//        set<tuple<long long, int, int>> visited;
//        bool resolved = false;
//
//        while (!resolved) {
//            // Check if outside the strip
//            if (pos < 1 || pos > MAX_POS) {
//                cout << "YES\n";
//                resolved = true;
//                break;
//            }
//
//            tuple<long long, int, int> state = make_tuple(pos, dir, t_mod);
//            if (visited.find(state) != visited.end()) {
//                cout << "NO\n";
//                resolved = true;
//                break;
//            }
//            visited.insert(state);
//
//            // Check if at a traffic light and turn if red
//            if (delay_map.count(pos)) {
//                if (t_mod == delay_map[pos]) {
//                    dir = 1 - dir;
//                }
//            }
//            // Calculate next event
//            long long d;
//            if (dir == 1) { // Moving right
//                long long d_boundary = MAX_POS - pos + 1; // Steps to exit right
//                long long next_light = -1;
//                auto it = upper_bound(light_positions_sorted.begin(), light_positions_sorted.end(), pos);
//                if (it != light_positions_sorted.end()) {
//                    next_light = *it;
//                }
//                long long d_light = (next_light == -1) ? (d_boundary + 1) : (next_light - pos);
//                d = min(d_boundary, d_light);
//
//                if (d == d_boundary) {
//                    cout << "YES\n";
//                    resolved = true;
//                    break;
//                }
//                else {
//                    pos = next_light;
//                    t_mod = (t_mod + d) % k;
//                }
//            }
//            else { // Moving left
//                long long d_boundary = pos; // Steps to exit left (to 0)
//                long long next_light = -1;
//                auto it = lower_bound(light_positions_sorted.begin(), light_positions_sorted.end(), pos);
//                if (it != light_positions_sorted.begin()) {
//                    --it;
//                    next_light = *it;
//                }
//                long long d_light = (next_light == -1) ? (d_boundary + 1) : (pos - next_light);
//                d = min(d_boundary, d_light);
//
//                if (d == d_boundary) {
//                    cout << "YES\n";
//                    resolved = true;
//                    break;
//                }
//                else {
//                    pos = next_light;
//                    t_mod = (t_mod + d) % k;
//                }
//            }
//        }
//    }
//}
//int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        solve();
//    }
//}


//��3������������
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 1e9 + 7;
//signed main() {
//	string num;
//	cin >> num;
//	int dp[55][3];//iλ�ü�֮ǰ���ַ�����������%3Ϊ0��1��2�ĸ���
//	num = " " + num;
//	int ans = 0;
//	dp[0][0] = 1;
//	dp[0][1] = 0;
//	dp[0][2] = 0;
//	for (int i = 1, cur; i < num.size(); i++) {
//		cur = (num[i] - '0') % 3;
//		if (cur == 0) {
//			dp[i][0] = dp[i - 1][0] * 2%mod;
//			dp[i][1] = dp[i - 1][1] * 2%mod;
//			dp[i][2] = dp[i - 1][2] * 2%mod;
//		}
//		else if (cur == 1) {
//			dp[i][0] = (dp[i - 1][0] + dp[i - 1][2])%mod;
//			dp[i][1] = (dp[i - 1][1] + dp[i - 1][0])%mod;
//			dp[i][2] = (dp[i - 1][2] + dp[i - 1][1])%mod;
//		}
//		else if (cur == 2) {
//			dp[i][0] = (dp[i - 1][0] + dp[i - 1][1])%mod;
//			dp[i][1] = (dp[i - 1][1] + dp[i - 1][2])%mod;
//			dp[i][2] = (dp[i - 1][2] + dp[i - 1][0])%mod;
//		}
//	}
//	cout << dp[num.size() - 1][0]-1 << endl;
//}


//ɾ����
//#include<bits/stdc++.h>
//using namespace std;
//string s, t;
//int help[105];//��ǰλ������������ţ�����Ե��������±�
//int dp[105][105];
//bool f(int i, int j) {//s��0-i���ܷ�ͨ��ɾ�������0-j�ϵ�t
//	if (i < j || (i < 0 && j >= 0)) {
//		return false;
//	}
//	if (j<0)return true;
//	bool ans = 0;
//	if (dp[i][j] != -1)return dp[i][j];
//	if (s[i] == t[j]) {
//		ans |= f(i - 1, j - 1);
//		if (s[i] == ')') {
//			ans |= f(help[i] - 1, j);
//		}
//	}
//	else if (s[i] == '(' && t[j] == ')')return false;
//	else if (s[i] == ')' && t[j] == '(') {
//		ans |= f(help[i] - 1, j);
//	}
//	dp[i][j] = ans;
//	return ans;
//}
//
//int main() {
//	cin >> s >> t;
//	stack<int>sta;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] == '(') {
//			sta.push(i);
//		}
//		else {
//			help[i] = sta.top();
//			sta.pop();
//		}
//	}
//	memset(dp, -1, sizeof(dp));
//	cout << (f(s.size() - 1, t.size() - 1) ? "Possible" : "Impossible") << '\n';
//}


//��������
//#include<bits/stdc++.h>
//using namespace std;
//constexpr int mod = 1e9 + 7;
//int n;
//int dp[42][1605][3][42];
//vector<int>a;
//int f(int cur, int sum, int k, int pre) {//40*40*40*2*40
//	if (dp[cur][sum][k][pre] != -1)return dp[cur][sum][k][pre];
//	if (cur > n)return 1;
//	int ans = 0;
//	if (a[cur] != -1) {
//		if (k == 1 && a[cur] < pre || a[cur] * (cur - 1) > sum)return 0;
//		else {
//			ans+=f(cur + 1, sum + a[cur], a[cur] < pre, a[cur]);
//		}
//	}
//	else {
//		if (k == 1) {
//			for (int i = pre; i * (cur - 1) <= sum && i <= 40; i++) {
//				ans = (ans + f(cur + 1, sum + i, 0, i)) % mod;
//			}
//		}
//		else {
//			for (int i = 0; i * (cur - 1) <= sum; i++) {
//				ans = (ans + f(cur + 1, sum + i, !(i <= pre), i)) % mod;
//			}
//		}
//	}
//	dp[cur][sum][k][pre] = ans;
//	return ans;
//}
//int main() {
//	cin >> n;
//	memset(dp, -1, sizeof(dp));
//	a.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	//�����ݼ���k������Ч��������,�������ܵõ���������������
//	if (a[1] != -1) {
//		cout << f(2, a[1], 0, a[1]) << endl;
//	}
//	else {
//		int ans = 0;
//		for (int i = 0; i <= 40; i++) {
//			ans = (ans + f(2,i,0,i)) % mod;
//		}
//		cout << ans << endl;
//	}
//}


//****
// �ڽ����������ʱ��������Ҫȷ����Ŀ�Ĵ���˳�򡣶���������ĿA��B���������Ǿ�����ʱ��tʱ�����������⣬��ô������˳����A��B��������B��A��
//˳��1����A��B����
//�÷�A = score[A] - minu[A] * (t + tim[A])
//�÷�B = score[B] - minu[B] * (t + tim[A] + tim[B])
//˳��2����B��A����
//�÷�B = score[B] - minu[B] * (t + tim[B])
//�÷�A = score[A] - minu[A] * (t + tim[B] + tim[A])
//˳��1���ܷ֣�score[A] + score[B] - minu[A] * (t + tim[A]) - minu[B] * (t + tim[A] + tim[B])
//˳��2���ܷ֣�score[A] + score[B] - minu[B] * (t + tim[B]) - minu[A] * (t + tim[B] + tim[A])
//�Ƚ�˳��1��˳��2���ܷ֣����Ǹ�ϣ��ѡ���ֽܷϴ������˳����ˣ�������Ҫ�Ƚϣ�
//minu[A] * tim[A] + minu[B] * (tim[A] + tim[B])  ��   minu[B] * tim[B] + minu[A] * (tim[A] + tim[B])
//ʵ���ϣ����ǱȽϵ�������˳�����ʧ�����ٵķ�������
//˳��1����ʧ��minu[A] * (t + tim[A]) + minu[B] * (t + tim[A] + tim[B]) = (minu[A] + minu[B]) * t + minu[A] * tim[A] + minu[B] * (tim[A] + tim[B])
//˳��2����ʧ��minu[B] * (t + tim[B]) + minu[A] * (t + tim[B] + tim[A]) = (minu[A] + minu[B]) * t + minu[B] * tim[B] + minu[A] * (tim[A] + tim[B])
//��ˣ��Ƚ���ʧ���ǱȽϣ�
//˳��1�Ķ�����ʧ��minu[A] * tim[A] + minu[B] * (tim[A] + tim[B])
//˳��2�Ķ�����ʧ��minu[B] * tim[B] + minu[A] * (tim[A] + tim[B])
//���
//˳��1�Ķ�����ʧ - ˳��2�Ķ�����ʧ = minu[A] * tim[A] + minu[B] * tim[A] + minu[B] * tim[B] - minu[B] * tim[B] - minu[A] * tim[A] - minu[A] * tim[B]
//= minu[B] * tim[A] - minu[A] * tim[B]
//���ԣ��� minu[B] * tim[A] < minu[A] * tim[B] ʱ��˳��1����ʧ��С��Ҳ������A��B���á�
//	������ minu[A] / tim[A] > minu[B] / tim[B] ʱ������A���á�
//	��ˣ����ǰ��� minu[i] / tim[i] �ı�ֵ�Ӵ�С����������������������Ŀʱ��������ֵ�����Ŀ�ܹ�ʹ��ʧ��С��
//	ע�⣺������۶��ڶ����ĿҲ�ǳ����ģ���Ϊ���ڵ�������Ŀ������������˳�����ǿ��Խ���������������ʧ����ð�������˼�룩������������а������˳�����������ŵġ�
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n, T;
//vector<int>score;
//vector<int>minu;
//vector<int>tim;
//vector<int>idx;
//int dp[55][100005];
//int f(int i, int t) {//��ǰ������i����,ʱ��ΪT������ʣ��ʱ������ȡ�õ�������
//	if (dp[i][t] != -1)return dp[i][t];
//	if (i > n || t >= T)return 0;
//	int ans = f(i + 1, t);
//	int cur = idx[i];
//	if (T - t >= tim[cur] && score[cur] - minu[cur] * (t + tim[cur]) > 0) {
//		ans = max(ans, f(i + 1, t + tim[cur])
//			+ score[cur] - minu[cur] * (t + tim[cur]));
//	}
//	dp[i][t] = ans;
//	return ans;
//}
//signed main() {
//	cin >> n >> T;
//	score.resize(n + 1);
//	minu.resize(n + 1);
//	tim.resize(n + 1);
//	memset(dp, -1, sizeof(dp));
//	for (int i = 1; i <= n; i++) {
//		cin >> score[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> minu[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> tim[i];
//	}
//	idx.resize(n + 1);
//	iota(idx.begin(), idx.end(), 0);
//	sort(idx.begin() + 1, idx.end(), [&](int a, int b) {
//		return double(minu[a]) / tim[a] > double(minu[b]) / tim[b];
//		});//��minu������ѡ���õ�����Ȼ���������
//	cout << f(1, 0) << endl;
//}



//�����****
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//constexpr int mod = 1e9 + 9;
//vector<int>a;
//int dp[3000][70];
//int n;
//int f(int s, int pos) {//��ǰ�������ڸ�λ�Ƿ�����,���ǵ��ڼ�λ��
//	if (pos < 0)return 1;//�Ը���Ϊbasecaseʱ��ط���ǰ���Է�ֹ����Խ��
//	if (dp[s][pos] != -1)return dp[s][pos];
//	int ans = 0;
//	//��λ������1
//	int ts = s;
//	for (int i = 1; i <= n; i++) {
//		if ((ts & (1ll << i)) == 0 && (a[i] & (1ll << pos))) {
//			ts ^= 1ll << i;
//		}
//	}
//	//����һ��1
//	ans = (ans + f(ts, pos - 1)) % mod;
//	for (int i = 1; i <= n; i++) {
//		if ((s & (1ll << i)) == 0 && (a[i] & (1ll << pos))) {
//			ans = (ans + f(ts & (~(1 << i)), pos - 1)) % mod;
//		}
//		else if (s & (1ll << i)) {
//			ans = (ans + f(ts, pos - 1)) % mod;
//		}
//	}
//	dp[s][pos] = ans;
//	return ans;
//}
//signed main() {
//
//	cin >> n;
//	memset(dp, -1, sizeof(dp));
//	a.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	cout << f(0, 63) << '\n';
//}


//#include<bits/stdc++.h>
//#define int long long
//const int inf = 1e15 + 10;
//using namespace std;
//vector<int>add(26, inf);
//vector<int>del(26, inf);
//vector<int>anc(26, inf);
//vector<int>cna(26, inf);
//vector<vector<int>>cts(26, vector<int>(26, inf));
//vector<vector<int>>cha(26, vector<int>(26, inf));
//string s;
//int dp[55][55];
//int f(int l, int r) {//��l-r�ϵ��ַ�����Ϊ���ĵ���С����
//	if (l >= r)return 0;
//	if (dp[l][r] != -1)return dp[l][r];
//	int ans = inf;
//	if (s[l] == s[r])ans = f(l + 1, r - 1);//��֪��Ϊʲôֱ��l+1 r-1�������ŵ�
//	int cl = s[l] - 'a';
//	int cr = s[r] - 'a';
//
//	//if (add[cl] != inf) {
//	//	ans = min(ans, add[cl] + f(l + 1, r));
//	//}
//	if (del[cl] != inf) {
//		ans = min(ans, del[cl] + f(l + 1, r));
//	}
//	if (anc[cl] != inf) {
//		ans = min(ans, anc[cl] + f(l + 1, r));
//	}
//	//if (cna[cl] != inf) {
//	//	ans = min(ans, cna[cl] + f(l + 1, r));
//	//}
//	if (cha[cl][cr] != inf) {
//		ans = min(ans, cha[cl][cr] + f(l + 1, r - 1));
//	}
//	//if (add[cr] != inf) {
//	//	ans = min(ans, add[cr] + f(l, r - 1));
//	//}
//	if (del[cr] != inf) {
//		ans = min(ans, del[cr] + f(l, r - 1));
//	}
//	if (anc[cr] != inf) {
//		ans = min(ans, anc[cr] + f(l, r - 1));
//	}
//	//if (cna[cr] != inf) {
//	//	ans = min(ans, cna[cl] + f(l, r - 1));
//	//}
//	if (cha[cr][cl] != inf) {
//		ans = min(ans, cha[cr][cl] + f(l + 1, r - 1));
//	}
//	if (cts[cr][cl] != inf) {
//		ans = min(ans, cts[cr][cl] + f(l + 1, r - 1));
//	}
//	dp[l][r] = ans;
//	return ans;
//}
//signed main() {
//	memset(dp, -1, sizeof(dp));
//	cin >> s;
//	int m;
//	cin >> m;
//	string tmp;
//	char a, b;
//	int t;
//	for (int i = 1; i <= m; i++) {
//		cin >> tmp;
//		if (tmp == "add") {
//			cin >> a >> t;
//			add[a - 'a'] = min(add[a - 'a'], t);
//		}
//		else if (tmp == "erase") {
//			cin >> a >> t;
//			del[a - 'a'] = min(del[a - 'a'], t);
//		}
//		else {
//			cin >> a >> b >> t;
//			cha[a - 'a'][b - 'a'] = min(cha[a - 'a'][b - 'a'], t);
//		}
//	}
//	for (int i = 0; i < 26; i++) {
//		cha[i][i] = 0; // ��ʼ�������޸Ĵ���Ϊ0
//	}
//	for (int brg = 0; brg < 26; brg++) {
//		for (int i = 0; i < 26; i++) {
//			for (int j = 0; j < 26; j++) {
//				if (cha[i][brg] != inf && cha[brg][j] != inf) {
//					cha[i][j] = min(cha[i][j], cha[i][brg] + cha[brg][j]);
//				}
//			}
//		}
//	}
//	for (int brg = 0; brg < 26; brg++) {
//		for (int i = 0; i < 26; i++) {
//			for (int j = 0; j < 26; j++) {
//				if (cha[i][brg] != inf && cha[j][brg] != inf) {
//					cts[i][j] = min(cts[i][j], cha[i][brg] + cha[j][brg]);
//					cts[j][i] = min(cts[i][j], cha[i][brg] + cha[j][brg]);
//				}
//			}
//		}
//	}
//	for (int i = 0; i < 26; i++) {
//		for (int j = 0; j < 26; j++) {
//			if (cha[i][j] != inf && del[j] != inf) {
//				del[i] = min(del[i], cha[i][j] + del[j]);
//			}
//		}
//	}
//
//	// 	for (int i = 0; i < 26; i++) {
//	// 		for (int j = 0; j < 26; j++) {
//	// 			if (cha[j][i] != inf && add[j] != inf) {
//	// 				add[i] = min(add[i], cha[j][i] + add[j]);//ע���±�˳��
//	// 			}
//	// 		}
//	// 	}
//	for (int i = 0; i < 26; i++) {
//		for (int j = 0; j < 26; j++) {
//			if (cha[i][j] != inf) {
//				for (int k = 0; k < 26; k++) {
//					if (add[k] != inf && cha[k][j] != inf) {
//						anc[i] = min(anc[i], cha[i][j] + add[k] + cha[k][j]);
//					}
//				}
//			}
//		}
//	}
//	/*for (int i = 0; i < 26; i++) {
//		for (int j = 0; j < 26; j++) {
//			cout << "[" << char(i + 'a') << "," << char(j + 'a') << ']' << ":" << (cha[i][j]==inf?-1:cha[i][j]) << " ";
//		}
//		cout << '\n';
//	}*/
//	//cout << anc[23] << endl;
//	int ans = f(0, s.size() - 1);
//	cout << (ans == inf ? -1 : ans) << '\n';
//}



//�ǵò�����dp
//������Ϸ
//#include<bits/stdc++.h>
//using namespace std;
//double dp[2500][2500];//i���δ���,δ��j�������Ϸ����������
//int main() {
//	int n, m;
//	cin >> n >> m;
//	dp[0][0] = 0;
//	for (int j= 0; j <= n * m; j++) {
//		for (int i = 0; i <= n*m; i++) {
//			if (i + j > n * m || (j - i) % 2 || i > j)continue;//�������i>j��Ϊ��Ѳ���ȷ����
//			//������������֪�����,��Ѳ��Ծ���ֱ�ӷ���֮ǰ�����
//			double p = double(i) / j;
//			if (i > 0 && j > 0) {
//				dp[i][j] += (dp[i - 1][j - 1] + 1) * p;
//			}
//			if (j > 1) {
//				double a = 1.0 / (j - 1);//���η���һ��
//				double b = double(j - 2 - i) / (j - 1);//��һ�Σ��ڶ��ζ������ҵڶ���δ֪
//				double c = 1 - a - b;//�ڶ�����֪
//			
//				dp[i][j] += (1 - p) * a * (dp[i][j - 2] + 1);
//				dp[i][j] += (1 - p) * b * (dp[i + 2][j - 2] + 1);
//				dp[i][j] += (1 - p) * c * (dp[i][j - 2] + 2);//������һ��
//			}
//		}
//	}
//	cout << fixed << setprecision(9) << dp[0][n * m] << endl;
//}


//��������
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 11;
//const int mod = 1e9 + 7;
//int odd[N][N];//��ǰ�������������ж��������,(���ǽ�һ�����Ӷ�������ͬ��ϵ��Ϊ'.'�ĸ��ӵ�����ۼ�)
//int even[N][N];
//bool modd[N][N];//��ǰ���ӱ�����������
//bool meven[N][N];
//int dp[N][1 << N];
//signed main() {
//	int h, w, n, m;
//	cin >> h >> w >> n >> m;
//	string s;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			odd[i][j] = even[i][j] = 1;
//		}
//	}
//	for (int i = 0; i < h; i++) {
//		cin >> s;
//		int ni = i % n;
//		for (int j = 0; j < w; j++) {
//			int nj = j % m;
//			if (s[j] == '.') {
//				odd[ni][nj] = odd[ni][nj] * 5 % mod;//������'.'�Ŀ������۳˵�һ��������
//				even[ni][nj] = even[ni][nj] * 4 % mod;
//			}
//			else {
//				if ((s[j] - '0') & 1) {
//					modd[ni][nj] = true;
//				}
//				else {
//					meven[ni][nj] = true;
//				}
//			}
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (modd[i][j] && meven[i][j]) {//���һ������������Լ�����޽�
//				cout << 0 << '\n';
//				return 0;
//			}
//		}
//	}
//	dp[0][0] = 1;//dp[i][j]��ʾ��ǰi������ż��Ϊj,���ܵ������
//	for (int i =1; i <= n; i++) {//��һ��ʼʵ������ƫ����һλ,����дbasecase��һ�ж�û��ȫ��ż��
//		for (int j = 0; j < (1 << m); j++) {//ö����һ�����п��ܵ���ż״̬
//			int sum = 1;
//			bool ok=1;
//			int jo=0;
//			for (int k = 0; k < m; k++) {//������ż״̬�Ƿ���ܳ���
//				if (j & (1 << k)) {
//					jo ^= 1;
//					sum = sum * odd[i-1][k] % mod;//�ڼ��Ĺ�����˳��ͳ���������ż״̬����,�������������ż״̬�ж����ַ���
//					if (meven[i-1][k]) { ok = 0; break; }
//				}
//				else{
//					sum = sum * even[i-1][k] % mod;
//					if (modd[i-1][k]) { ok = 0; break; }
//				}
//			}
//			if (ok && jo) {//������ܳ��֣����µ�����Ϊֹ��ͬ��ż�������Ӧ�������
//				for (int k = 0; k < (1 << m); k++) {
//					dp[i][k ^ j] = (dp[i][k ^ j] + dp[i - 1][k]*sum) % mod;
//				}
//			}//�����������ϵ��˼���Ͳ�̫����ת�Ʒ���,��Ϊ�е������̫�ò�����
//		}
//	}
//	cout << dp[n][(1 << m) - 1] << '\n';
//}


//#include<bits/stdc++.h>
//#define ll long long
//#define int long long
//using namespace std;
//vector<int>a;
//const int mod = 1e9 + 7;
//int dp[55][55][55][55];
//int fact[55];
//int qpow(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if(b&1)ans = ans * a % mod;
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ans;
//}
//int C(int n, int m) {
//	return fact[n] * qpow(fact[n - m], mod - 2)%mod * qpow(fact[m], mod - 2)%mod;
//}
//int f(int l, int r, int st, int en) {
//	if (dp[l][r][st][en] != -1)return dp[l][r][st][en];
//	int ans = 0;
//	if (l == r) {
//		return st == a[l];
//	}
//	int x1, x2, y1, y2;
//	for (int i = l; i < r; i++) {
//		if (l == r - 1) {
//			x1 =x2= en;
//			y1 = y2 = st;
//		}
//		else if (i == l) {
//			x1 = i + 1, x2 = i + 1;
//			y1 = st; y2 = en;
//		}
//		else if (i +1== r ) {
//			x1 = st; x2 = en;
//			y1 = y2 = i;
//		}
//		else {
//			x1 = st, x2 = i + 1;
//			y1 = i; y2 = en;
//		}
//		ans = (ans + f(l, i, x1, x2) * f(i + 1, r, y1, y2) % mod * C(r - l - 1, i - l)) % mod;
//	}
//	dp[l][r][st][en] = ans;
//	return ans;
//}
//
//signed main() {
//	memset(dp, -1, sizeof(dp));
//	int n;
//	cin >> n;
//	fact[0] = 1;
//	for (int i = 1; i <= 54; i++) {
//		fact[i] = fact[i - 1] * i%mod;
//	}
//	a.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		a[i]++;
//	}
//	cout << f(1, n,1,n) << '\n';
//}


//#include<bits/stdc++.h>
//using namespace std;
//int n, k;
//bool notPrime[500005];
//void egpty() {
//	notPrime[0] = true;
//	notPrime[1] = true;
//	for (int i = 2; i <= 500000; i++) {
//		if (notPrime[i])continue;
//		for (int j = i + i; j <= 500000; j += i) {
//			notPrime[j] = true;
//		}
//	}
//}
//struct info {
//	bool win;
//	int zhi;
//	info(bool w, int a) {
//		win = w;
//		zhi = a;
//	}
//	info() {
//
//	}
//};
//info dp[500000][2];
//bool vis[500000][2];
//info f(int rest, bool who) {//ʣ�༸��ʯͷ,������˭�Ļغ�(1ΪFFF(��) 0ΪGGG(��)) �����Ļ��������Ļغϣ����Ӯ�Ļ�����Ӯ����С�Ļغ�
//	if (vis[rest][who])return dp[rest][who];
//	vis[rest][who] = 1;
//	//cout << rest << " " << who << endl;
//	bool win = 0;
//	int wmin = INT_MAX, lmax = -1;
//	bool flag = 0;//��¼��û�е�ѡ
//	for (int i = 1; i <= min(rest, k); i++) {
//		if ((!who && notPrime[rest - i] && rest - i > 1) || (who && !notPrime[rest - i] && rest - i > 1)) {
//			flag = 1;
//			info tmp = f(rest - i, !who);
//			if (tmp.win) {
//				lmax = max(tmp.zhi, lmax);//�����Է�Ӯ�������Ļغ���
//			}
//			else {
//				//cout << "haha\n";
//				win = 1;
//				wmin = min(tmp.zhi, wmin);//�����Է�������Ļغ���
//			}
//		}
//	}
//	if (!flag) {
//		//cout << "no choice\n";
//		dp[rest][who] = info{ false,0 };
//	}
//	if (win) {
//		//cout << wmin + 1 << '\n';
//		dp[rest][who] = info{ true,wmin + 1 };
//	}
//	else {
//		//cout << lmax + 1 << '\n';
//		dp[rest][who] = info{ false,lmax + 1 };
//	}
//	return dp[rest][who];
//}
//int main() {
//	egpty();
//	cin >> n >> k;
//	info t = f(n, 1);
//	if (t.win) {
//		cout << t.zhi << '\n';
//	}
//	else {
//		cout << -t.zhi << '\n';
//	}
//}
// 
// ��map�ͻ������ڹ��������������Ż�
//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAXN = 500005;
//int n, k;
//bool notPrime[MAXN];
//
//struct info {
//	bool win;
//	int zhi;
//	info(bool w = false, int a = 0) : win(w), zhi(a) {}
//};
//
//struct Node {
//	int p;
//	bool win;
//	int zhi;
//	Node(int _p, bool _w, int _z) : p(_p), win(_w), zhi(_z) {}
//};
//
//void sieve() {
//	notPrime[1] = true;
//	for (int i = 2; i < MAXN; i++) {
//		if (!notPrime[i]) {
//			for (int j = i + i; j < MAXN; j += i) {
//				notPrime[j] = true;
//			}
//		}
//	}
//}
//
//int main() {
//	sieve();
//	cin >> n >> k;
//	vector<vector<info>> dp(n + 1, vector<info>(2));
//
//	dp[1][0] = info(false, 0);
//	dp[1][1] = info(false, 0);
//
//	if (n == 1) {
//		cout << "0" << endl;
//		return 0;
//	}
//
//	queue<Node> q1, q2;
//	multiset<int> min_set1, max_set1, min_set2, max_set2;
//
//	for (int rest = 2; rest <= n; rest++) {
//		if (rest - 1 >= 2) {
//			if (!notPrime[rest - 1]) {
//				info tmp = dp[rest - 1][0];
//				if (tmp.win) {
//					max_set1.insert(tmp.zhi);
//				}
//				else {
//					min_set1.insert(tmp.zhi);
//				}
//				q1.push(Node(rest - 1, tmp.win, tmp.zhi));
//			}
//			else {
//				info tmp = dp[rest - 1][1];
//				if (tmp.win) {
//					max_set2.insert(tmp.zhi);
//				}
//				else {
//					min_set2.insert(tmp.zhi);
//				}
//				q2.push(Node(rest - 1, tmp.win, tmp.zhi));
//			}
//		}
//
//		while (!q1.empty() && q1.front().p < rest - k) {
//			Node node = q1.front();
//			q1.pop();
//			if (node.win) {
//				auto it = max_set1.find(node.zhi);
//				if (it != max_set1.end()) max_set1.erase(it);
//			}
//			else {
//				auto it = min_set1.find(node.zhi);
//				if (it != min_set1.end()) min_set1.erase(it);
//			}
//		}
//		while (!q2.empty() && q2.front().p < rest - k) {
//			Node node = q2.front();
//			q2.pop();
//			if (node.win) {
//				auto it = max_set2.find(node.zhi);
//				if (it != max_set2.end()) max_set2.erase(it);
//			}
//			else {
//				auto it = min_set2.find(node.zhi);
//				if (it != min_set2.end()) min_set2.erase(it);
//			}
//		}//�������ڽڵ�
//		//�ô��������ֵ���µ�ǰ�ڵ�
//		if (!min_set1.empty()) {
//			int m = *min_set1.begin();
//			dp[rest][1] = info(true, m + 1);
//		}
//		else if (!max_set1.empty()) {
//			int m = *max_set1.rbegin();
//			dp[rest][1] = info(false, m + 1);
//		}
//		else {
//			dp[rest][1] = info(false, 0);
//		}
//
//		if (!min_set2.empty()) {
//			int m = *min_set2.begin();
//			dp[rest][0] = info(true, m + 1);
//		}
//		else if (!max_set2.empty()) {
//			int m = *max_set2.rbegin();
//			dp[rest][0] = info(false, m + 1);
//		}
//		else {
//			dp[rest][0] = info(false, 0);
//		}
//	}
//	info res = dp[n][1];
//	if (res.win) {
//		cout << res.zhi << endl;
//	}
//	else {
//		cout << -res.zhi << endl;
//	}
//}

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int one, zero;
//vector<int>b;
//string s;
//int ans = 0;
//void check() {
//	vector<vector<int>>dp(50, vector<int>(50, 0));//ǰi���ַ�����j����ɫ��������
//	dp[0][0] = 1;
//	//cout << s.size() << " " << b.size() << '\n';
//	//for (int i = 0; i < b.size(); i++)cout << b[i] << " "; cout << '\n';
//	for (int i = 1; i <= s.size(); i++) {
//		for (int j = 0; j <= min(i, (int)(s.size()) >> 1); j++) {
//			if (j > 0 && dp[i - 1][j - 1] && b[j] == s[i - 1] - '0') {
//				dp[i][j] += dp[i - 1][j - 1];
//			}
//			if (i - j > 0 && i - j < b.size() && dp[i - 1][j] && b[i - j] == s[i - 1] - '0') {
//				dp[i][j] += dp[i - 1][j];
//			}
//		}
//	}
//	//cout << "haha\n";
//	//for (int i = 0; i < s.size(); i++) {
//	//	for (int j = 0; j <= min(i, int(b.size())-1); j++) {
//	//		cout << dp[i][j] << " ";
//	//	}
//	//	cout << '\n';
//	//}
//	ans += dp[s.size()][(int)(s.size()) >> 1];
//}
//void dfs() {
//	if (one == 0 && zero == 0) {
//		check();
//		return;
//	}
//	if (one > 0) {
//		one--;
//		b.push_back(1);
//		dfs();
//		b.pop_back();
//		one++;
//	}
//	if (zero) {
//		zero--;
//		b.push_back(0);
//		dfs();
//		b.pop_back();
//		zero++;
//	}
//}
//signed main() {
//	cin >> s;
//	one = count(s.begin(), s.end(), 'o');
//	zero = count(s.begin(), s.end(), 'x');
//	if (one & 1) {
//		cout << 0 << '\n';
//		return 0;
//	}
//	replace(s.begin(), s.end(), 'o', '1');
//	replace(s.begin(), s.end(), 'x', '0');
//	one /= 2;
//	zero /= 2;
//	b.push_back(-1);
//	dfs();
//	cout << ans << endl;
//}


//���������м���***
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 1e9 + 7;
//string s;
//int n;
//int x[3005];
//int dp[3005][3005];//0-l�ϵ������� ��r-n�ϱ�����rλ���ַ���ͷ�����������γɵĻ�������  һ�����ƿ�ͷһ�˲���
//signed main() {
//	cin >> s;
//	int n = s.size();
//	for (int i = 0; i < n; i++) {
//		x[i] = 1;
//	}
//	for (int l = 0; l < n; l++) {
//		int mid = l + 1;
//		int t = 0;
//		for (int r = n - 1; r > mid; r--) {
//			dp[l][r] = l - 1 >= 0 ? dp[l - 1][r] : 0;
//			if (s[l] == s[r]) {
//				dp[l][r] = (dp[l][r] + t + 1)%mod;
//			}
//			t = (t + (l - 1 >= 0 ? dp[l - 1][r] : 0)) % mod;
//			x[mid] = (x[mid] + dp[l][r])%mod;
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		ans ^= (i + 1) * x[i] % mod;
//	}
//	cout << ans << endl;
//}


//ţţ������
//#include<bits/stdc++.h>
//// #define int long long
//using namespace std;
//int dp[2505][2505];//0-i����0-j�ϵĲ��뷽��
//int asum[2505];
//int bsum[2505];
//const int mod = 1e9 + 7;
//signed main() {
//	string a, b;
//	cin >> a >> b;
//	//�����޽�
//	if (((int)(a.size() + b.size()) & 1) ||
//		count(a.begin(), a.end(), '(') + count(b.begin(), b.end(), '(') != (a.size() + b.size()) / 2) {
//		cout << 0 << endl;
//		return 0;
//	}
//	int na = a.size(), nb = b.size();
//	a = " " + a;
//	b = " " + b;
//	for (int i = na; i >= 1; i--) {
//		asum[i] = asum[i + 1] + (a[i] == '(' ? -1 : 1);
//	}
//	for (int i = nb; i >= 1; i--) {
//		bsum[i] = bsum[i + 1] + (b[i] == '(' ? -1 : 1);
//	}
//	//for (int i = 0, backsum; i <= na; i++) {
//	//	backsum = bsum[1] + asum[i + 1];
//	//	if (backsum >= 0) {
//	//		dp[i][0] = 1;
//	//	}
//	//}
//	//for (int i = 0, backsum; i <= nb; i++) {
//	//	backsum = bsum[i + 1] + asum[1];
//	//	if (backsum >= 0) {
//	//		dp[0][i] = 1;
//	//	}
//	//}
//	//0ʱҲҪ��ǰ׺�Ͳ��ܾ���
//	dp[0][0] = 1;
//	int backsum;
//	for (int i = 0; i <= na; i++) {
//		for (int j = 0; j <= nb; j++) {
//			backsum = asum[i + 1] + bsum[j + 1];
//			//cout << "(" << i << "," << j << ')' << ':' << backsum << endl;
//			if (backsum > 0) {
//				dp[i][j] = ((dp[i][j] + (i - 1 >= 0 ? dp[i - 1][j] : 0)) % mod + (j - 1 >= 0 ? dp[i][j - 1] : 0)) % mod;
//			}
//			else if (backsum == 0) {
//				if (a[i] == ')') {
//					dp[i][j] = (dp[i][j] + (i - 1 >= 0 ? dp[i - 1][j] : 0)) % mod;
//				}
//				if (b[j] == ')') {
//					dp[i][j] = (dp[i][j] + (j - 1 >= 0 ? dp[i][j - 1] : 0)) % mod;
//				}
//			}
//		}
//	}
//	//for (int i = 0; i <= na; i++) {
//	//	for (int j = 0; j <= nb; j++) {
//	//		cout << dp[i][j] << " ";
//	//	}
//	//	cout << '\n';
//	//}
//	cout << dp[na][nb] << endl;
//	return 0;
//}


//ţţȥ����
//���Բ��ö��ִ𰸣����״̬dp[i]��i�������С���� dp[i]=min(dp[i],dp[i-w]+v[i])
//memset(f , 0x3f , sizeof f);
//for (int i = 1; i <= n; i++) {
//	int w = a[i];  // ��������(ai+1)
//	for (int j = 50000; j >= w; j--)
//		f[j] = min(f[j], f[j - w] + v[i]);
//}
//for (int i = k; i <= 50000; i++) {
//	ans = min(ans, f[i]);
//}
//���ִ𰸰�
//#include<bits/stdc++.h>
//using namespace std;
//int n, k, sum = 0;
//vector<int>a;
//vector<int>b;
//vector<int>ab;
//vector<int>c;
//bool check(int m, int t, vector<int>& a, vector<int>& c) {
//	vector<int>dp(m + 5, 0);
//	for (int i = 1; i <= n; i++) {
//		for (int j = m; j >= c[i]; j--) {
//			dp[j] = max(dp[j], dp[j - c[i]] + a[i]);
//		}
//	}
//	return dp[m] >= t;
//}
//int getmincost(int t, vector<int>& a, vector<int>& c) {
//	int l = 0, r = sum, m, ans = INT_MAX;
//	while (l <= r) {
//		m = l + r >> 1;
//		if (check(m, t, a, c)) {
//			ans = m;
//			r = m - 1;
//		}
//		else {
//			l = m + 1;
//		}
//	}
//	return ans;
//}
//int main() {
//	cin >> n >> k;
//	a.resize(n + 1);
//	b.resize(n + 1);
//	ab.resize(n + 1);
//	c.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		ab[i] += a[i];
//		--a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//		ab[i] += b[i];
//		--b[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> c[i];
//		sum += c[i];
//	}
//	int ans = min({ getmincost(k,a,c),getmincost(k,b,c),getmincost(2 * k - 1,ab,c) });
//	cout << (ans == INT_MAX ? -1 : ans) << '\n';
//}


//ţţ������
//#include<bits/stdc++.h>
//#define i64 long long
//using namespace std;
//const int mod = 1e9 + 7;
//i64 dp[11][100005];//ǰi������j��β�ķ�����
//int main() {
//	int n, k;
//	cin >> n >> k;
//	i64 sum = k;
//	for (int i = 1; i <= k; i++) {
//		dp[1][i] = 1;
//	}
//	for (int i = 2; i <= n; i++) {
//		for (int j = 1; j <= k; j++) {
//			dp[i][j] = sum;
//			for (int m = j + j; m <= k; m += j) {
//				dp[i][j] = (dp[i][j] - dp[i - 1][m] + mod) % mod;
//			}
//		}
//		sum = 0;
//		for (int j = 1; j <= k; j++) {
//			sum = (sum + dp[i][j]) % mod;
//		}
//	}
//	cout << sum << '\n';
//}


//���̵ı�ʤ����
//#include<bits/stdc++.h>
//using namespace std;
//string g[55];
//int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//int main() {
//	int r, c, k;
//	cin >> r >> c >> k;
//	int x, y;
//	for (int i = 0; i < r; i++) {
//		cin >> g[i];
//		for (int j = 0; j < c; j++) {
//			if (g[i][j] == 'T') {
//				x = i;
//				y = j;
//			}
//		}
//	}
//	bool canmove = 0;
//	for (int d = 0; d < 4; d++) {
//		int nx = x + dx[d];
//		int ny = y + dy[d];
//		if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
//			if (g[nx][ny] == 'E') {
//				cout << "niuniu\n";
//				return 0;
//			}
//			if (g[nx][ny] != '#') {
//				canmove = 1;
//			}
//		}
//	}
//	if (!canmove) {
//		cout << "niumei\n";
//		return 0;
//	}
//	if (!(k & 1)) {
//		cout << "niumei\n";
//		return 0;
//	}
//	if (k == 1) {
//		cout << "niuniu\n";
//		return 0;
//	}
//	for (int d = 0; d < 4; d++) {
//		int nx = x + dx[d];
//		int ny = y + dy[d];
//		if (nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny] != '#') {
//			bool flag = 1;
//			for (int d1 = 0; d1 < 4; d1++) {
//				int nnx = nx + dx[d1];
//				int nny = ny + dy[d1];
//				if (nnx >= 0 && nnx < r && nny >= 0 && nny < c && g[nnx][nny] == 'E') {
//					flag = 0;
//				}
//			}
//			if (flag) {
//				cout << "niuniu\n";
//				return 0;
//			}
//		}
//	}
//	cout << "niumei\n";
//}


//ţţ�ļ�����ڴ�
//�����̰�İ�
//#include<bits/stdc++.h>
//using namespace std;
//string s[25];
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		cin >> s[i];
//	}
//	string state = string(m, '0');
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		int mincost = INT_MAX;
//		int minpos = i;
//		for (int j = i; j < n; j++) {
//			int cost = 0;
//			for (int k = 0; k < m; k++) {
//				if (s[j][k] == '1' && state[k] == '0') {
//					cost++;
//				}
//			}
//			if (cost < mincost) {
//				minpos = j;
//				mincost = cost;
//			}
//		}
//		swap(s[minpos], s[i]);
//		for (int j = 0; j < m; j++) {
//			if (s[i][j] == '1') {
//				state[j] = '1';
//			}
//		}
//		ans += mincost * mincost;
//	}
//	cout << ans << '\n';
//}
//̰�Ĳ�֪��Ϊʲô�� 
//״ѹdp��
//#include<bits/stdc++.h>
//using namespace std;
//int a[25];
//int n, m;
//int es;
//int popcount(int x) {
//	int count = 0;
//	while (x) {
//		count += x & 1;
//		x >>= 1;
//	}
//	return count;
//}
//int dp[1 << 20];
//int f(int state, int cur) {//�ڵ�ǰ��������µ���С���ʻ��� cur��ʾ�ڴ�������(��state����)
//	if (dp[state] != -1)return dp[state];
//	if (state == es)return 0;
//	int ans = INT_MAX;
//	for (int i = 0; i < n; i++) {
//		if (!((state >> i) & 1)) {
//			ans = min(ans, f(state | (1 << i), cur | a[i]) + popcount((a[i] | cur) ^ cur) * popcount((a[i] | cur) ^ cur));
//		}
//	}
//	dp[state] = ans;
//	return ans;
//}
//int main() {
//	cin >> n >> m;
//	memset(dp, -1, sizeof(dp));
//	es = (1 << n) - 1;
//	string s;
//	for (int i = 0; i < n; i++) {
//		cin >> s;
//		for (int j = 0; j < m; j++) {
//			a[i] = a[i] * 2 + s[j] - '0';
//		}
//	}
//	cout << f(0, 0) << '\n';
//}



//¥��
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 1e9 + 9;
//int fac[1305];
//int inv[1305];//�洢�׳˵���Ԫ
//int dp[1305][1305];//����ѡiλ�ú���λ���γ�j����ɫ�ķ�����(ͳ�����н�ͳ�ƺ�������)
//int qpow(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a % mod;
//		}
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ans;
//}
//void prepare() {
//	fac[0] = 1;
//	for (int i = 1; i <= 1300; i++) {
//		fac[i] = i * fac[i - 1] % mod;
//	}
//	inv[1300] = qpow(fac[1300], mod - 2);
//	//cout <<fac[1300]<<" "<< inv[1300] << '\n';
//	for (int i = 1299; i >= 1; i--) {
//		inv[i] = inv[i + 1] * (i + 1) % mod;
//	}
//	inv[0] = 1;
//
//}
//int f(int k, int n) {//��k��������˳��Ĳ���n�����䵫���ܲ����һ����֮ǰ
//	return fac[n + k - 1] * inv[n - 1] % mod;
//}
//signed main() {
//	prepare();
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n, l;
//	cin >> n >> l;
//	vector<int>color(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> color[i];
//	}
//	dp[n][1] = 1;
//	for (int i = n - 1; i >= 1; i--) {
//		for (int j = l; j >= 1; j--) {
//			for (int k = i + 1; k <= n; k++) {
//				if (dp[k][j - 1] == 0 && dp[k][j] == 0)break;
//				if (color[k] == color[i]) {
//					//cout << "same:" << i << " " << k<<" "<<j << '\n';
//					dp[i][j] = (dp[i][j] + dp[k][j] * f(k - i - 1, n - k + 1) % mod) % mod;
//				}
//				else {
//					//cout << "diff:" << i << " " << k <<" "<<j << '\n';
//					dp[i][j] = (dp[i][j] + dp[k][j - 1] * f(k - i - 1, n - k + 1) % mod) % mod;
//					//cout << k-i-1<<" "<<n-k+1<<" "<<f(k - i - 1, n - k + 1) << '\n';
//				}
//			}
//		}
//	}
//	//for (int i = n; i >= 1; i--) {
//	//	for (int j = 0; j <= l; j++) {
//	//		cout << dp[i][j] << " ";
//	//	}
//	//	cout << endl;
//	//}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		ans = (ans + dp[i][l] * f(i - 1, n - i + 1) % mod) % mod;
//	}
//	cout << ans << endl;
//}
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int mod = 1e9 + 9;
//int fac[1305];
//int inv[1305];//�洢�׳˵���Ԫ
//int qpow(int a, int b) {
//	int ans = 1;
//	while (b != 0) {
//		if (b & 1) {
//			ans = ans * a % mod;
//		}
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ans;
//}
//void prepare() {
//	fac[0] = 1;
//	for (int i = 1; i <= 1300; i++) {
//		fac[i] = i * fac[i - 1] % mod;
//	}
//	inv[1300] = qpow(fac[1300], mod - 2);
//	//cout <<fac[1300]<<" "<< inv[1300] << '\n';
//	for (int i = 1299; i >= 1; i--) {
//		inv[i] = inv[i + 1] * (i + 1) % mod;
//	}
//	inv[0] = 1;
//
//}
//int f(int k, int n) {//��k��������˳��Ĳ���n�����䵫���ܲ����һ����֮ǰ
//	return fac[n + k - 1] * inv[n - 1] % mod;
//}
//int ginv(int x) {
//	return qpow(x, mod - 2);
//}
//int dp[1305][1305];//��c��ɫ��ͷ,�γ�l���ȵĿɼ���ɫ�ķ�����dp[0][l]��¼l���ȵ��ܷ�����
//signed main() {
//	prepare();
//	int n, l;
//	cin >> n >> l;
//	vector<int>color(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> color[i];
//	}
//	dp[color[n]][1] = dp[0][1]=1;
//	for (int i = n - 1; i >= 1; i--) {//�Ӻ���ǰ����color����
//		int tmp=ginv(n-i);
//		for (int j = l; j > 1; j--) {//��������
//			dp[0][j] =(dp[0][j]+ (dp[0][j - 1] - dp[color[i]][j - 1] + dp[color[i]][j]+mod)%mod * tmp)%mod;//dp[0][j-1]-dp[color][j-1]���ǰһ���ȿ�ͷ��ɫ�뵱ǰ��ɫ��ͬ�ķ����� dp[color[i]][j]��ͬ������
//			dp[color[i]][j] =(dp[color[i]][j]+ (dp[0][j - 1] - dp[color[i]][j - 1] + dp[color[i]][j] + mod) % mod * tmp)%mod;
//		}
//		//j=1��ʱ��Ҫ��������Ϊ��ߵĿ϶������һ��,���ҽ���color[i]�����һ����ɫ��ͬʱ�Ÿ���,��Ϊ��ͬ�������Ը�λ�ÿ�ͷ�γ�1
//		if (color[i] == color[n]) {
//			dp[0][1] =(dp[0][1]+ dp[color[n]][1] * tmp)%mod;
//			dp[color[n]][1]=(dp[0][1]+ dp[color[n]][1] * tmp)%mod;
//		}
//	}
//	for (int i = n - 1; i >= 1; i--) {
//		(dp[0][l] *= (n - i)) %= mod;
//	}
//	cout << dp[0][l] << '\n';
//}



//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; i++)cin >> a[i];
//	vector<int>ed(33,0);//��iλ��Ϊ0������β�������
//	for (int i = 1; i <= n; i++) {
//		int t = a[i];
//		int p = 0;
//		int mx = 0;
//		while (t != 0) {
//			if (t & 1) {
//				ed[p] += 1;
//				mx = max(mx, ed[p]);
//			}
//			p++;
//			t >>= 1;
//		}
//		t = a[i];
//		p = 0;
//		while (t != 0) {
//			if (t & 1) {
//				ed[p] = max(ed[p], mx);
//			}
//			p++;
//			t >>= 1;
//		}
//	}
//	int ans = INT_MIN;
//	for (int i = 0; i < 32; i++) {
//		ans = max(ans, ed[i]);
//	}
//	cout << ans << '\n';
//}



//#include<bits/stdc++.h>
//using namespace std;
//signed main() {
//	int l;
//	int s, t, m;
//	cin >> l;
//	cin >> s >> t >> m;
//	vector<int>rock(m + 2, 0);
//	for (int i = 1; i <= m; i++) {
//		cin >> rock[i];
//	}
//	rock[m + 1] = INT_MAX;
//	sort(rock.begin()+1, rock.end()-1);
//	vector<vector<int>>a;
//	vector<int>tmp;
//	for (int i = 1; i <= m; i++) {
//		if (rock[i] + 1000 > rock[i + 1]&&rock[i+1]!=INT_MAX) {
//			tmp.push_back(rock[i]);
//		}
//		else {
//			tmp.push_back(rock[i]);
//			a.push_back(tmp);
//			tmp.clear();
//		}
//	}
//	//for (int i = 0; i < a.size(); i++) {
//	//	for (auto v : a[i])cout << v << " ";
//	//	cout << '\n';
//	//}
//	vector<int>dp;
//	set<int>r;
//	int ans = 0;
//	for (int i = 0; i < a.size(); i++) {
//		tmp.clear();
//		if (a[i][0] > 11) {
//			for (int j = 1; j < a[i].size(); j++) {
//				a[i][j] -= a[i][0] - 11;
//				r.insert(a[i][j]);
//			}
//			a[i][0] = 11;
//			r.insert(11);
//			dp.assign(a[i].back() + 20, INT_MAX);
//			for (int j = 0; j <= 10; j++) {
//				dp[j] = 0;
//			}
//			//for (auto v : a[i])cout << v << " ";
//			//cout << '\n';
//			for (int j = 11; j <= a[i].back() + 11; j++) {
//				for (int k = s; k <= t; k++) {
//					if(dp[j-k]!=INT_MAX)
//					dp[j] = min(dp[j], dp[j - k] + (int)(r.count(j - k)));
//				}
//			}
//			ans += dp[a[i].back() + 11];
//		}
//		else {
//			for (int j = 0; j < a[i].size(); j++) {
//				r.insert(a[i][j]);
//			}
//			dp.assign(a[i].back() + 20, INT_MAX);
//			dp[0] = 0;
//			for (int j = 1; j <= a[i].back() + 11; j++) {
//				for (int k = s; k <= t; k++) {
//					if (j - k >= 0&&dp[j-k]!=INT_MAX) {
//						dp[j] = min(dp[j], dp[j - k] + (int)(r.count(j - k)));
//					}
//				}
//			}
//			ans += dp[a[i].back() + 11];
//		}
//	}
//	cout << ans << '\n';
//}
//


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int safe = 201;
//signed main() {
//	int l;
//	cin >> l;
//	int s, t, m;
//	cin >> s >> t >> m;
//	vector<int>a(m + 1);
//	vector<int>where(m + 1);
//	vector<bool>stone(1000000);
//	for (int i = 1; i <= m; i++) {
//		cin >> a[i];
//	}
//	sort(a.begin() + 1, a.end());
//	if (s == t) {
//		int ans = 0;
//		for (int i = 1; i <= m; i++) {
//			if (a[i] % s == 0) {
//				ans++;
//			}
//		}
//		cout << ans << '\n';
//		return 0;
//	}
//	for (int i = 1; i <= m; i++) {
//		where[i] = where[i - 1] + min(a[i] - a[i - 1], safe);
//		stone[where[i]] = true;
//	}
//	vector<int>dp(where.back()+safe+1, INT_MAX);
//	dp[0] = 0;
//	for (int i = 1; i <= where.back()+safe; i++) {
//		for (int k = s; k <= t; k++) {
//			if (i - k >= 0&&dp[i-k]!=INT_MAX) {
//				dp[i] = min(dp[i], dp[i - k]+stone[i-k]);
//			}
//		}
//	}
//	cout << dp[where.back() + safe]<<'\n';
//}


//#include<bits/stdc++.h>
//using namespace std;
//int f(int m, int n) {
//	if (m == 0) {
//		return 1;
//	}
//	if (n == 0)return 0;
//	if (m < n)return f(m, m);
//	return f(m, n - 1) + f(m - n, n);
//}
//int main() {
//	int m, n;
//	cin >> m >> n;
//	int t = 1;
//	cout << f(m, n) << '\n';
//}


//�Ӽ���****************************************************************************************************************************************
//����˼��
//����˼������Ҫ�Ż�
//#include<bits/stdc++.h>
//using namespace std;
//int dp[101][10001];//i��������j����������ٲ�
//class Solution {
//public:
//    int superEggDrop(int k, int n) {
//        memset(dp, 0, sizeof(dp));
//        if (k == 1)return n;
//        for (int j = 1; j <= n; j++)dp[1][j] = j;
//        for (int j = 1; j <= n; j++) {
//            for (int i = 2; i <= k; i++) {
//                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + 1;
//                if (dp[i][j] >= n)return j;
//            }
//        }
//        return -1;
//    }
//};
//�۲���ƺ��������Է�
//#include<bits/stdc++.h>
//using namespace std;
//int dp[101][10001];
//int f(int k, int n) {
//    if (dp[k][n] != -1)return dp[k][n];
//    if (n == 0) {
//        return dp[k][n] = 0;
//    }
//    if (k == 1) {
//        return dp[k][n] = n;
//    }
//    int hi = n, lo = 1;
//    while (lo + 1 < hi) {
//        int mid = lo + hi / 2;
//        int m1 = f(k - 1, mid-1);
//        int m2 = f(k, n-mid);
//        if (m1 < m2) {
//            lo = mid;
//        }
//        else {
//            lo=hi = mid;
//        }
//    }
//    return dp[k][n] = 1 + min(max(f(k - 1, lo - 1), f(k, n - lo)), max(f(k - 1, hi - 1), f(k, n - hi)));
//}
//class Solution {
//public:
//    int superEggDrop(int k, int n) {
//        memset(dp, -1, sizeof(dp));
//        return f(k, n);
//    }
//};

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 5;
//const int NA = LLONG_MIN;
//int dp[N][2];
//int f(vector<int>& b, int i, int free) {
//	if (dp[i][free] != NA)return dp[i][free];
//	if (i == b.size())return dp[i][free] = 0;
//	if (free == 0) {
//		return dp[i][free] = b[i] + f(b, i + 1, 1);
//	}
//	return dp[i][free] = max(b[i] + f(b, i + 1, 1), f(b, i + 1, 0));
//}
//bool check(int t, vector<int>& a) {
//	vector<int>b(a.size());
//	for (int i = 1; i < a.size(); i++) {
//		if (a[i] >= t) {
//			b[i] = 1;
//		}
//		else {
//			b[i] = -1;
//		}
//	}
//	for (int i = 0; i < b.size(); i++) {
//		dp[i][0] = dp[i][1] = NA;
//	}
//	return f(b, 1, 1) > 0;
//}
//
//const double inf = 1e15;
//double sml = 1e-5;
//double dp1[N][2];
//double g(vector<double>& b, int i, int free) {
//	if (abs(dp1[i][free] - inf)>sml)return dp1[i][free];
//	if (i == b.size())return dp1[i][free] = 0;
//	if (free == 0) {
//		return dp1[i][free] = b[i] + g(b, i + 1, 1);
//	}
//	return dp1[i][free] = max(b[i] + g(b, i + 1, 1), g(b, i + 1, 0));
//}
//bool check1(double t, vector<int>& a) {
//	vector<double>b(a.size());
//	for (int i = 1; i < a.size(); i++) {
//		b[i] = a[i] - t;
//	}
//	for (int i = 0; i < a.size(); i++) {
//		dp1[i][0] = dp1[i][1] = inf;
//	}
//	return g(b, 1, 1) >= 0;
//}
//signed main() {
//	int n;
//	cin >> n;
//	vector<int>a(n + 1);
//	int mn = LLONG_MAX, mx = LLONG_MIN;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		mn = min(mn, a[i]);
//		mx = max(mx, a[i]);
//	}
//
//	{
//		double l = 0, r = mx,ans=0;
//		while (l + sml < r) {
//			double mid = (l + r) / 2;
//			if (check1(mid, a)) {
//				ans = mid;
//				l = mid + sml;
//			}
//			else {
//				r = mid - sml;
//			}
//		}
//		cout << ans << '\n';
//	}
//
//
//	{
//		int l = mn, r = mx, ans = -1;
//		while (l <= r) {
//			int mid = l + r >> 1;
//			if (check(mid, a)) {
//				ans = mid;
//				l = mid + 1;
//			}
//			else {
//				r = mid - 1;
//			}
//		}
//		cout << ans << '\n';
//	}
//}


//�����ԲμӵĻ�����Ŀ II
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//class Solution {
//public:
//    int maxValue(vector<vector<int>>& events, int k) {
//        sort(events.begin(), events.end(), [&](auto& x, auto& y) {
//            return x[1] < y[1];
//            });
//        vector<vector<int>>dp(events.size() + 1, vector<int>(k + 1, 0));
//        for (int i = 1; i <= k; i++) {
//            dp[0][i] = events[0][2];
//        }
//        for (int i = 1; i < events.size(); i++) {
//            for (int j = 1; j <= k; j++) {
//                dp[i][j] = dp[i - 1][j];
//                auto x = upper_bound(events.begin(), events.end(), events[i][0], [&](int t, vector<int>& a) {
//                    return t <= a[1];
//                    });
//                //cout << i << " " << x - events.begin() << '\n';
//                if (x == events.end() || x == events.begin()) {
//                    dp[i][j] = max(dp[i][j], events[i][2]);
//                }
//                else {
//                    dp[i][j] = max(dp[i][j], dp[x - events.begin() - 1][j - 1] + events[i][2]);
//                }
//            }
//        }
//        return dp[events.size() - 1][k];
//    }
//};


//��·
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 51;
//bool st[N][N][64];//i-j�ܲ�����pow(2,p)������
//int g[N][N];
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			g[i][j] = LLONG_MAX;
//		}
//	}
//	for (int i = 1,u,v; i <= m; i++) {
//		cin >> u >> v;
//		st[u][v][0] = true;
//		g[u][v] = 1;
//	}
//	for (int p = 1; p < 64; p++) {
//		for (int brg = 1; brg <= n; brg++) {
//			for (int i = 1; i <= n; i++) {
//				for (int j = 1; j <= n; j++) {
//					if (st[i][brg][p - 1] == true && st[brg][j][p - 1] == true) {
//						st[i][j][p] = true;
//						g[i][j] = 1;
//					}
//				
//				}
//			}
//		}
//	}
//	for (int brg = 1; brg <= n; brg++) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				if (g[i][brg] != LLONG_MAX && g[brg][j] != LLONG_MAX&&g[i][brg]+g[brg][j]<g[i][j]) {
//					g[i][j] = g[i][brg] + g[brg][j];
//				}
//			}
//		}
//	}
//	cout << g[1][n] << '\n';
//}



//#include<bits/stdc++.h>
//using namespace std;
//int nex[205][26];
//long long st[205][29];//��iλ�ó������1<<p��s2Ҫ����
//class Solution {
//public:
//    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
//        string temp = s1 + s1;
//        memset(nex, -1, sizeof(nex));
//        for (int i = temp.size() - 1; i >= 0; i--) {
//            for (int j = 0; j < 26; j++) {
//                nex[i][j] = nex[i + 1][j] == -1 ? -1 : nex[i + 1][j] + 1;
//            }
//            nex[i][temp[i] - 'a'] = 1;
//        }
//        int n = s1.size();
//        for (int i = 0; i < s1.size(); i++) {
//            int cur = i;
//            int len = 0;
//            for (int j = 0; j < s2.size(); j++) {
//                if (nex[cur][s2[j] - 'a'] == -1)return 0;
//                len += nex[cur][s2[j] - 'a'];
//                cur = (cur + nex[cur][s2[j] - 'a']) % n;
//            }
//            st[i][0] = len;
//        }
//        for (int p = 1; p < 29; p++) {
//            for (int i = 0; i < n; i++) {
//                st[i][p] = st[i][p - 1] + st[(i + st[i][p - 1]) % n][p - 1];
//            }
//        }
//        // cout << n << '\n';
//        // for (int i = 0; i < n; i++) {
//        //     for (int j = 0; j < 26; j++) {
//        //         cout << st[i][j] << " ";
//        //     }cout << '\n';
//        // }
//        long long ans = 0;
//        for (int p = 28, start = 0; p >= 0; p--) {
//            if (st[start % n][p] + start <= n * n1) {
//                ans += 1 << p;
//                start = start + st[start % n][p];
//            }
//        }
//        return ans / n2;
//    }
//};


//��������
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 5;
//int h[N];
//int dis1[N];//�뵱ǰ��������ĳ��еľ���
//int to1[N];//���ĸ�����
//int dis2[N];//�뵱ǰ���еڶ����ĳ��еľ���
//int to2[N];//���ĸ�����
//
//int stto[N][21];//�ӵ�ǰ���г�����i�ֵ��ĸ���
//int stdis[N][21];//�ӵ�ǰ���г�����i���ߵ��ܾ���
//int stA[N][21];//�ӵ�ǰ���м����A�ߵ��ܾ���
//int stB[N][21];//B
////������������ĸ����ṹ
//int pre[N];
//int nex[N];
//
//int a, b;
//int n;
//
//void travel(int s,int x) {
//	a = 0, b = 0;
//	int dis = 0;
//	for (int p = 20; p >= 0; p--) {
//		if (stto[s][p]!=0&&dis+stdis[s][p] <= x) {
//			a += stA[s][p];
//			b += stB[s][p];
//			dis+= stdis[s][p];
//			s = stto[s][p];
//		}
//	}
//	if (dis2[s]+dis <= x) {
//		a += dis2[s];
//	}
//}
//
//int best(int x0) {
//	int ans = 0;
//	int mo, son;
//	for (int i = 1; i < n; i++) {
//		travel(i, x0);
//		// cur��ô���ø���ȫһЩ
//		if (b == 0)continue;
//		if (ans == 0  ||a*mo<b*son||a*mo==b*son&&h[i] > h[ans]) {
//			ans = i;
//			mo = b;
//			son = a;
//		}
//	}
//	return ans;
//}
//
////int best(int x0) {
////	if (n <= 1) return 1; // �����߽����
////	int ans = 1; // �ӵ�һ����ЧԪ�ؿ�ʼ��ʼ��
////	// �ȼ����һ��Ԫ�ص�a��b����ʼ�����ӷ�ĸ
////	travel(1, x0);
////	int mo = b;    // ��ʼ����ĸΪ��һ��Ԫ�ص�b
////	int son = a;   // ��ʼ������Ϊ��һ��Ԫ�ص�a
////
////	for (int i = 2; i < n; i++) { // �ӵڶ���Ԫ�ؿ�ʼ�Ƚ�
////		travel(i, x0);
////		// �������0�����bΪ0����Ϊ��Ч�⣬������
////		if (b == 0) continue;
////
////		// �Ƚϵ�ǰi��a/b�����Ž��son/mo
////		// �ȼ��ڱȽ� a*mo < son*b��������ˣ����⸡������
////		if ((long long)a * mo < (long long)son * b) {
////			ans = i;
////			son = a;
////			mo = b;
////		}
////		// ���ʱ��ȡh[i]�����
////		else if ((long long)a * mo == (long long)son * b && h[i] > h[ans]) {
////			ans = i;
////			son = a;
////			mo = b;
////		}
////	}
////	return ans;
////}
//
//signed main() {
//	
//	cin >> n;
//	for (int i = 1; i <=n; i++) {
//		cin >> h[i];
//	}
//	vector<int>idx(n + 2);
//	iota(idx.begin(), idx.end(), 0);
//	sort(idx.begin() + 1, idx.begin() + n, [&](int x,int y) {
//		return h[x] < h[y];
//		});
//	for (int i = 1; i <= n; i++) {
//		pre[idx[i]] = idx[i - 1];
//		nex[idx[i]] = idx[i + 1];
//	}
//
//	auto update = [&](int cur, int id) ->void {
//		if (id == 0||id==n+1)return;
//		int dis = abs(h[id] - h[cur]);
//		if (to1[cur]==0||dis < dis1[cur]||dis==dis1[cur]&&h[id]<h[to1[cur]]) {
//			dis2[cur] = dis1[cur];
//			to2[cur] = to1[cur];
//			dis1[cur] = dis;
//			to1[cur] = id;
//		}
//		else if(to2[cur]==0||dis<dis2[cur]||dis==dis2[cur]&&h[id]<h[to2[cur]]) {
//			dis2[cur] = dis;
//			to2[cur] = id;
//		}
//	};
//	for (int i = 1; i <= n; i++) {
//		int l = pre[i];int ll = pre[pre[i]];int r = nex[i];int rr = nex[nex[i]];
//		update(i, l);update(i, ll);update(i, r);update(i, rr);
//		pre[nex[i]] = pre[i];
//		nex[pre[i]] = nex[i];
//	}
//
//	//{
//	//	cout << "---------------\n";
//	//	for (int i = 1; i <= n; i++) {
//	//		//cout << pre[i] << " " << nex[i] << '\n';
//	//		cout << to1[i] <<" "<< dis1[i] << " " << to2[i] << " " << dis2[i] << '\n';
//	//	}
//	//	cout << "---------------\n";
//	//}
//
//	for (int i = 1; i <= n; i++) {
//		stto[i][0] = to1[to2[i]];
//		stdis[i][0] = dis2[i] + dis1[to2[i]];
//		stA[i][0] = dis2[i];
//		stB[i][0] = dis1[to2[i]];
//	}
//	for (int p = 1; p <= 20; p++) {
//		for (int i = 1; i <= n; i++) {
//			stto[i][p] = stto[stto[i][p - 1]][p - 1];
//			if (stto[i][p] != 0) {
//				stdis[i][p] = stdis[i][p - 1] + stdis[stto[i][p - 1]][p - 1];
//				stA[i][p] = stA[i][p - 1] + stA[stto[i][p - 1]][p - 1];
//				stB[i][p] = stB[i][p - 1] + stB[stto[i][p - 1]][p - 1];
//			}
//		}
//	}
//	int x0,m;
//	cin >> x0>>m;
//	//double bizhi=1e17;
//	//int city = 1;
//	//for (int i = 1; i < n; i++) {
//	//	travel(i, x0);
//	//	double cur = b == 0 ? 1e17 : (double(a) / b);
//	//	if (city == 0 || cur < bizhi || abs(cur - bizhi) < sml && h[i] > h[city]) {
//	//		city = i;
//	//		bizhi = cur;
//	//	}
//	//}
//
//	cout << best(x0) << '\n';
//	for (int i = 1,s,x; i <= m; i++) {
//		cin >> s >> x;
//		travel(s, x);
//		cout << a << " " << b << '\n';
//	}
//}