
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;

    // cout << log(2) << ' ' << log(3);

    // loga(b) = ln(b)/ln(a)
    // y = loga(x) - bx = ln(x)/ln(a) - bx
    // y' = 1/xln(a) - b = 0 => x * ln(a) * b = 1

    double x0 = 1 / (log(a) * b);

    // double x0 = 1 / (log(a) * b);
    // double l = 0, r = 2 * x0;
    // while (r - l > 1e-15) {
    //     double mid  = (l + r) / 2.0;
    //     if (mid * log(a) * b > 1.0) r = mid;
    //     else l = mid;
    // }
    // x0 = l;

    double y = log(x0)/log(a) - b * x0;

    // 直接使用 cout 默认小数点后 6 位
    // cout << y << endl;      // -0.913929
    // cout << setprecision(15) << y << endl; // -0.913928667944066
    printf("%.15f\n", y);   // -0.913928667944066
    return 0;
}