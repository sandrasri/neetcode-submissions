class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        result = deque()
        currentHighest = 0
        for char in s:
            if char not in result:
                result.append(char)
            else:
                if currentHighest < len(result):
                    currentHighest = len(result)
                while result and result[0] != char:
                    result.popleft()
                result.popleft()
                result.append(char)
        return max(currentHighest, len(result))

