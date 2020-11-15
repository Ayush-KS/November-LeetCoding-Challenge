# Poor Pigs

class Solution:
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        ans = 0
        tests = minutesToTest // minutesToDie + 1
        while(tests ** ans < buckets):
            ans += 1
        return ans
        