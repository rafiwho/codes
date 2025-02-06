#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5;
int timer = 1, n, m;

vector<array<int, 2>>v[N];
vector<int>in(N), low(N);
vector<bool> vis(N);
vector<array<int, 2>>edges;
std::map<array<int, 2>, bool> vis_edges;

void dfs(int ver, int par) {
  vis[ver] = true;
  in[ver] = low[ver] = timer++;
  for (auto [nei, i] : v[ver]) {
    if (nei == par) continue;

    if (vis[nei] == 0) {
      if (!vis_edges.contains({ver, nei})) {
        vis_edges[ {ver, nei}] = true;
        edges.push_back({ver, nei});
      }
      dfs(nei, ver);
      low[ver] = min(low[nei], low[ver]);
      if (low[nei] > in[ver]) {
        cout << 0 << '\n';
        exit(0);
      }
    } else {
      if (!vis_edges.contains({nei, ver})) {
        vis_edges[ {ver, nei}] = true;
        edges.push_back({ver, nei});
      }
      low[ver] = min(low[nei], low[ver]);
    }
  }
}

void tcase() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y;
    v[x].push_back({y, i});
    v[y].push_back({x, i});
  }
  dfs(1, -1);
  for (auto [x, y] : edges) {
    cout << x << ' ' << y << '\n';
  }
}
int32_t main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int32_t t = 1;
  //cin >> t;

  while (t-- > 0)
    tcase();
}