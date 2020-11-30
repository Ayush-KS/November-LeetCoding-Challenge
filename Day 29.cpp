// Jump Game III

class Solution {
public:
    unordered_map<int, bool> vis;
    bool canReach(vector<int>& arr, int start) {
        if(start >= 0 && start < arr.size() && !vis[start]) {
            vis[start] = true;
            if(arr[start] == 0)
                return true;
            return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
        }
        return false;
    }
};