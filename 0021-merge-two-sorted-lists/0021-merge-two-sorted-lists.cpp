
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        std::list<int> myList;  // Assuming you want to store the merged values in a list

        ListNode* i = list1;
        ListNode* j = list2;

        while (i != nullptr && j != nullptr) {
            if (i->val <= j->val) {
                myList.push_back(i->val);
                i = i->next;
            } else {
                myList.push_back(j->val);
                j = j->next;
            }
        }

        // Handle remaining elements in list1, if any
        while (i != nullptr) {
            myList.push_back(i->val);
            i = i->next;
        }

        // Handle remaining elements in list2, if any
        while (j != nullptr) {
            myList.push_back(j->val);
            j = j->next;
        }

        // Assuming you have a ListNode constructor that takes a value and a next pointer
        ListNode* mergedList = nullptr;
        ListNode* current = nullptr;

        for (const auto& val : myList) {
            ListNode* newNode = new ListNode(val);
            if (mergedList == nullptr) {
                mergedList = newNode;
                current = newNode;
            } else {
                current->next = newNode;
                current = newNode;
            }
        }

        return mergedList;
    }
};
