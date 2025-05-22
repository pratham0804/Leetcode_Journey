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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int idx = 0;
        while(idx < k){
            if(curr == NULL)return head;
            curr = curr->next;
            idx++;
        }
        curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        ListNode* first = head;
        int i = 0;
        while(i < k){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            i++;
        }
        first->next = reverseKGroup(nxt, k);
        
        return prev;
    }
};