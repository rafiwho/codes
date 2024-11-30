#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

void tcase() {

	const int mx_input_output = 10;
	for (auto i = 1LL; i <= mx_input_output ; ++i) {

		// fun is the sol of a given prob
		auto fun = [&](int x, int y) {

			ofstream myfle(to_string(i) + ".in"); // input1....100.txt

			// myfle << x << " " << y; // pushing to my input file

			ofstream myfile(to_string(i) + ".out");// output1...100.txt

			// myfile << "something\n"; // pushing to my output fill

		};
		fun(rng() % 100 + 1, rng() % 200 + 1);
		// ranges

	}
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}