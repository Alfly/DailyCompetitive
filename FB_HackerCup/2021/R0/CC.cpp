#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 52;

int N, C[MAXN];
vector<int> adj[MAXN];

// 结点i到叶节点的最大路径和
int get_sum(int i, int parent) {
  int sum = 0;
  for (int j: adj[i]) {
    if (j != parent) sum = max(sum, get_sum(j, i));
  }
  return sum + C[i];
}

int solve() {
  cin >> N;
  for (int i = 0; i < N; i ++) {
    cin >> C[i];
    adj[i].clear();
  }
  for (int i = 0; i < N - 1; i ++) {
    int a, b;
    cin >> a >> b;
    a --, b --;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  // 根节点下和最大的两个子节点
  int m1 = 0, m2 = 0;
  for (int x: adj[0]) {
    int v = get_sum(x, 0);
    if (v > m1) {
      m2 = m1;
      m1 = v;
    } else {
      m2 = max(m2, v);
    }
  }
  return m1 + m2 + C[0];
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}
