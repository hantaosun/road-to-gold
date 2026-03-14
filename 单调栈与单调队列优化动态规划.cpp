//琪露诺
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int NA = INT_MIN;
//signed main() {
//	int n, l, r;
//	cin >> n >> l >> r;
//	vector<int>a(n + 1);
//	for (int i = 0; i <= n; i++) {
//		cin >> a[i];
//	}
//	deque<int>q;
//	vector<int>dp(n + 1,NA);
//	dp[0] = 0;
//	for (int i = 1; i <= n; i++) {
//		if (i - l < 0)continue;
//		while (!q.empty()&&(dp[q.back()] < dp[i - l] || dp[q.back()] == NA)) {
//			q.pop_back();
//		}
//		q.push_back(i - l);
//		if (i - r - 1 >= 0) {
//			while (!q.empty()&&q.front() <= i - r - 1) {
//				q.pop_front();
//			}
//		}
//		if (q.empty())dp[i] = NA;
//		else dp[i] = dp[q.front()] + a[i];
//	}
//	int ans = INT_MIN;
//	for (int i = n; i >= n - r+1; i--) {
//		ans = max(ans, dp[i]);
//	}
//	cout << ans << '\n';
//}


//Power收集
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 4002;
//int grid[N][N];
//int dp[N][N];
//int main() {
//	int n, m, k, t;
//	cin >> n >> m >> k >> t;
//	for (int i = 1, x, y, v; i <= k; i++) {
//		cin >> x >> y >> v;
//		grid[x][y] = v;
//	}
//	for (int i = 1; i <= m; i++) {
//		dp[1][i] = grid[1][i];
//	}
//	deque<int>q;
//	for (int i = 2; i <= n; i++) {
//		q.clear();
//		for (int j = 1; j <= t; j++) {
//			while (!q.empty() && dp[i - 1][q.back()] < dp[i - 1][j]) {
//				q.pop_back();
//			}
//			q.push_back(j);
//		}
//		for (int j = 1; j <= m; j++) {
//			if (j + t <= m) {
//				while (!q.empty()&&dp[i - 1][q.back()] < dp[i - 1][j + t]) {
//					q.pop_back();
//				}
//				q.push_back(j + t);
//			}
//			if (j - t - 1 >= 1) {
//				while (!q.empty()&&q.front() <= j - t - 1) {
//					q.pop_front();
//				}
//			}
//			dp[i][j] = dp[i - 1][q.front()]+grid[i][j];
//		}
//	}
//	int ans = INT_MIN;
//	for (int i = 1; i <= m; i++) {
//		ans = max(ans, dp[n][i]);
//	}
//
//	//{
//	//	for (int i = 1; i <= n; i++) {
//	//		for (int j = 1; j <= m; j++) {
//	//			cout << grid[i][j] << ' ';
//	//		}cout << '\n';
//	//	}
//	//	cout << '\n';
//	//	for (int i = 1; i <= n; i++) {
//	//		for (int j = 1; j <= m; j++) {
//	//			cout << dp[i][j] << ' ';
//	//		}cout << '\n';
//	//	}
//	//}
//
//	cout << ans << '\n';
//}


//Moving the lawn G
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e5 + 2;
//int dp[N];//1-i范围上不违规的情况下获得的最大累加和
//using namespace std;
//signed main() {
//	int n, k;
//	cin >> n >> k;
//	vector<int>cow(n + 1);
//	vector<int>presum(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> cow[i];
//		presum[i] = presum[i - 1] + cow[i];
//	}
//	deque<int>q;
//	auto val = [&](int i)->int {
//		if (i == 0) {
//			return 0;
//		}
//		return dp[i - 1] - presum[i];
//	};
//	q.push_back(0);
//	for (int i = 1; i <= n; i++) {
//		while (!q.empty() && val(q.back()) < val(i)) {
//			q.pop_back();
//		}
//		q.push_back(i);
//		while (!q.empty() && q.front() <= i - k - 1) {
//			q.pop_front();
//		}
//		dp[i] = val(q.front()) + presum[i];
//	}
//	cout << dp[n]<<'\n';
//}


//#include<bits/stdc++.h>
//using namespace std;
//struct worker {
//	int l, p, s;
//	worker(int l,int p,int s) {
//		this->l = l;
//		this->p = p;
//		this->s = s;
//	}
//	worker() {
//
//	}
//};
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n, k;
//	cin >> n >> k;
//	vector<worker>a(k+2);
//	for (int i = 1; i <= k; i++) {
//		cin >> a[i].l>>a[i].p>>a[i].s;
//	}
//
//	sort(a.begin()+1, prev(a.end()), [&](auto &x,auto &y) {
//		return x.s < y.s;
//		});	
//	a[k + 1].s = n + 1;
//	a[0].s = 0;
//	vector<int>dp(n + 1);//前一个工人最右刷到x位置获得的最大收益
//	deque<int>q;
//	auto val = [&](int j, int v)->int {
//		return dp[j] - (j - 1) * v;
//		};
//	for (int i = 1; i <= k; i++) {
//		q.clear();
//		for (int t = min(n, a[i].s + a[i].l - 1); t >= max(1, min(n, a[i].s + a[i].l - 1) - a[i].l)+1; t--) {
//			q.push_back(t);
//		}
//		for (int j = min(n,a[i].s+a[i].l - 1); j >= a[i].s; j--) {//这里错了实际上窗口只包含a[i].s左侧的部分，因为a[i].s必选
//			if (j - a[i].l >= 1) {
//				while (!q.empty() && val(q.back(),a[i].p) < val(j - a[i].l + 1,a[i].p)) {
//					q.pop_back();
//				}
//				q.push_back(j - a[i].l + 1);
//			}
//			while (!q.empty() && q.front() >= j) {
//				q.pop_front();
//			}
//			if(!q.empty()) dp[j] = val(q.front(),a[i].p) + j * a[i].p;
//			/*for (int l = j; l >= max(1,j - a[i].l + 1); l--) {
//				
//				cout << l <<" "<<j<< '\n';
//				dp[j] = max(dp[j], (l > 0 ? dp[l - 1] : 0) + (j - l + 1) * a[i].p);
//			}*/
//		}
//		for (int j = min(n, a[i].s + a[i].l - 1) + 1; j <= n; j++) {
//			dp[j] = max(dp[j], dp[j - 1]);
//		}
//		//for (int j = 0; j <= n; j++) {
//		//	cout << dp[j] << ' ';
//		//}cout << "\n";
//	}
//	int ans = INT_MIN;
//	for (int i = 0; i <= n; i++) {
//		ans = max(ans, dp[i]);
//	}
//	cout << ans << '\n';
//}




//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const int N = 105;
//const ll NA = LLONG_MAX;
////ll dp[N][N];//当前来到第i号工厂解决前j个机器人需要的最小距离
//class Solution {
//public:
//    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
//        sort(robot.begin(), robot.end());
//        sort(factory.begin(), factory.end(), [&](auto& x, auto& y) {
//            return x[0] < y[0];
//            });
//        int m = robot.size();
//        int n = factory.size();
//        robot.insert(robot.begin(), 0);
//        factory.insert(factory.begin(), { 0,0 });
//        //dp[0][0] = 0;
//        //for (int i = 1; i <= m; i++) {
//        //    dp[0][i] = NA;
//        //}
//        vector<ll>sum(m + 1,0);
//        deque<ll>q;
//        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
//        // 初始化：所有工厂处理0个机器人的距离为0
//        for (int i = 0; i <= n; i++) {
//            dp[i][0] = 0;
//        }
//        auto dis = [&](int i, int j)->ll {
//            return abs((ll)(robot[j]) - factory[i][0]);
//            };
//        //auto val = [&](int i, int j)->ll {
//        //    if (dp[i - 1][j - 1] == NA)return NA;
//        //    return dp[i - 1][j - 1] - sum[j - 1];
//        //};
//        for (int i = 1; i <= n; i++) {
//            int cap = factory[i][1];
//            sum[0] = 0;
//            for (int j = 1; j <= m; j++) {
//                sum[j] = sum[j - 1] + dis(i, j);
//            }
//            q.clear();
//            auto val = [&](int j) -> long long {
//                if (dp[i - 1][j - 1] == LLONG_MAX) return LLONG_MAX;
//                return dp[i - 1][j - 1] - sum[j - 1];
//                };
//            for (int j = 1; j <= m; j++) {
//                dp[i][j] = dp[i - 1][j];//该工厂不用
//                if (val(j) != NA) {
//                    while (!q.empty() && val(q.back()) >= val(j)) {
//                        q.pop_back();
//                    }
//                    q.push_back(j);
//                }
//                if (j - cap > 0) {
//                    while (!q.empty() && q.front() <= j - cap) {
//                        q.pop_front();
//                    }
//                }
//                if (!q.empty())dp[i][j] = min(dp[i][j], sum[j] + val(q.front()));
//            }
//        }
//        return dp[n][m];
//    }
//};


//#include<bits/stdc++.h>**************这种问题可以用求和符号来推导！！！！！！！！！求和符号简化可以用填格子来思考
//using namespace std;
//const int N = 1e5 + 10;
//const int mod = 1e9 + 7;
//using ll = long long;
//ll sumsum[N];
//ll sum[N];
//int n;
//int st[N];
//int cal(vector<int>& li, int l, int r, int m) {
//    ll lft = sumsum[r - 1], rht = 0;
//    if (m - 1 >= 0) {
//        lft = (lft - sumsum[m - 1] + mod) % mod;
//    }
//    lft = (lft * (m - l)) % mod;
//    rht = 0;
//    if (m - 1 >= 0) {
//        rht = (rht + sumsum[m - 1]) % mod;
//    }
//    if (l - 1 >= 0) {
//        rht = (rht - sumsum[l - 1] + mod) % mod;
//    }
//    rht = (rht * (r - m)) % mod;
//    return (lft - rht + mod) % mod * ll(li[m]) % mod;
//
//}
//class Solution {
//public:
//    int totalStrength(vector<int>& li) {
//        n = li.size();
//        li.insert(li.begin(), 0);
//        for (int i = 1; i <= n; i++) {
//            sum[i] = (sum[i - 1] + li[i]) % mod;
//        }
//        for (int i = 1; i <= n; i++) {
//            sumsum[i] = (sumsum[i - 1] + sum[i]) % mod;
//        }
//        int r = 0;
//        ll ans = 0;
//        for (int i = 1; i <= n; i++) {
//            while (r != 0 && li[st[r - 1]] >= li[i]) {
//                ans = (ans + cal(li, r - 2 >= 0 ? st[r - 2] : 0, i, st[r - 1])) % mod;
//                r--;
//            }
//            st[r++] = i;
//        }
//        while (r != 0) {
//            ans = (ans + cal(li, r - 2 >= 0 ? st[r - 2] : 0, n + 1, st[r - 1])) % mod;
//            r--;
//        }
//        return ans;
//    }
//};



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 10;
//int dp[N];//运输完i-n所有的箱子并最终回到仓库的里程数
//class Solution {
//public:
//    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
//        int n = boxes.size();
//        boxes.insert(boxes.begin(), { 0,0 });
//        for (int i = 1; i <= n; i++) {
//            dp[i] = INT_MAX;
//        }
//        dp[n + 1] = 0;
//        dp[n] = 2;
//        for (int l = n - 1; l >= 1; l--) {
//            int num = 1, weight = boxes[l][1];
//            int diff = 1;
//            dp[l] = dp[l + 1] + 2;
//            for (int j = l + 1; j <= n; j++) {
//                num += 1;
//                weight += boxes[j][1];
//                if (boxes[j][0] != boxes[j - 1][0])diff++;
//                if (num <= maxBoxes && weight <= maxWeight) {
//                    dp[l] = min(dp[l], dp[j + 1] + diff + 1);
//                }
//                else break;
//            }
//        }
//        for (int i = 1; i <= n; i++) {
//            cout << dp[i] << ' ';
//        }cout << '\n';
//        return dp[1];
//    }
//};



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 10;
//int dp[N];//运输完i-n所有的箱子并最终回到仓库的里程数
//class Solution {
//public:
//    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
//        int n = boxes.size();
//        boxes.insert(boxes.begin(), { 0,0 });
//        for (int i = 1; i <= n; i++) {
//            dp[i] = INT_MAX;
//        }
//        dp[n + 1] = 0;
//        dp[n] = 2;
//        int num = 2;//第一趟要花几个历程
//        int weight = boxes[n][1];//第一趟总重
//        int cnt = 1;//第一趟总个数
//        for (int l = n - 1,r=n; l >= 1; l--) {
//            if (boxes[l] != boxes[r]) {
//                num++;
//            }
//            cnt++;
//            weight += boxes[l][1];
//            while (cnt > maxBoxes || weight > maxWeight) {
//                r--;
//                weight -= boxes[r + 1][1];
//                cnt--;
//                if (boxes[r + 1][0] != boxes[r][0]) {
//                    num--;
//                }
//            }
//            dp[l] = dp[r + 1] + num;
//        }
//        return dp[1];
//    }
//};




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 10;
//int dp[N];
//class Solution {
//public:
//    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
//        int n = boxes.size();
//        boxes.insert(boxes.begin(), { 0,0 });
//        for (int i = 0; i <= n; i++) {
//            dp[i] = INT_MAX;
//        }
//        dp[0] = 0;
//        dp[1] = 2;
//        int num = 2;
//        int weight = boxes[1][1];
//        int cnt = 1;
//        for (int r = 2, l = 1; r <= n; r++) {
//            if (boxes[r][0] != boxes[r - 1][0]) {
//                num++;
//            }
//            weight += boxes[r][1];
//            cnt++;
//            while (weight > maxWeight || cnt > maxBoxes || dp[l] <= dp[l - 1]) {//如果是小于等于,由于dp[r]尚未填写,l有可能超过r,全初始化为INT_MAX也可以
//                weight -= boxes[l][1];
//                cnt--;
//                if (boxes[l][0] != boxes[l + 1][0]) {
//                    num--;
//                }
//                l++;
//            }
//            dp[r] = dp[l - 1] + num;
//        }
//        for (int i = 1; i <= n; i++) {
//            cout << dp[i] << ' ';
//        }cout << '\n';
//        return dp[n];
//    }
//};