# Smallest Integer Divisible by K

class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        arr = [0]
        for i in range(1, int(1e5+1)):
            arr.append((arr[-1]*10 + 1) % k)
            if(arr[-1] is 0):
                return i
        return -1
        