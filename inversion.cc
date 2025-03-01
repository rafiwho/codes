// 1 based
struct F {
  vector<int> bit;
  int n;

  F(int n) : n(n) {
    bit.assign(n + 1, 0);
  }

  void update(int idx, int delta) {
    for (; idx <= n; idx += idx & -idx)
      bit[idx] += delta;
  }

  int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
      sum += bit[idx];
    return sum;
  }
};
int getinv(vector<int>&a) {
  int n = size(a);
  F f(n);
  int inv = 0;
  for (int i = n - 1; ~i; --i) {
    inv += f.query(a[i] - 1);
    f.update(a[i], 1);
  }
  return inv;
}