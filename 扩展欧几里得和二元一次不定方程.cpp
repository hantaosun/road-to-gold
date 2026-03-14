//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int d, x, y, px, py;
//void exgcd(int a, int b) {
//	if (b == 0) {
//		d = a;
//		x = 1;
//		y = 0;
//	}
//	else {
//		exgcd(b, a % b);
//		px = x;
//		py = y;
//		x = py;
//		y = px - py* (a / b);
//	}
//}
//void solve() {
//	int a, b, c;
//	cin >> a >> b >> c;
//	exgcd(a, b);
//	if (c % d != 0) {
//		cout << -1 << endl;
//		return;
//	}
//	x *= c / d;
//	y *= c / d;
//	int ix = b/d;
//	int iy = a/d;
//	if (x < 0) {
//		int t = (1 - x + ix - 1) / ix;
//		x += t * ix;
//		y -= t * iy;
//	}
//	else {
//		int t = (x - 1) / ix;
//		x -= t * ix;
//		y += t * iy;
//	}
//	if (y <= 0) {
//		cout << x<<" ";
//		cout << y+(1 - y + iy - 1) / iy * iy << endl;
//	}
//	else {
//		cout << (y - 1) / iy+1<<" ";
//		cout << x << " ";
//		cout << y - (y - 1) / iy * iy << " ";
//		cout << x + (y - 1) / iy * ix << " ";
//		cout << y << endl;
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
//#define int long long
//using namespace std;
//int d, x, y, px, py;
//void exgcd(int a, int b) {
//	if (b == 0) {
//		d = a;
//		x = 1;
//		y = 0;
//	}
//	else {
//		exgcd(b, a % b);
//		px = x;
//		py = y;
//		x = py;
//		y = px - py * (a/b);
//	}
//}
//signed main() {
//	int x1, y1, m, n, L;
//	cin >> x1 >> y1 >> m >> n >> L;
//	if (x1 > y1) {
//		swap(x1, y1);
//		swap(m, n);
//	}
//	int a, b, c;
//	if (m > n) {
//		a = m - n;
//		b = L;
//		c = y1 - x1;
//	}
//	else {
//		a = n - m;
//		b = L;
//		c = L - y1 + x1;
//	}
//	exgcd(a,b);
//	if (c % d != 0) {
//		cout << "Impossible\n";
//		return 0;
//	}
//	x = x * c / d;
//	int dx = b / d;
//	if (x < 0) {
//		x += (1 - x + dx - 1)/dx * dx;
//	}
//	else {
//		x -= (x - 1) / dx * dx;
//	}
//	cout << x << '\n';
//}


//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//signed main() {
//	int a, b;
//	cin >> a >> b;
//	cout << a * b - a - b << endl;
//}


//#include<iostream>
//#include<iomanip>
//#define int long long
//using namespace std;
//int gcd(int a, int b) {
//	while (b != 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//void solve(int id) {
//	int m;
//	cin >> m;
//	double area = 0;
//	int p = 0;
//	int x = 0, y = 0;
//	for (int i = 1, dx, dy; i <= m; i++) {
//		cin >> dx >> dy;
//		area += x * (y + dy) - y * (x + dx);
//		p += gcd(abs(dx), abs(dy));
//		y += dy;
//		x += dx;
//	}
//	area /= 2;
//	int innerP = area - p / 2 + 1;
//	cout << "cenario #" << id << ":\n";
//	cout << innerP << " " << p << " " << fixed << setprecision(1) << area << endl;
//}
//signed main() {
//	int t;
//	cin >> t;
//	for (int i = 1; i <= t; i++) {
//		solve(i);
//	}
//}