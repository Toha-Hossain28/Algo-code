#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
  vector<int> rank, parent, size;
public:
  DisjointSet(int n) {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }

  int findUParent(int node) {
    if (node == parent[node])
      return node;
    return parent[node] = findUParent(parent[node]);
  }

  void unionByRank(int u, int v) {
    int Pu = findUParent(u);
    int Pv = findUParent(v);
    if (Pu == Pv)
      return;
    if (rank[Pu] < rank[Pv]) {
      parent[Pu] = Pv;
    }
    else if (rank[Pu] > rank[Pv]) {
      parent[Pv] = Pu;
    }
    else {
      parent[Pv] = Pu;
      rank[Pu]++;
    }
  }

  void unionBySize(int u, int v) {
    int Pu = findUParent(u);
    int Pv = findUParent(v);
    if (Pu == Pv)
      return;
    if (size[Pu] < size[Pv]) {
      parent[Pu] = Pv;
      size[Pv] += size[Pu];
    }
    else {
      parent[Pv] = Pu;
      size[Pu] += size[Pv];
    }
  }

};

int main() {
  DisjointSet ds(7);
  ds.unionByRank(1, 2);
  ds.unionByRank(2, 3);
  ds.unionByRank(4, 5);
  ds.unionByRank(6, 7);
  ds.unionByRank(5, 6);
  if (ds.findUParent(3) == ds.findUParent(7))
    cout << "same comp\n";
  else
    cout << "different comp\n";
  ds.unionByRank(3, 7);

  if (ds.findUParent(3) == ds.findUParent(7))
    cout << "same comp\n";
  else
    cout << "different comp\n";

  return 0;
}