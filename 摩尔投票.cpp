//多数元素
//#include<bits/stdc++.h>
//using namespace std;
//class Solution {
//public:
//    int majorityElement(vector<int>& nums) {
//        int t;
//        int cnt = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            if (cnt == 0) {
//                t = nums[i];
//                cnt++;
//            }
//            else if (nums[i] != t) {
//                cnt--;
//            }
//            else {
//                cnt++;
//            }
//        }
//        return t;
//    }
//};


//合法分割的最小下标
//#include<bits/stdc++.h>
//using namespace std;
//class Solution {
//public:
//    int minimumIndex(vector<int>& nums) {
//        int t;
//        int cnt = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            if (cnt == 0) {
//                t = nums[i];
//                cnt++;
//            }
//            else if (nums[i] != t) {
//                cnt--;
//            }
//            else cnt++;
//        }
//        cnt = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] == t) {
//                cnt++;
//            }
//        }
//        int c = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] == t) {
//                c++;
//            }
//            if (c > (i + 1) / 2 && cnt - c > (nums.size() - i - 1) / 2) {
//                return i;
//            }
//        }
//        return -1;
//    }
//};


//多数元素II
//#include<bits/stdc++.h>
//#define pii pair<int,int>
//using namespace std;
//void f(vector<pii>& table, int a) {
//    for (int i = 0; i < table.size(); i++) {
//        if (table[i].second != 0 && table[i].first == a) { table[i].second++; return; }
//    }
//    for (int i = 0; i < table.size(); i++) {
//        if (table[i].second == 0) {
//            table[i].first = a;
//            table[i].second++;
//            return;
//        }
//    }
//    for (int i = 0; i < table.size(); i++) {
//        table[i].second--;
//    }
//}
//bool check(int a, vector<int>& nums, int k) {
//    int cnt = 0;
//    for (int i : nums) {
//        if (i == a) {
//            cnt++;
//        }
//    }
//    return cnt > nums.size() / k;
//}
//vector<int> findWaterKing(vector<int>& nums, int k) {
//    vector<pii>table(k - 1, make_pair(0, 0));
//    for (int i = 0; i < nums.size(); i++) {
//        f(table, nums[i]);
//    }
//    vector<int>ans;
//    for (int i = 0; i < table.size(); i++) {
//        if (table[i].second != 0 && check(table[i].first, nums, k)) {
//            ans.push_back(table[i].first);
//        }
//    }
//    return ans;
//}
//
//class Solution {
//public:
//    vector<int> majorityElement(vector<int>& nums) {
//        return findWaterKing(nums, 3);
//    }
//};


//线段树里捉海王
//#include<bits/stdc++.h>
//#define pii pair<int,int>
//using namespace std;
//const int MAXN = 2 * 1e4+10;
//vector<int>cand(MAXN<<2);
//vector<int>hp(MAXN << 2);
//int n;
//void up(int i) {
//    int clson = cand[i << 1], hpl = hp[i << 1];
//    int crson = cand[i << 1 | 1], hpr = hp[i << 1 | 1];
//    if (clson == crson) {
//        cand[i] = clson;
//        hp[i] = hp[i << 1] + hp[i << 1 | 1];
//    }
//    else {
//        cand[i] = hpl >= hpr ? clson : crson;
//        hp[i] = abs(hpl - hpr);
//    }
//}
//void build(int l, int r, int i, vector<int>& arr) {
//    if (l == r) {
//        cand[i] = arr[l - 1];
//        hp[i] = 1;
//    }
//    else {
//        int mid = l + r >> 1;
//        build(l, mid, i << 1, arr);
//        build(mid + 1, r, i << 1 | 1,arr);
//        up(i);
//    }
//}
//struct info {
//    int cand, hp;
//    info(int cand, int hp) {
//        this->cand = cand;
//        this->hp = hp;
//    }
//};
//info queryW(int jl,int jr,int l,int r,int i) {
//    if (jl <= l && jr >= r) {
//        return info(cand[i], hp[i]);
//    }
//    int mid = l + r >> 1;
//    if (jl > mid) {
//        return queryW(jl, jr, mid + 1, r, i << 1 | 1);
//    }
//    if (jr <= mid) {
//        return queryW(jl, jr, l, mid, i << 1);
//    }
//    info lson = queryW(jl, jr, l, mid, i << 1);
//    info rson = queryW(jl, jr, mid+1, r, i << 1|1);
//    int c, h;
//    if (lson.cand == rson.cand) {
//        c = lson.cand;
//        h = lson.hp + rson.hp;
//    }
//    else {
//        c = lson.hp >= rson.hp ? lson.cand : rson.cand;
//        h = abs(lson.hp- rson.hp);
//    }
//    return info(c, h);
//}
//vector<pii>asort;
//int bs(int t, int x) {
//    int l = 0, r = asort.size() - 1, m;
//    int ans = -1;
//    while (l <= r) {
//        m = l + r >> 1;
//        if (asort[m].first < t || asort[m].first == t && asort[m].second <= x) {
//            ans = m;
//            l = m + 1;
//        }
//        else {
//            r = m - 1;
//        }
//    }
//    return ans+1;
//}
//int cnt(int l,int r,int x) {
//    return bs(x, r) - bs(x, l - 1);
//}
//class MajorityChecker {
//public:
//    MajorityChecker(vector<int>& arr) {
//        build(1, arr.size(), 1, arr);
//        for (int i = 0; i < arr.size(); i++) {
//            asort.push_back(make_pair(arr[i], i));
//        }
//        asort.clear();
//        sort(asort.begin(), asort.end(), [](pii&a,pii&b) {
//            if (a.first == b.first)return a.second < b.second;
//            return a.first < b.first;
//        });
//        n = arr.size();
//    }
//
//    int query(int left, int right, int threshold) {
//        int cand= queryW(left+1, right+1, 1, n, 1).cand;
//        if (cnt(left, right, cand) >= threshold)return cand;
//        return -1;
//    }
//};