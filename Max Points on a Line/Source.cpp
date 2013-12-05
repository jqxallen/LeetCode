#include <vector>
#include <map>
using namespace::std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

/**
* Definition for a point.
* struct Point {
*     int x;
*     int y;
*     Point() : x(0), y(0) {}
*     Point(int a, int b) : x(a), y(b) {}
* };
*/
class Solution {
public:
	int maxPoints(vector<Point> &points) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (points.empty()) return 0;
		int max_points = 1;
		for (auto i = points.cbegin(); i != points.cend(); ++i) {
			map<double, int> counter;
			int same_counter = 1;
			for (auto j = points.cbegin(); j != points.cend(); ++j) {
				if (j == i) continue;
				if (j->x == i->x && j->y == i->y) 
					same_counter++;
				else {
					double slope = INT_MAX;
					if (j->x != i->x) slope = 1.0 * (j->y - i->y) / (j->x - i->x);
					if (counter.find(slope) == counter.cend()) counter.insert(make_pair(slope, 0));
					counter[slope]++;
				}
			}
			if (same_counter > max_points) max_points = same_counter;
			for (auto p : counter)
				if (p.second + same_counter > max_points)
					max_points = p.second + same_counter;
		}
		return max_points;
	}
};