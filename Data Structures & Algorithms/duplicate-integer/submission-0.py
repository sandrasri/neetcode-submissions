class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        hashmap = Counter(nums)
        for c in hashmap:
            if hashmap[c] > 1:
                return True
        return False