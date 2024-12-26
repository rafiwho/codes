#include <bits/stdc++.h>
using namespace std;
#undef _GLIBCXX_HAVE_ICONV
#include <bits/extc++.h>

template<class T>
using o_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

struct info {
  int ac = 0;
  int wa = 0;
  int score = 0;
};

void tcase() {
  int k, n; cin >> k >> n;
  cin.ignore();

  int64_t start = -1;
  o_set<int>rank;
  vector<info>team(k + 1);

  auto mili = [](string & time) -> long long {
    int hours, minutes, seconds, milliseconds;
    char ch;
    stringstream ss(time);
    ss >> hours >> ch >> minutes >> ch >> seconds >> ch >> milliseconds;
    return (int64_t(hours) * 60 * 60 + seconds) * 1000 + milliseconds;
  };

  for (int i = 0; i < n; ++i) {
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<string>tmp;
    string word;
    while (ss >> word) {
      tmp.push_back(word);
    }
    int team_id = stoi(tmp[1]);
    char problemid = tmp[2];

    if (start == -1 && tmp.back() == "AC") {
      start = mili(tmp[0]);
    }
    if (start != -1) {
      int name = stoi(tmp[1]);
      int64_t penalty = start + 20 * team[name].wa;
      team[name].score
    }
  }
}
int32_t main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int32_t t = 1;
  // cin >> t;

  while (t-- > 0)
    tcase();
}