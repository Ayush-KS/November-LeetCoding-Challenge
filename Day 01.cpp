// Convert Binary Number in a Linked List to Integer

class Solution {
public:
    
    pair<int, int> helper(ListNode* head) {
        if(!head) 
            return {0,0};
        pair<int, int> smallAns = helper(head -> next);
        if(head -> val == 0)
            return {smallAns.first + 1, smallAns.second};
        else
            return {smallAns.first + 1, pow(2, smallAns.first) + smallAns.second};
    }
    
    int getDecimalValue(ListNode* head) {
        return helper(head).second;
    }
};