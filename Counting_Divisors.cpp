#include <bits/stdc++.h>
using namespace std;

//cses
const int N = 1e6 + 9;

vector<int>divi(N, 1);
void store() {
	for (auto i = 2; i < N; ++i) {
		for (auto j = i; j < N; j += i) {
			divi[j]++;
		}
	}
}
void tcase() {
	int n;
	cin >> n;
	cout << divi[n] << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	store();
	int t = 1;
	cin >> t;

	while (t-- > 0)
		tcase();
}