/*
 * Author: Qiang Jia
 * Date: Aug 20, 2015
 * Link: https://leetcode.com/problems/lru-cache/
 * Description:
 *      Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 *      get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 *      set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 */

#include <iostream>
#include <unordered_map>
#include <list>
using namespace::std;

class LRUCache{
public:
	LRUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		auto it = handle.find(key);
		if (it != handle.end()) {
			body.splice(body.end(), body, it->second);
			return it->second->second;
		}
		return -1;
	}

	void set(int key, int value) {
		auto it = handle.find(key);
		if (it != handle.end()) {
			handle.erase(it);
			body.erase(it->second);
		}
		if (handle.size() >= size) {
			handle.erase(handle.find(body.front().first));
			body.pop_front();
		}
		body.push_back(pair<int, int>(key, value));
		handle[key] = --body.end();
	}
private:
	int size;
	unordered_map<int, list<pair<int, int>>::iterator> handle;
	list<pair<int, int>> body;
};
