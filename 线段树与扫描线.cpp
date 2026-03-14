//包含每个查询的最小区间
//#include<bits/stdc++.h>
//using namespace std;
//bool f(pair<int, int>& a, pair<int, int>& b) {
//	return a.first < b.first;
//}
//struct Compare {
//	bool operator()(pair<int, int>& a, pair<int, int>& b) {
//		return a.first > b.first;
//	}
//};
//bool g(vector<int>& a, vector<int>& b) {
//	return a[0] < b[0];
//}
//class Solution {
//public:
//	vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
//		vector<pair<int, int>>que(queries.size());
//		vector<int>ans(queries.size());
//		for (int i = 0; i < queries.size(); i++) {
//			que[i].first = queries[i];
//			que[i].second = i;
//		}
//		sort(que.begin(), que.end(), f);
//		sort(intervals.begin(), intervals.end(), g);
//		priority_queue<pair<int, int>, vector<pair<int, int>>, Compare>pq;
//		for (int i = 0, j = 0; i < que.size(); i++) {
//			while (j < intervals.size() && intervals[j][0] <= que[i].first) {
//				pq.push(make_pair(intervals[j][1] - intervals[j][0] + 1, intervals[j][1]));
//				j++;
//			}
//			while (!pq.empty() && pq.top().second < que[i].first) {
//				pq.pop();
//			}
//			if (!pq.empty()) {
//				ans[que[i].second] = pq.top().first;
//			}
//			else {
//				ans[que[i].second] = -1;
//			}
//		}
//		return ans;
//	}
//};


//天际线
//#include<bits/stdc++.h>
//#define pii pair<int,int>
//using namespace std;
//int rankk(int t, int l, int r, vector<int>& lisan) {
//    int m;
//    int ans = -1;
//    while (l <= r) {
//        m = l + r >> 1;
//        if (lisan[m] >= t) {
//            ans = m;
//            r = m - 1;
//        }
//        else {
//            l = m + 1;
//        }
//    }
//    return ans;
//}
//bool f(vector<int>& a, vector<int>& b) {
//    return a[0] < b[0];
//}
//struct Compare {
//    bool operator()(pii& a, pii& b) {
//        return a.first < b.first;
//    }
//};
//class Solution {
//public:
//    vector<vector<int>> getSkyline(vector<vector<int>>& bui) {
//        sort(bui.begin(), bui.end(), f);
//        vector<int>lisan;
//        for (int i = 0; i < bui.size(); i++) {
//            lisan.push_back(bui[i][0]);
//            lisan.push_back(bui[i][1]);
//            lisan.push_back(bui[i][1] - 1);
//        }
//        sort(lisan.begin(), lisan.end());
//        int len = 0;
//        for (int i = 1; i < lisan.size(); i++) {
//            if (lisan[i] != lisan[len]) {
//                lisan[++len] = lisan[i];
//            }
//        }
//        for (int i=0; i < bui.size(); i++) {
//            bui[i][0] = rankk(bui[i][0], 0, len, lisan);
//            bui[i][1] = rankk(bui[i][1]-1, 0, len, lisan);
//        }
//        priority_queue<pii, vector<pii>, Compare>pq;
//        vector<int>height(len + 1);
//        for (int i = 0, j = 0; i <= len; i++) {
//            while (j < bui.size() && bui[j][0]<= i) {
//                pq.push(make_pair(bui[j][2], bui[j][1]));
//                j++;
//            }
//            while (!pq.empty() && pq.top().second < i) {
//                pq.pop();
//            }
//            if (pq.empty()) {
//                height[i] = 0;
//            }
//            else {
//                height[i] = pq.top().first;
//            }
//        }
//        vector<vector<int>>final;
//        for (int i = 0, pre = 0; i <= len; i++) {
//            if (height[i] != pre) {
//                final.emplace_back(vector<int>{lisan[i], height[i]});
//            }
//            pre = height[i];
//        }
//        return final;
//    }
//};


//矩形面积并
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN = 1e5 + 10;
//vector<int>ysort;
//vector<vector<int>>event;
//vector<int>cover(MAXN << 4);//覆盖长度
//vector<int>cnt(MAXN << 4);//覆盖次数
//vector<int>length(MAXN << 4);
//int len = 0;
//int rnk(int t) {
//	int ans = 0, m;
//	int l = 0, r = len;
//	while (l <= r) {
//		m = l + r >> 1;
//		if (ysort[m] >= t) {
//			ans = m;
//			r = m - 1;
//		}
//		else {
//			l = m + 1;
//		}
//	}
//	return ans + 1;
//}
//void build(int l, int r, int i) {
//	if (l < r) {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//	}
//	cover[i] = 0;
//	cnt[i] = 0;
//	length[i] = ysort[r] - ysort[l - 1];
//	//cout << l << " " << r << " " << i << " " << length[i] << endl;
//}
//void up(int i) {
//	if (cnt[i] > 0) {
//		cover[i] = length[i];
//	}
//	else cover[i] = cover[i << 1] + cover[i << 1 | 1];
//}
//void add(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		cnt[i] += v;
//	}
//	else {
//		int mid = l + r >> 1;
//		if (jl <= mid) {
//			add(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			add(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//	}
//	up(i);
//}
//signed main() {
//	int n;
//	cin >> n;
//	for (int i = 1, x1, y1, x2, y2; i <= n; i++) {
//		cin >> x1 >> y1 >> x2 >> y2;
//		event.push_back(vector<int>{x1, y1, y2, 1});
//		event.push_back(vector<int>{x2, y1, y2, -1});
//		ysort.push_back(y1);
//		ysort.push_back(y2);
//	}
//	sort(ysort.begin(), ysort.end());
//	for (int i = 1; i < ysort.size(); i++) {
//		if (ysort[i] != ysort[len]) {
//			ysort[++len] = ysort[i];
//		}
//	}
//	ysort.push_back(INT_MAX);
//	ysort[len + 1] = ysort[len];
//	sort(event.begin(), event.end(), [](vector<int>& x, vector<int>& y) {
//		if (x[0] != y[0])
//			return x[0] < y[0];
//		else {
//			return x[3] > y[3];
//		}
//		});
//	//for (int i = 0; i <= len + 1; i++)cout << ysort[i] <<" ";
//	//cout << endl;
//	int ans = 0;
//	build(1, len + 1, 1);
//	for (int i = 0, pre = 0; i < event.size(); i++) {
//		//cout << event[i][1] << " " << event[i][2] << " " << event[i][3] << endl;
//		//cout << event[i][0] - pre << " " << cover[1] << endl;
//		//cout << rnk(event[i][1]) << " " << rnk(event[i][2]) << endl;
//		ans += (event[i][0] - pre) * cover[1];
//		add(rnk(event[i][1]), rnk(event[i][2]) - 1, event[i][3], 1, len + 1, 1);
//		pre = event[i][0];
//	}
//	cout << ans << endl;
//}


//矩形周长并
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 10000;
//int xlen = 0;
//int ylen = 0;
//vector<int>ysort;
//vector<int>xsort;
//vector<vector<int>>yevent;
//vector<vector<int>>xevent;
//bool f(vector<int>&a,vector<int>& b) {
//	if (a[0] == b[0])return a[3] > b[3];
//	return a[0] < b[0];
//}
//vector<int>cover(MAXN<<2);
//vector<int>length(MAXN << 2);
//vector<int>cnt(MAXN << 2);
//int rnk(int t, int len, vector<int>& vsort) {
//	int ans = 0;
//	int l = 0, r = len, m;
//	while (l <= r) {
//		m = l + r >> 1;
//		if (vsort[m] >= t) {
//			ans = m;
//			r = m - 1;
//		}
//		else {
//			l = m + 1;
//		}
//	}
//	return ans + 1;
//}
//void up(int i) {
//	if (cnt[i] > 0) {
//		cover[i] = length[i];
//	}
//	else {
//		cover[i] = cover[i << 1] + cover[i << 1|1];
//	}
//}
//void build(int l, int r, int i, vector<int>&vsort) {
//	if (l < r) {
//		int mid = l + r >> 1;
//		build(l, mid, i << 1,vsort);
//		build(mid + 1, r, i << 1 | 1,vsort);
//	}
//	length[i] =vsort[r]-vsort[l-1];
//	cnt[i] = 0;
//	cover[i] = 0;
//}
//void add(int jl, int jr, int v, int l, int r, int i) {
//	if (jl <= l && jr >= r) {
//		cnt[i] += v;
//	}
//	else {
//		int mid = l + r >> 1;
//		if (jl <= mid) {
//			add(jl, jr, v, l, mid, i << 1);
//		}
//		if (jr > mid) {
//			add(jl, jr, v, mid + 1, r, i << 1 | 1);
//		}
//	}
//	up(i);
//}
//int cal(vector<int>vsort,vector<vector<int>>vevent,int len) {
//	build(1, len+1, 1, vsort);
//	int ans = 0;
//	for (int i = 0,pre=0; i < vevent.size(); i++) {
//		add(rnk(vevent[i][1],len,vsort), rnk(vevent[i][2],len,vsort)-1, vevent[i][3], 1, len+1, 1);
//		ans += abs(cover[1] - pre);
//		pre = cover[1];
//	}
//	return ans;
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1, x1, y1, x2, y2; i <= n; i++) {
//		cin >> x1 >> y1 >> x2 >> y2;
//		ysort.push_back(y1);
//		ysort.push_back(y2);
//		xsort.push_back(x1);
//		xsort.push_back(x2);
//		yevent.push_back(vector<int>{x1, y1, y2, 1});
//		xevent.push_back(vector<int>{y1, x1, x2, 1});
//		yevent.push_back(vector<int>{x2, y1, y2, -1});
//		xevent.push_back(vector<int>{y2, x1, x2, -1});
//	}
//	sort(xsort.begin(), xsort.end());
//	sort(ysort.begin(), ysort.end());
//	sort(xevent.begin(), xevent.end(), f);
//	sort(yevent.begin(), yevent.end(), f);
//	for (int i = 1; i < xsort.size(); i++) {
//		if (xsort[i] != xsort[xlen]) {
//			xsort[++xlen] = xsort[i];
//		}
//	}
//	xsort.push_back(INT_MAX);
//	xsort[xlen + 1] = xsort[xlen];
//	for (int i = 1; i < ysort.size(); i++) {
//		if (ysort[i] != ysort[ylen]) {
//			ysort[++ylen] = ysort[i];
//		}
//	}
//	ysort.push_back(INT_MAX);
//	ysort[ylen + 1] = ysort[ylen];
//	int a = cal(xsort,xevent,xlen);
//	int b = cal(ysort,yevent,ylen);
//	cout << a + b << endl;
//}