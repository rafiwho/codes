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

int n , m;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

bool is_valid (int i , int j) {
	return i >= 0 && i < m && j >= 0 && j < n;
}

void f(int i, int j , vector<string>&v) {

	v[i][j] = '*';

	for (int l = 0; l < 8; ++l) {
		int a = i + dx[l];
		int b = j + dy[l];
		if (is_valid(a, b) && v[a][b] != '*') {
			f(a, b, v);
		}
	}

}
void tcase() {
	while (cin >> m >> n && m) {

		std::vector<string> v(m, string(n, ' '));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> v[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (v[i][j] == '*')
					continue;
				else {
					f(i, j, v);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';

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