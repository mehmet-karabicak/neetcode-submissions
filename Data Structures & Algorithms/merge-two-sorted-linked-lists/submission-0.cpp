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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        } 
        if(list2==nullptr){
            return list1;
        }

        ListNode* bothHead;

        if(list1->val<=list2->val){
            bothHead = list1;
            list1 = list1->next;
        } else{
            bothHead = list2;
            list2 = list2->next;
        }

        ListNode* currMerged = bothHead;

        while(!(list1==nullptr and list2==nullptr)){
            if(!list1){
                currMerged->next = list2;
                list2 = list2->next;
            } else if(!list2){
                currMerged->next = list1;
                list1 = list1->next;             
            } else{
                if(list1->val<=list2->val){
                    currMerged->next = list1;
                    list1 = list1->next;
                } else{
                    currMerged->next = list2;
                    list2 = list2->next;
                }
            }
            currMerged = currMerged->next;
        }


        return bothHead;
    }
};