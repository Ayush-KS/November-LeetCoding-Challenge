// Partition Equal Subset Sum

class Solution {
public:
    vector<int> arr;
    bool helper(vector<vector<int>>& dp, int si, int sum) {
        int tot = dp[0].size();
        if(sum == tot)
            return true;
        if(sum > tot || si >= dp.size())
            return false;
        if(dp[si][sum] != -1)
            return dp[si][sum];
        dp[si][sum] = helper(dp, si + 1, sum + arr[si]) | helper(dp, si + 1, sum);
        return dp[si][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        arr = nums;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if(sum & 1)
            return false;
        sum >>= 1;
        vector<vector<int>> dp(n, vector<int>(sum, -1));
        
        return helper(dp, 0, 0);
    }
};