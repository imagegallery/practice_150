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
        unordered_map<Node*, Node*> s;

        Node* temp = head;
        while(temp != NULL){
            s[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = new Node(-1);
        Node* aux = temp;
        Node* curr = head;
        while(curr != NULL){
            Node* t = s[curr];
            t->next = s[curr->next];
            t->random = s[curr->random];
            temp->next = t;
            temp = temp->next;
            curr = curr->next;
        }
        return aux->next;
    }
};