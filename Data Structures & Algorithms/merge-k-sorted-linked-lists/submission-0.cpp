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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;

        ListNode head;
        ListNode* curr = &head;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap;

        for(ListNode*& list: lists){
            if(list){
                minHeap.push({list->val, list});
            }
        }

        while(!minHeap.empty()){
            auto toAdd = minHeap.top().second;

            minHeap.pop();

            curr->next = toAdd;

            curr = curr->next;

            if(toAdd->next){
                ListNode* son = toAdd->next;
                minHeap.push({son->val, son});
            }
        }

        return head.next;
    }
};