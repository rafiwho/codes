#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

void tcase() {

	const int mx_input_output = 100;
	for (auto i = 1LL; i <= mx_input_output ; ++i) {
		// fun is the sol of a given prob
		auto fun = [&](int x, int y) {
			ofstream myfle("input" + to_string(i) + ".txt"); // input1....100.txt
			myfle << x << " " << y; // pushing to my input file
			ofstream myfile("output" + to_string(i) + ".txt");// output1...100.txt
			myfile << 69; // pushing to my output file
		};
		fun(rng() % 100, rng() % 200);
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