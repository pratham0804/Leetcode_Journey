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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* iterator = head;
        

      
        

        while(iterator!=NULL){
            
            ListNode* nextNode = iterator->next;
            iterator->next = prev;

            prev = iterator;
            iterator = nextNode;
            

        }

        return prev;
    }
};