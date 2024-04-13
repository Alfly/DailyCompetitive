#include <iostream>
#include <vector>
#include <map>
using namespace std;

int k, a, b, c;

int main() {
    cin >> k >> a >> b >> c;

    vector<int> nums = {a, b, c};
    sort(nums.begin(), nums.end());
    int minv = nums[0], maxv = nums[2];

    int l = 1, r = (1 << k) - 1;
    int mid;
    while (1) {
        mid = (l + r) >> 1;
        if ((mid > minv && mid < maxv) || mid == minv || mid == maxv) {
            break;
        }
        if (mid < minv) {
            l = mid + 1;
        } else if (mid > maxv) {
            r = mid - 1;
        }
    }
    cout << mid << endl;

    return 0;
}