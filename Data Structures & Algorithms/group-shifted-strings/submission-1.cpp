struct VectorHasher {
    size_t operator()(const std::vector<int>& vec) const {
        std::hash<int> hasher;
        size_t seed = 1;
        for (int i = 0; i < vec.size(); i++) {
            seed *= hasher(vec[i]);
        }
        return seed;
    }
};

class Solution {
public:
    std::vector<int> get_string_encoding(const std::string& sequence) {
        std::vector<int> encoding;
        encoding.reserve(sequence.size() - 1);

        for (int i = 1; i < sequence.size(); i++) {
            int diff = sequence[i] - sequence[i - 1];
            if (diff < 0) diff += 26;
            encoding.emplace_back(diff);
        }

        return encoding;
    }

    std::vector<std::vector<std::string>> groupStrings(std::vector<std::string>& strings) {
        std::unordered_map<std::vector<int>, std::vector<std::string>, VectorHasher> map;
        for (const auto& seq: strings) {
            map[get_string_encoding(seq)].emplace_back(seq);
        }

        std::vector<std::vector<std::string>> res;

        for (const auto& entry: map) {
            res.emplace_back(entry.second);
        }

        return res;
    }
};
