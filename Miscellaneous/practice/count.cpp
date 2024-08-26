#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100;
int arr[N];
int n;

void show() {
    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    cout << endl;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    //count
    int i = 1;
    while (i <= n) {
        show();
        if (arr[i] <= 0) {
            i++;
            continue; 
        }
        int t = arr[i];
        if (arr[t] > 0) {
            arr[i] = arr[t];
            arr[t] = -1;
        } else {
            arr[i] = 0;
            arr[t] -= 1;
        }
    }
    show();

    //output
    for (int i = 1; i <= n; i++) {
        if (arr[i] < 0) {
            cout << i << " -> " << -arr[i] << endl;
        }
    }

    return 0;
}
// 5 5 4 3 2 1
// 5 4 4 4 2 1
// 13 3 4 4 1 2 1 3 7 1 6 5 6 4
