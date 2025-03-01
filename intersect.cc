#include <bits/stdc++.h>
using namespace std;
using dist_t = long double;

struct P {
	int64_t x = 0, y = 0;

	P(int64_t _x = 0, int64_t _y = 0) : x(_x), y(_y) {}

	P& operator += (const P &other) { x += other.x; y += other.y; return *this; }
	P& operator -= (const P &other) { x -= other.x; y -= other.y; return *this; }

	P operator + (const P &other) const { return P(*this) += other; }
	P operator - (const P &other) const { return P(*this) -= other; }
	P operator * (int64_t mult) const { return {x * mult, y * mult}; }
	P operator - () const { return { -x, -y}; }
	bool operator == (const P &other) const { return x == other.x && y == other.y; }
	bool operator != (const P &other) const { return !(*this == other); }

	P rotate90() const { return { -y, x}; }
	dist_t dist(const P &b) const { return hypotl(x - b.x, y - b.y); }
	int64_t cross(const P &b) const { return x * b.y - y * b.x; }
	int64_t triangle(P& a, P& b) { return (a - *this).cross(b - *this);}

	friend ostream &operator << (ostream &os, const P &p) { return os << p.x << " " << p.y; }
	friend istream &operator >> (istream &is, P &p) { return is >> p.x >> p.y; }
};
bool intersect(P a, P b, P c, P d) {
	if ((b - a).cross(d - c) == 0) {
		if (a.triangle(b, c) != 0) {
			// not colinear
			return false;
		}
		for (int rep = 0; rep < 2; ++rep) {
			// maybe linear
			if ((max(a.x, b.x) < min(c.x, d.x)) || (max(a.y, b.y) < min(c.y, d.y))) {
				return false;
			}
			swap(a, c);
			swap(b, d);
		}
		return true;
	}
	for (int rep = 0; rep < 2; ++rep) {
		int64_t sign1 = (b - a).cross(c - a);
		int64_t sign2 = (b - a).cross(d - a);
		if ((sign1 > 0 && sign2 > 0) || (sign1 < 0 && sign2 < 0)) {
			return false;
		}
		swap(a, c);
		swap(b, d);
	}
	return true;
}
bool segment_contains(P a, P b, P c) {
	if (a.triangle(b, c) != 0) return false;
	return (min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x)) &&
	       min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}