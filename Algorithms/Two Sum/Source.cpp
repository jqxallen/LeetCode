/*
 * Author: Qiang Jia
 * Date: Nov 1, 2013
 * Link: https://leetcode.com/problems/two-sum/
 * Description:
 *		Given an array of integers, find two numbers such that they add up to a specific target number.
 *		The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *		You may assume that each input would have exactly one solution.
 *		Input: numbers={2, 7, 11, 15}, target=9
 *		Output: index1=1, index2=2
 */

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
using namespace::std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		multimap<int, int> coll;
		for (int i = 0; i < numbers.size(); ++i)
			coll.insert(make_pair(numbers[i], i + 1));
		auto first = coll.begin(), last = coll.end();
		last--;
		while (first != last) {
			if (first->first + last->first > target) last--;
			else if (first->first + last->first < target) first++;
			else break;
		}
		vector<int> index;
		index.push_back(first->second);
		index.push_back(last->second);
		sort(index.begin(), index.end());
		return index;
	}
};

void main()
{
	int arr[] = { 150, 24, 79, 50, 88, 345, 3 };
	int target = 200;
	vector<int> numbers(arr, arr + sizeof(arr) / sizeof(int));
	Solution solution;
	vector<int> res = solution.twoSum(numbers, target);
	copy(res.cbegin(), res.cend(), ostream_iterator<int>(cout, "\n"));
}
