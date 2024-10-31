#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
struct SegmentTree {
	vector<T> t;
	int n;
	function<T(T, T)> mrg; // Merge function
	T id; // Identity value

	SegmentTree(int size, function<T(T, T)> mergeFunc, T identityValue)
		: n(size), mrg(mergeFunc), id(identityValue) {
		t.assign(4 * n, id);
	}

	SegmentTree(const vector<T>& values, function<T(T, T)> mergeFunc, T identityValue)
		: mrg(mergeFunc), id(identityValue) {
		n = values.size();
		t.assign(4 * n, id);
		build(values, 1, 0, n - 1);
	}

	void build(const vector<T>& values, int node, int start, int end) {
		if (start == end) {
			t[node] = values[start];
			return;
		}
		int mid = (start + end) >> 1;
		int left = node << 1, right = left | 1;
		build(values, left, start, mid);
		build(values, right, mid + 1, end);
		t[node] = mrg(t[left], t[right]);
	}

	void update(int node, int start, int end, int idx, T value) {
		if (start > idx || end < idx) return;
		if (start == end && start == idx) {
			t[node] = value;
			return;
		}
		int mid = (start + end) >> 1;
		int left = node << 1, right = left | 1;
		update(left, start, mid, idx, value);
		update(right, mid + 1, end, idx, value);
		t[node] = mrg(t[left], t[right]);
	}

	T query(int node, int start, int end, int left, int right) {
		if (start > right || end < left) return id;
		if (start >= left && end <= right) return t[node];
		int mid = (start + end) >> 1;
		T l_query = query(node << 1, start, mid, left, right);
		T r_query = query((node << 1) | 1, mid + 1, end, left, right);
		return mrg(l_query, r_query);
	}

	void update(int idx, T value) {
		update(1, 0, n - 1, idx, value);
	}

	T query(int left, int right) {
		return query(1, 0, n - 1, left, right);
	}
};
void tcase() {
	int n;
	cin >> n;
	vector<int>h(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	SegmentTree<int64_t>sg(n + 1, [](int64_t a, int64_t b) {return max(a, b);}, numeric_limits<int64_t>::min());
	vector<int64_t>dp(n);
	for (int i = 0; i < n; ++i) {
		dp[i] = b[i];
		dp[i] = max(dp[i], sg.query(0, h[i] - 1) + b[i]);
		sg.update(h[i], dp[i]);
	}
	int64_t ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}
int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}