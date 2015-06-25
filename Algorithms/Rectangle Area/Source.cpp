/*
 * Author: Qiang Jia
 * Date: Jun 25, 2015
 * Link: https://leetcode.com/problems/rectangle-area/
 * Description:
 *      Find the total area covered by two rectilinear rectangles in a 2D plane.
 *      Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 *      Assume that the total area is never beyond the maximum possible value of int.
 */

#include <iostream>
#include <algorithm>
using namespace::std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		return (C - A) * (D - B) + (G - E) * (H - F) - max(min(min(C - E, G - A), min(C - A, G - E)), 0) * max(min(min(H - B, D - F), min(H - F, D - B)), 0);
	}
};
