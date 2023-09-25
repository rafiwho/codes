#include <iostream>
#include<vector>
using namespace std;
vector<int>v = {5, 4, 3, 2, 1, 6, 3, 6, 7, 8, 12};
int partition(int l, int r) {
	int pivot  = v[l];
	int i = l;
	int j = r;
	while (i < j) {
		while (v[i] <= pivot) {
			i++;
		}
		while (v[j] > pivot) {
			j--;
		}
		if (i < j)
			swap(v[i], v[j]);
	}
	swap(v[j], v[l]);
	return j;
}
void quick_sort(int l, int r) {
	if (l < r) {
		int par = partition(l, r);
		quick_sort(l, par - 1);
		quick_sort(par + 1, r);
	}
}
void tcase() {
	quick_sort(0, int(v.size()) - 1);
	for (auto a : v)
		cout << a << ' ';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}