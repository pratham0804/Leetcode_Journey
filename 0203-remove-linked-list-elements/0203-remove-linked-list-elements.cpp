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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        if(head->next == NULL && val == head->val){
            delete head;
            return NULL;
        }

        while(head != NULL && head->val == val){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        if(head == NULL || head->next == NULL) return head;

        ListNode* curr = head->next;
        ListNode* prev = head;
        while(curr != NULL && curr->next!=NULL){
            if(curr->val == val){
                prev->next = curr->next;
                delete curr;
                curr = prev;
            }
            prev = curr;
            curr = curr->next;
        
        }
        if(curr != NULL && curr->next == NULL && curr->val == val){
            prev->next = NULL;
            delete curr;
        }
        return head;
    }
};