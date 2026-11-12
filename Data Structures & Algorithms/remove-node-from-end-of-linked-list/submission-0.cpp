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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;

        for (int i=0; i<n; i++){
            current=current->next;
        }

        if (current==nullptr) {
            return head->next;
        } 

        ListNode* father = head;

        while (current->next!=nullptr){
            current = current->next;
            father = father->next;
        }

        father->next = father->next->next;

        return head;
    }
};