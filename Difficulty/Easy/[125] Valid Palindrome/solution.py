class Solution:
    def isPalindrome(self, s: str) -> bool:
        left, right = 0, len(s) - 1
        while left < right:
            if ord(s[left]) < ord('0') or (ord(s[left]) > ord('9') and ord(s[left]) < ord('A')) or (ord(s[left]) > ord('Z') and ord(s[left]) < ord('a')) or ord(s[left]) > ord('z'):
               left += 1
               continue
            if ord(s[right]) < ord('0') or (ord(s[right]) > ord('9') and ord(s[right]) < ord('A')) or (ord(s[right]) > ord('Z') and ord(s[right]) < ord('a')) or ord(s[right]) > ord('z'):
               right -= 1
               continue
            if s[left].lower() == s[right].lower():
                left += 1
                right -= 1
            else:
                return False
        return True
                