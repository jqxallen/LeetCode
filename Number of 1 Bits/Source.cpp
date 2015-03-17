#include <iostream>
using namespace::std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; ++i)
            count += n >> i & 0x1;
        return count;
    }
};

int main() {
    Solution solution;
    cout << solution.hammingWeight(11) << endl;
    return 0;
}
