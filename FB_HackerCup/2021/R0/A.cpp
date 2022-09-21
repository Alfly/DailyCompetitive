#include <string>
#include <vector>
#include <iostream>

using namespace std;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int INF = int(1e9) + 5;
const int ALPHABET = 26;
const char MIN_CHAR = 'A';

vector<vector<int>> dist;

bool is_vowel(char ch) {
    const string VOWELS = "AEIOU";
    return VOWELS.find(ch) != string::npos;
}

// chapter1
void build_changes() {
    for (int a = 0; a < ALPHABET; ++a) 
        for (int b = 0; b < ALPHABET; ++b) 
            if (is_vowel(char(MIN_CHAR + a)) ^ is_vowel(char(MIN_CHAR + b)))
                dist[a][b] = 1;
}

// chapter2
void read_change() {
    int N;  cin >> N;
    for (int i = 0; i < N; i ++) {
        string str;
        cin >> str;
        dist[str[0] - MIN_CHAR][str[1] - MIN_CHAR] = 1;
    }
}

void run_cases(int test_case) {
    string S;
    cin >> S;

    dist.assign(ALPHABET, vector<int>(ALPHABET, INF));
    build_changes();
    // read_change();

    for (int i = 0; i < ALPHABET; ++i) 
        dist[i][i] = 0;
    for (int k = 0; k < ALPHABET; ++k) 
        for (int i = 0; i < ALPHABET; ++i) 
            for (int j = 0; j <ALPHABET; ++j) 
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int64_t ans = INF;
    for (int c = 0; c < ALPHABET; ++ c) {
        int64_t sum = 0;
        for (auto& ch: S) {
            sum += dist[ch - MIN_CHAR][c];
        }
        ans = min(ans, sum);
    }

    cout << "Case #" << test_case << ": " << (ans < INF ? ans : -1) << '\n';
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