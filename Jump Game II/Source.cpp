#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int i = 0, j = 1, step = 0, max;
        while (i < nums.size() - 1 && i + nums[i] < nums.size() - 1) {
            for (max = j; j <= i + nums[i]; ++j)
                if (j + nums[j] >= max + nums[max])
                    max = j;
            i = max;
            ++step;
        }
        return ++step;
    }
};

int main()
{
    int arr[] = {2,3,1,1,4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    Solution solution;
    cout << solution.jump(nums) << endl;
}
