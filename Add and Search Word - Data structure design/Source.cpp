/*
 * Author: Qiang Jia
 * Date: May 16, 2015
 * Link: https://leetcode.com/problems/add-and-search-word-data-structure-design/
 * Description:
 *		Design a data structure that supports the following two operations:
 *			void addWord(word)
 *			bool search(word)
 *		search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
 *		For example:
 *			addWord("bad")
 *			addWord("dad")
 *			addWord("mad")
 *			search("pad") -> false
 *			search("bad") -> true
 *			search(".ad") -> true
 *			search("b..") -> true
 *		Note:
 *			You may assume that all words are consist of lowercase letters a-z.
 *		Hints:
 *			You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) (https://leetcode.com/problems/implement-trie-prefix-tree/) first.
 */

#include <string>
#include <unordered_set>
#include <algorithm>
using namespace::std;

class WordDictionary {
public:
	struct Node {
		char word;
		bool tag;
		unordered_set<Node*> next;
		Node(char w, bool t) : word(w), tag(t) {
			this->next.clear();
		}
	};

	bool _search_(const string &word, const int i, const Node *node) {
		if (i >= word.size())
			return 0;
		if (word[i] != '.') {
			const auto pos = find_if(node->next.cbegin(), node->next.cend(), [&](const Node *n) {
				return word[i] == n->word;
			});
			if (pos == node->next.cend())
				return 0;
			if (i == word.size() - 1)
				return (*pos)->tag;
			if (this->_search_(word, i + 1, *pos))
				return 1;
		}
		else {
			if (i == word.size() - 1) {
				const auto pos = find_if(node->next.cbegin(), node->next.cend(), [&](const Node *n) {
					return n->tag;
				});
				return pos != node->next.cend();
			}
			for (const Node* n : node->next) {
				if (this->_search_(word, i + 1, n))
					return 1;
			}
		}
	}

	// Adds a word into the data structure.
	void addWord(string word) {
		if (!root)
			root = new Node('.', 0);
		Node *node = root, *tmp;
		for (int i = 0; i < word.size(); ++i) {
			const auto pos = find_if(node->next.cbegin(), node->next.cend(), [&](const Node* n) {
				return word[i] == n->word;
			});
			if (pos == node->next.cend()) {
				tmp = new Node(word[i], i == word.size() - 1);
				node->next.insert(tmp);
			}
			else {
				tmp = *pos;
				tmp->tag |= i == word.size() - 1;
			}
			node = tmp;
		}
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		if (root)
			return this->_search_(word, 0, root);
		return 0;
	}
private:
	Node *root = NULL;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
