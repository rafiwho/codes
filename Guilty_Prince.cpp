#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

#define pb push_back
#define in insert
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()

const int N = 30;
int n , m , cnt = 0;;

vector<vector<bool>>dp(N, vector<bool>(N, false));
std::vector<string> v(N, string(N, ' '));

bool is_valid(int i , int j) {
	return i >= 0 && i < m && j >= 0 && j < n && v[i][j] != '#' && !dp[i][j];
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int i , int j) {

	dp[i][j] = true;
	cnt++;
	for (int m = 0; m < 4; ++m) {
		int aa = i + dx[m];
		int bb = j + dy[m];

		if (is_valid(aa , bb)) {
			dfs(aa, bb);
		}
	}
}

void tcase() {
	cin >> n >> m;

	pair<int, int> posi = {0, 0};

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
			if (v[i][j] == '@')
				posi = {i, j};
		}
	}

	dfs(posi.ff , posi.ss);

	cout << cnt << '\n';

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			dp[i][j] = false;
		}
	}
	cnt = 0;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;

	int xx = 1;
	while (t-- > 0) {
		cout << "Case " << xx++ << ": ";
		tcase();
	}
}