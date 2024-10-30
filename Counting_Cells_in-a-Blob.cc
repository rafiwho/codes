#include "bits/stdc++.h"
using namespace std;
#define pb push_back
////////////////////
std::vector<string> v;

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

bool is_valid(int i , int j) {
	return i >= 0 && i < int(v.size()) && j >= 0 && j < int(v[0].size());
}

int cnt = 0;
void dfs(int i , int j) {
	if (v[i][j] == '0')
		return ;
	v[i][j] = '0';
	cnt++;

	for (int k = 0; k < 8; ++k) {
		int aa = i + dx[k];
		int bb = j + dy[k];
		if (is_valid(aa , bb)) {
			dfs(aa , bb );
		}
	}
}

void tcase() {

	string s;
	while (getline(cin , s) && int(s.size())) {
		v.pb(s);
	}

	int ans = 0;
	for (int i = 0; i < int(v.size()); ++i) {
		for (int j = 0; j < int(v[0].size()); ++j) {
			if (v[i][j] == '1') {
				dfs(i, j);
				ans = max(ans , cnt);
				cnt = 0;
			}
		}
	}

	cout << ans << '\n';
	v.clear();

}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int t = 1;
	cin >> t;
	cin.ignore();
	cin.ignore();

	bool xxx = false;

	while (t-- > 0) {
		if (xxx) {
			cout << '\n';
		}
		tcase();
		xxx = true;
	}
}