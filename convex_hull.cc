#include <bits/stdc++.h>
using namespace std;
using dist_t = long double;

struct Point {
	int64_t x = 0, y = 0;

	Point(int64_t _x = 0, int64_t _y = 0) : x(_x), y(_y) {}

	Point& operator += (const Point& other) { x += other.x; y += other.y; return *this; }
	Point& operator -= (const Point& other) { x -= other.x; y -= other.y; return *this; }

	Point operator + (const Point& other) const { return Point(*this) += other; }
	Point operator - (const Point& other) const { return Point(*this) -= other; }
	Point operator * (int64_t mult) const { return {x * mult, y * mult}; }
	Point operator - () const { return { -x, -y}; }
	bool operator == (const Point& other) const { return x == other.x && y == other.y; }
	bool operator != (const Point& other) const { return !(*this == other); }
	bool operator <(const Point& b)const { return make_pair(x, y) < make_pair(b.x, b.y); }

	Point rotate90() const { return { -y, x}; }
	dist_t dist(const Point& b) const { return hypotl(x - b.x, y - b.y); }
	int64_t cross(const Point& b) const { return x * b.y - y * b.x; }
	int64_t triangle(const Point& a, const Point& b) const { return (a - *this).cross(b - *this); }

	friend ostream &operator << (ostream& os, const Point& p) { return os << p.x << " " << p.y; }
	friend istream &operator >> (istream& is, Point& p) { return is >> p.x >> p.y; }
};

void tcase() {
	int n; cin >> n;
	vector<Point> points(n);
	for (int i = 0; i < n; ++i) {
		cin >> points[i];
	}
	sort(points.begin(), points.end());
	vector<Point> hull;
	for (int rep = 0; rep < 2; ++rep) {
		const int S = hull.size();
		for (Point C : points) {
			while ((int)hull.size() >= S + 2) {
				Point A = hull.end()[-2];
				Point B = hull.end()[-1];
				if (A.triangle(B, C) <= 0) { // including colinear
					//good
					break;
				}
				hull.pop_back();
			}
			hull.push_back(C);
		}
		hull.pop_back(); // remove right most point
		reverse(points.begin(), points.end());
	}
	cout << (int) hull.size() << '\n';
	for (auto x : hull)
		cout << x << '\n';
}
int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}