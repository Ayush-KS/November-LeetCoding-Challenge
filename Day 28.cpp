// Sliding Window Maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> op (nums.size() - k + 1);
        deque<int> dq;
        
        for(int i = 0; i < k; i++) {
            while(!dq.empty() && nums[dq.front()] < nums[i]) {
                dq.pop_front();
            }
            dq.push_front(i);
        }
        
        for(int i = k; i < nums.size(); i++) {
            op[i - k] = nums[dq.back()];
            while(!dq.empty() && dq.back() <= i - k) {
                dq.pop_back();
            }
            while(!dq.empty() && nums[dq.front()] < nums[i]) {
                dq.pop_front();
            }
            dq.push_front(i);
        }
        op[nums.size() - k] = nums[dq.back()];
        
        return op;
    }
};