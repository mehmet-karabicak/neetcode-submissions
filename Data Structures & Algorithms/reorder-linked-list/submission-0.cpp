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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr and fast->next->next!=nullptr){
            fast = fast->next->next; 
            slow = slow->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;

        while(second!=nullptr){
            ListNode* nextTemp = second->next;
            second->next = prev;
            prev = second;
            second = nextTemp;
        }

        ListNode* curr = head;

        while(curr){
            ListNode* tempNext = curr->next;

            curr->next = prev;
            if(prev){
                ListNode* tempPrev = prev->next;
                prev->next = tempNext;
                prev = tempPrev;
            }

            curr = tempNext;
        }
    }
};