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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        int len1 = 0;
        while(temp1 != NULL){
            len1++;
            temp1 = temp1->next;
        }

        int len2 = 0;
        while(temp2 != NULL){
            len2++;
            temp2 = temp2->next;
        }

        temp1 = headA;
        temp2 = headB;
        int x = len1-len2;
        if(x < 0){
            x = abs(x);
            while(x--){
                temp2 = temp2->next;
            }

        }
        else if(x > 0){
            while(x--){
                temp1 = temp1->next;
            }
        }


        while(temp1 != NULL && temp2 != NULL){
            if(temp1 == temp2) return temp1;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }


        return NULL;
    }
};