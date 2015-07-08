/*
 * Author: Qiang Jia
 * Date: Jul 8, 2015
 * Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
 * Description:
 *      Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 *      For example,
 *      Given [3,2,1,5,6,4] and k = 2, return 5.
 *      Note:
 *      You may assume k is always valid, 1 <= k <= array's length.
 */

#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		heapify(nums);
		int i, j = 0, n = nums.size();
		for (i = n - 1; i > 0 && n - i <= k; --i, j = 0) {
			swap(nums[j], nums[i]);
			while (j * 2 + 1 < i) {
				if (nums[j] < nums[j * 2 + 1]) {
					if (j * 2 + 2 < i && nums[j * 2 + 1] < nums[j * 2 + 2]) {
						swap(nums[j], nums[j * 2 + 2]);
						j = j * 2 + 2;
					}
					else {
						swap(nums[j], nums[j * 2 + 1]);
						j = j * 2 + 1;
					}
				}
				else if (j * 2 + 2 < i && nums[j] < nums[j * 2 + 2]) {
					swap(nums[j], nums[j * 2 + 2]);
					j = j * 2 + 2;
				}
				else {
					break;
				}
			}
		}
		return nums[nums.size() - k];
	}
private:
	void heapify(vector<int>& nums) {
		int i, j, n = nums.size();
		for (i = j = 0; i < n; ++i, j = i) {
			while (j > 0) {
				if (nums[j] > nums[(j - 1) / 2])
					swap(nums[j], nums[(j - 1) / 2]);
				j = (j - 1) / 2;
			}
		}
	}
};

void main()
{
	int arr[] = { 6, 5, 3, 1, 8, 7, 2, 4 };
	vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
	Solution solution;
	cout << solution.findKthLargest(nums, 3) << endl;
}
