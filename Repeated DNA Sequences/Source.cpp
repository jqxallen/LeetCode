#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> v;
        int n = 10;
        vector<bool> checker(1 << 2 * n);
        for (int i = n - 1; i < s.length(); ++i) {
            int hash = 0;
            for (int j = i - n + 1; j <= i; ++j) {
                hash <<= 2;
                hash += (s.at(j) - 'B') >> 1 & 0x3;
            }
            if (checker[hash]) {
                string t(s.substr(i - n + 1, n));
                if (find(v.cbegin(), v.cend(), t) == v.cend())
                    v.push_back(t);
            } else {
                checker[hash] = 1;
            }
        }
        return v;
    }
};

int main() {
    string s = "GAGAGAGAGAGA";
    Solution solution;
    vector<string> vec = solution.findRepeatedDnaSequences(s);
    copy(vec.begin(),vec.end(),ostream_iterator<string>(cout, "\n"));
}
