//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//struct Point {
//	int x, y;
//};
//struct Circle {
//	Point c;
//	int r;
//};
//int dist(Point a,Point b) {
//	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
//}
//signed main() {
//	int n;
//	cin >> n;
//	vector<Circle>a(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i].c.x;
//	}
//	for (int i = 0; i < n; i++) {
//		cin >> a[i].c.y;
//	}
//	for (int i = 0; i < n; i++) {
//		cin >> a[i].r;
//	}
//	Point p1, p2;
//	cin >> p1.x >> p1.y >> p2.x >> p2.y;
//	int ans = 0;
//	vector<bool>in1(n,false);
//	vector<bool>in2(n,false);
//	for (int i = 0; i < n; i++) {
//		if (dist(p1, a[i].c) < a[i].r * a[i].r) {
//			in1[i] = true;
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		if (dist(p2, a[i].c) < a[i].r * a[i].r) {
//			in2[i] = true;
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		if (in1[i] ^ in2[i]) {
//			ans++;
//		}
//	}
//	cout << ans << '\n';
//}


//#include<bits/stdc++.h>
//using namespace std;
//struct Point {
//	int x, y;
//	Point(Point a,Point b) {
//		x = b.x - a.x;
//		y = b.y - a.y;
//	}
//	Point() {
//		x = 0, y = 0;
//	}
//};
//int toleft(Point a,Point line) {
//	int t=a.x* line.y - a.y * line.x;
//	if (t > 0)return 1;
//	if (t == 0)return 0;
//	if (t < 0)return -1;
//}
//array<int, 2> reads(string s) {
//	int i = 1;
//	int x = 0;
//	while (s[i] != ',') {
//		x = x * 10 + s[i] - '0';
//		i++;
//	}
//	i++;
//	int y = 0;
//	while (s[i] != ')') {
//		y = y * 10 + s[i] - '0';
//		i++;
//	}
//	return { x,y };
//}
//int main() {
//	vector<Point>t(3);
//	string s;
//	for (int i = 0; i < 3; i++) {
//		cin >> s;
//		auto tmp = reads(s);
//		t[i].x = tmp[0];
//		t[i].y = tmp[1];
//	}
//	Point p;
//	cin >> s;
//	auto tmp = reads(s);
//	p.x = tmp[0];
//	p.y = tmp[1];
//	bool same = 0;
//	vector<int>tl(3);
//	for (int i = 0; i < 3; i++) {
//		if (p.x == t[i].x && p.y == t[i].y) {
//			cout << 4 << '\n';
//			return 0;
//		}
//	}
//	//由于三角型必是凸多边形,可以用toleft测试
//	for (int i = 0; i < 3; i++) {
//		tl[i] = toleft(Point(t[i], p), Point(t[(i + 1) % 3], t[i]));
//		if ( tl[i] == 0) {
//			if (p.x >= min(t[i].x, t[(i + 1) % 3].x) && p.x <= max(t[i].x, t[(i + 1) % 3].x)&&p.y>= min(t[i].y, t[(i + 1) % 3].y)&&p.y<= max(t[i].y, t[(i + 1) % 3].y)) {//一定要两维都比,防止直线垂直的特殊情况
//				cout << 3 << '\n';
//				return 0;
//			}
//		}
//	}
//	if ((tl[0] <= 0 && tl[1] <= 0 && tl[2] <= 0) || (tl[0] >= 0 && tl[1] >= 0 && tl[2] >= 0)) {
//		cout << 1 << '\n';
//	}
//	else {
//		cout << 2 << '\n';
//	}
//}


//#include<bits/stdc++.h>
//#define double long double
//using namespace std;
//struct Point {
//	double x, y;
//};
//int main() {
//	int n;
//	double d;
//	cin >> n >> d;
//	vector<Point>island(n);
//	for (int i = 0; i < n; i++) {
//		cin >> island[i].x >> island[i].y;
//	}
//	for (int i = 0; i < n; i++) {
//		if (island[i].y > d) {
//			cout << -1 << '\n';
//			return 0;
//		}
//	}
//	vector<array<double, 2>>seg;
//	for (int i = 0; i < n; i++) {
//		double dx = sqrt(d * d - island[i].y * island[i].y);
//		seg.push_back({island[i].x - dx, island[i].x + dx});
//	}
//	sort(seg.begin(), seg.end(), [&](auto x,auto y) {
//		return x[1] < y[1];
//	});
//	int ans = 0;
//	double r;
//	for (int i = 0; i < seg.size();) {
//		ans++;
//		r = seg[i][1];
//		while (i<seg.size()&&seg[i][0] <= r) {
//			i++;
//		}
//	}
//	cout << ans << '\n';
//}



//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//struct Point {
//	int x, y;
//	Point() {
//		x = 0;
//		y = 0;
//	}
//	Point(Point a, Point b) {
//		x = b.x - a.x;
//		y = b.y - a.y;
//	}
//};
//int cross(Point x, Point y) {
//	return x.x * y.y - x.y * y.x;
//}
//void solve() {
//	int n;
//	cin >> n;
//	vector<Point>a(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i].x >> a[i].y;
//	}
//	vector<pair<Point,bool>>nail;
//	int tot=0;
//	for (int i = 0; i < n; i++) {
//		int cx = cross(Point(a[i], a[(i + 1) % n]), Point(a[(i + 1) % n], a[(i + 2)%n]));
//		tot += cross(a[i], a[(i + 1)%n]);
//		if (cx > 0) {
//			nail.push_back({ a[(i + 1) % n], 1 });
//		}
//		else if (cx < 0) {
//			nail.push_back({ a[(i + 1)%n],0 });
//		}
//	}
//	if (tot < 0) {
//		for (int i = 0; i < nail.size(); i++) {
//			nail[i].second = !nail[i].second;
//		}
//	}
//	cout << nail.size() << '\n';
//	sort(nail.begin(), nail.end(), [&](auto a,auto b) {
//		if (a.first.x == b.first.x)return a.first.y < b.first.y;
//		return a.first.x < b.first.x;
//		});
//	for (int i = 0; i < nail.size(); i++) {
//		cout << nail[i].first.x << " " << nail[i].first.y << " " << (nail[i].second?"YES":"NO") << '\n';
//	}
//}
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		solve();
//	}
//}