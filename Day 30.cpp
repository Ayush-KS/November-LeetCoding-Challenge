// The Skyline Problem

#define ff first
#define ss second

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        int maxH = 0;
        multiset<pair<int, int>> points;
        map<int, int> heights;
        heights[0]++;
        
        for(auto v : arr) {
            points.insert({v[0], -v[2]});
            points.insert({v[1], v[2]});
        }
        
        for(auto it : points) {
            int ht = it.ss > 0 ? it.ss : -it.ss;
            if(it.ss < 0) {
                heights[ht]++;
            } else {
                heights[ht]--;
            }
            if(!heights[ht])
                heights.erase(ht);
            if(heights.rbegin() -> ff != maxH) {
                maxH = heights.rbegin() -> ff;
                ans.push_back({it.ff, maxH});
            }
        }
        
        return ans;
    }
};