// Find the Smallest Divisor Given a Threshold

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = 0;
        for(int i : nums)
            hi = max(hi, i);
        
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int curr = 0;
            for(int i : nums) {
                curr += (i / mid);
                if(i % mid)
                    curr++;
            }
            
            if(curr <= threshold) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};