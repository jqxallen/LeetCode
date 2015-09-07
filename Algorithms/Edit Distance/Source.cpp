/*
 * Author: Qiang Jia
 * Date: Sep 7, 2015
 * Link: https://leetcode.com/problems/edit-distance/
 * Description:
 *      Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 *      You have the following 3 operations permitted on a word:
 *			a) Insert a character
 *			b) Delete a character
 *			c) Replace a character
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> m(word2.size() + 1, vector<int>(word1.size() + 1, 0));
		for (int i = 0; i < word1.size(); ++i)
			m[0][i + 1] = m[0][i] + 1;
		for (int i = 0; i < word2.size(); ++i)
			m[i + 1][0] = m[i][0] + 1;
		for (int i = 0; i < word1.size(); ++i) {
			for (int j = 0; j < word2.size(); ++j) {
				m[j + 1][i + 1] = min(min(m[j][i + 1], m[j + 1][i]) + 1, m[j][i] + (word1[i] != word2[j]));
			}
		}
		return m[word2.size()][word1.size()];
	}
};

void main()
{
	Solution solution;
	cout << (solution.minDistance("abcde", "bcfe") == 2) << endl;
	cout << (solution.minDistance("zoologicoarchaeologist", "zoogeologist") == 10) << endl;
}
