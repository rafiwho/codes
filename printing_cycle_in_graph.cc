#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

#define pb push_back
#define in insert
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
	if (start < 0) start = 0;
	if (end < 0) end = int(v.size());

	for (int i = start; i < end; i++)
		cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
void tcase() {
	int n;
	cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	int pos = 1;
	for (int i = 0; i < 2 * n; ++i) {
		pos = v[pos];
	}
	vector<int>ans;
	ans.emplace_back(pos);
	while (true) {
		pos = v[pos];
		if (pos == ans[0])
			break;
		else
			ans.emplace_back(pos);
	}

	cout << int(ans.size()) << '\n';
	output_vector(ans);
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}