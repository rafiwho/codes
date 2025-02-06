#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1E7;
vector<int>spf(N);
void cal() {
  for (int i = 1; i < N; ++i) {
    spf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (spf[i] == i) {
      for (int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}
void tcase() {
}
int32_t main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int32_t t = 1;
  //cin >> t;

  while (t-- > 0)
    tcase();
}