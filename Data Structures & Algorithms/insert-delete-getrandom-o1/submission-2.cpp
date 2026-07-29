#include <cstddef>
#include <cstdlib>
#include <vector>
#include <unordered_map>

class RandomizedSet {
    private:
        std::vector<int> number_set;
        std::unordered_map<int, size_t> index_to_num_map;

    public:
        bool insert(int val) {
            auto iter = index_to_num_map.find(val);
            if (iter != index_to_num_map.end()) return false;

            number_set.push_back(val);
            index_to_num_map.insert({val, number_set.size() - 1});
            return true;
        }
        
        bool remove(int val) {
            auto iter = index_to_num_map.find(val);
            if (iter == index_to_num_map.end()) return false;
            index_to_num_map.erase(iter);
            return true;
        }
        
        int getRandom() const {
            size_t index = rand() % number_set.size();

            while (!index_to_num_map.contains(number_set[index])) {
                index = rand() % number_set.size();
            }

            return number_set[index];
        }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */