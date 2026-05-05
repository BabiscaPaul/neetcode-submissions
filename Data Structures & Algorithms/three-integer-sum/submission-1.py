class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        sorted_nums = sorted(nums)
        result = set()
        
        for i in range(len(sorted_nums) - 2):
            for j in range(i + 1, len(sorted_nums) - 1):
                k = len(sorted_nums) - 1
                while k > j:
                    curr_triplet = (sorted_nums[i], sorted_nums[j], sorted_nums[k])
                    if sum(curr_triplet) == 0 and curr_triplet not in result:
                        result.add(curr_triplet)
                    k -= 1
        
        result = [[x, y, z] for x, y, z in result]
        return result
