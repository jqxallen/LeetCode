#include <string>
#include <queue>
#include <unordered_set>
using namespace::std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		queue<string> coll, temp_coll;
		coll.push(start);
        int distance = 1;
        while (!dict.empty() && !coll.empty()) {
			while (!coll.empty()) {
				string curr = coll.front();
				coll.pop();
				for (int i = 0; i < curr.size(); ++i) {
					for (char j = 'a'; j < 'z'; ++j) {
						if (j == curr[i]) continue;
						char c = curr[i];
						curr[i] = j;
						if (curr == end) return distance + 1;
						if (dict.find(curr) != dict.cend()) {
							temp_coll.push(curr);
							dict.erase(curr);
						}
						curr[i] = c;
					}
				}
			}
			coll.swap(temp_coll);
        	distance++;
        }
        return 0;
    }
};
