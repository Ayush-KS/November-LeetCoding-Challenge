# Unique Morse Code Words

class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        ans = 0
        mp = list()
        
        for word in words:
            curr = ''
            for ch in word:
                curr += morse[ord(ch) - 97]
            if curr not in mp:
                ans += 1
                mp.append(curr)
                
        return ans
        