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
ListNode* reverseLL(ListNode* head){
    if(head == NULL || head->next == NULL) return head;

    ListNode* temp = reverseLL(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;
    return temp;
}
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){

            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast != NULL && fast->next == NULL){
            slow = slow->next;
        }
        slow = reverseLL(slow);

        ListNode* temp2 = slow;
        ListNode* temp1 = head;

        while(temp2 != NULL){
            if(temp2->val != temp1->val) return false;
            temp2 =temp2->next;
            temp1 =temp1->next;
        }

        return true;
    }
};