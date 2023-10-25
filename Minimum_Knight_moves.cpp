#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9 + 10;
bool vis[8][8];
int level[8][8];
int getX(string s) {
	return s[0] - 'a';
}
int getY(string s) {
	return s[1] - '1';
}
vector<pair<int, int>>movs = {
	{ -1, 2}, {1, 2},
	{ -1, -2}, {1, -2},
	{2, -1}, {2, 1},
	{ -2, -1}, { -2, 1},
};
bool val(int x, int y) {
	return x >= 0 && y >= 0 && x < 8 && y < 8;
}
void reset() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			vis[i][j] = false;
			level[i][j] = INF;
		}
	}
}
int bfs(string &source, string &des) {
	int src_x = getX(source);
	int src_y = getY(source);
	int des_x = getX(des);
	int des_y = getY(des);
	queue<pair<int, int>>q;
	q.push({src_x, src_y});
	vis[src_x][src_y] = true;
	level[src_x][src_y] = 0;
	while (!q.empty()) {
		auto [par_x, par_y] = q.front();
		q.pop();
		for (auto [xx, yy] : movs) {
			int child_x = par_x + xx;
			int child_y = par_y + yy;
			if (!val(child_x, child_y))continue;
			if (!vis[child_x][child_y]) {
				q.push({child_x, child_y});
				level[child_x][child_y] = level[par_x][par_y] + 1;
				vis[child_x][child_y] = true;
			}
		}
		if (level[des_x][des_y] != INF)
			break;
	}
	return level[des_x][des_y];
}
void tcase() {
	string s1, s2; cin >> s1 >> s2;
	cout << bfs(s1, s2) << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;

	while (t-- > 0) {
		reset();
		tcase();
	}
}