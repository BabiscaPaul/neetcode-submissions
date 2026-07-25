#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
private:
    std::list<std::pair<int, int>> cache;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> key_to_it_map;
    int capacity;

public:
    LRUCache(int capacity) : capacity{capacity} {}
    
    int get(int key) {
        auto it = key_to_it_map.find(key);
        if (it == key_to_it_map.end()) return -1;
        
        int value = it->second->second;
        put(key, value);
        return value;
    }
    
    void put(int key, int value) {
        auto it = key_to_it_map.find(key);
        
        if (it != key_to_it_map.end()) {
            cache.erase(it->second);
            key_to_it_map.erase(it);
        }

        if (key_to_it_map.size() == capacity) {
            auto first = cache.front();
            key_to_it_map.erase(first.first);
            cache.pop_front();
        }
        
        cache.push_back({key, value});
        key_to_it_map[key] = std::prev(cache.end());
    }
};
