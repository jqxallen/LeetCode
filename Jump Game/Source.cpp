#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > jump) return 0;
            jump = max(jump, i + nums[i]);
        }
        return 1;
    }
};

int main()
{
    int arr[] = {2,3,1,1,4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    Solution solution;
    cout << (solution.canJump(nums) == 1) << endl;
}
