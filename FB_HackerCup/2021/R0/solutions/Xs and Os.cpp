#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

const int MAXN = 50, INF = 1e9;

int N;
char C[MAXN][MAXN];

void solve() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> C[i][j];
    }
  }
  int ans1 = INF, ans2;
  set<pair<int, int>> S;
  // Rows
  for (int i = 0, j; i < N; i++) {
    vector<int> empty;
    for (j = 0; j < N; j++) {
      if (C[i][j] == 'O') {
        break;
      }
      if (C[i][j] == '.') {
        empty.push_back(j);
      }
    }
    if (j == N) {
      int c = empty.size();
      if (c < ans1) {
        ans1 = c;
        ans2 = 0;
      }
      if (c == 1) {
        S.insert(make_pair(i, empty[0]));
      } else if (c == ans1) {
        ans2++;
      }
    }
  }
  // Columns
  for (int i, j = 0; j < N; j++) {
    vector<int> empty;
    for (i = 0; i < N; i++) {
      if (C[i][j] == 'O') {
        break;
      }
      if (C[i][j] == '.') {
        empty.push_back(i);
      }
    }
    if (i == N) {
      int c = empty.size();
      if (c < ans1) {
        ans1 = c;
        ans2 = 0;
      }
      if (c == 1) {
        S.insert(make_pair(empty[0], j));
      } else if (c == ans1) {
        ans2++;
      }
    }
  }
  if (ans1 == INF) {
    cout << "Impossible" << endl;
  } else {
    cout << ans1 << " " << (ans1 == 1 ? S.size() : ans2) << endl;
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
