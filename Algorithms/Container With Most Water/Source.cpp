/*
 * Author: Qiang Jia
 * Date: Jul 28, 2015
 * Link: https://leetcode.com/problems/container-with-most-water/
 * Description:
 *      Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *      Note: You may not slant the container.
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace::std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int l = 0, r = height.size() - 1, h, w = 0;
		while (l < r) {
			h = min(height[l], height[r]);
			w = max(w, (r - l) * h);
			while (l < r && height[l] <= h) ++l;
			while (l < r && height[r] <= h) --r;
		}
		return w;
	}
};
