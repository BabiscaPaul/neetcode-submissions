class Solution:
    def simplifyPath(self, path: str) -> str:
        dirs = [dir for dir in path.split('/') if dir]
        stack = []
        result = ""
        
        for dir in dirs:
            if dir == '.':
                continue
            if dir == ".." and len(stack) > 0:
                stack.pop()
            elif dir != "..":
                stack.append(dir)
        
        for dir in stack:
            result += f"/{dir}"
        
        return result if stack else "/"