#include <string>
#include <bitset>
#include <unordered_map>
using namespace::std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size())
			return false;
		bitset<256> checker;
		unordered_map<char, char> cache;
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			if (cache.find(s[i]) == cache.end()) {
				if (checker.test(t[i]))
					return false;
				cache.insert(pair<char, char>(s[i], t[i]));
				checker.set(t[i]);
			}
			else if (cache[s[i]] != t[i]) {
				return false;
			}
		}
		return true;
	}
};
