#include "bits/stdc++.h"
using namespace std;

const int N = 1e6;
std::vector<int64_t> bit(N + 1, 0);

int64_t sum(int indx) {
	int64_t sum = 0;
	for (; indx > 0 ; indx -= (indx & -indx))
		sum += bit[indx];
	return sum;
}

void update(int indx , int value) {
	for (; indx < N; indx += (indx & -indx)	)
		bit[indx] += value;
}

void tcase() {

	int64_t n;
	cin >> n;

	vector<int64_t>v(n + 1);
	std::map<int64_t, int32_t> mp;

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		mp[v[i]];
	}

	int ptr = 1;
	for (auto&A : mp)
		A.second = ptr++;


	for (int i = 1; i <= n; ++i) {
		v[i] = mp[v[i]];
	}

	int64_t inv_cnt = 0;

	for (int i = 1; i <= n; ++i) {
		inv_cnt += (sum(N - 5) - sum(v[i]));
		update(v[i], 1);
	}

	cout << inv_cnt << '\n';
	for (int i = 1; i <= N; ++i)
		bit[i] = 0;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;

	while (t-- > 0)
		tcase();
}