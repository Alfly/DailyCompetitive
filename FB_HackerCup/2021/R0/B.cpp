#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void run_cases(int test_case) {
    int N;
    cin >> N;
    vector<string> grid(N);
    for (int i = 0; i < N; i ++) {
        cin >> grid[i];
    }

    int minv = N + 1;
    vector<vector<int>> solutions;
    for (int iter = 0; iter < 2; iter ++) { // hor and ver
        for (int r = 0; r < N; r ++) {
            int need = 0;
            vector<int> solution;

            for (int c = 0; c < N; c ++) {
                if (grid[r][c] == 'O') {
                    need = N + 1;
                    break;
                }
                // need += grid[r][c] == '.';
                if (grid[r][c] == '.') {
                    need ++;
                    solution.push_back(iter == 0 ? r * N + c : c * N + r);
                }
            }
            sort(solution.begin(), solution.end());

            if (need < minv) {
                minv = need;
                solutions = {solution};
            } else if (need == minv) {
                solutions.emplace_back(solution);
            }
        }

        // other direction
        for (int i = 0; i < N; i ++)
            for (int j = i + 1; j < N; j ++)
                swap(grid[i][j], grid[j][i]);
    }

    // uniq
    sort(solutions.begin(), solutions.end());
    solutions.erase(unique(solutions.begin(), solutions.end()), solutions.end());

    cout << "Case #" << test_case << ": ";
    if (minv > N) 
        cout << "Impossible" << '\n';
    else
        cout << minv << ' ' << solutions.size() << '\n';

}

int main() {
    quick_read();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int tc = 1; tc <= tests; tc ++) {
        run_cases(tc);
        cout << flush;
    }
    return 0;
}