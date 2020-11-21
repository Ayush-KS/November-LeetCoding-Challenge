// Search in Rotated Sorted Array II

class Solution {
    public boolean search(int[] nums, int target) {
        if(nums.length == 0)
            return false;
        int lo = 0, hi = nums.length - 1;
        
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if(nums[hi] == nums[mid]) {
                hi--;
            } else if(nums[mid] < nums[hi]) {
                if((nums[mid] < target) && (nums[hi] >= target)) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            } else {
                if((nums[mid] >= target) && (nums[lo] <= target)) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
        }
        
        return nums[lo] == target;
    }
}