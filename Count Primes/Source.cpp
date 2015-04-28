#include <iostream>
#include <vector>
#include <cmath>
using namespace::std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        if (n == 3) return 1;
        vector<bool> checker((n - 4) / 2 + 1, 0);
        int max = sqrt(n - 1);
        for (int i = 3; i <= max; i += 2) {
            if (checker[(i - 3) / 2])
                continue;
            for (int j = i * i; j < n; j += i)
                if (j % 2)
                    checker[(j - 3) / 2] = 1;
        }
        int sum = 1;
        for (const bool b : checker)
            sum += !b;
        return sum;
    }
};

int main()
{
    Solution solution;
    cout << (solution.countPrimes(3) == 1) << endl;
    cout << (solution.countPrimes(4) == 2) << endl;
    cout << (solution.countPrimes(6) == 3) << endl;
    cout << (solution.countPrimes(13) == 5) << endl;
}
