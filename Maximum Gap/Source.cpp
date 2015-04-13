#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
    struct bucket {
        int min;
        int max;
        bucket() : min(INT_MAX), max(INT_MIN) {}
    };
    int maximumGap(vector<int> &num) {
        if (num.size() < 2) return 0;
        auto min_iter = min_element(num.cbegin(), num.cend());
        auto max_iter = max_element(num.cbegin(), num.cend());
        int bucket_size = (*max_iter - *min_iter) / (num.size() - 1);
        bucket_size = max(1, bucket_size);
        vector<bucket> buckets((*max_iter - *min_iter) / bucket_size + 1);
        for (auto it = num.cbegin(); it != num.cend(); ++it) {
            int bid = (*it - *min_iter) / bucket_size;
            buckets[bid].min = min(buckets[bid].min, *it);
            buckets[bid].max = max(buckets[bid].max, *it);
        }
        int max_gap = 0, prev_max = INT_MAX;
        for (auto it = buckets.cbegin(); it != buckets.cend(); ++it) {
            if (it->min == INT_MAX && it->max == INT_MIN)
                continue;
            max_gap = max(max_gap, it->min - prev_max);
            prev_max = it->max;
        }
        return max_gap;
    }
};

int main()
{
    int arr[] = {8, 11, 7, 31, 17, 3, 23, 37, 13, 27};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));
    Solution solution;
    cout << solution.maximumGap(num) << endl;
}
