#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
    int rob(vector<int> &num) {
        if (num.empty())
            return 0;
        int foo = num[0], bar = 0, tmp;
        for (int i = 1; i < num.size(); ++i) {
            tmp = foo;
            foo = max(foo, bar + num[i]);
            bar = tmp;
        }
        return max(foo, bar);
    }
};

int main() {
    int arr[] = {2,7,1,13,5,11,19,3};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));
    Solution solution;
    cout << solution.rob(num) << endl;
}
