/*
 * Author: Qiang Jia
 * Date: Aug 20, 2015
 * Link: https://leetcode.com/problems/insert-interval/
 * Description:
 *      Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *      You may assume that the intervals were initially sorted according to their start times.
 *      Example 1:
 *			Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *      Example 2:
 *			Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *			This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> results;
		intervals.push_back(newInterval);
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
