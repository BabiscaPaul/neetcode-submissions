class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj_list = defaultdict(list)
        curr_path = set()
        visited = set()

        for u, v in prerequisites:
            adj_list[u].append(v)

        def dfs(start: int) -> bool:
            if start in visited and start in curr_path: return True
            if start in visited: return False

            visited.add(start)
            curr_path.add(start)
            
            for neighbor in adj_list[start]:
                if dfs(neighbor): return True
                
            curr_path.remove(start)
            return False
        
        for v in range(numCourses):
            if dfs(v): return False
        return True 