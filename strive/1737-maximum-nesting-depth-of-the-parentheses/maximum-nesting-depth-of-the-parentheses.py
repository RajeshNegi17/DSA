class Solution:
    def maxDepth(self, s: str) -> int:
        count = 0
        ans = 0
        for char in s:
            if char == '(':
                count += 1
            elif char==')':
                ans = max(count,ans)
                count -= 1
        return ans