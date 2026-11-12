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
    bool hasCycle(ListNode* head) {
        if(head==nullptr or head->next==nullptr){
            return false;
        }
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;

        while(1){
            if(ptr2->next==nullptr){
                return false;
            } else{
                ptr2 = ptr2->next;
            }
    
            if(ptr2->next==nullptr){
                return false;
            } else{
                ptr2 = ptr2->next;
            }

            ptr1 = ptr1->next;


            if(ptr1==ptr2){
                return true;
            }
        }
        return false;
    }
};
