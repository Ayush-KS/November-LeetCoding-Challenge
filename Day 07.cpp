// Add Two Numbers II

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1) {
            s1.push(l1->val);
            l1 = l1 -> next;
        }
        while(l2) {
            s2.push(l2->val);
            l2 = l2 -> next;
        }
        ListNode* head = new ListNode((s1.top() + s2.top()) % 10);     
        int carry = (s1.top() + s2.top()) / 10;
        s1.pop();
        s2.pop();
        while(s1.size() || s2.size()) {
            ListNode* newNode;
            if(s1.empty()) {
                newNode = new ListNode((s2.top() + carry) % 10);
                carry = (s2.top() + carry) / 10;    
                s2.pop();
            } else if(s2.empty()) {
                newNode = new ListNode((s1.top() + carry) % 10);
                carry = (s1.top() + carry) / 10;   
                s1.pop();
            } else {
                newNode = new ListNode((s2.top() + carry + s1.top()) % 10);
                carry = (s2.top() + carry + s1.top()) / 10;  
                s1.pop();
                s2.pop();
            }
            newNode -> next = head;
            head = newNode;
        }
        if(carry) {
            ListNode* newHead = new ListNode(1);
            newHead -> next = head;
            head = newHead;
        }
        return head;
    }
};