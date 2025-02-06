template<typename T>
struct LinkCutTree {
  struct Node {
    int parent = -1, left = -1, right = -1;
    T value, sum;
    bool rev = false;

    Node(T val = T()) : value(val), sum(val) {}
  };

  vector<Node> nodes;
  function<T(T, T)> combine;
  T identity;

  LinkCutTree(int n, function<T(T, T)> combine_func, T identity_element)
    : nodes(n), combine(combine_func), identity(identity_element) {}

  bool isRoot(int x) {
    int p = nodes[x].parent;
    return p == -1 || (nodes[p].left != x && nodes[p].right != x);
  }

  void push(int x) {
    if (nodes[x].rev) {
      swap(nodes[x].left, nodes[x].right);
      if (nodes[x].left != -1) nodes[nodes[x].left].rev ^= true;
      if (nodes[x].right != -1) nodes[nodes[x].right].rev ^= true;
      nodes[x].rev = false;
    }
  }

  void update(int x) {
    nodes[x].sum = nodes[x].value;
    if (nodes[x].left != -1) nodes[x].sum = combine(nodes[x].sum, nodes[nodes[x].left].sum);
    if (nodes[x].right != -1) nodes[x].sum = combine(nodes[x].sum, nodes[nodes[x].right].sum);
  }

  void rotate(int x) {
    int p = nodes[x].parent;
    int gp = nodes[p].parent;

    if (!isRoot(p)) {
      if (nodes[gp].left == p) nodes[gp].left = x;
      else nodes[gp].right = x;
    }
    nodes[x].parent = gp;

    if (nodes[p].left == x) {
      nodes[p].left = nodes[x].right;
      if (nodes[x].right != -1) nodes[nodes[x].right].parent = p;
      nodes[x].right = p;
    } else {
      nodes[p].right = nodes[x].left;
      if (nodes[x].left != -1) nodes[nodes[x].left].parent = p;
      nodes[x].left = p;
    }
    nodes[p].parent = x;

    update(p);
    update(x);
  }

  void splay(int x) {
    while (!isRoot(x)) {
      int p = nodes[x].parent;
      int gp = nodes[p].parent;
      if (!isRoot(p)) push(gp);
      push(p);
      push(x);

      if (!isRoot(p)) {
        if ((nodes[gp].left == p) == (nodes[p].left == x)) rotate(p);
        else rotate(x);
      }
      rotate(x);
    }
    push(x);
  }

  int expose(int x) {
    int last = -1;
    for (int y = x; y != -1; y = nodes[y].parent) {
      splay(y);
      nodes[y].right = last;
      update(y);
      last = y;
    }
    splay(x);
    return last;
  }

  void makeRoot(int x) {
    expose(x);
    nodes[x].rev ^= true;
    push(x);
  }

  void link(int x, int y) {
    makeRoot(x);
    nodes[x].parent = y;
  }

  void cut(int x) {
    expose(x);
    if (nodes[x].left != -1) {
      nodes[nodes[x].left].parent = -1;
      nodes[x].left = -1;
      update(x);
    }
  }

  T queryPath(int x, int y) {
    makeRoot(x);
    expose(y);
    return nodes[y].sum;
  }

  void updateNode(int x, T value) {
    expose(x);
    nodes[x].value = value;
    update(x);
  }
};

/*
Example Usage:
LinkCutTree<int> lct(5, [](int a, int b) { return a + b; }, 0);
lct.link(0, 1);               // Create an edge between nodes 0 and 1
lct.link(1, 2);               // Create an edge between nodes 1 and 2
lct.updateNode(1, 5);         // Update the value of node 1 to 5
lct.queryPath(0, 2);          // Query the path sum between nodes 0 and 2
lct.cut(1);                   // Cut the connection between nodes 0 and 1
lct.link(2, 3);               // Create an edge between nodes 2 and 3
*/
