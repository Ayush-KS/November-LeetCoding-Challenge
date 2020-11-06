// Minimum Cost to Move Chips to The Same Position

class Solution {
public:
    int minCostToMoveChips(vector<int>& arr) {
        int odd = 0;
        for(int i : arr) {
            odd += (i & 1);
        }
        return min(odd, (int)arr.size() - odd);
    }
};