#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1025;
int v[N][N];
void tcase() {
	int d, n; cin >> d >> n;
	int x, y, size;
	int i, j, xl, xr, yl, yr;
	while (n--) {
		cin >> x >> y >> size;
		xl = max(0, x - d), xr = min(x + d, 1024);
		yl = max(0, y - d), yr = min(y + d, 1024);

		for (i = xl; i <= xr; i++)
			for (j = yl; j <= yr; j++)
				v[i][j] += size;
	}
	int mx = -1, rx, ry;
	for (i = 0; i < 1025; i++)
		for (j = 0; j < 1025; j++)
			if (v[i][j] > mx)
				mx = v[i][j], rx = i, ry = j;
	cout << rx << ' ' << ry << ' ' << mx << '\n';
	memset(v, 0, sizeof(v));
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;

	while (t-- > 0)
		tcase();
}