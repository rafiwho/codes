#include "bits/stdc++.h"
using namespace std;


const int maxx = 110;
const int  inf = 1e9;

void tcase() {
	int n;
	cin >> n;
	std::vector<int> v[maxx];
	vector<vector<int>>dis(maxx , vector<int>(maxx));

	for (int i = 1; i < maxx; ++i) {
		for (int j = 1; j < maxx; ++j) {
			if (i == j)
				dis[i][j] = 0;
			else
				dis[i][j] = inf;
		}
	}

	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = 1; j <= y; j++) {
			int nn;
			cin >> nn;
			v[x].emplace_back(nn);
			dis[x][nn] = 1;
		}
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << i << ' ' << ( dis[1][i] == inf ? -1 : dis[1][i]) << '\n';
	}

}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
