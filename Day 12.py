# Permutations II

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans = []
        def backtrack(curr, freq):
            if(len(curr) == len(nums)):
                ans.append(list(curr))
                return
            
            for num in freq:
                if(freq[num]):
                    curr.append(num)
                    freq[num] -= 1
                    
                    backtrack(curr, freq)
                    
                    curr.pop()
                    freq[num] += 1
        
        backtrack([], Counter(nums))
        
        return ans