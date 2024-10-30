
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto &[wt, val] : v) {
		cin >> wt >> val;
		val /= wt; // pair er second value te 1 kg er val store kortesi
	}
	sort(v.begin(), v.end(), [](auto a, auto b)->bool{
		return a.second > b.second; // eta dile pair er second value decending onujayi sort hobe
	});

	int capacity;
	cin >> capacity; // mot capacity
	float tot = 0;
	int cur_cap = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i].first + cur_cap < capacity) { // check kortesi current capacity + cur item er weight
			// mot capacity er kom kinaa
			//kom hole oita tot value te add hosse r cur_cap(occupyied) bartese
			tot += v[i].second;
			cur_cap += v[i].first;
		} else {
			int frac = (capacity - cur_cap); // r full item newar moto jaiga faka nai
			tot += frac * (v[i].second);     // so frac e baki koto tuku nite parbo dhektesi then tar sathe ration gun korte frac weight er value pabo then breeak
			break;
		}
	}
	cout << tot << '\n'; // total eto takar item nite parbo
	return 0;
}
