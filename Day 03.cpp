// Consecutive Characters

class Solution {
public:
    int maxPower(string s) {
        if(s.length() == 0)
            return 0;
        int ans, curr;
        ans = curr = 1;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i - 1]) {
                curr++;
            } else {
                ans = max(ans, curr);
                curr = 1;
            }
        }
        return max(ans, curr);
    }
};