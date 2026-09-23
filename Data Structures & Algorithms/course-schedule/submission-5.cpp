#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::vector;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        build_graph(adj_list, prerequisites);
        
        for (const auto [key, _]: adj_list) {
            if (has_cycle(key))
                return false;
        }

        return true;
    }
private:
    using Graph = std::unordered_map<int, std::vector<int>>;
    Graph adj_list;
    std::unordered_set<int> curr_path, visited;

    void build_graph(Graph& adj_list, const vector<vector<int>>& prerequisites) {
        for (const auto& pair: prerequisites) {
            adj_list[pair[1]].push_back(pair[0]);
        }
    }

    bool has_cycle(int curr_node) {
        if (visited.contains(curr_node) && curr_path.contains(curr_node))
            return true;
        
        if (visited.contains(curr_node))
            return false;

        visited.insert(curr_node);
        curr_path.insert(curr_node);

        for (const int neighbor: adj_list[curr_node]) {
            bool res = has_cycle(neighbor);
            if (res) return true;
        }

        curr_path.erase(curr_node);

        return false;
    }
};
