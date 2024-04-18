#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

unordered_map<string, vector<string>> graph;
unordered_map<string, int> risks1;
unordered_map<string, int> risks2;

pair<int, int> dfs(const string& dept) {
    int risk1 = risks1[dept];
    int risk2 = risks2[dept];

    for (const string& sub : graph[dept]) {
        auto subRisks = dfs(sub);
        risk1 += subRisks.first;
        risk2 += subRisks.second;
    }

    return {risk1, risk2};
}

int main() {
    int m, n;
    cin >> m >> n;

    unordered_set<string> roots;
    for (int i = 0; i < n; i++) {
        string dept, parent;
        int level, num;
        cin >> dept >> parent >> level >> num;

        if (parent == "*") {
            roots.insert(dept);
        } else {
            graph[parent].push_back(dept);
        }

        if (level == 0) {
            risks1[dept] = num;
        } else {
            risks2[dept] = num;
        }
    }

    int cnt = 0;
    for (const string& root : roots) {
        auto risks = dfs(root);
        if (5 * risks.first + 2 * risks.second > m) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}

/* 

dfs 根节点求总数

 */