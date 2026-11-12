/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* currentNode = ans;

        int l1_val;
        int l2_val;
        int carry = 0;
        while(l1 or l2 or carry){
            l1_val = l1 ? l1->val : 0;
            l2_val = l2 ? l2->val : 0;

            int total = l1_val + l2_val + carry;

            currentNode->val = total%10;

            carry = total/10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

            //when do we not want next added? if !l1 and if !l2 AND if carry = 0
            if (l1 or l2 or carry){
                ListNode* next = new ListNode(1);
                currentNode = 
                currentNode->next = 
                next;  
            }

        }
        return ans;
    }
};