class RandomizedSet {
    private:
        std::vector<int> number_set;


    public:
        RandomizedSet() {}
        
        bool insert(int val) {
            for (int num: number_set) {
                if (num == val) return false;
            }

            number_set.push_back(val);
            return true;
        }
        
        bool remove(int val) {
            for (size_t i = 0; i < number_set.size(); ++i) {
                if (number_set[i] == val) {
                    number_set.erase(number_set.begin() + i);
                    return true;
                }
            }

            return false;
        }
        
        int getRandom() const {
            size_t index = rand() % number_set.size();
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