#include <vector>
using namespace::std;

class Solution {
public:
	bool isCycle(vector<vector<int>> &checker, int n) {
		if (!checker[n][0]) {
			checker[n][0] = 1;
			checker[n][1] = 1;
			for (int i = 2; i < checker[n].size(); ++i) {
				if (isCycle(checker, checker[n][i]) || checker[checker[n][i]][1])
					return 1;
			}
			checker[n][1] = 0;
		}
		return 0;
	}
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> checker(numCourses, vector<int>(2, 0));
		for (const auto &p : prerequisites)
			checker[p.first].push_back(p.second);
		for (int i = 0; i < numCourses; ++i) {
			if (isCycle(checker, i))
				return 0;
		}
		return 1;
	}
};
