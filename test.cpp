#include <bits/stdc++.h>
using namespace std;

void tcase() {
	string s; cin >> s;
	s.back() = '4';
	cout << s << '\n';
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 1;
   //cin >> t;

   while (t-- > 0)
     tcase();
}