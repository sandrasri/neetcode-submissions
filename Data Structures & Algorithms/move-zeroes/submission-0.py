class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        numZeroes = 0
        i = 0
        while i < len(nums):
            if nums[i] == 0:
                nums.pop(i)
                numZeroes+=1
            else:
                i+=1
        
        for i in range(numZeroes):
            nums.append(0)
        
        