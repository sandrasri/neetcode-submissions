class Solution:
    def isPalindrome(self, s: str) -> bool:
        cleaned = "".join(char for char in s if char.isalnum()).lower()
        if (cleaned[::-1] == cleaned):
            return True
        return False