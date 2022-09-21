#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 1e6;

bool is_vowel(char c) {
  return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

string S;

int solve() {
  cin >> S;
  int ans = INF;
  for (char c1 = 'A'; c1 <= 'Z'; c1++) {
    int curr = 0;
    for (char c2 : S) {
      if (c1 != c2) {
        curr += is_vowel(c1) == is_vowel(c2) ? 2 : 1;
      }
    }
    ans = min(ans, curr);
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}
