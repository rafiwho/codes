#include "bits/stdc++.h"
using namespace std;
#define pb push_back
std::vector<string> v;

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

bool is_valid(int i , int j) {
	return i >= 0 && i < int(v.size()) && j >= 0 && j < int(v[0].size());
}

void dfs(int i , int j) {
	if (v[i][j] == '0')
		return ;
	v[i][j] = '0';

	for (int k = 0; k < 8; ++k) {
		int aa = i + dx[k];
		int bb = j + dy[k];
		if (is_valid(aa , bb)) {
			dfs(aa , bb );
		}
	}
}
int xx = 1;

void tcase() {

	int n;
	while (cin >> n) {
		string s;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			v.pb(s);
		}
		int ans = 0;
		for (int i = 0; i < int(v.size()); ++i) {
			for (int j = 0; j < int(v[0].size()); ++j) {
				if (v[i][j] == '1') {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << "Image number " << xx++ << " contains " << ans << " war eagles.\n";
		v.clear();
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int t = 1;
	// cin >> t;
	bool xxx = false;

	while (t-- > 0) {
		if (xxx) {
			cout << '\n';
		}
		tcase();
		xxx = true;
	}
}