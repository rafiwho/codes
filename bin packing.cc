#include <bits/stdc++.h>
using namespace std;
int firstFitBinPacking(int items[], int n, int binCapacity) {
	int bin[n];
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int j;
		for (j = 0; j < cnt; ++j) {
			if (bin[j] >= items[i]) {
				bin[j] -= items[i];
				break;
			}
		}
		if (j == cnt)
			bin[cnt++] = binCapacity - items[i];
	}
	return cnt;
}
void tcase() {

	int items[] = {4, 8, 1, 4, 2, 1, 8, 5, 7};
	int n = sizeof(items) / sizeof(items[0]);
	int binCapacity = 10;
	int binsUsed = firstFitBinPacking(items, n, binCapacity);
	cout << binsUsed << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}