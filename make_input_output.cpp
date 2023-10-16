#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

void tcase() {

	const int mx_input_output = 10;
	for (auto i = 1LL; i <= mx_input_output ; ++i) {
		// fun is the sol of a given prob
		auto fun = [&](int x, int y) {
			ofstream myfle("input" + to_string(i) + ".txt"); // input1....100.txt
			myfle << x << " " << y; // pushing to my input file
			int ticket_price = 0;

			if (x < 3 || x >= 70) {
				ticket_price = 0;
			} else if (x >= 3 && x <= 12) {
				ticket_price = 10;
			} else if (x >= 65 && x <= 69) {
				ticket_price = 15;
			} else if (x >= 30 && x <= 40 && y > 75) {
				ticket_price = 18;
			} else {
				ticket_price = 20;
			}
			ofstream myfile("output" + to_string(i) + ".txt");// output1...100.txt

			if (ticket_price == 0) {
				myfile << "Free\n"; // pushing to my output fill
			} else {
				myfile << ticket_price << '\n'; // pushing to my output file
			}
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