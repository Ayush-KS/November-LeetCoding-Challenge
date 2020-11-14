# Valid Square

class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        
        def helper(p1: List[int], p2: List[int], p3: List[int], p4: List[int]):
            d1 = (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2
            d2 = (p1[0] - p3[0])**2 + (p1[1] - p3[1])**2
            d3 = (p1[0] - p4[0])**2 + (p1[1] - p4[1])**2
            return d1 and d2 and d3 and ((d1 == d2 and d3 == 2*d1) or (d2 == d3 and d1 == 2*d2) or (d1 == d3 and d2 == 2*d1))
        
        return (helper(p1, p2, p3, p4) and helper(p2, p3, p4, p1)) and (helper(p3, p4, p1, p2) and helper(p4, p1, p2, p3))
            