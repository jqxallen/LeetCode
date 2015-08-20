/*
 * Author: Qiang Jia
 * Date: Aug 20, 2015
 * Link: https://leetcode.com/problems/merge-intervals/
 * Description:
 *      For example,
 *			Given [1,3],[2,6],[8,10],[15,18],
 *			return [1,6],[8,10],[15,18].
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> results;
		if (intervals.empty()) return results;
		sort(intervals.begin(), intervals.end(), [](const Interval &left, const Interval &right) {
			if (left.start != right.start)
				return left.start < right.start;
			return left.end < right.end;
		});
		results.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); ++i) {
			if (intervals[i].end <= results.back().end)
				continue;
			if (intervals[i].start > results.back().end)
				results.push_back(intervals[i]);
			else
				results.back().end = intervals[i].end;
		}
		return results;
	}
};
