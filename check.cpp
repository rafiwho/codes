#include <bits/stdc++.h>
using namespace std;
std::map<char, int> suits;
std::map<char, bool> vis;

void fillValues() {
    std::mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    char ch = 'A';
    for (int i = 0; i < 26; ++i) {
        suits[ch++] = rng() % 11;
    }
}
#include "test.h"
void tcase() {	
  fillValues();
  debug(suits);
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 1;
   //cin >> t;

   while (t-- > 0)
     tcase();
}