#include <iostream>
using namespace::std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int val = 0;
        for (int i = 0; i < 32; val <<= 1, val += n >> i++ & 0x1);
        return val;
    }
};

int main() {
    Solution solution;
    cout << solution.reverseBits(43261596) << endl;
    cout << solution.reverseBits(1) << endl;
    return 0;
}
