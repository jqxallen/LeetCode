#include <iostream>
using namespace::std;

class Solution {
public:
    void _rotate_(int nums[], int n, int k, int s) {
        int i = s, num = nums[i], tmp;
        do {
            tmp = nums[(i + k) % n];
            nums[(i + k) % n] = num;
            i = (i + k) % n;
            num = tmp;
        } while (i != s);
    }
    void rotate(int nums[], int n, int k) {
        if (n < 2 || k < 1 || k % n == 0) return;
        k = k % n;
        int min = k < (n - k)? k: n - k;
        if (n % 2 == 0 && n % min == 0) {
            for (int i = 0; i < min; ++i)
                _rotate_(nums, n, k, i);
        } else {
            _rotate_(nums, n, k, 0);
        }
    }
};

int main() {
    int n = 6, k = 3;
    int nums[] = {1,2,3,4,5,6};
    Solution solution;
    for (auto i: nums) cout << i << " "; cout << endl;
    solution.rotate(nums, n, k);
    for (auto i: nums) cout << i << " "; cout << endl;
    return 0;
}
