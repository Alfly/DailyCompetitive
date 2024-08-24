#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class BitMap {
private:
    char *bits;    // 位图数据
    int size;
public:
    BitMap(): bits(nullptr), size(0) {}
    BitMap(int _size) {
        bits = new char[_size];
        memset(bits, 0, _size);
        this->size = _size;
    }
    bool Set(int num) {
        if (num > 8*size) {
            return false;
        }
        int pos = num / 8;
        int offset = num % 8;
        // cout << pos << ' ' << offset << endl;
        bits[pos] |= (0x80 >> offset);
        // bits[pos] |= (0x1 << offset);
        return true;
    }
    bool Get(int num) {
        if (num > 8*size) {
            return false;
        }
        int pos = num / 8;
        int offset = num % 8;
        return (bits[pos] & (0x80 >> offset)) > 0;
    }
};

int main() {
    vector<int> nums({1, 2, 3});
    vector<int> numsCheck({1, 2, 3, 4});
    BitMap *bitMap = new BitMap(100);
    for (int x: nums) {
        bitMap->Set(x);
    }
    for (int x: numsCheck) {
        cout << bitMap->Get(x) << endl;
    }
    return 0;
}