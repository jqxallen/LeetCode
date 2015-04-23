#include <iostream>
#include <vector>
#include <unordered_map>
using namespace::std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

/**
* Definition for undirected graph.
* struct UndirectedGraphNode {
*     int label;
*     vector<UndirectedGraphNode *> neighbors;
*     UndirectedGraphNode(int x) : label(x) {};
* };
*/
class Solution {
public:
	void cloneNode(UndirectedGraphNode *node) {
		if (cache.find(node) != cache.cend()) return;
		cache.insert({ node, new UndirectedGraphNode(node->label) });
		for (const auto &neighbor : node->neighbors)
			cloneNode(neighbor);
	}
	void cloneNeighbors(UndirectedGraphNode *node) {
		if (!cache.find(node)->second->neighbors.empty()) return;
		for (const auto &neighbor : node->neighbors) {
			cache.find(node)->second->neighbors.push_back(cache.find(neighbor)->second);
			cloneNeighbors(neighbor);
		}
	}
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node) return NULL;
		cloneNode(node);
		cloneNeighbors(node);
		return cache.find(node)->second;
	}
private:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> cache;
};
