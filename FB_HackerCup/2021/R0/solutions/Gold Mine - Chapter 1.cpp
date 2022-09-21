#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int LIM = 52;

int N, C[LIM];
vector<int> adj[LIM];

// Maximum path sum from i down to any leaf.
int rec(int i, int parent) {
  int m = 0;
  for (int j : adj[i]) {
    if (j != parent) {
      m = max(m, rec(j, i));
    }
  }
  return C[i] + m;
}

int solve() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> C[i];
    adj[i].clear();
  }
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  // Find up to 2 best children of root.
  int m1 = 0, m2 = 0;
  for (auto c : adj[0]) {
    int v = rec(c, 0);
    if (v > m1) {
      m2 = m1;
      m1 = v;
    } else {
      m2 = max(m2, v);
    }
  }
  return C[0] + m1 + m2;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}
