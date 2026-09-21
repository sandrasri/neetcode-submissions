class Solution:
    def isValid(self, s: str) -> bool:
        validBrackets = {'(':')', '{':'}', '[':']'}
        stack = []

        for char in s:
            if stack and stack[-1] in validBrackets and char == validBrackets[stack[-1]]:
                stack.pop()
            else:
                stack.append(char)  

        if stack:
            return False
        return True


        