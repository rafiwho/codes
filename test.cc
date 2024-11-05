#include <bits/stdc++.h>
using namespace std;

struct State {
	int length, link;
	std::map<char, int> transitions;
	int cnt; // For counting occurrences
	long long num_substrings; // Number of unique substrings from this state
};

class SuffixAutomaton {
public:
	std::vector<State> states;
	int last;

	SuffixAutomaton(const std::string &s) {
		states.push_back({0, -1});
		last = 0;
		for (char c : s) add_char(c);
		count_substrings(0);
	}

	void add_char(char c) {
		int cur = states.size();
		states.push_back({states[last].length + 1, 0, {}, 1});
		int p = last;
		while (p != -1 && !states[p].transitions.count(c)) {
			states[p].transitions[c] = cur;
			p = states[p].link;
		}
		if (p == -1) {
			states[cur].link = 0;
		} else {
			int q = states[p].transitions[c];
			if (states[p].length + 1 == states[q].length) {
				states[cur].link = q;
			} else {
				int clone = states.size();
				states.push_back({states[p].length + 1, states[q].link, states[q].transitions, 0});
				while (p != -1 && states[p].transitions[c] == q) {
					states[p].transitions[c] = clone;
					p = states[p].link;
				}
				states[q].link = states[cur].link = clone;
			}
		}
		last = cur;
	}
	bool contains(const std::string &substr) {
		int current = 0;
		for (char c : substr) {
			if (!states[current].transitions.count(c)) return false;
			current = states[current].transitions[c];
		}
		return true;
	}

	void build() {
		int sz = states.size();
		std::vector<int> indegree(sz, 0);
		for (int i = 0; i < sz; ++i) {
			if (states[i].link != -1) indegree[states[i].link]++;
		}
		std::queue<int> q;
		for (int i = 0; i < sz; ++i) {
			if (indegree[i] == 0) q.push(i);
		}
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (states[cur].link != -1) {
				states[states[cur].link].cnt += states[cur].cnt;
				if (--indegree[states[cur].link] == 0) {
					q.push(states[cur].link);
				}
			}
		}
	}
	// Count the number of unique substrings from a given state
	long long count_substrings(int state) {
		if (states[state].num_substrings != 0) return states[state].num_substrings;
		long long cnt = 1;
		for (auto &[c, next_state] : states[state].transitions) {
			cnt += count_substrings(next_state);
		}
		return states[state].num_substrings = cnt;
	}
	// Count occurrences of a specific substring in the original string
	// Ensure `build` is called before this function to propagate `cnt` values
	int count_occurrences(const std::string &substr) {
		int current = 0;
		for (char c : substr) {
			if (!states[current].transitions.count(c)) return 0;
			current = states[current].transitions[c];
		}
		return states[current].cnt;
	}
	// Find the k-th lexicographical substring
	std::string kth_substring(int k) {
		int current = 0;
		std::string result;
		while (k > 0) {
			for (auto &[c, next_state] : states[current].transitions) {
				int num = states[next_state].num_substrings;
				if (k > num) {
					k -= num;
				} else {
					result += c;
					current = next_state;
					k--;
					break;
				}
			}
		}
		return result;
	}

	int longest_common_substring(const std::string &t) {
		int current = 0, length = 0, best = 0;
		for (char c : t) {
			while (current != -1 && !states[current].transitions.count(c)) {
				current = states[current].link;
				length = current == -1 ? 0 : states[current].length;
			}
			if (current != -1) {
				current = states[current].transitions[c];
				length++;
				best = std::max(best, length);
			}
		}
		return best;
	}
	// Count the number of distinct substrings in the original string
	long long count_distinct_substrings() {
		long long total = 0;
		for (const auto &state : states) {
			total += state.length - (state.link == -1 ? 0 : states[state.link].length);
		}
		return total;
	}

};
void tcase() {
	string s;
	cin >> s;
	SuffixAutomaton sa(s);
	auto ans = [&](char ch)->int64_t{
		if (sa.states[0].transitions.count(ch) == 0) return 0;
		return sa.count_substrings(sa.states[0].transitions[ch]);
	};
	for (char ch = 'a'; ch <= 'z'; ++ch) {
		cout << ans(ch) << ' ';
	}
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1;
	// cin >> t;

	while (t-- > 0)
		tcase();

	return 0;
}
