// Longest Substring with At Least K Repeating Characters

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;
        
        for(int i = 1; i <= 26; i++) {
            vector<int> freq(26, 0);
            int left = 0, right = 0;
            int charWithK = 0, currUnique = 0;
            int curr;
            
            while(right < n) {
                if(currUnique <= i) {
                    curr = s[right++] - 'a';
                    if(!freq[curr])
                        currUnique++;
                    freq[curr]++;
                    if(freq[curr] == k)
                        charWithK++;
                } else {
                    curr = s[left++] - 'a';
                    if(freq[curr] == k)
                        charWithK--;
                    freq[curr]--;
                    if(!freq[curr])
                        currUnique--;
                }
                
                if(currUnique == i && charWithK == currUnique) {
                    ans = max(ans, right - left);
                }
            }
        }
        
        return ans;
    }
};