/*
 * Author: Qiang Jia
 * Date: Aug 5, 2015
 * Link: https://leetcode.com/problems/sliding-window-maximum/
 * Description:
 *      Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 *      For example,
 *			Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 *			Window position                Max
 *			---------------               -----
 *			[1  3  -1] -3  5  3  6  7       3
 *			 1 [3  -1  -3] 5  3  6  7       3
 *			 1  3 [-1  -3  5] 3  6  7       5
 *			 1  3  -1 [-3  5  3] 6  7       5
 *			 1  3  -1  -3 [5  3  6] 7       6
 *			 1  3  -1  -3  5 [3  6  7]      7
 *			Therefore, return the max sliding window as [3,3,5,5,6,7].
 *      Note:
 *			You may assume k is always valid, ie: 1 ¡Ü k ¡Ü input array's size for non-empty array.
 *      Follow up:
 *			Could you solve it in linear time?
 *      Hint:
 *			1. How about using a data structure such as deque (double-ended queue)?
 *			2. The queue size need not be the same as the window¡¯s size.
 *			3. Remove redundant elements and the queue should store only elements that need to be considered.
 */

#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
using namespace::std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> results;
		deque<int> deq;
		for (int i = 0; i < nums.size(); ++i) {
			if (!deq.empty() && deq.front() == i - k)
				deq.pop_front();
			while (!deq.empty() && nums[deq.back()] < nums[i])
				deq.pop_back();
			deq.push_back(i);
			if (i + 2 > k)
				results.push_back(nums[deq.front()]);
		}
		return results;
	}
};

void main()
{
	int arr[] = { 1, 3, -1, -3, 5, 3, 6, 7 }, k = 3;
	vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
	Solution solution;
	vector<int> results = solution.maxSlidingWindow(nums, k);
	copy(results.cbegin(), results.cend(), ostream_iterator<int>(cout, ","));
}
