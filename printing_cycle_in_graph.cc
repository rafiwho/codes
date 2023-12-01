#include <iostream>
#include <vector>
using namespace std;
template<typename T>
void output_vector(const vector<T> &v, bool add_one = false) {
	int start = 0 , end = int(v.size());

	for (int i = start; i < end; i++)
		cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}
void tcase() {
	int n, m;
	cin >> n >> m;
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