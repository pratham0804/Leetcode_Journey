/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        if(head == NULL || head->next ==NULL) return NULL;

        do{

            if(fast == NULL || fast->next == NULL) return NULL;
            slow = slow->next;
            fast = fast->next->next;
        }while(slow != fast);


        slow = head;
        while(slow != fast){
            fast = fast->next;
            slow=slow->next;

        }

        return slow;
    }
};