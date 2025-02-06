#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct HLD {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    vector<T> segtree;
    int cur_pos;

    function<T(T, T)> combine;
    T identity;

    HLD(int nodes, function<T(T, T)> combine_func, T identity_element)
        : n(nodes), adj(nodes), parent(nodes, -1), depth(nodes, 0),
          heavy(nodes, -1), head(nodes), pos(nodes), segtree(4 * nodes, identity_element),
          cur_pos(0), combine(combine_func), identity(identity_element) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int dfs(int u) {
        int size = 1, max_subtree = 0;
        for (int v : adj[u]) {
            if (v != parent[u]) {
                parent[v] = u;
                depth[v] = depth[u] + 1;
                int subtree_size = dfs(v);
                if (subtree_size > max_subtree) {
                    max_subtree = subtree_size;
                    heavy[u] = v;
                }
                size += subtree_size;
            }
        }
        return size;
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = cur_pos++;
        if (heavy[u] != -1) {
            decompose(heavy[u], h);
        }
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                decompose(v, v);
            }
        }
    }

    void update(int idx, T value) {
        int n = cur_pos;
        segtree[idx += n] = value;
        for (; idx > 1; idx /= 2) {
            segtree[idx / 2] = combine(segtree[idx], segtree[idx ^ 1]);
        }
    }
private:
    T query(int l, int r) {
        int n = cur_pos;
        T res = identity;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = combine(res, segtree[l++]);
            if (r & 1) res = combine(res, segtree[--r]);
        }
        return res;
    }
public:
    T query_path(int u, int v) {
        T res = identity;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            res = combine(res, query(pos[head[v]], pos[v] + 1));
            v = parent[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        res = combine(res, query(pos[u], pos[v] + 1));
        return res;
    }

    void initialize(int root = 0) {
        dfs(root);
        decompose(root, root);
    }
};
/*
make everything 0 based
after adding edge
hld.initialize();
*/
void tcase() {
}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int32_t t = 1;
    //cin >> t;

    while (t-- > 0)
        tcase();
}