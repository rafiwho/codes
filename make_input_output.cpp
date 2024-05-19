#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int mx = 1E9;
void tcase() {

	const int mx_input_output = 10;
	for (auto i = 1LL; i <= mx_input_output ; ++i) {
		// fun is the sol of a given prob
<<<<<<< HEAD
		auto fun = [&](int x, int y) {
			ofstream myfle(to_string(i) + ".in"); // input1....100.txt
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
			ofstream myfile(to_string(i) + ".out");// output1...100.txt
=======
		auto fun = [&](int a, int b , int c, int x) {

			ofstream myfle("input" + to_string(i) + ".txt"); // input1....100.txt
			myfle << a << " " << b << " " << c << " " << d; // pushing to my input file

			ofstream myfile("output" + to_string(i) + ".txt");// output1...100.txt
			myfile << 0LL + a + b + c + d << '\n'; // pushing to my output file
>>>>>>> 4593e14 (xx)

		};
		fun(rng() % mx , rng() % mx, rng() % mx, rng() % mx);
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
