#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace::std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> v(digits);
        int carry = 1;
        for_each(v.rbegin(), v.rend(), [&](int &i) {
            int tmp = i + carry;
            i = tmp % 10;
            carry = tmp / 10;
        });
        if (carry)
            v.insert(v.begin(), carry);
        return v;
    }
};

int main()
{
    int arr[] = {9, 9, 9};
    vector<int> digits(arr, arr + sizeof(arr) / sizeof(int));
    Solution solution;
    vector<int> v = solution.plusOne(digits);
    copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, "\n"));
}
