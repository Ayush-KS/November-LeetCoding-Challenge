// Insertion Sort List

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head -> next)
            return head;
        ListNode* prev = head;
        ListNode* temp = head -> next;
        
        while(temp != NULL) {
            ListNode* next = temp -> next;
            ListNode* temp2 = head;
            if(head -> val > temp -> val) {
                prev -> next = next;
                temp -> next = head;
                head = temp;
                temp = next;
                continue;
            }
            while(temp2 -> next != temp && temp2 -> next -> val < temp -> val) {
                temp2 = temp2 -> next;
            }
            if(temp2 -> next == temp) {
                prev = temp;
                temp = next;
                continue;
            }
            temp -> next = temp2 -> next;
            temp2 -> next = temp;
            prev -> next = next;
            temp = next;
        }
        
        return head;
    }
};