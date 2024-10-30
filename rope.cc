#include <bits/stdc++.h>
using namespace std;

double dist (double x1, double y1, double x2, double y2) {
	double d1 = x2 - x1;
	double d2 = y2 - y1;
	return sqrt((d1 * d1) + (d2 * d2));
}
void tcase() {
	double n, r;
	cin >> n >> r;
	vector<array<double, 2>>v(n);
	for (auto &a : v)
		cin >> a[0] >> a[1];
	double len = 0;
	for (int i = 1; i < n; ++i) {
		len += dist(v[i][0], v[i][1], v[i - 1][0], v[i - 1][1]);
	}
	len += dist(v[0][0], v[0][1], v[n - 1][0], v[n - 1][1]);
	len += 2.0 * acos(-1.0) * r;
	cout << fixed << setprecision(5) << len << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}