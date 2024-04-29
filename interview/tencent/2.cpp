#include <iostream>
#include <vector>
#include <map>
using namespace std;

int k, a, b, c;

int getlayer(int x, vector<int>& p) {
    int layer = 1;
    int t = 1 << (k - 1);
    int delta = t / 2;
    while (t != x) {
        // printf("t: %d\n", t);
        // printf("delta: %d\n", delta);
        p.push_back(t);
        if (t > x) t -= delta;
        else t += delta;
        layer++;
        delta /= 2;
    }
    p.push_back(t);
    return layer;
}

int main() {
    cin >> k >> a >> b >> c;

    vector<int> pa;
    vector<int> pb;
    vector<int> pc;

    int la = getlayer(a, pa), lb = getlayer(b, pb), lc = getlayer(c, pc);

    for (int x: pa) cout << x << ' ';
    cout << endl;
    for (int x: pb) cout << x << ' ';
    cout << endl;
    for (int x: pc) cout << x << ' ';
    cout << endl;

    vector<int> pab;
    map<int, bool> sta, stab;
    for (int x: pa) sta[x] = true;
    for (int x: pb) {
        if (sta[x]) {
            pab.push_back(x);
            stab[x] = true;
        }
    }

    vector<int> pabc;
    for (int x: pc) {
        if (stab[x]) {
            pabc.push_back(x);
        }
    }
    cout << pabc.back() << endl;

    return 0;
}