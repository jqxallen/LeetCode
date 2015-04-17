#include <iostream>
#include <cmath>
using namespace::std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n) return m;
        return m & n & (0xffffffff << int(log((n - m) * 1.0) / log(2.0) + 1));
    }
};

int main()
{
    Solution solution;
    cout << (solution.rangeBitwiseAnd(0, 0) == 0) << endl;
    cout << (solution.rangeBitwiseAnd(3, 3) == 3) << endl;
    cout << (solution.rangeBitwiseAnd(0, 7) == 0) << endl;
    cout << (solution.rangeBitwiseAnd(4, 6) == 4) << endl;
    cout << (solution.rangeBitwiseAnd(5, 6) == 4) << endl;
    cout << (solution.rangeBitwiseAnd(5, 7) == 4) << endl;
    cout << (solution.rangeBitwiseAnd(6, 7) == 6) << endl;
    cout << (solution.rangeBitwiseAnd(11, 15) == 8) << endl;
    cout << (solution.rangeBitwiseAnd(11, 16) == 0) << endl;
    cout << (solution.rangeBitwiseAnd(15, 2147483647) == 0) << endl;
}
