#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int i, j, k, sum, min = num[0] + num[1] + num[num.size() - 1];
        for (i = 0; i < num.size() - 2; ++i) {
            j = i + 1, k = num.size() - 1;
            while (j < k) {
                sum = num[i] + num[j] + num[k];
                if (sum == target) return sum;
                if (sum > target) --k;
                else ++j;
                min = (abs(sum - target) < abs(min - target))? sum: min;
            }
        }
        return min;
    }
};

int main()
{
    int arr1[] = {-1,2,1,-4};
    vector<int> num1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    int arr2[] = {-3,-2,-5,3,-4};
    vector<int> num2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    int target1 = 1;
    int target2 = -1;
    Solution solution;
    cout << solution.threeSumClosest(num1, target1) << endl;
    cout << solution.threeSumClosest(num2, target2) << endl;
}
