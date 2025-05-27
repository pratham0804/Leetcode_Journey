/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;

        unordered_map<Node*,Node*> mpp;

        while(temp != NULL){
            Node* newnode = new Node(temp->val);
        
            mpp[temp] = newnode;
            temp = temp->next;
        }

        temp = head;
        
        while(temp != NULL){
            mpp[temp]->next = mpp[temp->next];
            mpp[temp]->random = mpp[temp->random];
            temp = temp->next;
        }
        return mpp[head];
    }
};