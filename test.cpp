#include <bits/stdc++.h>
using namespace std;
bool f = false;
int n, m;
vector<int>subset;
void subset_gen(int index, int n, vector<int>&v) {
  if (index == n) {
    if (subset.size() > 0) {
      int total = accumulate(subset.begin(), subset.end(), 0);
      if (total % m == 0) {
        f = true;
        return;
      }
    }
  } else {
    subset_gen(index + 1, n, v);
    subset.push_back(v[index]);
    subset_gen(index + 1, n, v);
    subset.pop_back();
  }
}
void solve() {
  cin >> n >> m;
  vector<int>v(n);
  for (auto &x : v) {
    cin >> x;
  }
  if (n > m) {
    cout << "Yes\n";
    return;
  }
  subset_gen(0, n, v);
  if (f) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc = 1;
  // cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}