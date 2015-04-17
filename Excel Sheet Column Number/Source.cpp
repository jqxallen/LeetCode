#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace::std;

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0, i = 0;
        for_each(s.crbegin(), s.crend(), [&](char c){
            res += pow(26.0, i++) * (c - 'A' + 1);
        });
        return res;
    }
};

int main()
{
    Solution solution;
    cout << (solution.titleToNumber("A") == 1) << endl;
    cout << (solution.titleToNumber("Z") == 26) << endl;
    cout << (solution.titleToNumber("AA") == 27) << endl;
    cout << (solution.titleToNumber("ZZ") == 702) << endl;
    cout << (solution.titleToNumber("AAA") == 703) << endl;
    cout << (solution.titleToNumber("ZZZ") == 18278) << endl;
}
