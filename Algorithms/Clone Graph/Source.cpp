/*
 * Author: Qiang Jia
 * Date: Apr 23, 2015
 * Link: https://leetcode.com/problems/clone-graph/
 * Description:
 * 		Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 * 		OJ's undirected graph serialization:
 * 			Nodes are labeled uniquely.
 * 			We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 * 			As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 * 			The graph has a total of three nodes, and therefore contains three parts as separated by #.
 * 				1. First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * 				2. Second node is labeled as 1. Connect node 1 to node 2.
 * 				3. Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 * 			Visually, the graph looks like the following:
 *			        1
 *			       / \
 *			      /   \
 *			     0 --- 2
 *			          / \
 *			          \_/
 */

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
