/*
 * Author: Qiang Jia
 * Date: May 10, 2015
 * Link: https://leetcode.com/problems/implement-trie-prefix-tree/
 * Description:
 *		Implement a trie with insert, search, and startsWith methods.
 *		Note:
 *			You may assume that all inputs are consist of lowercase letters a-z.
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace::std;

class TrieNode {
public:
	char word;
	bool tag;
	unordered_set<TrieNode*> next;
	// Initialize your data structure here.
	TrieNode() {
		word = '.';
		tag = 0;
		next.clear();
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string s) {
		TrieNode* node = root, *tmp;
		for (int i = 0; i < s.size(); ++i) {
			auto p = find_if(node->next.cbegin(), node->next.cend(), [&](TrieNode* n){
				return s[i] == n->word;
			});
			if (p == node->next.cend()) {
				tmp = new TrieNode();
				tmp->word = s[i];
				tmp->tag = (i == s.size() - 1);
				node->next.insert(tmp);
			}
			else {
				tmp = *p;
				if (!tmp->tag)
					tmp->tag = (i == s.size() - 1);
			}
			node = tmp;
		}
	}

	// Returns if the word is in the trie.
	bool search(string key) {
		return search(key, 1);
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		return search(prefix, 0);
	}

	bool search(string s, bool complete) {
		TrieNode* node = root;
		for (int i = 0; i < s.size(); ++i) {
			auto p = find_if(node->next.cbegin(), node->next.cend(), [&](TrieNode* n){
				return s[i] == n->word;
			});
			if (p == node->next.cend())
				return 0;
			else
				node = *p;
			if (i == s.size() - 1 && complete && !(*p)->tag)
				return 0;
		}
		return 1;
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
