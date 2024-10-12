/* 
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
 */

#include <iostream>
#include <vector>
using namespace std;

vector<string> ans;
int n; 

void dfs(int l, int r, string path) {
    if (l < 0 || r < 0) return;
    if (l == 0 && r == 0) ans.push_back(path);

    dfs(l - 1, r, path + "(");
    
    // check
    if (l < r) {
        dfs(l, r - 1, path + ")");
    }
}

int main() {
    // cin >> n;
    n = 3;

    string path = "";
    dfs(n, n, path);

    for (auto s: ans) {
        cout << s << endl;
    }

    return 0;
}