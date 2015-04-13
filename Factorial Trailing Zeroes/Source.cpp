#include <iostream>
using namespace::std;

class Solution {
public:
    int trailingZeroes(int n) {
        int num = 0;
        while (n >= 5) {
            n /= 5;
            num += n;
        }
        return num;
    }
};

int main()
{
    Solution solution;
    for (int i = 1; i < 51; ++i)
        cout << i << "! has " << solution.trailingZeroes(i) << " trailing zeroes." << endl;
    cout << INT_MAX << "! has " << solution.trailingZeroes(INT_MAX) << " trailing zeroes." << endl;
}
