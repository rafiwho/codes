void ___(int x) {cerr << x;}
void ___(long x) {cerr << x;}
void ___(long long x) {cerr << x;}
void ___(unsigned x) {cerr << x;}
void ___(unsigned long x) {cerr << x;}
void ___(unsigned long long x) {cerr << x;}
void ___(float x) {cerr << x;}
void ___(double x) {cerr << x;}
void ___(long double x) {cerr << x;}
void ___(char x) {cerr << '\'' << x << '\'';}
void ___(const char *x) {cerr << '\"' << x << '\"';}
void ___(const string &x) {cerr << '\"' << x << '\"';}
void ___(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void ___(const pair<T, V> &x) {cerr << '{'; ___(x.first); cerr << ','; ___(x.second); cerr << '}';}
template<typename T>
void ___(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), ___(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {___(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
