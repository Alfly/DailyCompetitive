#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
using namespace std;

int n, m;

int main() {
    cin >> n;

    set<string> match; // 判断是否存在相同的时间戳客户和计费因子
    map<pair<string, string>, int> h1;

    for (int i = 0; i < n; i++) {
        string logstr, tmp;
        cin >> logstr;
        stringstream ss(logstr);
        vector<string> log;
        while (getline(ss, tmp, ',')) {
            log.push_back(tmp);
        }

        string ts = log[0] + log[1] + log[2];
        if (match.count(ts)) continue;
        else match.insert(ts);

        int time = stoi(log[3]);
        if (time < 0 || time > 100) continue;

        h1[{log[1], log[2]}] += time;
    }

    cin >> m;

    unordered_map<string, int> h2;

    while (m--) {
        string p, t;
        cin >> p;
        stringstream ss(p);
        vector<string> price;
        while (getline(ss, t, ',')) {
            price.push_back(t);
        }

        h2[price[0]] = stoi(price[1]);
    }

    map<string, int> h3;

    for (auto& [k, v]: h1) {
        string c = k.first, f = k.second;
        h3[c] += v * h2[f];
    }

    for (auto& [k, v]: h3) {
        printf("%s,%d\n", k.c_str(), v);
    }

    return 0;
}