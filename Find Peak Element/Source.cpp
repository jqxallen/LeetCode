#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
    int _find_local_peak_(const vector<int> &num, int start, int end, int size) {
        int middle = (start + end) / 2;
        if ((middle == 0 || num[middle] > num[middle - 1]) && (middle == size - 1 || num[middle] > num[middle + 1]))
            return middle;
        else if (num[middle] > num[middle + 1])
            return this->_find_local_peak_(num, start, middle, size);
        return this->_find_local_peak_(num, middle + 1, end, size);
    }
    int findPeakElement(const vector<int> &num) {
        return this->_find_local_peak_(num, 0, num.size() - 1, num.size());
    }
};

int main()
{
    int arr[] = {1, 2, 3, 1};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));
    Solution solution;
    cout << solution.findPeakElement(num) << endl;
}
