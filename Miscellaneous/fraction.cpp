#include <iostream>
using LL = long long;

struct Fraction {
    LL up, down;
};

// 最大公约数
LL gcd(LL a, LL b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}

// 约简
Fraction reduction(Fraction f) {
    if (f.down < 0) {
        f.up = -f.up;
        f.down = -f.down;
    }
    if (f.up == 0) {
        f.down = 1;
    } else {
        int d = gcd(abs(f.up), abs(f.down));
        f.up /= d;
        f.down /= d;
    }
    return f;
}

Fraction add(Fraction a, Fraction b) {
    Fraction res;
    res.up = a.up * b.down + a.down * b.up;
    res.down = a.down * b.down;
    return reduction(res);
}
Fraction sub(Fraction a, Fraction b) {
    Fraction res;
    res.up = a.up * b.down - a.down * b.up;
    res.down = a.down * b.down;
    return reduction(res);
}
Fraction mul(Fraction a, Fraction b) {
    Fraction res;
    res.up = a.up * b.up;
    res.down = a.down * b.down;
    return reduction(res);
}
Fraction div(Fraction a, Fraction b) {
    Fraction res;
    res.up = a.up * b.down;
    res.down = a.down * b.up;
    return reduction(res);
}

void show(Fraction r) {
    r = reduction(r);
    if (r.up < 0) {
        printf("-");
        r.up = abs(r.up);
    }
    if (r.down == 1) {
        printf("%lld", r.up);
    } else if (r.up > r.down) {
        // 假分数: 分子大于或等于分母 -> 带分数: 非零自然数+真分数
        printf("%lld %lld/%lld", r.up / r.down, r.up % r.down, r.down);
    } else {
        printf("%lld/%lld", r.up, r.down);
    }
}

int main() {
    Fraction f = {5, -2};
    show(f);    // -2 1/2
}